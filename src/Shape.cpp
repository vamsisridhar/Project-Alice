#include <Shape.h>


void Shape::LoadBuffers(float* vertices, int sizeof_vertices){

    glGenBuffers(1, &VBO);
    {
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * sizeof_vertices, vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    glGenVertexArrays(1, &VAO);
    {
        glBindVertexArray(VAO);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }


}

Rect::Rect(float posX, float posY, float w, float h){

    float vertices[] = {
        -0.5f, 0.5f, 0.0f, // top left point
        0.5f, 0.5f, 0.0f, // top right point
        0.5f, -0.5f, 0.0f, // bottom right point
        0.5f, -0.5f, 0.0f, // bottom right point
        -0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f // bottom left point
   
    };

    LoadBuffers(vertices, 3 * 6);

}

void Rect::Draw(){

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3 * 6);

}

Cube::Cube(float posX, float posY, float s){


    float vertices[] = {
        -0.5f, -0.5f, -0.5f, 
        0.5f, -0.5f, -0.5f, 
        0.5f,  0.5f, -0.5f, 
        0.5f,  0.5f, -0.5f, 
        -0.5f,  0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f,  0.5f, 
        0.5f, -0.5f,  0.5f, 
        0.5f,  0.5f,  0.5f, 
        0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f,  0.5f, 
        -0.5f, -0.5f,  0.5f, 
        -0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f,  0.5f, 
        -0.5f,  0.5f,  0.5f, 
        0.5f,  0.5f,  0.5f, 
        0.5f,  0.5f, -0.5f, 
        0.5f, -0.5f, -0.5f, 
        0.5f, -0.5f, -0.5f, 
        0.5f, -0.5f,  0.5f, 
        0.5f,  0.5f,  0.5f, 
        -0.5f, -0.5f, -0.5f, 
        0.5f, -0.5f, -0.5f, 
        0.5f, -0.5f,  0.5f, 
        0.5f, -0.5f,  0.5f, 
        -0.5f, -0.5f,  0.5f, 
        -0.5f, -0.5f, -0.5f, 
        -0.5f,  0.5f, -0.5f, 
        0.5f,  0.5f, -0.5f, 
        0.5f,  0.5f,  0.5f, 
        0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f, -0.5f
    };

    LoadBuffers(vertices, 36*3);

}

void Cube::Draw(){

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36*3);

}