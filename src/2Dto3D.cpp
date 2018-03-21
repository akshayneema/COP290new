
#include "2Dto3D.h"

// top-> xz  front -> xy left -> zy
ThreeDBody threeDlabel (TwoDBody &top,TwoDBody &front,TwoDBody &left) //,Labelled2D side
{
	ThreeDBody temp;
	std::vector<Vertex3D> vobj;
	std::vector<Edge3D> eobj;

	int n = top.v.size();
	double x,y,z;

	TwoDBody top1 = top;
	TwoDBody front1 = front;

	for(int i=0; i < n; i++ )
	{
		x = top1.v.back().x;
		y;
		z = top1.v.back().y;
		string labeler;
		vector<string> vec_label = top1.v.back().vec_label;
		int label_sz = vec_label.size();


 		for (int i=0;i<label_sz;i++)
		 {
			string labeled = vec_label.back();
			int done = 0;
			for (std::vector<Vertex2D>::iterator it = front1.v.begin(); done ==0 && it != front1.v.end(); ++it)
			{
				vector<string> tmp = (*it).vec_label;
				int size_lp = tmp.size();

				for(int j=0;j<size_lp && done == 0;j++)
				{
					string asli = tmp.at(j);

					if(labeled == asli) 
					{
						y = (*it).y;
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

						// cout << labeler << "   ("<< x << ','<< y << ','<< z << ")  "  << endl;

					}
				}
			}
			vec_label.pop_back();

			//cout << 69 << endl;
		 }


		top1.v.pop_back();
	}

	std::vector<Vertex3D> temp_vobj = vobj;
	//top1 = top;
	front1 = front;

	int limit = temp.v.size();
	int adj[limit][limit];

	for (std::vector<Vertex3D>::iterator it_a = temp.v.begin(); it_a != temp.v.end(); ++it_a)
	{
		x = (*it_a).x ;
		y = (*it_a).y ;
		z = (*it_a).z ;
		

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
				v3 =1;
			}
			else
			{
				for (std::vector<VisibleEdge>::iterator it = left.ve.begin(); it != left.ve.end(); ++it)
				{
					//cout << 263 <<endl;
					if(z == ((*it).x1) && y == ((*it).y1))
					{
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
				// cout << "Edges : "<<'('<< x << ','<< y << ','<< z << ")   ("<<aa<< ','<< bb << ','<<cc << ')'<< endl;

				//vobj.push_back(vtemp);
				temp.e.push_back(vtemp);
				//Add the edge.
			}

		}

	}
	return temp;
}

