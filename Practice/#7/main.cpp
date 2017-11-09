/*
		2012136139 ������
		��ǻ�ͱ׷��Ƚ� �� �ǽ� : ���� 7
*/
#include <gl/glut.h>
#include <stdio.h>

bool bPressed = false;	// ���콺 Ŭ�� ����
float pX, pY;	// ���콺Ŭ�� �� ��ǥ
int dx, dy;	// ���콺 �����϶� ��ǥ
int menu = 0;	// �޴� ����
double size = 1.0;		// ũ�⺯ȯ ����
int Width, Height;	// â�� ����, ���� ũ��

// Menu : �޴� ������ ���� �̵� & ȸ��
void Menu() {
	// �޴� ������ 1�̸� (�̵�)
	if(menu == 1){
		// ��ǥ�� �̵�
		glTranslatef(dx/100.0, -dy/100.0, 0.0);
	}
	// �޴� ������ 2�̸� (ȸ��)
	else if(menu == 2){
		// ��ǥ��� ȸ��
		glRotatef(dx, 0, 1, 0);
		glRotatef(dy, 1, 0, 0);
	}
}

// DrawBody : �κ��� ���� �׸��� �Լ�
void DrawBody() {
	glPushMatrix(); // ��� ���� �ױ�
	{
		glTranslatef(0.0, 0.2, 0.0);	// y������ 0.2 ��ŭ �̵�
		glScalef(1.0, 2.0, 1.0);	// y������ ũ�⸦ 2�踸ŭ �ø�
		glutSolidCube(0.4);	// ���� ���̰� 0.4�� WireCube�� �׸�
	}
	glPopMatrix(); // ��� ���� �ǵ�����
}

// DrawHead : �κ��� �Ӹ��� �׸��� �Լ�
void DrawHead() {
	glPushMatrix(); // ��� ���� �ױ�
	{
		glTranslatef(0.0, 0.8, 0.0);	// y������ 0.8��ŭ �̵�
		glutSolidSphere(0.2, 16, 16);	// �������� 0.2�� WireSphere�� �׸�
	}
	glPopMatrix(); // ��� ���� �ǵ�����
}

// DrawArm : �κ��� �� �� �ٸ��� �׸��� �Լ�
// �Ű������� x��ǥ, y��ǥ, ȸ���� ������ �޴´�.
void DrawArm(float dx, float dy, int angle, double scale) {
	glPushMatrix(); // ��� ���� �ױ�
	{
		glTranslatef(dx, dy, 0.0); // �Ű������� ���� x, y��ǥ�� �̵�
		glRotatef(angle, 0.0, 0.0, 1.0); // �Ű������� ���� ������ z���� �������� ȸ��
		glutSolidSphere(0.1, 16, 16); // �������� 0.1�� WireSphere�� �׸� (����)

		glTranslatef(0.1 + scale/20, 0.0, 0.0); // x������ 0.2��ŭ �̵�
		glScalef(scale, 1.2, 1.2); // x������ 2��, y������ 1.2��, z������ 1.2�� ũ�� ����
		glutSolidCube(0.1); // ���� ���̰� 0.1�� SolidCube�� �׸� (�� or �ٸ�)
	}
	glPopMatrix(); // ��� ���� �ǵ�����
}

// DrawScene : �ٴ��� �׸��� �Լ�
void DrawScene() {
    glColor3f(0.7, 0.7, 0.7); // �� : ȸ��
    glPushMatrix(); // ��� ���� �ױ�
        glTranslatef(0.0, -1.0, 0.0); // y������ -1��ŭ �̵�
        glBegin(GL_QUADS); // GL_QUADS
            glVertex3f(2.0, 0.0, 2.0); // �� ����
            glVertex3f(2.0, 0.0, -2.0); // �� ����
            glVertex3f(-2.0, 0.0, -2.0); // �� ����
            glVertex3f(-2.0, 0.0, 2.0); // �� ����
        glEnd(); // �׸��� ����
    glPopMatrix(); // ��� ���� �ǵ�����
}

// DrawRobot : �κ� ��ü�� �׸��� �Լ�
void DrawRobot(double x) {
	glPushMatrix(); // ��� ���� �ױ�
	{
		Menu(); // Menu
		glScalef(1.0 * x, 1.0 * x, 1.0 * x); // �Ű������� ���� ũ�� ����
		DrawScene(); // �ٴ� �׸���
		glColor3f(0.0, 0.0, 0.5); // �� : �����
		DrawBody();		// ���� �׸���.
		DrawHead();		// �Ӹ��� �׸���.
		DrawArm(0.3, 0.5, 280, 4.0);		// �������� �׸���.
		DrawArm(-0.3, 0.5, 260, 4.0);	// ������ �׸���.
		DrawArm(-0.1, -0.3, 250, 6.0);	// �޴ٸ��� �׸���.
		DrawArm(0.1, -0.3, 290, 6.0);		// �����ٸ��� �׸���.
	}
	glPopMatrix(); // ��� ���� �ǵ�����
}

// MyMainMenu : ���� �޴�
void MyMainMenu(int entryID) {
	if(entryID == 1){	// entryID�� 1�̸�
		menu = 1;		// �޴� ���� = 1
	}
	else if(entryID == 2){		// entryID�� 2�̸�
		menu = 2;			// �޴� ���� = 2
	}
	else if(entryID == 3){		// entryID�� 3�̸�
		menu = 3;			// �޴� ���� = 3
	}
	else if(entryID == 4){		// entryID�� 4�̸�
		menu = 4;			// �޴� ���� = 4
	}
	else if(entryID == 5){		// entryID�� 5�̸�
		exit(0);	// ���α׷� ����
	}
	glutPostRedisplay(); // �ٽ� �׸���.
}

