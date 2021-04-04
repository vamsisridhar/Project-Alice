#pragma once
#include <glfw/glfw3.h>
#include <glad/glad.h>
#include "EventHandler.h"
#include "common.h"
#include "Primitives/Shape.h"
class Application
{
    public:
        Application();
        virtual ~Application();
        void Run();
    private:

        
        static void error_callback(int error, const char* description){fprintf(stderr, "Error: %s\n", description);}
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)glfwSetWindowShouldClose(window, GLFW_TRUE);}

        void Events();
        void Update();
        void Render(std::vector<Shape*> &RenderQueue);
        void LoadShaders();
        void MathDebug();

    protected:
        int w_width, w_height;
        bool m_Running = false;
        GLFWwindow* window;

        EventHandler* ev_handler;
        unsigned int shaderProgram;
        

};