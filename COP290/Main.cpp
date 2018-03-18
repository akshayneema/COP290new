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
//int main(std::ifstream &InputFile)
int main(int argc, char** argv){

/*
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(640, 320);   // Set the window's initial width & height
	glutInitWindowPosition(100, 50); // Position the window's initial top-left corner
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the infinitely event-processing loop
*/

	TwoDBody top,front,left;
	std::vector<Vertex2D> vobj;
	std::vector<VisibleEdge> e1_obj;
	std::vector<HiddenEdge> e2_obj;
	Vertex2D temp;
	VisibleEdge ve_temp;
	HiddenEdge he_temp; 
	vector<string> vec_label_tmp;

	//vobj.push_back(temp);

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

			top.v.push_back(temp);
			vec_label_tmp.clear();

			temp.x =2;
			temp.y =0.6;
			vec_label_tmp.push_back("c");
			vec_label_tmp.push_back("d");
			//vec_label_tmp.push_back("d");
			temp.vec_label = vec_label_tmp ;

			top.v.push_back(temp);


vec_label_tmp.clear();

			temp.x =0.6;
			temp.y =2;
			vec_label_tmp.push_back("e");
			vec_label_tmp.push_back("f");
			//vec_label_tmp.push_back("d");
			temp.vec_label = vec_label_tmp ;

			top.v.push_back(temp);
vec_label_tmp.clear();

			temp.x =2;
			temp.y =2;
			vec_label_tmp.push_back("g");
			vec_label_tmp.push_back("h");
			//vec_label_tmp.push_back("d");
			temp.vec_label = vec_label_tmp ;

			top.v.push_back(temp);			
vec_label_tmp.clear();
		}

		{
			//Edges
			ve_temp.x1 =0.6;
			ve_temp.y1 =0.6;
			ve_temp.x2 =0.6;
			ve_temp.y2 =2;

			top.ve.push_back(ve_temp);

			ve_temp.x2 =2;
			ve_temp.y2 =0.6;

			top.ve.push_back(ve_temp);

			ve_temp.x1 =2;
			ve_temp.y1 =2;
			top.ve.push_back(ve_temp);

			ve_temp.x2 =0.6;
			ve_temp.y2 =2;

			top.ve.push_back(ve_temp);

			
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
			
			temp.vec_label = vec_label_tmp ;

			front.v.push_back(temp);
vec_label_tmp.clear();
			temp.x =2;
			temp.y =2;
			vec_label_tmp.push_back("d");
			vec_label_tmp.push_back("h");
			
			temp.vec_label = vec_label_tmp ;

			front.v.push_back(temp);

vec_label_tmp.clear();									
		}

		{
			//Edges
			ve_temp.x1 =0.6;
			ve_temp.y1 =0.6;
			ve_temp.x2 =0.6;
			ve_temp.y2 =2;

			front.ve.push_back(ve_temp);

			ve_temp.x2 =2;
			ve_temp.y2 =0.6;

			front.ve.push_back(ve_temp);

			ve_temp.x1 =2;
			ve_temp.y1 =2;
			front.ve.push_back(ve_temp);

			ve_temp.x2 =0.6;
			ve_temp.y2 =2;

			front.ve.push_back(ve_temp);			
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
			ve_temp.x1 =0.6;
			ve_temp.y1 =0.6;
			ve_temp.x2 =0.6;
			ve_temp.y2 =2;

			left.ve.push_back(ve_temp);

			ve_temp.x2 =2;
			ve_temp.y2 =0.6;

			left.ve.push_back(ve_temp);

			ve_temp.x1 =2;
			ve_temp.y1 =2;
			left.ve.push_back(ve_temp);

			ve_temp.x2 =0.6;
			ve_temp.y2 =2;

			left.ve.push_back(ve_temp);			
			
		}
	}

	threeDlabel(top,front,left);

	return 0;

};
	//encapsulates all the functions involving 3d to 2d projection.
