// We need to add #define GLFW_INCLUDE_NONE so we dont get multiple GL header
// included error.
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <cstddef>
#include <glad/glad.h>
#include <iostream>

int main() {
  // Initialize GLFW
  glfwInit();

  // We need to tell OpenGL what version of GL we are using
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

  // Here we tell GLFW that we want to use Core profile
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // We create the window with size 800 width and 800 height with the name app
  GLFWwindow *window = glfwCreateWindow(800, 800, "app", NULL, NULL);

  // Check if the window was initialized if it isnt we error
  if (window == NULL) {
    std::cout << "Error making window.";
    glfwTerminate();
    return -1;
  }

  // We show the window by adding it to the context.
  glfwMakeContextCurrent(window);

  // Load glad
  gladLoadGL();

  // set the viewport aka the dimenstions from x = 0, y = 0 to x = 800, y = 800
  glViewport(0, 0, 800, 800);

  // Set the color of the bg to a dark blue
  glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

  // The app loop, so while the app should continue running
  while (!glfwWindowShouldClose(window)) {
    // Clean the back buffer and assign it to the new color
    glClear(GL_COLOR_BUFFER_BIT);

    // Swap the back buffer with the front buffer
    glfwSwapBuffers(window);

    // Handle events like window resize, etc.
    glfwPollEvents();
  }

  // After the user closes the app we want to distroy the window
  glfwDestroyWindow(window);

  // Then we terminate the process
  glfwTerminate();

  return 0;
}
