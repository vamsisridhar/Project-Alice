#pragma once
#include "common.h"

class Shape{

    public:

        virtual ~Shape(){};

        unsigned int VAO;
        unsigned int VBO;
        
        unsigned int EBO;
        void LoadBuffers(float* vertices, unsigned int* indices, int sizeof_vertices, int sizeof_indices);
        virtual void Draw(){};
        


};


class Rect:public Shape{
    public:
        Rect(float posX, float posY, float width, float height);
    
        virtual ~Rect(){};

        virtual void Draw();

};