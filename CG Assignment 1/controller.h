#include "GL/freeglut.h"
#include "GL/gl.h"

static float mX,mY,camAngleX,camAngleY;
static float camDist=-7.0;
static float transX=0.0, transY=0.0;
static float hl = 1.0;
static float step = 0.6366;
static float radius=1;
static bool mouseRightDown=false;
static float MouseX1, MouseY1, MouseX2, MouseY2;
static float distance;
static int flag=1;
static float count=0;

class controller
{
    public:
    static void mouse(int,int,int,int);
    static void motionMouse(int,int);
    static void keyboardInput(unsigned char,int,int);
    static void special(int,int,int);
    int getFlag();
    float getTransX();
    float getTransY();
    float getCamAngleX();
    float getCamAngleY();
    float getCamDist();
};
