#include <vector>
class Vertex3D
{
    public:
        float x,y,z;
	void translatex(float dx)
	{
		
	}
	void translatey(float dy)
	{
	
	}
	void translatez(float dz)
	{
		
	}
	void rotate(float delta, float theta, bool dirdelta, bool dirtheta, Vertex3D axis)
	{
		//rotates
	}
};

class Edge3D
{
    public:
        float x1,y1,z1;
	float x2,y2,z2;
	void translatex(float dx)
	{
		//translate the edge in x direction
	}
	void translatey(float dy)
	{
		//y direction
	}
	void translatez(float dz)
	{
		//z direction
	}
	void rotate(float delta, float theta, bool dirdelta, bool dirtheta, Vertex3D axis)
	{
		//rotates
	}
};

class Plane3D
{
    public:
        std::vector<Edge3D> plane;
	void translatex(float dx)
	{
		//translate the edge in x direction
	}
	void translatey(float dy)
	{
		//y direction
	}
	void translatez(float dz)
	{
		//z direction
	}
	void rotate(float delta, float theta, bool dirdelta, bool dirtheta, Vertex3D axis)
	{
		//rotates
	}
};
class HiddenEdge3D
{
    public:
        float x1,y1,z1;
	float x2,y2,z2;
	void translatex(float dx)
	{
		//translate the edge in x direction
	}
	void translatey(float dy)
	{
		//y direction
	}
	void translatez(float dz)
	{
		//z direction
	}
	void rotate(float delta, float theta, bool dirdelta, bool dirtheta, Vertex3D axis)
	{
		//rotates
	}
};
class VisibleEdge3D
{
    public:
        float x1,y1,z1;
	float x2,y2,z2;
	void translatex(float dx)
	{
		//translate the edge in x direction
	}
	void translatey(float dy)
	{
		//y direction
	}
	void translatez(float dz)
	{
		//z direction
	}
	void rotate(float delta, float theta, bool dirdelta, bool dirtheta, Vertex3D axis)
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

