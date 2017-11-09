#include <gl/glut.h>
#include <stdio.h>

int Width= 300, Height = 300; // 창 가로, 세로 크기 = 300, 300
bool bPressed = false;	// 마우스 클릭 여부
float X1, Y1, X2, Y2;	// 좌표1(X1, Y1), 좌표2(X2, Y2)
bool isCohen = false; // 절단 여부

#define LEFT_EDGE  0x1 // 왼쪽 영역
#define RIGHT_EDGE 0x2 // 오른쪽 영역
#define BOTTOM_EDGE 0x4 // 아래쪽 영역
#define TOP_EDGE   0x8 // 위쪽 영역

#define INSIDE(a)  (!a) // 점의 NOT 연산
#define REJECT(a,b) (a&b) // 양끝점의 영역코드를 AND연산했을 때 0000이 아닌 경우
#define ACCEPT(a,b) (!(a|b)) // 양끝점의 영역코드가 모두 0000인 경우

// x, y좌표를 갖는 구조체
typedef struct position {
	double x; // x 좌표
	double y; // y 좌표
}Pos;
 
Pos winMin = {-0.33, -0.33}; // 윈도우 min 좌표
Pos winMax = {0.33, 0.33}; // 윈도우 max 좌표

// 점의 영역을 결정하는 함수
unsigned char encode (Pos pt)
{
	unsigned char code=0x00; // 코드 : 내부 점으로 초기화

	// 점의 x좌표가 윈도우의 min.x좌표보다 작으면
	if (pt.x < winMin.x)
		code = code | LEFT_EDGE; // 왼쪽 영역
	// 점의 x좌표가 윈도우의 max.x좌표보다 크면
	if (pt.x > winMax.x)
		code = code | RIGHT_EDGE; // 오른쪽 영역
	// 점의 y좌표가 윈도우의 min.y좌표보다 작으면
	if (pt.y < winMin.y)
		code = code | BOTTOM_EDGE; // 아래쪽 영역
	// 점의 y좌표가 윈도우의 max.y좌표보다 크면
	if (pt.y > winMax.y)
		code = code | TOP_EDGE; // 위쪽 영역

	return (code); // 코드 반환
}

// 두 점을 바꾸는 함수
void swapPts (Pos *p1, Pos *p2)
{
	Pos tmp;
	tmp = *p1; 
	*p1 = *p2; 
	*p2 = tmp;
}

// 두 점의 코드를 바꾸는 함수
void swapCodes (unsigned char * c1, unsigned char * c2)
{
	unsigned char tmp;
	tmp = *c1; 
	*c1 = *c2; 
	*c2 = tmp;
}

// 코헨-서덜랜드 알고리즘을 통해 절단하는 함수
void clipLine (Pos p1, Pos p2)
{
	unsigned char code1, code2; // 점1의 코드, 점2의 코드
	int done = false; // 절단 완료 여부
	int draw = false; // 그림을 그릴지 여부
	float m;
 
	while (!done) { // 절단이 완료되지 않았으면
		code1 = encode (p1); // 점1의 코드 추출 후 저장
		code2 = encode (p2); // 점2의 코드 추출 후 저장
		// 두 점을 OR연산 했을 때 결과가 0이면 두 점이 내부에 있다.
		if (ACCEPT (code1, code2)) { // OR, NOT연산 결과가 0이 아니면
			done = true; // 절단 완료
			draw = true; // 그림을 그린다.
		}
		// 두 점을 AND연산 했을 때 결과가 0이 아니라면 두 점이 외부에 있다.
		else if (REJECT (code1, code2))  // AND연산 결과가 0이 아니면
			done = true; // 절단 완료
		else {
			/* Ensure that p1 is outside window */  
			if (INSIDE (code1)) { // 점1이 영역 외부에 있다면
				swapPts (&p1, &p2); // 점1과 점2를 바꾼다.
				swapCodes (&code1, &code2); // 점1과 점2의 코드를 바꾼다.
			}
			/* Use slope (m) to find line-clipEdge intersections */  
			if (p2.x != p1.x) // 점1의 x좌표와 점2의 x좌표가 다르면
				m = (p2.y - p1.y) / (p2.x - p1.x); // m = 두 점의 기울기

			if (code1 & LEFT_EDGE) { // 점1이 왼쪽 영역에 있으면
				p1.y += (winMin.x - p1.x) * m;
				p1.x = winMin.x; 
			}
			else if (code1 & RIGHT_EDGE) { // 점1이 오른쪽 영역에 있으면
				p1.y += (winMax.x - p1.x) * m;  
				p1.x = winMax.x;
			}
			else if (code1 & BOTTOM_EDGE) { // 점1이 아래쪽 영역에 있으면
				/* Need to update p1.x for non-vertical lines only */  
				if (p2.x != p1.x)
					p1.x += (winMin.y - p1.y) / m;
				p1.y = winMin.y;
			}
			else if (code1 & TOP_EDGE) { // 점1이 위쪽 영역에 있으면
				if (p2.x != p1.x) p1.x += (winMax.y - p1.y) / m;  
				p1.y = winMax.y;
			}
		}
	}
	if (draw) // draw == true
		glBegin(GL_LINE_LOOP); // LineLoop을 그린다.

		glVertex3f(p1.x, p1.y, 0.0); // (X1, Y1) 부터
		glVertex3f(p2.x, p2.y, 0.0); // (X2, Y2) 까지 LineLoop을 그린다.

		glEnd(); // 정점 선언을 마친다.
}

