#include <stdio.h>
#include <gl/glut.h>

GLfloat firstX, firstY, lastX, lastY; // first point and last point
unsigned char key; // for keyboad callback function
int start_drawing = 0; // �׸��� ���� = 0

// display function
void MyDisplay() {
	glMatrixMode(GL_MODELVIEW); // set modelview mode
	glLoadIdentity();

	// background polygon : ��� �簢�� �׸���
	glColor3f(0, 0, 0); // �� ����
	glBegin(GL_POLYGON); // �簢�� �׸���
	// ��ǥ ����
	glVertex3f(10, 10, 0);
	glVertex3f(0, 10, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(10, 0, 0); 
	glEnd(); // �׸��� ����

	// grid lines : �� �׸���
	glColor3f(1, 1, 1); // �� ����
	for (int i = 0; i < 10; i++) { // 10�� �ݺ�
		glBegin(GL_LINES); // �� �׸���
		// ��ǥ ����
		glVertex3f(i + 0.5, 0, 0);
		glVertex3f(i + 0.5, 10, 0);
		glEnd(); // �׸��� ����
		glBegin(GL_LINES); // �� �׸���
		// ��ǥ ����
		glVertex3f(0, i + 0.5, 0);
		glVertex3f(10, i + 0.5, 0);
		glEnd(); // �׸��� ����
	}

	// draw rectangles for pixel line
	if (start_drawing == 1) {
		int fx, fy, lx, ly; // ó����ǥ, ����ǥ

		// ��ǥ �ݿø�
		fx = (int)(firstX + 0.5);
		fy = (int)(firstY + 0.5);
		lx = (int)(lastX + 0.5);
		ly = (int)(lastY + 0.5);

		// if firstX is less than lastX, exchange their values
		// fix firstX < lastX
		int temp;
		if (lx < fx) { // �� x��ǥ�� ó�� x��ǥ���� ������
			// �� ��ǥ ��ü
			temp = fx;
			fx = lx;
			lx = temp;
			temp = fy;
			fy = ly;
			ly = temp;
		}

		// first clicked pixel : ó�� Ŭ���� �ȼ� ��ĥ�ϱ�
		glColor3f(0.9, 0.8, 0.8); // �� ����
		glBegin(GL_POLYGON); // �簢�� �׸���
		 // ��ǥ ����
		glVertex3f(fx + 0.5, fy + 0.5, 0);
		glVertex3f(fx - 0.5, fy + 0.5, 0);
		glVertex3f(fx - 0.5, fy - 0.5, 0);
		glVertex3f(fx + 0.5, fy - 0.5, 0);
		glEnd(); // �׸��� ����

		// values for Bresenham Algorithm : �극���� �˰���
		int x = fx, y = fy;
		int dx, dy, incrE, incrNE, D;
		// D : decision Variable, incrE : increment east, incrNE : increment north and east
		dx = lx - fx; // x ������
		dy = ly - fy; // y ������

		// if dy/dx is less than 1 and not negative
		if (dy < dx && dy >= 0) { // ���� < 1 && y ������ >= 0
			D = 2 * dy - dx; // F(x+1, y+1/2) = dx - 2dy
			incrE = 2 * dy; // F(x+1, y) - F(x, y) = 2dy
			incrNE = 2 * dy - 2 * dx; // F(x+1, y+1) - F(x, y) = 2dy - 2dx

			while (x < lx) { // ����ǥ�� �����Ҷ����� �ݺ�
				if (D <= 0) { // next mid point is higher than the line
					D += incrE; // ���� �̵�
					x++; // x 1����
				}
				else { // next mid point is lower than the line
					D += incrNE; // �ϵ��� �̵�
					x++; // x 1����
					y++; // y 1����
				}
				// drawing pixels : �ȼ� �׸���
				glBegin(GL_POLYGON);
				glVertex3f(x + 0.5, y + 0.5, 0);
				glVertex3f(x - 0.5, y + 0.5, 0);
				glVertex3f(x - 0.5, y - 0.5, 0);
				glVertex3f(x + 0.5, y - 0.5, 0);
				glEnd();
			}
		}
		// if dy/dx is more than 1 and not negative
		else if (dy >= dx && dy >= 0) { // ���� >= 1 && y ������ >= 0
			D = 2 * dx - dy; // 0~45������ x�� y�� �ٲ�
			incrE = 2 * dx;
			incrNE = 2 * dx - 2 * dy;

			while (y < ly) { // ����ǥ�� �����Ҷ����� �ݺ�
				if (D <= 0) { 
					D += incrE; // ���� �̵�
					y++; // y 1����
				}
				else {
					D += incrNE; // �ϵ��� �̵�
					x++; // x 1����
					y++; // y 1����
				}
				// �ȼ� �׸���
				glBegin(GL_POLYGON);
				glVertex3f(x + 0.5, y + 0.5, 0);
				glVertex3f(x - 0.5, y + 0.5, 0);
				glVertex3f(x - 0.5, y - 0.5, 0);
				glVertex3f(x + 0.5, y - 0.5, 0);
				glEnd();
			}
		}
		// if dy/dx is less than -1 and negative
		else if (-dy >= dx && dy < 0) { // ���� >= -1 && y ������ < 0
			D = 2 * dx + dy;
			incrE = 2 * dx;
			incrNE = 2 * dx + 2 * dy;

			while (y > ly) { // ������ �����Ҷ����� �ݺ�
				if (D <= 0) {
					D += incrE; // �����̵�
					y--; // y 1����
				}
				else {
					D += incrNE; // �ϵ����̵�
					x++; // x 1����
					y--; // y 1����
				}
				// �ȼ� �׸���
				glBegin(GL_POLYGON);
				glVertex3f(x + 0.5, y + 0.5, 0);
				glVertex3f(x - 0.5, y + 0.5, 0);
				glVertex3f(x - 0.5, y - 0.5, 0);
				glVertex3f(x + 0.5, y - 0.5, 0);
				glEnd();
			}
		}
		// if dy/dx is more than -1 and negative
		else if (-dy < dx && dy < 0) { // ���� < -1 && y ������ < 0
			D = -2 * dy - dx;
			incrE = -2 * dy;
			incrNE = -2 * dy - 2 * dx;

			while (x < lx) { // ������ �����Ҷ����� �ݺ�
				if (D <= 0) {
					D += incrE; // �����̵�
					x++; // x 1����
				}
				else {
					D += incrNE; // �ϵ����̵�
					x++; // x 1����
					y--; // y 1����
				}
				// �ȼ� �׸���
				glBegin(GL_POLYGON);
				glVertex3f(x + 0.5, y + 0.5, 0);
				glVertex3f(x - 0.5, y + 0.5, 0);
				glVertex3f(x - 0.5, y - 0.5, 0);
				glVertex3f(x + 0.5, y - 0.5, 0);
				glEnd();
			}
		}

		// ������ �ȼ� �׸���
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

	glFlush(); // ��ɾ� ����
}

// mouse click callback function finding clicked position
void MyMouseClick(GLint button, GLint state, GLint x, GLint y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// convert viewport coordinate to model coordinate
		firstX = x / 30.0; // ó�� x��ǥ ���� 
		firstY = (300 - y) / 30.0; // ó�� y��ǥ ����
		printf("���� : (%d, %d)\n", (int)(firstX + 0.5), (int)(firstY + 0.5));
	}
	start_drawing = 1; // �׸��� ���� = 1
}

// mouse move callback function finding current position after mouse click
void MyMouseMove(GLint x, GLint y) {
	// convert viewport coordinate to model coordinate
	lastX = x / 30.0; // �� x��ǥ ����
	lastY = (300 - y) / 30.0; // �� y��ǥ ����
	printf("���� : (%d, %d)\n", (int)(lastX + 0.5), (int)(lastY + 0.5));

	glutPostRedisplay(); // �ٽ� �׸���
}

// keyboard callback function
void MyKeyboard(unsigned char key, int x, int y) {
	if (key == 'q') // q������
		exit(0); // ���α׷� ����
	else if (key == 'c') { // c������
		start_drawing = 0; // �׸��⺯�� = 0
		firstX = firstY = lastX = lastY = 0; // ó����ǥ, ����ǥ �ʱ�ȭ
	}

	glutPostRedisplay(); // �ٽñ׸���
}

// main 
int main(int argc, char **argv) {
	// initializaing window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);// âũ�� 300*300
	glutInitWindowPosition(100, 10); // â������ġ 100, 10
	glutCreateWindow("Homework #9"); // init ���ϰ� ��������� ����� ��ǥ�谡 �ȸ��� �� ������ �� �����ϼ���.

	glClearColor(0, 0, 0, 1); // ���� ����
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