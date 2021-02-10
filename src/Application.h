#pragma once
#include <glfw/glfw3.h>
#include <glad/glad.h>
#include "EventHandler.h"
#include "common.h"
class Application
{
    public:
        Application();
        virtual ~Application();
        void Run();
    private:
        int w_width, w_height;
        bool m_Running = true;
        
        static void error_callback(int error, const char* description){fprintf(stderr, "Error: %s\n", description);}
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)glfwSetWindowShouldClose(window, GLFW_TRUE);}

        void Events();
        void Update();
        void Render();

    protected:
        GLFWwindow* window;

        EventHandler* ev_handler;

};