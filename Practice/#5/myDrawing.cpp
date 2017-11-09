#include <GL/glut.h>

//*** ¸öÅë
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

//*** ¸Ó¸®
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

//*** ´Ù¸®
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

//*** ¹ÙÁö
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

//*** ±¸½½
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

//*** ¿À¸¥ÂÊ ÆÈ
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

//*** ¿À¸¥ÂÊ ¼Õ
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

//*** ¿ÞÂÊ ÆÈ
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

//*** ¿ÞÂÊ ¼Õ
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

//*** ·Îº¿À» ±×¸°´Ù.
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
