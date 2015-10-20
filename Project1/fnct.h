#pragma once

//in fnctMath.cpp
extern int extractTensPlace(int a);
extern float frac(float div, float num, float den);
extern void graphPoly(int terms, float coef[], float length, float X, float Y, bool lengthIsHeight, bool flip);

//int fnctCvrt.cpp
extern int getIntFromChar(char a);
extern char getCharFromInt(int a);