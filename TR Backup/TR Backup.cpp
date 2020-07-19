#include <iostream>
#include <GL/freeglut.h>

void init(void);
void object(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);

int is_depth;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(5.0);
    glLineWidth(3.0f);
}


void object(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.6, 0.6, 1.6);
    glBegin(GL_TRIANGLES);
    glVertex3f(20.0, 0.0, -20.0);
    glVertex3f(20.0, 0.0, 20.0);
    glVertex3f(0.0, 30.0, 0.0);
    glEnd();

    /////////////////
    glColor3f(0, 255, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(-20.0, 0.0, -20.0);
    glVertex3f(20.0, 0.0, -20.0);
    glVertex3f(0.0, -30.0, 0.0);
    glEnd();

    glColor3f(255, 255, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(-20.0, 0.0, -20.0);
    glVertex3f(-20.0, 0.0, 20.0);
    glVertex3f(0.0, -30.0, 0.0);
    glEnd();

    glColor3f(128, 0, 128);
    glBegin(GL_TRIANGLES);
    glVertex3f(-20.0, 0.0, 20.0);
    glVertex3f(20.0, 0.0, 20.0);
    glVertex3f(0.0, -30.0, 0.0);
    glEnd();

    glColor3f(0, 0, 255);
    glBegin(GL_TRIANGLES);
    glVertex3f(20.0, 0.0, -20.0);
    glVertex3f(20.0, 0.0, 20.0);
    glVertex3f(0.0, -30.0, 0.0);
    glEnd();

    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':                                   ////zoom in
    case 'W':
        glScalef(0.75, 0.75, 0.75);
        break;
    case 'd':                                   ////geser kanan
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 's':                                    ///zoom out
    case 'S':
        glScalef(1.75, 1.75, 1.75);
        break;
    case 'a':                                   ////geser kiri
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case'q':                                    ////gser atas
    case'Q':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case 'e':
    case 'E':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case 'x':                                   ///putar kanan ke kiri
    case 'X':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case 'z':                                   ///putar kiri ke kanan 
    case 'Z':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    }
    object();
}

void specialKeyboard(int key, int x, int y)
{

    switch (key) {
    case 100:
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case 101:
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case 102:
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case 103:
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    }
    glutPostRedisplay();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Tugas Transformasi-672018152");
    init();
    glutDisplayFunc(object);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeyboard);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}