#include <stdio.h>
#include <gl/glut.h>

GLfloat firstX, firstY, lastX, lastY; // first point and last point
unsigned char key; // for keyboad callback function
int start_drawing = 0; // 그리기 변수 = 0

// display function
void MyDisplay() {
	glMatrixMode(GL_MODELVIEW); // set modelview mode
	glLoadIdentity();

	// background polygon : 배경 사각형 그리기
	glColor3f(0, 0, 0); // 색 지정
	glBegin(GL_POLYGON); // 사각형 그리기
	// 좌표 지정
	glVertex3f(10, 10, 0);
	glVertex3f(0, 10, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(10, 0, 0); 
	glEnd(); // 그리기 종료

	// grid lines : 줄 그리기
	glColor3f(1, 1, 1); // 색 지정
	for (int i = 0; i < 10; i++) { // 10번 반복
		glBegin(GL_LINES); // 줄 그리기
		// 좌표 지정
		glVertex3f(i + 0.5, 0, 0);
		glVertex3f(i + 0.5, 10, 0);
		glEnd(); // 그리기 종료
		glBegin(GL_LINES); // 줄 그리기
		// 좌표 지정
		glVertex3f(0, i + 0.5, 0);
		glVertex3f(10, i + 0.5, 0);
		glEnd(); // 그리기 종료
	}

	// draw rectangles for pixel line
	if (start_drawing == 1) {
		int fx, fy, lx, ly; // 처음좌표, 끝좌표

		// 좌표 반올림
		fx = (int)(firstX + 0.5);
		fy = (int)(firstY + 0.5);
		lx = (int)(lastX + 0.5);
		ly = (int)(lastY + 0.5);

		// if firstX is less than lastX, exchange their values
		// fix firstX < lastX
		int temp;
		if (lx < fx) { // 끝 x좌표가 처음 x좌표보다 작으면
			// 두 좌표 교체
			temp = fx;
			fx = lx;
			lx = temp;
			temp = fy;
			fy = ly;
			ly = temp;
		}

		// first clicked pixel : 처음 클릭된 픽셀 색칠하기
		glColor3f(0.9, 0.8, 0.8); // 색 지정
		glBegin(GL_POLYGON); // 사각형 그리기
		 // 좌표 지정
		glVertex3f(fx + 0.5, fy + 0.5, 0);
		glVertex3f(fx - 0.5, fy + 0.5, 0);
		glVertex3f(fx - 0.5, fy - 0.5, 0);
		glVertex3f(fx + 0.5, fy - 0.5, 0);
		glEnd(); // 그리기 종료

		// values for Bresenham Algorithm : 브레스넘 알고리즘
		int x = fx, y = fy;
		int dx, dy, incrE, incrNE, D;
		// D : decision Variable, incrE : increment east, incrNE : increment north and east
		dx = lx - fx; // x 증가량
		dy = ly - fy; // y 증가량

		// if dy/dx is less than 1 and not negative
		if (dy < dx && dy >= 0) { // 기울기 < 1 && y 증가량 >= 0
			D = 2 * dy - dx; // F(x+1, y+1/2) = dx - 2dy
			incrE = 2 * dy; // F(x+1, y) - F(x, y) = 2dy
			incrNE = 2 * dy - 2 * dx; // F(x+1, y+1) - F(x, y) = 2dy - 2dx

			while (x < lx) { // 끝좌표에 도달할때까지 반복
				if (D <= 0) { // next mid point is higher than the line
					D += incrE; // 동쪽 이동
					x++; // x 1증가
				}
				else { // next mid point is lower than the line
					D += incrNE; // 북동쪽 이동
					x++; // x 1증가
					y++; // y 1증가
				}
				// drawing pixels : 픽셀 그리기
				glBegin(GL_POLYGON);
				glVertex3f(x + 0.5, y + 0.5, 0);
				glVertex3f(x - 0.5, y + 0.5, 0);
				glVertex3f(x - 0.5, y - 0.5, 0);
				glVertex3f(x + 0.5, y - 0.5, 0);
				glEnd();
			}
		}
		// if dy/dx is more than 1 and not negative
		else if (dy >= dx && dy >= 0) { // 기울기 >= 1 && y 증가량 >= 0
			D = 2 * dx - dy; // 0~45도에서 x와 y를 바꿈
			incrE = 2 * dx;
			incrNE = 2 * dx - 2 * dy;

			while (y < ly) { // 끝좌표에 도달할때까지 반복
				if (D <= 0) { 
					D += incrE; // 동쪽 이동
					y++; // y 1증가
				}
				else {
					D += incrNE; // 북동쪽 이동
					x++; // x 1증가
					y++; // y 1증가
				}
				// 픽셀 그리기
				glBegin(GL_POLYGON);
				glVertex3f(x + 0.5, y + 0.5, 0);
				glVertex3f(x - 0.5, y + 0.5, 0);
				glVertex3f(x - 0.5, y - 0.5, 0);
				glVertex3f(x + 0.5, y - 0.5, 0);
				glEnd();
			}
		}
		// if dy/dx is less than -1 and negative
		else if (-dy >= dx && dy < 0) { // 기울기 >= -1 && y 증가량 < 0
			D = 2 * dx + dy;
			incrE = 2 * dx;
			incrNE = 2 * dx + 2 * dy;

			while (y > ly) { // 끝점에 도달할때까지 반복
				if (D <= 0) {
					D += incrE; // 동쪽이동
					y--; // y 1감소
				}
				else {
					D += incrNE; // 북동쪽이동
					x++; // x 1감소
					y--; // y 1감소
				}
				// 픽셀 그리기
				glBegin(GL_POLYGON);
				glVertex3f(x + 0.5, y + 0.5, 0);
				glVertex3f(x - 0.5, y + 0.5, 0);
				glVertex3f(x - 0.5, y - 0.5, 0);
				glVertex3f(x + 0.5, y - 0.5, 0);
				glEnd();
			}
		}
		// if dy/dx is more than -1 and negative
		else if (-dy < dx && dy < 0) { // 기울기 < -1 && y 증가량 < 0
			D = -2 * dy - dx;
			incrE = -2 * dy;
			incrNE = -2 * dy - 2 * dx;

			while (x < lx) { // 끝점에 도달할때까지 반복
				if (D <= 0) {
					D += incrE; // 동쪽이동
					x++; // x 1증가
				}
				else {
					D += incrNE; // 북동쪽이동
					x++; // x 1증가
					y--; // y 1감소
				}
				// 픽셀 그리기
				glBegin(GL_POLYGON);
				glVertex3f(x + 0.5, y + 0.5, 0);
				glVertex3f(x - 0.5, y + 0.5, 0);
				glVertex3f(x - 0.5, y - 0.5, 0);
				glVertex3f(x + 0.5, y - 0.5, 0);
				glEnd();
			}
		}

		// 마지막 픽셀 그리기
		glBegin(GL_POLYGON);
		glVertex3f(lx + 0.5, ly + 0.5, 0);
		glVertex3f(lx - 0.5, ly + 0.5, 0);
		glVertex3f(lx - 0.5, ly - 0.5, 0);
		glVertex3f(lx + 0.5, ly - 0.5, 0);
		glEnd();

		// a line drawn by a mouse
		if (firstX != lastX || firstY != lastY) { // if the line is just a point, this window doesn't draw it
			glColor3f(0.8, 0.7, 0.9);
			glBegin(GL_LINES);
			glVertex3f(fx, fy, 0); // first point
			glVertex3f(lx, ly, 0); // last point
			glEnd();
		}
	}

	glFlush(); // 명령어 전달
}

// mouse click callback function finding clicked position
void MyMouseClick(GLint button, GLint state, GLint x, GLint y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// convert viewport coordinate to model coordinate
		firstX = x / 30.0; // 처음 x좌표 지정 
		firstY = (300 - y) / 30.0; // 처음 y좌표 지정
		printf("시작 : (%d, %d)\n", (int)(firstX + 0.5), (int)(firstY + 0.5));
	}
	start_drawing = 1; // 그리기 변수 = 1
}

