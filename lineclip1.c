#include<stdio.h>
#include<GL/glut.h>

double xmin=50,ymin=50,xmax=100,ymax=100;
double x1=75, y1=110, x2=110, y2=75, x3=75, y3=40;

const int RIGHT= 8; 
const int LEFT =2;  
const int TOP=4;    
const int BOTTOM=1; 

int code(double x,double y); 

void cs(double x0,double y0,double x1,double y1)
{
    int outcode0,outcode1,outcodeOut;
    int accept =0,done =0;
    outcode0= code(x0,y0);
    outcode1= code(x1,y1);

do
{
    if(!(outcode0|outcode1)) 
    { accept=1;
      done=1;
    }
    else
        if(outcode0 & outcode1)  
             done=1;
        else
        {
            double x,y;
            outcodeOut= outcode0?outcode0:outcode1;

if(outcodeOut & TOP) 
   {
        x= x0+(x1-x0)*(ymax-y0)/(y1-y0);
                 y=ymax;
             }
           else
        if(outcodeOut & BOTTOM) 
             {
        x= x0+(x1-x0)*(ymin-y0)/(y1-y0);
                 y=ymin;
             }
             else
        if(outcodeOut & RIGHT) 
             {
        y= y0+(y1-y0)*(xmax-x0)/(x1-x0);
                 x=xmax;
         }
             else                   
             {
                 y= y0+(y1-y0)*(xmin-x0)/(x1-x0);
                 x=xmin;
             }
      if(outcodeOut == outcode0) 
             { x0=x;                           
               y0=y;
               outcode0 = code(x0,y0);    
             }
        else                           
             {                           
               x1=x;
               y1=y;
               outcode1 = code(x1,y1);
             }
        }
}while(!done);
if(accept) 
    {
        glColor3f(0.0,1.0,0.0);
        glBegin(GL_LINES);
        glVertex2d(x0,y0);
        glVertex2d(x1,y1);
        glEnd();
    }
}

int code(double x,double y)
{
    int code =0;
     if(y>ymax)   
         code |=TOP;
    if(y<ymin)   
         code |=BOTTOM;
    if(x>xmax)        
         code |=RIGHT;
    if(x<xmin)  
         code |=LEFT;
         return code;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0); 
     glBegin(GL_LINE_LOOP);
          glVertex2d(x1,y1);
          glVertex2d(x2,y2);
          glVertex2d(x3,y3);
          glEnd();
   glColor3f(0.0,0.0,1.0); 
      glBegin(GL_LINE_LOOP);
         glVertex2f(xmin,ymin);
         glVertex2f(xmax,ymin);
         glVertex2f(xmax,ymax);
         glVertex2f(xmin,ymax);
         glEnd();
       cs(x1,y1,x2,y2);
       cs(x2,y2,x3,y3);
       cs(x3,y3,x1,y1);
       glFlush();
}

void myinit()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,499.0,0.0,499.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Line Clipping algorithm");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}