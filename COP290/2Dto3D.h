#ifndef TWOD_TO_THREED_H
#define TWOD_TO_THREED_H
#include "3D.h"
#include "2D.h"


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

// top-> xz  front -> xy left -> zy
ThreeDBody threeDlabel (TwoDBody &top,TwoDBody &front,TwoDBody &left); //,Labelled2D side
#endif