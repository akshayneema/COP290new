#include <vector>
class Vertex2D
{
    public:
        float x,y;
	void translatex(float dx)
	{
	
	}
	void translatey(float dy)
	{
	
	}
	
	void rotate(float delta, bool dirdelta, Vertex2D axis)
	{
		//rotates
	}
};

class VisibleEdge
{
    public:
        float x1,y1;
		float x2,y2;

	void translatex(float dx)
	{
		//translate the edge in x direction
	}
	void translatey(float dy)
	{
		//y direction
	}
	void rotate(float delta, bool dirdelta, Vertex2D axis)
	{
		//rotates
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
        float x1,y1;
		float x2,y2;

	void translatex(float dx)
	{
		//translate the edge in x direction
	}
	void translatey(float dy)
	{
		//y direction
	}
	void rotate(float delta, bool dirdelta, Vertex2D axis)
	{
		//rotates
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

