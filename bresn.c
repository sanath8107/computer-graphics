#include <stdio.h>
#include <GL/glut.h>

float x0 , y0 , x2 , y2;
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    int dx ,dy;float X, Y, p;
    dx = x2 - x0;
    dy = y2 - y0;
    X = x0;
    Y = y0;
    p = 2*dy -dx;
    while(X<x2)
    {
      glBegin(GL_POINTS);
        glColor3f(0,1,0);
        glPointSize(4);
        glVertex2i(X,Y);
        glEnd();
      if(p>=0)
      {
        Y=Y+1;
        p=p+2*dy-2*dx;
      }
      else
      {
        p=p+2*dy;
      }
    X=X+1;
  }
    glFlush();
}

void reshape(GLsizei width, GLsizei height) {  
   if (height == 0) height = 1;
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (width >= height) {
      gluOrtho2D(-1000.0 * aspect, 1000.0 * aspect, -1000.0, 1000.0);
   } else {
     gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    printf("Enter x1,y1,x2,y2\n");
    scanf("%f%f%f%f",&x0,&y0,&x2,&y2);
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Different shapes");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initGL();
    glutMainLoop();
    return 0;
}