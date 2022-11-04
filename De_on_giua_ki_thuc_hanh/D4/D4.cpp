#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static GLfloat goc1 = 0, goc2 = 0;

void loop1(void){
	goc1 = (goc1 >360)?(goc1-360):(goc1-0.2);
	glutPostRedisplay();
}

void loop2(void){
	goc2 = (goc2 >360)?(goc2-360):(goc2-0.2);
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
	if(key == 'r'){
		glutIdleFunc(loop1);
	}
	else if(key ='a'){
		glutIdleFunc(loop2);
	}
}

void init(void)
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat light_ambient[] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position);
	
	glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT2);
	glEnable(GL_DEPTH_TEST);
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//gluLookAt (-0.5, 0.5, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glScalef(0.2,1,0.2);

	glPushMatrix();
		glTranslatef(0,0.9,0);
		glutSolidCube(0.8);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0.4,0);
		glRotatef(0.3*goc1, 0,0,1);
		glTranslatef(0,-0.4,0);
	
		glTranslatef(0,0.8,0);
		glRotatef(0.3*goc2, 0,0,1);
		glTranslatef(0,-0.8,0);
		
		glutSolidCube(0.8);
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
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
