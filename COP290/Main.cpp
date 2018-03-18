#include <GL/glut.h>
#include "Reduce3DInput.h"
#include "3Dto2D.h"
#include "Recreate2DOutput.h"

#include "Reduce2DInput.h"
#include "2Dto3D.h"
#include "Recreate3DOutput.h"

#include <string>
#include <vector>
#include <math.h>
#include "myarea.h"
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <fstream>
#include<bits/stdc++.h>
#include <stdlib.h> 
using namespace std;


// GUI interface

/*
void display() {

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
 
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex2f(-0.5f, -0.5f);    // x, y
    glVertex2f( 0.4f, -0.6f);
    glVertex2f( 0.6f,  0.4f);
    glVertex2f(-0.5f,  0.5f);
	glEnd();
 
	glFlush();  // Render now
};
*/

int main(int argc, char** argv){
	ifstream inFile;
<<<<<<< HEAD
	inFile.open("testP.txt");
=======
	inFile.open("3dip.txt");
>>>>>>> e027de3d275ae66f8b27d338a69d56d1f2ec9390

	int type=0; 

	//char output[100];
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

			threeDlabel(top,front,left);
		}

		else if(type==2)
		{
			ThreeDBody temp;
			double aq,sw,de,fr;
			while(!inFile.eof())
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
					//inFile >> output;
					//inFile >> output;
					
					temp.v.push_back(v_temp3D);


					inFile >> output;
					if(output == ";") break;
				

				}

				inFile >> output;
				
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

				inFile >> output;
				inFile >> output;
				//boolean bigClos = true;

				std::vector<Edge3D> plane;

				while(true)
				{
					while(true)
					{
						

						inFile >> output;

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
					Plane3D pl;
					pl.plane=plane;
					temp.p.push_back(pl);

					inFile >> output;
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
			rotate3D(temp,normalofplane(aq,sw,de,fr));
			hiddenedgedetection(temp, aq,sw,de,fr);
			TwoDBody twdb;
			twdb=TopView(temp);
			auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

		   Gtk::Window win;
		   win.set_title("AutoCad");

		   MyArea area;
		   win.add(area);
		   area.show();

		   return app->run(win);


			
		}
	}

	return 0;
}


