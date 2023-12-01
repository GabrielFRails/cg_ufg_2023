#include <GL/freeglut.h>
#include <stdio.h>

// Definindo a estrutura para representar um ponto no plano 2D
typedef struct ponto2d {
    int x, y;
} Ponto2D;

// Função para desenhar um ponto na tela
void desenha_ponto(int x, int y, float r, float g, float b) {
    glBegin(GL_POINTS);
    glColor3f(r, g, b);
    glVertex2i(x, y);
    glEnd();
}

// Função para desenhar uma reta utilizando o algoritmo de Bresenham
void desenha_reta(Ponto2D inicio, Ponto2D fim, float r, float g, float b) {
    int dx = fim.x - inicio.x;
    int dy = fim.y - inicio.y;
    int p = 2 * dy - dx;
    int twoDy = 2 * dy;
    int twoDyMinusDx = 2 * (dy - dx);
    int x = inicio.x, y = inicio.y;

    // Desenha o ponto inicials
    desenha_ponto(x, y, r, g, b);

    // Loop para percorrer a reta
    while (x < fim.x) {
        x++;

        // Escolhe o próximo pixel
        if (p < 0) {
            p += twoDy;
        } else {
            y++;
            p += twoDyMinusDx;
        }

        // Desenha o próximo ponto na reta
        desenha_ponto(x, y, r, g, b);
    }
}

// Função de exibição
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Define dois pontos para a reta
    Ponto2D ponto1 = {20, 10};
    Ponto2D ponto2 = {80, 70};

    // Desenha uma reta vermelha
    desenha_reta(ponto1, ponto2, 1.0, 0.0, 0.0);

    glFlush();
}

// Função de callback para o teclado
void keyboard(unsigned char key, int x, int y) {
    if (key == 27) // ASCII para tecla Esc
        exit(0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Traçado de Reta Interativo");

    // Configura a janela de visualização ortogonal
    gluOrtho2D(0, 100, 0, 100);

    // Configura a cor de fundo (branco)
    glClearColor(1.0, 1.0, 1.0, 0.0);

    // Define a função de exibição
    glutDisplayFunc(display);

    // Registra a função de callback para o teclado
    glutKeyboardFunc(keyboard);

    // Entra no loop principal do GLUT
    glutMainLoop();

    return 0;
}
