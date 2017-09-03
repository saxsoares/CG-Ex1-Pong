#ifndef EX1_PONG_H_INCLUDED
#define EX1_PONG_H_INCLUDED
#include <GL/glut.h>

void Ex1_Pong();
void desenhaCampo(void);
void Player1(GLfloat, GLfloat);
void Player2(GLfloat, GLfloat);
void bola();
void AnimaBola();
void Timer(int );
void Keyboard(unsigned char, int , int );
void MovimentaMouse(int, int);
void CheckCollision(void);
void SpecialKeys (int , int , int );

extern GLint veloc;
GLint sw, sh, winPosX, winPosY;
GLfloat w_width, w_height;
extern GLfloat racketSize;
extern GLfloat preto[], branco[], verde[], vermelho[], azul[], verde[], amarelo[], cor7[], cor8[], cor9[], cor10[], cor11[], cor12[];
extern GLfloat xEsq, xDir, yCima, yBaixo;
extern GLfloat xTracejadoEsq, xTracejadoDir;
extern GLfloat xBola, yBola, pxBola, pyBola, incXBola, incYBola;
extern GLfloat xP1, yP1, xP2, yP2;
extern char placar[];
extern void *font;
extern GLfloat *corBola;

#endif // EX1_PONG_H_INCLUDED
