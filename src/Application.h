#pragma once
#include <common.h>


class Application
{
    public:
        Application(float &WIN_WIDTH, float &WIN_HEIGHT, const char* &WIN_TITLE);
        virtual ~Application();
        void Run(const int& fps);
    /*
        float* Gravity(float x1,float y1,float z1,float x2,float y2,float z2){
            float m1 = 1.0f;
            float m2 = 2.0f;
            float r_sq = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2);
            float F = (m1*m2)/(r_sq);

        };      
    */
    private:
        static void errorCallback(int error, const char* description){fprintf(stderr, "Error: %s\n", description);}
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)glfwSetWindowShouldClose(window, GLFW_TRUE);}
        void WinInit(); 
        void LoadShaders();
    protected:
        float w_width, w_height;
        const char* w_title;
        bool w_running = true;
        GLFWwindow* window;
        Shader* shaderProgram;

};