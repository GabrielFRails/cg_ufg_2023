#include <GL/freeglut.h>
#include <math.h>

typedef struct {
	float x;
	float y;
} Ponto;

Ponto verticesOriginal[] = {{100.0, 100.0}, {200.0, 100.0}, {150.0, 200.0}};
Ponto verticesRotacionados[3]; // Armazenará os vértices rotacionados

float angulo = 50.0; // Ângulo de rotação em graus

void desenhaTriangulo() {
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 3; i++) {
		glVertex2f(verticesOriginal[i].x, verticesOriginal[i].y);
	}
	glEnd();
}

void rotacionaTriangulo() {
	float radianos = angulo * (M_PI / 180.0); // Converte o ângulo para radianos
	float cosAngulo = cos(radianos);
	float sinAngulo = sin(radianos);

	for (int i = 0; i < 3; i++) {
		verticesRotacionados[i].x = verticesOriginal[i].x * cosAngulo - verticesOriginal[i].y * sinAngulo;
		verticesRotacionados[i].y = verticesOriginal[i].x * sinAngulo + verticesOriginal[i].y * cosAngulo;
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Desenha o triângulo original
	glColor3f(1.0, 0.0, 0.0); // Vermelho
	desenhaTriangulo();
	
	// Rotação
	rotacionaTriangulo();
	
	// Desenha o triângulo rotacionado
	glColor3f(0.0, 1.0, 0.0); // Verde
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 3; i++) {
		glVertex2f(verticesRotacionados[i].x, verticesRotacionados[i].y);
	}
	glEnd();
	
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Rotacionando um Triangulo");

	glOrtho(0, 400, 0, 400, -1, 1);
	
	glutDisplayFunc(display);
	
	glutMainLoop();
	
	return 0;
}
