#include "Application.h"
#include "EventHandler.h"
#include <glfw/glfw3.h>
#include <glad/glad.h>
#include "common.h"
int WIN_WIDTH = 1920;
int WIN_HEIGHT = 1080;

Application::Application(){
    this->w_width = WIN_WIDTH;
    this->w_height = WIN_HEIGHT;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) exit(EXIT_FAILURE);

    LOG("Creating window of size: "<< std::to_string(w_width)<< ", "<<  std::to_string(w_height));

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

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

    LoadShaders();

 
        

}

Application::~Application(){
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

void Application::LoadShaders(){
    const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\0";

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

}

void Application::Run(){
    LOG("Initating Entry Point...");


    

    
    std::vector<Shape*> RenderQueue;
    float s = 200;
    float increment = 5;
    while(m_Running && !glfwWindowShouldClose(window)){
        glfwGetWindowSize(window, &WIN_WIDTH, &WIN_HEIGHT);
        LOG(WIN_WIDTH << " " << WIN_HEIGHT);


        if (s>=500 || s<=100)
        {
            increment = -increment;
        }

        s += increment;

        Sleep((1/60)*1000);
        Rect* rect = new Rect(200, 300, s, s);
        RenderQueue.push_back(&*rect);

        Render(RenderQueue);

        



        for (size_t i = 0; i < RenderQueue.size(); i++)
        {

            delete (RenderQueue[i]);
            RenderQueue[i] = nullptr;
            
        }
        
        


        RenderQueue.clear();
        //LOG(RenderQueue[0]);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Application::Render(std::vector<Shape*> &RenderQueue){
    

    glScalef(w_width, w_height, 0);
    glClearColor(1.0f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    for (size_t i = 0; i < RenderQueue.size(); i++)
    {
        //LOG("RENDER LOOP");
        // draw our first triangle
        glUseProgram(shaderProgram);
        RenderQueue[i]->Draw(); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        
    }
    
        
    glBindVertexArray(0);

}