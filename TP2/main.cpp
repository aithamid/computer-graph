#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <cmath>

#include "common/GLShader.h"

struct vec2 { float x, y; };
struct vec3 { float x, y, z; };
struct vec4 { float x, y, z, w; };

struct Vertex
{
    vec2 position;
    vec3 color;
};

struct Application
{
    GLShader g_BasicShader;

    void Initialize()
    {
        g_BasicShader.LoadVertexShader("basic.vs.glsl");
        g_BasicShader.LoadFragmentShader("basic.fs.glsl");
        g_BasicShader.Create();
        // GLuint vao;
        // glGenVertexArrays(1, &vao);
        // glBindVertexArray(vao);
    }

    void Terminate()
    {
        g_BasicShader.Destroy();
    }

    void Render(int width, int height)
    { 
        // etape a. A vous de recuperer/passer les variables width/height
        glViewport(0, 0, width, height);
        
        // etape b. Notez que glClearColor est un etat, donc persistant
        glClearColor(1.f, 1.f, 1.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        // etape c. on specifie le shader program a utiliser
        uint32_t basicProgram = g_BasicShader.GetProgram();
        glUseProgram(basicProgram);

        // etape d.
		const std::vector<Vertex> triangle =
		{
			{ { 0.0f, 0.5f }, {1.0, 1.0, 0.0} },    // sommet 0
			{ { -0.5f, -0.5f }, {1.0, 0.0, 0.0} },  // sommet 1
			{ { 0.5f, -0.5f }, {0.0, 1.0, 1.0} },   // sommet 2
		};

        // etape e.
        int loc_position = glGetAttribLocation(basicProgram, "a_Position");
        glEnableVertexAttribArray(loc_position);
        glVertexAttribPointer(loc_position, 2, GL_FLOAT, false, sizeof(Vertex), triangle.data());

        int loc_color = glGetAttribLocation(basicProgram, "a_Color");
        glEnableVertexAttribArray(loc_color);
        glVertexAttribPointer(loc_color, 3, GL_FLOAT, false, sizeof(Vertex), &triangle[0].color);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // on suppose que la phase d’echange des buffers front et back
        // le « swap buffers » est effectuee juste apres

    }
};



int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    int width = 640;
    int height = 480;
    window = glfwCreateWindow(640, 480, "Exemple OpenGL 2.+", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // ICI !
    GLenum error = glewInit();
    if (error != GLEW_OK) {
        std::cout << "Erreur d'initialisation de GLEW" << std::endl;
    }

    Application app;
    app.Initialize();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {        
        /* Render here */
        app.Render(width, height);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    app.Terminate();

    glfwTerminate();
    return 0;
}