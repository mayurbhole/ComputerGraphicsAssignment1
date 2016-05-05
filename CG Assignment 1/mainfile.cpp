#include "GL/freeglut.h"
#include "GL/gl.h"
#include <stdio.h>
#include <math.h>

#include "controller.h"
#include "view.h"
#include "model.h"



char title[] = "3D Shapes";

int main(int argc,char** argv)
{
    glutInit(&argc, argv);            // Initialize GLUT
	count=0;
	glutInitDisplayMode(GLUT_DOUBLE);  // Enable double buffered mode
	glutInitWindowSize(600, 600);      // Set the window's initial width & height
	glutInitWindowPosition(50, 50);    // Position the window's initial top-left corner
	glutCreateWindow(title);           // Create window with the given title
	glutDisplayFunc(view::display);          // Register callback handler for window re-paint event
	glutReshapeFunc(view::reshape);          // Register callback handler for window re-size event
	glutMouseFunc(controller::mouse);
	glutMotionFunc(controller::motionMouse);
	glutKeyboardFunc(controller::keyboardInput);
	glutSpecialFunc(controller::special);
	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;

}
