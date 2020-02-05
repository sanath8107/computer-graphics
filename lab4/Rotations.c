#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
float ang = 0;
float a = 100, b= 200, c = 700, d =400;
float cx =0,cy=0;
int r=0;
int xc ,yc;

float px[100],py[100];
float fx[100],fy[100];
int n=0;

int steps;
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void line() {
  int a1,b1,c1,d1;
  int x,y;
  x =a;
  y=b;

    glClear(GL_COLOR_BUFFER_BIT);

     glBegin(GL_LINES);
    glColor3f(0,0,1);
    glVertex2i(0,800);
    glVertex2i(0,-800);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,1);
    glVertex2i(800,0);
    glVertex2i(-800,0);
    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0,0,1);
    glVertex2i(0,0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0,1,0);
    glVertex2i(a,b);
    glVertex2i(c,d);
    glEnd(); 
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    a1 = cx + (int)((float)(a - cx) * cos(ang)) - ((float)(b - cy) * sin(ang)); 
    b1 = cy + (int)((float)(a - cx) * sin(ang)) + ((float)(b - cy) * cos(ang)); 
    c1 = cx + (int)((float)(c - cx) * cos(ang)) - ((float)(d - cy) * sin(ang)); 
    d1 = cy + (int)((float)(c - cx) * sin(ang)) + ((float)(d - cy) * cos(ang)); 
    glVertex2i(a1,b1);
    glVertex2i(c1,d1);
    glEnd(); 
    glFlush();
}

void polygon(){

  glClear(GL_COLOR_BUFFER_BIT);
  int i=0;
  glBegin(GL_LINES);
    glColor3f(0,0,1);
    glVertex2i(0,800);
    glVertex2i(0,-800);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,1);
    glVertex2i(800,0);
    glVertex2i(-800,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    for(i=0;i<n;i++){
      glVertex2i(px[i],py[i]);
    }
    glEnd(); 

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    for(i=0;i<n;i++){
      fx[i] = cx + (int)((float)(px[i] - cx) * cos(ang)) - ((float)(py[i] - cy) * sin(ang)); 
      fy[i] = cy + (int)((float)(px[i] - cx) * sin(ang)) + ((float)(py[i] - cy) * cos(ang)); 
      glVertex2i(fx[i],fy[i]);
    }
    glEnd(); 
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
  int a1;
    glutInit(&argc, argv);
    printf("enter angle of rotation\n");
    scanf("%f",&ang);
    printf("what do you want me to rotate 1.line 2. polygon\n");
    scanf("%d",&a1);
    switch(a1){
        case 1:{
        printf("Enter x1,y1,x2,y2\n");
        scanf("%f%f%f%f",&a,&b,&c,&d);
        glutInitWindowSize(1366, 768);
        glutInitWindowPosition(50, 50);
        glutCreateWindow("Line");
        glutDisplayFunc(line);
        glutReshapeFunc(reshape);
        break;
      }

      case 2:{
        printf("Enter number of sides\n");
        scanf("%d",&n);
        int i=0;
        printf("enter all the points\n");
        for(i=0;i<n;i++){
          scanf("%f%f",&px[i],&py[i]);
        }
        glutInitWindowSize(1366, 768);
        glutInitWindowPosition(50, 50);
        glutCreateWindow("polygons");
        glutDisplayFunc(polygon);
        glutReshapeFunc(reshape);
        break;
      }
  }
    initGL();
    glutMainLoop();
    return 0;
}