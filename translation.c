#include <stdio.h> 
#include <GL/glut.h> 
float tx,ty,tz;
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClearDepth(1.0f);   
   glEnable(GL_DEPTH_TEST); 
   glDepthFunc(GL_LEQUAL); 
   glShadeModel(GL_SMOOTH); 
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
 
void cube() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW); 
 
   glLoadIdentity();              
   glTranslatef(1.5f, 0.0f, -7.0f); 
 
   glBegin(GL_QUADS);            
      glColor3f(0.0f, 1.0f, 0.0f);   
      glVertex3i( 1.5, 1.5, -1.5);
      glVertex3i(-1.5, 1.5, -1.5);
      glVertex3i(-1.5, 1.5,  1.5);
      glVertex3i( 1.5, 1.5,  1.5);
 
      glColor3f(1.0f, 0.5f, 0.0f);   
      glVertex3i( 1.5, -1.5,  1.5);
      glVertex3i(-1.5, -1.5,  1.5);
      glVertex3i(-1.5, -1.5, -1.5);
      glVertex3i( 1.5, -1.5, -1.5);
 
      glColor3f(1.0f, 0.0f, 0.0f);   
      glVertex3i( 1.5,  1.5, 1.5);
      glVertex3i(-1.5,  1.5, 1.5);
      glVertex3i(-1.5, -1.5, 1.5);
      glVertex3i( 1.5, -1.5, 1.5);

      glColor3f(1.0f, 1.5, 0.0f);
      glVertex3i( 1.5, -1.5, -1.5);
      glVertex3i(-1.5, -1.5, -1.5);
      glVertex3i(-1.5,  1.5, -1.5);
      glVertex3i( 1.5,  1.5, -1.5);

      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3i(-1.5,  1.5,  1.5);
      glVertex3i(-1.5,  1.5, -1.5);
      glVertex3i(-1.5, -1.5, -1.5);
      glVertex3i(-1.5, -1.5,  1.5);
 
    
      glColor3f(1.5, 0.0f, 1.0f);    
      glVertex3i(1.5,  1.5, -1.5);
      glVertex3i(1.5,  1.5,  1.5);
      glVertex3i(1.5, -1.5,  1.5);
      glVertex3i(1.5, -1.5, -1.5);



      glColor3f(0.0f, 1.0f, 0.0f);   
      glVertex3i( 1.5+tx, 1.5+ty, -1.5+tz);
      glVertex3i(-1.5+tx, 1.5+ty, -1.5+tz);
      glVertex3i(-1.5+tx, 1.5+ty,  1.5+tz);
      glVertex3i( 1.5+tx, 1.5+ty,  1.5+tz);
 
      glColor3f(1.0f, 0.5f, 0.0f);   
      glVertex3i( 1.5+tx, -1.5+ty,  1.5+tz);
      glVertex3i(-1.5+tx, -1.5+ty,  1.5+tz);
      glVertex3i(-1.5+tx, -1.5+ty, -1.5+tz);
      glVertex3i( 1.5+tx, -1.5+ty, -1.5+tz);
 
      glColor3f(1.0f, 0.0f, 0.0f);   
      glVertex3i( 1.5+tx,  1.5+ty, 1.5+tz);
      glVertex3i(-1.5+tx,  1.5+ty, 1.5+tz);
      glVertex3i(-1.5+tx, -1.5+ty, 1.5+tz);
      glVertex3i( 1.5+tx, -1.5+ty, 1.5+tz);

      glColor3f(1.0f, 1.5, 0.0f);
      glVertex3i( 1.5+tx, -1.5+ty, -1.5+tz);
      glVertex3i(-1.5+tx, -1.5+ty, -1.5+tz);
      glVertex3i(-1.5+tx,  1.5+ty, -1.5+tz);
      glVertex3i( 1.5+tx,  1.5+ty, -1.5+tz);

      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3i(-1.5+tx,  1.5+ty,  1.5+tz);
      glVertex3i(-1.5+tx,  1.5+ty, -1.5+tz);
      glVertex3i(-1.5+tx, -1.5+ty, -1.5+tz);
      glVertex3i(-1.5+tx, -1.5+ty,  1.5+tz);
 
    
      glColor3f(1.5, 0.0f, 1.0f);    
      glVertex3i( 1.5+tx,  1.5+ty, -1.5+tz);
      glVertex3i( 1.5+tx,  1.5+ty,  1.5+tz);
      glVertex3i( 1.5+tx, -1.5+ty,  1.5+tz);
      glVertex3i( 1.5+tx, -1.5+ty, -1.5+tz);
   glEnd();

   glutSwapBuffers();
}

