#ifndef H_RECTANGLE_TEMP
#define H_RECTANGLE_TEMP

#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <random>
#include <memory>
#include <chrono>

#include <glad/glad.h> // include glad to get all the required OpenGL headers

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> 

#include <setupManager.h>
#include "shader.h"

class Rectangle {
    public:
        MainManager* mainManager;
        float width, height;
        float convertedWidth, convertedHeight;

        unsigned int VAO;
        unsigned int VBO;

        Rectangle(MainManager* manager, float width, float height, glm::vec3 color);
        Rectangle();

        void Use(glm::mat4 transform_matrix, Shader* shader, const char* transformUniformName);

};

#endif