/*
		2012136139 ������
		��ǻ�ͱ׷��Ƚ� �� �ǽ� : ���� 04
*/
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

int WinWidth = 1000;   // â�� ���� ���� = 1000
int WinHeight = 500;   // â�� ���� ���� = 500
bool bPressed = false;   // ���콺 Ŭ�� ���� = false
GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;   // ȸ���� �ʿ��� ��ǥ

// 0 = �׸��� �ʴ´�.
// 1 = Solid�� �׸���.
// 2 = Wire�� �׸���.
GLint IsCubeSolid = 0;   // Cube
GLint IsSphereSolid = 0;   // Sphere
GLint IsTorusSolid = 0;   // Torus
GLint IsConeSolid = 0;   // Cone
GLint IsTeapotSolid = 0;   // Teapot

//*** �̸��� ����ϴ� �Լ�
void Name() {

	//********** �� **********

	glBegin(GL_QUADS);	// ���� ������ �����Ѵ�.
	// GL_QUADS : �簢��

	glVertex3f(-0.85, 0.5, 0.0);	// ������ �����Ѵ�. (3����)
	glVertex3f(-0.65, 0.5, 0.0);
	glVertex3f(-0.65, 0.55, 0.0);
	glVertex3f(-0.85, 0.55, 0.0);

	glEnd();	// ���� ������ ������.

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

	//********** �� **********

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

	//********** �� **********
	glBegin(GL_QUADS);

	glVertex3f(-0.45, 0.5, 0.0);
	glVertex3f(-0.4, 0.5, 0.0);
	glVertex3f(-0.4, -0.2, 0.0);
	glVertex3f(-0.45, -0.2, 0.0);

	glEnd();

	//********** �� **********

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
	
	//********** �� **********

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

	//********** �� **********

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

	//********** �� **********

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

	//********** �� **********

	glBegin(GL_QUADS);

	glVertex3f(0.45, 0.25, 0.0);
	glVertex3f(0.95, 0.25, 0.0);
	glVertex3f(0.95, 0.2, 0.0);
	glVertex3f(0.45, 0.2, 0.0);

	glEnd();

	//********** �� **********

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

	glFlush();		// ������� ���� ��ɾ���� ���μ������� ����
}

//*** GLUT ��ü�� �׸��� �Լ�
void Draw() {

	// IsCubeSolid�� 1�̰� �������� 0�̸� = SolidCube
	if(IsCubeSolid == 1 && IsSphereSolid == 0 && IsTorusSolid == 0 && IsConeSolid == 0 && IsTeapotSolid == 0)
		glutSolidCube(0.5);
	// IsCubeSolid�� 2�̰� �������� 0�̸� = WireCube
	else if(IsCubeSolid == 2 && IsSphereSolid == 0 && IsTorusSolid == 0 && IsConeSolid == 0 && IsTeapotSolid == 0)
		glutWireCube(0.5);
	// IsSphereSolid�� 1�̰� �������� 0�̸� = SolidSphere
	else if(IsSphereSolid == 1 && IsCubeSolid == 0 && IsTorusSolid == 0 && IsConeSolid == 0 && IsTeapotSolid == 0)
		glutSolidSphere(0.4, 15, 15);
	// IsSphereSolid�� 2�̰� �������� 0�̸� = WireSphere
	else if(IsSphereSolid == 2 && IsCubeSolid == 0 && IsTorusSolid == 0 && IsConeSolid == 0 && IsTeapotSolid == 0)
		glutWireSphere(0.4, 15, 15);
	// IsTorusSolid�� 1�̰� �������� 0�̸� = SolidTorus
	else if(IsTorusSolid == 1 && IsSphereSolid == 0 && IsCubeSolid == 0 && IsConeSolid == 0 && IsTeapotSolid == 0)
		glutSolidTorus(0.2, 0.5, 40, 20);
	// IsTorusSolid�� 2�̰� �������� 0�̸� = WireTorus
	else if(IsTorusSolid == 2 && IsSphereSolid == 0 && IsCubeSolid == 0 && IsConeSolid == 0 && IsTeapotSolid == 0)
		glutWireTorus(0.2, 0.5, 40, 20);
	// IsConeSolid�� 1�̰� �������� 0�̸� = SolidCone
	else if(IsConeSolid == 1 && IsSphereSolid == 0 && IsTorusSolid == 0 && IsCubeSolid == 0 && IsTeapotSolid == 0)
		glutSolidCone(0.5, 0.5, 40, 20);
	// IsConeSolid�� 2�̰� �������� 0�̸� = WireCone
	else if(IsConeSolid == 2 && IsSphereSolid == 0 && IsTorusSolid == 0 && IsCubeSolid == 0 && IsTeapotSolid == 0)
		glutWireCone(0.5, 0.5, 40, 20);
	// IsTeapotSolid�� 1�̰� �������� 0�̸� = SolidTeapot
	else if(IsTeapotSolid == 1 && IsSphereSolid == 0 && IsTorusSolid == 0 && IsConeSolid == 0 && IsCubeSolid == 0)
		glutSolidTeapot(0.5);
	// IsTeapotSolid�� 2�̰� �������� 0�̸� = WireTeapot
	else if(IsTeapotSolid == 2 && IsSphereSolid == 0 && IsTorusSolid == 0 && IsConeSolid == 0 && IsCubeSolid == 0)
		glutWireTeapot(0.5);

	glFlush();   // glFlush
}

