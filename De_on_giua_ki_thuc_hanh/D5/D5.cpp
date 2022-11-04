#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<math.h>

static GLfloat goc = 0;

//su kien chuot và ban phim
void loop(void){
	goc = (goc > 360)?(goc -360):(goc-0.2);
	glutPostRedisplay();
}

void keyboard(unsigned char key , int x, int y){
	if(key == 'r'){
		glutIdleFunc(loop);
	}
}

void init(void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	//glShadeModel (GL_FLAT);
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glLoadIdentity ();
	
	glBegin(GL_QUADS);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(4,-4);
		glVertex2f(-4,-4);
		glVertex2f(-4,4);
		glVertex2f(4,4);
	glEnd();
	
	glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(3,-3);
		glVertex2f(-3,-3);
		glVertex2f(-3,3);
		glVertex2f(3,3);
	glEnd();
	
	glPushMatrix();
		glTranslatef(-3,0,0);
		glRotatef(goc,0,0,1);
		glTranslatef(3,0,0);
		
		glRotatef(45,0,0,1);
		GLfloat ag, r;
		GLfloat step = 3.14/4.0;
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		for(int i=0; i<8; ++i){
			r = (i%2 == 0? 1:3);
			ag = i*step;
			glVertex3f(r*cos(ag),r*sin(ag),0.0);
		}
		glEnd();
	glPopMatrix();
	glutSwapBuffers();
	glFlush ();
}
void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho(-9.0, 9.0, -9.0, 9.0, -1.0, 1.0);
	glMatrixMode (GL_MODELVIEW);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
