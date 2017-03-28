#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include <linmath.h>

#include "skeleton_utils.h"
#include "main.h"


int main(int argc, char **argv) {
  GLFWwindow* window = createWindow("1. Opening a Window");
  glClear(GL_COLOR_BUFFER_BIT);

  while (!glfwWindowShouldClose(window)) {

    // Render a colour based on the current time.
    render();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  cleanExit(window);
}


/**
 * Given a current time, calculate a colour and "clear" the screen
 * to that colour.
 */
void render() {
  const GLfloat color[] = {
    0.1f,  // Red
    0.3f,  // Green
    0.6f,  // Blue
    1.0f   // Alpha
  };
  glClearBufferfv(GL_COLOR, 0, color);
}


