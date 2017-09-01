#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
void desenhaCampo(void);
void desenhaPlayers(void);

GLfloat w_width, w_height;
GLfloat s_width, s_height;
GLfloat preto[] = {0,0,0},
        branco[] = {1,1,1},
        verde[] = {0,1,0};
GLfloat cantoIEX = -0.95,cantoIEY = -0.95,cantoSDX = 0.95,cantoSDY = 0.95,
        cantoIDX = 0.95, cantoIDY = -0.95,cantoSEX = -0.95,cantoSEY = 0.95;
GLfloat x1TracejadoEsq = -0.80, x2TracejadoEsq = -0.80;
GLfloat x1TracejadoDir = 0.80, x2TracejadoDir = 0.80;

void desenhaCampo(void){
    w_width = glutGet(GLUT_WINDOW_WIDTH);
    w_height = glutGet(GLUT_WINDOW_HEIGHT);
    s_width = glutGet(GLUT_SCREEN_WIDTH);
    s_height = glutGet(GLUT_SCREEN_HEIGHT);

    glPolygonMode(GL_FRONT,GL_LINE);
    glColor3fv(branco); glRectf(cantoIEX,cantoIEY,cantoSDX,cantoSDY);
    glBegin(GL_LINES);
        glVertex2f(0, cantoSEY);
        glVertex2f(0, cantoIDY);
    glEnd();
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(3, 0x00FF);
    glBegin(GL_LINES);
        glVertex2f(x1TracejadoEsq, cantoSEY);
        glVertex2f(x2TracejadoEsq, cantoIDY);
        glVertex2f(x1TracejadoDir, cantoSEY);
        glVertex2f(x2TracejadoDir, cantoIDY);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}
void desenhaPlayers(void){

}

void bola(void){

}

void Ex1_Pong(){
    glClearColor(0.0,0.0,0.0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT);
    glPointSize(1.0);

        desenhaCampo();

    glFlush();
    glFinish();
}
