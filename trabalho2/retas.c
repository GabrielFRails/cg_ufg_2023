#include <GL/glut.h>
#include <stdio.h>

#define ESPACAMENTO 0.05

/*
    Apesar de o algoritmo apresentado em sala utilizar
    inteiros, este código foi feito utilizando double,
    pois com valores inteiros o espaçamento entre os
    pontos fica muito grande, e não é possível visualizar
    a reta.
*/

// Criando uma struct do tipo ponto2d
typedef struct ponto2d {
    double x, y;
}Ponto2D;

void desenha_reta(Ponto2D inicio, Ponto2D fim);
void desenha_ponto(Ponto2D ponto);
Ponto2D construir_Ponto2D(double x, double y); 

Ponto2D construir_Ponto2D(double x, double y){ //pseudo construtor de Ponto2D
    Ponto2D ponto;
    ponto.x = x;
    ponto.y = y;

    return ponto;
}

void desenha_reta(Ponto2D inicio, Ponto2D fim){

    double dx, dy, incE, incNE, d;
    Ponto2D pontoAtual;

    dx = fim.x - inicio.x;
    dy = fim.y - inicio.y;
    d = 2 * dy - dx;
    incE = 2 * dy;
    incNE = 2 * (dy - dx);
    pontoAtual.x = inicio.x;
    pontoAtual.y = inicio.y;
    desenha_ponto(pontoAtual);

    while(pontoAtual.x < fim.x){
        if(d <= 0){
            //escolhe E
            d += incE;
            pontoAtual.x += ESPACAMENTO;
        } else {
            //escolhe NE
            d += incNE;
            pontoAtual.x += ESPACAMENTO;
            pontoAtual.y += ESPACAMENTO;
        }
        desenha_ponto(pontoAtual);
    }
}

void desenha_ponto(Ponto2D ponto){
    glBegin(GL_POINTS);
    glVertex2d(ponto.x, ponto.y);
    glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
    Ponto2D ponto1 = construir_Ponto2D(0,0);
    Ponto2D ponto2 = construir_Ponto2D(3,2);
    Ponto2D ponto3 = construir_Ponto2D(-5,-2);
    Ponto2D ponto4 = construir_Ponto2D(9,7);

    glColor3f(0.5, 1.0, 1.0); //ciano
	desenha_reta(ponto3, ponto2);
    glColor3f(1.0, 1.0, 0.0); //amarelo
    desenha_reta(ponto1, ponto4);
    glFlush();

}

int main(int argc, char ** argv)
{
 	glutInit(&argc, argv);
 	glutInitWindowSize(1200,900);
 	glutInitWindowPosition(10,10);
 	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 	glutCreateWindow("Tracado de retas otimizado");
 	glClearColor(0,0,0,0);
 	gluOrtho2D(-6,6,-6,6);
 	glutDisplayFunc(display); 
 	glutMainLoop();
 	
 	return 0;
}