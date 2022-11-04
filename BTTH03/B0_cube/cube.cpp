#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int angle = 0;

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);	//tô bóng mô hình(trong mô hình chieu sang)
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);	
	glColor3f (1.0, 1.0, 1.0);
	glLoadIdentity (); /* clear the matrix */
	/* dinh nghia diem nhin cua nguoi quan sat:
	glulookAt(x1,y1,z1,x2,y2,z2,x3,y3,z3)
	- x1,y1,z1: vi tri cua nguoi quan sat
	- x2,y2,z2: diem ngam cua nguoi quan sat 
	- x3,y3,z3: huong dinh dau cua nguoi quan sat*/
	
	//gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);	//ban dau
	
	//gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);	//1.1a
	//gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 100.0, 0.0, 1.0, 0.0);	//1.1b
	gluLookAt (10.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);		//1.2a
	//gluLookAt (10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0);
	//gluLookAt (0.0, -5.0, 0.0, 0.0, 0.0, 0.0, 3.0, 0.0, -3.0);
	//gluLookAt (0.0, 0.0, 5.0, -10.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	
	//glScalef (1.0, 2.0, 1.0); /* dãn ám tra theo chieu y tang gap doi, chieu x va z du nguyen */
	//glutWireCube (1.0);	
	glRotatef(angle, 0,1,0);
	//glutWireTeapot(1.5);	//lenh ve am tra
	glutSolidTeapot(1.5);
//	glutSwapBuffers();		//
	glFlush ();
}

//ham tuong tac voi su kien cua chuot
void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		angle = (angle + 2)%360;	//góc quay tang len 2 do(neu goc quay >360 thi lay phan du -> quay tron deu	)	
		glutPostRedisplay();	//ve lai anh voi goc quay khac
	}
}

void keyboard(unsigned char key, int x, int y){
	if(key == 'a')
	{
		angle = (angle + 2)%360;	//góc quay tang len 2 do(neu goc quay >360 thi lay phan du -> quay tron deu	)	
		glutPostRedisplay();	//ve lai anh voi goc quay khac
	}	
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);	//phep chieu phoi canh
	//phep chieu xong xong
	//glOrtho(-2.0, 2.0, -2.0, 2.0, 1.5, 20.0);
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
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

