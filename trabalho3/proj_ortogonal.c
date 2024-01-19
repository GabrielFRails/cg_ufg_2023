//#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdio.h>

// Definição da estrutura para armazenar os vértices de uma forma tridimensional
typedef struct shape {
    float vertices[8][3];
} Shape;

// Definição de uma forma padrão (cubo)
Shape defaultShape = {.vertices =
    {
        {-0.5, 0.5, 0.5},
        {-0.5, -0.5, 0.5},
        {0.5, -0.5, 0.5},
        {0.5, 0.5, 0.5},
        {0.5, 0.5, -0.5},
        {0.5, -0.5, -0.5},
        {-0.5, -0.5, -0.5},
        {-0.5, 0.5, -0.5},
    }
};

// Variável para alternar entre projeção ortogonal e perspectiva
int useOrthographic = 1;

// Função de inicialização do OpenGL
void initialize() {
    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

// Função para desenhar a forma com as coordenadas fornecidas
void draw(float m[8][3]) {
    glBegin(GL_QUADS);

    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex3f(m[0][0], m[0][1], m[0][2]);
    glVertex3f(m[1][0], m[1][1], m[1][2]);
    glVertex3f(m[2][0], m[2][1], m[2][2]);
    glVertex3f(m[3][0], m[3][1], m[3][2]);

    // ... (repetido para outras faces)

    glEnd();
}

// Função para projetar a forma com base no tipo de projeção (ortogonal ou perspectiva)
void project(Shape t) {
    if (useOrthographic) {
        float orthoProj[8][3];
        int i, j;

        // Copia as coordenadas da forma diretamente para a projeção ortogonal
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 3; j++) {
                orthoProj[i][j] = t.vertices[i][j];
            }
        }

        // Desenha a projeção ortogonal
        draw(orthoProj);
    } else {
        float perspProj[8][3];
        int i, j;

        // Matriz de projeção perspectiva
        float perspectiveMatrix[4][4] = {
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, -2},
            {0, 0, -1, 0}
        };

        // Calcula as novas coordenadas para a projeção perspectiva
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 3; j++) {
                perspProj[i][j] = 0;
                for (int k = 0; k < 4; k++) {
                    perspProj[i][j] += perspectiveMatrix[j][k] * t.vertices[i][k];
                }
            }
        }

        // Desenha a projeção perspectiva
        draw(perspProj);
    }
}

// Função de exibição - é chamada a cada quadro
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Projeta a forma (cubo) ortogonalmente ou perspectivamente
    project(defaultShape);

    // Troca os buffers
    glutSwapBuffers();
}

// Função de teclado para alternar entre projeção ortogonal e perspectiva
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'o':
        case 'O':
            useOrthographic = 1;
            break;
        case 'p':
        case 'P':
            useOrthographic = 0;
            break;
        case 27: // Tecla Esc
            exit(0);
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char ** argv) {
    // Inicialização do GLUT
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Projection");

    // Inicialização do OpenGL
    initialize();

    // Funções de callback
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    // Loop principal do GLUT
    glutMainLoop();
    return 0;
}
