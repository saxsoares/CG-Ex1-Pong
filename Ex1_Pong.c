/* Exercicio Computação Gŕafica por Fernando Bandeira Soares
-- Implementação do jogo PONG utiliZANDO OpenGL ---

----- MANUAL do GAME ---------------------------------------
Atende a todos os requisitos do exercicio e:
-Tecla seta para a direita aumenta a velocidade da "bola"
-Tecla seta para a esquerda diminui a velocidade da "bola"
*/


#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "Ex1_Pong.h"


GLfloat xEsq = -0.95, xDir = 0.95, yCima = 0.95, yBaixo = -0.95;
GLfloat xTracejadoEsq = -0.50, xTracejadoDir = 0.50;
GLfloat xBola = 0, yBola = 0, pxBola = 0.0, pyBola = 0.0, incXBola = 0.011, incYBola = 0.007;
GLfloat xP1 = -0.85, yP1 = 0, xP2 = 0.85, yP2 = 0;
GLfloat racketSize = .1;
char placar[5] = {0, 0};
void *font = GLUT_BITMAP_9_BY_15;
GLfloat *corBola  = branco;
GLint veloc = 10;
GLboolean GameOver = 0;

void desenhaCampo(void){
    w_width = glutGet(GLUT_WINDOW_WIDTH);
    w_height = glutGet(GLUT_WINDOW_HEIGHT);

    glPolygonMode(GL_FRONT,GL_LINE);
    glColor3fv(branco); glRectf(xEsq,yBaixo,xDir,yCima);
    glBegin(GL_LINES);
        glVertex2f(0, yCima);
        glVertex2f(0, yBaixo);
    glEnd();
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(3, 0x00FF);
    glBegin(GL_LINES);
        glVertex2f(xTracejadoEsq, yCima);
        glVertex2f(xTracejadoEsq, yBaixo);
        glVertex2f(xTracejadoDir, yCima);
        glVertex2f(xTracejadoDir, yBaixo);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}
void Player1(GLfloat xp1, GLfloat yp1){
    glLineWidth(5.0);
    glBegin(GL_LINES);
        glColor3fv(verde);
            glVertex2f(xp1, yp1-.1);
            glVertex2f(xp1, yp1+.1);
    glEnd();
    glLineWidth(1.0);
}

void Player2(GLfloat xp2, GLfloat yp2){
    glLineWidth(5.0);
    glBegin(GL_LINES);
        glColor3fv(verde);
            glVertex2f(xp2, yp2-racketSize);
            glVertex2f(xp2, yp2+racketSize);
    glEnd();
    glLineWidth(1.0);
}

void bola(){
    glPointSize(10.0);
    glBegin(GL_POINTS);
        glColor3fv(corBola);
            glVertex2f(pxBola, pyBola);
    glEnd();
    glPointSize(1.0);
}

void MovimentaMouse(int x, int y){
    float aux1, aux2;

    if(incXBola < 0){
        y = w_height - y;
        aux1 = ((x/w_width)*2 -1);
        if(aux1 < xTracejadoEsq && aux1 > xEsq) xP1 = aux1;
        else if(aux1 >= xTracejadoEsq) xP1 = xTracejadoEsq;
        else if(aux1 <= xEsq) xP1 = xEsq;
        aux2 = ((y/w_height)*2 - 1);
        if((aux2+racketSize) < yCima && (aux2-racketSize) > yBaixo) yP1 = aux2;
        else if((aux2+racketSize) >= yCima) yP1 = yCima-racketSize;
        else if((aux2-racketSize) <= yBaixo) yP1 = yBaixo+racketSize;
    }
    else{
        y = w_height - y;
        aux1 = ((x/w_width)*2 -1);
        if(aux1 > xTracejadoDir && aux1 < xDir) xP2 = aux1;
        else if(aux1 <= xTracejadoDir) xP2 = xTracejadoDir;
        else if(aux1 >= xDir) xP2 = xDir;
        aux2 = ((y/w_height)*2 - 1);
        if((aux2+racketSize) < yCima && (aux2-racketSize) > yBaixo) yP2 = aux2;
        else if((aux2+racketSize) >= yCima) yP2 = yCima-racketSize;
        else if((aux2-racketSize) <= yBaixo) yP2 = yBaixo+racketSize;
    }
}
void CheckCollision(){
    float collisionFactor = 0.01, edgeFactor = 0.01;
    if((pxBola <= xP1 + collisionFactor) && (pxBola >= xP1 - collisionFactor)){
        if(pyBola <= yP1+racketSize && pyBola >= yP1-racketSize){
            incXBola = -incXBola;
            if( ((pyBola <= (yP1+racketSize)+edgeFactor) && pyBola >= (yP1+racketSize)-edgeFactor) ||
                ((pyBola <= (yP1-racketSize)-edgeFactor) && pyBola >= (yP1-racketSize)+edgeFactor))
                incYBola = -incYBola;
        }
    }
    else if((pxBola <= xP2 + collisionFactor) && (pxBola >= xP2 - collisionFactor)){
        if(pyBola <= yP2+racketSize && pyBola >= yP2-racketSize){
            incXBola = -incXBola;
            if( ((pyBola <= (yP2+racketSize)+edgeFactor) && pyBola >= (yP2+racketSize)-edgeFactor) ||
                ((pyBola <= (yP2-racketSize)-edgeFactor) && pyBola >= (yP2-racketSize)+edgeFactor))
                incYBola = -incYBola;
        }
    }
}

void AnimaBola(){
    bola();
    CheckCollision();
    if (pxBola>xDir-.008 || pxBola<xEsq+.008){
        GameOver = 1;
        incXBola = -incXBola;
        glutPostRedisplay();
    }
    if (pyBola>yCima-.015 || pyBola<yBaixo+.015)
        incYBola = -incYBola;
    pxBola += incXBola;
    pyBola += incYBola;
}

void Keyboard (unsigned char key, int x, int y){
    switch (key)    {
    case '0' :
    corBola = vermelho;
    break;
    case '1' :
    corBola = verde;
    break;
    case '2' :
    corBola = azul;
    break ;
    case '3' :
    corBola = amarelo;
    break;
    case '4' :
    corBola = cor7;
    break ;
    case '5' :
    corBola = cor8;
    break;
    case '6' :
    corBola = cor9;
    break ;
    case '7' :
    corBola = cor10;
    break;
    case '8' :
    corBola = cor11;
    break ;
    case '9' :
    corBola = cor12;
    break;
    default :
    break ;
    }
    glutPostRedisplay() ;
}
void SpecialKeys (int key, int x, int y){
    switch (key) {
        case GLUT_KEY_LEFT:
            veloc = (veloc + 100) > 1000 ? 1000 : veloc + 100;
            incXBola = incXBola * 0.98;
            corBola = cor12;
        break;
        case GLUT_KEY_RIGHT:
            veloc = (veloc - 90 ) <= 0 ? 0 : (veloc - 90);
            incXBola = incXBola * 1.01;
            corBola = cor12;
        break;
        default :
        break ;
        }
    glutPostRedisplay() ;
}
void Timer(int extra){
    if(!GameOver){
        glutPostRedisplay();
        glutTimerFunc(veloc,Timer,0);
    }
}
void Ex1_Pong(){
    if(GameOver)
        glClearColor(0.07,0.04,0.56,0);
    else
        glClearColor(0.0,0.0,0.0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT);
        desenhaCampo();
        AnimaBola();
        Player1(xP1, yP1);
        Player2(xP2, yP2);
    glutSwapBuffers();
    glFlush();
    glFinish();
}
