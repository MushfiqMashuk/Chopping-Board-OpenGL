/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.

 * CSE 064 07578 - Musfiq Ahmed Mashuk
 * Asif Ul Islam - cse 06407575

 */
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define PI 3.1416
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <MMSystem.h>

int c = 0, appleCount = 0, carrotCount = 0;
float cx=0, cy=0, angle=0;

bool lPressed = false, aPressed = false, sliceApple = false, slice = false, cPressed = false, sliceCarrot = false;

/* Program entry point */

void timer(int);
void myDisplayFunc();

void init(){
    glClearColor(0.75f,0.75f,0.75f,0.0f);
    glOrtho(-12, +12, -10, +10, -10, +10);

}

void circle(float radiusX, float radiusY, int density){
    int i = 0;
    float angle = 0;

    glBegin(GL_POLYGON);
    for(i=0; i<density; i++){
        angle = 2 * PI * i / density;
        glVertex2d(radiusX * cos(angle), radiusY * sin(angle));
        //printf("Angle: %f, X: %f, Y: %f\n", angle, radiusX * cos(angle), radiusY * sin(angle));
    }
    glEnd();
}

void semiCircle(float radiusX, float radiusY, int density){
    int i = 0;
    float angle = 0;

    glBegin(GL_LINE_LOOP);
    for(i=0; i<density; i++){
        angle = 2 * PI * i / density;
        glVertex2d(radiusX * cos(angle), radiusY * sin(angle));
    }
    glEnd();
}

void choppingBoard(){
    glPushMatrix();

        glTranslated(-2,1.5,0);
        glRotated(10, 0, 0, -1);

        glColor3f(1, 0.8549, 0.7254);
        glBegin(GL_POLYGON);
            glVertex2d(-8.5,6);
            glVertex2d(9,6);
            glVertex2d(9,-7);
            glVertex2d(-8.5,-7);
        glEnd();

    glPopMatrix();

    glPushMatrix();

        glTranslated(-1.5,1.4,0);
        glRotated(10, 0, 0, -1);

        glColor3f(0.41176, 0.41176, 0.41176);
        glBegin(GL_POLYGON);
            glVertex2d(8.5,6);
            glVertex2d(9,5.6);
            glVertex2d(9,-7.3);
            glVertex2d(8.5,-7);
        glEnd();

    glPopMatrix();
}

void lemon(float color1, float color2, float color3){
    glPushMatrix();

    glTranslated(2,2,0);
        // lemon 1
    glPushMatrix();
        //glTranslated();
        glColor3f(color1, color2, color3); // color- 0.2352,0.7019,0.4431
        circle(1.3,2.3,2000);

    glPopMatrix();
    // lemon 2
    glPushMatrix();
        glTranslated(0,1.5,0);
        glColor3f(color1, color2, color3);
        circle(0.4,1,2000);

    glPopMatrix();
   // lemon 3
    glPushMatrix();
        glTranslated(0,-1.5,0);
        glColor3f(color1, color2, color3);
        circle(0.4,1,2000);

    glPopMatrix();
    glPopMatrix();

    glutPostRedisplay();
}

void apple(){
    glPushMatrix();

    glTranslated(-2,2,0);
        // circle 1
    glPushMatrix();
        //glTranslated(-2,4,0);
        glColor3f(0.698,0.133,0.133);
        circle(1.6,1,2000);

    glPopMatrix();

    // circle 2
    glPushMatrix();
        glTranslated(0, 0.3, 0);
        glColor3f(0.698,0.133,0.133);
        circle(1,1,2000);

    glPopMatrix();

    // circle 3
    glPushMatrix();
        glTranslated(-0.4, -1, 0);
        glColor3f(0.698,0.133,0.133);
        circle(1.5,2.3,2000);

    glPopMatrix();

    // circle 4
    glPushMatrix();
        glTranslated(0.4, -1, 0);
        glColor3f(0.698,0.133,0.133);
        circle(1.5,2.3,2000);

    glPopMatrix();

    // semi circle
    glPushMatrix();
        glTranslated(0, 0.8, 0);
        glColor3f(0, 0, 0);
        semiCircle(0.5,0.2,2000);
        glRotated(10, 0, 0, 1);
        glTranslated(0, 0.2, 0);
        glColor3f(0.698,0.133,0.133);
        circle(0.47,0.2,2000);
    glPopMatrix();

    glPopMatrix();
}


