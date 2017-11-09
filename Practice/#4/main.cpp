/*
		2012136139 최형근
		컴퓨터그래픽스 및 실습 : 과제 04
*/
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

int WinWidth = 1000;   // 창의 가로 길이 = 1000
int WinHeight = 500;   // 창의 세로 길이 = 500
bool bPressed = false;   // 마우스 클릭 여부 = false
GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;   // 회전에 필요한 좌표

// 0 = 그리지 않는다.
// 1 = Solid로 그린다.
// 2 = Wire로 그린다.
GLint IsCubeSolid = 0;   // Cube
GLint IsSphereSolid = 0;   // Sphere
GLint IsTorusSolid = 0;   // Torus
GLint IsConeSolid = 0;   // Cone
GLint IsTeapotSolid = 0;   // Teapot

//*** 이름을 출력하는 함수
void Name() {

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

//*** GLUT 객체를 그리는 함수
void Draw() {

	// IsCubeSolid만 1이고 나머지는 0이면 = SolidCube
	if(IsCubeSolid == 1 && IsSphereSolid == 0 && IsTorusSolid == 0 && IsConeSolid == 0 && IsTeapotSolid == 0)
		glutSolidCube(0.5);
	// IsCubeSolid만 2이고 나머지는 0이면 = WireCube
	else if(IsCubeSolid == 2 && IsSphereSolid == 0 && IsTorusSolid == 0 && IsConeSolid == 0 && IsTeapotSolid == 0)
		glutWireCube(0.5);
	// IsSphereSolid만 1이고 나머지는 0이면 = SolidSphere
	else if(IsSphereSolid == 1 && IsCubeSolid == 0 && IsTorusSolid == 0 && IsConeSolid == 0 && IsTeapotSolid == 0)
		glutSolidSphere(0.4, 15, 15);
	// IsSphereSolid만 2이고 나머지는 0이면 = WireSphere
	else if(IsSphereSolid == 2 && IsCubeSolid == 0 && IsTorusSolid == 0 && IsConeSolid == 0 && IsTeapotSolid == 0)
		glutWireSphere(0.4, 15, 15);
	// IsTorusSolid만 1이고 나머지는 0이면 = SolidTorus
	else if(IsTorusSolid == 1 && IsSphereSolid == 0 && IsCubeSolid == 0 && IsConeSolid == 0 && IsTeapotSolid == 0)
		glutSolidTorus(0.2, 0.5, 40, 20);
	// IsTorusSolid만 2이고 나머지는 0이면 = WireTorus
	else if(IsTorusSolid == 2 && IsSphereSolid == 0 && IsCubeSolid == 0 && IsConeSolid == 0 && IsTeapotSolid == 0)
		glutWireTorus(0.2, 0.5, 40, 20);
	// IsConeSolid만 1이고 나머지는 0이면 = SolidCone
	else if(IsConeSolid == 1 && IsSphereSolid == 0 && IsTorusSolid == 0 && IsCubeSolid == 0 && IsTeapotSolid == 0)
		glutSolidCone(0.5, 0.5, 40, 20);
	// IsConeSolid만 2이고 나머지는 0이면 = WireCone
	else if(IsConeSolid == 2 && IsSphereSolid == 0 && IsTorusSolid == 0 && IsCubeSolid == 0 && IsTeapotSolid == 0)
		glutWireCone(0.5, 0.5, 40, 20);
	// IsTeapotSolid만 1이고 나머지는 0이면 = SolidTeapot
	else if(IsTeapotSolid == 1 && IsSphereSolid == 0 && IsTorusSolid == 0 && IsConeSolid == 0 && IsCubeSolid == 0)
		glutSolidTeapot(0.5);
	// IsTeapotSolid만 2이고 나머지는 0이면 = WireTeapot
	else if(IsTeapotSolid == 2 && IsSphereSolid == 0 && IsTorusSolid == 0 && IsConeSolid == 0 && IsCubeSolid == 0)
		glutWireTeapot(0.5);

	glFlush();   // glFlush
}

// MyDisplay
void MyDisplay() {

	glClear(GL_COLOR_BUFFER_BIT);   //컬러버퍼에 초기화 색을 가함
	
	glViewport(0, 0, WinWidth/2, WinHeight);   // 좌측 뷰포트
	glColor3f(0.3, 0.3, 0.3);   // 회색
	Name();   // 이름 쓰기

	glViewport(WinWidth/2, 0, WinWidth/2, WinHeight);   // 우측 뷰포트
	glColor3f(0.5, 0.0, 0.5);   // 보라색
	Draw();   // 객체 그리기
}

// MyReshape : 창의 크기가 변해도 이름, 객체의 크기는 그대로
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
	// 마우스 왼쪽버튼이 눌렸으면
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		bPressed = true;
        TopLeftX = X;
        TopLeftY = Y;
    }
	// 마우스 왼쪽버튼이 안눌렸으면
	else bPressed = false;
}

