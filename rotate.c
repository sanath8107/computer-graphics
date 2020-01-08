#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
float angle=0.0;

void update(int value){
	angle +=2.0f;
	glutPostRedisplay();
	glutTimerFunc(25,update,0);
}
void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(0.3f,0.0f,0.0f);
	glRotatef(angle,0.0,0.1,0.0);
	glTranslatef(-0.3f,0.0f,0.0f);

	glBegin(GL_TRIANGLES);
    glVertex2f(0.6f,0.0f);
    glVertex2f(0.3,0.5f);
    glVertex2f(0.0,0.0f);
    glEnd();
    glPopMatrix(); 

    glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(0.0f,-0.5f,0.0f);
	glRotatef(angle,1.0,0.1,0.0);
	glTranslatef(0.0f,0.5f,0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2f,-0.5f);
    glVertex2f(-0.2f,-0.7f);
    glVertex2f(0.0f,-0.8f);
    glVertex2f(0.2f,-0.7f);
    glVertex2f(0.2f,-0.5f);
    glEnd();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(angle,1.0,0.1,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5f,0.0f);
    glVertex2f(-0.1f,0.0f);
    glVertex2f(-0.1f,0.4f);
    glVertex2f(-0.5f,0.4f);
    glEnd();
    glPopMatrix();
  
	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(1366, 768); 
	glutInitWindowPosition(0, 0);  
	glutCreateWindow("Rotating figures"); 
	glClearColor(0.0, 0.0, 0.0, 1.0);  
	glColor3f(0.5,0.5,0.0);
	glutDisplayFunc(display); 
	glutTimerFunc(25,update,0);
	glutMainLoop(); 
} 
