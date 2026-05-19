#include <GL/glut.h>
#include <windows.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
float logoX = 0.0f, logoY = 0.0f, logoAngle = 0.0f, logoScale = 1.0f;
float flagX = 0.0f, flagY = 0.0f, flagAngle = 0.0f, flagScale = 1.0f;
float waveTime = 0.0f;
float windScale = 0.5f;
float flagLift = 1.0f;

<<<<<<< HEAD
void renderText(float x, float y, std::string text, void* font, float r, float g, float b) {
   glColor3f(r, g, b);
   glRasterPos2f(x, y);
   for (char c : text) {
       glutBitmapCharacter(font, c);
    }
}

void renderHUD() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.0f, 0.0f, 0.0f, 0.65f);
    glBegin(GL_QUADS);
        glVertex2f(0, 685);
        glVertex2f(1200, 685);
        glVertex2f(1200, 750);
        glVertex2f(0, 750);
    glEnd();
    glDisable(GL_BLEND);

    if (isAnimated) {
        renderText(15, 730, "[ STATUS: RUNNING ]", GLUT_BITMAP_HELVETICA_12, 0.2f, 1.0f, 0.2f);
        renderText(15, 715, "Double-Click Logo to PAUSE", GLUT_BITMAP_HELVETICA_10, 0.7f, 0.7f, 0.7f);
   } else {
        renderText(15, 730, "[ STATUS: PAUSED ]", GLUT_BITMAP_HELVETICA_12, 1.0f, 0.2f, 0.2f);
        renderText(15, 715, "Double-Click Logo to RESUME", GLUT_BITMAP_HELVETICA_10, 0.7f, 0.7f, 0.7f);
}
    if (isNight) {
        renderText(185, 730, "ENVIRONMENT: NIGHT (MOON)", GLUT_BITMAP_HELVETICA_12, 0.7f, 0.8f, 1.0f);
        renderText(185, 715, "Single-Click Logo to shift DAY", GLUT_BITMAP_HELVETICA_10, 0.7f, 0.7f, 0.7f);
    } else {
     renderText(185, 730, "ENVIRONMENT: DAYTIME (SUN)", GLUT_BITMAP_HELVETICA_12, 1.0f, 0.9f, 0.0f);
        renderText(185, 715, "Single-Click Logo to shift NIGHT", GLUT_BITMAP_HELVETICA_10, 0.7f, 0.7f, 0.7f);
  }

    int windPercent = (int)((windScale / 3.0f) * 100.0f);
    if (windPercent > 100) windPercent = 100;
    std::string windStr = "WIND INTENSITY: " + std::to_string(windPercent) + "%";
    renderText(400, 730, windStr, GLUT_BITMAP_HELVETICA_12, 0.3f, 0.8f, 1.0f);
    renderText(400, 715, "Press '1' / '2' to Adjust", GLUT_BITMAP_HELVETICA_10, 0.7f, 0.7f, 0.7f);

    std::string zoomStr = "VIEW CAMERA ZOOM: " + std::to_string((int)(zoomFactor * 100)) + "%";
    renderText(615, 730, zoomStr, GLUT_BITMAP_HELVETICA_12, 1.0f, 0.6f, 0.2f);
    renderText(615, 715, "Press '8' Zoom Out / '9' In", GLUT_BITMAP_HELVETICA_10, 0.7f, 0.7f, 0.7f);

    std::string scalesStr = "SCALE -> Logo: " + std::to_string((int)(logoScale * 100)) + "% | Flag: " + std::to_string((int)(flagScale * 100)) + "%";
    renderText(825, 730, scalesStr, GLUT_BITMAP_HELVETICA_10, 1.0f, 1.0f, 1.0f);
    renderText(825, 715, "Keys: Logo [n,m] | Flag [b,u]", GLUT_BITMAP_HELVETICA_10, 0.7f, 0.7f, 0.7f);

    std::string rotStr = "ROTATION -> Logo: " + std::to_string((int)logoAngle % 360) + " deg | Flag: " + std::to_string((int)flagAngle % 360) + " deg";
    renderText(825, 700, rotStr, GLUT_BITMAP_HELVETICA_10, 0.9f, 0.9f, 0.9f);

    renderText(15, 695, "TRANSLATIONS (MOVE) -> Logo Keys: W, A, S, D  |  Flag Keys: G, H, J, Y", GLUT_BITMAP_HELVETICA_10, 0.8f, 0.8f, 0.8f);
    renderText(400, 695, "ROTATION CONTROLS -> Logo Keys: R, T  |  Flag Keys: I, O", GLUT_BITMAP_HELVETICA_10, 0.8f, 0.8f, 0.8f);
}


