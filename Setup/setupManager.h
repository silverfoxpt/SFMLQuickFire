#ifndef H_SETUP_MANAGER
#define H_SETUP_MANAGER

#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <random>
#include <memory>
#include <chrono>

class MainManager {
    public:
        int width, height; 
        GLFWwindow* window;

        MainManager(int width, int height) {
            this->width = width;
            this->height = height;

            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        
            this->window = glfwCreateWindow(width, height, "QuickFire", NULL, NULL);
            if (this->window == NULL)
            {
                std::cerr << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
                //return -1;
                return;
            }
            glfwMakeContextCurrent(this->window);

            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                std::cerr << "Failed to initialize GLAD" << std::endl;
                //return -1;
                return;
            }    

            glEnable(GL_DEPTH_TEST);
            glfwSetFramebufferSizeCallback(this->window, framebuffer_size_callback);  
        }

        static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
        {
            glViewport(0, 0, width, height);
        } 
};

#endif