#include<GL/glut.h>

void initGL(){
	glClearColor(1,1,1,1);
	glOrtho(-200,500,-200,500,-1,1);
}

//ve toa do oxy
void oxy(){
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
		glVertex2f(0.0,400.0);
		glVertex2f(0.0,0.0);
		glVertex2f(400.0,0.0);
	glEnd();
	glFlush();
}

void Bresenham(int x1, int y1, int x2, int y2){
	int x = x1; int y = y1;
	int dx = x2-x1; int dy = y2-y1; int d = dx-2*dy;
	
	glColor3f(0.0,0.0,153.0);
	glBegin(GL_POINTS);
	while(x<=x2){
		
		if(x%10<5){		//nét dut 5
			for(int i=-2; i<=2; i++){	//ve do day la 5 (ve them 2 diem ben tren và 2 diem ben duoi) 
				glVertex2i(x,y+i);
			}
		}
		
		if(d>0){
			d = d-2*dy;
		}
		else{
			d = d + 2*dx - 2*dy;
			y = y+1;
		}
		x++;
	}
	glEnd();
}

void mydisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	Bresenham(10,30,200,160);
	oxy();
	glFlush();
}

int main(int argc, char ** argv){
	glutInit(&argc, argv);	//khoi tao Glut
	
	//Thiet lap che do hien thi do GLUT cung cap, va che do mau RGB
	int mode = GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	
	glutInitWindowSize(640,480);	//kich thuoc cua so ung dung
	glutInitWindowPosition(0,0);	//vi tri xuat hien cua so ung dung
	glutCreateWindow("Thuat toan ve doan thang - Bresenham");	//ten tieu de cua so ung dung
	
	initGL();	//goi ham thiet lap cau hinh OpenGL
	glutDisplayFunc(mydisplay);
	glutMainLoop();		//su ly su kien tiep theo
}



