
#include "2D.h"


		
	
	
	void Vertex2D::rotate(double delta, bool dirdelta)
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


        //Edge bw imp_label

	
	void VisibleEdge::rotate(double delta, bool dirdelta)
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

	void HiddenEdge::rotate(double delta, bool dirdelta)
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


//Assume that we have got the number of vertices.
//Input Format (v1,v2,Label a)



