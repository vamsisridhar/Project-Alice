#include <common.h>
#include <Application.h>

float WIN_WIDTH = 1920.0f;
float WIN_HEIGHT = 1080.0f;

int main(){
    
    const char* WIN_TITLE = "Node Simulator Framework";
    const int FPS = 60;



    Application* app = new Application(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
    app -> Run(FPS);
    delete app;
}