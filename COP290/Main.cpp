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

	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(640, 320);   // Set the window's initial width & height
	glutInitWindowPosition(100, 50); // Position the window's initial top-left corner
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the infinitely event-processing loop
	return 0;

};
	//encapsulates all the functions involving 3d to 2d projection.