void renderText(float x, float y, std::string text, void* font, float r, float g, float b) {
    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    for (char c : text) {
        glutBitmapCharacter(font, c);
    }
}

void renderHUD() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.0f, 0.0f, 0.0f, 0.65f);
    glBegin(GL_QUADS);
        glVertex2f(0, 685);
        glVertex2f(1200, 685);
        glVertex2f(1200, 750);
        glVertex2f(0, 750);
    glEnd();
    glDisable(GL_BLEND);

    if (isAnimated) {
        renderText(15, 730, "[ STATUS: RUNNING ]", GLUT_BITMAP_HELVETICA_12, 0.2f, 1.0f, 0.2f);
        renderText(15, 715, "Double-Click Logo to PAUSE", GLUT_BITMAP_HELVETICA_10, 0.7f, 0.7f, 0.7f);
    } else {
        renderText(15, 730, "[ STATUS: PAUSED ]", GLUT_BITMAP_HELVETICA_12, 1.0f, 0.2f, 0.2f);
        renderText(15, 715, "Double-Click Logo to RESUME", GLUT_BITMAP_HELVETICA_10, 0.7f, 0.7f, 0.7f);
    }

    if (isNight) {
        renderText(185, 730, "ENVIRONMENT: NIGHT (MOON)", GLUT_BITMAP_HELVETICA_12, 0.7f, 0.8f, 1.0f);
        renderText(185, 715, "Single-Click Logo to shift DAY", GLUT_BITMAP_HELVETICA_10, 0.7f, 0.7f, 0.7f);
    } else {
        renderText(185, 730, "ENVIRONMENT: DAYTIME (SUN)", GLUT_BITMAP_HELVETICA_12, 1.0f, 0.9f, 0.0f);
        renderText(185, 715, "Single-Click Logo to shift NIGHT", GLUT_BITMAP_HELVETICA_10, 0.7f, 0.7f, 0.7f);
    }

    int windPercent = (int)((windScale / 3.0f) * 100.0f);
    if (windPercent > 100) windPercent = 100;
    std::string windStr = "WIND INTENSITY: " + std::to_string(windPercent) + "%";
    renderText(400, 730, windStr, GLUT_BITMAP_HELVETICA_12, 0.3f, 0.8f, 1.0f);
    renderText(400, 715, "Press '1' / '2' to Adjust", GLUT_BITMAP_HELVETICA_10, 0.7f, 0.7f, 0.7f);

    std::string zoomStr = "VIEW CAMERA ZOOM: " + std::to_string((int)(zoomFactor * 100)) + "%";
    renderText(615, 730, zoomStr, GLUT_BITMAP_HELVETICA_12, 1.0f, 0.6f, 0.2f);
    renderText(615, 715, "Press '8' Zoom Out / '9' In", GLUT_BITMAP_HELVETICA_10, 0.7f, 0.7f, 0.7f);

    std::string scalesStr = "SCALE -> Logo: " + std::to_string((int)(logoScale * 100)) + "% | Flag: " + std::to_string((int)(flagScale * 100)) + "%";
    renderText(825, 730, scalesStr, GLUT_BITMAP_HELVETICA_10, 1.0f, 1.0f, 1.0f);
    renderText(825, 715, "Keys: Logo [n,m] | Flag [b,u]", GLUT_BITMAP_HELVETICA_10, 0.7f, 0.7f, 0.7f);

    std::string rotStr = "ROTATION -> Logo: " + std::to_string((int)logoAngle % 360) + " deg | Flag: " + std::to_string((int)flagAngle % 360) + " deg";
    renderText(825, 700, rotStr, GLUT_BITMAP_HELVETICA_10, 0.9f, 0.9f, 0.9f);

    renderText(15, 695, "TRANSLATIONS (MOVE) -> Logo Keys: W, A, S, D  |  Flag Keys: G, H, J, Y", GLUT_BITMAP_HELVETICA_10, 0.8f, 0.8f, 0.8f);
    renderText(400, 695, "ROTATION CONTROLS -> Logo Keys: R, T  |  Flag Keys: I, O", GLUT_BITMAP_HELVETICA_10, 0.8f, 0.8f, 0.8f);
}


