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



Rect::Rect(float scalex, float scaley){

    float vertices[] = {
        -1.0f, 1.0f, 0.0f, // top left point
        1.0f, 1.0f, 0.0f, // top right point
        1.0f, -1.0f, 0.0f, // bottom right point
        1.0f, -1.0f, 0.0f, // bottom right point
        -1.0f, 1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f // bottom left point
   
    };
    


    
    LoadBuffers(vertices, 3 * 6);

}

void Rect::Draw(Shader *shaderProgram){

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3 * 6);

}

Cube::Cube(float posX, float posY, float posZ){

    this->posX = posX;
    this->posY = posY;
    this->posZ = posZ;

    float vertices[] = {
        -1.0f, -1.0f, -1.0f, 
        1.0f, -1.0f, -1.0f, 
        1.0f,  1.0f, -1.0f, 
        1.0f,  1.0f, -1.0f, 
        -1.0f,  1.0f, -1.0f, 
        -1.0f, -1.0f, -1.0f, 
        -1.0f, -1.0f,  1.0f, 
        1.0f, -1.0f,  1.0f, 
        1.0f,  1.0f,  1.0f, 
        1.0f,  1.0f,  1.0f, 
        -1.0f,  1.0f,  1.0f, 
        -1.0f, -1.0f,  1.0f, 
        -1.0f,  1.0f,  1.0f, 
        -1.0f,  1.0f, -1.0f, 
        -1.0f, -1.0f, -1.0f, 
        -1.0f, -1.0f, -1.0f, 
        -1.0f, -1.0f,  1.0f, 
        -1.0f,  1.0f,  1.0f, 
        1.0f,  1.0f,  1.0f, 
        1.0f,  1.0f, -1.0f, 
        1.0f, -1.0f, -1.0f, 
        1.0f, -1.0f, -1.0f, 
        1.0f, -1.0f,  1.0f, 
        1.0f,  1.0f,  1.0f, 
        -1.0f, -1.0f, -1.0f, 
        1.0f, -1.0f, -1.0f, 
        1.0f, -1.0f,  1.0f, 
        1.0f, -1.0f,  1.0f, 
        -1.0f, -1.0f,  1.0f, 
        -1.0f, -1.0f, -1.0f, 
        -1.0f,  1.0f, -1.0f, 
        1.0f,  1.0f, -1.0f, 
        1.0f,  1.0f,  1.0f, 
        1.0f,  1.0f,  1.0f, 
        -1.0f,  1.0f,  1.0f, 
        -1.0f,  1.0f, -1.0f
    };

    LoadBuffers(vertices, 36*3);

    ;

}

void Cube::Draw(Shader *shaderProgram){

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(posX, posY, posZ)); 
    model = glm::rotate(model, (float)(glm::radians(60.0) * (float)glfwGetTime()), glm::vec3(1.0f, 0.3f, 0.5f));
    int modelLoc = glGetUniformLocation(shaderProgram->ID, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36*3);

}