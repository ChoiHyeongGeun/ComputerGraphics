/*
		2012136139 최형근
		컴퓨터그래픽스 및 실습 : 과제 6-1
*/
#include <gl/glut.h>
#include <stdio.h>

bool bPressed = false;	// 마우스 클릭 여부
float X1, Y1, X2, Y2;	// 좌표1(X1, Y1), 좌표2(X2, Y2)
bool isLine = true;		// Line을 그릴 것인지 Rectangle을 그릴 것인지 판단

// MyDisplay
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);	// 프레임 버퍼 초기화
	glColor3f(1.0, 1.0, 1.0);		// 색 지정

	glBegin(GL_LINE_LOOP);		// LineLoop을 그린다.

	if(isLine) {		// isLine == true 이면
		glVertex3f(X1, Y1, 0.0);	// (X1, Y1) 부터
		glVertex3f(X2, Y2, 0.0);	// (X2, Y2) 까지 LineLoop을 그린다.
	}
	else {	// isLine == false 이면
		glVertex3f(X1, Y1, 0.0);	// (X1, Y1)
		glVertex3f(X2, Y1, 0.0);	// (X2, Y1)
		glVertex3f(X2, Y2, 0.0);	// (X2, Y2)
		glVertex3f(X1, Y2, 0.0);	// (X1, Y2)을 4개의 점으로 하는 사각형을 그린다.
	}

	glEnd();	// 정점 선언을 마친다.
	glFlush();	// 명령어를 프로세서에게 전달
}

// mouseClick
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {	// 마우스 왼쪽 버튼을 클릭하면
			bPressed = true;	// bPressed를 true로 지정
			X1 = (X-150)/150.;	// X1 좌표 설정 (윈도우 좌표가 아닌 OpenGL 좌표로 변경)
			Y1 = (150-Y)/150.;	// Y1 좌표 설정
			printf("시작 : (%5.2f, %5.2f)\n", X1, Y1);	// 콘솔창에 좌표 출력
		}
		else	// 마우스 왼쪽 버튼을 클릭하지 않으면
			bPressed = false;	// bPressed를 false로 지정
}

// mouseMove
void MyMouseMove(GLint X, GLint Y) {
	if( bPressed) {	// 마우스 왼쪽 버튼이 클릭된 상태이면
		X2 = (X-150)/150.;	// X2 좌표 설정
		Y2 = (150-Y)/150.;	// Y2 좌표 설정
		printf("종료 : (%5.2f, %5.2f)\n", X2, Y2);	// 콘솔창에 좌표 출력
		glutPostRedisplay();		// 다시 그린다.
	}
}

// MyMainMenu
void MyMainMenu(int entryID) {
	if(entryID == 1){	// entryID가 1이면
		isLine = true;	// isLine을 true로 지정
	}
	else if(entryID == 2){		// entryID가 2이면
		isLine = false;			// isLine을 false로 지정
	}
	else if(entryID == 3){		// entryID가 3이면
		exit(0);	// 프로그램 종료
	}
	glutPostRedisplay();
}

// main
int main() {
	glutInitWindowSize(300, 300);	// 윈도우 창 사이즈 : 300 * 300
	glutCreateWindow("Homework #6");	// 윈도우 창 이름

	// 메인 메뉴 설정
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Draw Line", 1);	// 1번메뉴 : Draw Line
	glutAddMenuEntry("Draw Rectangle", 2);	// 2번메뉴 : Draw Rectangle
	glutAddMenuEntry("Exit", 3);	// 3번메뉴 : Exit
    glutAttachMenu(GLUT_RIGHT_BUTTON);	// 메인 메뉴 접근 방법 : 마우스 우측 버튼

	glutDisplayFunc(MyDisplay);	// MyDisplay 함수 호출
	glutMouseFunc(MyMouseClick);	// MyMouseClick 함수 호출
	glutMotionFunc(MyMouseMove);	// MyMouseMove 함수 호출

	glutMainLoop();	// 이벤트 루프로 진입
	return 0;
}