// MyDisplay
void MyDisplay() {

	glClear(GL_COLOR_BUFFER_BIT);   //�÷����ۿ� �ʱ�ȭ ���� ����
	
	glViewport(0, 0, WinWidth/2, WinHeight);   // ���� ����Ʈ
	glColor3f(0.3, 0.3, 0.3);   // ȸ��
	Name();   // �̸� ����

	glViewport(WinWidth/2, 0, WinWidth/2, WinHeight);   // ���� ����Ʈ
	glColor3f(0.5, 0.0, 0.5);   // �����
	Draw();   // ��ü �׸���
}

// MyReshape : â�� ũ�Ⱑ ���ص� �̸�, ��ü�� ũ��� �״��
void MyReshape(int NewWidth, int NewHeight) {
	WinWidth = NewWidth;
	WinHeight = NewHeight;

	GLfloat WidthFactor = (GLfloat) NewWidth / (GLfloat) 300;
	GLfloat HeightFactor = (GLfloat) NewHeight / (GLfloat) 300;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor,
		-1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}

// MyMouseClick
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	// ���콺 ���ʹ�ư�� ��������
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		bPressed = true;
        TopLeftX = X;
        TopLeftY = Y;
    }
	// ���콺 ���ʹ�ư�� �ȴ�������
	else bPressed = false;
}

// MyMouseMove
void MyMouseMove(GLint X, GLint Y) {
	if( bPressed ) {   // bPressed == true
		int dx = X - BottomRightX;
		int dy = Y - BottomRightY;
		BottomRightX = X; 
		BottomRightY = Y;
		glRotatef( dx, 0.0, 1.0, 0.0 );   // ȸ��
		glRotatef( dy, 1.0, 0.0, 0.0 );
		glutPostRedisplay();
	}
}

// MyMainMenu
void MyMainMenu(int entryID) {
	if (entryID == 6) 
		exit(0);   // Exit
}

// Cube�� �׸��� ���� ����޴��Լ�
void CubeMenu(int entryID) {
	if(entryID == 1)
		IsCubeSolid = 1;   // SolidCube
	else if(entryID == 2)
		IsCubeSolid = 2;   // WireCube

	// Cube�� ������ �������� 0
	IsSphereSolid = 0;
	IsTorusSolid = 0;
	IsConeSolid = 0;
	IsTeapotSolid = 0;

	glutPostRedisplay();   // �ٽ� �׸���
}

// Sphere�� �׸��� ���� ����޴��Լ�
void SphereMenu(int entryID) {
	if(entryID == 1)
		IsSphereSolid = 1;   // SolidSphere
	else if(entryID == 2)
		IsSphereSolid = 2;   // WireSphere

	// Sphere�� ������ �������� 0
	IsCubeSolid = 0;
	IsTorusSolid = 0;
	IsConeSolid = 0;
	IsTeapotSolid = 0;

	glutPostRedisplay();
}

// Torus�� �׸��� ���� ����޴��Լ�
void TorusMenu(int entryID) {
	if(entryID == 1)
		IsTorusSolid = 1;   // SolidTorus
	else if(entryID == 2)
		IsTorusSolid = 2;   // WireTorus

	// Torus�� ������ �������� 0
	IsSphereSolid = 0;
	IsCubeSolid = 0;
	IsConeSolid = 0;
	IsTeapotSolid = 0;

	glutPostRedisplay();
}

// Cone�� �׸��� ���� ����޴��Լ�
void ConeMenu(int entryID) {
	if(entryID == 1)
		IsConeSolid = 1;   // SolidCone
	else if(entryID == 2)
		IsConeSolid = 2;   // WireCone

	// Cone�� ������ �������� 0
	IsSphereSolid = 0;
	IsTorusSolid = 0;
	IsCubeSolid = 0;
	IsTeapotSolid = 0;

	glutPostRedisplay();
}

