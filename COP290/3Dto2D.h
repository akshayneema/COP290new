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
void hiddenedgedetection(ThreeDBody threedbody, std::vector<char> plane)
{
	//for every edge classifies it into hidden-part and visible-part and updates vertices accordingly
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
