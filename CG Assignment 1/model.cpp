
#include "GL/freeglut.h"
#include "GL/gl.h"

#include "model.h"
#include <math.h>

void model::normalize(GLfloat *a) {
    GLfloat d=sqrt(a[0]*a[0]+a[1]*a[1]+a[2]*a[2]);
    a[0]/=d; a[1]/=d; a[2]/=d;
}
