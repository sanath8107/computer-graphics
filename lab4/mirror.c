#include <stdio.h>
#include <GL/glut.h>
int a;
int px[100],py[100];

int n=0;

int steps;
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void polygon(){
  glClear(GL_COLOR_BUFFER_BIT);
  int i=0;
    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    for(i=0;i<n;i++){
      glVertex2i(px[i],py[i]);
    }
    glEnd(); 

    if(a==1){
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    for(i=0;i<n;i++){
      glVertex2i(px[i],-1*py[i]);
    }
    glEnd();
  }

  if(a==2){
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    for(i=0;i<n;i++){
      glVertex2i(-1*px[i],py[i]);
    }
    glEnd();
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
    printf("Enter number of sides\n");
        scanf("%d",&n);
        int i=0;
        printf("enter all the points\n");
        for(i=0;i<n;i++){
          scanf("%d%d",&px[i],&py[i]);
        }
    printf("what do you want me to reflect wrt 1.x 2.y\n");
    scanf("%d",&a);
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("polygon");
    glutDisplayFunc(polygon);
    glutReshapeFunc(reshape);
    initGL();
    glutMainLoop();
    return 0;
}