#include <GL/glut.h>
// #include "Reduce3DInput.h"
#include "3Dto2D.h"
// #include "Recreate2DOutput.h"

// #include "Reduce2DInput.h"
#include "2Dto3D.h"
// #include "Recreate3DOutput.h"

#include <string>
#include <vector>
#include <math.h>
#include "myarea.h"
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <fstream>
#include<bits/stdc++.h>
#include <stdlib.h> 
// #include "buttons.h"
using namespace std;


int type=0; 
int main(int argc, char** argv){
	// cout<<"enter file name:"<<argv[1]<<"\n";
	ifstream inFile;

	cout << "Give a file name to input " << endl;
	
	string fl_name;
	getline(cin,fl_name);

	inFile.open(fl_name);

	// int type=0; 

	TwoDBody top,front,left;

	Vertex2D v_temp2D;
	VisibleEdge e_temp2D;
	vector<string> vec_label_tmp;

	Vertex3D v_temp3D;
	Edge3D e_temp3D;
	Plane3D p_temp3D;

	string output;

	if (inFile.is_open()) 
	{
		if(!inFile.eof())
		{
			inFile >> output;
			transform(output.begin(), output.end(), output.begin(), ::tolower);
			if(output == "2dto3d") type=1;
			else if (output == "3dto2d") type=2;
			else cout << "Try Again" <<endl;
			type_equal(type);

		}

		if(type==1)
		{	
			while(!inFile.eof())
			{
				inFile >> output;
				//cout<<output<<endl;

				transform(output.begin(), output.end(), output.begin(), ::tolower);
				string view_type = output;
				TwoDBody temp;

				inFile >> output;
				inFile >> output;

				while (!inFile.eof()) 
				{

					//v_temp2D.x = atof(output);
					v_temp2D.x = atof (output.c_str());
					inFile >> output;
					v_temp2D.y = atof(output.c_str());
					inFile >> output;
					inFile >> output;
					while(output != "]")
					{	
						vec_label_tmp.push_back(output);
						inFile >> output;
					}
					v_temp2D.vec_label = vec_label_tmp;
					temp.v.push_back(v_temp2D);

					vec_label_tmp.clear();

					inFile >> output;
					if(output == ";") break;
				

				}

				inFile >> output;
				
				//cout << output <<endl;
				inFile >> output;

				while (!inFile.eof()) 
				{
					e_temp2D.x1 = atof (output.c_str());
					inFile >> output;
					e_temp2D.y1 = atof(output.c_str());
					inFile >> output;
					e_temp2D.x2 = atof (output.c_str());
					inFile >> output;
					e_temp2D.y2 = atof(output.c_str());

					temp.ve.push_back(e_temp2D);

					inFile >> output;
					if(output == ";;") break;
				}

				//inFile >> output;
				//cout << output <<endl;

				if(view_type == "top")
				{
					//cout << "Stop" << endl;
					top = temp;
				}
				else if(view_type == "front")
				{
					//cout << "Stop2" << endl;
					front = temp;
				}
				else if(view_type == "left")
				{
					//cout << "Stop3" << endl;
					left = temp;
				}
				else 
				{
					cout << "Something Wrong" << endl;
				}

			}

		// 	rotate3D(temp,normalofplane(aq,sw,de,fr));
		// 	hiddenedgedetection(temp, aq,sw,de,fr);
		// 	TwoDBody twdb;
		// 	twdb=TopView(temp);
		// 	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

		//    Gtk::Window win;
		//    win.set_title("AutoCad");
		//    win.set_default_size(640, 360);

		//    MyArea area;
		//    win.add(area);
		//    area.show();

		//    return app->run(win);




			 ThreeDBody threedb;
			 threedb=threeDlabel(top,front,left);

			 
			 // threedb.rotate(true,.1,true,.15,true,.05);
			 ThreeDBody tdbtemp=rotate3D(threedb,normalofplane(1,1,1,1));
			 ThreeDBodi (threedb);
				
			TopView(tdbtemp);
			auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
			MyWindow win;
			win.set_default_size(640, 360);
			win.set_title("AutoCad");

		   return app->run(win);
		}

		else if(type==2)
		{
			ThreeDBody temp;
			double aq,sw,de,fr;
			if(!inFile.eof())
			{
				

				inFile >> output;
				inFile >> output;

				while (!inFile.eof()) 
				{

					//v_temp2D.x = atof(output);
					v_temp3D.x = atof (output.c_str());
					inFile >> output;
					v_temp3D.y = atof(output.c_str());
					inFile >> output;
					v_temp3D.z = atof(output.c_str());
						
					temp.v.push_back(v_temp3D);


					inFile >> output;
					if(output == ";") break;
				

				}

				inFile >> output;
				// cout<<output<<endl;
				
				//cout << output <<endl;
				inFile >> output;

				while (!inFile.eof()) 
				{
					e_temp3D.x1 = atof (output.c_str());
					inFile >> output;
					e_temp3D.y1 = atof(output.c_str());
					inFile >> output;
					e_temp3D.z1 = atof(output.c_str());
					inFile >> output;
					e_temp3D.x2 = atof (output.c_str());
					inFile >> output;
					e_temp3D.y2 = atof(output.c_str());
					inFile >> output;
					e_temp3D.z2 = atof(output.c_str());

					temp.e.push_back(e_temp3D);

					inFile >> output;
					if(output == ";;") break;
				}
				// cout<<output<<endl;
				inFile >> output;
				inFile >> output;
				inFile >> output;
				//boolean bigClos = true;

				std::vector<Edge3D> plane;
				// cout<<output<<endl;

				while(true)
				{
					while(true)
					{
					
						inFile >> output;
						// if(output!="-10.0")cout<<output<<endl;
						//cout<<output<<endl;

						e_temp3D.x1 = atof (output.c_str());
						inFile >> output;
						e_temp3D.y1 = atof(output.c_str());
						inFile >> output;
						e_temp3D.z1 = atof(output.c_str());
						inFile >> output;
						e_temp3D.x2 = atof (output.c_str());
						inFile >> output;
						e_temp3D.y2 = atof(output.c_str());
						inFile >> output;
						e_temp3D.z2 = atof(output.c_str());
						inFile >> output;

						inFile >> output;

						plane.push_back(e_temp3D);



						if(output == "]") break;


					}

					//cout<<output<<endl;
					Plane3D pl;
					pl.plane=plane;

					plane.clear();
					temp.p.push_back(pl);

					inFile >> output;

					// cout<<output<<endl;
					if(output == ";;;") break;

					inFile >> output;

				}	

				inFile >> output;
				aq = atof (output.c_str());

				inFile >> output;
				sw = atof (output.c_str());

				inFile >> output;
				de = atof (output.c_str());

				inFile >> output;
				fr = atof (output.c_str());

			}
			// cout<<"d="<<fr<<"\n";

			
			ThreeDBody tdbtemp=rotate3D(temp,normalofplane(aq,sw,de,fr));
			hiddenedgedetection(tdbtemp, aq,sw,de,fr);
			TwoDBody twdb;
			twdb=TopView(tdbtemp);
			auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

		   MyWindow win;
		   win.set_title("AutoCad");
		   win.set_default_size(640, 360);

		   return app->run(win);
		
		}
	}
	return 0;
}