// mouse move callback function finding current position after mouse click
void MyMouseMove(GLint x, GLint y) {
	// convert viewport coordinate to model coordinate
	lastX = x / 30.0; // 끝 x좌표 지정
	lastY = (300 - y) / 30.0; // 끝 y좌표 지정
	printf("　끝 : (%d, %d)\n", (int)(lastX + 0.5), (int)(lastY + 0.5));

	glutPostRedisplay(); // 다시 그리기
}

// keyboard callback function
void MyKeyboard(unsigned char key, int x, int y) {
	if (key == 'q') // q누르면
		exit(0); // 프로그램 종료
	else if (key == 'c') { // c누르면
		start_drawing = 0; // 그리기변수 = 0
		firstX = firstY = lastX = lastY = 0; // 처음좌표, 끝좌표 초기화
	}

	glutPostRedisplay(); // 다시그리기
}

// main 
int main(int argc, char **argv) {
	// initializaing window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);// 창크기 300*300
	glutInitWindowPosition(100, 10); // 창실행위치 100, 10
	glutCreateWindow("Homework #9"); // init 안하고 윈도우부터 만들면 좌표계가 안맞을 수 있으니 꼭 주의하세요.

	glClearColor(0, 0, 0, 1); // 배경색 설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 10, 0, 10, -1, 1); // volume rectangle's length is 10

	glutKeyboardFunc(MyKeyboard); // register keyboard callback function
	glutMouseFunc(MyMouseClick); // register mouse click callback function
	glutMotionFunc(MyMouseMove); // register mouse move callback function after click
	glutDisplayFunc(MyDisplay); // register display callback function
	glutMainLoop();
	return 0;
}