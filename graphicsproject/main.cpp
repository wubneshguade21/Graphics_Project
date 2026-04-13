#include <windows.h>
#include <GL/glut.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
float logoX = 0.0f, logoY = 0.0f, logoAngle = 0.0f, logoScale = 1.0f;
float flagX = 0.0f, flagY = 0.0f, flagAngle = 0.0f, flagScale = 1.0f;

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': logoY += 10.0f; break;
        case 's': logoY -= 10.0f; break;
        case 'a': logoX -= 10.0f; break;
        case 'd': logoX += 10.0f; break;
        case 'r': logoAngle += 10.0f; break;
        case 't': logoAngle -= 10.0f; break;
        case 'm': logoScale += 0.1f; break;
        case 'n': if(logoScale > 0.1) logoScale -= 0.1f; break;

        case 'y': flagY += 10.0f; break;
        case 'h': flagY -= 10.0f; break;
        case 'g': flagX -= 10.0f; break;
        case 'j': flagX += 10.0f; break;
        case 'i': flagAngle += 10.0f; break;
        case 'o': flagAngle -= 10.0f; break;
        case 'u': flagScale += 0.1f; break;
        case 'b': if(flagScale > 0.1) flagScale -= 0.1f; break;

        case 27: exit(0); break;
    }
    glutPostRedisplay();
}


void display() {
    glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

     glPushMatrix();
        glTranslatef(flagX, flagY, 0.0f);
        glTranslatef(200, 250, 0);
        glRotatef(flagAngle, 0, 0, 1);
        glScalef(flagScale, flagScale, 1);
        glTranslatef(-200, -250, 0);

        glColor3f(0.8f, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex2i(50, 100);
            glVertex2i(350, 100);
            glVertex2i(350, 400);
            glVertex2i(50, 400);
        glEnd();
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_POLYGON);
            glVertex2i(50, 100);
            glVertex2i(200, 100);
            glVertex2i(200, 400);
            glVertex2i(50, 400);
        glEnd();
        glBegin(GL_TRIANGLES);
            for(int y=100; y<400; y+=60){
                glVertex2i(200,y);
                glVertex2i(230,y+30);
                glVertex2i(200,y+60);
            }
        glEnd();
    glPopMatrix();

        glPushMatrix();
        float cX = 500.0f, cY = 300.0f;
        glTranslatef(logoX, logoY, 0.0f);
        glTranslatef(cX, cY, 0);
        glRotatef(logoAngle, 0, 0, 1);
        glScalef(logoScale, logoScale, 1);
        glTranslatef(-cX, -cY, 0);

        glColor3f(0.0f, 0.51f, 0.99f);
        glBegin(GL_POLYGON);
            for(int i=0; i<=360; i++){
                float r = i * M_PI / 180.0f;
                float offsetY = (i > 180) ? -85 : 85;
                glVertex2f(cX + cos(r)*110, cY + offsetY + sin(r)*110);
            }
        glEnd();


        glColor3f(1.0f, 1.0f, 1.0f);
       glBegin(GL_QUADS);


            glVertex2i(493, 170);
            glVertex2i(507, 170);
            glVertex2i(507, 430);
             glVertex2i(493, 430);


            glVertex2i(500, 438);
            glVertex2i(507, 425);
            glVertex2i(565, 370);
            glVertex2i(553, 380);


            glVertex2i(500, 162);
            glVertex2i(507, 175);
            glVertex2i(565, 230);
             glVertex2i(555, 225);

            glVertex2i(433, 235);
             glVertex2i(445, 225);
            glVertex2i(567, 375);
             glVertex2i(555, 385);


            glVertex2i(433, 365);
            glVertex2i(445, 375);
            glVertex2i(567, 225);
            glVertex2i(555, 215);
        glEnd();

    glPopMatrix();

    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(850, 650);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Infinite Thickness Bluetooth + Bahrain Flag");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 850, 0, 650);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);

    glutMainLoop();
    return 0;
}
