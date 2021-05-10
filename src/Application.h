#pragma once
#include <common.h>


class Application
{
    public:
        Application(int &WIN_WIDTH, int &WIN_HEIGHT, const char* &WIN_TITLE);
        virtual ~Application();
        void Run(const int& fps);

    private:
        static void errorCallback(int error, const char* description){fprintf(stderr, "Error: %s\n", description);}
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)glfwSetWindowShouldClose(window, GLFW_TRUE);}
        void WinInit(); 
        void LoadShaders();
    protected:
        int w_width, w_height;
        const char* w_title;
        bool w_running = true;
        GLFWwindow* window;
        Shader* shaderProgram;

};