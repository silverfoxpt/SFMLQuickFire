#include "rectangle.h"

Rectangle::Rectangle(MainManager* manager, float width, float height, glm::vec3 color) {
    this->mainManager = manager;
    this->width = width;
    this->height = height;

    this->convertedWidth = width / this->mainManager->width;
    this->convertedHeight = height / this->mainManager->height;

    //update vertex
    float newVertice[] = {
        // first triangle
        -convertedWidth/2, convertedHeight/2, 0.0f,     color.r, color.g, color.b,   0.0f, 1.0f, // left 
        convertedWidth/2, -convertedHeight/2, 0.0f,     color.r, color.g, color.b,   1.0f, 0.0f, // right
        -convertedWidth/2, -convertedHeight/2, 0.0f,    color.r, color.g, color.b,   0.0f, 0.0f, // bottom 

        // second triangle
        -convertedWidth/2, convertedHeight/2, 0.0f,     color.r, color.g, color.b,   0.0f, 1.0f, // left 
        convertedWidth/2, -convertedHeight/2, 0.0f,     color.r, color.g, color.b,   1.0f, 0.0f, // right
        convertedWidth/2, convertedHeight/2, 0.0f,      color.r, color.g, color.b,   1.0f, 1.0f // top 
    };

    //Configure Vertex Buffer Object (VBO)
    glGenBuffers(1, &VBO);  

    //Configure Vertex Array Object (VAO)
    glGenVertexArrays(1, &VAO);  
    glBindVertexArray(VAO);

    //Vertices to VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);     
    glBufferData(GL_ARRAY_BUFFER, sizeof(newVertice), newVertice, GL_STATIC_DRAW);

    //Configure Vertex Array - position attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  

    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    //texture attributes
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);  

    //Unbind VAO and VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0); 
}

void Rectangle::Use(glm::mat4 transform_matrix, Shader* shader, const char* transformUniformName) {
    glBindVertexArray(this->VAO);
    shader->use();

    unsigned int transformLoc = glGetUniformLocation(shader->ID, transformUniformName);
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform_matrix));

    glDrawArrays(GL_TRIANGLES, 0, 6);
}