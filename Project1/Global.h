/* Holds the includes and namespace usage needed for most if not all source files, as well as the externs for tempVars */

#pragma once
#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include "sfwdraw.h"
using namespace sfw;
using namespace std;

//in main.cpp
extern void runMain();

//in menuDraw.cpp
extern float SCREEN_X;
extern float SCREEN_Y;

//in tempVars.cpp
extern int iTemp;
extern int iTemp2;
extern int iTemp3;

extern float fTemp;

extern char cTemp;

extern bool bTemp;
