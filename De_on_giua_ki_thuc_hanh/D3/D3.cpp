#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static GLfloat Sx = 1, Sy = 1,Sz = 1;

void loop(void){
	if(Sx <= 2){
		Sx = Sx + 0.0001;
		Sy = Sy + 0.0001;
		Sz = Sz + 0.0001;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		glutIdleFunc(loop);
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
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display(void)
{
	glLoadIdentity();
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLfloat light_ambient1[] = {1.0, 1.0, 0.0, 1.0};
	GLfloat light_diffuse1[] = {1.0, 1.0, 0.0, 1.0};
	GLfloat light_ambient2[] = {0.0, 1.0, 0.0, 1.0};
	GLfloat light_diffuse2[] = {0.0, 1.0, 0.0, 1.0};

	glTranslatef(0,0.5,0);
	glPushMatrix();
		glScalef(Sx, Sy, Sz);
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient1);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse1);
		glutSolidSphere (0.2, 20, 16);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,-1,0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient2);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse2);
		glutSolidSphere (0.4, 20, 16);
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
	glOrtho (-1.5*(GLfloat)w/(GLfloat)h, 1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
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














