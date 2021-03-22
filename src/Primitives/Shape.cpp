#include "Shape.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"

void Shape::LoadBuffers(float* vertices, unsigned int* indices, int sizeof_vertices, int sizeof_indices){

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof_vertices * sizeof(float), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof_indices * sizeof(unsigned int), indices, GL_STATIC_DRAW); 

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

}

Rect::Rect(float posX, float posY, float w, float h){
    LOG("RECT");
    w = w/WIN_WIDTH;
    h = h/WIN_HEIGHT;

    
    
    std::vector<float> vertices = {
     w,  h, 0.0f,  // top right
     w, -h, 0.0f,  // bottom right
    -w, -h, 0.0f,  // bottom left
    -w,  h, 0.0f   // top left 
    };
    
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };  
    //LOG("CREATING RECT...");
    LoadBuffers(vertices.data(), indices, 12, 6);


}
void Rect::Draw(){

    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}