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

  while (!glfwWindowShouldClose(window)) {

    // Render a colour based on the current time.
    double time = glfwGetTime();
    render(time);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  cleanExit(window);
}


/**
 * Given a current time, calculate a colour and "clear" the screen
 * to that colour.
 */
void render(double currentTime) {
  static double TWO_PI = 3.14159 * 2;
  const GLfloat color[] = {
    (float) sin(currentTime) * 0.5f + 0.5f,  // Red
    (float) cos(currentTime) * 0.5f + 0.5f,  // Green
    0.0f,                                    // Blue
    1.0f                                     // Alpha
  };
  glClearBufferfv(GL_COLOR, 0, color);
}


