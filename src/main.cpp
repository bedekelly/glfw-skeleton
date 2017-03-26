#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include <linmath.h>

#include "skeleton_utils.h"
#include "main.h"


int main(int argc, char **argv) {
  GLFWwindow* window = createWindow(".plain blue.");
  glClear(GL_COLOR_BUFFER_BIT);

  gldata data = glSetup();
  
  while (!glfwWindowShouldClose(window)) {

    // Render a colour based on the current time.
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
  static double TWO_PI = 3.14159 * 2;
  const GLfloat backgroundColor[] = {
    (float) sin(currentTime) * 0.5f + 0.5f,  // Red
    (float) cos(currentTime) * 0.5f + 0.5f,  // Green
    0.0f,                                    // Blue
    1.0f                                     // Alpha
  };
  glClearBufferfv(GL_COLOR, 0, backgroundColor);
  glUseProgram(data.program);

  GLfloat offset[] = {
    (float) sin(currentTime) * 0.5f,
    (float) cos(currentTime) * 0.6f,
    0.0f, 0.0f
  };

  GLfloat color[] = {
    0.6, 0.7, 0.8, 1.0
  };

  glVertexAttrib4fv(0, offset);
  glVertexAttrib4fv(1, color);
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

  // Load the source code for both shaders:
  std::string vshader_str = loadShaderSource("vertex.vs");
  std::string fshader_str = loadShaderSource("fragment.fs");

  const GLchar *vshader_source = const_cast<GLchar*>(vshader_str.c_str());
  const GLchar *fshader_source = const_cast<GLchar*>(fshader_str.c_str());
  
  // Create and compile the vertex shader:
  vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_shader, 1, &vshader_source, NULL);
  glCompileShader(vertex_shader);

  // Display the logs from compiling the vertex shader:
  GLint logLength;
  glGetShaderiv(vertex_shader, GL_INFO_LOG_LENGTH, &logLength);
  GLchar* infoLog = new GLchar[logLength+1];
  glGetShaderInfoLog(vertex_shader, logLength, NULL, infoLog);
  std::cout << infoLog << std::endl;
  
  // Create and compile the fragment shader:
  fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_shader, 1, &fshader_source, NULL);
  glCompileShader(fragment_shader);

  // GLint logLength;
  glGetShaderiv(fragment_shader, GL_INFO_LOG_LENGTH, &logLength);
  glGetShaderInfoLog(fragment_shader, logLength, NULL, infoLog);
  std::cout << infoLog << std::endl;
  
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

