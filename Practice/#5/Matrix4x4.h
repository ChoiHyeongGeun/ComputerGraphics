#pragma once
#include <gl/glut.h>
#include <stdio.h>

class Matrix4x4
{
	float	mat[16];
public:

	Matrix4x4(void) { identity(); }
	~Matrix4x4(void) { }

	// ���� Opengl�� ����� �о���� �Լ�
	//	GL_MODELVIEW_MATRIX, GL_PROJECTION_MATRIX, GL_TEXTURE_MATRIX, GL_COLOR_MATRIX
	void getMatrix( GLenum pname ) {
		glGetFloatv( pname, mat);
	}

	void identity() {
		for( int i=0 ; i<4 ; i++ )
		for( int j=0 ; j<4 ; j++ ) {
			mat[i*4 + j] = ( i == j ) ? 1.0f : 0.0f;
		}
	}
	void translate(float tx, float ty, float tz) {
		identity();
		mat[12] = tx;
		mat[13] = ty;
		mat[14] = tz;
	}
	void scale(float sx, float sy, float sz) {
		identity();
		mat[0] = sx;
		mat[5] = sy;
		mat[10] = sz;
	}
	void getShearZ( float sx, float sy ) {
		identity();
		mat[1] = sx;
		mat[4] = sy;
	}
	void mult( ) {
		glMatrixMode(GL_MODELVIEW);
		glMultMatrixf( mat );
	}

	// ��� ��� �Լ���
	void printModelViewMatrix(char *str = "���� MODELVIEW ��� = ") {
		getMatrix( GL_MODELVIEW_MATRIX );
		printMatrix(str);
	}
	void printProjectionMatrix(char *str = "���� PROJECTION ��� = ") {
		getMatrix( GL_PROJECTION_MATRIX );
		printMatrix(str);
	}
	void printMatrix(char* str = "���� ��� = ") {
		printf("%s", str);
		for( int i=0 ; i<4 ; i++ ) {
			printf("\n\t");
			for( int j=0 ; j<4 ; j++ ) 
				printf("%6.2f", mat[j*4+i]);
		}
		printf("\n");
	}
};

