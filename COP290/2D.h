#include <math.h>
#include <vector>
class Vertex2D
{
    public:
        double x,y;
	void translatex(double dx)
	{
		x=x+dx;
	}
	void translatey(double dy)
	{
		y=y+dy;
	}
	
	void rotate(double delta, bool dirdelta)
	{
		double tempx, tempy;
		
		if(dirdelta==true)//anticlockwise rotation
		{
			tempx=((x)*cos(delta))+((y)*sin(delta));
			tempy=-((x)*sin(delta))+((y)*cos(delta));
			x=tempx;
			y=tempy;
		}
		else
		{
			tempx=((x)*cos(delta))-((y)*sin(delta));
			tempy=((x)*sin(delta))+((y)*cos(delta));
			x=tempx;
			y=tempy;
		}
	}
};

class VisibleEdge
{
    public:
        double x1,y1;
		double x2,y2;

	void translatex(double dx)
	{
		x1=x1+dx;
		x2=x2+dx;//translate the edge in x direction
	}
	void translatey(double dy)
	{
		y1=y1+dy;
		y2=y2+dy;//y direction
	}
	void rotate(double delta, bool dirdelta)
	{
		double tempx1, tempy1;
		double tempx2, tempy2;
		if(dirdelta==true)//anticlockwise rotation
		{
			tempx1=((x1)*cos(delta))+((y1)*sin(delta));
			tempy1=-((x1)*sin(delta))+((y1)*cos(delta));
			x1=tempx1;
			y1=tempy1;
			tempx2=((x2)*cos(delta))+((y2)*sin(delta));
			tempy2=-((x2)*sin(delta))+((y2)*cos(delta));
			x2=tempx2;
			y2=tempy2;
		}
		else
		{
			tempx1=((x1)*cos(delta))-((y1)*sin(delta));
			tempy1=((x1)*sin(delta))+((y1)*cos(delta));
			x1=tempx1;
			y1=tempy1;
			tempx2=((x2)*cos(delta))-((y2)*sin(delta));
			tempy2=((x2)*sin(delta))+((y2)*cos(delta));
			x2=tempx2;
			y2=tempy2;
		}//rotates
	}
};

class OrthographicView
{
	public:
		int view_type;

};

class HiddenEdge
{
    public:
        double x1,y1;
		double x2,y2;

	void translatex(double dx)
	{
		x1=x1+dx;
		x2=x2+dx;//translate the edge in x direction
	}
	void translatey(double dy)
	{
		y1=y1+dy;
		y2=y2+dy;//y direction
	}
	void rotate(double delta, bool dirdelta)
	{
		double tempx1, tempy1;
		double tempx2, tempy2;
		if(dirdelta==true)//anticlockwise rotation
		{
			tempx1=((x1)*cos(delta))+((y1)*sin(delta));
			tempy1=-((x1)*sin(delta))+((y1)*cos(delta));
			x1=tempx1;
			y1=tempy1;
			tempx2=((x2)*cos(delta))+((y2)*sin(delta));
			tempy2=-((x2)*sin(delta))+((y2)*cos(delta));
			x2=tempx2;
			y2=tempy2;
		}
		else
		{
			tempx1=((x1)*cos(delta))-((y1)*sin(delta));
			tempy1=((x1)*sin(delta))+((y1)*cos(delta));
			x1=tempx1;
			y1=tempy1;
			tempx2=((x2)*cos(delta))-((y2)*sin(delta));
			tempy2=((x2)*sin(delta))+((y2)*cos(delta));
			x2=tempx2;
			y2=tempy2;
		}//rotates
	}
};

class TwoDBody
{
	public:
		std::vector<Vertex2D> v;
		std::vector<VisibleEdge> ve;
		std::vector<HiddenEdge> he;
		std::vector<OrthographicView> view;

};

