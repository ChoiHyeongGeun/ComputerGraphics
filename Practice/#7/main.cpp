/*
		2012136139 최형근
		컴퓨터그래픽스 및 실습 : 과제 7
*/
#include <gl/glut.h>
#include <stdio.h>

bool bPressed = false;	// 마우스 클릭 여부
float pX, pY;	// 마우스클릭 시 좌표
int dx, dy;	// 마우스 움직일때 좌표
int menu = 0;	// 메뉴 변수
double size = 1.0;		// 크기변환 변수
int Width, Height;	// 창의 가로, 세로 크기

// Menu : 메뉴 변수에 따른 이동 & 회전
void Menu() {
	// 메뉴 변수가 1이면 (이동)
	if(menu == 1){
		// 좌표로 이동
		glTranslatef(dx/100.0, -dy/100.0, 0.0);
	}
	// 메뉴 변수가 2이면 (회전)
	else if(menu == 2){
		// 좌표대로 회전
		glRotatef(dx, 0, 1, 0);
		glRotatef(dy, 1, 0, 0);
	}
}

// DrawBody : 로봇의 몸을 그리는 함수
void DrawBody() {
	glPushMatrix(); // 행렬 스택 쌓기
	{
		glTranslatef(0.0, 0.2, 0.0);	// y축으로 0.2 만큼 이동
		glScalef(1.0, 2.0, 1.0);	// y축으로 크기를 2배만큼 늘림
		glutSolidCube(0.4);	// 변의 길이가 0.4인 WireCube를 그림
	}
	glPopMatrix(); // 행렬 스택 되돌리기
}

// DrawHead : 로봇의 머리를 그리는 함수
void DrawHead() {
	glPushMatrix(); // 행렬 스택 쌓기
	{
		glTranslatef(0.0, 0.8, 0.0);	// y축으로 0.8만큼 이동
		glutSolidSphere(0.2, 16, 16);	// 반지름이 0.2인 WireSphere를 그림
	}
	glPopMatrix(); // 행렬 스택 되돌리기
}

// DrawArm : 로봇의 팔 과 다리를 그리는 함수
// 매개변수로 x좌표, y좌표, 회전할 각도를 받는다.
void DrawArm(float dx, float dy, int angle, double scale) {
	glPushMatrix(); // 행렬 스택 쌓기
	{
		glTranslatef(dx, dy, 0.0); // 매개변수로 받은 x, y좌표로 이동
		glRotatef(angle, 0.0, 0.0, 1.0); // 매개변수로 받은 각도로 z축을 기준으로 회전
		glutSolidSphere(0.1, 16, 16); // 반지름이 0.1인 WireSphere를 그림 (연골)

		glTranslatef(0.1 + scale/20, 0.0, 0.0); // x축으로 0.2만큼 이동
		glScalef(scale, 1.2, 1.2); // x축으로 2배, y축으로 1.2배, z축으로 1.2배 크기 증가
		glutSolidCube(0.1); // 변의 길이가 0.1인 SolidCube를 그림 (팔 or 다리)
	}
	glPopMatrix(); // 행렬 스택 되돌리기
}

// DrawScene : 바닥을 그리는 함수
void DrawScene() {
    glColor3f(0.7, 0.7, 0.7); // 색 : 회색
    glPushMatrix(); // 행렬 스택 쌓기
        glTranslatef(0.0, -1.0, 0.0); // y축으로 -1만큼 이동
        glBegin(GL_QUADS); // GL_QUADS
            glVertex3f(2.0, 0.0, 2.0); // 점 지정
            glVertex3f(2.0, 0.0, -2.0); // 점 지정
            glVertex3f(-2.0, 0.0, -2.0); // 점 지정
            glVertex3f(-2.0, 0.0, 2.0); // 점 지정
        glEnd(); // 그리기 종료
    glPopMatrix(); // 행렬 스택 되돌리기
}

// DrawRobot : 로봇 전체를 그리는 함수
void DrawRobot(double x) {
	glPushMatrix(); // 행렬 스택 쌓기
	{
		Menu(); // Menu
		glScalef(1.0 * x, 1.0 * x, 1.0 * x); // 매개변수에 따라서 크기 변경
		DrawScene(); // 바닥 그리기
		glColor3f(0.0, 0.0, 0.5); // 색 : 보라색
		DrawBody();		// 몸을 그린다.
		DrawHead();		// 머리를 그린다.
		DrawArm(0.3, 0.5, 280, 4.0);		// 오른팔을 그린다.
		DrawArm(-0.3, 0.5, 260, 4.0);	// 왼팔을 그린다.
		DrawArm(-0.1, -0.3, 250, 6.0);	// 왼다리를 그린다.
		DrawArm(0.1, -0.3, 290, 6.0);		// 오른다리를 그린다.
	}
	glPopMatrix(); // 행렬 스택 되돌리기
}

// MyMainMenu : 메인 메뉴
void MyMainMenu(int entryID) {
	if(entryID == 1){	// entryID가 1이면
		menu = 1;		// 메뉴 변수 = 1
	}
	else if(entryID == 2){		// entryID가 2이면
		menu = 2;			// 메뉴 변수 = 2
	}
	else if(entryID == 3){		// entryID가 3이면
		menu = 3;			// 메뉴 변수 = 3
	}
	else if(entryID == 4){		// entryID가 4이면
		menu = 4;			// 메뉴 변수 = 4
	}
	else if(entryID == 5){		// entryID가 5이면
		exit(0);	// 프로그램 종료
	}
	glutPostRedisplay(); // 다시 그린다.
}

