/* Exercicio Computação Gŕafica por Fernando Bandeira Soares
-- Implementação do jogo PONG utiliZANDO OpenGL ---

----- MANUAL do GAME ---------------------------------------
Atende a todos os requisitos do exercicio e:
-Tecla seta para a direita aumenta a velocidade da "bola"
-Tecla seta para a esquerda diminui a velocidade da "bola"
*/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "Ex1_Pong.h"


GLfloat preto[] = {0,0,0}, branco[] = {1,1,1}, verde[] = {0,1,0},
        vermelho[] = {1,0,0}, azul[] = {0,0,1}, amarelo[] = {1,1,0},
        cor7[] = {0,1,1}, cor8[] = {0.93,0.51,93}, cor9[] = {0,0.5,0.5},
        cor10[] = {0.99,0.06,0.75}, cor11[] = {0.5,0.5,0.5}, cor12[] = {1,0.39,0.28};

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    sw = glutGet(GLUT_SCREEN_WIDTH);
    sh = glutGet(GLUT_SCREEN_HEIGHT);
    winPosX = 0; winPosY = 0;
    glutInitWindowPosition(winPosX, winPosY);
    glutInitWindowSize(sw, sh);
    glutCreateWindow("CG Fernando Ex1-Pong");
        glutDisplayFunc(Ex1_Pong);
        glutTimerFunc(0,Timer,0);
        glutKeyboardFunc(Keyboard);
        glutSpecialFunc(SpecialKeys);
        glutPassiveMotionFunc(MovimentaMouse);
//        glutReshapeFunc(AlteraTamanhoJanela);
    glutMainLoop();
}
