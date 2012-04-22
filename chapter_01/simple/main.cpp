/*
 * For the Libraries you would do
 * Project Properties-> Build-> Linker-> Libraries
 * click on Add Library.
 * 
 * To compile under Ubuntu:
 * g++ main.cpp -lGL -lglut -lGLU
*/

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

void Init();
void Mouse(int button, int state, int x, int y);
void Keyboard(unsigned char key, int x, int y);
void Menu(int option);
void Animation();
void Reshape(int w, int h);
void Display();

void Init() {
    int mainMenu;
    
    mainMenu = glutCreateMenu(Menu);
    
    glutSetMenu(mainMenu);
    glutAddMenuEntry("Exit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glEnable(GL_DEPTH_TEST);
}

void Mouse(int button, int state, int x, int y) {
    switch(button) {
        case GLUT_LEFT_BUTTON:
                {
                        exit(0);
                }
                break;
        default:
                break;
    }
    glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'q' :
            {
                exit(0);

            }
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void Menu(int option) {
    switch(option) {
        case 0:
            {
                exit(0);
            }
        break;
        default:
            break;
    }
    glutPostRedisplay();
}

void Animation() {
    glutPostRedisplay();
}

void Reshape(int w, int h) {
    if(h == 0) {
        return;
    }
    
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, w / h, 1.0, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
}

void Display() {
    
    glLoadIdentity();
    gluLookAt(0.0, 1.0, 6.0,
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0
            );
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(2.0, 2.5, -1.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(-3.5, -2.5, -1.0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(2.0, -4.0, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-1.0, 2.0, 0.0);
        glColor3f(1.0, 1.0, 0.0);
        glVertex3f(-1.0, 2.0, 0.0);
        glColor3f(0.0, 1.0, 1.0);
        glVertex3f(-1.5, -3.0, 0.0);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(1.0, -2.0, 0.0);
        glColor3f(1.0, 0.0, 1.0);
        glVertex3f(1.0, 1.0, 0.0);
    glEnd();
    
    glutSwapBuffers();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Simple");

    Init();

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutMouseFunc(Mouse);
    glutKeyboardFunc(Keyboard);
    glutIdleFunc(Animation);

    glutMainLoop();

    return 0;
}

