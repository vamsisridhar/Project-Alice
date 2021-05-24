#pragma once
#include <common.h>

class Shape{

    public:

        virtual ~Shape(){};

        unsigned int VAO;
        unsigned int VBO;
        
        unsigned int EBO;
        void LoadBuffers(float* vertices, int sizeof_vertices);
        virtual void Draw(Shader *shaderProgram){};

        float posX, posY, posZ; /// Needs to be made into Vector

};

class Rect:public Shape{
    public:
        Rect(float scalex, float scaley);

        virtual ~Rect(){};

        virtual void Draw(Shader *shaderProgram);
};

class Cube:public Shape{
    public:
        Cube(float scalex, float scaley, float scalez);

        virtual ~Cube(){};

        virtual void Draw(Shader *shaderProgram);
};