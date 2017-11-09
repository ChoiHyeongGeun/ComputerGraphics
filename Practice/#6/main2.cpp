/*
		2012136139 ������
		��ǻ�ͱ׷��Ƚ� �� �ǽ� : ���� 6-2
*/
#include <gl/glut.h>
#include <stdio.h>

// DrawBody : �κ��� ���� �׸��� �Լ�
void DrawBody() {
	glPushMatrix();
	{
		glTranslatef(0.0, 0.2, 0.0);	// y������ 0.2 ��ŭ �̵�
		glScalef(1.0, 2.0, 1.0);	// y������ ũ�⸦ 2�踸ŭ �ø�
		glutWireCube(0.4);	// ���� ���̰� 0.4�� WireCube�� �׸�
	}
	glPopMatrix();
}

// DrawHead : �κ��� �Ӹ��� �׸��� �Լ�
void DrawHead() {
	glPushMatrix();
	{
		glTranslatef(0.0, 0.8, 0.0);	// y������ 0.8��ŭ �̵�
		glutWireSphere(0.2, 16, 16);	// �������� 0.2�� WireSphere�� �׸�
	}
	glPopMatrix();
}

// DrawArm : �κ��� �� �� �ٸ��� �׸��� �Լ�
// �Ű������� x��ǥ, y��ǥ, ȸ���� ������ �޴´�.
void DrawArm(float dx, float dy, int angle) {
	glPushMatrix();
	{
		glTranslatef(dx, dy, 0.0);	// �Ű������� ���� x, y��ǥ�� �̵�
		glRotatef(angle, 0.0, 0.0, 1.0);	// �Ű������� ���� ������ z���� �������� ȸ��

		glutWireSphere(0.1, 16, 16);	// �������� 0.1�� WireSphere�� �׸� (����)
		glTranslatef(0.4, 0.0, 0.0);		// x������ 0.4��ŭ �̵�
		glScalef(3.0, 1.0, 0.0);				// x������ 3�踸ŭ �ø�
		glutWireCube(0.2);					// ���� ���̰� 0.2�� WireCube�� �׸� (�� or �ٸ�)
	}
	glPopMatrix();
}

// DrawRobot : �κ� ��ü�� �׸��� �Լ�
void DrawRobot() {
	glPushMatrix();
	{
		DrawBody();		// ���� �׸���.
		DrawHead();		// �Ӹ��� �׸���.
		DrawArm(0.3, 0.5, 0);		// �������� �׸���.
		DrawArm(-0.3, 0.5, 220);	// ������ �׸���.
		DrawArm(-0.1, -0.3, 220);	// �޴ٸ��� �׸���.
		DrawArm(0.1, -0.3, 320);		// �����ٸ��� �׸���.
	}
	glPopMatrix();
}

// MyDisplay
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);	// ������ ���� �ʱ�ȭ

	DrawRobot();	// �κ��� �׸���.
	
	glFlush();		// ��� ��ɾ ���μ������� ����
}

// main
int main() {
	glutInitWindowSize(300, 300);	// ������ â ũ�� : 300 * 300
	glutCreateWindow("Homework #6-2");	// ������ â �̸�

	glutDisplayFunc(MyDisplay);	// MyDisplay �Լ� ȣ��

	glutMainLoop();	// �̺�Ʈ ������ ����
	return 0;
}