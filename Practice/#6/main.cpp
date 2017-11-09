/*
		2012136139 ������
		��ǻ�ͱ׷��Ƚ� �� �ǽ� : ���� 6-1
*/
#include <gl/glut.h>
#include <stdio.h>

bool bPressed = false;	// ���콺 Ŭ�� ����
float X1, Y1, X2, Y2;	// ��ǥ1(X1, Y1), ��ǥ2(X2, Y2)
bool isLine = true;		// Line�� �׸� ������ Rectangle�� �׸� ������ �Ǵ�

// MyDisplay
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);	// ������ ���� �ʱ�ȭ
	glColor3f(1.0, 1.0, 1.0);		// �� ����

	glBegin(GL_LINE_LOOP);		// LineLoop�� �׸���.

	if(isLine) {		// isLine == true �̸�
		glVertex3f(X1, Y1, 0.0);	// (X1, Y1) ����
		glVertex3f(X2, Y2, 0.0);	// (X2, Y2) ���� LineLoop�� �׸���.
	}
	else {	// isLine == false �̸�
		glVertex3f(X1, Y1, 0.0);	// (X1, Y1)
		glVertex3f(X2, Y1, 0.0);	// (X2, Y1)
		glVertex3f(X2, Y2, 0.0);	// (X2, Y2)
		glVertex3f(X1, Y2, 0.0);	// (X1, Y2)�� 4���� ������ �ϴ� �簢���� �׸���.
	}

	glEnd();	// ���� ������ ��ģ��.
	glFlush();	// ��ɾ ���μ������� ����
}

// mouseClick
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {	// ���콺 ���� ��ư�� Ŭ���ϸ�
			bPressed = true;	// bPressed�� true�� ����
			X1 = (X-150)/150.;	// X1 ��ǥ ���� (������ ��ǥ�� �ƴ� OpenGL ��ǥ�� ����)
			Y1 = (150-Y)/150.;	// Y1 ��ǥ ����
			printf("���� : (%5.2f, %5.2f)\n", X1, Y1);	// �ܼ�â�� ��ǥ ���
		}
		else	// ���콺 ���� ��ư�� Ŭ������ ������
			bPressed = false;	// bPressed�� false�� ����
}

// mouseMove
void MyMouseMove(GLint X, GLint Y) {
	if( bPressed) {	// ���콺 ���� ��ư�� Ŭ���� �����̸�
		X2 = (X-150)/150.;	// X2 ��ǥ ����
		Y2 = (150-Y)/150.;	// Y2 ��ǥ ����
		printf("���� : (%5.2f, %5.2f)\n", X2, Y2);	// �ܼ�â�� ��ǥ ���
		glutPostRedisplay();		// �ٽ� �׸���.
	}
}

// MyMainMenu
void MyMainMenu(int entryID) {
	if(entryID == 1){	// entryID�� 1�̸�
		isLine = true;	// isLine�� true�� ����
	}
	else if(entryID == 2){		// entryID�� 2�̸�
		isLine = false;			// isLine�� false�� ����
	}
	else if(entryID == 3){		// entryID�� 3�̸�
		exit(0);	// ���α׷� ����
	}
	glutPostRedisplay();
}

// main
int main() {
	glutInitWindowSize(300, 300);	// ������ â ������ : 300 * 300
	glutCreateWindow("Homework #6");	// ������ â �̸�

	// ���� �޴� ����
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Draw Line", 1);	// 1���޴� : Draw Line
	glutAddMenuEntry("Draw Rectangle", 2);	// 2���޴� : Draw Rectangle
	glutAddMenuEntry("Exit", 3);	// 3���޴� : Exit
    glutAttachMenu(GLUT_RIGHT_BUTTON);	// ���� �޴� ���� ��� : ���콺 ���� ��ư

	glutDisplayFunc(MyDisplay);	// MyDisplay �Լ� ȣ��
	glutMouseFunc(MyMouseClick);	// MyMouseClick �Լ� ȣ��
	glutMotionFunc(MyMouseMove);	// MyMouseMove �Լ� ȣ��

	glutMainLoop();	// �̺�Ʈ ������ ����
	return 0;
}