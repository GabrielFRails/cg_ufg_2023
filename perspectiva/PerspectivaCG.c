#include <GL/glut.h>

float angle = 0.0;
int perspectiveMode = 0;  // 0 para perspectiva padrão, 1 para outra perspectiva

void display() {
    // Limpa o buffer de cores e o buffer de profundidade
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Define a matriz de visualização com gluLookAt, escolhendo entre duas posições predefinidas
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (perspectiveMode == 0) {
        gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    } else {
        gluLookAt(-5.0, 5.0, -5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    }

    // Empurra e popa a matriz de modelo para isolar a rotação
    glPushMatrix();
    glRotatef(angle, 1.0, 1.0, 1.0);
    
    // Desenha um cubo de arame com lados de comprimento 2.0
    glutWireCube(2.0);
    
    // Restaura a matriz de modelo
    glPopMatrix();

    // Troca os buffers para exibir o resultado
    glutSwapBuffers();
}

void reshape(int width, int height) {
    // Define a janela de visualização (viewport) e a matriz de projeção
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)width / (float)height, 1.0, 100.0);
}

void idle() {
    // Atualiza o ângulo de rotação e redisplay
    angle += 0.5;
    if (angle > 360.0) {
        angle -= 360.0;
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    // Alterna entre as perspectivas quando a tecla 'p' é pressionada
    if (key == 'p' || key == 'P') {
        perspectiveMode = 1 - perspectiveMode;  // Alterna entre 0 e 1
        glutPostRedisplay();  // Atualiza a janela para refletir a nova perspectiva
    }
}

int main(int argc, char** argv) {
    // Inicializa o GLUT e cria uma janela
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Perspective Example");

    // Habilita o teste de profundidade
    glEnable(GL_DEPTH_TEST);

    // Define as funções de callback
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);  // Registra a função de callback do teclado

    // Configura o fundo da janela para preto
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Entra no loop principal do GLUT
    glutMainLoop();

    return 0;
}

