#include <windows.h>
#include <GL/glut.h>
#include <math.h> // Required for sin and cos to draw the circle

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void display() {
    // Clear background to a light gray so the white part of the flag is visible
    glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // =========================
    // BAHRAIN FLAG
    // =========================

    // 1. Red Base (It's easier to draw the red rectangle first)
    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2i(50, 100);
        glVertex2i(350, 100);
        glVertex2i(350, 400);
        glVertex2i(50, 400);
    glEnd();

    // 2. White part (Left side)
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2i(50, 100);
        glVertex2i(200, 100);
        glVertex2i(200, 400);
        glVertex2i(50, 400);
    glEnd();

    // 3. Zig-zag edge (5 white triangles pointing into the red)
    glBegin(GL_TRIANGLES);
        glVertex2i(200, 100); glVertex2i(230, 130); glVertex2i(200, 160);
        glVertex2i(200, 160); glVertex2i(230, 190); glVertex2i(200, 220);
        glVertex2i(200, 220); glVertex2i(230, 250); glVertex2i(200, 280);
        glVertex2i(200, 280); glVertex2i(230, 310); glVertex2i(200, 340);
        glVertex2i(200, 340); glVertex2i(230, 370); glVertex2i(200, 400);
    glEnd();

    // =========================
    // BLUETOOTH LOGO
    // =========================

    // 1. Black Background Circle
   glColor3f(0.0f, 0.0f, 0.0f); // Pure Black

    float cX = 500.0f;
    float cY = 300.0f;
    float radius = 100.0f;      // The width of the "U"
    float straightHeight = 70.0f; // Length of the straight vertical sides

    glColor3f(0.0f, 0.0f, 0.0f); // Black Background

    // This single loop draws the top U, straight sides, and bottom U together
    glBegin(GL_POLYGON);
        // Top semicircle (Inverted U)
        for (int i = 0; i <= 180; i++) {
            float rad = i * M_PI / 180.0f;
            glVertex2f(cX + cos(rad) * radius, (cY + straightHeight) + sin(rad) * radius);
        }
        // Bottom semicircle (Regular U)
        for (int i = 180; i <= 360; i++) {
            float rad = i * M_PI / 180.0f;
            glVertex2f(cX + cos(rad) * radius, (cY - straightHeight) + sin(rad) * radius);
        }
    glEnd();

    // 2. White Rune (The "B" shape)
    glColor3f(1.0f, 1.0f, 1.0f); // White Rune
    glLineWidth(60.0f); // Make the lines nice and thick
    glBegin(GL_LINE_STRIP);
        glVertex2i(445, 225); // Bottom left
        glVertex2i(555, 375); // Top right
        glVertex2i(500, 435); // Top center
        glVertex2i(500, 165); // Bottom center
        glVertex2i(555, 225); // Bottom right
        glVertex2i(445, 375); // Top left
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(50, 50);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Bluetooth (Black Circle) + Bahrain Flag");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 700, 0, 600);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
