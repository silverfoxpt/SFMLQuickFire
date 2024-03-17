#ifndef H_TEXTURE_TEMP_H
#define H_TEXTURE_TEMP_H

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

class Texture {
    public:
        unsigned int textureID;

        Texture(const char* pathToTex, bool includeAlpha);
        void Use(GLenum textureIndex, 
            Shader* myShader, const char* textureUniformPath, int textureUniformValue);
};

#endif