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

// top-> xz  front -> xy left -> zy
void threeDlabel (TwoDBody top,TwoDBody front,TwoDBody left) //,Labelled2D side
{
	ThreeDBody temp;
	std::vector<Vertex3D> vobj;
	std::vector<Edge3D> eobj;

	//int n = top.val; //top.val = front.val
	int n = top.v.size();
	int x,y,z;

	TwoDBody top1 = top;
	TwoDBody front1 = front;

	for(int i=0; i < n; i++ )
	{
		int x = top1.v.front().x;
		int y;
		//int y = front1.v.front().y;
		int z = top1.v.front().y;
		string labeler;
		//string label = top1.v.front().label;
		vector<string> vec_label = top1.v.front().vec_label;
		int label_sz = vec_label.size();


 		for (int i=0;i<label_sz;i++)
		 {
			string labeled = vec_label.front();
			for (std::vector<Vertex2D>::iterator it = front1.v.begin(); it != front1.v.end(); ++it)
			{
				vector<string> tmp = (*it).vec_label;
				int size_lp = tmp.size();

				for(int j=0;j<size_lp;j++)
				{
					string asli = tmp.front();
					if(labeled == asli) 
					{
						y = (*it).y;
						labeler = asli; 
					}
				}
			}
			vec_label.pop_back();
		 }

		Vertex3D vtemp;

		vtemp.x = x;
		vtemp.y = y;
		vtemp.z = z;
		vtemp.str = labeler;

		vobj.push_back(vtemp);
		temp.v.push_back(vtemp);
		top1.v.pop_back();
		//temp.v.push_back();
	}

	
	std::vector<Vertex3D> temp_vobj = vobj;
	top1 = top;
	front1 = front;

	int limit = temp.v.size();
	int adj[n][n];
	for (int i = 0; i < limit; i++)
	{
		for(int j = 0; j < limit; j++)
		{
			if(i<j) adj[i][j] = 1;
			else adj[i][j]=0;
		}
	}

	int x_1,y_1,z_1,x_2,y_2,z_2;
	vector< pair <double,double> > front_e,top_e,left_e;
/*
	std::vector<VisibleEdge> front_edges,top_edges,left_edges;
	front_edges = front.ve;
	top_edges = top.ve;
	left_edges = left.ve;



	for (std::vector<HiddenEdge>::iterator it = top.he.begin(); it != top.he.end(); ++it)
	{
		x_1 = (*it).x1 ;
		y_1 = (*it).y1 ;

		front_edges.push_back();
		//top_e.push_back(make_pair(x_1,y_1));	

	}	
*/
	for (std::vector<Vertex3D>::iterator it = temp.v.begin(); it != temp.v.end(); ++it)
	{
		x = (*it).x ;
		y = (*it).y ;
		z = (*it).z ;

// top-> xz  front -> xy left -> zy
		int aa,bb,cc;
		int v1,v2,v3;

		for (std::vector<Vertex3D>::iterator it = temp.v.begin(); it != temp.v.end(); ++it)
		{
			aa = (*it).x ;
			bb = (*it).y ;	
			cc = (*it).z ;
			v1=2;
			v2=2;
			v3=2;

//Top x-z
			if( x==aa && z==cc)
			{
				v1 =1;
			}
			else
			{
				for (std::vector<VisibleEdge>::iterator it = top.ve.begin(); it != top.ve.end(); ++it)
				{
					if(x == ((*it).x1) && z == ((*it).y1))
					{
						if( aa == ((*it).x2) && cc == ((*it).y2) ) v1 =1;
						else v1=0;
					}

					else if (aa == ((*it).x1) && cc == ((*it).y1))
					{
						if( x == ((*it).x2) && z == ((*it).y2) ) v1 =1;
						else v1=0;						
					}

					//if(v1==0 || v1==1) break;

				}

				for (std::vector<HiddenEdge>::iterator it = top.he.begin(); it != top.he.end(); ++it)
				{
					if(x == ((*it).x1) && z == ((*it).y1))
					{
						if( aa == ((*it).x2) && cc == ((*it).y2) ) v1 =1;
						else v1=0;
					}

					else if (aa == ((*it).x1) && cc == ((*it).y1))
					{
						if( x == ((*it).x2) && z == ((*it).y2) ) v1 =1;
						else v1=0;						
					}
					//if(v1==0 || v1==1) break;

				}
			}

//Front x-y 
			if( x==aa && y==bb)
			{
				v2 =1;
			}
			else
			{
				for (std::vector<VisibleEdge>::iterator it = front.ve.begin(); it != front.ve.end(); ++it)
				{
					if(x == ((*it).x1) && y == ((*it).y1))
					{
						if( aa == ((*it).x2) && bb == ((*it).y2) ) v2 =1;
						else v2=0;
					}

					else if (aa == ((*it).x1) && bb == ((*it).y1))
					{
						if( x == ((*it).x2) && y == ((*it).y2) ) v2 =1;
						else v2=0;						
					}

					//if(v2==0 || v2==1) break;

				}

				for (std::vector<HiddenEdge>::iterator it = front.he.begin(); it != front.he.end(); ++it)
				{
					if(x == ((*it).x1) && y == ((*it).y1))
					{
						if( aa == ((*it).x2) && bb == ((*it).y2) ) v2 =1;
						else v2=0;
					}

					else if (aa == ((*it).x1) && bb == ((*it).y1))
					{
						if( x == ((*it).x2) && y == ((*it).y2) ) v2 =1;
						else v2=0;						
					}
					//if(v2==0 || v2==1) break;

				}
			}

//Left z-y
			if( z==cc && y==bb)
			{
				v3 =1;
			}
			else
			{
				for (std::vector<VisibleEdge>::iterator it = left.ve.begin(); it != left.ve.end(); ++it)
				{
					if(z == ((*it).x1) && y == ((*it).y1))
					{
						if( cc == ((*it).x2) && bb == ((*it).y2) ) v3 =1;
						else v3=0;
					}

					else if (cc == ((*it).x1) && bb == ((*it).y1))
					{
						if( bb == ((*it).x2) && y == ((*it).y2) ) v3 =1;
						else v3=0;						
					}

					//if(v3==0 || v3==1) break;

				}

				for (std::vector<HiddenEdge>::iterator it = left.he.begin(); it != left.he.end(); ++it)
				{
					if(z == ((*it).x1) && y == ((*it).y1))
					{
						if( cc == ((*it).x2) && bb == ((*it).y2) ) v3 =1;
						else v3=0;
					}

					else if (cc == ((*it).x1) && bb == ((*it).y1))
					{
						if( z == ((*it).x2) && y == ((*it).y2) ) v3 =1;
						else v3=0;						
					}
					//if(v3==0 || v3==1) break;

				}
			}

			if(v1 && v2 && v3)
			{
				;
				//Add the edge.
			}

		}

	}
	for(int i=0; i < limit; i++ )
	{
		;

		
		
	}

}

class AdjacencyMatrix
{
    private:
        int n;
        int **adj;
        bool *visited;
    public:
        AdjacencyMatrix(int n)
        {
            this->n = n;
            visited = new bool [n];
            adj = new int* [n];
            for (int i = 0; i < n; i++)
            {
                adj[i] = new int [n];
                for(int j = 0; j < n; j++)
                {
                    adj[i][j] = 0;
                }
            }
        }
        /*
         * Adding Edge to Graph
         */ 
        void add_edge(int origin, int destin)
        {
            if( origin > n || destin > n || origin < 0 || destin < 0)
            {   
                cout<<"Invalid edge!\n";
            }
            else
            {
                adj[origin - 1][destin - 1] = 1;
            }
        }
        /*
         * Print the graph
         */ 
        void display()
        {
            int i,j;
            for(i = 0;i < n;i++)
            {
                for(j = 0; j < n; j++)
                    cout<<adj[i][j]<<"  ";
                cout<<endl;
            }
        }
};


void threeDReconstruct(TwoDBody twodbody, ThreeDBody threedbody)
{
	//reconstructs 3D skeleton.
}