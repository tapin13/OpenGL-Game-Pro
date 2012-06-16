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
#include <vector>

using std::vector;

void Init();
void Mouse(int button, int state, int x, int y);
void Keyboard(unsigned char key, int x, int y);
void Menu(int option);
void Animation();
void Reshape(int w, int h);
void Display();

vector<GLfloat> m_vertices;
vector<GLuint> m_indeces;
GLuint m_vertexBuffer;

void Init() {
    int mainMenu;
    
    mainMenu = glutCreateMenu(Menu);
    
    glutSetMenu(mainMenu);
    glutAddMenuEntry("Exit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glEnable(GL_DEPTH_TEST);    
    
    glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    m_vertices.push_back(-2.0f);
    m_vertices.push_back(-2.0f);
    m_vertices.push_back(0.0f);
    
    m_vertices.push_back(2.0f);
    m_vertices.push_back(-2.0f);
    m_vertices.push_back(0.0f);
    
    m_vertices.push_back(2.0f);
    m_vertices.push_back(2.0f);
    m_vertices.push_back(0.0f);
    
    m_vertices.push_back(-2.0f);
    m_vertices.push_back(2.0f);
    m_vertices.push_back(0.0f);
    
    m_indeces.push_back(0);
    m_indeces.push_back(1);
    m_indeces.push_back(3);

    m_indeces.push_back(1);
    m_indeces.push_back(2);
    m_indeces.push_back(3);
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
    gluPerspective(52.0f, w / h, 1.0, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Display() {
    

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glTranslatef(0.0f, 0.0f, -6.0f);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &m_vertices[0]);
    
    glDrawElements(GL_TRIANGLES, m_indeces.size(), GL_UNSIGNED_INT, &m_indeces[0]);
    
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Shared Vertices");

    Init();

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutMouseFunc(Mouse);
    glutKeyboardFunc(Keyboard);
    glutIdleFunc(Animation);

    glutMainLoop();

    return 0;
}

