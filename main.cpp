/* 
 * File:   main.cpp
 * Author: anthony
 *
 * Created on November 22, 2010, 7:02 PM
 */
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>
using namespace std;

static GLfloat spin_z = 0.0;
static GLfloat spin_x = 0.0;
static GLfloat spin_y = 0.0;

void init(void);
void display(void);
void reshape(int, int);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);

/*
 * 
 */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640,480);
    glutCreateWindow("OpenGL.20101122.SpinningSquare");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    // call our main loop
    glutMainLoop();

    return 0;
}

void init(void) {
    // set the clear color
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glRotatef(spin_z, 0.0, 0.0, 1.0);
    glRotatef(spin_y, 0.0, 1.0, 0.0);
    glRotatef(spin_x, 1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.0);
        glVertex2f(20.0, 0.0);
        glVertex2f(20.0, 20.0);
        glVertex2f(0.0, 20.0);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 27:
            exit(0);
            break;
        case 32:
            spin_z += 1.0;
            if(spin_z > 360.0)
                spin_z = spin_z - 360.0;
            cout << "spin_z: " << spin_z << endl;
            glutPostRedisplay();
            break;
        case 97:
            spin_y -= 1.0;
            if(spin_y < 0.0)
                spin_y = spin_y + 360.0;
            cout << "spin_y: " << spin_y << endl;
            glutPostRedisplay();
            break;
        case 100:
            spin_y += 1.0;
            if(spin_y > 360.0)
                spin_y = spin_y - 360.0;
            cout << "spin_y: " << spin_y << endl;
            glutPostRedisplay();
            break;
        case 115:
            spin_x -= 1.0;
            if(spin_y < 0.0)
                spin_x = spin_x + 360.0;
            cout << "spin_x: " << spin_x << endl;
            glutPostRedisplay();
            break;
        case 119:
            spin_x += 1.0;
            if(spin_x > 360.0)
                spin_x = spin_x - 360.0;
            cout << "spin_y: " << spin_x << endl;
            glutPostRedisplay();
            break;

        case 113:
            spin_x = spin_y = spin_z = 0;
            glutPostRedisplay();
            break;

        default: break;
    }
}

void mouse(int button, int state, int x, int y) {
    
}