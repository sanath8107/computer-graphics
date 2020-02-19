#include <stdio.h>
#include <GL/glut.h>
int tx=0,ty=0;
float x0 = 100, y0= 200, x2 = 700, y2 =400;

int r=0;
int xc ,yc;

int px[100],py[100];

int n=0;

int steps;
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void line() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(0,1,0);
    glVertex2i(x0,y0);
    glVertex2i(x2,y2);
    glEnd(); 

   glBegin(GL_QUADS);
      glColor3f(0.0, 1.0, 0.0);     // Green
      glVertex3f( 100, 100, -100);
      glVertex3f(-100, 100, -100);
      glVertex3f(-100, 100,  100);
      glVertex3f( 100, 100,  100);
 
      // Bottom face (y = -100)
      glColor3f(100, 0.5f, 0.0f);     // Orange
      glVertex3f( 100, -100,  100);
      glVertex3f(-100, -100,  100);
      glVertex3f(-100, -100, -100);
      glVertex3f( 100, -100, -100);
 
      // Front face  (z = 100)
      glColor3f(100, 0.0f, 0.0f);     // Red
      glVertex3f( 100,  100, 100);
      glVertex3f(-100,  100, 100);
      glVertex3f(-100, -100, 100);
      glVertex3f( 100, -100, 100);
 
      // Back face (z = -100)
      glColor3f(100, 100, 0.0f);     // Yellow
      glVertex3f( 100, -100, -100);
      glVertex3f(-100, -100, -100);
      glVertex3f(-100,  100, -100);
      glVertex3f( 100,  100, -100);
 
      // Left face (x = -100)
      glColor3f(0.0f, 0.0f, 100);     // Blue
      glVertex3f(-100,  100,  100);
      glVertex3f(-100,  100, -100);
      glVertex3f(-100, -100, -100);
      glVertex3f(-100, -100,  100);
 
      // Right face (x = 100)
      glColor3f(100, 0.0f, 100);     // Magenta
      glVertex3f(100,  100, -100);
      glVertex3f(100,  100,  100);
      glVertex3f(100, -100,  100);
      glVertex3f(100, -100, -100);
   glEnd();  // End of drawing color-cube
 
   // glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
   //    // Front
   //    glColor3f(100, 0.0f, 0.0f);     // Red
   //    glVertex3f( 0.0f, 100, 0.0f);
   //    glColor3f(0.0f, 100, 0.0f);     // Green
   //    glVertex3f(-100, -100, 100);
   //    glColor3f(0.0f, 0.0f, 100);     // Blue
   //    glVertex3f(100, -100, 100);
 
   //    // Right
   //    glColor3f(100, 0.0f, 0.0f);     // Red
   //    glVertex3f(0.0f, 100, 0.0f);
   //    glColor3f(0.0f, 0.0f, 100);     // Blue
   //    glVertex3f(100, -100, 100);
   //    glColor3f(0.0f, 100, 0.0f);     // Green
   //    glVertex3f(100, -100, -100);
 
   //    // Back
   //    glColor3f(100, 0.0f, 0.0f);     // Red
   //    glVertex3f(0.0f, 100, 0.0f);
   //    glColor3f(0.0f, 100, 0.0f);     // Green
   //    glVertex3f(100, -100, -100);
   //    glColor3f(0.0f, 0.0f, 100);     // Blue
   //    glVertex3f(-100, -100, -100);
 
   //    // Left
   //    glColor3f(100,0.0f,0.0f);       // Red
   //    glVertex3f( 0.0f, 100, 0.0f);
   //    glColor3f(0.0f,0.0f,100);       // Blue
   //    glVertex3f(-100,-100,-100);
   //    glColor3f(0.0f,100,0.0f);       // Green
   //    glVertex3f(-100,-100, 100);
   // glEnd();   // Done drawing the pyramid
   glFlush();
 
   // glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

void Circle(){
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

  glColor3f(0,1,0);
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
  }

  xc = xc +tx ;
  yc = yc +ty ;
  x =0,y=r;
  d = 3-2*r;
  while(y>=x){
    x++;
    if(d>=0){
      y--;  
      d = d + 4 * (x - y) + 10; 
    } 
    else
      d = d + 4 * x + 6;

  glColor3f(1,0,0);
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
  }

  glFlush();
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

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    for(i=0;i<n;i++){
      glVertex2i(px[i]+tx,py[i]+ty);
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
  int a;
    glutInit(&argc, argv);
    printf("enter translation factors\n");
    scanf("%d%d",&tx,&ty);
    printf("what do you want me to translate 1.line 2. polygon 3.Circle\n");
    scanf("%d",&a);
    switch(a){
        case 1:{
        printf("Enter x1,y1,x2,y2\n");
        scanf("%f%f%f%f",&x0,&y0,&x2,&y2);
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
          scanf("%d%d",&px[i],&py[i]);
        }
        glutInitWindowSize(1366, 768);
        glutInitWindowPosition(50, 50);
        glutCreateWindow("polygons");
        glutDisplayFunc(polygon);
        glutReshapeFunc(reshape);
        break;
      }

       case 3:{
        printf("Enter centre and radius\n");
        scanf("%d%d%d",&xc,&yc,&r);
        glutInitWindowSize(1366, 768);
        glutInitWindowPosition(50, 50);
        glutCreateWindow("Circle");
        glutDisplayFunc(Circle);
        glutReshapeFunc(reshape);
        break;
      }
  }
    initGL();
    glutMainLoop();
    return 0;
}