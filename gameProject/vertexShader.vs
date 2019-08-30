#version 330 core 
// layout 0 is for later
// inputs to the shader are declared with the prefix in 
layout (location = 0) in vec3 aPos;

void main(){
	// gl_Position sets the location of the passed along vertice
	// since we are just passing along a location already within the 
	// openGL's viewport, we can just pass along the unaltered variable 
	// typically, this isnt the case and we need to transform the input to 
	// appear within opengl's visable region 
	gl_Position = vec4 (aPos.x, aPos.y, aPos.z, 1.0);

}
