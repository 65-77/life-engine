#include "../dep/glad/include/glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void framebuffer_size_callback(GLFWwindow* /*window*/, int width, int height)
{
    glViewport(0, 0, width, height);
}


const unsigned int window_w = 640;	// width
const unsigned int window_h = 640;	// height

int main() {
   glfwInit();
   /* Setting window (inititaton?) properties */
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
   glfwWindowHint(GLFW_POSITION_X, 0);
   glfwWindowHint(GLFW_POSITION_Y, 0);
   
   if(!glfwInit()) {
      glfwTerminate();
   }
   
   /* creates glfw window */
   GLFWwindow* window = glfwCreateWindow(window_w, window_h, "Simple complexity", NULL, NULL);
   
   if (!window) {
      std::cout << __LINE__ << ": Failed to create GLFW window";
      glfwTerminate();
   }

   glfwMakeContextCurrent(window);
   glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

   if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
      std::cout << __LINE__ << ": Failed to initialize glad" << std::endl;
      glfwTerminate();
      return -1;
   }

   /* initialize GL functions after glad */
   
   glViewport(0, 0, window_w, window_h);

   /* main loop */
   while(!glfwWindowShouldClose(window)) {
      glfwSwapBuffers(window);
      glfwPollEvents();
   }

   glfwTerminate(); 
   std::cout << "Total lines: "<< __LINE__+2 << std::endl;
   return 0;
}
