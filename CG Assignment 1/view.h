#include "GL/freeglut.h"
#include "GL/gl.h"

/*static float mX,mY,camAngleX,camAngleY;
static float camDist=-7.0;
static float transX=0.0, transY=0.0;
static float hl = 1.0;
static float step = 0.6366;
static float radius=1;
static bool mouseRightDown=false;
static float MouseX1, MouseY1, MouseX2, MouseY2;
static float distance;*/

#define X .525731112119133606
#define Z .850650808352039932

static GLfloat vdata[12][3] = {
    {-X, 0.0, Z}, {X, 0.0, Z}, {-X, 0.0, -Z}, {X, 0.0, -Z},
    {0.0, Z, X}, {0.0, Z, -X}, {0.0, -Z, X}, {0.0, -Z, -X},
    {Z, X, 0.0}, {-Z, X, 0.0}, {Z, -X, 0.0}, {-Z, -X, 0.0}
};
static GLuint tindices[20][3] = {
    {0,4,1}, {0,9,4}, {9,5,4}, {4,5,8}, {4,8,1},
    {8,10,1}, {8,3,10}, {5,3,8}, {5,2,3}, {2,7,3},
    {7,10,3}, {7,6,10}, {7,11,6}, {11,0,6}, {0,1,6},
    {6,1,10}, {9,0,11}, {9,11,2}, {9,2,5}, {7,2,11} };





class view
{
    public:
    static void initGL();
    static void display();
    void drawAxis();
    void drawCube ();
    void drawCylinder();
    void drawtri(GLfloat *,GLfloat *,GLfloat *,int,float);
    void drawsphere(int,float);
    static void reshape(GLsizei,GLsizei);


};
