#include "Application.h"
#include "EventHandler.h"
#include <glfw/glfw3.h>
#include <glad/glad.h>
#include "common.h"

Application::Application(){
    this->w_width = 300;
    this->w_height = 600;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) exit(EXIT_FAILURE);

    LOG("Creating window of size: "<< std::to_string(w_width)<< ", "<<  std::to_string(w_height));

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    ev_handler -> InitCallbackFuncs();

    window = glfwCreateWindow(this->w_width, this->w_height, "Alice", NULL, NULL);
    if (!window){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);

    LOG("Initialisation Finished...");
}

Application::~Application(){
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

void Application::Run(){
    LOG("Initating Entry Point...");
    while(m_Running && !glfwWindowShouldClose(window)){
        
        Render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Application::Render(){
    
        glClear(GL_COLOR_BUFFER_BIT);

        glClearColor(1.0, 0, 0, 1.0);

}