void pyramid(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW); 
  glLoadIdentity(); 
  glTranslatef(1.5f, 0.0f, -7.0f);               
   glBegin(GL_TRIANGLES); 

      glColor3f(1.0f, 0.0f, 0.0f); 
      glVertex3i( 0, 1.5, 0);
      glColor3f(0.0f, 1.0f, 0.0f); 
      glVertex3i(-1.5, -1.5, 1.5);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3i(1.5, -1.5, 1.5);
 

      glColor3f(1.0f, 0.0f, 0.0f); 
      glVertex3i(0, 1.5, 0);
      glColor3f(0.0f, 0.0f, 1.5); 
      glVertex3i(1.5, -1.5, 1.5);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3i(1.5, -1.5, -1.5);
 

      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3i(0, 1.5, 0);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3i(1.5, -1.5, -1.5);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3i(-1.5, -1.5, -1.5);
 
      glColor3f(1.0f,0.0f,0.0f);
      glVertex3i( 0, 1.5, 0);
      glColor3f(0.0f,0.0f,1.0f);
      glVertex3i(-1.5,-1.5,-1.5);
      glColor3f(0.0f,1.0f,0.0f); 
      glVertex3i(-1.5,-1.5, 1.5);



      glColor3f(1.0f, 0.0f, 0.0f); 
      glVertex3i( 0+tx, 1.5+ty, 0+tz);
      glColor3f(0.0f, 1.0f, 0.0f); 
      glVertex3i(-1.5+tx, -1.5+ty, 1.5+tz);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3i(1.5+tx, -1.5+ty, 1.5+tz);
 

      glColor3f(1.0f, 0.0f, 0.0f); 
      glVertex3i(0+tx, 1.5+ty, 0+tz);
      glColor3f(0.0f, 0.0f, 1.5); 
      glVertex3i(1.5+tx, -1.5+ty, 1.5+tz);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3i(1.5+tx, -1.5+ty, -1.5+tz);
 

      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3i(0+tx, 1.5+ty, 0+tz);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3i(1.5+tx, -1.5+ty, -1.5+tz);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3i(-1.5+tx, -1.5+ty, -1.5+tz);
 
      glColor3f(1.0f,0.0f,0.0f);
      glVertex3i( 0+tx, 1.5+ty, 0+tz);
      glColor3f(0.0f,0.0f,1.0f);
      glVertex3i(-1.5+tx,-1.5+ty,-1.5+tz);
      glColor3f(0.0f,1.0f,0.0f); 
      glVertex3i(-1.5+tx,-1.5+ty, 1.5+tz);
   glEnd();

      glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) { 
   if (height == 0) height = 1;                
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);  
   glLoadIdentity(); 
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
 
int main(int argc, char** argv) {
  glutInit(&argc, argv); 
  printf("enter the translation factors\n");
  scanf("%f%f%f",&tx,&ty,&tz);
  int a ;
  printf("what do you want me to tarnslate 1.cube 2.pyramid\n");
  scanf("%d",&a);
  switch(a){
    case 1:{
        glutInitDisplayMode(GLUT_DOUBLE);
        glutInitWindowSize(1366, 768);
        glutInitWindowPosition(50, 50);
        glutCreateWindow("cube");
        glutDisplayFunc(cube);
        glutReshapeFunc(reshape);
        break;
    }
    case 2:{
        glutInitDisplayMode(GLUT_DOUBLE);
        glutInitWindowSize(1366, 768);
        glutInitWindowPosition(50, 50);
        glutCreateWindow("pyramid");
        glutDisplayFunc(pyramid);
        glutReshapeFunc(reshape);
        break;
    }
  }      
   initGL();                       
   glutMainLoop();                 
}