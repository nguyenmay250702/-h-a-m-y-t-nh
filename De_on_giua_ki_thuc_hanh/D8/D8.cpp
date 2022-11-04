#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<math.h>

static GLfloat goc1 = 0, Sx = 1, Sy=1, Sz = 1;

void loop1(void){
	if(Sx >0.525){
		goc1 = (goc1>360)?(goc1-360):(goc1 - 0.2);
		Sx = Sx-0.0001;
		Sy = Sy-0.0001;
		Sz = Sz-0.0001;
	}
	
	glutPostRedisplay();
}
void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		glutIdleFunc(loop1);
	}
}

void init(void)
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT2);
	glEnable(GL_DEPTH_TEST);
}

void display(void)
{
	//gluLookAt (-1.2, 0.5, 1.2, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glLoadIdentity();
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLfloat light_ambient1[] = {1.0, 1.0, 0.0, 1.0};
	GLfloat light_diffuse1[] = {1.0, 1.0, 0.0, 1.0};
	GLfloat light_ambient2[] = {1.0, 0.0, 0.0, 1.0};
	GLfloat light_diffuse2[] = {1.0, 1.0, 0.0, 1.0};
	glPushMatrix();
		glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient2);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse2);
		
		glRotatef(30,0,0,1);
		
		GLfloat ag, r; GLfloat step = 3.14/3.0;
		glBegin(GL_POLYGON);
			for(int i=0; i<6; ++i){
				r = 1;
				ag = i*step;
				glVertex3f(r*cos(ag),r*sin(ag),0.0);
			}
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glScalef(Sx,Sy,Sz);
		glTranslatef(0,0,1);
		glRotatef(goc1,0,1,0);
		glTranslatef(0,0,-1);
		
		glTranslatef(0,0,1);
		glRotatef(16,0,1,0);
		glRotatef(16,1,0,0);
		glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient1);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse1);
		glutSolidCube(1.05);
	glPopMatrix();
	glFlush ();
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	
	if (w <= h)
		glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
	else
	glOrtho (-1.5*(GLfloat)w/(GLfloat)h,1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
	
	
	//glOrtho(0, 3.0, 0.0, 3.0, -1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
