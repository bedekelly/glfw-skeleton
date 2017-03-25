#include <GLFW/glfw3.h>
#include <iostream>
#include <linmath.h>

#include "skeleton_utils.h"


int main(int argc, char **argv) {
  GLFWwindow* window = createWindow(".plain blue.");
  glClear(GL_COLOR_BUFFER_BIT);

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Do something cool!

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  cleanExit(window);
}
