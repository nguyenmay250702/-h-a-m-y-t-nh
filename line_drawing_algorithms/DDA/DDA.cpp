#include<GL/glut.h>

//~~~~~~~~~~~~~ve duong thang bang thuat toan DDA

//dinh nghia thiet lap cau hinh openGL
void initGL(){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);	//thiet lap mau nen
	glOrtho(-320, 320, -240, 240, -1, 1);	//thiet lap khung nhin (toa do khung nhin tren man hinh: l,r,b,t,near,far)
}

//thuat toan DDA ve doan thang
void DDA(int x1, int y1, int x2, int y2){
	int Dx = x2 - x1;
	int Dy = y2 - y1;
	int k = Dy/Dx;
	int x = x1;
	int y = y1;
	glBegin(GL_POINTS);
	while(x <= x2){
		if(x%10<5){		
			for(int i=-2; i<=2; i++){
				glVertex2i(x,y+i);	//xac dinh toa do diem dau tien can ve
			}
		}
		
		x = x + 1;
		y = y + k;
	}
	glEnd();
}

//ve doan thang
void mydisplay(){
	glClear(GL_COLOR_BUFFER_BIT);	// xoa mau trong vung dem khung
	glColor3f(102, 0, 0);		//thiet lap mau ve
	DDA(10, 10, 109, 200);		//goi ham ve doan thang tu diem co toa do la: x1= 10, y1=10 va x2= 200, y2= 200
	glViewport(0,0,640,480);		//thiet lap khung nhin tren cua so ung dung
	glFlush();			
}

int main(int argc, char ** argv){
	glutInit(&argc, argv);	//khoi tao Glut
	
	//thiet lap che do hien thi do GLUT cung cap, va che do mau la RGB 
	int mode= GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	
	glutInitWindowSize(640, 480);	//kich thuoc cua so ung dung
	glutInitWindowPosition(0,0);	//vi tri xuat hien cua so ung dung
	glutCreateWindow("Thuat toan ve doan thang - DDA");	//tao ra cua so voi tien tieu de: "thuat toan ..."
	initGL();	
	glutDisplayFunc(mydisplay);
	glutMainLoop();		//su ly su kien tiep neu co
}


