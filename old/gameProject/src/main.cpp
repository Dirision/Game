
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>


// changes the viewport size 
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
	
	}
int main(){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window = glfwCreateWindow(800, 600, "Learnin", NULL, NULL);
	if (window == NULL){
		 std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);

// when window is resized, call the declared fn to resize the viewport
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	// create array of points that represnts vertices of a triangle
	// 1xyz/2xyz/3xyz
	float triVertices[]{
		-0.5f,-0.5f,-0.5f,
		0.5,-0.5f,0.0f,
		0.0f,0.5f,0.0f
	};

	float vertices[] = {
			 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};
	unsigned int indicies[] = {
		0,1,3,
		1,2,3
		};

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	
	// Create a vertex buffer object (VBO) that will be copied to the gpu for rapid 
	// access
	unsigned int VBO;
	// and give it a unique ID corresponding to the buffer
	glGenBuffers(1, &VBO);

	// bind this buffer to the GL_ARRAY_BUFFER for openGL to use
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Copy the vertex array to the GL_ARRAY_BUFFER for rendering on the gpu
	//glBufferData(GL_ARRAY_BUFFER, sizeof(triVertices), triVertices, GL_STATIC_DRAW);

	// gl buffer data is a special function that is used to copy user defined data 
	// into the currently bound buffer. The last parameter tells the gpu what to do
	// with the data.
	// We can GL_STATIC_DRAW for when the data doesnt change much
	// GL_DYNAMIC_DRAW for data that is likely to change
	// GL_STREAM_DRAW for data that is constantly changing with every draw


	////// Compiling the Shader

	// VERTEX -> GEOMETRIC -> FRAGMENT 
	// vertices -> complex edges and making new edges -> coloring & effects

	// we start by storing the vertex shaders code in a string 
	const char* vertexShaderSource = "#version 330 core\n"
		"layout(location = 0) in vec3 aPos;"
		"void main(){"
		"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);}";
	
	// create the shader object 
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// attach our shader source to the shader objec that we just created
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	// compile that shader
	glCompileShader(vertexShader);

	// we check to see if the compilation was successful here 
	int success;
	char infoLog[512];
	// pulls the compilation status of the vertex shader object and binds it to success
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Fragment Shader 
	// we have a vec4 representing the output color of the incoming pixel
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;"
		"void main(){"
		"FragColor = vec4(1.0f,0.5f,0.2f,1.0f);}";
	// compile using the appropriate call, in a similar manner to the vertex shader
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	
	// get compile status for education's sake
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//// Shader program
	// the shader program object is the final result of linking all shaders.
	// we call this program to render objects on screen.
	// the shaders attached to the shader program will be called when
	// render calls are issued
	unsigned int shaderProgram;
	// create program function creates the program and returns a reference to the object
	shaderProgram = glCreateProgram();
	// now we need to attach all shaders that we have just built 
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER_PROGRAM::LINK_PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// we can delete the shaders objects once they are linked to save memory
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	//// Vertex Array Object
	// In reality we often have hundreds of objects rendering in a scene, so we cannot
	// use our original method of a vertex buffer object. Instead, we will use a 
	// Vertex array object.
	// A Vertex array object (VAO) can be bound just like a vertex buffer object ( VBO at 
	// beginning of this code), and can be store many VBO's within the VAO 
	// for maximum efficiency!
	// https://learnopengl.com/img/getting-started/vertex_array_objects.png

	// generating the VAO is very similar to the VBO /////////////////////////////////////////
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	// bind the VAO 
	glBindVertexArray(VAO);
	// copy the vertices array into a buffer for OGL to use 
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// enable the vertex attribute
	glEnableVertexAttribArray(0);


	//// Linking vertex attributes 
	// we have to tell opengl how to interpret the floating point array defined above
	// parameter |  description
	//---------------------------
	//     1     |  specifies the vertex attribute we want to configure. Remember,
	//					 |	in the vertex shader we specified the location of the vertex 
	//					 |  attribute with layout (location = 0). this sets the location of the
	//					 |  vertex attribute to 0, and since we want to pass data to this vertex
	//					 |	attribute, we pass 0
	//     2     |	size of the vertex attribute. This is a vec3 so we pass in 3 
	//		 3     |	type of the data (vec3 is comprised of floats)
	//     4		 |  Do we want this data to be normalized? yes for ints and bytes, no for flt
	//     5		 |  The stride, aka space between consecutive vertex attributes. Since 
	//					 |	the next value is located 3 floats away, we input 3*float size
	//     6		 |  offset of where the position data begins in the buffer. because 
	//					 |	this is at the start of the array, we put 0

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// This is the main rendering loop 
	while (!glfwWindowShouldClose(window)) {
		// Inputs are processed here
		processInput(window);

		// rendering commands here

		// make screen wipe this color
		glClearColor(0.4f, 0.4f, 0.9f, 1.0f);
		// wipe screen to color defined above
		glClear(GL_COLOR_BUFFER_BIT);

		//// shader rendering operations go here
		glUseProgram(shaderProgram);
		// bring our vertex array object into the scene, this has the VBO that has the 
		// data for our triangle
		glBindVertexArray(VAO);
		// Draws the triangle
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,GL_NONE);
		glBindVertexArray(0);

		// The first argument is the gl primitive that we are trying to draw
		// Secend argument is the starting index of the vertex array object, which we 
		// have set to 0
		// Third argument is the number of vertices, and since we're only rendering one 
		// triangle, this is set to 3 

		// Check and call events, and swap buffers
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

