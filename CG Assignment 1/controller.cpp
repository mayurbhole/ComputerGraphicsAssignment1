#include "GL/freeglut.h"
#include "GL/gl.h"
#include "controller.h"
#include <math.h>

//Capture mouse location
void controller::mouse(int btn, int state, int x, int y)
{

	mX=x;
	mY=y;

	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		count++;

		if (count==1)
		{
		MouseX1 = (x-300)/(float)200;
		MouseY1 = (300-y)/(float)200;
		}

		if (count==2)
		{
		MouseX2 = (x-300)/(float)200;
		MouseY2 = (300-y)/(float)200;
		distance = sqrt ( (MouseX2-MouseX1)*(MouseX2-MouseX1) + (MouseY2-MouseY1)*(MouseY2-MouseY1) );

		count=0;
		}
	}

	if(btn==GLUT_RIGHT_BUTTON )
	{
		if(state==GLUT_DOWN)
		mouseRightDown = true;
		else if(state==GLUT_UP)
		mouseRightDown = false;
	}
}

//Capture mouse motion
void controller::motionMouse(int x,int y)
{
	if(mouseRightDown)
	{
		camAngleY+= (x-mX);
		camAngleX+=(y-mY);
		mX=x;
		mY=y;
	}
}


// Take input from keyboard
void controller::keyboardInput(unsigned char key, int x, int y)
{
	switch(key)
	{
		case '+':
			camDist += 0.2f;
			break;

		case '-':
			camDist -= 0.2f;
			break;

		case '1':                // Cube
			transX=0;
			transY=0;
			flag=1;
			break;

		case'2':                 //Cylinder
			transX=0;
			transY=0;
			flag=2;
			break;

		case'3':                 // Sphere
			transX=0;
			transY=0;
			flag=3;

	}

}

//Keyboard input for translation
void controller::special(int k, int x, int y)
{
	switch(k)
	{
		case GLUT_KEY_UP:    transY += distance; break;
		case GLUT_KEY_DOWN:  transY -= distance; break;
		case GLUT_KEY_LEFT:  transX -= distance; break;
		case GLUT_KEY_RIGHT: transX += distance; break;
	}
}
int controller::getFlag()
{
    return flag;
}


float controller::getTransX()
{
    return transX;
}

float controller::getTransY()
{
    return transY;
}

float controller::getCamAngleX()
{
    return camAngleX;
}
float controller::getCamAngleY()
{
    return camAngleY;
}

float controller::getCamDist()
{
    return camDist;
}