=======
void handleMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int currentTime = glutGet(GLUT_ELAPSED_TIME);
        float mouseX = (float)x;
        float mouseY = (float)(750 - y);
        float logoWorldCenterX = logoX + 750.0f;
        float logoWorldCenterY = logoY + 350.0f;
        float distance = sqrt(pow(mouseX - logoWorldCenterX, 2) + pow(mouseY - logoWorldCenterY, 2));

        if (distance < 110.0f * logoScale) {
            if (currentTime - lastClickTime < 300) {
                isAnimated = !isAnimated;
            } else {
                isNight = !isNight;
            }
            lastClickTime = currentTime;
        }
    }
    glutPostRedisplay();
}

>>>>>>> origin/dave-mousehandling

void drawCelestialBody(float cx, float cy, float r, int segments, bool isSun) {
    glPushMatrix();
    glTranslatef(cx, cy, 0.0f);

    if (isSun && !isNight) {
        glScalef(sunCorePulse, sunCorePulse, 1.0f);
    }

    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(segments);
        glVertex2f(r * cosf(theta), r * sinf(theta));
    }
    glEnd();

    if (isSun && !isNight) {
        glRotatef(sunRayRotation, 0.0f, 0.0f, 1.0f);
        float rayPulse = isAnimated ? (sin(waveTime * 2.0f) * 0.1f + 0.9f) : 1.0f;
        glColor3f(1.0f, 0.7f * rayPulse, 0.0f);
        glLineWidth(2.0f);
        glBegin(GL_LINES);
        for (int i = 0; i < 16; i++) {
            float theta = 2.0f * M_PI * float(i) / 16.0f;
            glVertex2f(r * cosf(theta), r * sinf(theta));
            glVertex2f((r * 1.5f) * cosf(theta), (r * 1.5f) * sinf(theta));
        }
        glEnd();
    }
    glPopMatrix();
}

void drawStars() {
    srand(42);
    glBegin(GL_POINTS);
    for (int i = 0; i < 150; i++) {
        float x = (float)(rand() % 1200);
        float y = (float)(rand() % 750);
        float twinkle = isAnimated ? (sin(waveTime * 2.0f + i) * 0.5f + 0.5f) : 1.0f;
        glColor3f(twinkle, twinkle, twinkle);
        glVertex2f(x, y);
    }
    glEnd();
}




void handleMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int currentTime = glutGet(GLUT_ELAPSED_TIME);
        float mouseX = (float)x;
        float mouseY = (float)(750 - y);
        float logoWorldCenterX = logoX + 750.0f;
        float logoWorldCenterY = logoY + 350.0f;
        float distance = sqrt(pow(mouseX - logoWorldCenterX, 2) + pow(mouseY - logoWorldCenterY, 2));

        if (distance < 110.0f * logoScale) {
            if (currentTime - lastClickTime < 300) {
                isAnimated = !isAnimated;
            } else {
                isNight = !isNight;
            }
            lastClickTime = currentTime;
        }
    }
    glutPostRedisplay();
}




void timer(int value) {
    float effectiveWind = (isAnimated) ? windScale : 0.15f;
    if (effectiveWind < 0.1f) effectiveWind = 0.1f;

    waveTime += (0.025f * effectiveWind);

    if (isAnimated) {
        if (!isNight && flagLift < 1.0f) flagLift += 0.005f;
        if (isNight && flagLift > 0.0f) flagLift -= 0.005f;

        sunRayRotation += 0.45f;
        if (sunRayRotation > 360.0f) sunRayRotation -= 360.0f;

        sunCorePulse = 1.0f + (sinf(waveTime * 2.5f) * 0.05f);

        moonOrbitOffsetX = sinf(waveTime * 0.8f) * 20.0f;
        moonOrbitOffsetY = cosf(waveTime * 0.4f) * 8.0f;
        moonShadowMaskX = 20.0f + (sinf(waveTime * 0.5f) * 4.0f);
    }

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}


