#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <cmath>

#include "common/GLShader.h"

struct vec2 { float x, y; };
struct vec3 { float x, y, z; };

struct Vertex
{
    vec2 position;
    vec3 color;
};

struct Application
{
    GLShader g_BasicShader;
    GLuint VBO, IBO;

    void Initialize()
    {
        g_BasicShader.LoadVertexShader("basic.vs.glsl");
        g_BasicShader.LoadFragmentShader("basic.fs.glsl");
        g_BasicShader.Create();

        const std::vector<Vertex> vertices =
        {
            { { 0.5f, 0.5f }, {1.0, 1.0, 0.0} },  
            { { 0.5f, -0.5f }, {1.0, 0.0, 0.0} },  
            { { -0.5f, -0.5f }, {0.0, 1.0, 1.0} }, 
            { { -0.5f, 0.5f }, {0.0, 0.0, 1.0} }, 
        };

        const std::vector<GLuint> indices = {
            0, 1, 3, 
            1, 2, 3  
        };


        glGenBuffers(1, &VBO);
        glGenBuffers(1, &IBO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);


        GLuint program = g_BasicShader.GetProgram();
        glUseProgram(program);

        GLint loc_Position = glGetAttribLocation(program, "a_Position");
        glEnableVertexAttribArray(loc_Position);
        glVertexAttribPointer(loc_Position, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

        GLint loc_Color = glGetAttribLocation(program, "a_Color");
        glEnableVertexAttribArray(loc_Color);
        glVertexAttribPointer(loc_Color, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

    }

    void Terminate()
    {
        g_BasicShader.Destroy();
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &IBO);
    }

    void Render(int width, int height)
    { 
        glViewport(0, 0, width, height);
        glClearColor(1.f, 1.f, 1.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }
};

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    int width = 640;
    int height = 480;
    window = glfwCreateWindow(width, height, "OpenGL Example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    GLenum error = glewInit();
    if (error != GLEW_OK) {
        std::cout << "GLEW Initialization Error" << std::endl;
        return -1;
    }

    Application app;
    app.Initialize();

    while (!glfwWindowShouldClose(window))
    {        
        app.Render(width, height);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    app.Terminate();
    glfwTerminate();
    return 0;
}
