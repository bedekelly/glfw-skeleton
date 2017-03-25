#include <iostream>
#include "GLFW/glfw3.h"

#include "linmath.h"

#include "skeleton.h"


int main() {

    GLFWwindow* window = windowBegin();

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    windowEnd(window);
}


/**
 * Callback for whenever GLFW encounters an error.
 * @param error The error code for the problem GLFW encountered.
 * @param description A short description of why the error occurred.
 */
void error_callback(int error, const char* description) {
    std::cerr << "Error: " << description << std::endl;
}


/**
 * Create and return a window, with all necessary error-checking.
 * @return A GLFW window with a current OpenGL context.
 */
GLFWwindow* windowBegin() {
    // Initialize variables.
    GLFWwindow* window;
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;

    // Set an error callback for GLFW to use.
    glfwSetErrorCallback(error_callback);

    // Check we've initialized GLFW correctly.
    if (!glfwInit())
        exit(EXIT_FAILURE);

    // Ensure we get the right version of OpenGL.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // Create our window, and check it's initialized correctly.
    window = glfwCreateWindow(640, 480, "plain blue.", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // OpenGL should hold state about this current window.
    glfwMakeContextCurrent(window);

    // Enable V-Sync.
    glfwSwapInterval(1);

    // Set the default clear-colour to a dark blue.
    glClearColor(0.1, 0.3, 0.5, 1.0);

    return window;
}


/**
 * When we're finished with the GLFW window, this function should be
 * called to terminate it and exit cleanly.
 * @param window: The GLFW window to terminate.
 */
void windowEnd(GLFWwindow* window) {
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
