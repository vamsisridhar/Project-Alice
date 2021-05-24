#include <Application.h>
#include <Shape.h>



Application::Application(float &WIN_WIDTH, float &WIN_HEIGHT, const char* &WIN_TITLE){
    w_width = WIN_WIDTH;
    w_height = WIN_HEIGHT;
    w_title = WIN_TITLE;

    glfwSetErrorCallback(errorCallback);
    if(!glfwInit()) exit(EXIT_FAILURE);
    
    LOG("INITIALISING WINDOW ...");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(w_width, w_height, w_title, NULL, NULL);

    if(!window){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, keyCallback);

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);

    LoadShaders();
    LOG("WINDOW INITIALISED ...");




}

void Application::LoadShaders(){
    
    shaderProgram =  new Shader("../src/Shaders/shader.vs", "../src/Shaders/shader.fs");

}

void Application::Run(const int& FPS){
    
    while(w_running && !glfwWindowShouldClose(window)){
        std::vector<Shape*> renderQueue;
        Sleep((1/FPS)*1000);
        LOG("RUNNING...");

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        
        shaderProgram -> use();

                
        
        


        Cube* c1 = new Cube(2.0f, 5.0f, -15.0f);
        renderQueue.push_back(c1);
        Cube* c2 = new Cube(2.0f, -5.0f, -15.0f);
        renderQueue.push_back(c2);

        glm::mat4 view = glm::mat4(1.0f);
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        int viewLoc = glGetUniformLocation(shaderProgram->ID, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

        glm::mat4 projection;
        projection = glm::perspective(glm::radians(60.0f) , w_width/w_height , 0.1f, 100.0f);
        int projectionLoc = glGetUniformLocation(shaderProgram->ID, "projection");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
        

 
        for (size_t i = 0; i < renderQueue.size(); i++)
        {
            renderQueue[i]->Draw(shaderProgram);
        }

        renderQueue.clear();
        renderQueue.shrink_to_fit();
        

        glfwSwapBuffers(window);
        glfwPollEvents();

        
    }
}



Application::~Application(){
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