// MyDisplay
void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);	// 프레임 버퍼 초기화
	glColor3f(0.0, 0.0, 0.0);		// 색 지정 : 검은색

	glBegin(GL_LINE_LOOP); // 그리기 시작 : 라인 루프

	// 좌표 지정
	glVertex3f(-0.33, 0.33, 0.0);
	glVertex3f(0.33, 0.33, 0.0);
	glVertex3f(0.33, -0.33, 0.0);
	glVertex3f(-0.33, -0.33, 0.0);

	glEnd(); // 그리기 종료

	glColor3f(1.0, 0.0, 0.0); // 색 지정 : 빨간색

	if(isCohen == false) // isCohen == false이면
	{
		glBegin(GL_LINE_LOOP);	 // LineLoop을 그린다.

		glVertex3f(X1, Y1, 0.0); // (X1, Y1) 부터
		glVertex3f(X2, Y2, 0.0); // (X2, Y2) 까지 LineLoop을 그린다.

		glEnd(); // 정점 선언을 마친다.
	}
	else // isCohen == true이면
	{
		Pos d1 = {X1, Y1}; // 점1
		Pos d2 = {X2, Y2}; // 점2
		clipLine(d1, d2); // 점1, 점2에 대해 절단
		isCohen = false; // isCohen을 false로 변경
	}

	glFlush(); // 모든 명령어를 프로세서에게 전달
}

// mouseClick
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) { // 마우스 왼쪽 버튼을 클릭하면
			bPressed = true; // bPressed를 true로 지정
			X1 = (X-150)/150.; // X1 좌표 설정 (윈도우 좌표가 아닌 OpenGL 좌표로 변경)
			Y1 = (150-Y)/150.; // Y1 좌표 설정
		}
		else	// 마우스 왼쪽 버튼을 클릭하지 않으면
			bPressed = false;	// bPressed를 false로 지정
}

// mouseMove
void MyMouseMove(GLint X, GLint Y) {
	if( bPressed) { // 마우스 왼쪽 버튼이 클릭된 상태이면
		X2 = (X-150)/150.; // X2 좌표 설정
		Y2 = (150-Y)/150.; // Y2 좌표 설정
		//printf("%.2f %2.f\n", X2, Y2);
		glutPostRedisplay();	 // 다시 그린다.
	}
}

// MyKeyboard
void MyKeyboard(unsigned char KeyPressed, int X, int Y)
{
	switch (KeyPressed){ // 키보드가 눌렸으면
    case 'c': // 눌린 키가 'c'이면
		isCohen = true; // isCohen을 true로 변경
        break;
    case 'C': // 눌린 키가 'C'이면
		isCohen = true; // isCohen을 true로 변경
        break;
    }
	glutPostRedisplay(); // 다시 그린다.
}

// main
int main() 
{
	glutInitWindowSize(Width, Height); // 윈도우 창 크기 : 300 * 300
	glutCreateWindow("Homework #8"); // 윈도우 창 이름

	glClearColor(1.0, 1.0, 1.0, 0.0); // 배경색 초기화

	glutDisplayFunc(MyDisplay); // MyDisplay 함수 호출
	glutKeyboardFunc(MyKeyboard); // MyKeyboard 함수 호출
	glutMouseFunc(MyMouseClick); // MyMouseClick 함수 호출
	glutMotionFunc(MyMouseMove); // MyMouseMove 함수 호출

	glutMainLoop(); // 이벤트 루프로 진입
	return 0;
}