#version 410 core

layout (triangles) in;
layout (points, max_vertices = 3) out;


void main(void) {
     int i;

     for (i = 0; i < gl_in.length(); i++) {
         // Explicitly send a vertex down the pipeline.
     	 gl_Position = gl_in[i].gl_Position;
	 EmitVertex();
     }
}