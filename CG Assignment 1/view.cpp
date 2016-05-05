#include "GL/freeglut.h"
#include "GL/gl.h"

#include "controller.h"
#include "view.h"
#include "model.h"

#include <stdio.h>
#include <math.h>

#define X .525731112119133606
#define Z .850650808352039932


/* Global variables */
/*
char title[] = "3D Shapes";
float distance;
float MouseX1, MouseY1, MouseX2, MouseY2;
float count=0;
float transX=0.0, transY=0.0;
bool mouseRightDown=false;
float mX,mY,camAngleX,camAngleY;
float camDist=-7.0;
float a=0.0;
float radius=1;
float hl = 1.0;
int flag=1;
float step = 0.6366;
*/

view v;
controller c;

/* Initialize OpenGL Graphics */
void view::initGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling

	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void view::drawAxis()
{

	glPushMatrix();

	// drawing axes
	glBegin(GL_LINES);

	// draw line for x axis
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-10.0, 0.0, 0.0);
	glVertex3f(10.0, 0.0, 0.0);

	// draw line for y axis
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, -10.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);

	// draw line for Z axis
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, -10.0);
	glVertex3f(0.0, 0.0, 10.0);
	glEnd();

	glPopMatrix();

}

//Draw Cube
void view::drawCube ()
{
	glPushMatrix();
	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads

	// Top face (y = 1.0f)
	// Define vertices in counter-clockwise (CCW) order with normal pointing out
	glColor3f(0.0f, 1.0f, 0.0f);     // Green
	glVertex3f( 1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f,  1.0f);
	glVertex3f( 1.0f, 1.0f,  1.0f);

	// Bottom face (y = -1.0f)
	glColor3f(1.0f, 0.5f, 0.0f);     // Orange
	glVertex3f( 1.0f, -1.0f,  1.0f);
	glVertex3f(-1.0f, -1.0f,  1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f( 1.0f, -1.0f, -1.0f);

	// Front face  (z = 1.0f)
	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f( 1.0f,  1.0f, 1.0f);
	glVertex3f(-1.0f,  1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f( 1.0f, -1.0f, 1.0f);

	// Back face (z = -1.0f)
	glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
	glVertex3f( 1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f,  1.0f, -1.0f);
	glVertex3f( 1.0f,  1.0f, -1.0f);

	// Left face (x = -1.0f)
	glColor3f(0.0f, 0.0f, 1.0f);     // Blue
	glVertex3f(-1.0f,  1.0f,  1.0f);
	glVertex3f(-1.0f,  1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f,  1.0f);

	// Right face (x = 1.0f)
	glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
	glVertex3f(1.0f,  1.0f, -1.0f);
	glVertex3f(1.0f,  1.0f,  1.0f);
	glVertex3f(1.0f, -1.0f,  1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();  // End of drawing color-cube
	glPopMatrix();

}



//Draw Cylinder
void view::drawCylinder()
{
    float a=0.0;
    float x = cos(a) * radius;
    float z = sin(a) * radius;
	float i;
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(x, -hl, z);

	for(i=0; i<=2*3.14;i+=0.001)
		glVertex3f(1*cos(i),1.0,1*sin(i));

	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
    for (i = 0; i < 100; ++i)
    {
        x = cos(a) * radius;
        z = sin(a) * radius;
        glVertex3f(x,-hl,z);
        glVertex3f(x,hl,z);

        a += step;
    }
glEnd();
}



//Draw Sphere
void view::drawtri(GLfloat *a, GLfloat *b, GLfloat *c, int div, float r) {
    if (div<=0) {
        glNormal3fv(a); glVertex3f(a[0]*r, a[1]*r, a[2]*r);
        glNormal3fv(b); glVertex3f(b[0]*r, b[1]*r, b[2]*r);
        glNormal3fv(c); glVertex3f(c[0]*r, c[1]*r, c[2]*r);
    } else {
        GLfloat ab[3], ac[3], bc[3];
        for (int i=0;i<3;i++) {
            ab[i]=(a[i]+b[i])/2;
            ac[i]=(a[i]+c[i])/2;
            bc[i]=(b[i]+c[i])/2;
        }
        model m;
        m.normalize(ab); m.normalize(ac); m.normalize(bc);
        drawtri(a, ab, ac, div-1, r);
        drawtri(b, bc, ab, div-1, r);
        drawtri(c, ac, bc, div-1, r);
        drawtri(ab, bc, ac, div-1, r);  //<--Comment this line and see the sphere
    }
}

void view::drawsphere(int ndiv, float radius=1.0) {
    glBegin(GL_TRIANGLES);
    for (int i=0;i<20;i++)
        v.drawtri(vdata[tindices[i][0]], vdata[tindices[i][1]], vdata[tindices[i][2]], ndiv, radius);
    glEnd();
}

void view::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

	// Render a color-cube consisting of 6 quads with different colors
	glLoadIdentity();                 // Reset the model-view matrix
	glTranslatef(c.getTransX(),c.getTransY(), c.getCamDist());  // Move right and into the screen
	//	  glTranslatef(0.0f, -1.5, 0.0f

	glRotatef(c.getCamAngleX(),1,0,0);
	glRotatef(c.getCamAngleY(),0,1,0);
	v.drawAxis();

	if(c.getFlag()==1)
	{
		v.drawCube();
	}
	else if(c.getFlag()==2)
	{
		v.drawCylinder();
	}
	else
	{
		v.drawsphere(5,1.0);
	}
	printf("%d ",c.getFlag());
	glFlush();
	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
	glutPostRedisplay();
}


void view::reshape(GLsizei width, GLsizei height)
{
	 // GLsizei for non-negative integer
	// Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset

	// Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