// Inside display()
glPushMatrix();
    glTranslatef(flagX, flagY, 0.0f);
    glTranslatef(150, 0, 0);
    glRotatef(flagAngle, 0, 0, 1);
    glScalef(flagScale, flagScale, 1);
    glTranslatef(-150, 0, 0);

    float tieOffY = 220.0f;
    float liftMax = 420.0f;
    int flagBottom = (int)tieOffY + (int)(flagLift * liftMax);
    int flagTop = flagBottom + 185;
    float flagStart = 62.0f;
    float poleHeight = 840.0f;

    // Flag pole and decorations
    glColor3f(0.0f, 0.0f, 1.0f); glRecti(10, 0, 90, 30);
    glColor3f(0.6f, 0.1f, 0.6f); glRecti(25, 30, 75, 55);
    glColor3f(0.3f, 0.3f, 0.5f); glRecti(35, 55, 65, 75);
    glColor3f(0.7f, 0.7f, 0.7f); glRecti(46, 75, 54, poleHeight);

    // Rope and rings
    float ringRadius = 15.0f;
    glColor3f(0.7f, 0.7f, 0.7f); glLineWidth(3.0f);
    drawRingArc(50, (float)flagTop, ringRadius, true);
    drawRingArc(50, (float)flagBottom, ringRadius, true);

    float ropeStartX = 50 + ringRadius;
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glVertex2f(ropeStartX, (float)flagTop); glVertex2f(ropeStartX, tieOffY);
        glVertex2f(ropeStartX, (float)flagTop); glVertex2f(flagStart, (float)flagTop);
        glVertex2f(ropeStartX, (float)flagBottom); glVertex2f(flagStart, (float)flagBottom);
        glVertex2f(50.0f + 10.0f, tieOffY); glVertex2f(ropeStartX, tieOffY);
    glEnd();

    // Waving flag effect
    float currentWind = (isAnimated) ? windScale : 0.3f;
    for (float x = flagStart; x < 480.0f; x += 1.0f) {
        float distFromPole = (x - 50);
        float yWave = (distFromPole * (0.15f * currentWind)) * sin(0.05f * x + waveTime);
        float xWave = (distFromPole * (0.03f * currentWind)) * cos(0.05f * x + waveTime);

        if (x < 160.0f) glColor3f(1.0f, 1.0f, 1.0f);
        else glColor3f(0.85f, 0.0f, 0.0f);

        glBegin(GL_QUAD_STRIP);
            glVertex2f(x + xWave, (float)flagBottom + yWave);
            glVertex2f(x + xWave, (float)flagTop + yWave);
            float nextX = x + 1.0f;
            float nYW = ((nextX - 50) * (0.15f * currentWind)) * sin(0.05f * nextX + waveTime);
            float nXW = ((nextX - 50) * (0.03f * currentWind)) * cos(0.05f * nextX + waveTime);
            glVertex2f(nextX + nXW, (float)flagBottom + nYW);
            glVertex2f(nextX + nXW, (float)flagTop + nYW);
        glEnd();
    }

    // Triangular flag details
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    float triH = (float)(flagTop - flagBottom) / 5.0f;
    for (float y = (float)flagBottom; y < (float)flagTop; y += triH) {
        float ywB = ((160.0f - 50) * (0.15f * currentWind)) * sin(0.05f * 160.0f + waveTime);
        float xwB = ((160.0f - 50) * (0.03f * currentWind)) * cos(0.05f * 160.0f + waveTime);
        float tX = 160.0f + 60.0f;
        float ywT = ((tX - 50) * (0.15f * currentWind)) * sin(0.05f * tX + waveTime);
        float xwT = ((tX - 50) * (0.03f * currentWind)) * cos(0.05f * tX + waveTime);
        glVertex2f(160.0f + xwB, y + ywB);
        glVertex2f(tX + xwT, y + (triH / 2.0f) + ywT);
        glVertex2f(160.0f + xwB, y + triH + ywB);
    }
    glEnd();
glPopMatrix();

