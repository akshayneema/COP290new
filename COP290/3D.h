#include <vector>
#include <math.h>
using namespace std;
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
	void rotatex(double delta, bool dirdelta)
	{
		double tempy, tempz;
		if(dirdelta==true)//anticlockwise rotation
		{
			tempy=((y)*cos(delta))+((z)*sin(delta));
			tempz=-((y)*sin(delta))+((z)*cos(delta));
			y=tempy;
			z=tempz;
		}
		else
		{
			tempy=((y)*cos(delta))-((z)*sin(delta));
			tempz=((y)*sin(delta))+((z)*cos(delta));
			y=tempy;
			z=tempz;
		}//rotates
	}
	void rotatey(double delta, bool dirdelta)
	{
		double tempx, tempz;
		if(dirdelta==true)//anticlockwise rotation
		{
			tempx=((x)*cos(delta))-((z)*sin(delta));
			tempz=((x)*sin(delta))+((z)*cos(delta));
			x=tempx;
			z=tempz;
		}
		else
		{
			tempx=((x)*cos(delta))+((z)*sin(delta));
			tempz=-((x)*sin(delta))+((z)*cos(delta));
			x=tempx;
			z=tempz;
		}//rotates
	}
	void rotatez(double delta, bool dirdelta)
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
		}//rotates
	}
	void rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz)
	{
		this->rotatex(deltax, dirx);
		this->rotatey(deltay, diry);
		this->rotatez(deltaz, dirz);
	}
};

class Edge3D
{
    public:
        double x1,y1,z1;
	double x2,y2,z2;
	void translatex(double dx)
	{
		x1= x1+dx;
		x2= x2+dx;//translate the edge in x direction
	}
	void translatey(double dy)
	{
		y1= y1+dy;
		y2= y2+dy;//y direction
	}
	void translatez(double dz)
	{
		z1= z1+dz;
		z2= z2+dz;//z direction
	}
	void rotatex(double delta, bool dirdelta)
	{
		double tempy1, tempz1;
		double tempy2, tempz2;
		if(dirdelta==true)//anticlockwise rotation
		{
			tempy1=((y1)*cos(delta))+((z1)*sin(delta));
			tempz1=-((y1)*sin(delta))+((z1)*cos(delta));
			y1=tempy1;
			z1=tempz1;
			tempy2=((y2)*cos(delta))+((z2)*sin(delta));
			tempz2=-((y2)*sin(delta))+((z2)*cos(delta));
			y2=tempy2;
			z2=tempz2;
		}
		else
		{
			tempy1=((y1)*cos(delta))-((z1)*sin(delta));
			tempz1=((y1)*sin(delta))+((z1)*cos(delta));
			y1=tempy1;
			z1=tempz1;
			tempy2=((y2)*cos(delta))+((z2)*sin(delta));
			tempz2=-((y2)*sin(delta))+((z2)*cos(delta));
			y2=tempy2;
			z2=tempz2;
		}//rotates
	}
	void rotatey(double delta, bool dirdelta)
	{
		double tempx1, tempz1;
		double tempx2, tempz2;
		if(dirdelta==true)//anticlockwise rotation
		{
			tempx1=((x1)*cos(delta))-((z1)*sin(delta));
			tempz1=((x1)*sin(delta))+((z1)*cos(delta));
			x1=tempx1;
			z1=tempz1;
			tempx2=((x2)*cos(delta))-((z2)*sin(delta));
			tempz2=((x2)*sin(delta))+((z2)*cos(delta));
			x2=tempx2;
			z2=tempz2;
		}
		else
		{
			tempx1=((x1)*cos(delta))+((z1)*sin(delta));
			tempz1=-((x1)*sin(delta))+((z1)*cos(delta));
			x1=tempx1;
			z1=tempz1;
			tempx2=((x2)*cos(delta))+((z2)*sin(delta));
			tempz2=-((x2)*sin(delta))+((z2)*cos(delta));
			x2=tempx2;
			z2=tempz2;

		}//rotates
	}
	void rotatez(double delta, bool dirdelta)
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
	void rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz)
	{
		this->rotatex(deltax, dirx);
		this->rotatey(deltay, diry);
		this->rotatez(deltaz, dirz);
	}
	
};

