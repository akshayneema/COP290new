
#include "3Dto2D.h"
#include "myarea.h"
#include <cairomm/context.h>
int type1;
TwoDBody twodbodyy;
ThreeDBody wire_frame;
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
ThreeDBody rotate3D(ThreeDBody &threedbody, std::vector<double> normal)
{
	std::vector<Vertex3D> vtemp;
	std::vector<Edge3D> etemp;
	std::vector<Plane3D> ptemp;
	// ThreeDBody returntdb;
	double a= normal[0];
	double b= normal[1];
	double c= normal[2];
	//cout<<"rotate3d function called";
	if((a!=1)&&(a!=-1))
	{
		//cout<<"if wala case";
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
		cout<<"else wala case";
		for (std::vector<Vertex3D>::iterator it = threedbody.v.begin() ; it != threedbody.v.end(); it++)
		{
			Vertex3D vobj;
			vobj.x=(*it).z;
			vobj.y=(*it).y;
			vobj.z=a*((*it).x);
			// cout<< vobj.x<<vobj.y<<vobj.z;
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
	// cout<< vtemp[1].x<<vtemp[1].y<<vtemp[1].z;
	// cout<< threedbody.v[1].x<<threedbody.v[1].y<<threedbody.v[1].z;
	ThreeDBody threedbodytemp;
	threedbodytemp.v=vtemp;
	// cout<< threedbody.v[1].x<<threedbody.v[1].y<<threedbody.v[1].z;
	threedbodytemp.e=etemp;
	threedbodytemp.p=ptemp;
	return threedbodytemp;
	//rotate the coordinate axes and updates the 3D object coordinates
}
std::vector<Edge3D> edge_segmentation(ThreeDBody &threedbody)
{
	cout<<"edge segmentation started\n";
	std::vector<Edge3D> tempe;
	int k=0;
	// for (std::vector<Edge3D>::iterator it = threedbody.e.begin() ; it != threedbody.e.end(); it++)
	// {
	// 	cout<< "("<<(*it).x1<<","<<(*it).y1<<","<<(*it).z1<<")"<<" "<< "("<<(*it).x2<<","<<(*it).y2<<","<<(*it).z2<<")"<<"\n";
	// }
	for (std::vector<Edge3D>::iterator it = threedbody.e.begin() ; it != threedbody.e.end(); it++)
	{
		cout<<"Next Edge\n";
		cout<< "("<<(*it).x1<<","<<(*it).y1<<","<<(*it).z1<<")"<<" "<< "("<<(*it).x2<<","<<(*it).y2<<","<<(*it).z2<<")"<<"\n";
		// cout<< "("<<","<<","<<")"<<" "<< "("<<","<<","<<")"<<"\n";
		std::vector<Vertex3D> tempv;
		double x1= (*it).x1;
		// cout<<x1<<"\n";
		double x2= (*it).x2;
		// cout<<x2<<"\n";
		double y1= (*it).y1;
		// cout<<y1<<"\n";
		double y2= (*it).y2;
		// cout<<y2<<"\n";
		for (std::vector<Edge3D>::iterator itr = threedbody.e.begin() ; itr != threedbody.e.end(); itr++)
		{
			double x,y,z,q;
			double x3= (*itr).x1;
			double x4= (*itr).x2;
			double y3= (*itr).y1;
			double y4= (*itr).y2;
			// cout<< "("<<(*itr).x1<<","<<(*itr).y1<<","<<(*itr).z1<<")"<<" "<< "("<<(*itr).x2<<","<<(*itr).y2<<","<<(*itr).z2<<")"<<"\n";
			if(!(((x1==x2)&&(y1==y2))||((x3==x4)&&(y3==y4))))
			{
				if(x2==x1)
				{
					if(x4!=x3)
					{
						Vertex3D v3d;
						x=x1;
						y=(((y3)*(x1-x4))+((y4)*(x3-x2)))/(x3-x4);
						double d1= sqrt(pow(x-x1,2.0)+pow(y-y1,2.0));
						double d2= sqrt(pow(x-x2,2.0)+pow(y-y2,2.0));
						double d= sqrt(pow(x2-x1,2.0)+pow(y2-y1,2.0));
						double e1= sqrt(pow(x-x3,2.0)+pow(y-y3,2.0));
						double e2= sqrt(pow(x-x4,2.0)+pow(y-y4,2.0));
						double e= sqrt(pow(x3-x4,2.0)+pow(y3-y4,2.0));
						d=d-d1-d2;
						e=e-e1-e2;
						// cout<<d<<" "<<e<<"\n";
						// cout<<"first edge parallel to y axis inside condition not checked\n";
						// cout<< "("<<(*itr).x1<<","<<(*itr).y1<<","<<(*itr).z1<<")"<<" "<< "("<<(*itr).x2<<","<<(*itr).y2<<","<<(*itr).z2<<")"<<"\n";
						// cout<<"d="<<d<<" d1="<<d1<<" d2="<<d2<<" e="<<e<<" e1="<<e1<<" e2="<<e2<<"\n";
						if(((-.000001<d)&&(d<.000001))&&((-.000001<e)&&(e<.000001)))
						{
							z= ((((*it).z2)*(y-y1))+(((*it).z1)*(y2-y)))/(y2-y1);
							v3d.x=x;
							v3d.y=y;
							v3d.z=z;
							v3d.l=sqrt(pow(x-x1,2.0)+pow(y-y1,2.0));
							cout<<"first edge parallel to y axis\n";
							tempv.push_back(v3d);
							cout<<"("<<x<<","<<y<<","<<z<<")\n";
							cout<< "("<<(*itr).x1<<","<<(*itr).y1<<","<<(*itr).z1<<")"<<" "<< "("<<(*itr).x2<<","<<(*itr).y2<<","<<(*itr).z2<<")"<<"\n";
						}
						
					}
				}
				else if(x4==x3)
				{
					if(x2!=x1)
					{
						Vertex3D v3d;
						x=x3;
						y=(((y1)*(x3-x2))+((y2)*(x1-x4)))/(x1-x2);
						double d1= sqrt(pow(x-x1,2.0)+pow(y-y1,2.0));
						double d2= sqrt(pow(x-x2,2.0)+pow(y-y2,2.0));
						double d= sqrt(pow(x2-x1,2.0)+pow(y2-y1,2.0));
						double e1= sqrt(pow(x-x3,2.0)+pow(y-y3,2.0));
						double e2= sqrt(pow(x-x4,2.0)+pow(y-y4,2.0));
						double e= sqrt(pow(x3-x4,2.0)+pow(y3-y4,2.0));
						d=d-d1-d2;
						e=e-e1-e2;
						if(((-.000001<d)&&(d<.000001))&&((-.000001<e)&&(e<.000001)))
						{
							z= ((((*it).z2)*(x-x1))+(((*it).z1)*(x2-x)))/(x2-x1);
							v3d.x=x;
							v3d.y=y;
							v3d.z=z;
							v3d.l=sqrt(pow(x-x1,2.0)+pow(y-y1,2.0));
							cout<<"second edge parallel to y axis\n";
							tempv.push_back(v3d);
							cout<<"("<<x<<","<<y<<","<<z<<")\n";
							cout<< "("<<(*itr).x1<<","<<(*itr).y1<<","<<(*itr).z1<<")"<<" "<< "("<<(*itr).x2<<","<<(*itr).y2<<","<<(*itr).z2<<")"<<"\n";
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
						double d1= sqrt(pow(x-x1,2.0)+pow(y-y1,2.0));
						double d2= sqrt(pow(x-x2,2.0)+pow(y-y2,2.0));
						double d= sqrt(pow(x2-x1,2.0)+pow(y2-y1,2.0));
						double e1= sqrt(pow(x-x3,2.0)+pow(y-y3,2.0));
						double e2= sqrt(pow(x-x4,2.0)+pow(y-y4,2.0));
						double e= sqrt(pow(x3-x4,2.0)+pow(y3-y4,2.0));
						d=d-d1-d2;
						e=e-e1-e2;
						if(((-.000001<d)&&(d<.000001))&&((-.000001<e)&&(e<.000001)))
						{
							z= ((((*it).z2)*(x-x1))+(((*it).z1)*(x2-x)))/(x2-x1);
							v3d.x=x;
							v3d.y=y;
							v3d.z=z;
							v3d.l=sqrt(pow(x-x1,2.0)+pow(y-y1,2.0));
							cout<<"first edge parallel to x-axis\n";
							tempv.push_back(v3d);
							cout<<"("<<x<<","<<y<<","<<z<<")\n";
							cout<< "("<<(*itr).x1<<","<<(*itr).y1<<","<<(*itr).z1<<")"<<" "<< "("<<(*itr).x2<<","<<(*itr).y2<<","<<(*itr).z2<<")"<<"\n";
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
						double d1= sqrt(pow(x-x1,2.0)+pow(y-y1,2.0));
						double d2= sqrt(pow(x-x2,2.0)+pow(y-y2,2.0));
						double d= sqrt(pow(x2-x1,2.0)+pow(y2-y1,2.0));
						double e1= sqrt(pow(x-x3,2.0)+pow(y-y3,2.0));
						double e2= sqrt(pow(x-x4,2.0)+pow(y-y4,2.0));
						double e= sqrt(pow(x3-x4,2.0)+pow(y3-y4,2.0));
						d=d-d1-d2;
						e=e-e1-e2;
						if(((-.000001<d)&&(d<.000001))&&((-.000001<e)&&(e<.000001)))
						{
							z= ((((*it).z2)*(x-x1))+(((*it).z1)*(x2-x)))/(x2-x1);
							v3d.x=x;
							v3d.y=y;
							v3d.z=z;
							v3d.l=sqrt(pow(x-x1,2.0)+pow(y-y1,2.0));
							cout<<"second edge parallel to x axis\n";
							tempv.push_back(v3d);
							cout<<"("<<x<<","<<y<<","<<z<<")\n";
							cout<< "("<<(*itr).x1<<","<<(*itr).y1<<","<<(*itr).z1<<")"<<" "<< "("<<(*itr).x2<<","<<(*itr).y2<<","<<(*itr).z2<<")"<<"\n";
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
						double d1= sqrt(pow(x-x1,2.0)+pow(y-y1,2.0));
						double d2= sqrt(pow(x-x2,2.0)+pow(y-y2,2.0));
						double d= sqrt(pow(x2-x1,2.0)+pow(y2-y1,2.0));
						double e1= sqrt(pow(x-x3,2.0)+pow(y-y3,2.0));
						double e2= sqrt(pow(x-x4,2.0)+pow(y-y4,2.0));
						double e= sqrt(pow(x3-x4,2.0)+pow(y3-y4,2.0));
						d=d-d1-d2;
						e=e-e1-e2;
						if(((-.000001<d)&&(d<.000001))&&((-.000001<e)&&(e<.000001)))
						{
							z= ((((*it).z2)*(x-x1))+(((*it).z1)*(x2-x)))/(x2-x1);
							v3d.x=x;
							v3d.y=y;
							v3d.z=z;
							v3d.l=sqrt(pow(x-x1,2.0)+pow(y-y1,2.0));
							cout<<"general case\n";
							tempv.push_back(v3d);
							cout<<"("<<x<<","<<y<<","<<z<<")\n";
							cout<< "("<<(*itr).x1<<","<<(*itr).y1<<","<<(*itr).z1<<")"<<" "<< "("<<(*itr).x2<<","<<(*itr).y2<<","<<(*itr).z2<<")"<<"\n";
						}

					}
				}	
			}
		}
		int i;
		int j;
		// cout<<"unsorted\n";
		// for(i=0; i<tempv.size(); i++)
		// {
		// 	cout<< "("<<tempv[i].x<<","<<tempv[i].y<<","<<tempv[i].z<<")"<<"\n";
		// }
		// cout<<tempv.size()<<"\n";
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
		// cout<<tempv.size()<<"\n";
		//tempv ko sort krna hai l ke basis pe
		// cout<<"*"<<tempv.size()<<"*";
		// cout<<"sorted\n";

		// for(i=0; i<tempv.size(); i++)
		// {
		// 	cout<< "("<<tempv[i].x<<","<<tempv[i].y<<","<<tempv[i].z<<")"<<"\n";
		// }
		if(tempv.size()!=0)
		{


			for(i=0; i<(tempv.size()-1); i++)
			{
				double tempvx= tempv[i+1].x-tempv[i].x;
				double tempvy= tempv[i+1].y-tempv[i].y;
				
				if(!(((-.000001<tempvx)&&(tempvx<.000001))&&((-.000001<tempvy)&&(tempvy<.000001))))
				{
					Edge3D eobj;
					eobj.x1=tempv[i].x;
					eobj.y1=tempv[i].y;
					eobj.z1=tempv[i].z;
					eobj.x2=tempv[i+1].x;
					eobj.y2=tempv[i+1].y;
					eobj.z2=tempv[i+1].z;
					bool ifcond1= (eobj.x1==eobj.x2);
					bool ifcond2= (eobj.y1==eobj.y2);
					bool ifcond= !((eobj.x1==eobj.x2)&&(eobj.y1==eobj.y2));
					// cout<< "("<<eobj.x1<<","<<eobj.y1<<","<<eobj.z1<<")"<<" "<< "("<<eobj.x2<<","<<eobj.y2<<","<<eobj.z2<<")"<<"\n";
					k=k+1;
					// cout<<k<<"th eobj\n";
					// cout<<"ifcond1="<<ifcond1<<" ifcond2="<<ifcond2<<" ifcond="<<ifcond<<"\n";
					 // cout<< "("<<eobj.x1<<","<<eobj.y1<<","<<eobj.z1<<")"<<" "<< "("<<eobj.x2<<","<<eobj.y2<<","<<eobj.z2<<")"<<"\n";
					// cout<<tempv.size()<<"\n";
					// cout<< "("<<tempv[i].x<<","<<tempv[i].y<<","<<tempv[i].z<<")"<<" "<< "("<<tempv[i+1].x<<","<<tempv[i+1].y<<","<<tempv[i+1].z<<")"<<"\n";
					// cout<< "("<<eobj.x1<<","<<eobj.y1<<","<<eobj.z1<<")"<<" "<< "("<<eobj.x2<<","<<eobj.y2<<","<<eobj.z2<<")"<<"\n";
					tempe.push_back(eobj);


				}

			}
		}
		// cout<<tempv.size()<<"\n";
		// cout<<"afterloop\n";
		//edges nikaal ke
		//tempe me add kro saari edges
	}
	// cout<<"*"<<tempe.size()<<"*";
	return tempe;
}

void crossProduct(double vect_A[], double vect_B[], double cross_P[])
 
{
 
    cross_P[0] = vect_A[1] * vect_B[2] - vect_A[2] * vect_B[1];
    cross_P[1] = -vect_A[0] * vect_B[2] + vect_A[2] * vect_B[0];
    cross_P[2] = vect_A[0] * vect_B[1] - vect_A[1] * vect_B[0];
}

int raycast(double x, double y, Plane2D plane)// 0-> out 1->in 2-> on the line
{
	int no=0;
	// double m=tan(sqrt(2));
	for(int i=0; i<plane.plane.size(); i++)//point is on edge
	{
		double x1= plane.plane[i].x1;
		double y1= plane.plane[i].y1;
		double x2= plane.plane[i].x2;
		double y2= plane.plane[i].y2;
		double d1= sqrt(pow(x-x1,2.0)+pow(y-y1,2.0));
		double d2= sqrt(pow(x-x2,2.0)+pow(y-y2,2.0));
		double d= sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0));
		d=d-d1-d2;
		if((-0.000001<d)&&(d<0.000001))
		{
			return 2;
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

		if((y==vertex[i].y)&&(x<vertex[i].x))
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
				{
					cout<<"line no. 453\n";
					no=no+1;
				}// this implies that the ray is of in<->out type.
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
			{
				//cout<<"line no. 511\n";
				no=no+1;// this implies that the ray is of in<->out type.
			}
		}
	}
	//normal intersection now
	
	for(int i=0; i<plane.plane.size(); i++)
	{
		double x1= plane.plane[i].x1;
		double y1= plane.plane[i].y1;
		double x2= plane.plane[i].x2;
		double y2= plane.plane[i].y2;
		if(y2!=y1)
		{
			
			double xintersect= ((y-y1)*(x2-x1)/(y2-y1))+x1;
			double d1= sqrt(pow((y-y1),2.0)+pow((xintersect-x1),2.0));
			double d2= sqrt(pow((y2-y),2.0)+pow((x2-xintersect),2.0));
			double d= sqrt(pow((y2-y1),2.0)+pow((x2-x1),2.0));
			d=d-d1-d2;
			if((d1>.000001)&&(d2>.000001)&&(d>-.000001)&&(d<.000001))
			{
				cout<<"d1="<<d1<<" d2="<<d2<<"\n";
				if(xintersect>x)
				{
					//cout<<"line no. 534\n";
					no=no+1;
				}
			}
		}
	}
	if(no%2==0)
	{
		cout<<"no="<<no<<"\n";
		return 0;
	}
	else
	{
		cout<<"no="<<no<<"\n";
		return 1;
	}
	

}

void hiddenedgedetection(ThreeDBody &threedbody, double a, double b, double c, double d)
{
	cout<<"hidden edge detection started\n";
	double q= (a*a)+(b*b)+(c*c);
	double x= -a*d;
	double y= -b*d;
	double z= -c*d;
	x=x/q;
	y=y/q;
	z=z/q;//x,y,z are the 
	std::vector<double> normal= normalofplane(a,b,c,d);
	double tempz;
	// vobj.z=(a*((*it).x))+(b*((*it).y))+(c*((*it).z));
	tempz=normal[0]*(x)+normal[1]*(y)+normal[2]*(z);
	cout<<"rotated plane="<<tempz<<"\n";
	std::vector<Edge3D> tempe= edge_segmentation(threedbody);
	for (std::vector<Edge3D>::iterator it = tempe.begin() ; it != tempe.end(); it++)
	{
		cout<< "("<<(*it).x1<<","<<(*it).y1<<","<<(*it).z1<<")"<<" "<< "("<<(*it).x2<<","<<(*it).y2<<","<<(*it).z2<<")"<<"\n";
	}
	for (std::vector<Edge3D>::iterator it = tempe.begin() ; it != tempe.end(); it++)
	{
		double x1=(*it).x1;
		double y1=(*it).y1;
		double z1=(*it).z1;
		double x2=(*it).x2;
		double y2=(*it).y2;
		double z2=(*it).z2;
		cout<<"New Edge-----------------------------------------------------------------------"<<"\n";
		cout<< "("<<x1<<","<<y1<<","<<z1<<")"<<" "<< "("<<x2<<","<<y2<<","<<z2<<")"<<"\n";
		for (std::vector<Plane3D>::iterator itr = threedbody.p.begin() ; itr != threedbody.p.end(); itr++)
		{
			// cout<<(*itr).plane.size()<<"\n";
			cout<<"plane ki edges\n";
			for (std::vector<Edge3D>::iterator itrr = (*itr).plane.begin() ; itrr != (*itr).plane.end(); itrr++)
			{
				cout<< "("<<(*itrr).x1<<","<<(*itrr).y1<<","<<(*itrr).z1<<")"<<" "<< "("<<(*itrr).x2<<","<<(*itrr).y2<<","<<(*itrr).z2<<")"<<"\n";
			}
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
			double tempd= -((tempn[0]*(*itr).plane[0].x1)+(tempn[1]*(*itr).plane[0].y1)+(tempn[2]*(*itr).plane[0].z1));
			cout<<tempn[0]<<"x+"<<tempn[1]<<"y+"<<tempn[2]<<"z+"<<tempd<<"=0\n";
			if(tempn[2]!=0)//c cant be zero coz plane parallel to z-axis
			{
				double k1,k2;
				k1=-(tempd+(tempn[0]*x1)+(tempn[1]*y1)+(tempn[2]*z1))/tempn[2];
				k2=-(tempd+(tempn[0]*x2)+(tempn[1]*y2)+(tempn[2]*z2))/tempn[2];
				cout<<"k1="<<k1<<" k2="<<k2<<"\n";
				//ye waali condition refine krni hai
				// if(((((tempz>0)&&(k1>0))||((tempz<0)&&(k1<0)))&&(((tempz>0)&&(k2>0))||((tempz<0)&&(k2<0))))||((((tempz>0)&&(k1==0))||((tempz<0)&&(k1==0)))&&(((tempz>0)&&(k2>0))||((tempz<0)&&(k2<0))))||((((tempz>0)&&(k1>0))||((tempz<0)&&(k1<0)))&&(((tempz>0)&&(k2==0))||((tempz<0)&&(k2==0)))))//point 1 behind and point.2 behind
				if(((((tempz>0)&&(k1>0))||((tempz<0)&&(k1<0)))&&(((tempz>0)&&(k2>0))||((tempz<0)&&(k2<0))))||(((k1>-0.000001)&&(k1<0.000001))&&(((tempz>0)&&(k2>0))||((tempz<0)&&(k2<0))))||(((k2>-0.000001)&&(k2<0.000001))&&(((tempz>0)&&(k1>0))||((tempz<0)&&(k1<0)))))
				{
					cout<<"line is behind\n";
					cout<<"Now we will check that its hidden or not \n";
					Plane2D temppl;
					for (std::vector<Edge3D>::iterator itrr = (*itr).plane.begin() ; itrr != (*itr).plane.end(); itrr++)
					{
						Edge2D temped;
						temped.x1=(*itrr).x1;
						temped.y1=(*itrr).y1;
						temped.x2=(*itrr).x2;
						temped.y2=(*itrr).y2;
						cout<<"("<<temped.x1<<","<<temped.y1<<")("<<temped.x2<<","<<temped.y2<<") \n";
						temppl.plane.push_back(temped);
					}
					int point1=raycast(x1,y1,temppl);
					cout<<"("<<x1<<","<<y1<<")raycast output is = "<<point1<<"\n";
					int point2=raycast(x2,y2,temppl);
					cout<<"("<<x2<<","<<y2<<") raycast output is = "<<point2<<"\n";
					if(((point1==2)&&(point2==1))||((point2==2)&&(point1==1))||((point1==1)&&(point2==1)))//ek andar ek bahar aur dono andar
					{
						(*it).visibility=false;
						cout<<"Ya!! its hidden\n";
					}
					else if((point1==2)&&(point2==2))//both the endpoints are on edge
					{
						double midx= (x1+x2)/2;
						double midy= (y1+y2)/2;
						int midray= raycast(midx, midy, temppl);
						if(midray==1)
						{
							(*it).visibility=false;
							cout<<"Ya!! its hidden\n";
						}
					}
				}
			}
			//dono points k liye aage piche check
			//k times kcap solve krna hai plane ki eqn k saath. if sign of k= sign of tempz then piche else aage
			//if both piche then raycasting and check both bahar(visible) or both andar(hidden). else visible.
		}
	}//for every edge classifies it into hidden-part and visible-part and updates vertices accordingly
	threedbody.e=tempe;
}
TwoDBody TopView(ThreeDBody &threedbody)
{
	TwoDBody twodbody;
	for (std::vector<Vertex3D>::iterator it = threedbody.v.begin() ; it != threedbody.v.end(); it++)
	{
		Vertex2D vobj;
		vobj.x=(*it).x;
		vobj.y=(*it).y;
		twodbody.v.push_back(vobj);
	}
	for (std::vector<Edge3D>::iterator it = threedbody.e.begin() ; it != threedbody.e.end(); it++)
	{
		Edge2D eobj;
		eobj.x1=(*it).x1;
		eobj.y1=(*it).y1;
		eobj.x2=(*it).x2;
		eobj.y2=(*it).y2;
		eobj.visibility=(*it).visibility;
		twodbody.e.push_back(eobj);
	}
	// for (std::vector<HiddenEdge3D>::iterator it = threedbody.he.begin() ; it != threedbody.he.end(); it++)
	// {
	// 	HiddenEdge heobj;
	// 	heobj.x1=(*it).x1;
	// 	heobj.y1=(*it).y1;
	// 	heobj.x2=(*it).x2;
	// 	heobj.y2=(*it).y2;
	// 	twodbody.he.push_back(heobj);
	// }
	twodbodyy=twodbody;
	return twodbody;
	//takes top view of all the vertices, hidden edges and visible edges
}
MyWindow::MyWindow()
: buttonx("Rotatex"),
 buttony("Rotatey"),
 buttonz("Rotatez")
{
	// button.override_background_color(GTK_STATE_FLAGS_NORMAL, Gdk::RGBA(0.1 , 0.0 , 0.0, 0.1));
	// cout<<"constructor called\n";
// GdkColor color;


	add(grid);
	area.set_size_request(800,500);
	grid.add(area);	

	area.signal_draw().connect(sigc::mem_fun(*this,
	&MyWindow::on_drawe));

	if(type1==1)
	{
		grid.attach_next_to(buttonx,area,Gtk::POS_BOTTOM,1,1);
		grid.attach_next_to(buttony,buttonx,Gtk::POS_BOTTOM,1,1);
		grid.attach_next_to(buttonz,buttony,Gtk::POS_BOTTOM,1,1);

		buttonx.signal_clicked().connect( sigc::bind<int>(sigc::mem_fun(*this, 
				&MyWindow::on_click),1));
		buttony.signal_clicked().connect( sigc::bind<int>(sigc::mem_fun(*this, 
				&MyWindow::on_click),2));

		buttonz.signal_clicked().connect( sigc::bind<int>(sigc::mem_fun(*this, 
				&MyWindow::on_click),3));
		
	}

	show_all_children();
	
}

MyWindow::~MyWindow()
{
}
bool MyWindow::on_drawe(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  // coordinates for the center of the window
  int xc, yc;
  xc = width / 2;
  yc = height / 2;

  cr->set_line_width(2.0);
  



  for (std::vector<Edge2D>::iterator it = twodbodyy.e.begin() ; it != twodbodyy.e.end(); it++)
	{
		if((*it).visibility==true)
		{
			//cr->save();
			cr->set_source_rgb(0.0,0.5,1.0);
			// cout<<"visible\n";
			cr->move_to(100*(*it).x1+xc, 100*(*it).y1+yc);
  			cr->line_to(100*(*it).x2+xc,100*(*it).y2+yc);
  			cr->stroke();
  			// cr->restore();
			  //cout << wire_frame.v[0].x;
		}
		else
		{
			cr->save();
			// cout<<"not visible\n";
			std::vector<double> vec;
			cr->set_source_rgb(0.0,0.5,1.0);
			vec.push_back(10.0);
			vec.push_back(5.0);
			cr->set_dash(vec, 0);
			cr->move_to(100*(*it).x1+xc, 100*(*it).y1+yc);
  			cr->line_to(100*(*it).x2+xc,100*(*it).y2+yc);
  			cr->stroke();
  			cr->restore();
			  
		}
	}
  return true;
}

void MyWindow::on_click(int x)
{
	if(x==1) 
	{
		wire_frame.rotate(0.05,true,0.0,false,0.0,true);
		//cout<<"x=1\n";
	}
	else if (x==2) wire_frame.rotate(0.0,true,0.05,true,0.0,true);
	else if (x==3) wire_frame.rotate(0.0,false,0.0,true,0.05,true);

	ThreeDBody tdbtemp=rotate3D(wire_frame,normalofplane(1,1,1,1));

	TopView(tdbtemp);

	
	area.queue_draw();

}

void ThreeDBodi ( ThreeDBody need)
{
	wire_frame = need;
	//cout << wire_frame.v[0].x;

}
void type_equal (int type)
{
   		type1 = type;
	//cout << wire_frame.v[0].x;

}

