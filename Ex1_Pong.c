#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
void desenhaCampo(void);
void desenhaPlayers(void);

GLfloat w_width;
GLfloat w_height;
GLfloat s_width;
GLfloat s_height;

void desenhaCampo(void){
    w_width = glutGet(GLUT_WINDOW_WIDTH);
    w_height = glutGet(GLUT_WINDOW_HEIGHT);

    glPolygonMode(GL_FRONT,GL_LINE);
    glColor3f(0.0,1.0,0.0); glRectf(-0.95,-0.95,0.95,0.95);
    glLineStipple(1, 1);

}
void desenhaPlayers(void){

}
void Ex1_Pong(){
    s_width = glutGet(GLUT_SCREEN_WIDTH);
    s_height = glutGet(GLUT_SCREEN_HEIGHT);

    glClearColor(0.0,0.0,0.0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT);
    glPointSize(1.0);

        desenhaCampo();
        glutReshapeFunc(Ex1_Pong);

    glFlush();
    glFinish();
}
