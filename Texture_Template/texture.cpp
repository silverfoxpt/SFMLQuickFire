#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(const char* pathToTex, bool includeAlpha) {
    //Handle Textures
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);  

    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // load and generate the texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load(pathToTex, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, (includeAlpha) ? GL_RGBA : GL_RGB, 
            width, height, 0, (includeAlpha) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {   
        std::string pat = pathToTex;
        std::cout << "Failed to load texture: " + pat << std::endl;
    }
    stbi_image_free(data);
}

void Texture::Use(GLenum textureIndex, 
            Shader* myShader, const char* textureUniformPath, int textureUniformValue) {
    //set uniform 
    myShader->use();
    myShader->setInt(textureUniformPath, textureUniformValue);

    glActiveTexture(textureIndex);
    glBindTexture(GL_TEXTURE_2D, this->textureID);
}