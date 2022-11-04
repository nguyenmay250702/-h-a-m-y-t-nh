#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>

static GLfloat goc = 0;

//su kien chuot và ban phim
void loop(void){
	goc = (goc > 360)?(goc -360):(goc-0.2);
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		glutIdleFunc(NULL);
	}
}

void keyboard(unsigned char key, int x, int y){
	if(key == 'r'){
		glutIdleFunc(loop);	
	}
}

//thiet lap 
void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
}

//ve hinh
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(4,0);
		glVertex2f(-4,0);
		glVertex2f(0,4*sqrt(3));
	glEnd();
	
	glPushMatrix();
		glTranslatef(-2,2*sqrt(3),0.0);
		glRotatef(goc, 0.0, 0.0, 1.0);
		glTranslatef(2,-2*sqrt(3),0.0);
		
		glBegin(GL_TRIANGLES);
			glColor3f (0.0, 1.0, 0.0);
			glVertex2f(0,0);
			glVertex2f(-2,2*sqrt(3));
			glVertex2f(2,2*sqrt(3));
		glEnd();
	glPopMatrix();
	//glutSwapBuffers();
	glFlush();
}

int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("De 1");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

