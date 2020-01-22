#include <stdio.h>
#include <GL/glut.h>
int xc=0, yc = 0;
int r;int i =1;
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void update(int value){
  if(xc>0&&xc<2*r&&i==1){
    xc=xc+8;
  }
  else if(xc<=0){
    i=1;
    xc = xc+8;
  }
  else if(xc>=2*r){
    xc = xc -8;
    i=-1;
  }
  else if(xc>=0&&xc<=2*r&&i==-1){
    xc=xc-8;
  }
  glutPostRedisplay();
  glutTimerFunc(30,update,0);
}
void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  int x =0,y=r;
  int d;
  d = 3-2*r;
  while(y>=x){
    x++;
    if(d>=0){
      y--;  
      d = d + 4 * (x - y) + 10; 
    } 
    else
      d = d + 4 * x + 6;

  glColor3f(0.0,1,0);
  glPointSize(2);
  glBegin(GL_POINTS);
  glVertex2i(xc+x,yc+y);
  glVertex2i(xc-x,yc+y);
  glVertex2i(xc+x,yc-y);
  glVertex2i(xc-x,yc-y);
  glVertex2i(xc+y,yc+x);
  glVertex2i(xc-y,yc+x);
  glVertex2i(xc+y,yc-x);
  glVertex2i(xc-y,yc-x);
  glEnd();
  glFlush();
  }

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
    printf("Enter radius\n");
    scanf("%d",&r);
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("circle");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(30,update,0);
    initGL();
    glutMainLoop();
    return 0;
}