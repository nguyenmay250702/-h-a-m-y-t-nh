#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>

int goc_1 = 0;
int goc_2 = 0;

void keyboard(unsigned char key, int x, int y){
	if(key == 'a'){
		goc_2 = (goc_2 + 6)%360;
		glutPostRedisplay();
	}
}

void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		goc_1 = (goc_1 + 6)%360;
		glutPostRedisplay();
	}
}

void init(void){
	glClearColor(0.0,0.0,0.0,0.0);		//thiet lap mau nen
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);	//xoa mau co san trong vung dem
	glLoadIdentity();	//xoa va thiet lap ma tran hien thoi la don vi
	
	gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);		//dinh nghia diem nhin cua nguoi quan sat

	glTranslatef(-3.0,0,0);
	
	glPushMatrix();
		glColor3f(1.0,1.0,1.0);		//thiet lap mau ve doi tuong
		
		//nhan chuot trai
		glRotatef(goc_1, 1,0,0);
		
		//nhan phim a
		glTranslatef(3,0,0);
		glRotatef(goc_2, 0,1,0);
		glTranslatef(-3,0,0);
		
		glutWireSphere(1.5,30,30);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.0,0.0,1.0);		//thiet lap mau ve doi tuong
		glTranslatef(3.0,0,0);
		glutWireSphere(1,30,30);	
	glPopMatrix();
	
	glutSwapBuffers();
	glFlush();
}

void reshape(int w, int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5,5,-5,5,1.5,20.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (700, 700);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