// MyMouseMove
void MyMouseMove(GLint X, GLint Y) {
	if( bPressed ) {   // bPressed == true
		int dx = X - BottomRightX;
		int dy = Y - BottomRightY;
		BottomRightX = X; 
		BottomRightY = Y;
		glRotatef( dx, 0.0, 1.0, 0.0 );   // 회전
		glRotatef( dy, 1.0, 0.0, 0.0 );
		glutPostRedisplay();
	}
}

// MyMainMenu
void MyMainMenu(int entryID) {
	if (entryID == 6) 
		exit(0);   // Exit
}

// Cube를 그리기 위한 서브메뉴함수
void CubeMenu(int entryID) {
	if(entryID == 1)
		IsCubeSolid = 1;   // SolidCube
	else if(entryID == 2)
		IsCubeSolid = 2;   // WireCube

	// Cube를 제외한 나머지는 0
	IsSphereSolid = 0;
	IsTorusSolid = 0;
	IsConeSolid = 0;
	IsTeapotSolid = 0;

	glutPostRedisplay();   // 다시 그리기
}

// Sphere를 그리기 위한 서브메뉴함수
void SphereMenu(int entryID) {
	if(entryID == 1)
		IsSphereSolid = 1;   // SolidSphere
	else if(entryID == 2)
		IsSphereSolid = 2;   // WireSphere

	// Sphere를 제외한 나머지는 0
	IsCubeSolid = 0;
	IsTorusSolid = 0;
	IsConeSolid = 0;
	IsTeapotSolid = 0;

	glutPostRedisplay();
}

// Torus를 그리기 위한 서브메뉴함수
void TorusMenu(int entryID) {
	if(entryID == 1)
		IsTorusSolid = 1;   // SolidTorus
	else if(entryID == 2)
		IsTorusSolid = 2;   // WireTorus

	// Torus를 제외한 나머지는 0
	IsSphereSolid = 0;
	IsCubeSolid = 0;
	IsConeSolid = 0;
	IsTeapotSolid = 0;

	glutPostRedisplay();
}

// Cone를 그리기 위한 서브메뉴함수
void ConeMenu(int entryID) {
	if(entryID == 1)
		IsConeSolid = 1;   // SolidCone
	else if(entryID == 2)
		IsConeSolid = 2;   // WireCone

	// Cone을 제외한 나머지는 0
	IsSphereSolid = 0;
	IsTorusSolid = 0;
	IsCubeSolid = 0;
	IsTeapotSolid = 0;

	glutPostRedisplay();
}

// Teapot를 그리기 위한 서브메뉴함수
void TeapotMenu(int entryID) {
	if(entryID == 1)
		IsTeapotSolid = 1;   // SolidTeapot
	else if(entryID == 2)
		IsTeapotSolid = 2;   // WireTeapot

	// Teapot을 제외한 나머지는 0
	IsSphereSolid = 0;
	IsTorusSolid = 0;
	IsConeSolid = 0;
	IsCubeSolid = 0;

	glutPostRedisplay();
}