// Teapot�� �׸��� ���� ����޴��Լ�
void TeapotMenu(int entryID) {
	if(entryID == 1)
		IsTeapotSolid = 1;   // SolidTeapot
	else if(entryID == 2)
		IsTeapotSolid = 2;   // WireTeapot

	// Teapot�� ������ �������� 0
	IsSphereSolid = 0;
	IsTorusSolid = 0;
	IsConeSolid = 0;
	IsCubeSolid = 0;

	glutPostRedisplay();
}

// MyKeyboard : Ű �Է¿� ���� �̺�Ʈ�� �ִ� �Լ�
void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
	switch (KeyPressed){
	// 'Q', 'q', esc�� ������ ����
	case 'Q':
		exit(0); break;
	case 'q':
		exit(0); break;
	case 27:             //'esc' Ű�� �ƽ�Ű �ڵ� ��
		exit(0); break;
	// 'C', 'c'�� ������ SolidCube�� �׸���.
	case 'C' : 
		CubeMenu(1); break;
	case 'c' : 
		CubeMenu(1); break;
	// 'S', 's'�� ������ SolidSphere�� �׸���.
	case 'S' :
		SphereMenu(1); break;
	case 's' :
		SphereMenu(1); break;
	// 'T', 't'�� ������ SolidTorus�� �׸���.
	case 'T' : 
		TorusMenu(1); break;
	case 't' :
		TorusMenu(1); break;
	// 'N', 'n'�� ������ SolidCone�� �׸���.
	case 'N' : 
		ConeMenu(1); break;
	case 'n' :
		ConeMenu(1); break;
	// 'P', 'p'�� ������ SolidTeapot�� �׸���.
	case 'P' : 
		TeapotMenu(1); break;
	case 'p' :
		TeapotMenu(1); break;
	}
	glFlush();
}

// main 
int main(int argc, char** argv) {

	glutInit(&argc,argv);   // ������ �ý��۰� ����
	glutInitDisplayMode(GLUT_RGB);   // �׸��� ǥ���� �ֿ� Ư¡ ����
	glutInitWindowSize(WinWidth, WinHeight);   // â�� ũ�� ����
	glutInitWindowPosition(0, 0);   // â�� ��ġ ����

	glutCreateWindow("Homework #4");   // â�� �̸�

	glClearColor(1.0, 1.0, 1.0, 1.0);   //�ʱ�ȭ ���� ���

	// Cube�� ����޴�
	GLint CubeMenuID = glutCreateMenu(CubeMenu);
	glutAddMenuEntry("Solid", 1);
	glutAddMenuEntry("Wire", 2);

	// Sphere�� ����޴�
	GLint SphereMenuID = glutCreateMenu(SphereMenu);
	glutAddMenuEntry("Solid", 1);
	glutAddMenuEntry("Wire", 2);

	// Torus�� ����޴�
	GLint TorusMenuID = glutCreateMenu(TorusMenu);
	glutAddMenuEntry("Solid", 1);
	glutAddMenuEntry("Wire", 2);

	// Cone�� ����޴�
	GLint ConeMenuID = glutCreateMenu(ConeMenu);
	glutAddMenuEntry("Solid", 1);
	glutAddMenuEntry("Wire", 2);

	// Teapot�� ����޴�
	GLint TeapotMenuID = glutCreateMenu(TeapotMenu);
	glutAddMenuEntry("Solid", 1);
	glutAddMenuEntry("Wire", 2);

	// ���θ޴���
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddSubMenu("Cube", CubeMenuID);
	glutAddSubMenu("Sphere", SphereMenuID);
	glutAddSubMenu("Torus", TorusMenuID);
	glutAddSubMenu("Corn", ConeMenuID);
	glutAddSubMenu("Teapot", TeapotMenuID);
    glutAddMenuEntry("Exit", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);   // ���콺 ������ ��ư���� �޴� ����

	glutDisplayFunc(MyDisplay);   // MyDisplay
	glutReshapeFunc(MyReshape);   // MyReshape
	glutKeyboardFunc(MyKeyboard);   // MyKeyboard
	glutMouseFunc(MyMouseClick);   // MyMouseClick
    glutMotionFunc(MyMouseMove);   // MyMouseMove

	glutMainLoop();   // �޽����� ���� ������ �ݹ� �Լ� ȣ��
	return 0;
}