#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>

static GLfloat dx = 0;
void loop(void){
	if(dx<22){
		dx = dx + 0.01;	
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
	if(key == 'r'){
		glutIdleFunc(loop);	
	}
}

//thiet lap 
void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
//	glShadeModel (GL_SMOOTH);
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	//glLoadIdentity();
		glOrtho (-15.0, 15.0, -15.0, 15.0, -10.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
}

//ve sao
void draw_star(){
	GLfloat ag, r; 
	GLfloat step = 3.14/5.0;
	glBegin(GL_LINE_LOOP);
		for(int i=0; i<10; ++i){
			r = (i%2 == 0? 1:3);
			ag = i*step;
			glVertex3f(r*cos(ag),r*sin(ag),0.0);
		}
	glEnd();
}

//ve
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	glTranslatef(-10,0,0);
	glPushMatrix();
		glColor3f(0.0,0.0,1.0);
		glTranslatef(dx, 0, 0);
		glTranslatef(0, 4, 0);
		draw_star();
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(1.0,1.0,1.0);
		glTranslatef(0, -3, 0);
		draw_star();
	glPopMatrix();
	
	glutSwapBuffers();
	glFlush();
}

int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("De 2");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
