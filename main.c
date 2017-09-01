#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "Ex1_Pong.h"

GLint sw, sh, winPosX, winPosY;

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    sw = glutGet(GLUT_SCREEN_WIDTH), sh = glutGet(GLUT_SCREEN_HEIGHT),
        winPosX = 0, winPosY = 0;
    glutInitWindowPosition(winPosX, winPosY);
    glutInitWindowSize(sw, sh);
    glutCreateWindow("CG Fernando Ex1-Pong");

    glutDisplayFunc(Ex1_Pong);

    glutMainLoop();
}
