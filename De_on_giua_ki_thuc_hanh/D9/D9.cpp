#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static GLfloat dv1 = 0, dv2 = 0, dx1 = 0, dx2 = 0, goc = 0;
void loop(void){
	if(dv1 <= 1.2){
		dv1 = dv1 + 0.001;
		goc = (goc >360)?(goc - 360):(goc + 0.3);
	}
	else if(dv2>=-1.2){
		dv2 = dv2 - 0.001;
		goc = (goc >360)?(goc - 360):(goc + 0.3);
	}
	
	if(dx1 >=-1.2){
		dx1 = dx1 - 0.001;
	}
	else if(dx2<=1.2){
		dx2 = dx2 + 0.001;	
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
	glLoadIdentity();
	gluLookAt (-0.5, 0.5, 3.0, 0.0, 0.0, 0.0, 0.0, 3.0, 0.0);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLfloat light_ambient1[] = {1.0, 1.0, 0.0, 1.0};
	GLfloat light_diffuse1[] = {1.0, 1.0, 0.0, 1.0};
	GLfloat light_ambient2[] = {0.0, 1.0, 0.0, 1.0};
	GLfloat light_diffuse2[] = {0.0, 1.0, 0.0, 1.0};
	
	glPushMatrix();
		glTranslatef(dv2,0,0);
		glTranslatef(dv1,0,0);
		
		glTranslatef(0,1,0);
		glRotatef(goc, 0,0,1);
		glTranslatef(0,-1,0);
		
		glTranslatef(0,1,0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient1);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse1);
		glutSolidCube(0.5);
	glPopMatrix();
	
	
	glPushMatrix();
		glTranslatef(dx2,0,0);
		glTranslatef(dx1,0,0);
		
		glRotatef(goc, 0,0,1);
		
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient2);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse2);
		glutSolidCube(0.5);
	glPopMatrix();
	glFlush ();
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-4,4,-4,4,1.5,20);
	
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
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
