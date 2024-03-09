#include <bits/stdc++.h>
#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include <shader.h>

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
unsigned int shaderProgram;

float vertices[] = {
    // first triangle
    -0.5f, 0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // left 
    0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,   // bottom 

    // second triangle
    -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,    // left 
    0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,    // right
    0.5f, 0.5f, 0.0f,  0.0f, 0.0f, 1.0f     // top 
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  

    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    //Unbind VAO and VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0); 
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
    myShader.use();

    //Set Uniforms
    //glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

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
    
    PrepareForRendering();
    SetUpShaders();

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