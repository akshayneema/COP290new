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
void threeDlabel (TwoDBody top,TwoDBody front) //,Labelled2D side
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
			for (auto it = front1.v.begin(); it != front1.v.end(); ++it)
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
		top1.v.pop_back();
		//temp.v.push_back();
	}

	top1 = top;
	front1 = front;
	int adj[n][n];
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			adj[i][j] = 1;
		}
	}

	for(int i=0; i < n; i++ )
	{
		Edge3D eobj;
		
		
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