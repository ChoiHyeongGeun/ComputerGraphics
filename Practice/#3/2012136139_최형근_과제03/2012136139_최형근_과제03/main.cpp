/*
		2012136139 ������
		��ǻ�ͱ׷��Ƚ� �� �ǽ� : ���� 03 - �̸� ����
*/
#include <gl/glut.h>	// GLUT ���̺귯���� ����ϱ� ���� ���
#include <gl/GL.h>		// GL ���̺귯���� ����ϱ� ���� ���
#include <gl/GLU.h>	// GLU ���̺귯���� ����ϱ� ���� ���

void MyDisplay() {
	
	glClear(GL_COLOR_BUFFER_BIT);	// ���۸� �̸� ������ ������ �����.
	// GL_COLOR_BUFFER_BIT : �÷� ���⸦ ���� ���� Ȱ��ȭ �� ����

	//********** �� **********

	glBegin(GL_QUADS);	// ���� ������ �����Ѵ�.
	// GL_QUADS : �簢��

	glVertex3f(-0.85, 0.5, 0.0);	// ������ �����Ѵ�. (3����)
	glVertex3f(-0.65, 0.5, 0.0);
	glVertex3f(-0.65, 0.55, 0.0);
	glVertex3f(-0.85, 0.55, 0.0);

	glEnd();	// ���� ������ ������.

	glBegin(GL_QUADS);

	glVertex3f(-0.95, 0.45, 0.0);
	glVertex3f(-0.55, 0.45, 0.0);
	glVertex3f(-0.55, 0.4, 0.0);
	glVertex3f(-0.95, 0.4, 0.0);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(-0.63, 0.4, 0.0);
	glVertex3f(-0.55, 0.4, 0.0);
	glVertex3f(-0.87, 0.1, 0.0);
	glVertex3f(-0.95, 0.1, 0.0);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(-0.77, 0.25, 0.0);
	glVertex3f(-0.7, 0.26, 0.0);
	glVertex3f(-0.55, 0.1, 0.0);
	glVertex3f(-0.63, 0.1, 0.0);

	glEnd();

	//********** �� **********

	glBegin(GL_QUADS);

	glVertex3f(-0.75, 0.05, 0.0);
	glVertex3f(-0.7, 0.05, 0.0);
	glVertex3f(-0.7, -0.1, 0.0);
	glVertex3f(-0.75, -0.1, 0.0);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(-0.95, -0.1, 0.0);
	glVertex3f(-0.5, -0.1, 0.0);
	glVertex3f(-0.5, -0.15, 0.0);
	glVertex3f(-0.95, -0.15, 0.0);

	glEnd();

	//********** �� **********
	glBegin(GL_QUADS);

	glVertex3f(-0.45, 0.5, 0.0);
	glVertex3f(-0.4, 0.5, 0.0);
	glVertex3f(-0.4, -0.2, 0.0);
	glVertex3f(-0.45, -0.2, 0.0);

	glEnd();

	//********** �� **********

	glBegin(GL_QUADS);

	glVertex3f(-0.17, 0.55, 0.0);
	glVertex3f(0.13, 0.55, 0.0);
	glVertex3f(0.13, 0.5, 0.0);
	glVertex3f(-0.17, 0.5, 0.0);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(-0.27, 0.45, 0.0);
	glVertex3f(0.23, 0.45, 0.0);
	glVertex3f(0.23, 0.4, 0.0);
	glVertex3f(-0.27, 0.4, 0.0);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(-0.22, 0.3, 0.0);
	glVertex3f(-0.12, 0.35, 0.0);
	glVertex3f(0.08, 0.35, 0.0);
	glVertex3f(0.18, 0.3, 0.0);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(-0.22, 0.3, 0.0);
	glVertex3f(-0.12, 0.3, 0.0);
	glVertex3f(-0.12, 0.15, 0.0);
	glVertex3f(-0.22, 0.15, 0.0);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(0.18, 0.3, 0.0);
	glVertex3f(0.08, 0.3, 0.0);
	glVertex3f(0.08, 0.15, 0.0);
	glVertex3f(0.18, 0.15, 0.0);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(-0.22, 0.15, 0.0);
	glVertex3f(-0.12, 0.1, 0.0);
	glVertex3f(0.08, 0.1, 0.0);
	glVertex3f(0.18, 0.15, 0.0);

	glEnd();
	
	//********** �� **********

	glBegin(GL_QUADS);

	glVertex3f(0.19, 0.32, 0.0);
	glVertex3f(0.29, 0.32, 0.0);
	glVertex3f(0.29, 0.27, 0.0);
	glVertex3f(0.19, 0.27, 0.0);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(0.19, 0.23, 0.0);
	glVertex3f(0.29, 0.23, 0.0);
	glVertex3f(0.29, 0.18, 0.0);
	glVertex3f(0.19, 0.18, 0.0);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(0.28, 0.55, 0.0);
	glVertex3f(0.33, 0.55, 0.0);
	glVertex3f(0.33, 0.1, 0.0);
	glVertex3f(0.28, 0.1, 0.0);

	glEnd();

	//********** �� **********

	glBegin(GL_QUADS);

	glVertex3f(-0.12, 0.0, 0.0);
	glVertex3f(-0.02, 0.05, 0.0);
	glVertex3f(0.18, 0.05, 0.0);
	glVertex3f(0.28, 0.0, 0.0);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(-0.12, 0.0, 0.0);
	glVertex3f(-0.02, 0.0, 0.0);
	glVertex3f(-0.02, -0.15, 0.0);
	glVertex3f(-0.12, -0.15, 0.0);
	
	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(0.28, 0.0, 0.0);
	glVertex3f(0.18, 0.0, 0.0);
	glVertex3f(0.18, -0.15, 0.0);
	glVertex3f(0.28, -0.15, 0.0);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(-0.12, -0.15, 0.0);
	glVertex3f(-0.02, -0.2, 0.0);
	glVertex3f(0.18, -0.2, 0.0);
	glVertex3f(0.28, -0.15, 0.0);

	glEnd();

	//********** �� **********

	glBegin(GL_QUADS);

	glVertex3f(0.5, 0.55, 0.0);
	glVertex3f(0.9, 0.55, 0.0);
	glVertex3f(0.9, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(0.85, 0.5, 0.0);
	glVertex3f(0.9, 0.5, 0.0);
	glVertex3f(0.9, 0.3, 0.0);
	glVertex3f(0.85, 0.3, 0.0);

	glEnd();

	//********** �� **********

	glBegin(GL_QUADS);

	glVertex3f(0.45, 0.25, 0.0);
	glVertex3f(0.95, 0.25, 0.0);
	glVertex3f(0.95, 0.2, 0.0);
	glVertex3f(0.45, 0.2, 0.0);

	glEnd();

	//********** �� **********

	glBegin(GL_QUADS);

	glVertex3f(0.5, 0.15, 0.0);
	glVertex3f(0.55, 0.15, 0.0);
	glVertex3f(0.55, -0.15, 0.0);
	glVertex3f(0.5, -0.15, 0.0);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(0.5, -0.15, 0.0);
	glVertex3f(0.9, -0.15, 0.0);
	glVertex3f(0.9, -0.2, 0.0);
	glVertex3f(0.5, -0.2, 0.0);

	glEnd();

	glFlush();		// ������� ���� ��ɾ���� ���μ������� ����
}

int main() {
		glutCreateWindow("OpenGL Drawing Example");	// glut���� ���ο� �����츦 �����϶�� ���
		glutDisplayFunc(MyDisplay);	// ȣ���� �Լ� ��� (�ݹ� �Լ�)
		glutMainLoop();	// �̺�Ʈ ������ ������ �Լ� (��� GL���α׷��� �������� �ۼ��Ѵ�.)
		return 0;
}