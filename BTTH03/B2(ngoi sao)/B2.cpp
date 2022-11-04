#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<math.h>

int angle = 0;
int angle1 = 0;

//thiet lap cau hinh OpenGL
void init(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);	//thiet lap mau nen
}

//tuong tac voi chuot
void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		angle1 = (angle1 + 2)%360;
		glutPostRedisplay();
	}
}

//tuong tac voi cac phim
void keyboard(unsigned char key , int x, int y){
	if(key == 'a'){
		angle = (angle + 2)%360;
		glutPostRedisplay();
	}
}

//ve hinh
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);	//xoa cac mau trong vung dem khung neu co
	glColor3f(1.0,1.0,1.0);		//thiet lap mau ve
	glLoadIdentity();		//thiet lap ma tran don vi
	//dinh nghia diem nhin cua nguoi quan sat: dung tren truc oz, nhin vao diem 0(0,0,0), dau huong ve trc oy
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0);
	
		glTranslatef(15*cos(3.14/5), 15*sin(3.14/5), 0.0);
		glRotatef(angle,0,0,1);
		glTranslatef(-15*cos(3.14/5), -15*sin(3.14/5), 0.0);
		glRotatef(angle1,0,0,1);
	
	//ve ngoi sao
	GLfloat ag, r; GLfloat step = 3.14/5.0;
	glBegin(GL_LINE_LOOP);
	for(int i=0; i<10; ++i){
		r = (i%2 == 0? 5:15);
		ag = i*step;
		glVertex3f(r*cos(ag),r*sin(ag),0.0);
	}
	glEnd();

	//doi cho 2 khung hinh
	glutSwapBuffers();

	//sinh anh ra vung dem khung
	glFlush();
}

void reshape(int w, int h){
	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);	//trc khi dinh nghia phep chieu can thiet lap mt = cau lenh
	glLoadIdentity();
	glOrtho(-50.0,50.0,-50.0,50.0,1.5,20.0);
	glMatrixMode(GL_MODELVIEW);	//phep chieu thanh cong, hien doi tuong theo phep chieu da thiet lap
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}









