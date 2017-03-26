#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include <linmath.h>

#include "skeleton_utils.h"
#include "main.h"


int main(int argc, char **argv) {
  GLFWwindow* window = createWindow("Fragment Colour From Position");
  glClear(GL_COLOR_BUFFER_BIT);
  gldata data = glSetup();
  
  while (!glfwWindowShouldClose(window)) {

    double time = glfwGetTime();
    render(time, data);
    
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glTearDown(data);

  cleanExit(window);
}


/**
 * Given a current time, calculate a colour and "clear" the screen
 * to that colour.
 */
void render(double currentTime, gldata data) {
  static const GLfloat bgColor[] = { 0.0f, 0.0f, 0.05f, 1.0f };
  glClearBufferfv(GL_COLOR, 0, bgColor);

  glUseProgram(data.program);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}


/**
 * Setup a shader program, and a vertex array.
 */
gldata glSetup() {
  gldata data;
  data.program = compileShaders();
  glGenVertexArrays(1, &data.vao);
  glBindVertexArray(data.vao);

  return data;
}


/**
 * Delete the shader program and vertex array.
 */
void glTearDown(gldata data) {
  glDeleteVertexArrays(1, &data.vao);
  glDeleteProgram(data.program);
  glDeleteVertexArrays(1, &data.vao);
}


/**
 * Create and compile a shader program.
 */
GLuint compileShaders() {
  GLuint vertex_shader;
  GLuint fragment_shader;
  GLuint program;

  // Load, create and compile each shader:
  vertex_shader = compileShader(GL_VERTEX_SHADER, "vertex.vs");
  fragment_shader = compileShader(GL_FRAGMENT_SHADER, "fragment.fs");
  
  // Create a program, attach shaders to it, and link it:
  program = glCreateProgram();
  glAttachShader(program, vertex_shader);
  glAttachShader(program, fragment_shader);
  glLinkProgram(program);

  // Delete the shaders, since they've been attached to a program:
  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);

  return program;
}

