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

#include "cameraSetup.h"

class MainManager {
    public:
        int width, height; 
        GLFWwindow* window;
        static Camera* camera;

        static bool firstMouse;
        static float lastX;
        static float lastY;

        MainManager(int width, int height, Camera* cameraIn) {
            this->width = width;
            this->height = height;
            camera = cameraIn;

            firstMouse = true;
            lastX  = width / 2.0f;
            lastY = height / 2.0f;

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
            glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);  

            glfwSetCursorPosCallback(this->window, mouse_callback); 
            glfwSetScrollCallback(this->window, scroll_callback);
        }

        static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
        {
            glViewport(0, 0, width, height);
        } 

        static void mouse_callback(GLFWwindow* window, double xposIn, double yposIn) {
            float xpos = static_cast<float>(xposIn);
            float ypos = static_cast<float>(yposIn);

            if (firstMouse)
            {
                lastX = xpos;
                lastY = ypos;
                firstMouse = false;
            }

            float xoffset = xpos - lastX;
            float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

            lastX = xpos;
            lastY = ypos;

            camera->ProcessMouseMovement(xoffset, yoffset);
        }

        static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
        {
            camera->ProcessMouseScroll(static_cast<float>(yoffset));
        }
};

#endif