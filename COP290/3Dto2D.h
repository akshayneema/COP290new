#ifndef THREED_TO_TWOD_H
#define THREED_TO_TWOD_H
#include "3D.h"

#include "2D.h"


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <set>


std::vector<double> normalofplane(double a, double b, double c, double d);
ThreeDBody rotate3D(ThreeDBody &threedbody, std::vector<double> normal);
std::vector<Edge3D> edge_segmentation(ThreeDBody &threedbody);

void crossProduct(double vect_A[], double vect_B[], double cross_P[]);

int raycast(double x, double y, Plane2D plane);// 0-> out 1->in 2-> on the line

void hiddenedgedetection(ThreeDBody &threedbody, double a, double b, double c, double d);

TwoDBody TopView(ThreeDBody &threedbody);

void ThreeDBodi ( ThreeDBody need);
void type_equal (int type);
#endif