// MyKeyboard : 키 입력에 따라 이벤트를 주는 함수
void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
	switch (KeyPressed){
	// 'Q', 'q', esc를 누르면 종료
	case 'Q':
		exit(0); break;
	case 'q':
		exit(0); break;
	case 27:             //'esc' 키의 아스키 코드 값
		exit(0); break;
	// 'C', 'c'를 누르면 SolidCube를 그린다.
	case 'C' : 
		CubeMenu(1); break;
	case 'c' : 
		CubeMenu(1); break;
	// 'S', 's'를 누르면 SolidSphere를 그린다.
	case 'S' :
		SphereMenu(1); break;
	case 's' :
		SphereMenu(1); break;
	// 'T', 't'를 누르면 SolidTorus를 그린다.
	case 'T' : 
		TorusMenu(1); break;
	case 't' :
		TorusMenu(1); break;
	// 'N', 'n'를 누르면 SolidCone를 그린다.
	case 'N' : 
		ConeMenu(1); break;
	case 'n' :
		ConeMenu(1); break;
	// 'P', 'p'를 누르면 SolidTeapot를 그린다.
	case 'P' : 
		TeapotMenu(1); break;
	case 'p' :
		TeapotMenu(1); break;
	}
	glFlush();
}

// main 
int main(int argc, char** argv) {

	glutInit(&argc,argv);   // 윈도우 시스템과 연결
	glutInitDisplayMode(GLUT_RGB);   // 그리기 표면의 주요 특징 결정
	glutInitWindowSize(WinWidth, WinHeight);   // 창의 크기 설정
	glutInitWindowPosition(0, 0);   // 창의 위치 설정

	glutCreateWindow("Homework #4");   // 창의 이름

	glClearColor(1.0, 1.0, 1.0, 1.0);   //초기화 색은 백색

	// Cube의 서브메뉴
	GLint CubeMenuID = glutCreateMenu(CubeMenu);
	glutAddMenuEntry("Solid", 1);
	glutAddMenuEntry("Wire", 2);

	// Sphere의 서브메뉴
	GLint SphereMenuID = glutCreateMenu(SphereMenu);
	glutAddMenuEntry("Solid", 1);
	glutAddMenuEntry("Wire", 2);

	// Torus의 서브메뉴
	GLint TorusMenuID = glutCreateMenu(TorusMenu);
	glutAddMenuEntry("Solid", 1);
	glutAddMenuEntry("Wire", 2);

	// Cone의 서브메뉴
	GLint ConeMenuID = glutCreateMenu(ConeMenu);
	glutAddMenuEntry("Solid", 1);
	glutAddMenuEntry("Wire", 2);

	// Teapot의 서브메뉴
	GLint TeapotMenuID = glutCreateMenu(TeapotMenu);
	glutAddMenuEntry("Solid", 1);
	glutAddMenuEntry("Wire", 2);

	// 메인메뉴들
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddSubMenu("Cube", CubeMenuID);
	glutAddSubMenu("Sphere", SphereMenuID);
	glutAddSubMenu("Torus", TorusMenuID);
	glutAddSubMenu("Corn", ConeMenuID);
	glutAddSubMenu("Teapot", TeapotMenuID);
    glutAddMenuEntry("Exit", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);   // 마우스 오른쪽 버튼으로 메뉴 접근

	glutDisplayFunc(MyDisplay);   // MyDisplay
	glutReshapeFunc(MyReshape);   // MyReshape
	glutKeyboardFunc(MyKeyboard);   // MyKeyboard
	glutMouseFunc(MyMouseClick);   // MyMouseClick
    glutMotionFunc(MyMouseMove);   // MyMouseMove

	glutMainLoop();   // 메시지가 들어올 때마다 콜백 함수 호출
	return 0;
}