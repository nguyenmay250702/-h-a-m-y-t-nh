#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

int angle = 0;

//thiet lap cau hinh OpenGL
void init(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);	//thiet lap mau nen
	//glShadeModel(GL_FLAT);	//tô bóng mô hình
}

//tuong tac voi chuot
void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		angle = (angle + 2)%360;	//goc quay tang len 2 do(neu goc quay >360 thi lay phan du --> quay tron deu)
		glutPostRedisplay();	//ve lai anh voi 1 goc quay khac
	}
}

//tuong tac voi cac phim
void keyboard(unsigned char key, int x, int y){
	if(key == 'a'){
		angle = angle + 2;
		if(angle >360) angle = angle -360;
		glutPostRedisplay();	
	}
}

//ve hinh
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);	//xoa tat ca cac mau trong vung dem khung trc do neu co
	glColor3f(1.0, 1.0, 1.0);	//thiet lap mau ve
	glLoadIdentity();	//thiet lap ma tran cua toa do là ma tran don vi
	
	/* dinh nghia diem nhin cua nguoi quan sat:
	glulookAt(x1,y1,z1,x2,y2,z2,x3,y3,z3)
	- x1,y1,z1: vi tri cua nguoi quan sat
	- x2,y2,z2: diem ngam cua nguoi quan sat 
	- x3,y3,z3: huong dinh dau cua nguoi quan sat*/
	gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	/*
	gluLookAt (10.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	gluLookAt (10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0);
	gluLookAt (0.0, -5.0, 0.0, 0.0, 0.0, 0.0, 3.0, 0.0, -3.0);
	gluLookAt (0.0, 0.0, 5.0, -10.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	*/
	
	glRotatef(angle, 0,1,0);	//quay doi tuong 1 goc angle quanh 1 truc = noi 0(0,0,0) den (1,0,0) (quay quanh truc ox)
	glutWireTeapot(1.0);	//ve am tra dang luoi(duong kinh = 1)
	glutSwapBuffers();		//doi cho 2 khung hinh
	glFlush();		//sinh anh ra vung dem khung
}

void reshape(int w, int h){
	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();		//thiet lap mt toa do la mt don vi
	glOrtho(-2.0,2.0,-2.0,2.0,1.5,20.0);	//phep chieu xong xong(dinh nghia khung nhin)
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char ** argv){
	glutInit(&argc, argv);	//khoi tao doi tuong Glut
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	//thiet lap mau cau hinh che do ve
	glutInitWindowSize(500,500);	//thiet lap kich thuoc cua so ung dung
	glutInitWindowPosition(100, 100);	//thiet lap vi tri hien thi cua cua so
	glutCreateWindow(argv[0]);	//toa ra cua so hien thi
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}






















