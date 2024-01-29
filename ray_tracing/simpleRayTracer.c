#include <GL/glut.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    float x, y, z;
} Vec3;

typedef struct {
    Vec3 origin;
    Vec3 direction;
} Ray;

typedef struct {
    Vec3 center;
    float radius;
} Sphere;

// Função para calcular o produto escalar de dois vetores
float dot(Vec3 v1, Vec3 v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Função para subtrair dois vetores
Vec3 subtract(Vec3 v1, Vec3 v2) {
    Vec3 result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

// Função para normalizar um vetor
Vec3 normalize(Vec3 v) {
    float length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    Vec3 result;
    result.x = v.x / length;
    result.y = v.y / length;
    result.z = v.z / length;
    return result;
}

// Função para verificar a interseção entre um raio e uma esfera
int intersect(Ray ray, Sphere sphere, float *t) {
    Vec3 oc = subtract(ray.origin, sphere.center);
    float a = dot(ray.direction, ray.direction);
    float b = 2.0 * dot(oc, ray.direction);
    float c = dot(oc, oc) - sphere.radius * sphere.radius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return 0; // Não há interseção
    }

    // Encontrar o valor de t para a interseção mais próxima
    float t1 = (-b - sqrt(discriminant)) / (2.0 * a);
    float t2 = (-b + sqrt(discriminant)) / (2.0 * a);

    *t = fmin(t1, t2);

    return 1; // Há interseção
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    Sphere sphere;
    sphere.center.x = 0.0;
    sphere.center.y = 0.0;
    sphere.center.z = -5.0;
    sphere.radius = 1.0;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Ray ray;
            ray.origin.x = 0.0;
            ray.origin.y = 0.0;
            ray.origin.z = 0.0;
            ray.direction.x = (2.0 * x - WIDTH) / WIDTH;
            ray.direction.y = -(2.0 * y - HEIGHT) / HEIGHT;
            ray.direction.z = -1.0;
            ray.direction = normalize(ray.direction);

            float t;
            if (intersect(ray, sphere, &t)) {
                glColor3f(1.0, 1.0, 1.0);
            } else {
                glColor3f(0.0, 0.0, 0.0);
            }

            glVertex2i(x, y);
        }
    }

    glEnd();
    glFlush();
}

void initialize() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Ray Tracing with OpenGL");

    initialize();

    glutDisplayFunc(render);
    glutMainLoop();

    return 0;
}
