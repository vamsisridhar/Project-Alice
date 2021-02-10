#include "Application.h"
#include "common.h"
int main(){

    Application* app = new Application();
    app ->Run();
    delete app;
}