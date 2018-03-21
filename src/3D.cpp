
#include "3D.h"



	void Vertex3D::rotatex(double delta, bool dirdelta)
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
	void Vertex3D::rotatey(double delta, bool dirdelta)
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
	void Vertex3D::rotatez(double delta, bool dirdelta)
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
	void Vertex3D::rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz)
	{
		this->rotatex(deltax, dirx);
		this->rotatey(deltay, diry);
		this->rotatez(deltaz, dirz);
	}


	
	void Edge3D::rotatex(double delta, bool dirdelta)
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
	void Edge3D::rotatey(double delta, bool dirdelta)
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
	void Edge3D::rotatez(double delta, bool dirdelta)
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
	void Edge3D::rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz)
	{
		this->rotatex(deltax, dirx);
		this->rotatey(deltay, diry);
		this->rotatez(deltaz, dirz);
	}
	
	void Plane3D::rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz)
	{
		for (std::vector<Edge3D>::iterator it = plane.begin() ; it != plane.end(); it++)
		{
			(*it).rotate(deltax, dirx, deltay, diry, deltaz, dirz);
		}//rotates
	}

	void HiddenEdge3D::rotatex(double delta, bool dirdelta)
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
	void HiddenEdge3D::rotatey(double delta, bool dirdelta)
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
	void HiddenEdge3D::rotatez(double delta, bool dirdelta)
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
	void HiddenEdge3D::rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz)
	{
		this->rotatex(deltax, dirx);
		this->rotatey(deltay, diry);
		this->rotatez(deltaz, dirz);
	}


	void VisibleEdge3D::rotatex(double delta, bool dirdelta)
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
	void VisibleEdge3D::rotatey(double delta, bool dirdelta)
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
	void VisibleEdge3D::rotatez(double delta, bool dirdelta)
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
	void VisibleEdge3D::rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz)
	{
		this->rotatex(deltax, dirx);
		this->rotatey(deltay, diry);
		this->rotatez(deltaz, dirz);
	}


	void ThreeDBody::rotate(double deltax, bool dirx, double deltay, bool diry, double deltaz, bool dirz)
	{
		cout<<"line no. 460";
		for (std::vector<Edge3D>::iterator it = this->e.begin() ; it != this->e.end(); it++)
		{
			(*it).rotate(deltax, dirx, deltay, diry, deltaz, dirz);
		}
		for (std::vector<Vertex3D>::iterator it = this->v.begin() ; it != this->v.end(); it++)
		{
			(*it).rotate(deltax, dirx, deltay, diry, deltaz, dirz);
		}
	}
	

