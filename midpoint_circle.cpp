#include<windows.h>
#include<GL/glut.h>

int xc=320, yc=240;

void plot_point(int x, int y){
    glBegin(GL_POINTS);
        glVertex2i(xc+x, yc+y);
        glVertex2i(xc+x, yc-y);
        glVertex2i(xc+y, yc+x);
        glVertex2i(xc+y, yc-x);
        glVertex2i(xc-x, yc-y);
        glVertex2i(xc-y, yc-x);
        glVertex2i(xc-x, yc+y);
        glVertex2i(xc-y, yc+x);
    glEnd();
}

void midpoint_circle(int r){
    int x=0,y=r;
    float pk=(5.0/4.0)-r;
    plot_point(x,y);

    while(x<y){
        x=x+1;
        if(pk<0){
            pk+= (2*x)+3;
        }else{
            y=y-1;
            pk+=(2*(x-y))+5;
        }
        plot_point(x,y);
    }
    glFlush();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    midpoint_circle(100);
}
void init(){
    glClearColor(1.0,1.0,1.0,0);
    glColor3f(0.0,0.0,0.0);
    gluOrtho2D(0,640,0,480);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("Midpoint_circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}
