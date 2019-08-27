
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

	// Create a vertex buffer object (VBO) that will be copied to the gpu for rapid 
	// access
	unsigned int VBO;
	// and give it a unique ID corresponding to the buffer
	glGenBuffers(1, &VBO);

	// bind this buffer to the GL_ARRAY_BUFFER 
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Copy the vertex array to the GL_ARRAY_BUFFER for rendering on the gpu
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// gl buffer data is a special function that is used to copy user defined data 
	// into the currently bound buffer. The last parameter tells the gpu what to do
	// with the data.
	// We can GL_STATIC_DRAW for when the data doesnt change much
	// GL_DYNAMIC_DRAW for data that is likely to change
	// GL_STREAM_DRAW for data that is constantly changing with every draw

	// This is the main rendering loop 
	while (!glfwWindowShouldClose(window)) {
		// Inputs are processed here
		processInput(window);

		// rendering commands here

		// make screen wipe this color
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		// wipe screen to color defined above
		glClear(GL_COLOR_BUFFER_BIT);

		// Check and call events, and swap buffers
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

