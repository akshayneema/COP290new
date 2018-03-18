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
	//cout<< left.ve.size()<<endl;
	double x,y,z;

	TwoDBody top1 = top;
	TwoDBody front1 = front;

	for(int i=0; i < n; i++ )
	{
		x = top1.v.back().x;
		//cout << x << " " << 34 <<endl;
		y;
		//int y = front1.v.front().y;
		z = top1.v.back().y;
		string labeler;
		//string label = top1.v.front().label;
		vector<string> vec_label = top1.v.back().vec_label;
		//cout << vec_label <<endl;
		int label_sz = vec_label.size();
		//cout << label_sz <<endl;


 		for (int i=0;i<label_sz;i++)
		 {
			string labeled = vec_label.back();
			int done = 0;
			//cout <<"   "<< 45678907654678977  <<  labeled <<  endl;
			for (std::vector<Vertex2D>::iterator it = front1.v.begin(); done ==0 && it != front1.v.end(); ++it)
			{
				//cout<<labeled<<endl;
				vector<string> tmp = (*it).vec_label;
				int size_lp = tmp.size();
				//cout << size_lp << "    " << 54<< endl;

				for(int j=0;j<size_lp && done == 0;j++)
				{
					string asli = tmp.at(j);
					// cout<<" "<<endl;
					// cout<<asli<<" " <<labeled<<endl;
					// cout<<" "<<endl;
					if(labeled == asli) 
					{
						y = (*it).y;
						//cout<<y<<endl;
						labeler = asli; 
						done=1;

							Vertex3D vtemp;

							vtemp.x = x;
							vtemp.y = y;
							vtemp.z = z;
							vtemp.str = labeler;
							//cout << labeler <<endl;

							vobj.push_back(vtemp);
							temp.v.push_back(vtemp);

						cout << labeler << "   ("<< x << ','<< y << ','<< z << ")  "  << endl;

						// cout << endl;
						// cout << labeler << endl;

						// cout << 63 << endl;
					}
				}
			}
			vec_label.pop_back();

			//cout << 69 << endl;
		 }


		top1.v.pop_back();
		//top1.v.pop_back();
		//temp.v.push_back();
	}

	//cout<< left.ve.size()<<98<<endl;	
	std::vector<Vertex3D> temp_vobj = vobj;
	//top1 = top;
	front1 = front;

	//cout<< left.ve.size()<<103<<endl;

	int limit = temp.v.size();
	int adj[limit][limit];
	//cout << limit<<n<<n<<endl;

	//cout<< left.ve.size()<<"  " <<108<<endl;
	//cout<< left.ve.at(1).x1<<"  " <<109<<endl;
