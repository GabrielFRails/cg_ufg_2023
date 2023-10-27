#include <GL/freeglut.h>

typedef struct {
	float x;
	float y;
} Ponto;

Ponto verticesOriginal[] = {{100.0, 100.0}, {200.0, 100.0}, {150.0, 200.0}};
Ponto verticesTransladados[3]; // Armazenará os vértices transladados

float tx = 50.0; // Translação em X
float ty = 100.0; // Translação em Y

void desenhaTriangulo() {
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 3; i++) {
		glVertex2f(verticesOriginal[i].x, verticesOriginal[i].y);
	}
	glEnd();
}

void transladaTriangulo() {
	for (int i = 0; i < 3; i++) {
		verticesTransladados[i].x = verticesOriginal[i].x + tx;
		verticesTransladados[i].y = verticesOriginal[i].y + ty;
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Desenha o triângulo original
	glColor3f(1.0, 0.0, 0.0); // Vermelho
	desenhaTriangulo();
	
	// Translação
	transladaTriangulo();
	
	// Desenha o triângulo transladado
	glColor3f(0.0, 1.0, 0.0); // Verde
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 3; i++) {
		glVertex2f(verticesTransladados[i].x, verticesTransladados[i].y);
	}
	glEnd();
	
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Transladando um Triangulo");

	glOrtho(0, 400, 0, 400, -1, 1);
	
	glutDisplayFunc(display);
	
	glutMainLoop();
	
	return 0;
}
