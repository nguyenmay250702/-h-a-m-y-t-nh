#include <GL/gl.h>
#include <GL/glut.h>

void bre(int x1,int y1,int x2,int y2)
{
	unsigned long pattern =0xff00ff00;
	unsigned long mask =0x80000000;
	int x,y,dy,dx;float d;
	dx=x2-x1;dy=y2-y1;d=2*dy-dx;
	x=x1;y=y1;
	
	while(x<=x2){
		 int j=-3;
		 mask=mask? mask : 0x80000000;
		 if(d<0) d=d+2*dy;
		 else {
			d=d+2*dy-2*dx;
			y++;
		 }
		 if (pattern&mask) glVertex2f(x,y);
		 x++;
		 mask>>=1;
	}
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
		bre(10,10,100,80);
	glEnd();
	glFlush ();
}

void init (void){
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 200.0, 0.0, 200.0, -1.0, 1.0);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);// Kh?i t?o Glut và x? lí m?i dòng l?nh d?i s?, glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);// s? d?ng mô hình RGBA
	glutInitWindowSize (250, 250);// kích c? c?a s? 
	glutInitWindowPosition (100, 100);// ch? ra v? trí màn hình góc trên bên trái
	glutCreateWindow ("hello"); // T?o tiêu d? c?a s? “hello”
	init ();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0; 
}