void carrot() {


    glPushMatrix();
        glRotated(3, 0, 0, 1);
        glTranslated(-7, 6, 0);
        glColor3f(0.2352,0.7019,0.4431);
            glBegin(GL_QUADS);
            glVertex2f(0,0);
            glVertex2f(0,4);
            glVertex2f(-0.06, 4);
            glVertex2f(-0.06, 0);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glRotated(3, 1, 3, 1);
        glTranslated(-6.8, 6, 0);
        glColor3f(0.2352,0.7019,0.4431);
            glBegin(GL_QUADS);
            glVertex2f(0,0);
            glVertex2f(0,4);
            glVertex2f(-0.06, 4);
            glVertex2f(-0.06, 0);
        glEnd();
    glPopMatrix();


    glPushMatrix();
        glColor3f(1, 0.5490, 0);
        glTranslated(-7, 5.8, 0);
        circle(1.2, 2, 9000);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-7, 5.5, 0);
        circle(1.2, 2, 9000);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-7, 5, 0);
        circle(1.2, 2, 9000);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-7, 3, 0);
        circle(1.2, 3, 9000);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-7, 2, 0);
        circle(1.2, 3.2, 9000);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-7, 2, 0);
        circle(0.8, 6, 9000);
    glPopMatrix();

    glPushMatrix();
        glRotated(3, 1, 3, 1);
        glTranslated(-6.6, 7.5, 0);
        glColor3f(0.2352,0.7019,0.4431);
            glBegin(GL_QUADS);
            glVertex2f(0,0);
            glVertex2f(0,2);
            glVertex2f(-0.06, 2);
            glVertex2f(-0.06, 0);
        glEnd();
    glPopMatrix();


    glPushMatrix();
        glRotated(3, 1, 3, 1);
        glTranslated(-7, 7.5, 0);
        glColor3f(0.2352,0.7019,0.4431);
            glBegin(GL_QUADS);
            glVertex2f(0,0);
            glVertex2f(0,2);
            glVertex2f(-0.06, 2);
            glVertex2f(-0.06, 0);
        glEnd();
    glPopMatrix();

}

void lemonSlice1() {

    glPushMatrix();
    glRotated(3, 0, 0, 1);
    glTranslated(0.5, 1, 0);

    glColor3f(1, 0.8549, 0.7254);
        glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(3,0);
        glVertex2f(3, -0.06);
        glVertex2f(0, -0.06);
    glEnd();
    glPopMatrix();
}


void lemonSlice2() {

    glPushMatrix();
        glRotated(2, 0, 0, 1);
        glTranslated(0.5, 2, 0);
        glColor3f(1, 0.8549, 0.7254);
        glBegin(GL_QUADS);
            glVertex2f(0,0);
            glVertex2f(3,0);
            glVertex2f(3, -0.06);
            glVertex2f(0, -0.06);
        glEnd();
    glPopMatrix();
}


void lemonSlice3() {

    glPushMatrix();
        glRotated(3, 0, 0, -1);
        glTranslated(0.5, 3, 0);
        glColor3f(1, 0.8549, 0.7254);
            glBegin(GL_QUADS);
            glVertex2f(0,0);
            glVertex2f(3,0);
            glVertex2f(3, -0.06);
            glVertex2f(0, -0.06);
        glEnd();
    glPopMatrix();
}

void appleSlice1() {

    glPushMatrix();
        glRotated(3, 0, 0, -1);
        glTranslated(-4, 2.3, 0);
        glColor3f(1, 0.8549, 0.7254);
            glBegin(GL_QUADS);
            glVertex2f(0,0);
            glVertex2f(4,0);
            glVertex2f(4, -0.06);
            glVertex2f(0, -0.06);
        glEnd();
    glPopMatrix();
}


void appleSlice2() {

    glPushMatrix();
        glRotated(3, 0, 0, -1);
        glTranslated(-4.2, 1, 0);
        glColor3f(1, 0.8549, 0.7254);
            glBegin(GL_QUADS);
            glVertex2f(0,0);
            glVertex2f(4.3,0);
            glVertex2f(4.3, -0.06);
            glVertex2f(0, -0.06);
        glEnd();
    glPopMatrix();
}


void appleSlice3() {

    glPushMatrix();
        glRotated(3, 0, 0, 1);
        glTranslated(-4, -0.5, 0);
        glColor3f(1, 0.8549, 0.7254);
            glBegin(GL_QUADS);
            glVertex2f(0,0);
            glVertex2f(4,0);
            glVertex2f(4, -0.06);
            glVertex2f(0, -0.06);
        glEnd();
    glPopMatrix();
}

void carrotSlice1() {

    glPushMatrix();
        glRotated(3, 0, 0, -1);
        glTranslated(-9, 6, 0);
        glColor3f(1, 0.8549, 0.7254);
            glBegin(GL_QUADS);
            glVertex2f(0,0);
            glVertex2f(4,0);
            glVertex2f(4, -0.06);
            glVertex2f(0, -0.06);
        glEnd();
    glPopMatrix();
}

