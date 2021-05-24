#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <ostream>
#include <vector>
#include <windows.h>
#include <functional>
#include <algorithm>
#include <stdarg.h>
#include <fstream>
#include <sstream>

#define LOG(...) std::cout << __VA_ARGS__ << '\n'

extern float WIN_WIDTH;
extern float WIN_HEIGHT;

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <Shader.h>
#include <Math/Math.h>