class Plane3D
{
    public:
        std::vector<Edge3D> plane;
	void translatex(double dx)
	{
		for (std::vector<Edge3D>::iterator it = plane.begin() ; it != plane.end(); it++)
		{
			(*it).translatex(dx);
		}//translate the edge in x direction
	}
	void translatey(double dy)
	{
		for (std::vector<Edge3D>::iterator it = plane.begin() ; it != plane.end(); it++)
		{
			(*it).translatey(dy);
		}//y direction
	}
	void translatez(double dz)
	{
		for (std::vector<Edge3D>::iterator it = plane.begin() ; it != plane.end(); it++)
		{
			(*it).translatez(dz);
		}//z direction
	}
	void rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz)
	{
		for (std::vector<Edge3D>::iterator it = plane.begin() ; it != plane.end(); it++)
		{
			(*it).rotate(deltax, dirx, deltay, diry, deltaz, dirz);
		}//rotates
	}
};
class HiddenEdge3D
{
    public:
        public:
        double x1,y1,z1;
	double x2,y2,z2;
	void translatex(double dx)
	{
		x1= x1+dx;
		x2= x2+dx;//translate the edge in x direction
	}
	void translatey(double dy)
	{
		y1= y1+dy;
		y2= y2+dy;//y direction
	}
	void translatez(double dz)
	{
		z1= z1+dz;
		z2= z2+dz;//z direction
	}
	void rotatex(double delta, bool dirdelta)
	{
		double tempy1, tempz1;
		double tempy2, tempz2;
		if(dirdelta==true)//anticlockwise rotation
		{
			tempy1=((y1)*cos(delta))+((z1)*sin(delta));
			tempz1=-((y1)*sin(delta))+((z1)*cos(delta));
			y1=tempy1;
			z1=tempz1;
			tempy2=((y2)*cos(delta))+((z2)*sin(delta));
			tempz2=-((y2)*sin(delta))+((z2)*cos(delta));
			y2=tempy2;
			z2=tempz2;
		}
		else
		{
			tempy1=((y1)*cos(delta))-((z1)*sin(delta));
			tempz1=((y1)*sin(delta))+((z1)*cos(delta));
			y1=tempy1;
			z1=tempz1;
			tempy2=((y2)*cos(delta))+((z2)*sin(delta));
			tempz2=-((y2)*sin(delta))+((z2)*cos(delta));
			y2=tempy2;
			z2=tempz2;
		}//rotates
	}
	void rotatey(double delta, bool dirdelta)
	{
		double tempx1, tempz1;
		double tempx2, tempz2;
		if(dirdelta==true)//anticlockwise rotation
		{
			tempx1=((x1)*cos(delta))-((z1)*sin(delta));
			tempz1=((x1)*sin(delta))+((z1)*cos(delta));
			x1=tempx1;
			z1=tempz1;
			tempx2=((x2)*cos(delta))-((z2)*sin(delta));
			tempz2=((x2)*sin(delta))+((z2)*cos(delta));
			x2=tempx2;
			z2=tempz2;
		}
		else
		{
			tempx1=((x1)*cos(delta))+((z1)*sin(delta));
			tempz1=-((x1)*sin(delta))+((z1)*cos(delta));
			x1=tempx1;
			z1=tempz1;
			tempx2=((x2)*cos(delta))+((z2)*sin(delta));
			tempz2=-((x2)*sin(delta))+((z2)*cos(delta));
			x2=tempx2;
			z2=tempz2;

		}//rotates
	}
	void rotatez(double delta, bool dirdelta)
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
	void rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz)
	{
		this->rotatex(deltax, dirx);
		this->rotatey(deltay, diry);
		this->rotatez(deltaz, dirz);
	}
};
class VisibleEdge3D
{
    public:
        public:
        double x1,y1,z1;
	double x2,y2,z2;
	void translatex(double dx)
	{
		x1= x1+dx;
		x2= x2+dx;//translate the edge in x direction
	}
	void translatey(double dy)
	{
		y1= y1+dy;
		y2= y2+dy;//y direction
	}
	void translatez(double dz)
	{
		z1= z1+dz;
		z2= z2+dz;//z direction
	}
	void rotatex(double delta, bool dirdelta)
	{
		double tempy1, tempz1;
		double tempy2, tempz2;
		if(dirdelta==true)//anticlockwise rotation
		{
			tempy1=((y1)*cos(delta))+((z1)*sin(delta));
			tempz1=-((y1)*sin(delta))+((z1)*cos(delta));
			y1=tempy1;
			z1=tempz1;
			tempy2=((y2)*cos(delta))+((z2)*sin(delta));
			tempz2=-((y2)*sin(delta))+((z2)*cos(delta));
			y2=tempy2;
			z2=tempz2;
		}
		else
		{
			tempy1=((y1)*cos(delta))-((z1)*sin(delta));
			tempz1=((y1)*sin(delta))+((z1)*cos(delta));
			y1=tempy1;
			z1=tempz1;
			tempy2=((y2)*cos(delta))+((z2)*sin(delta));
			tempz2=-((y2)*sin(delta))+((z2)*cos(delta));
			y2=tempy2;
			z2=tempz2;
		}//rotates
	}
	void rotatey(double delta, bool dirdelta)
	{
		double tempx1, tempz1;
		double tempx2, tempz2;
		if(dirdelta==true)//anticlockwise rotation
		{
			tempx1=((x1)*cos(delta))-((z1)*sin(delta));
			tempz1=((x1)*sin(delta))+((z1)*cos(delta));
			x1=tempx1;
			z1=tempz1;
			tempx2=((x2)*cos(delta))-((z2)*sin(delta));
			tempz2=((x2)*sin(delta))+((z2)*cos(delta));
			x2=tempx2;
			z2=tempz2;
		}
		else
		{
			tempx1=((x1)*cos(delta))+((z1)*sin(delta));
			tempz1=-((x1)*sin(delta))+((z1)*cos(delta));
			x1=tempx1;
			z1=tempz1;
			tempx2=((x2)*cos(delta))+((z2)*sin(delta));
			tempz2=-((x2)*sin(delta))+((z2)*cos(delta));
			x2=tempx2;
			z2=tempz2;

		}//rotates
	}
	void rotatez(double delta, bool dirdelta)
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
	void rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz)
	{
		this->rotatex(deltax, dirx);
		this->rotatey(deltay, diry);
		this->rotatez(deltaz, dirz);
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

