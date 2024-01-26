#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenha os eixos x e y
    glColor3f(0.4, 1.0, 1.0);  // Cor branca
    glBegin(GL_LINES);
    // Eixo x
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    // Eixo y
    glVertex2f(0.0, -1.0);
    glVertex2f(0.0, 1.0);
    glEnd();

    // Desenha um quadrado branco
    glColor3f(1.0, 1.0, 1.0);  // Cor branca
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.0, 1.0, -1.0, 4.0, -3.0, 1.0);  // Projeção ortogonal
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Projeção Ortogonal");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    
    return 0;
}

