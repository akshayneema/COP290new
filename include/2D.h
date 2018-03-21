#ifndef TWOD_H
#define TWOD_H
#include <math.h>
#include <vector>
#include <string>
using namespace std;

class Vertex2D
{
    public:
        double x,y;
		string imp_label;
		vector<string> vec_label;
		
	
	
	void rotate(double delta, bool dirdelta);
};

class VisibleEdge
{
    public:
        double x1,y1;
		double x2,y2;
		string a,b;         //Edge bw imp_label

	
	void rotate(double delta, bool dirdelta);
};

class OrthographicView
{
	public:
		int view_type;

};

class Label
{
	public:
		string label;
};

class HiddenEdge
{
    public:
        double x1,y1;
		double x2,y2;

	
	void rotate(double delta, bool dirdelta);
};

class Edge2D
{
	public:
		double x1, y1;
		double x2, y2;
		bool visibility;
};

class Plane2D
{
	public:
		std::vector<Edge2D> plane;
};


//Assume that we have got the number of vertices.
//Input Format (v1,v2,Label a)


class TwoDBody
{
	public:
		std::vector<Vertex2D> v;
		std::vector<VisibleEdge> ve;
		std::vector<HiddenEdge> he;
		std::vector<Edge2D> e;
		int val;

};

class Labelled2D
{
	public:
		std::vector<Vertex2D> v;
		std::vector<VisibleEdge> ve;
		std::vector<HiddenEdge> he;
		std::vector<Label> lbl;

};
#endif
