#include <GL/freeglut.h>
#include <stdio.h>

typedef struct {
	float x;
	float y;
} Ponto;

Ponto verticesOriginal[] = {{100.0, 100.0}, {200.0, 100.0}, {150.0, 200.0}};
Ponto verticesEscalados[3]; // Armazenará os vértices escalados

void desenhaTriangulo() {
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 3; i++) {
		glVertex2f(verticesOriginal[i].x, verticesOriginal[i].y);
	}
	glEnd();
}

void escalaTriangulo(float escalaX, float escalaY) {
	for (int i = 0; i < 3; i++) {
		verticesEscalados[i].x = verticesOriginal[i].x * escalaX;
		verticesEscalados[i].y = verticesOriginal[i].y * escalaY;
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Desenha o triângulo original
	glColor3f(1.0, 0.0, 0.0); // Vermelho
	desenhaTriangulo();
	
	// Escala pela metade
	escalaTriangulo(0.5, 0.5);
	
	// Desenha o triângulo escalado pela metade
	glColor3f(0.0, 1.0, 0.0); // Verde
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 3; i++) {
		glVertex2f(verticesEscalados[i].x, verticesEscalados[i].y);
	}
	glEnd();
	
	// Escala para o dobro
	escalaTriangulo(2.0, 2.0);
	
	// Desenha o triângulo escalado para o dobro
	glColor3f(0.0, 0.0, 1.0); // Azul
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 3; i++) {
		glVertex2f(verticesEscalados[i].x, verticesEscalados[i].y);
	}
	glEnd();
	
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Escalando um Triângulo");
	
	glOrtho(0, 400, 0, 400, -1, 1);
	
	glutDisplayFunc(display);
	
	glutMainLoop();
	
	return 0;
}