// Logo drawing
glPushMatrix();
    float cX = 750.0f, cY = 350.0f;
    float breath = isAnimated ? (float)(0.06 * sin(waveTime * 1.2)) : 0.0f;
    float bluePulse = isAnimated ? (float)(0.85 + (0.15 * sin(waveTime * 1.5))) : 1.0f;

    glTranslatef(logoX + cX, logoY + cY, 0.0f);
    glRotatef(logoAngle, 0, 0, 1);
    glScalef(logoScale + breath, logoScale + breath, 1.0f);

    if (isNight) glColor3f(0.2f, 0.2f, 0.4f);
    else glColor3f(0.0f, 0.51f, bluePulse);
    if (!isAnimated) glColor3f(0.5f, 0.5f, 0.5f);

    glBegin(GL_POLYGON);
        for (int i = 0; i <= 360; i++) {
            float r = (float)i * M_PI / 180.0f;
            glVertex2f(cos(r) * 110.0f, ((i > 180) ? -85.0f : 85.0f) + sin(r) * 110.0f);
        }
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-7.0f, -90.0f); glVertex2f(7.0f, -90.0f);
        glVertex2f(7.0f, 





void drawRingArc(float cx, float cy, float radius, bool isFront) {
    glBegin(GL_LINE_STRIP);
    int start = isFront ? 270 : 90;
    int end = isFront ? 450 : 270;
    for (int i = start; i <= end; i++) {
        float rad = (float)i * M_PI / 180.0f;
        glVertex2f(cx + cos(rad) * radius, cy + sin(rad) * (radius * 0.4f));
    }
    glEnd();
}

void drawCircle(float cx, float cy, float r) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = 2.0f * M_PI * float(i) / 360.0f;
        glVertex2f(cx + r * cosf(theta), cy + r * sinf(theta));
    }
    glEnd();
}
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': logoY += 10.0f; break;
        case 's': logoY -= 10.0f; break;
        case 'a': logoX -= 10.0f; break;
        case 'd': logoX += 10.0f; break;
        case 'r': logoAngle += 5.0f; break;
        case 't': logoAngle -= 5.0f; break;
        case 'm': logoScale += 0.1f; break;
        case 'n': if (logoScale > 0.1) logoScale -= 0.1f; break;
        case 'y': flagY += 10.0f; break;
        case 'h': flagY -= 10.0f; break;
        case 'g': flagX -= 10.0f; break;
        case 'j': flagX += 10.0f; break;
        case 'i': flagAngle += 5.0f; break;
        case 'o': flagAngle -= 5.0f; break;
        case 'u': flagScale += 0.1f; break;
        case 'b': if (flagScale > 0.1) flagScale -= 0.1f; break;
        case '2': if (windScale < 3.0f) windScale += 0.1f; break;
        case '1': if (windScale > 0.1f) windScale -= 0.1f; break;
        case 27: exit(0); break;
    }
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        glPushMatrix();
            glTranslatef(flagX, flagY, 0.0f);
            glTranslatef(150, 0, 0);
            glRotatef(flagAngle, 0, 0, 1);
            glScalef(flagScale, flagScale, 1);
            glTranslatef(-150, 0, 0);

            float tieOffY = 220.0f;
            int flagBottom = 640;
            int flagTop = 825;
            float flagStart = 62.0f;
            int poleHeight = 840;
            glColor3f(0.0, 0.0, 1.0);
            glBegin(GL_QUADS);
                glVertex2i(10, 0);
                 glVertex2i(90, 0);
                 glVertex2i(90, 30);
                 glVertex2i(10, 30);
            glEnd();


            glColor3f(0.6, 0.1, 0.6);
            glBegin(GL_QUADS);
                glVertex2i(25, 30);
                glVertex2i(75, 30);
                glVertex2i(75, 55);
                glVertex2i(25, 55);
            glEnd();

            glColor3f(0.3, 0.3, 0.5);
            glBegin(GL_QUADS);
                glVertex2i(35, 55);
                glVertex2i(65, 55);
                glVertex2i(65, 75);
                glVertex2i(35, 75);
            glEnd();

            glColor3f(0.7, 0.7, 0.7);
            glBegin(GL_QUADS);
                glVertex2i(46, 75);
                glVertex2i(54, 75);
                glVertex2i(54, 840);
                glVertex2i(46, 840);
            glEnd();
            glColor3f(0.5, 0.5, 0.5);
            drawCircle(50, 845, 10);
            glColor3f(0.7, 0.7, 0.7);
             glLineWidth(3.0f);
            drawRingArc(50, 825.0f, 15.0f, true);
            drawRingArc(50, 640.0f, 15.0f, true);

            glColor3f(0.1, 0.1, 0.1);
            glLineWidth(2.5f);
            glBegin(GL_LINES);
                glVertex2f(65.0f, 825.0f);
                glVertex2f(65.0f, 220.0f);
                glVertex2f(65.0f, 825.0f);
                glVertex2f(62.0f, 825.0f);
                glVertex2f(65.0f, 640.0f);
                glVertex2f(62.0f, 640.0f);
                glVertex2f(60.0f, 220.0f);
                glVertex2f(65.0f, 220.0f);
            glEnd();
            glColor3f(0.2, 0.2, 0.2);
            glBegin(GL_LINE_LOOP);
                for(int i=0; i<360; i++) {
                    float rad = i*M_PI/180.0f;
                    glVertex2f(50.0f + cos(rad) * 10.0f, 220.0f + sin(rad) * 4.0f);
                }
            glEnd();
            for (float x = 62.0f; x < 480.0f; x += 1.0f) {
                float dist = x - 50.0f;
                float yW = (dist * (0.15f * windScale)) * sin(0.05f * x + waveTime);
                float xW = (dist * (0.03f * windScale)) * cos(0.05f * x + waveTime);

                if (x < 160.0f) glColor3f(1.0, 1.0, 1.0);
                else glColor3f(0.85, 0.0, 0.0);

                glBegin(GL_QUAD_STRIP);
                    glVertex2f(x + xW, 640.0f + yW);
                    glVertex2f(x + xW, 825.0f + yW);
                    float nx = x + 1.0f;
                    float nYW = ((nx - 50.0f) * (0.15f * windScale)) * sin(0.05f * nx + waveTime);
                    float nXW = ((nx - 50.0f) * (0.03f * windScale)) * cos(0.05f * nx + waveTime);
                    glVertex2f(nx + nXW, 640.0f + nYW);
                    glVertex2f(nx + nXW, 825.0f + nYW);
                glEnd();
            }
            glColor3f(1.0, 1.0, 1.0);
            glBegin(GL_TRIANGLES);
                float ywB = (110.0f * (0.15f * windScale)) * sin(8.0f + waveTime);
                float xwB = (110.0f * (0.03f * windScale)) * cos(8.0f + waveTime);
                float ywT = (170.0f * (0.15f * windScale)) * sin(11.0f + waveTime);
                float xwT = (170.0f * (0.03f * windScale)) * cos(11.0f + waveTime);

                for (float y = 640.0f; y < 825.0f; y += 37.0f) {
                    glVertex2f(160.0f + xwB, y + ywB);
                    glVertex2f(220.0f + xwT, y + 18.5f + ywT);
                    glVertex2f(160.0f + xwB, y + 37.0f + ywB);
                }
            glEnd();
        glPopMatrix();
        glPushMatrix();
            float cX = 750.0f, cY = 350.0f;
            glTranslatef(logoX + cX, logoY + cY, 0.0f);
            glRotatef(logoAngle, 0, 0, 1);
            glScalef(logoScale, logoScale, 1.0f);

            glColor3f(0.0, 0.51, 1.0);
            glBegin(GL_POLYGON);
                for (int i = 0; i <= 360; i++) {
                    float r = (float)i * M_PI / 180.0f;
                    glVertex2f(cos(r) * 110.0f, ((i > 180) ? -85.0f : 85.0f) + sin(r) * 110.0f);
                }
            glEnd();

            glColor3f(1.0f, 1.0f, 1.0f);
            glBegin(GL_QUADS);
                glVertex2f(-7.0f, -90.0f);
                glVertex2f(7.0f, -90.0f);
                glVertex2f(7.0f, 90.0f);
                glVertex2f(-7.0f, 90.0f);
                glVertex2f(-62.0f, -55.0f);
                glVertex2f(-48.0f, -55.0f);
                glVertex2f(47.0f, 40.0f);
                glVertex2f(33.0f, 40.0f);
                glVertex2f(-62.0f, 55.0f);
                glVertex2f(-48.0f, 55.0f);
                glVertex2f(47.0f, -40.0f);
                glVertex2f(33.0f, -40.0f);
                glVertex2f(-7.0f, 90.0f);
                glVertex2f(7.0f, 90.0f);
                glVertex2f(47.0f, 40.0f);
                 glVertex2f(33.0f, 40.0f);
                glVertex2f(-7.0f, -90.0f);
                glVertex2f(7.0f, -90.0f);
                glVertex2f(47.0f, -40.0f);
                 glVertex2f(33.0f, -40.0f);
            glEnd();
        glPopMatrix();
    glPopMatrix();

    glFlush();
}
void update() {
    waveTime += 0.005f * windScale;
    glutPostRedisplay();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 750);
    glutInitWindowPosition(20, 20);
    glutIdleFunc(update);

    glutCreateWindow("Animation included");

    glClearColor(0.6, 0.8, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1200.0, 0.0, 750.0);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);

    glutMainLoop();
    return 0;
}
