#pragma once
#include <common.h>

class Vector{
    /*

    Vector class, supports up to 4 length 

    */
   
    public: 
        bool type = 0; // 0 - row, 1 - collumn
        int len;

        Vector();
        virtual ~Vector();

};

class Vector3:public Vector{

    

};