// MyMouseClick : 마우스 클릭 여부
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	// 마우스 왼쪽 버튼 클릭시
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		bPressed = true;	// bPressed를 true로 지정
		pX = X; // x좌표 저장
		pY = Y; // y좌표 저장
	}
	else
		bPressed = false; // bPressed를 false로 지정
}

// MyMouseMove : 마우스 이동
void MyMouseMove(GLint X, GLint Y) {
	// 마우스 왼쪽 버튼이 눌렸으면
	if( bPressed) {
		dx = X - pX;	// x좌표
		dy = Y - pY;	// y좌표

		// 메뉴 변수가 3이면 (크기 변환)
		if(menu == 3){
			pX = X; // x좌표 재지정
			pY = Y; // y좌표 재지정
			// x좌표대로 사이즈를 변환
			size += dx/100.0;
			// 그림을 다시 그린다.
			DrawRobot(size);
			glFlush(); // 모든 명령어를 프로세서에게 전달
		}
		glutPostRedisplay(); // 다시 그린다.
	}
}

// MyDisplay
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);	// 프레임 버퍼 초기화

	// 메뉴 변수가 4이면
	if(menu == 4)
		size = 1.0; // 크기 초기화

	// 뷰포트 1 : 왼쪽 아래
	glViewport(0, 0, Width/2, Height/2);
    glPushMatrix(); // 행렬 스택 쌓기
        gluLookAt(0.0, 0.0, 1.0,   0.0, 0.0, 0.0,   0.0, 1.0, 0.0); // 시점 변환
        DrawRobot(size);	// 로봇을 그린다.
    glPopMatrix(); // 행렬 스택 되돌리기

	// 뷰포트 2 : 오른쪽 아래
    glViewport(Width/2, 0, Width/2, Height/2);
    glPushMatrix(); // 행렬 스택 쌓기
        gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0, 1.0, 0.0); // 시점 변환
        DrawRobot(size);	// 로봇을 그린다.
    glPopMatrix(); // 행렬 스택 되돌리기

	// 뷰포트 3 : 왼쪽 위
    glViewport(0, Height/2, Width/2, Height/2);
    glPushMatrix(); // 행렬 스택 쌓기
        gluLookAt(0.0, 1.0, 0.0,   0.0, 0.0, 0.0,   0.0, 0.0, -1.0); // 시점 변환
        DrawRobot(size);	// 로봇을 그린다.
    glPopMatrix(); // 행렬 스택 되돌리기

	// 뷰포트 4 : 오른쪽 위
    glViewport(Width/2, Height/2, Width/2, Height/2);
    glMatrixMode(GL_PROJECTION); // 행렬모드 : 프로젝션
    glPushMatrix(); // 행렬 스택 쌓기
        glLoadIdentity(); // 항등행렬로 초기화
        gluPerspective(30, 1.0, 3.0, 50.0); // 대칭적 원근투상 
        glMatrixMode(GL_MODELVIEW); // 행렬모드 : 모델뷰
        glPushMatrix(); // 행렬 스택 쌓기
            gluLookAt(6.0, 6.0, 6.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0); // 시점 변환
            DrawRobot(size);	// 로봇을 그린다.
        glPopMatrix(); // 행렬 스택 되돌리기
        glMatrixMode(GL_PROJECTION); // 행렬모드 : 프로젝션
    glPopMatrix(); // 행렬 스택 되돌리기

	glFlush();	 // 모든 명령어를 프로세서에게 전달
}

// main
int main() {
	Width = 500; // 창의 가로 크기
	Height = 500; // 창의 세로 크기
	glutInitWindowSize(Width, Height);	// 윈도우 창 크기 : 500 x 500
	glutCreateWindow("Homework #7");	// 윈도우 창 이름

	glClearColor(1.0, 1.0, 1.0, 1.0); // 배경색 초기화
    glMatrixMode(GL_PROJECTION); // 행렬모드 : 프로젝션
    glLoadIdentity( ); // 항등행렬로 초기화

    glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0); // 평행투상
    glMatrixMode(GL_MODELVIEW); // 행렬모드 : 모델뷰
    glLoadIdentity( ); // 항등행렬 초기화

	// 메인 메뉴 설정
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("이동", 1);	// 1번메뉴 : 
	glutAddMenuEntry("회전", 2);	// 2번메뉴 : 
	glutAddMenuEntry("크기변환", 3);	// 3번메뉴 : 
	glutAddMenuEntry("원래대로", 4);	// 4번메뉴 : 
	glutAddMenuEntry("종료", 5);	// 5번메뉴 : 
    glutAttachMenu(GLUT_RIGHT_BUTTON);	// 메인 메뉴 접근 방법 : 마우스 우측 버튼

	glutDisplayFunc(MyDisplay);	// MyDisplay 함수 호출
	glutMouseFunc(MyMouseClick); // MyMouseClick 함수 호출
	glutMotionFunc(MyMouseMove); // MyMouseMove 함수 호출

	glutMainLoop();	// 이벤트 루프로 진입
	return 0;
}