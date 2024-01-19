//#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdio.h>

int raio;

// Protótipos das funções
void desenha(void);
void DesenhaCircunferencia(int raio);
void PontosCircunferencia(int x, int y);

int main(int argc, char **argv)
{
    // Solicita ao usuário para inserir o raio da circunferência
    printf("Digite o raio da circunferencia: ");
    scanf("%d", &raio);

    // Configuração inicial do ambiente GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Desenho de Circunferencia - GrupoXYZ");
    glColor3f(0.0, 0.0, 0.0);
    glutDisplayFunc(desenha);
    glutMainLoop();

    return 0;
}

// Função para desenhar os pontos da circunferência usando simetria de ordem 8
void PontosCircunferencia(int x, int y)
{
    glVertex2i(x, y);
    glVertex2i(x, -y);
    glVertex2i(-x, y);
    glVertex2i(-x, -y);
    glVertex2i(y, x);
    glVertex2i(y, -x);
    glVertex2i(-y, x);
    glVertex2i(-y, -x);
}

// Algoritmo do "ponto médio" para desenhar a circunferência
void DesenhaCircunferencia(int r)
{
    int x, y;
    float variavelDecisao;

    // Valores iniciais
    x = 0;
    y = r;
    variavelDecisao = 5.0 / 4 - r;

    glBegin(GL_POINTS);
    PontosCircunferencia(x, y);

    while (y > x)
    {
        if (variavelDecisao < 0)
        {
            // Selecione o caminho E
            variavelDecisao = variavelDecisao + 2 * x + 3;
            x++;
        }
        else
        {
            // Selecione o caminho SE
            variavelDecisao = variavelDecisao + 2 * (x - y) + 5;
            x++;
            y--;
        }
        PontosCircunferencia(x, y);
    }
    glEnd();
}

// Função de desenho principal
void desenha()
{
    // Limpa o buffer de cor
    glClear(GL_COLOR_BUFFER_BIT);

    // Define a janela de visualização
    gluOrtho2D(-raio, raio, -raio, raio);

    // Define a cor para verde
    glColor3f(0.0, 1.0, 0.0);

    // Define o tamanho dos pontos
    glPointSize(4);

    // Chama a função para desenhar a circunferência
    DesenhaCircunferencia(raio);

    // Força a execução dos comandos GL pendentes
    glFlush();
}
