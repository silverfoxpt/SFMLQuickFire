#define STB_IMAGE_IMPLEMENTATION

#include <bits/stdc++.h>
#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include <shader.h>
#include <stb_image.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

//Global Const
unsigned int VAO;
unsigned int VBO;

unsigned int texture;
unsigned int texture2;

float vertices[] = {
    // first triangle
    -0.5f, 0.5f, 0.0f,      1.0f, 0.0f, 0.0f,   0.0f, 1.0f,// left 
    0.5f, -0.5f, 0.0f,      0.0f, 1.0f, 0.0f,   1.0f, 0.0f,// right
    -0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f,   0.0f, 0.0f,// bottom 

    // second triangle
    -0.5f, 0.5f, 0.0f,  1.0f, 0.0f, 0.0f,    0.0f, 1.0f,// left 
    0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,    1.0f, 0.0f,// right
    0.5f, 0.5f, 0.0f,   0.0f, 0.0f, 1.0f,    1.0f, 1.0f,// top */
}; 

float texCoords[] = {
    0.0f, 0.0f,  // lower-left corner  
    1.0f, 0.0f,  // lower-right corner
    0.5f, 1.0f   // top-center corner
};

Shader myShader;
void SetUpShaders() {
    myShader = Shader("../Shaders/examplevert.vert", "../Shaders/examplefrag.frag");
}

void PrepareForRendering() {
    //Configure Vertex Buffer Object (VBO)
    glGenBuffers(1, &VBO);  

    //Configure Vertex Array Object (VAO)
    glGenVertexArrays(1, &VAO);  
    glBindVertexArray(VAO);

    //Vertices to VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);     
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

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

    //Handle Textures
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);  

    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // load and generate the texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load("../res/wall.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    //Handle Textures 2
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);  

    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // load and generate the texture
    unsigned char *data2 = stbi_load("../res/awesomeface.png", &width, &height, &nrChannels, 0);
    if (data2)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture 2" << std::endl;
    }
    stbi_image_free(data2);

    //set uniforms
    myShader.use();
    myShader.setInt("ourTexture", 0);
    myShader.setInt("newTexture", 1);
}

void Rendering() {
    //Change Background Color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    /*float timeValue = glfwGetTime();
    float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
    int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");*/

    //Set program
    //glUseProgram(shaderProgram);
    
    //myShader.setFloat("offsetX", 0.5f);

    //Set Uniforms
    //glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

    //bind texture
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);


    myShader.use();
    //Bind to VAO
    glBindVertexArray(VAO);

    //Draw Object
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

int InitializeOpenGL() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  
    GLFWwindow* window = glfwCreateWindow(800, 600, "QuickFire", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  
    
    SetUpShaders();
    PrepareForRendering();

    while(!glfwWindowShouldClose(window))
    {
        processInput(window);

        //Rendering
        Rendering();

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    glfwTerminate();
    return 0;
}

int main()
{
    return InitializeOpenGL();
    
}