#pragma once

#include "myDrawing.h"

GLfloat Delta = 0.0;	// �ִϸ��̼��� ���� ���� ��Ÿ

// MyScreen Ŭ����
class MyScreen
{
	bool	bPressed;	// ���콺 Ŭ�� ����
	int	pX, pY;	// ���콺 ��ǥ
	double		size;	// �κ� ������
	Matrix4x4 myMat;

public:
	int m;	// �޴� ����

	// ������
	MyScreen(void):bPressed(false), size(0.0){ }

	// �Ҹ���
	~MyScreen(void) { }

	// MyDisplay
	void display() {
		glClear(GL_COLOR_BUFFER_BIT);

		// �޴� ������ 4�̸� (�ִϸ��̼�)
		if(m == 4){
			// �κ��� ����� ���� �ø���.
			drawMyRobot(size + Delta);
		}
		// �޴� ������ 4�� �ƴϸ� (�̵�, ȸ��, ũ�⺯ȯ)
		else{
			// ���� ������� �κ��� �׸���.
			drawMyRobot(size);
		}

		glFlush();
	}

	// ���콺 Ŭ�� ����
	void mouseClick(GLint Button, GLint State, GLint X, GLint Y) {
		// ���콺 ���� ��ư Ŭ��
		if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
			bPressed = true;
			pX = X;
			pY = Y;
		}
		else
			bPressed = false;
	}

	// ���콺 �̵�
	void mouseMove(GLint X, GLint Y) {
		// ���콺 ���� ��ư�� ��������
		if( bPressed) {
			int dx = X - pX;	// x��ǥ
			int dy = Y - pY;	// y��ǥ
			pX = X;
			pY = Y;

			// �޴� ������ 1�̸� (�̵�)
			if(m == 1){
				// ��ǥ�� �̵�
				glTranslatef(dx/100.0, -dy/100.0, 0.0);
			}
			// �޴� ������ 2�̸� (ȸ��)
			else if(m == 2){
				// ��ǥ��� ȸ��
				glRotatef(dx, 0, 1, 0);
				glRotatef(dy, 1, 0, 0);
			}
			// �޴� ������ 3�̸� (ũ�� ��ȯ)
			else if(m == 3){
				// x��ǥ��� ����� ��ȯ
				size += dx/100.0;
				// �׸��� �ٽ� �׸���.
				drawMyRobot(size);
				glFlush();
			}
			glutPostRedisplay();
		}
	}
};
