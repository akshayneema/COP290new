#ifndef THREED_H
#define THREED_H
#include <vector>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;

class Vertex3D
{
    public:
        double x,y,z,l;
		string str;
	
	void rotatex(double delta, bool dirdelta);
	void rotatey(double delta, bool dirdelta);
	void rotatez(double delta, bool dirdelta);
	void rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz);
};

class Edge3D
{
    public:
        double x1,y1,z1;
		double x2,y2,z2;
		bool visibility=true;
	void rotatex(double delta, bool dirdelta);
	void rotatey(double delta, bool dirdelta);
	void rotatez(double delta, bool dirdelta);
	void rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz);
	
};

class Plane3D
{
    public:
        std::vector<Edge3D> plane;
	void rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz);
};
class HiddenEdge3D
{
    public:
        public:
        double x1,y1,z1;
	double x2,y2,z2;
	void rotatex(double delta, bool dirdelta);
	void rotatey(double delta, bool dirdelta);
	void rotatez(double delta, bool dirdelta);
	void rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz);
};
class VisibleEdge3D
{
        public:
        double x1,y1,z1;
	double x2,y2,z2;
	void rotatex(double delta, bool dirdelta);
	void rotatey(double delta, bool dirdelta);
	void rotatez(double delta, bool dirdelta);
	void rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz);
};
class ThreeDBody
{
	public:
		std::vector<Vertex3D> v;
		std::vector<Edge3D> e;
		std::vector<Plane3D> p;
		std::vector<HiddenEdge3D> he;
		std::vector<VisibleEdge3D> ve;
	void rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz);
	

};
#endif

