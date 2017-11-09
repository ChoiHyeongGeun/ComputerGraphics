/*
		2012136139 최형근
		컴퓨터그래픽스 및 실습 : 과제 6-2
*/
#include <gl/glut.h>
#include <stdio.h>

// DrawBody : 로봇의 몸을 그리는 함수
void DrawBody() {
	glPushMatrix();
	{
		glTranslatef(0.0, 0.2, 0.0);	// y축으로 0.2 만큼 이동
		glScalef(1.0, 2.0, 1.0);	// y축으로 크기를 2배만큼 늘림
		glutWireCube(0.4);	// 변의 길이가 0.4인 WireCube를 그림
	}
	glPopMatrix();
}

// DrawHead : 로봇의 머리를 그리는 함수
void DrawHead() {
	glPushMatrix();
	{
		glTranslatef(0.0, 0.8, 0.0);	// y축으로 0.8만큼 이동
		glutWireSphere(0.2, 16, 16);	// 반지름이 0.2인 WireSphere를 그림
	}
	glPopMatrix();
}

// DrawArm : 로봇의 팔 과 다리를 그리는 함수
// 매개변수로 x좌표, y좌표, 회전할 각도를 받는다.
void DrawArm(float dx, float dy, int angle) {
	glPushMatrix();
	{
		glTranslatef(dx, dy, 0.0);	// 매개변수로 받은 x, y좌표로 이동
		glRotatef(angle, 0.0, 0.0, 1.0);	// 매개변수로 받은 각도로 z축을 기준으로 회전

		glutWireSphere(0.1, 16, 16);	// 반지름이 0.1인 WireSphere를 그림 (연골)
		glTranslatef(0.4, 0.0, 0.0);		// x축으로 0.4만큼 이동
		glScalef(3.0, 1.0, 0.0);				// x축으로 3배만큼 늘림
		glutWireCube(0.2);					// 변의 길이가 0.2인 WireCube를 그림 (팔 or 다리)
	}
	glPopMatrix();
}

// DrawRobot : 로봇 전체를 그리는 함수
void DrawRobot() {
	glPushMatrix();
	{
		DrawBody();		// 몸을 그린다.
		DrawHead();		// 머리를 그린다.
		DrawArm(0.3, 0.5, 0);		// 오른팔을 그린다.
		DrawArm(-0.3, 0.5, 220);	// 왼팔을 그린다.
		DrawArm(-0.1, -0.3, 220);	// 왼다리를 그린다.
		DrawArm(0.1, -0.3, 320);		// 오른다리를 그린다.
	}
	glPopMatrix();
}

// MyDisplay
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);	// 프레임 버퍼 초기화

	DrawRobot();	// 로봇을 그린다.
	
	glFlush();		// 모든 명령어를 프로세서에게 전달
}

// main
int main() {
	glutInitWindowSize(300, 300);	// 윈도우 창 크기 : 300 * 300
	glutCreateWindow("Homework #6-2");	// 윈도우 창 이름

	glutDisplayFunc(MyDisplay);	// MyDisplay 함수 호출

	glutMainLoop();	// 이벤트 루프로 진입
	return 0;
}