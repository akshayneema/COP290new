#include <GL/glut.h>
#include "Reduce3DInput.h"
#include "3Dto2D.h"
#include "Recreate2DOutput.h"

#include "Reduce2DInput.h"
#include "2Dto3D.h"
#include "Recreate3DOutput.h"
// GUI interface


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

//int main(std::ifstream &InputFile)
int main(int argc, char** argv){

	// glutInit(&argc, argv);                 // Initialize GLUT
	// glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	// glutInitWindowSize(640, 320);   // Set the window's initial width & height
	// glutInitWindowPosition(100, 50); // Position the window's initial top-left corner
	// glutDisplayFunc(display); // Register display callback handler for window re-paint
	// glutMainLoop();
	// cout<< normalofplane(1,1,1,1)[0]<<" "<<normalofplane(1,1,1,1)[1]<<" "<<normalofplane(1,1,1,1)[2]; 
	Vertex3D v1;
	v1.x=0;
	v1.y=0;
	v1.z=0;
	Vertex3D v2;
	v2.x=1;
	v2.y=0;
	v2.z=0;
	Vertex3D v3;
	v3.x=0;
	v3.y=1;
	v3.z=0;
	Vertex3D v4;
	v4.x=0;
	v4.y=0;
	v4.z=1;
	std::vector<Vertex3D> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	Edge3D e1;
	e1.x1=0;
	e1.y1=0;
	e1.z1=0;
	e1.x2=1;
	e1.y2=0;
	e1.z2=0;
	Edge3D e2;
	e2.x1=0;
	e2.y1=0;
	e2.z1=0;
	e2.x2=0;
	e2.y2=1;
	e2.z2=0;
	Edge3D e3;
	e3.x1=0;
	e3.y1=0;
	e3.z1=0;
	e3.x2=0;
	e3.y2=0;
	e3.z2=1;
	Edge3D e4;
	e4.x1=0;
	e4.y1=0;
	e4.z1=1;
	e4.x2=1;
	e4.y2=0;
	e4.z2=0;
	Edge3D e5;
	e5.x1=1;
	e5.y1=0;
	e5.z1=0;
	e5.x2=0;
	e5.y2=1;
	e5.z2=0;
	Edge3D e6;
	e6.x1=0;
	e6.y1=1;
	e6.z1=0;
	e6.x2=0;
	e6.y2=0;
	e6.z2=1;
	std::vector<Edge3D> e;
	e.push_back(e1);
	e.push_back(e2);
	e.push_back(e3);
	e.push_back(e4);
	e.push_back(e5);
	e.push_back(e6);
	Plane3D p1;
	p1.plane.push_back(e1);
	p1.plane.push_back(e3);
	p1.plane.push_back(e4);
	Plane3D p2;
	p2.plane.push_back(e3);
	p2.plane.push_back(e2);
	p2.plane.push_back(e6);
	Plane3D p3;
	p3.plane.push_back(e4);
	p3.plane.push_back(e5);
	p3.plane.push_back(e6);
	Plane3D p4;
	p4.plane.push_back(e2);
	p4.plane.push_back(e5);
	p4.plane.push_back(e1);
	std::vector<Plane3D> p;
	p.push_back(p1);
	p.push_back(p2);
	p.push_back(p3);
	p.push_back(p4);
	ThreeDBody tdb;
	tdb.v=v;
	tdb.e=e;
	tdb.p=p;
	cout<< tdb.v[0].x<<" "<<tdb.v[0].y<<" "<<tdb.v[0].z<<"\n";
	cout<< tdb.v[1].x<<" "<<tdb.v[1].y<<" "<<tdb.v[1].z<<"\n";
	cout<< tdb.v[2].x<<" "<<tdb.v[2].y<<" "<<tdb.v[2].z<<"\n";
	cout<< tdb.v[3].x<<" "<<tdb.v[3].y<<" "<<tdb.v[3].z<<"\n";
	rotate3D(tdb, normalofplane(-1,-1,5,10));
	cout<< tdb.v[0].x<<" "<<tdb.v[0].y<<" "<<tdb.v[0].z<<"\n";
	cout<< tdb.v[1].x<<" "<<tdb.v[1].y<<" "<<tdb.v[1].z<<"\n";
	cout<< tdb.v[2].x<<" "<<tdb.v[2].y<<" "<<tdb.v[2].z<<"\n";
	cout<< tdb.v[3].x<<" "<<tdb.v[3].y<<" "<<tdb.v[3].z<<"\n";
	cout<< "("<<tdb.e[0].x1<<","<<tdb.e[0].y1<<","<<tdb.e[0].z1<<")"<<" "<< "("<<tdb.e[0].x2<<","<<tdb.e[0].y2<<","<<tdb.e[0].z2<<")"<<"\n";
	cout<< "("<<tdb.e[1].x1<<","<<tdb.e[1].y1<<","<<tdb.e[1].z1<<")"<<" "<< "("<<tdb.e[1].x2<<","<<tdb.e[1].y2<<","<<tdb.e[1].z2<<")"<<"\n";
	cout<< "("<<tdb.e[2].x1<<","<<tdb.e[2].y1<<","<<tdb.e[2].z1<<")"<<" "<< "("<<tdb.e[2].x2<<","<<tdb.e[2].y2<<","<<tdb.e[2].z2<<")"<<"\n";
	cout<< "("<<tdb.e[3].x1<<","<<tdb.e[3].y1<<","<<tdb.e[3].z1<<")"<<" "<< "("<<tdb.e[3].x2<<","<<tdb.e[3].y2<<","<<tdb.e[3].z2<<")"<<"\n";
	cout<< "("<<tdb.e[4].x1<<","<<tdb.e[4].y1<<","<<tdb.e[4].z1<<")"<<" "<< "("<<tdb.e[4].x2<<","<<tdb.e[4].y2<<","<<tdb.e[4].z2<<")"<<"\n";
	cout<< "("<<tdb.e[5].x1<<","<<tdb.e[5].y1<<","<<tdb.e[5].z1<<")"<<" "<< "("<<tdb.e[5].x2<<","<<tdb.e[5].y2<<","<<tdb.e[5].z2<<")"<<"\n";
	std::vector<Edge3D> segedge;
	hiddenedgedetection(tdb, -1,-1,5,10);
	for (std::vector<Edge3D>::iterator it = tdb.e.begin() ; it != tdb.e.end(); it++)
	{
		cout<< "("<<(*it).x1<<","<<(*it).y1<<","<<(*it).z1<<")"<<" "<< "("<<(*it).x2<<","<<(*it).y2<<","<<(*it).z2<<")"<<"\n";
		cout<<(*it).visibility<<"\n";
	}
	          // Enter the infinitely event-processing loop
	return 0;

};
	//encapsulates all the functions involving 3d to 2d projection.
