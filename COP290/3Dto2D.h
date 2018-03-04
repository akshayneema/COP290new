#ifndef OD_H
#define OD_H
#include "3D.h"
#endif

#ifndef OD2_H
#define OD2_H
#include "2D.h"
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
std::vector<float> normalofplane(char* plane)
{
	//derives normal of the plane
}
void rotate3D(ThreeDBody threedbody, std::vector<float> normal, std::vector<char> plane)
{
	//rotate the coordinate axes and updates the 3D object coordinates
}
void hiddenedgedetection(ThreeDBody threedbody, std::vector<char> plane)
{
	//for every edge classifies it into hidden-part and visible-part and updates vertices accordingly
}
TwoDBody TopView(ThreeDBody threedbody)
{
	//takes top view of all the vertices, hidden edges and visible edges
}