/*	
	for (int i = 0; i < limit; i++)
	{
		//cout<< left.ve.size()<<"  " <<112<<endl;
		for(int j = 0; j < limit; j++)
		{
			
			if(i<j) adj[i][j] = 1;
			else adj[i][j]=0;
			printf("%d",adj[i][j]);
			//cout<< left.ve.size()<<"  " <<115<<endl;
		}
		printf("\n");
	}

	*/

	// cout<< 120<<endl;
	// cout<< top.ve.size()<<"  " <<122<<endl;
	// cout<< 123<<endl;
	// cout<< left.ve.size()<<"  " <<124<<endl;
	//int x_1,y_1,z_1,x_2,y_2,z_2;
	//vector< pair <double,double> > front_e,top_e,left_e;
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
//cout<< left.ve.size()<<136<<endl;
cout << top.v.size() << endl;


	for (std::vector<Vertex3D>::iterator it_a = temp.v.begin(); it_a != temp.v.end(); ++it_a)
	{
		x = (*it_a).x ;
		y = (*it_a).y ;
		z = (*it_a).z ;

		//cout << 143 <<endl;
		cout << (*it_a).str << endl;
		

// top-> xz  front -> xy left -> zy
		double aa,bb,cc;
		int v1,v2,v3;
		//bool atmp =false;

		std::vector<Vertex3D>::iterator it = (it_a);
		
		

		if(it == temp.v.end()) break;

		for (it = ++it; it != temp.v.end() ; ++it)
		{
			//cout << 151 <<endl;
			
			aa = (*it).x ;
			bb = (*it).y ;	
			cc = (*it).z ;
			v1=0;
			v2=0;
			v3=0;

//Top x-z
			if( x==aa && z==cc)
			{
				v1 =1;
				//cout <<166<< endl;
			}
			else
			{
				for (std::vector<VisibleEdge>::iterator it = top.ve.begin(); it != top.ve.end(); ++it)
				{

					//cout<<173<<endl;
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

					if( v1==1) break;

				}
//cout<<189<<endl;
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
					if( v1==1) break;

				}
			}

//Front x-y 
			if( x==aa && y==bb)
			{
				//cout << 211 <<endl;
				v2 =1;
			}
			else
			{//cout << front.ve.size() << endl;
				for (std::vector<VisibleEdge>::iterator it = front.ve.begin(); it != front.ve.end(); ++it)
				{
						// cout << x << y <<aa <<bb<<endl;
						// cout << (*it).x1 << (*it).y1 <<(*it).x2 <<(*it).y2<<endl;

					//cout << 218 <<endl;
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

					if(v2==1) break;

				}
//cout<<234<<endl;
				for (std::vector<HiddenEdge>::iterator it = front.he.begin(); it != front.he.end(); ++it)
				{
					//cout<<237<<endl;
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
					if(v2==1) break;

				}
			}
//Left z-y
			if( z==cc && y==bb)
			{
				//cout << 256 <<endl;
				v3 =1;
			}
			else
			{
				//cout<<261<<endl;
				//cout << left.ve.size() <<281 << endl;
				//cout<<263<<endl;
				for (std::vector<VisibleEdge>::iterator it = left.ve.begin(); it != left.ve.end(); ++it)
				{
					//cout << 263 <<endl;
					if(z == ((*it).x1) && y == ((*it).y1))
					{
						//cout << 288 <<endl;
						// cout << z << y <<cc <<bb<<endl;
						// cout << (*it).x1 << (*it).y1 <<(*it).x2 <<(*it).y2<<endl;
						if( cc == ((*it).x2) && bb == ((*it).y2) ) v3 =1;
						else v3=0;
					}

					else if (cc == ((*it).x1) && bb == ((*it).y1))
					{
						//cout << 295 <<endl;
						if( z == ((*it).x2) && y == ((*it).y2) ) v3 =1;
						else v3=0;						
					}

					if(v3==1) break;

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
					if( v3==1) break;

				}
			}

			//cout << v1 <<" "<<v2<<" " <<v3 << " "<< (*it).str <<endl;

			if(v1 && v2 && v3)
			{
				Edge3D vtemp;

				vtemp.x1 = x;
				vtemp.x2 = aa;
				vtemp.y1 = y;
				vtemp.y2 = bb;
				vtemp.z1 = z;
				vtemp.z2 = cc;
				cout << '('<< x << ','<< y << ','<< z << ")   ("<<aa<< ','<< bb << ','<<cc << ')'<< endl;

				//vobj.push_back(vtemp);
				temp.e.push_back(vtemp);
				//Add the edge.
			}

		}

	}

	/*
	for(int i=0; i < limit; i++ )
	{
		;

		
		
	}*/

}


// class AdjacencyMatrix
// {
//     private:
//         int n;
//         int **adj;
//         bool *visited;
//     public:
//         AdjacencyMatrix(int n)
//         {
//             this->n = n;
//             visited = new bool [n];
//             adj = new int* [n];
//             for (int i = 0; i < n; i++)
//             {
//                 adj[i] = new int [n];
//                 for(int j = 0; j < n; j++)
//                 {
//                     adj[i][j] = 0;
//                 }
//             }
//         }

//         void add_edge(int origin, int destin)
//         {
//             if( origin > n || destin > n || origin < 0 || destin < 0)
//             {   
//                 cout<<"Invalid edge!\n";
//             }
//             else
//             {
//                 adj[origin - 1][destin - 1] = 1;
//             }
//         }
//         /*
//          * Print the graph
//          */ 
//         void display()
//         {
//             int i,j;
//             for(i = 0;i < n;i++)
//             {
//                 for(j = 0; j < n; j++)
//                     cout<<adj[i][j]<<"  ";
//                 cout<<endl;
//             }
//         }
// };



void threeDReconstruct(TwoDBody twodbody, ThreeDBody threedbody)
{
	//reconstructs 3D skeleton.
}