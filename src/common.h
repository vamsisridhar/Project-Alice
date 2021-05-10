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

extern int WIN_WIDTH;
extern int WIN_HEIGHT;

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Shader.h>