// MyMouseClick : ���콺 Ŭ�� ����
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	// ���콺 ���� ��ư Ŭ����
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		bPressed = true;	// bPressed�� true�� ����
		pX = X; // x��ǥ ����
		pY = Y; // y��ǥ ����
	}
	else
		bPressed = false; // bPressed�� false�� ����
}

// MyMouseMove : ���콺 �̵�
void MyMouseMove(GLint X, GLint Y) {
	// ���콺 ���� ��ư�� ��������
	if( bPressed) {
		dx = X - pX;	// x��ǥ
		dy = Y - pY;	// y��ǥ

		// �޴� ������ 3�̸� (ũ�� ��ȯ)
		if(menu == 3){
			pX = X; // x��ǥ ������
			pY = Y; // y��ǥ ������
			// x��ǥ��� ����� ��ȯ
			size += dx/100.0;
			// �׸��� �ٽ� �׸���.
			DrawRobot(size);
			glFlush(); // ��� ��ɾ ���μ������� ����
		}
		glutPostRedisplay(); // �ٽ� �׸���.
	}
}

// MyDisplay
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);	// ������ ���� �ʱ�ȭ

	// �޴� ������ 4�̸�
	if(menu == 4)
		size = 1.0; // ũ�� �ʱ�ȭ

	// ����Ʈ 1 : ���� �Ʒ�
	glViewport(0, 0, Width/2, Height/2);
    glPushMatrix(); // ��� ���� �ױ�
        gluLookAt(0.0, 0.0, 1.0,   0.0, 0.0, 0.0,   0.0, 1.0, 0.0); // ���� ��ȯ
        DrawRobot(size);	// �κ��� �׸���.
    glPopMatrix(); // ��� ���� �ǵ�����

	// ����Ʈ 2 : ������ �Ʒ�
    glViewport(Width/2, 0, Width/2, Height/2);
    glPushMatrix(); // ��� ���� �ױ�
        gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0, 1.0, 0.0); // ���� ��ȯ
        DrawRobot(size);	// �κ��� �׸���.
    glPopMatrix(); // ��� ���� �ǵ�����

	// ����Ʈ 3 : ���� ��
    glViewport(0, Height/2, Width/2, Height/2);
    glPushMatrix(); // ��� ���� �ױ�
        gluLookAt(0.0, 1.0, 0.0,   0.0, 0.0, 0.0,   0.0, 0.0, -1.0); // ���� ��ȯ
        DrawRobot(size);	// �κ��� �׸���.
    glPopMatrix(); // ��� ���� �ǵ�����

	// ����Ʈ 4 : ������ ��
    glViewport(Width/2, Height/2, Width/2, Height/2);
    glMatrixMode(GL_PROJECTION); // ��ĸ�� : ��������
    glPushMatrix(); // ��� ���� �ױ�
        glLoadIdentity(); // �׵���ķ� �ʱ�ȭ
        gluPerspective(30, 1.0, 3.0, 50.0); // ��Ī�� �������� 
        glMatrixMode(GL_MODELVIEW); // ��ĸ�� : �𵨺�
        glPushMatrix(); // ��� ���� �ױ�
            gluLookAt(6.0, 6.0, 6.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0); // ���� ��ȯ
            DrawRobot(size);	// �κ��� �׸���.
        glPopMatrix(); // ��� ���� �ǵ�����
        glMatrixMode(GL_PROJECTION); // ��ĸ�� : ��������
    glPopMatrix(); // ��� ���� �ǵ�����

	glFlush();	 // ��� ��ɾ ���μ������� ����
}

// main
int main() {
	Width = 500; // â�� ���� ũ��
	Height = 500; // â�� ���� ũ��
	glutInitWindowSize(Width, Height);	// ������ â ũ�� : 500 x 500
	glutCreateWindow("Homework #7");	// ������ â �̸�

	glClearColor(1.0, 1.0, 1.0, 1.0); // ���� �ʱ�ȭ
    glMatrixMode(GL_PROJECTION); // ��ĸ�� : ��������
    glLoadIdentity( ); // �׵���ķ� �ʱ�ȭ

    glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0); // ��������
    glMatrixMode(GL_MODELVIEW); // ��ĸ�� : �𵨺�
    glLoadIdentity( ); // �׵���� �ʱ�ȭ

	// ���� �޴� ����
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("�̵�", 1);	// 1���޴� : 
	glutAddMenuEntry("ȸ��", 2);	// 2���޴� : 
	glutAddMenuEntry("ũ�⺯ȯ", 3);	// 3���޴� : 
	glutAddMenuEntry("�������", 4);	// 4���޴� : 
	glutAddMenuEntry("����", 5);	// 5���޴� : 
    glutAttachMenu(GLUT_RIGHT_BUTTON);	// ���� �޴� ���� ��� : ���콺 ���� ��ư

	glutDisplayFunc(MyDisplay);	// MyDisplay �Լ� ȣ��
	glutMouseFunc(MyMouseClick); // MyMouseClick �Լ� ȣ��
	glutMotionFunc(MyMouseMove); // MyMouseMove �Լ� ȣ��

	glutMainLoop();	// �̺�Ʈ ������ ����
	return 0;
}