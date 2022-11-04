#include <GL/gl.h>

#include <GL/glut.h>

//ham ve hinh
void display(void){

	glClear (GL_COLOR_BUFFER_BIT);	//xóa tât ca cac mau trong vung dem khung trc do neu co
	
	glColor3f (1.0, 1.0, 1.0); //thiet lap mau ve
	glBegin(GL_POLYGON);	//bat dau ve hinh vuong
		glVertex3f (0.25, 0.25, 0.0);
		glVertex3f (0.75, 0.25, 0.0);
		glVertex3f (0.75, 0.75, 0.0);
		glVertex3f (0.25, 0.75, 0.0);
	glEnd();	//ket thuc ve
	//glFlush ();	//sinh anh dua ra vung dem khung
	
	
	glColor3f (1.0, 0.0, 0.0); //thiet lap mau ve
	glBegin(GL_TRIANGLES);	//bat dau ve hinh vuong
		glVertex3f (0.5, 1.0, 0.0);
		glVertex3f (0.25, 0.75, 0.0);
		glVertex3f (0.75, 0.75, 0.0);
	glEnd();	//ket thuc ve
	
	glFlush ();	//sinh anh dua ra vung dem khung
	
}
 
// dinh nghia hàm thiet lap cau hinh OpenGL 
void init (void){
	glClearColor (0.0, 0.0, 0.0, 0.0);	//thiet lap mau nen
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();		//xoa và thiet lap ma tran hien thoi ve ma tran don vi
	glOrtho(0.0, 1.0, 0.0, 1.5, -1.0, 1.0);		//thiet lap toa do ve (left, right, bottom, top, near, far)
}


int main(int argc, char** argv){
	glutInit(&argc, argv);				//Khoi tao Glut
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);	//thiet lap cau hinh che do ve
	
	glutInitWindowSize (250, 250);		//thiet lap kick thuoc cua so
	
	glutInitWindowPosition (100, 100);	// thiet lap vi tri xuat hien cua so goc tren ben trai : top=100, left = 100
	
	glutCreateWindow ("hello");			// tao cua so co tieu de :"hello"
	
	init ();					//goi ham thiet lap cau hinh OpenGL
	
	glutDisplayFunc(display);	//su ly su kien
	
	glutMainLoop();				//Lap dot su ly su kien
	
	return 0;
}
