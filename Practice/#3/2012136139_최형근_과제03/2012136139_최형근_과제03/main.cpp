/*
		2012136139 최형근
		컴퓨터그래픽스 및 실습 : 과제 03 - 이름 쓰기
*/
#include <gl/glut.h>	// GLUT 라이브러리를 사용하기 위한 헤더
#include <gl/GL.h>		// GL 라이브러리를 사용하기 위한 헤더
#include <gl/GLU.h>	// GLU 라이브러리를 사용하기 위한 헤더

void MyDisplay() {
	
	glClear(GL_COLOR_BUFFER_BIT);	// 버퍼를 미리 설정된 값으로 지운다.
	// GL_COLOR_BUFFER_BIT : 컬러 쓰기를 위해 현재 활성화 된 버퍼

	//********** ㅊ **********

	glBegin(GL_QUADS);	// 정점 선언을 시작한다.
	// GL_QUADS : 사각형

	glVertex3f(-0.85, 0.5, 0.0);	// 정점을 지정한다. (3차원)
	glVertex3f(-0.65, 0.5, 0.0);
	glVertex3f(-0.65, 0.55, 0.0);
	glVertex3f(-0.85, 0.55, 0.0);

	glEnd();	// 정점 선언을 끝낸다.

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

	//********** ㅗ **********

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

	//********** ㅣ **********
	glBegin(GL_QUADS);

	glVertex3f(-0.45, 0.5, 0.0);
	glVertex3f(-0.4, 0.5, 0.0);
	glVertex3f(-0.4, -0.2, 0.0);
	glVertex3f(-0.45, -0.2, 0.0);

	glEnd();

	//********** ㅎ **********

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
	
	//********** ㅕ **********

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

	//********** ㅇ **********

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

	//********** ㄱ **********

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

	//********** ㅡ **********

	glBegin(GL_QUADS);

	glVertex3f(0.45, 0.25, 0.0);
	glVertex3f(0.95, 0.25, 0.0);
	glVertex3f(0.95, 0.2, 0.0);
	glVertex3f(0.45, 0.2, 0.0);

	glEnd();

	//********** ㄴ **********

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

	glFlush();		// 현재까지 쌓인 명령어들을 프로세서에게 전달
}

int main() {
		glutCreateWindow("OpenGL Drawing Example");	// glut에게 새로운 윈도우를 생성하라는 명령
		glutDisplayFunc(MyDisplay);	// 호출할 함수 등록 (콜백 함수)
		glutMainLoop();	// 이벤트 루프를 돌리는 함수 (모든 GL프로그램의 마지막에 작성한다.)
		return 0;
}