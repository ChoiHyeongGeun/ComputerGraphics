#pragma once

#include "myDrawing.h"

GLfloat Delta = 0.0;	// 애니메이션을 위한 변수 델타

// MyScreen 클래스
class MyScreen
{
	bool	bPressed;	// 마우스 클릭 여부
	int	pX, pY;	// 마우스 좌표
	double		size;	// 로봇 사이즈
	Matrix4x4 myMat;

public:
	int m;	// 메뉴 변수

	// 생성자
	MyScreen(void):bPressed(false), size(0.0){ }

	// 소멸자
	~MyScreen(void) { }

	// MyDisplay
	void display() {
		glClear(GL_COLOR_BUFFER_BIT);

		// 메뉴 변수가 4이면 (애니메이션)
		if(m == 4){
			// 로봇의 사이즈를 점점 늘린다.
			drawMyRobot(size + Delta);
		}
		// 메뉴 변수가 4가 아니면 (이동, 회전, 크기변환)
		else{
			// 현재 사이즈로 로봇을 그린다.
			drawMyRobot(size);
		}

		glFlush();
	}

	// 마우스 클릭 여부
	void mouseClick(GLint Button, GLint State, GLint X, GLint Y) {
		// 마우스 왼쪽 버튼 클릭
		if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
			bPressed = true;
			pX = X;
			pY = Y;
		}
		else
			bPressed = false;
	}

	// 마우스 이동
	void mouseMove(GLint X, GLint Y) {
		// 마우스 왼쪽 버튼이 눌렸으면
		if( bPressed) {
			int dx = X - pX;	// x좌표
			int dy = Y - pY;	// y좌표
			pX = X;
			pY = Y;

			// 메뉴 변수가 1이면 (이동)
			if(m == 1){
				// 좌표로 이동
				glTranslatef(dx/100.0, -dy/100.0, 0.0);
			}
			// 메뉴 변수가 2이면 (회전)
			else if(m == 2){
				// 좌표대로 회전
				glRotatef(dx, 0, 1, 0);
				glRotatef(dy, 1, 0, 0);
			}
			// 메뉴 변수가 3이면 (크기 변환)
			else if(m == 3){
				// x좌표대로 사이즈를 변환
				size += dx/100.0;
				// 그림을 다시 그린다.
				drawMyRobot(size);
				glFlush();
			}
			glutPostRedisplay();
		}
	}
};
