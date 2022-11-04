#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
static int day= 0;

void init(void) {
	glClearColor (1.0, 1.0, 1.0, 1.0);
	//glShadeModel (GL_FLAT);
	
	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_shininess[] = {50.0};
	GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
	
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	GLfloat light_ambient1[] = {5.0, 0.0, 0.0, 1.0};
	GLfloat light_diffuse1[] = {1.25, 0.0, 0.0, 1.0};
	
	GLfloat light_ambient2[] = {0.0, 5.0, 0.0, 1.0};
	GLfloat light_diffuse2[] = {0.0, 1.25, 0.0, 1.0};
	
	glPushMatrix();
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient1);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse1);
		glRotatef(45,0,0,1);
		glScalef(15,0.6,5);
		glutWireCube(1.0);
	glPopMatrix();
	glPushMatrix();
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient2);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse2);
		glTranslatef(5,7,0);
		glTranslatef( (GLfloat) day/40 , (GLfloat) day/40 , 0);
		glRotatef (((GLfloat) day)*(-1), 0, 0, 1);
		glutWireSphere(1, 20, 15);
	glPopMatrix();
	glutSwapBuffers();
}

void reshape (int w, int h){
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (0, 0, 20, 0.0, 0.0, 0.0, 0, 1, 0);
}

void keyboard (unsigned char key, int x, int y){
	switch (key) {
		case '.':
		day = (day + 1)/1.1;
		glutPostRedisplay();
		break;
		case ',':
		day = (day - 1)*1.1;
		glutPostRedisplay();
		break;
		default:
		break;
	}
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (800, 800);
	glutInitWindowPosition (0, 0);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
