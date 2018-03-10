#include <vector>
class Vertex3D
{
    public:
        double x,y,z;
	void translatex(double dx)
	{
		x=x+dx;
	}
	void translatey(double dy)
	{
		y=y+dy;
	}
	void translatez(double dz)
	{
		z=z+dz;
	}
	void rotate(double delta, double theta, bool dirdelta, bool dirtheta, Vertex3D axis)
	{
		//rotates
	}
};

class Edge3D
{
    public:
        double x1,y1,z1;
	double x2,y2,z2;
	void translatex(double dx)
	{
		//translate the edge in x direction
	}
	void translatey(double dy)
	{
		//y direction
	}
	void translatez(double dz)
	{
		//z direction
	}
	void rotate(double delta, double theta, bool dirdelta, bool dirtheta, Vertex3D axis)
	{
		//rotates
	}
};

class Plane3D
{
    public:
        std::vector<Edge3D> plane;
	void translatex(double dx)
	{
		//translate the edge in x direction
	}
	void translatey(double dy)
	{
		//y direction
	}
	void translatez(double dz)
	{
		//z direction
	}
	void rotate(double delta, double theta, bool dirdelta, bool dirtheta, Vertex3D axis)
	{
		//rotates
	}
};
class HiddenEdge3D
{
    public:
        double x1,y1,z1;
	double x2,y2,z2;
	void translatex(double dx)
	{
		//translate the edge in x direction
	}
	void translatey(double dy)
	{
		//y direction
	}
	void translatez(double dz)
	{
		//z direction
	}
	void rotate(double delta, double theta, bool dirdelta, bool dirtheta, Vertex3D axis)
	{
		//rotates
	}
};
class VisibleEdge3D
{
    public:
        double x1,y1,z1;
	double x2,y2,z2;
	void translatex(double dx)
	{
		//translate the edge in x direction
	}
	void translatey(double dy)
	{
		//y direction
	}
	void translatez(double dz)
	{
		//z direction
	}
	void rotate(double delta, double theta, bool dirdelta, bool dirtheta, Vertex3D axis)
	{
		//rotates
	}
};
class ThreeDBody
{
	public:
		std::vector<Vertex3D> v;
		std::vector<Edge3D> e;
		std::vector<Plane3D> p;
		std::vector<HiddenEdge3D> he;
		std::vector<VisibleEdge3D> ve;

};

