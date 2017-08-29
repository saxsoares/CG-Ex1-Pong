#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "Ex1_Pong.h"

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    glutCreateWindow("CG Fernando Ex1-Pong");

    glutDisplayFunc(Ex1_Pong);

    glutMainLoop();
}
