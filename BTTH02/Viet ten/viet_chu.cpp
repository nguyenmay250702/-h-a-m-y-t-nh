#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

//mang raster 1 chieu, gom: 24 phan tu
//0x: bieu dien so o dang hexadecimal (he 16 = he thap luc phan)
//1 khoi ofxet phai co do rong la 8 (trong bai nay do rong 1 chu la 16 -> can 2 khoi ofset)
GLubyte rasters1[24] = {0x72, 0x0E, 0xCB, 0x19, 0xCB, 0x98, 0x6B, 0x58, 0x0B, 0x58, 0x0B, 0x58, 0x0B, 0x58, 0x0B, 0x58, 0x0B, 0x58, 0x0B, 0x58, 0x07, 0x38, 0x03, 0x18};
GLubyte rasters2[24] = {0x07, 0xB0, 0x0C, 0x68, 0x0C, 0x60, 0x0C, 0x60, 0x0C, 0x60, 0x06, 0x60, 0x03, 0xE0 , 0x00, 0x00, 0x04, 0x60, 0x02,0xC0, 0x01, 0x80, 0x00, 0x00};
GLubyte rasters3[26] = {0x01, 0x80, 0x02, 0xC0, 0x02, 0xC0, 0x02, 0xC0, 0x01, 0xC0, 0x00, 0xC0, 0x06, 0xE0 , 0x0D, 0xD0, 0x06, 0x60, 0x06, 0x60, 0x16, 0x60, 0x0E, 0x60, 0X06, 0X60};  

void init(void)
{
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
	glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glRasterPos2i (100, 100);	//dinh nghia lai goc toa do
	glBitmap (16, 12, 0.0, 0.0, 13.0, 0.0, rasters1);	//chieu rong, chieu cao, vi tri bat dau goc duoi ben trai, vi tri bat dau cua diem tiep theo
	glBitmap (16, 12, 0.0, 0.0, 10.0, 0.0, rasters2);
	glBitmap (16, 13, 0.0, 7.0, 0.0, 0.0, rasters3);
	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho (0,w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 27:
		exit(0);
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
