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
  const GLfloat color[] = {
    (float) sin(currentTime) * 0.5f + 0.5f,  // Red
    (float) cos(currentTime) * 0.5f + 0.5f,  // Green
    0.0f,                                    // Blue
    1.0f                                     // Alpha
  };
  glClearBufferfv(GL_COLOR, 0, color);
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

  // Source code for the vertex shader:
  static const GLchar* vertex_shader_source[] =
    {
      "#version 410 core\n"
      "\n"
      "void main(void){\n"
      "    const vec4 vertices[3] = vec4[3](\n"
      "        vec4(0.25, -0.25, 0.5, 1.0),\n"
      "        vec4(-0.25, -0.25, 0.5, 1.0),\n"
      "        vec4(0, 0.25, 0.5, 1.0));\n"
      "    gl_Position = vertices[gl_VertexID];\n"
      "}\n"
    };

  // Source code for the fragment shader:
  static const GLchar* fragment_shader_source[] =
    {
      "#version 410 core\n"
      "\n"
      "out vec4 color;\n"
      "\n"
      "void main(void)\n"
      "{\n"
      "    color = vec4(0.0, 0.8, 1.0, 1.0);\n"
      "}\n"
    };

  // Create and compile the vertex shader:
  vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
  glCompileShader(vertex_shader);

  GLint logLength;
  glGetShaderiv(vertex_shader, GL_INFO_LOG_LENGTH, &logLength);
  GLchar* infoLog = new GLchar[logLength+1];
  glGetShaderInfoLog(vertex_shader, logLength, NULL, infoLog);
  std::cout << infoLog << std::endl;
  
  // Create and compile the fragment shader:
  fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
  glCompileShader(fragment_shader);

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