/*
//int main(std::ifstream &InputFile)
int main(int argc, char** argv){


	// glutInit(&argc, argv);                 // Initialize GLUT
	// glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	// glutInitWindowSize(640, 320);   // Set the window's initial width & height
	// glutInitWindowPosition(100, 50); // Position the window's initial top-left corner
	// glutDisplayFunc(display); // Register display callback handler for window re-paint
	// glutMainLoop();
	// cout<< normalofplane(1,1,1,1)[0]<<" "<<normalofplane(1,1,1,1)[1]<<" "<<normalofplane(1,1,1,1)[2]; 
	// Vertex3D v1;
	// v1.x=0;
	// v1.y=0;
	// v1.z=0;
	// Vertex3D v2;
	// v2.x=1;
	// v2.y=0;
	// v2.z=0;
	// Vertex3D v3;
	// v3.x=0;
	// v3.y=1;
	// v3.z=0;
	// Vertex3D v4;
	// v4.x=0;
	// v4.y=0;
	// v4.z=1;
	// std::vector<Vertex3D> v;
	// v.push_back(v1);
	// v.push_back(v2);
	// v.push_back(v3);
	// v.push_back(v4);
	// Edge3D e1;
	// e1.x1=0;
	// e1.y1=0;
	// e1.z1=0;
	// e1.x2=1;
	// e1.y2=0;
	// e1.z2=0;
	// Edge3D e2;
	// e2.x1=0;
	// e2.y1=0;
	// e2.z1=0;
	// e2.x2=0;
	// e2.y2=1;
	// e2.z2=0;
	// Edge3D e3;
	// e3.x1=0;
	// e3.y1=0;
	// e3.z1=0;
	// e3.x2=0;
	// e3.y2=0;
	// e3.z2=1;
	// Edge3D e4;
	// e4.x1=0;
	// e4.y1=0;
	// e4.z1=1;
	// e4.x2=1;
	// e4.y2=0;
	// e4.z2=0;
	// Edge3D e5;
	// e5.x1=1;
	// e5.y1=0;
	// e5.z1=0;
	// e5.x2=0;
	// e5.y2=1;
	// e5.z2=0;
	// Edge3D e6;
	// e6.x1=0;
	// e6.y1=1;
	// e6.z1=0;
	// e6.x2=0;
	// e6.y2=0;
	// e6.z2=1;
	// std::vector<Edge3D> e;
	// e.push_back(e1);
	// e.push_back(e2);
	// e.push_back(e3);
	// e.push_back(e4);
	// e.push_back(e5);
	// e.push_back(e6);
	// Plane3D p1;
	// p1.plane.push_back(e1);
	// p1.plane.push_back(e3);
	// p1.plane.push_back(e4);
	// Plane3D p2;
	// p2.plane.push_back(e3);
	// p2.plane.push_back(e2);
	// p2.plane.push_back(e6);
	// Plane3D p3;
	// p3.plane.push_back(e4);
	// p3.plane.push_back(e5);
	// p3.plane.push_back(e6);
	// Plane3D p4;
	// p4.plane.push_back(e2);
	// p4.plane.push_back(e5);
	// p4.plane.push_back(e1);
	// std::vector<Plane3D> p;
	// p.push_back(p1);
	// p.push_back(p2);
	// p.push_back(p3);
	// p.push_back(p4);
	// ThreeDBody tdb;
	// tdb.v=v;
	// tdb.e=e;
	// tdb.p=p;
	Vertex3D v1;
	v1.x=0;
	v1.y=0;
	v1.z=0;
	Vertex3D v2;
	v2.x=2;
	v2.y=0;
	v2.z=0;
	Vertex3D v3;
	v3.x=2;
	v3.y=2;
	v3.z=0;
	Vertex3D v4;
	v4.x=0;
	v4.y=2;
	v4.z=0;
	Vertex3D v5;
	v5.x=1;
	v5.y=1;
	v5.z=2;
	std::vector<Vertex3D> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);
	Edge3D e1;
	e1.x1=0;
	e1.y1=0;
	e1.z1=0;
	e1.x2=2;
	e1.y2=0;
	e1.z2=0;
	Edge3D e2;
	e2.x1=0;
	e2.y1=0;
	e2.z1=0;
	e2.x2=0;
	e2.y2=2;
	e2.z2=0;
	Edge3D e3;
	e3.x1=0;
	e3.y1=0;
	e3.z1=0;
	e3.x2=1;
	e3.y2=1;
	e3.z2=2;
	Edge3D e4;
	e4.x1=0;
	e4.y1=2;
	e4.z1=0;
	e4.x2=2;
	e4.y2=2;
	e4.z2=0;
	Edge3D e5;
	e5.x1=2;
	e5.y1=2;
	e5.z1=0;
	e5.x2=2;
	e5.y2=0;
	e5.z2=0;
	Edge3D e6;
	e6.x1=1;
	e6.y1=1;
	e6.z1=2;
	e6.x2=0;
	e6.y2=2;
	e6.z2=0;
	Edge3D e7;
	e7.x1=1;
	e7.y1=1;
	e7.z1=2;
	e7.x2=2;
	e7.y2=2;
	e7.z2=0;
	Edge3D e8;
	e8.x1=1;
	e8.y1=1;
	e8.z1=2;
	e8.x2=2;
	e8.y2=0;
	e8.z2=0;
	std::vector<Edge3D> e;
	e.push_back(e1);
	e.push_back(e2);
	e.push_back(e3);
	e.push_back(e4);
	e.push_back(e5);
	e.push_back(e6);
	e.push_back(e7);
	e.push_back(e8);
	Plane3D p1;
	p1.plane.push_back(e1);
	p1.plane.push_back(e3);
	p1.plane.push_back(e8);
	Plane3D p2;
	p2.plane.push_back(e3);
	p2.plane.push_back(e2);
	p2.plane.push_back(e6);
	Plane3D p3;
	p3.plane.push_back(e4);
	p3.plane.push_back(e7);
	p3.plane.push_back(e6);
	Plane3D p4;
	p4.plane.push_back(e7);
	p4.plane.push_back(e5);
	p4.plane.push_back(e8);
	Plane3D p5;
	p5.plane.push_back(e1);
	p5.plane.push_back(e2);
	p5.plane.push_back(e4);
	p5.plane.push_back(e5);
	std::vector<Plane3D> p;
	p.push_back(p1);
	p.push_back(p2);
	p.push_back(p3);
	p.push_back(p4);
	p.push_back(p5);
	ThreeDBody tdb;
	tdb.v=v;
	tdb.e=e;
	tdb.p=p;
	// cout<< tdb.v[0].x<<" "<<tdb.v[0].y<<" "<<tdb.v[0].z<<"\n";
	// cout<< tdb.v[1].x<<" "<<tdb.v[1].y<<" "<<tdb.v[1].z<<"\n";
	// cout<< tdb.v[2].x<<" "<<tdb.v[2].y<<" "<<tdb.v[2].z<<"\n";
	// cout<< tdb.v[3].x<<" "<<tdb.v[3].y<<" "<<tdb.v[3].z<<"\n";
	rotate3D(tdb, normalofplane(24,-100,34,-10));
	// cout<< tdb.v[0].x<<" "<<tdb.v[0].y<<" "<<tdb.v[0].z<<"\n";
	// cout<< tdb.v[1].x<<" "<<tdb.v[1].y<<" "<<tdb.v[1].z<<"\n";
	// cout<< tdb.v[2].x<<" "<<tdb.v[2].y<<" "<<tdb.v[2].z<<"\n";
	// cout<< tdb.v[3].x<<" "<<tdb.v[3].y<<" "<<tdb.v[3].z<<"\n";
	// cout<< "("<<tdb.e[0].x1<<","<<tdb.e[0].y1<<","<<tdb.e[0].z1<<")"<<" "<< "("<<tdb.e[0].x2<<","<<tdb.e[0].y2<<","<<tdb.e[0].z2<<")"<<"\n";
	// cout<< "("<<tdb.e[1].x1<<","<<tdb.e[1].y1<<","<<tdb.e[1].z1<<")"<<" "<< "("<<tdb.e[1].x2<<","<<tdb.e[1].y2<<","<<tdb.e[1].z2<<")"<<"\n";
	// cout<< "("<<tdb.e[2].x1<<","<<tdb.e[2].y1<<","<<tdb.e[2].z1<<")"<<" "<< "("<<tdb.e[2].x2<<","<<tdb.e[2].y2<<","<<tdb.e[2].z2<<")"<<"\n";
	// cout<< "("<<tdb.e[3].x1<<","<<tdb.e[3].y1<<","<<tdb.e[3].z1<<")"<<" "<< "("<<tdb.e[3].x2<<","<<tdb.e[3].y2<<","<<tdb.e[3].z2<<")"<<"\n";
	// cout<< "("<<tdb.e[4].x1<<","<<tdb.e[4].y1<<","<<tdb.e[4].z1<<")"<<" "<< "("<<tdb.e[4].x2<<","<<tdb.e[4].y2<<","<<tdb.e[4].z2<<")"<<"\n";
	// cout<< "("<<tdb.e[5].x1<<","<<tdb.e[5].y1<<","<<tdb.e[5].z1<<")"<<" "<< "("<<tdb.e[5].x2<<","<<tdb.e[5].y2<<","<<tdb.e[5].z2<<")"<<"\n";
	std::vector<Edge3D> segedge;
	hiddenedgedetection(tdb, 24,-100,34,-10);
	// for (std::vector<Edge3D>::iterator it = tdb.e.begin() ; it != tdb.e.end(); it++)
	// {
	// 	cout<< "("<<(*it).x1<<","<<(*it).y1<<","<<(*it).z1<<")"<<" "<< "("<<(*it).x2<<","<<(*it).y2<<","<<(*it).z2<<")"<<"\n";
	// 	cout<<(*it).visibility<<"\n";
	// }
	TwoDBody twdb;
	twdb=TopView(tdb);
	// for (std::vector<Edge2D>::iterator it = twdb.e.begin() ; it != twdb.e.end(); it++)
	// {
	// 	cout<< "("<<(*it).x1<<","<<(*it).y1<<")"<<" "<< "("<<(*it).x2<<","<<(*it).y2<<")"<<"\n";
	// 	cout<<"visibility="<<(*it).visibility<<"\n";
	// }
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

   Gtk::Window win;
   win.set_title("NeemautoCad");

   MyArea area;
   win.add(area);
   area.show();

   return app->run(win);
// 	          // Enter the infinitely event-processing loop
// =======
// 
// 	glutInit(&argc, argv);                 // Initialize GLUT
// 	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
// 	glutInitWindowSize(640, 320);   // Set the window's initial width & height
// 	glutInitWindowPosition(100, 50); // Position the window's initial top-left corner
// 	glutDisplayFunc(display); // Register display callback handler for window re-paint
// 	glutMainLoop();           // Enter the infinitely event-processing loop
// 

// 	TwoDBody top,front,left;
// 	std::vector<Vertex2D> vobj;
// 	std::vector<VisibleEdge> e1_obj;
// 	std::vector<HiddenEdge> e2_obj;
// 	Vertex2D temp;
// 	VisibleEdge ve_temp2D;
// 	HiddenEdge he_temp2D; 
// 	vector<string> vec_label_tmp;

// 	//vobj.push_back(temp);

<<<<<<< HEAD
// 	//For Top View . SImilar ones required for other views.
// 	{
// 		{
// 			//x-z View
// 			//Vertices
// 			temp.x =1;
// 			temp.y =1;
// 			vec_label_tmp.push_back("a");
// 			vec_label_tmp.push_back("b");
// 			//vec_label_tmp.push_back("d");
// 			temp.vec_label = vec_label_tmp ;
=======
	//For Top View . SImilar ones required for other views.
	{
		{
			//x-z View
			//Vertices
			temp.x =0.6;
			temp.y =0.6;
			vec_label_tmp.push_back("a");
			vec_label_tmp.push_back("b");
			//vec_label_tmp.push_back("d");
			temp.vec_label = vec_label_tmp ;
>>>>>>> 3069c33604abf2d7abdbcdb45af4677a2e0114e0

// 			top.v.push_back(temp);
// 			vec_label_tmp.clear();

<<<<<<< HEAD
// 			temp.x =2;
// 			temp.y =1;
// 			vec_label_tmp.push_back("c");
// 			vec_label_tmp.push_back("d");
// 			//vec_label_tmp.push_back("d");
// 			temp.vec_label = vec_label_tmp ;
=======
			temp.x =2;
			temp.y =0.6;
			vec_label_tmp.push_back("c");
			vec_label_tmp.push_back("d");
			//vec_label_tmp.push_back("d");
			temp.vec_label = vec_label_tmp ;
>>>>>>> 3069c33604abf2d7abdbcdb45af4677a2e0114e0

// 			top.v.push_back(temp);


// vec_label_tmp.clear();

<<<<<<< HEAD
// 			temp.x =1;
// 			temp.y =2;
// 			vec_label_tmp.push_back("e");
// 			vec_label_tmp.push_back("f");
// 			//vec_label_tmp.push_back("d");
// 			temp.vec_label = vec_label_tmp ;
=======
			temp.x =0.6;
			temp.y =2;
			vec_label_tmp.push_back("e");
			vec_label_tmp.push_back("f");
			//vec_label_tmp.push_back("d");
			temp.vec_label = vec_label_tmp ;
>>>>>>> 3069c33604abf2d7abdbcdb45af4677a2e0114e0

// 			top.v.push_back(temp);
// vec_label_tmp.clear();

// 			temp.x =2;
// 			temp.y =2;
// 			vec_label_tmp.push_back("g");
// 			vec_label_tmp.push_back("h");
// 			//vec_label_tmp.push_back("d");
// 			temp.vec_label = vec_label_tmp ;

// 			top.v.push_back(temp);			
// vec_label_tmp.clear();
// 		}

<<<<<<< HEAD
// 		{
// 			//Edges
// 			ve_temp2D.x1 =1;
// 			ve_temp2D.y1 =1;
// 			ve_temp2D.x2 =1;
// 			ve_temp2D.y2 =2;
=======
		{
			//Edges
			ve_temp2D.x1 =0.6;
			ve_temp2D.y1 =0.6;
			ve_temp2D.x2 =0.6;
			ve_temp2D.y2 =2;
>>>>>>> 3069c33604abf2d7abdbcdb45af4677a2e0114e0

// 			top.ve.push_back(ve_temp2D);

<<<<<<< HEAD
// 			ve_temp2D.x2 =2;
// 			ve_temp2D.y2 =1;
=======
			ve_temp2D.x2 =2;
			ve_temp2D.y2 =0.6;
>>>>>>> 3069c33604abf2d7abdbcdb45af4677a2e0114e0

// 			top.ve.push_back(ve_temp2D);

// 			ve_temp2D.x1 =2;
// 			ve_temp2D.y1 =2;
// 			top.ve.push_back(ve_temp2D);

<<<<<<< HEAD
// 			ve_temp2D.x2 =1;
// 			ve_temp2D.y2 =2;
=======
			ve_temp2D.x2 =0.6;
			ve_temp2D.y2 =2;
>>>>>>> 3069c33604abf2d7abdbcdb45af4677a2e0114e0

// 			top.ve.push_back(ve_temp2D);

			
<<<<<<< HEAD
// 		}
// 	}

// 	//For Front View . SImilar ones required for other views.
// 	{
// 		{
// 			//x-y view
// 			//Vertices
// 			temp.x =1;
// 			temp.y =1;
// 			vec_label_tmp.push_back("a");
// 			vec_label_tmp.push_back("e");
			
// 			temp.vec_label = vec_label_tmp ;

// 			front.v.push_back(temp);
// vec_label_tmp.clear();
// 			temp.x =1;
// 			temp.y =2;
// 			vec_label_tmp.push_back("b");
// 			vec_label_tmp.push_back("f");
			
// 			temp.vec_label = vec_label_tmp ;

// 			front.v.push_back(temp);
// vec_label_tmp.clear();
// 			temp.x =2;
// 			temp.y =1;
// 			vec_label_tmp.push_back("c");
// 			vec_label_tmp.push_back("g");
=======
		}
	}

	//For Front View . SImilar ones required for other views.
	{
		{
			//x-y view
			//Vertices
			temp.x =0.6;
			temp.y =0.6;
			vec_label_tmp.push_back("a");
			vec_label_tmp.push_back("e");
			
			temp.vec_label = vec_label_tmp ;

			front.v.push_back(temp);
vec_label_tmp.clear();
			temp.x =0.6;
			temp.y =2;
			vec_label_tmp.push_back("b");
			vec_label_tmp.push_back("f");
			
			temp.vec_label = vec_label_tmp ;

			front.v.push_back(temp);
vec_label_tmp.clear();
			temp.x =2;
			temp.y =0.6;
			vec_label_tmp.push_back("c");
			vec_label_tmp.push_back("g");
>>>>>>> 3069c33604abf2d7abdbcdb45af4677a2e0114e0
			
// 			temp.vec_label = vec_label_tmp ;

// 			front.v.push_back(temp);
// vec_label_tmp.clear();
// 			temp.x =2;
// 			temp.y =2;
// 			vec_label_tmp.push_back("d");
// 			vec_label_tmp.push_back("h");
			
<<<<<<< HEAD
// 			temp.vec_label = vec_label_tmp ;

// 			front.v.push_back(temp);

// vec_label_tmp.clear();									
// 		}

// 		{
// 			//Edges
// 			ve_temp2D.x1 =1;
// 			ve_temp2D.y1 =1;
// 			ve_temp2D.x2 =1;
// 			ve_temp2D.y2 =2;

// 			front.ve.push_back(ve_temp2D);

// 			ve_temp2D.x2 =2;
// 			ve_temp2D.y2 =1;

// 			front.ve.push_back(ve_temp2D);

// 			ve_temp2D.x1 =2;
// 			ve_temp2D.y1 =2;
// 			front.ve.push_back(ve_temp2D);

// 			ve_temp2D.x2 =1;
// 			ve_temp2D.y2 =2;

// 			front.ve.push_back(ve_temp2D);			
// 		}
// 	}
// 	//For Left View . SImilar ones required for other views.
// 	{
// 		{
// 			//Vertices
// 			temp.x =1;
// 			temp.y =1;
// 			vec_label_tmp.push_back("a");
// 			vec_label_tmp.push_back("c");
// 			//vec_label_tmp.push_back("d");
// 			temp.vec_label = vec_label_tmp ;

// 			left.v.push_back(temp);
// vec_label_tmp.clear();
// 			temp.x =1;
// 			temp.y =2;
// 			vec_label_tmp.push_back("b");
// 			vec_label_tmp.push_back("d");
// 			//vec_label_tmp.push_back("d");
// 			temp.vec_label = vec_label_tmp ;

// 			left.v.push_back(temp);
// vec_label_tmp.clear();
// 			temp.x =2;
// 			temp.y =1;
// 			vec_label_tmp.push_back("e");
// 			vec_label_tmp.push_back("g");
// 			//vec_label_tmp.push_back("d");
// 			temp.vec_label = vec_label_tmp ;

// 			left.v.push_back(temp);
// vec_label_tmp.clear();
// 			temp.x =2;
// 			temp.y =2;
// 			vec_label_tmp.push_back("f");
// 			vec_label_tmp.push_back("h");
// 			//vec_label_tmp.push_back("d");
// 			temp.vec_label = vec_label_tmp ;

// 			left.v.push_back(temp);	

// vec_label_tmp.clear();								
// 		}

// 		{
// 			//Edges
// 			ve_temp2D.x1 =1;
// 			ve_temp2D.y1 =1;
// 			ve_temp2D.x2 =1;
// 			ve_temp2D.y2 =2;

// 			left.ve.push_back(ve_temp2D);

// 			ve_temp2D.x2 =2;
// 			ve_temp2D.y2 =1;

// 			left.ve.push_back(ve_temp2D);

// 			ve_temp2D.x1 =2;
// 			ve_temp2D.y1 =2;
// 			left.ve.push_back(ve_temp2D);

// 			ve_temp2D.x2 =1;
// 			ve_temp2D.y2 =2;

// 			left.ve.push_back(ve_temp2D);			
=======
			temp.vec_label = vec_label_tmp ;

			front.v.push_back(temp);

vec_label_tmp.clear();									
		}

		{
			//Edges
			ve_temp2D.x1 =0.6;
			ve_temp2D.y1 =0.6;
			ve_temp2D.x2 =0.6;
			ve_temp2D.y2 =2;

			front.ve.push_back(ve_temp2D);

			ve_temp2D.x2 =2;
			ve_temp2D.y2 =0.6;

			front.ve.push_back(ve_temp2D);

			ve_temp2D.x1 =2;
			ve_temp2D.y1 =2;
			front.ve.push_back(ve_temp2D);

			ve_temp2D.x2 =0.6;
			ve_temp2D.y2 =2;

			front.ve.push_back(ve_temp2D);			
		}
	}
	//For Left View . SImilar ones required for other views.
	{
		{
			//Vertices
			temp.x =0.6;
			temp.y =0.6;
			vec_label_tmp.push_back("a");
			vec_label_tmp.push_back("c");
			//vec_label_tmp.push_back("d");
			temp.vec_label = vec_label_tmp ;

			left.v.push_back(temp);
vec_label_tmp.clear();
			temp.x =0.6;
			temp.y =2;
			vec_label_tmp.push_back("b");
			vec_label_tmp.push_back("d");
			//vec_label_tmp.push_back("d");
			temp.vec_label = vec_label_tmp ;

			left.v.push_back(temp);
vec_label_tmp.clear();
			temp.x =2;
			temp.y =0.6;
			vec_label_tmp.push_back("e");
			vec_label_tmp.push_back("g");
			//vec_label_tmp.push_back("d");
			temp.vec_label = vec_label_tmp ;

			left.v.push_back(temp);
vec_label_tmp.clear();
			temp.x =2;
			temp.y =2;
			vec_label_tmp.push_back("f");
			vec_label_tmp.push_back("h");
			//vec_label_tmp.push_back("d");
			temp.vec_label = vec_label_tmp ;

			left.v.push_back(temp);	

vec_label_tmp.clear();								
		}

		{
			//Edges
			ve_temp2D.x1 =0.6;
			ve_temp2D.y1 =0.6;
			ve_temp2D.x2 =0.6;
			ve_temp2D.y2 =2;

			left.ve.push_back(ve_temp2D);

			ve_temp2D.x2 =2;
			ve_temp2D.y2 =0.6;

			left.ve.push_back(ve_temp2D);

			ve_temp2D.x1 =2;
			ve_temp2D.y1 =2;
			left.ve.push_back(ve_temp2D);

			ve_temp2D.x2 =0.6;
			ve_temp2D.y2 =2;

			left.ve.push_back(ve_temp2D);			
>>>>>>> 3069c33604abf2d7abdbcdb45af4677a2e0114e0
			
// 		}
// 	}

// 	threeDlabel(top,front,left);

// >>>>>>> 46e312f1551e606a97de5314af0bd70649c78eb6
	// return 0;

};
	//encapsulates all the functions involving 3d to 2d projection.
	*/
