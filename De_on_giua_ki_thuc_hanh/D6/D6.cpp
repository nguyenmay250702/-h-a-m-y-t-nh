#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
static GLfloat dx = 0, goc = 0;

void loop(void){
	if(dx<=2){
		dx = dx + 0.001;
		goc = (goc > 360)?(goc-360):(goc+0.2);
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key , int x, int y){
	if(key == 'r'){
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
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
		glTranslatef(dx,0,0);
		
		glTranslatef(-1,0,0);
		glRotatef(goc,0,0,1);
		glTranslatef(1,0,0);
	
		glTranslatef(-1,0,0);
		GLfloat light_ambient[] = {0.0, 1.0, 0.0, 1.0};
		GLfloat light_diffuse[] = {0.0, 1.0, 0.0, 1.0};
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
		glutSolidSphere (0.3, 60, 60);
	glPopMatrix();
	
	glPushMatrix();
		glRotatef(10, 0,1,0);
		glRotatef(10, 1,0,0);
		//glColor3f(0.0,0.0,1.0);
		glTranslatef(1,0,0);
		glutWireCube (0.6);
	glPopMatrix();
	
	glFlush ();
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
	glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
	1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
	else
	glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
	1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
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
