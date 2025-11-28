#include "../dep/glad/include/glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>

// declaring functions
// -------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// window width & height
const unsigned int window_w = 640; // width
const unsigned int window_h = 640; // height

int main() {
   glfwInit();
   // Setting window (inititaton?) configurations
   // -------------------------------------------
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
   glfwWindowHint(GLFW_POSITION_X, 0);
   glfwWindowHint(GLFW_POSITION_Y, 0);
   
   if(!glfwInit()) {
      glfwTerminate();
   }
   
   // creates glfw window
   // -------------------
   GLFWwindow* window = glfwCreateWindow(window_w, window_h, "Simple complexity", NULL, NULL);
   if (!window) {
      std::cout << __LINE__ << ": Failed to create GLFW window";
      glfwTerminate();
   }

   glfwMakeContextCurrent(window);
   glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

   if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){ // loads openGL function pointers
      std::cout << __LINE__ << ": Failed to initialize glad" << std::endl;
      glfwTerminate();
      return -1;
   }

   // initialize GL functions after glad
   // ----------------------------------
   
   glViewport(0, 0, window_w, window_h);

   // mainloop
   // -------
   while(!glfwWindowShouldClose(window)) {
      
      processInput(window); // checks for input

      glfwSwapBuffers(window); // swaps front and back buffer
      glfwPollEvents(); // processes events
   }

   glfwTerminate(); 
   std::cout << "Total lines: "<< __LINE__+2 << std::endl;
   return 0;
}

// processes inputs
// ----------------
void processInput(GLFWwindow *window){
   if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
      glfwSetWindowShouldClose(window, true);
   }
}

// Keeps glViewport static in case of change
// -----------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height){
   glViewport(0, 0, 640, 640);
}
