#ifndef OD_H
#define OD_H
#include "3D.h"
#endif

#ifndef OD2_H
#define OD2_H
#include "2D.h"
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
std::vector<double> normalofplane(double a, double b, double c, double d)
{
	double temp= (a*a)+(b*b)+(c*c);
	temp=sqrt(temp);
	std::vector<double> normal;
	normal.push_back(a/temp);
	normal.push_back(b/temp);
	normal.push_back(c/temp);
	return normal;
	//derives unit vector in the direction of normal of the plane
}
void rotate3D(ThreeDBody threedbody, std::vector<double> normal)
{
	std::vector<Vertex3D> vtemp;
	std::vector<Edge3D> etemp;
	std::vector<Plane3D> ptemp;
	double a= normal[0];
	double b= normal[1];
	double c= normal[2];
	if((a!=1)&&(a!=-1))
	{
		double d= (b*b)+(c*c);
		d=sqrt(d);
		for (std::vector<Vertex3D>::iterator it = threedbody.v.begin() ; it != threedbody.v.end(); it++)
		{
			Vertex3D vobj;
			vobj.x=((-c*((*it).y))/d)+((b*((*it).z))/d);
			vobj.y=(((*it).x)*d)-((a*((b*((*it).y))+(c*((*it).z))))/d);
			vobj.z=(a*((*it).x))+(b*((*it).y))+(c*((*it).z));
			vtemp.push_back(vobj);
		}
		for (std::vector<Edge3D>::iterator it = threedbody.e.begin() ; it != threedbody.e.end(); it++)
		{
			Edge3D eobj;
			eobj.x1=((-c*((*it).y1))/d)+((b*((*it).z1))/d);
			eobj.y1=(((*it).x1)*d)-((a*((b*((*it).y1))+(c*((*it).z1))))/d);
			eobj.z1=(a*((*it).x1))+(b*((*it).y1))+(c*((*it).z1));
			eobj.x2=((-c*((*it).y2))/d)+((b*((*it).z2))/d);
			eobj.y2=(((*it).x2)*d)-((a*((b*((*it).y2))+(c*((*it).z2))))/d);
			eobj.z2=(a*((*it).x2))+(b*((*it).y2))+(c*((*it).z2));
			etemp.push_back(eobj);
		}
		for (std::vector<Plane3D>::iterator it = threedbody.p.begin() ; it != threedbody.p.end(); it++)
		{
			Plane3D pobj;
			std::vector<Edge3D> edgep;
			for(std::vector<Edge3D>::iterator itr=(*it).plane.begin(); itr!= (*it).plane.end(); itr++)
			{
				Edge3D eobj;
				eobj.x1=((-c*((*itr).y1))/d)+((b*((*itr).z1))/d);
				eobj.y1=(((*itr).x1)*d)-((a*((b*((*itr).y1))+(c*((*itr).z1))))/d);
				eobj.z1=(a*((*itr).x1))+(b*((*itr).y1))+(c*((*itr).z1));
				eobj.x2=((-c*((*itr).y2))/d)+((b*((*itr).z2))/d);
				eobj.y2=(((*itr).x2)*d)-((a*((b*((*itr).y2))+(c*((*itr).z2))))/d);
				eobj.z2=(a*((*itr).x2))+(b*((*itr).y2))+(c*((*itr).z2));
				edgep.push_back(eobj);
			}
			pobj.plane=edgep;
			ptemp.push_back(pobj);
		}

	}
	else
	{
		for (std::vector<Vertex3D>::iterator it = threedbody.v.begin() ; it != threedbody.v.end(); it++)
		{
			Vertex3D vobj;
			vobj.x=(*it).z;
			vobj.y=(*it).y;
			vobj.z=a*((*it).x);
			vtemp.push_back(vobj);
		}
		for (std::vector<Edge3D>::iterator it = threedbody.e.begin() ; it != threedbody.e.end(); it++)
		{
			Edge3D eobj;
			eobj.x1=(*it).z1;
			eobj.y1=(*it).y1;
			eobj.z1=a*((*it).x1);
			eobj.x2=(*it).z2;
			eobj.y2=(*it).y2;
			eobj.z2=a*((*it).x2);
			etemp.push_back(eobj);
		}
		for (std::vector<Plane3D>::iterator it = threedbody.p.begin() ; it != threedbody.p.end(); it++)
		{
			Plane3D pobj;
			std::vector<Edge3D> edgep;
			for(std::vector<Edge3D>::iterator itr=(*it).plane.begin(); itr!= (*it).plane.end(); itr++)
			{
				Edge3D eobj;
				eobj.x1=(*itr).z1;
				eobj.y1=(*itr).y1;
				eobj.z1=a*((*itr).x1);
				eobj.x2=(*itr).z2;
				eobj.y2=(*itr).y2;
				eobj.z2=a*((*itr).x2);
				edgep.push_back(eobj);
			}
			pobj.plane=edgep;
			ptemp.push_back(pobj);
		}
	}
	threedbody.v=vtemp;
	threedbody.e=etemp;
	threedbody.p=ptemp;
	//rotate the coordinate axes and updates the 3D object coordinates
}
std::vector<Edge3D> edge_segmentation(ThreeDBody threedbody)
{
	std::vector<Edge3D> tempe;
	for (std::vector<Edge3D>::iterator it = threedbody.e.begin() ; it != threedbody.e.end(); it++)
	{
		std::vector<Vertex3D> tempv;
		double x1= (*it).x1;
		double x2= (*it).x2;
		double y1= (*it).y1;
		double y2= (*it).y2;
		for (std::vector<Edge3D>::iterator itr = threedbody.e.begin() ; itr != threedbody.e.end(); itr++)
		{
			double x,y,z,q;
			double x3= (*itr).x1;
			double x4= (*itr).x2;
			double y3= (*itr).y1;
			double y4= y4;
			if(x2==x1)
			{
				if(x4!=x3)
				{
					Vertex3D v3d;
					x=x1;
					y=(((y3)*(x1-x4))+((y4)*(x3-x2)))/(x3-x4);
					if(((y>=y1)&&(y<=y2))||((y<=y1)&&(y>=y2)))
					{
						z= ((((*it).z2)*(y-y1))+(((*it).z1)*(y2-y)))/(y2-y1);
						v3d.x=x;
						v3d.y=y;
						v3d.z=z;
						v3d.l=(y-y1)/(y2-y1);
						tempv.push_back(v3d);
					}
					
				}
			}
			else if(x4==x3)
			{
				if(x2!=x1)
				{
					Vertex3D v3d;
					x=x3;
					y=(((y1)*(x3-x2))+((y2)*(x1-x4)))/(x3-x4);
					if(((y>=y3)&&(y<=y4))||((y<=y3)&&(y>=y4)))
					{
						z= ((((*it).z2)*(y-y1))+(((*it).z1)*(y2-y)))/(y2-y1);
						v3d.x=x;
						v3d.y=y;
						v3d.z=z;
						v3d.l=(y-y1)/(y2-y1);
						tempv.push_back(v3d);
					}
					
				}
			}
			else if(y2==y1)
			{
				if(y4!=y3)
				{
					Vertex3D v3d;
					x=(((x3)*(y1-y4))+((x4)*(y3-y1)))/(y3-y4);
					y=y2;
					if(((x>=x1)&&(x<=x2))||((x<=x1)&&(x>=x2)))
					{
						z= ((((*it).z2)*(x-x1))+(((*it).z1)*(x2-x)))/(x2-x1);
						v3d.x=x;
						v3d.y=y;
						v3d.z=z;
						v3d.l=(x-x1)/(x2-x1);
						tempv.push_back(v3d);
					}
					
				}
			}
			else if(y4==y3)
			{
				if(y2!=y1)
				{
					Vertex3D v3d;
					x=(((x1)*(y2-y3))+((x2)*(y3-y1)))/(y2-y1);
					y=y4;
					if(((x>=x1)&&(x<=x2))||((x<=x1)&&(x>=x2)))
					{
						z= ((((*it).z2)*(x-x1))+(((*it).z1)*(x2-x)))/(x2-x1);
						v3d.x=x;
						v3d.y=y;
						v3d.z=z;
						v3d.l=(x-x1)/(x2-x1);
						tempv.push_back(v3d);
					}
					
				}
			}
			else
			{
				if(!((y2-y1)/(x2-x1)==(y4-y3)/(x4-x3))||((y2-y1)/(x2-x1)==-(y4-y3)/(x4-x3)))
				{
					Vertex3D v3d;
					x= (((((x1)*(y2))-((y1)*(x2)))*((x3)-(x4)))-((((x3)*(y4))-((y3)*(x4)))*((x1)-(x2))));
					y= (((((x1)*(y2))-((y1)*(x2)))*((y3)-(y4)))-((((x3)*(y4))-((y3)*(x4)))*((y1)-(y2))));
					q= (((x1)-(x2))*((y3)-(y4)))-(((y1)-(y2))*((x3)-(x4)));
					x=x/q;
					y=y/q;
					if(((y-y1)/(x-x1))==((y2-y)/(x2-x)))
					{
						z= ((((*it).z2)*(x-x1))+(((*it).z1)*(x2-x)))/(x2-x1);
						v3d.x=x;
						v3d.y=y;
						v3d.z=z;
						v3d.l=(x-x1)/(x2-x1);
						tempv.push_back(v3d);
					}

				}
			}
		}
		int i;
		int j;
		for (i=0; i<tempv.size();  i++)
		{
			for(j=i+1; j<tempv.size(); j++)
			{
				if(tempv[i].l>tempv[j].l)
				{
					std::swap(tempv[i],tempv[j]);
				}
			}
		}
		//tempv ko sort krna hai l ke basis pe
		for(i=0; i<tempv.size()-1; i++)
		{
			if(!((tempv[i].x==tempv[i+1].x)&&(tempv[i].y==tempv[i+1].y)))
			{
				Edge3D eobj;
				eobj.x1=tempv[i].x;
				eobj.y1=tempv[i].y;
				eobj.z1=tempv[i].z;
				eobj.x2=tempv[i+1].x;
				eobj.y2=tempv[i+1].y;
				eobj.z2=tempv[i+1].z;
				tempe.push_back(eobj);
			}

		}
		//edges nikaal ke
		//tempe me add kro saari edges
	}
	return tempe;
}
void crossProduct(double vect_A[], double vect_B[], double cross_P[])
 
