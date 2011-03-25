#include "calcAreas.h"

/*
- calcCircleArea(...)
- calcRectArea(...)
*/

float calcCircleArea(float r)
{
	float PI = 3.14159f;
	return r*r*PI;
}

float calcRectArea(float width,float height)
{
	return width*height;
}