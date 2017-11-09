/*
		2012136139 ������
		��ǻ�ͱ׷��Ƚ� �� �ǽ� : ���� 05
*/

#include <GL/glut.h>
#include "myDrawing.h"
#include "MyScreen.h"

Matrix4x4 myMat;
MyScreen screen;	// MyScreen Ŭ������ ��ü screen

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

// MyTimer : �ִϸ��̼�
void MyTimer(int value) {
	Delta = Delta + 0.001;
	glutPostRedisplay();
	glutTimerFunc(40, MyTimer, 1);	// 40ms�� ���ȣ��
}

// MyMainMenu : ���θ޴�
void MyMainMenu(int entryID) {
	// �� �޴��� ���õǸ� �޴� ������ ����
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

// MyReShape : â�� ũ�Ⱑ ���ص� ũ�⸦ �״��
void MyReshape(int NewWidth, int NewHeight) {

	GLfloat WidthFactor = (GLfloat) NewWidth / (GLfloat) 300;
	GLfloat HeightFactor = (GLfloat) NewHeight / (GLfloat) 300;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor,
		-1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}

// main : ���� �Լ�
int main() {
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(1000, 1000); 
	glutCreateWindow("Homework #5");
	glClearColor(0, 0, 0, 0);

	// ���� �޴���
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("�̵�", 1);
	glutAddMenuEntry("ȸ��", 2);
	glutAddMenuEntry("ũ�� ��ȯ", 3);
	glutAddMenuEntry("�ִϸ��̼�", 4);
	glutAddMenuEntry("No Action", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);   // ���콺 ������ ��ư���� �޴� ����

	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape); 
	glutMouseFunc(MyMouseClick);
	glutMotionFunc(MyMouseMove);
	glutTimerFunc(40, MyTimer, 1);

    glutMainLoop();
    return 0;
}
