#include<GL/gl.h>
#include<GL/glut.h>
#include<windows.h>
#include<math.h>
#define PI 3.14159265358979323846

void circle(int vx,int vy){
    int i;

    GLfloat x=vx; GLfloat y=vy; GLfloat radius = 5.0f;
    int triangleAmount = 40;

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
         glColor3f(0.00392,  0.12941,  0.41176);
         glVertex2f(x,y);
         for(i=0; i<= triangleAmount; i++){
            glVertex2f(
                       x + (radius * cos(i * twicePi/ triangleAmount)),
                       y + (radius * sin(i * twicePi/ triangleAmount))
                       );
         }
    glEnd();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);

    glBegin(GL_QUADS);
        glColor3f(0.9, 0.2, 0.27);
        glVertex3f(8.0f,0.0f,0.0f);
        glVertex3f(10.0f,0.0f,0.0f);
        glVertex3f(10.0f,92.0f,0.0f);
        glVertex3f(8.0f,92.0f,0.0f);

        glColor3f(0.0, 0.59216, 0.22353);
        glVertex3f(10.0f,60.0f,0.0f);
        glVertex3f(60.0f,60.0f,0.0f);
        glVertex3f(60.0f,90.0f,0.0f);
        glVertex3f(10.0f,90.0f,0.0f);

        glColor3f(0.99608,  0.86667 , 0.00000);
        glVertex3f(35.0f,66.0f,0.0f);
        glVertex3f(50.0f,75.0f,0.0f);
        glVertex3f(35.0f,84.0f,0.0f);
        glVertex3f(20.0f,75.0f,0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0,0.71,0.85);
        glVertex3f(0.0f,0.0f,0.0f);
        glVertex3f(18.0f,0.0f,0.0f);
        glVertex3f(9.0f,20.0f,0.0f);
    glEnd();
  
    circle(35,75);
  
    glFlush();
}
void init (void){
    glClearColor(1.0,1.0,1.0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,150.0,0.0,150.0,-10.0,10.0);
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Shape");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
