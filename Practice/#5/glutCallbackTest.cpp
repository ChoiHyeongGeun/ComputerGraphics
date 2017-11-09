/*
		2012136139 최형근
		컴퓨터그래픽스 및 실습 : 과제 05
*/

#include <GL/glut.h>
#include "myDrawing.h"
#include "MyScreen.h"

Matrix4x4 myMat;
MyScreen screen;	// MyScreen 클래스의 객체 screen

// MyDisplay
void MyDisplay() {
	screen.display();
}

// mouseClick
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	screen.mouseClick(Button, State, X, Y);
}

// mouseMove
void MyMouseMove(GLint X, GLint Y) {
	screen.mouseMove(X, Y);
}

// MyTimer : 애니메이션
void MyTimer(int value) {
	Delta = Delta + 0.001;
	glutPostRedisplay();
	glutTimerFunc(40, MyTimer, 1);	// 40ms로 재귀호출
}

// MyMainMenu : 메인메뉴
void MyMainMenu(int entryID) {
	// 각 메뉴가 선택되면 메뉴 변수를 변경
	if(entryID == 0){
		screen.m = 0;
	}
	else if(entryID == 1){ 
		screen.m = 1;
	}
	else if(entryID == 2){ 
		screen.m = 2;
	}
	else if(entryID == 3){ 
		screen.m = 3;
	}
	else if(entryID == 4){  
		screen.m = 4;
	}
	glutPostRedisplay();
}

// MyReShape : 창의 크기가 변해도 크기를 그대로
void MyReshape(int NewWidth, int NewHeight) {

	GLfloat WidthFactor = (GLfloat) NewWidth / (GLfloat) 300;
	GLfloat HeightFactor = (GLfloat) NewHeight / (GLfloat) 300;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor,
		-1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}

// main : 메인 함수
int main() {
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(1000, 1000); 
	glutCreateWindow("Homework #5");
	glClearColor(0, 0, 0, 0);

	// 메인 메뉴들
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("이동", 1);
	glutAddMenuEntry("회전", 2);
	glutAddMenuEntry("크기 변환", 3);
	glutAddMenuEntry("애니메이션", 4);
	glutAddMenuEntry("No Action", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);   // 마우스 오른쪽 버튼으로 메뉴 접근

	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape); 
	glutMouseFunc(MyMouseClick);
	glutMotionFunc(MyMouseMove);
	glutTimerFunc(40, MyTimer, 1);

    glutMainLoop();
    return 0;
}
