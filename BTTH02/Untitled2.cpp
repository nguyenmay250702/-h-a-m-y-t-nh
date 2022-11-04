#include <GL/gl.h>

#include <GL/glut.h>
#include <math.h>

//ham ve hinh
void display(void){
//~~~~~~~b1: 
//a) ngu giac
	/*
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glClear (GL_COLOR_BUFFER_BIT);	//xóa tât ca cac mau trong vung dem khung trc do neu co
	glColor3f (1.0, 1.0, 1.0); //thiet lap mau ve
	glBegin(GL_LINE_LOOP);	//bat dau ve hinh vuong
		glVertex3f (0.25, 0.25, 0.0);
		glVertex3f (0.55, 0.25, 0.0);
		glVertex3f (0.65, 0.55, 0.0);
		glVertex3f (0.40, 0.75, 0.0);
		glVertex3f (0.15, 0.55, 0.0);
	glEnd();	//ket thuc ve
	glFlush ();	//sinh anh dua ra vung dem khung
	*/


//b) luc giac
	/*
	glClear (GL_COLOR_BUFFER_BIT);	//xóa tât ca cac mau trong vung dem khung trc do neu co
	glColor3f (1.0, 1.0, 1.0); //thiet lap mau ve
	GLfloat step = 3.14 / 3.0;
	register int i;
	GLfloat angle, r;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < 6; ++i) {
		r = 2;
		angle = i * step;
		glVertex3f(r * cos(angle), r * sin(angle),0.0);
	}
	glEnd();	//ket thuc ve
	glFlush ();	//sinh anh dua ra vung dem khung
	*/
	
	
//~~~~~~~~b2:
//a)
	
//b)
	/*
	glClear (GL_COLOR_BUFFER_BIT);	//xóa tât ca cac mau trong vung dem khung trc do neu co
	glColor3f (1.0, 1.0, 1.0); //thiet lap mau ve
	GLfloat step = 3.14 / 90.0;
	register int i;
	GLfloat angle, r;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < 182; ++i) {
		r = (i % 2 == 0 ? 4 : 8);
		angle = i * step;
		glVertex3f(r * cos(angle), r * sin(angle),0.0);
	}
	glEnd();	//ket thuc ve
	glFlush ();	//sinh anh dua ra vung dem khung
	*/

	
//~~~~~~~~b4:
	/*
	glClear (GL_COLOR_BUFFER_BIT);	//xóa tât ca cac mau trong vung dem khung trc do neu co
		
	//ve so 8
	GLfloat step = 3.14 / 180.0;
	register int i,j;
	GLfloat angle, r, angle2, r2;
	
	glColor3f (1.0, 1.0, 1.0); //thiet lap mau ve
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < 362; ++i) {
		r = (i % 2 == 0 ? 0.5 : 1);
		angle = i * step;
		glVertex3f(r * cos(angle), r * sin(angle)+0.75,0.0);
	}
	glEnd();	//ket thuc ve
	
	glColor3f (1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (j = 0; j < 362; ++j) {
		r = (j % 2 == 0 ? -0.5 : -1);
		angle = j * step;
		glVertex3f(r * cos(angle), r * sin(angle) - 0.75 ,0.0);
	}
	glEnd();
	
	
	//truc toa do oxy
	glColor3f (1.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);	//bat dau ve hinh vuong
		glVertex2f(0.0,2.5);
		glVertex2f(0.0,0.0);
		glVertex2f(2.5,0.0);
	glEnd();
	
	glFlush ();	//sinh anh dua ra vung dem khung
	*/
	
}
 
// dinh nghia hàm thiet lap cau hinh OpenGL 
void init (void){
	glClearColor (0.0, 0.0, 0.0, 0.0);	//thiet lap mau nen
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();		//xoa và thiet lap ma tran hien thoi ve ma tran don vi
	//glOrtho(-3.0, 3.0, -3.0, 3.0, -1.0, 1.0);
	//glOrtho(-11.0, 11.0, -11.0, 11.0, -1.0, 1.0);		//thiet lap toa do ve (left, right, bottom, top, near, far)
}


int main(int argc, char** argv){
	glutInit(&argc, argv);				//Khoi tao Glut
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);	//thiet lap cau hinh che do ve
	
	glutInitWindowSize (550, 550);		//thiet lap kick thuoc cua so
	
	glutInitWindowPosition (100, 100);	// thiet lap vi tri xuat hien cua so goc tren ben trai : top=100, left = 100
	
	glutCreateWindow ("hello");			// tao cua so co tieu de :"hello"
	
	init ();					//goi ham thiet lap cau hinh OpenGL
	
	glutDisplayFunc(display);	//su ly su kien
	
	glutMainLoop();				//Lap dot su ly su kien
	
	return 0;
}

