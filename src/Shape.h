#pragma once
#include "common.h"

class Shape{

    public:

        virtual ~Shape(){};

        unsigned int VAO;
        unsigned int VBO;
        
        unsigned int EBO;
        void LoadBuffers(float* vertices, int sizeof_vertices);
        virtual void Draw(){};

};

class Rect:public Shape{
    public:
        Rect(float posX, float posY, float width, float height);

        virtual ~Rect(){};

        virtual void Draw();
};

class Cube:public Shape{
    public:
        Cube(float posX, float posY, float scale);

        virtual ~Cube(){};

        virtual void Draw();
};