void carrotSlice2() {

    glPushMatrix();
        glRotated(3, 0, 0, -1);
        glTranslated(-9, 4, 0);
        glColor3f(1, 0.8549, 0.7254); // 1, 0.8549, 0.7254
            glBegin(GL_QUADS);
            glVertex2f(0,0);
            glVertex2f(4,0);
            glVertex2f(4, -0.06);
            glVertex2f(0, -0.06);
        glEnd();
    glPopMatrix();
}

void carrotSlice3() {

    glPushMatrix();
        glRotated(3, 0, 0, -1);
        glTranslated(-9, 1, 0);
        glColor3f(1, 0.8549, 0.7254);
            glBegin(GL_QUADS);
            glVertex2f(0,0);
            glVertex2f(4,0);
            glVertex2f(4, -0.06);
            glVertex2f(0, -0.06);
        glEnd();
    glPopMatrix();
}

void carrotSlice4() {

    glPushMatrix();
        glRotated(3, 0, 0, -1);
        glTranslated(-9, -2, 0);
        glColor3f(1, 0.8549, 0.7254);
            glBegin(GL_QUADS);
            glVertex2f(0,0);
            glVertex2f(4,0);
            glVertex2f(4, -0.06);
            glVertex2f(0, -0.06);
        glEnd();
    glPopMatrix();
}


void cuttingLemon() {

        if(c == 1) {

            PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);

            lemonSlice1();

        }

    //clock_t start_time = clock();

    //while(clock() <= start_time + 1000);

    // 2nd slice

        if(c == 2) {
            lemonSlice1();
            lemonSlice2();
        }

    // 3rd slice

        if(c == 3) {
            lemonSlice1();
            lemonSlice2();
            lemonSlice3();
        }

}

void cuttingApple() {

        if(appleCount == 1) {

            PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);

            appleSlice1();

        }

        if(appleCount == 2) {
            appleSlice1();

            PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);
            appleSlice2();
        }

        if(appleCount == 3) {
            appleSlice1();
            appleSlice2();

            PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);
            appleSlice3();
        }

}

void cuttingCarrot() {

        if(carrotCount == 1) {

            PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);

            carrotSlice1();

        }

        if(carrotCount == 2) {

            carrotSlice1();

            PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);
            carrotSlice2();

        }

        if(carrotCount == 3) {

            carrotSlice1();
            carrotSlice2();

            PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);
            carrotSlice3();

        }

        if(carrotCount == 4) {

            carrotSlice1();
            carrotSlice2();
            carrotSlice3();

            PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);
            carrotSlice4();

        }



}


void timer(int i) {

    if(i == 0) {
        if(c == 3) {
        //c = 0;
        return;
    }
        else {
            slice = true;

            c += 1;
            glutPostRedisplay();
            glutTimerFunc(1000, timer, 0);
        }
    }

    if(i == 1) {
        if(appleCount == 3){
            return;
        }
        else {
            sliceApple = true;

            appleCount += 1;
            glutPostRedisplay();
            glutTimerFunc(1000, timer, 1);
        }
    }

    if(i == 2){
        if(carrotCount == 4){
            return;
        }
        else {
            sliceCarrot = true;

            carrotCount += 1;
            glutPostRedisplay();
            glutTimerFunc(1000, timer, 2);
        }
    }

}


void myDisplayFunc(){
    glClear(GL_COLOR_BUFFER_BIT);

    choppingBoard();

    carrot();

    if(sliceCarrot){
        cuttingCarrot();
    }

    apple();

    if(sliceApple){
        cuttingApple();
    }

    lemon(0.2352,0.7019,0.4431);

    if(slice) {
        cuttingLemon();
    }

    glFlush();

}

void normalKey(unsigned char key, int x, int y){
    switch(key){
        case 'l':

            if( !lPressed ){
                lPressed = true;
                glutTimerFunc(0, timer, 0);
            }
            else {
                c = 0;
                lPressed = false;
            }

            break;

        case 'a':

            if( !aPressed ){
                aPressed = true;
                glutTimerFunc(0, timer, 1);
            }
            else {
                appleCount = 0;
                aPressed = false;
            }

            break;

        case 'c':

            if( !cPressed ){
                cPressed = true;
                glutTimerFunc(0, timer, 2);
            }
            else {
                carrotCount = 0;
                cPressed = false;
            }

            break;

        default:
            break;
    }
}

int main()
{
    //glutInit(&argc, argv);
    glutInitWindowSize(1200,1200);
    glutInitWindowPosition(100,20);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("CSE 064 07578-Musfiq Ahmed Mashuk, Asif Ul Islam cse 06407575");
    init();
    glutDisplayFunc(myDisplayFunc);

    glutKeyboardFunc(normalKey);

    //sndPlaySound("sound.wav", SND_ASYNC);

    glutMainLoop(); //recursively main function k call korte thake

   return 0;
}
