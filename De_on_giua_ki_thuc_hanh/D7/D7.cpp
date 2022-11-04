#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<math.h>

static GLfloat goc1 = 0, goc2=0;

void loop1(void){
	goc1 = (goc1>360)?(goc1-360):(goc1 - 0.2);
	glutPostRedisplay();
}

void loop2(void){
	goc2 = (goc2>360)?(goc2-360):(goc2 - 0.2);
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
	if(key == 'r'){
		glutIdleFunc(loop1);
	}
}

void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		glutIdleFunc(loop2);
	}
}

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glLoadIdentity ();
	glTranslatef(sqrt(3)*3,0,0);
	glRotatef(goc2,0,0,1);
	glTranslatef(-sqrt(3)*3,0,0);
	
	glPushMatrix();
		glColor3f (0.0, 1.0, 0.0);
		
		glRotatef(30,0,0,1);
		
		GLfloat ag, r; GLfloat step = 3.14/3.0;
		glBegin(GL_POLYGON);
			for(int i=0; i<6; ++i){
				r = 6;
				ag = i*step;
				glVertex3f(r*cos(ag),r*sin(ag),0.0);
			}
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glColor3f (1.0, 1.0, 0.0);
		
		glRotatef(goc1,0,0,1);
		
		glScalef(1,0.6,1);
		glRotatef(45,0,0,1);
		
		glBegin(GL_QUADS);
			glVertex3f(3.6,3.6,0.0);
			glVertex3f(3.6,-3.6,0.0);
			glVertex3f(-3.6,-3.6,0.0);
			glVertex3f(-3.6,3.6,0.0);
		glEnd();
	glPopMatrix();
	
	glFlush ();
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho(-17.0,17.0,-17.0,17.0,-1,1);
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
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
