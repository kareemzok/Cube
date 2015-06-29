/*
  by kareem zock
 */


#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#include <iostream>
#include <stdlib.h>
#include "windows.h"
#include <glut/glut.h>
#ifdef __APPLE__
#include <gl/GL.h>
#include <gl/GLU.h>
#else
#include <gl/GL.h>
#include <gl/GLU.h>
#endif

#include "imageloader.h"

using namespace std;

const float BOX_SIZE = 10.0f; //The length of each side of the cube
const float BOX_HEIGHT = BOX_SIZE; //The height of the box off of the ground
const float FLOOR_SIZE = 20.0f; //The length of each side of the floor
float _angle = 0;            //The rotation of the box
float _anglee = 0;

GLuint _textureId;           //The OpenGL id of the texture
GLuint _textureId2;           //The OpenGL id of the texture
GLuint _textureIdbk;           //The OpenGL id of the texture
GLuint _textureFloorId;           //The OpenGL id of the texture

	
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
	}
}

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_RGB,
				 image->width, image->height,
				 0,
				 GL_RGB,
				 GL_UNSIGNED_BYTE,
				 image->pixels);
	return textureId;
}

void drawFloor(int textureId) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glBegin(GL_QUADS);
	
	glNormal3f(0, 1, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-FLOOR_SIZE / 2, 0, FLOOR_SIZE / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-FLOOR_SIZE / 2, 0, -FLOOR_SIZE / 2);
	glTexCoord2f(1, 1);
	glVertex3f(FLOOR_SIZE / 2, 0, -FLOOR_SIZE / 2);
	glTexCoord2f(1, 0);
	glVertex3f(FLOOR_SIZE / 2, 0, FLOOR_SIZE / 2);
	
	glEnd();
}

void drawCube(int _textureId1,int _textureId2,int _textureId3, int _textureId4, int _textureId5, int _textureId6) {

		glDisable(GL_TEXTURE_2D);
	
	glPushMatrix();

	glRotatef(-_angle, 1.0f, 1.0f, 0.0f);

	
     //texture for left image 
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);

	////Left face  picture
	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);

	glEnd();


	//Right face picture
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
    glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
    glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);

    glEnd();


	//Front face picture if fixed its default
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);

	glEnd();
	
	//Back face picture
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);

	glEnd();


		//Top face
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId5);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);

	glNormal3f(0.0, 1.0f,1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glEnd();

	//Bottom face
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId6);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);
	glNormal3f(0.0, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);

	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
		glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glEnd();


	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	
	Image* image = loadBMP("images/right.bmp");
	Image* image2 = loadBMP("images/left.bmp");
	Image* image3 = loadBMP("images/bk.bmp");
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);// mak it transparent 
	Image* imageF = loadBMP("images/vtr.bmp");
	_textureId = loadTexture(image);
	_textureId2 = loadTexture(image2);
	_textureIdbk = loadTexture(image3);
	_textureFloorId = loadTexture(imageF);
	
	delete image;
	delete image2;
	delete image3;
	delete imageF;
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}



void drawScene() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,255,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//glTranslatef(0.0f, 0.0f, -20.0f); //position of cube to the axe
	
	glTranslatef(0.0f, 0.0f, -50.0f); //position of cube to the axe
	glRotatef(30, 1, 0, 0);
	

	GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	
	GLfloat lightColor[] = {0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat lightPos[] = {-2 * BOX_SIZE, BOX_SIZE, 4 * BOX_SIZE, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	
	glPushMatrix();
	glTranslatef(0, BOX_HEIGHT, -10);
	drawCube(_textureId, _textureIdbk, _textureId2, _textureIdbk, _textureIdbk, _textureIdbk);
	glPopMatrix();

	glEnable(GL_STENCIL_TEST); //Enable using the stencil buffer
	glColorMask(255, 255, 255, 255); //Disable drawing colors to the screen
	glDisable(GL_DEPTH_TEST); //Disable depth testing
	glStencilFunc(GL_ALWAYS, 1, 1); //Make the stencil test always pass
	//Make pixels in the stencil buffer be set to 1 when the stencil test passes
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	//Set all of the pixels covered by the floor to be 1 in the stencil buffer
	drawFloor(_textureFloorId);
	
	glColorMask(1, 1, 1, 1); //Enable drawing colors to the screen
	glEnable(GL_DEPTH_TEST); //Enable depth testing
	//Make the stencil test pass only when the pixel is 1 in the stencil buffer
	glStencilFunc(GL_EQUAL, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); //Make the stencil buffer not change
	
	//Draw the cube, reflected vertically, at all pixels where the stencil
	//buffer is 1
	glPushMatrix();
	glScalef(1, -1, 1);
	glTranslatef(0, BOX_HEIGHT, -10);// position of reflected
	drawCube(_textureId, _textureIdbk, _textureId2, _textureIdbk, _textureIdbk, _textureIdbk);


	glPopMatrix();
	
	glDisable(GL_STENCIL_TEST); //Disable using the stencil buffer


	//Blend the floor onto the screen
	glEnable(GL_BLEND);
	glColor4f(1, 1, 1, 0.7f);
	drawFloor(_textureFloorId);
	glDisable(GL_BLEND);

	glutSwapBuffers();

}

//Called every 25 milliseconds
void update(int value) {
	
	_anglee += 1.0f; cout<<"//"<<_anglee;
if(_anglee < 500)// 3sec
{
	_angle += 1.0f;

}
if(_anglee > 500){
	_angle -= 1.0f;//cout<<"//"<<_angle;
	if(_anglee >1000){
	
	_anglee=0.0f;
	}
}
	if (_angle > 360) {
		_angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	
	glutCreateWindow("Putting It All Together");
	initRendering();
	
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	
	glutMainLoop();
	return 0;
}









