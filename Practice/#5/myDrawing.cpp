#include <GL/glut.h>

//*** ����
void drawBody(double x)
{
	glPushMatrix();
	{
		glColor3f(0.8, 0.8, 0.8);
		glScalef(1.0+x, 6.2+x, 1.0+x);
		glutSolidCube (0.1);
	}
	glPopMatrix();
}

//*** �Ӹ�
void drawHead(double x)
{
	glPushMatrix();
	{
		glColor3f(0.8, 0.8, 0.8);
		glScalef(1+x, 1+x, 1+x);
		glTranslatef(0.0, 0.5, 0.0);
		glutSolidSphere(0.2, 16, 16);
	}
	glPopMatrix();
}

//*** �ٸ�
void drawLeg(double x)
{
	glPushMatrix();
	{
		glColor3f(1, 0.95, 0);
		glScalef(1+x, 1+x, 1+x);
		glTranslatef(0.0, -0.25, 0.25);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glutSolidTorus(0.1, 0.25, 16, 16);
	}
	glPopMatrix();
}

//*** ����
void drawPants(double x)
{
	glPushMatrix();
	{
		glColor3f(1, 0, 0);
		glTranslatef(0.0, -0.15, 0.15);
		glRotatef(-45, 1, 0, 0);
		glScalef(0.3+x, 0.5+x, 0.05+x);
		glutSolidCube(0.5);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(0.0, -0.35, 0.23);
		glScalef(0.3+x, 0.5+x, 0.05+x);
		glutSolidCube(0.5);
	}
	glPopMatrix();
}

//*** ����
void drawBall(double x)
{
	glPushMatrix();
	{
		glColor3f(1, 1, 0.25);
		glScalef(1+x, 1+x, 1+x);
		glTranslatef(0.0, 1.0, -0.33);
		glutSolidSphere(0.1, 16, 16);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glColor3f(1, 1, 0.25);
		glScalef(1+x, 1+x, 1+x);
		glTranslatef(0.4, 0.7, -0.33);
		glutSolidSphere(0.1, 16, 16);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glColor3f(1, 1, 0.25);
		glScalef(1+x, 1+x, 1+x);
		glTranslatef(0.4, 0.33, -0.33);
		glutSolidSphere(0.1, 16, 16);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glColor3f(1, 1, 0.25);
		glScalef(1+x, 1+x, 1+x);
		glTranslatef(0.0, 0.0, -0.33);
		glutSolidSphere(0.1, 16, 16);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glColor3f(1, 1, 0.25);
		glScalef(1+x, 1+x, 1+x);
		glTranslatef(-0.4, 0.33, -0.33);
		glutSolidSphere(0.1, 16, 16);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glColor3f(1, 1, 0.25);
		glScalef(1+x, 1+x, 1+x);
		glTranslatef(-0.4, 0.7, -0.33);
		glutSolidSphere(0.1, 16, 16);
	}
	glPopMatrix();
}

//*** ������ ��
void drawRightArm(double x)
{
	glPushMatrix();
	{
		glColor3f(0.8, 0.8, 0.8);
		glTranslatef(-0.1, 0.0, 0.1);
		glRotatef(-30, 1, 0, 1);
		glScalef(0.5+x, 4.0+x, 0.5+x);
		glutSolidCube (0.1);
	}
	glPopMatrix();
}

//*** ������ ��
void drawRightHand(double x)
{
	glPushMatrix();
	{
		glColor3f(0.8, 0.8, 0.8);
		glTranslatef(-0.23, -0.05, 0.2);
		glRotatef(-30, -1, 0, -1);
		glScalef(0.5+x, 2.5+x, 0.5+x);
		glutSolidCube (0.1);
	}
	glPopMatrix();
}

//*** ���� ��
void drawLeftArm(double x)
{
	glPushMatrix();
	{
		glColor3f(0.8, 0.8, 0.8);
		glTranslatef(0.1, 0.0, 0.1);
		glRotatef(30, -1, 0, 1);
		glScalef(0.5+x, 4.0+x, 0.5+x);
		glutSolidCube (0.1);
	}
	glPopMatrix();
}

//*** ���� ��
void drawLeftHand(double x)
{
	glPushMatrix();
	{
		glColor3f(0.8, 0.8, 0.8);
		glTranslatef(0.23, -0.05, 0.2);
		glRotatef(30, 1, 0, -1);
		glScalef(0.5+x, 2.5+x, 0.5+x);
		glutSolidCube (0.1);
	}
	glPopMatrix();
}

//*** �κ��� �׸���.
void drawMyRobot( double x)
{
	glPushMatrix();
	{
		drawBody(x);
		drawHead(x);
		drawLeg(x);
		drawPants(x);
		drawBall(x);
		drawRightArm(x);
		drawRightHand(x);
		drawLeftArm(x);
		drawLeftHand(x);
	}
	glPopMatrix();
}
