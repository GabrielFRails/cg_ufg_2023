#include<GL/glut.h>
#include <stdio.h>

// Estrutura que representa os vértices de um cubo
typedef struct cubo {
	float vertices[8][3];   
} Cubo;

// Matriz dos vértices de um cubo padrão
Cubo padrao = {.vertices =
	{
		{-0.5,-0.5, -0.5}, //0
		{0.5,-0.5, -0.5}, //1
		{-0.5,0.5, -0.5}, //2
		{0.5,0.5, -0.5}, //3
		{-0.5,-0.5, 0.5}, //4
		{0.5,-0.5, 0.5}, //5
		{-0.5,0.5, 0.5}, //6
		{0.5,0.5, 0.5}, //7
	}
};

void inicializa()
{
glClearColor(0,0,0,0);
// glClearDepth(1.0f);
glEnable(GL_CULL_FACE);
glCullFace(GL_BACK);
//  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Desenha somente as linhas de cada face
gluOrtho2D(-2,2,-2,2);
}

// Desenha um cubo dados seus vertices
void desenha (float m[8][2]){
	glBegin(GL_QUADS);

	glColor3f(0.7f, 0.7f, 0.7f);    // Desenha a frente
	glVertex2f(m[2][0], m[2][1]);
	glVertex2f(m[3][0], m[3][1]);
	glVertex2f(m[1][0], m[1][1]);
	glVertex2f(m[0][0], m[0][1]);

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(m[3][0], m[3][1]);  // Desenha o lado direito
	glVertex2f(m[7][0], m[7][1]);
	glVertex2f(m[5][0], m[5][1]);
	glVertex2f(m[1][0], m[1][1]);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(m[7][0], m[7][1]);  // Desenha a parte de trás
	glVertex2f(m[6][0], m[6][1]);
	glVertex2f(m[4][0], m[4][1]);
	glVertex2f(m[5][0], m[5][1]);

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2f(m[6][0], m[6][1]);  // Desenha o lado esquerdo
	glVertex2f(m[2][0], m[2][1]);
	glVertex2f(m[0][0], m[0][1]);
	glVertex2f(m[4][0], m[4][1]);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex2f(m[6][0], m[6][1]);  // Desenha a parte de cima
	glVertex2f(m[7][0], m[7][1]);
	glVertex2f(m[3][0], m[3][1]);
	glVertex2f(m[2][0], m[2][1]);

	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2f(m[0][0], m[0][1]);  // Desenha a parte debaixo
	glVertex2f(m[1][0], m[1][1]);
	glVertex2f(m[5][0], m[5][1]);
	glVertex2f(m[4][0], m[4][1]);
	glEnd(); 
}

void projeta(Cubo t){
	float proj[8][2];
	int i,j; 
	float d = 2;  // distância do centro de projeção ao plano de projeção
	
	// calcula novas coordenadas dos vértices para a projeção perspectiva
	for(i=0; i<8; i++){
		for (int j = 0; j < 2; j++) {
			if(j==0)
				proj[i][j] = t.vertices[i][j]/((t.vertices[i][j+2]/d)+1); 
			if(j==1)
				proj[i][j] = t.vertices[i][j]/((t.vertices[i][j+1]/d)+1);
		}
	}
	desenha(proj); // desenha a projeção
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	// Projeta o cubo padrão usando perspectiva
	projeta(padrao);
	
glFlush();

}
int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Projecao Perspectiva");
	inicializa();
	glutDisplayFunc(display); 
	glutMainLoop();
}
