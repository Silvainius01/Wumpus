#include "Global.h"
#include "fnct.h"

//This was a surprising thing that was neccesary for converting numbers to printable chars
int extractTensPlace(int num) //267  || 10 || 107 || 1953
{
	int a = 0;
	num = (num / 10) % 100; //267 -> 26.7 -> 26 || 10 -> 1 -> 1 || 107 -> 10.7 -> 10 || 1953 -> 195.3 -> 95

	for (a = 0; a < num; ++a)
	{
		if (a == 10)
		{
			num -= 10; //26...16...6 || N/A || 10...0 || 95...85...75...65...55...45..35...25...15...5
			a = 0;
		}
	}

	return a; //6 || 1 || 0 || 5
}

//The number you want divided, and then the numerator and denomonator
float frac(float div, float num, float den)
{
	return ((div / den) * num);
}

//coefs[] must have a number of values equal to terms
void graphPoly(int terms, float coef[], float length, float X, float Y)
{
	//ax^n + bx^n ... + c
	float carry = 0;
	float temp;
	float yVal = 0;
	float prevY = 0;
	float prevX = 0;
	if (terms < 1) { terms = 1; }

	for (int a = 0; a < length; a++)
	{
		if (terms == 1)
		{
			yVal = coef[0] + Y;
		}
		else if (terms == 2)
		{
			yVal = (X * coef[1]) + coef[0] + Y;
		}
		else
		{
			carry = 0;
			for (int b = terms; b != 2; b--) //b = 4 
			{
				if (coef[b - 1] != 0)
				{
					fTemp = X;
					for (int c = 0; c < b - 2; c++)
					{
						fTemp *= X; 
					}
					fTemp *= coef[b - 1];
					carry += fTemp;
				}
			}
			temp = (X * coef[1]) + coef[0] + Y;
			yVal = carry + temp;
		}

		drawLine(X, yVal, X - 1, yVal - 1);
		drawLine(prevX, prevY, X, yVal);
		prevX = X;
		prevY = yVal;
		cout << "(" << X << ", " << yVal << ")\n";
		X++;
	}
}