{
 
    cross_P[0] = vect_A[1] * vect_B[2] - vect_A[2] * vect_B[1];
    cross_P[1] = vect_A[0] * vect_B[2] - vect_A[2] * vect_B[0];
    cross_P[2] = vect_A[0] * vect_B[1] - vect_A[1] * vect_B[0];
}

int raycast(double x, double y, Plane2D plane)// 0-> out 1->in 2-> on the line
{
	int no=0;
	double m=tan(sqrt(2));
	for(int i=0; i<plane.plane.size(); i++)//point is on edge
	{
		double x1= plane.plane[i].x1;
		double y1= plane.plane[i].y1;
		double x2= plane.plane[i].x2;
		double y2= plane.plane[i].y2;
		if(((y-y1)*(x2-x1))==((y2-y1)*(x-x1)))
		{
			double d1= sqrt((y-y1)^2+(x-x1)^2);
			double d2= sqrt((y2-y)^2+(x2-x)^2);
			double d= sqrt((y2-y1)^2+(x2-x1)^2);
			if(d1+d2==d)
			{
				return 2;
			}
		}

	}
	//edge set se vertex set bnana hai
	std::vector<Vertex2D> vertex;
	std::set<double> xset;
	std::set<double> yset;
	for(int i=0; i<plane.plane.size(); i++)
	{
		double x1= plane.plane[i].x1;
		double y1= plane.plane[i].y1;
		double x2= plane.plane[i].x2;
		double y2= plane.plane[i].y2;
		xset.insert(x1);
		xset.insert(x2);
		yset.insert(y1);
		yset.insert(y2);
	}
	std::set<double>::iterator it,itr;
	for (it = xset.begin(), itr= yset.begin(); it != xset.end(); it++,itr++)
	{
	    Vertex2D ver;
	    ver.x=*it;
	    ver.y=*itr;
	    vertex.push_back(ver);
	     // Note the "*" here
	}
	for(int i=0; i<vertex.size(); i++)//vertex intersection
	{
		std::vector<double> othery;

		if((y==vertex.y)&&(x<vertex.x))
		{
			for(int j=0; j<plane.plane.size(); j++)
			{
				if(((plane.plane[j].y1==y)||(plane.plane[j].y2==y))&&(plane.plane[j].y1!=plane.plane[j].y2))
				{
					if(plane.plane[j].y1==y)
					{
						othery.push_back(plane.plane[j].y2);
					}
					else if(plane.plane[j].y2==y)
					{
						othery.push_back(plane.plane[j].y1);
					}
				}
			}
		}
		if(othery.size()==2)//both edges sharing this vertex is non-parallel to the casted ray.
		{
			if((othery[0]-y)*(othery[1]-y)<0)//both the other vertices of the edges are on different sides of casted ray.
				no=no+1;// this implies that the ray is of in<->out type.
		}
	}
	//edge overlapping
	for(int i=0; i<plane.plane.size(); i++)
	{
		double x1= plane.plane[i].x1;
		double y1= plane.plane[i].y1;
		double x2= plane.plane[i].x2;
		double y2= plane.plane[i].y2;
		std::vector<double> othery;
		if(((y1==y2)&&(y1==y))&&((x<x1)&&(x<x2)))//conincide condition
		{
			for(int j=0; j<plane.plane.size(); j++)//finding other edge with x1 and y1 as vertex
			{
				if(((plane.plane[j].x1==x1)&&(plane.plane[j].y1==y1))||((plane.plane[j].x1==x1)&&(plane.plane[j].y1==y1)))
				{
					if((plane.plane[j].x1==x1)&&(plane.plane[j].y1==y1))
					{
						if(!((plane.plane[j].x2==x2)&&(plane.plane[j].y2==y2)))
						{
							othery.push_back(plane.plane[j].y2);
						}
					}
					else if((plane.plane[j].x2==x1)&&(plane.plane[j].y2==y1))
					{
						if(!((plane.plane[j].x1==x2)&&(plane.plane[j].y1==y2)))
						{
							othery.push_back(plane.plane[j].y1);
						}
					}
				}
			}
			for(int j=0; j<plane.plane.size(); j++)//finding other edge with x2 and y2 as vertex
			{
				if(((plane.plane[j].x1==x2)&&(plane.plane[j].y1==y2))||((plane.plane[j].x1==x2)&&(plane.plane[j].y1==y2)))
				{
					if((plane.plane[j].x1==x2)&&(plane.plane[j].y1==y2))
					{
						if(!((plane.plane[j].x2==x1)&&(plane.plane[j].y2==y1)))
						{
							othery.push_back(plane.plane[j].y2);
						}
					}
					else if((plane.plane[j].x2==x2)&&(plane.plane[j].y2==y2))
					{
						if(!((plane.plane[j].x1==x1)&&(plane.plane[j].y1==y1)))
						{
							othery.push_back(plane.plane[j].y1);
						}
					}
				}
			}
		}
		if(othery.size()==2)//both edges sharing this vertex is non-parallel to the casted ray.
		{
			if((othery[0]-y)*(othery[1]-y)<0)//both the other vertices of the edges are on different sides of casted ray.
				no=no+1;// this implies that the ray is of in<->out type.
		}
	}
	//normal intersection now
	
	for(int i=0; i<plane.plane.size(); i++)
	{
		if(y2!=y1)
		{
			double x1= plane.plane[i].x1;
			double y1= plane.plane[i].y1;
			double x2= plane.plane[i].x2;
			double y2= plane.plane[i].y2;
			double xintersect= ((y-y1)*(x2-x1)/(y2-y1))+x1;
			double d1= sqrt((y-y1)^2+(xintersect-x1)^2);
			double d2= sqrt((y2-y)^2+(x2-xintersect)^2);
			double d= sqrt((y2-y1)^2+(x2-x1)^2);
			if((d1>0)&&(d2>0)&&(d1+d2==d))
			{
				if(xintersect>x)
				{
					no=no+1;
				}
			}
		}
	}
	if(no%2==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	

}

void hiddenedgedetection(ThreeDBody threedbody, double a, double b, double c, double d)
{
	double q= (a*a)+(b*b)+(c*c);
	double x= -a*d;
	double y= -b*d;
	double z= -c*d;
	x=x/q;
	y=y/q;
	z=z/q;
	std::vector<double> normal= normalofplane(a,b,c,d);
	double tempz;
	if((normal[0]!=1)&&(normal[0]!=-1))
	{
		tempz=(normal[0]*(x))+(normal[1]*(y))+(normal[2]*(z));
	}
	else
	{
		tempz=normal[0]*(x);
	}
	
	std::vector<Edge3D> tempe= edge_segmentation(threedbody);
	for (std::vector<Edge3D>::iterator it = tempe.begin() ; it != tempe.end(); it++)
	{
		double x1=(*it).x1;
		double y1=(*it).y1;
		double z1=(*it).z1;
		double x2=(*it).x2;
		double y2=(*it).y2;
		double z2=(*it).z2;
		for (std::vector<Plane3D>::iterator itr = threedbody.p.begin() ; itr != threedbody.p.end(); itr++)
		{
			double ba[3];
			double ca[3];
			ba[0]=(*itr).plane[0].x2-(*itr).plane[0].x1;
			ba[1]=(*itr).plane[0].y2-(*itr).plane[0].y1;
			ba[2]=(*itr).plane[0].z2-(*itr).plane[0].z1;
			ca[0]=(*itr).plane[1].x2-(*itr).plane[1].x1;
			ca[1]=(*itr).plane[1].y2-(*itr).plane[1].y1;
			ca[2]=(*itr).plane[1].z2-(*itr).plane[1].z1;
			double tempn[3];
			crossProduct(ba, ca, tempn);
			double tempd= -((a*(*itr).plane[0].x1)+(b*(*itr).plane[0].y1)+(c*(*itr).plane[0].z1));
			if(tempn[2]!=0)//c cant be zero coz plane parallel to z-axis
			{
				double k1,k2;
				k1=-(tempd+(tempn[0]*x1)+(tempn[1]*y1)+(tempn[2]*z1))/tempn[2];
				k2=-(tempd+(tempn[0]*x2)+(tempn[1]*y2)+(tempn[2]*z2))/tempn[2];
				if((((tempz>0)&&(k1>0))||((tempz<0)&&(k1<0)))&&(((tempz>0)&&(k2>0))||((tempz<0)&&(k2<0))))//point 1 behind and point.2 behind
				{
					Plane2D temppl;
					for (std::vector<Edge3D>::iterator itrr = (*itr).begin() ; itrr != (*itr).end(); itrr++)
					{
						Edge2D temped;
						temped.x1=(*itrr).x1;
						temped.y1=(*itrr).y1;
						temped.x2=(*itrr).x2;
						temped.y2=(*itrr).y2;
						temppl.push_back(temped);
					}
					raycast(x1,y1,temppl);
					raycast(x2,y2,temppl);
				}
			}
			//dono points k liye aage piche check
			//k times kcap solve krna hai plane ki eqn k saath. if sign of k= sign of tempz then piche else aage
			//if both piche then raycasting and check both bahar(visible) or both andar(hidden). else visible.
		}
	}//for every edge classifies it into hidden-part and visible-part and updates vertices accordingly
}
TwoDBody TopView(ThreeDBody threedbody)
{
	TwoDBody twodbody;
	for (std::vector<Vertex3D>::iterator it = threedbody.v.begin() ; it != threedbody.v.end(); it++)
	{
		Vertex2D vobj;
		vobj.x=(*it).x;
		vobj.y=(*it).y;
		twodbody.v.push_back(vobj);
	}
	for (std::vector<VisibleEdge3D>::iterator it = threedbody.ve.begin() ; it != threedbody.ve.end(); it++)
	{
		VisibleEdge veobj;
		veobj.x1=(*it).x1;
		veobj.y1=(*it).y1;
		veobj.x2=(*it).x2;
		veobj.y2=(*it).y2;
		twodbody.ve.push_back(veobj);
	}
	for (std::vector<HiddenEdge3D>::iterator it = threedbody.he.begin() ; it != threedbody.he.end(); it++)
	{
		HiddenEdge heobj;
		heobj.x1=(*it).x1;
		heobj.y1=(*it).y1;
		heobj.x2=(*it).x2;
		heobj.y2=(*it).y2;
		twodbody.he.push_back(heobj);
	}
	return twodbody;
	//takes top view of all the vertices, hidden edges and visible edges
}
