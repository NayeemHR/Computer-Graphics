#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<windows.h>
#include<math.h>
#define PI 3.14159265358979323846

void circle(float cx , float cy, float cr, float tp=2.0, float r=1, float g=1, float b=1){
int i;

    GLfloat x=cx; GLfloat y=cy; GLfloat radius = cr;
    int triangleAmount = 40;

    GLfloat twicePi = tp * PI;

    glBegin(GL_TRIANGLE_FAN);
     glColor3f(r,g,b);
     glVertex2f(x,y);
     for(i=0; i<= triangleAmount; i++){
        glVertex2f(
                   x + (radius * cos(i * twicePi/ triangleAmount)),
                   y + (radius * sin(i * twicePi/ triangleAmount))
                   );
     }
     glEnd();
}
void cloud(float x=0, float y=0, float r =8){
    circle(x+17-r,y+20,r+7);
    circle(x+34-r,y+20,r+2);
    circle(x+47-r,y+10,r+2);
    circle(x+34-r,y,r+4);
    circle(x+22-r,y,r);
    circle(x+10-r,y,r+3);
    circle(x-r,y+10,r+4);
}
void treeleaf(float x=0, float y=0, float r =8){
    glColor3f(0,1,0);
    circle(x+17-r,y+20,r+7,2.0,0,1,0);
    circle(x+34-r,y+20,r+2,2.0,0,1,0);
    circle(x+47-r,y+10,r+2,2.0,0,1,0);
    circle(x+34-r,y,r+4,2.0,0,1,0);
    circle(x+22-r,y,r,2.0,0,1,0);
    circle(x+10-r,y,r+3,2.0,0,1,0);
    circle(x-r,y+10,r+4,2.0,0,1,0);
}

void treeleaf1(float x=0, float y=0, float r =8){
    glColor3f(0,1,0);

    circle(x+47-r,y+10,r+2,2.0,0,0.8,0);
    circle(x+34-r,y,r+4,2.0,0,0.8,0);
    circle(x+22-r,y,r,2.0,0,0.8,0);
    circle(x+10-r,y,r+3,2.0,0,0.8,0);
    circle(x-r,y+10,r+4,2.0,0,0.8,0);
    circle(x+17-r,y+20,r+7,2.0,0,0.9,0);
    circle(x+34-r,y+20,r+2,2.0,0,0.9,0);
}
int i;

// Function to initialize the Beizer
// Curve pointer
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

// Function to draw the Bitmap Text
void drawBitmapText(char* string, float x,
    float y, float z)
{
    char* c;
    glRasterPos2f(x, y);

    // Traverse the string
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(
            GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

// Function to draw the shapes
void draw(GLfloat ctrlpoints[4][3], float r, float g, float b)
{
    glShadeModel(GL_FLAT);
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4,
        &ctrlpoints[0][0]);

    glEnable(GL_MAP1_VERTEX_3);

    // Fill the color
    glColor3f(r, g, b);
    //glBegin(GL_LINE_STRIP);
    glBegin(GL_TRIANGLE_FAN);

    // Find the coordinates
    for (i = 0; i <= 30; i++)
        glEvalCoord1f((GLfloat)i / 30.0);

    glEnd();
    glFlush();
}
void crop(float x, float y, float s){
    GLfloat ctrlpoints3[4][3]
        = { { x, y, 0.0 },
            { x-2*s, y+3*s, 0.0 },
            { x+1*s, y, 0.0 },
            { x, y, 0.0 } };
    draw(ctrlpoints3,0,0,0);
    GLfloat ctrlpoints4[4][3]
        = { { x, y, 0.0 },
            { x+2*s, y+3*s, 0.0 },
            { x-1*s, y, 0.0 },
            { x, y, 0.0 } };
    draw(ctrlpoints4,0,0,0);


}

void bird2(float x, float y, float s){
    GLfloat ctrlpoints3[4][3]
        = { { x, y, 0.0 },
            { x-3*s, y+3*s, 0.0 },
            { x+1*s, y, 0.0 },
            { x, y, 0.0 } };
    draw(ctrlpoints3,0,0,0);
    GLfloat ctrlpoints4[4][3]
        = { { x, y, 0.0 },
            { x+3*s, y+3*s, 0.0 },
            { x-1*s, y, 0.0 },
            { x, y, 0.0 } };
    draw(ctrlpoints4,0,0,0);
}

void display(void)
{
    int i;
    glClearColor(0.49020,  0.89020,  1.00000, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    //sun
    circle(240,320,20,42,1.00000,  0.80000,  0.20000);

    //midle cloud
    cloud(150,280);
    //right cloud
    cloud(280,285);
    //birds
    bird2(250,270,5);
    bird2(265,275,5);
    bird2(275,285,5);
    // mountain
    GLfloat ctrlpoints[4][3]
        = { { 150.00, 220.00, 0.0 },
            { 180.00, 250.00, 0.0 },
            { 180.00, 250.00, 0.0 },
            { 210.00, 220.00, 0.0 } };
    draw(ctrlpoints,0.32157 , 0.32157 , 0.32157);
    GLfloat ctrlpoints3[4][3]
        = { { 210.00, 220.00, 0.0 },
            { 235.00, 250.00, 0.0 },
            { 235.00, 250.00, 0.0 },
            { 255.00, 220.00, 0.0 } };
    draw(ctrlpoints3,0.32157 , 0.32157 , 0.32157);
    GLfloat ctrlpoints5[4][3]
        = { { 290.00, 220.00, 0.0 },
            { 330.00, 265.00, 0.0 },
            { 330.00, 265.00, 0.0 },
            { 360.00, 220.00, 0.0 } };
    draw(ctrlpoints5,0.32157 , 0.32157 , 0.32157);
    GLfloat ctrlpoints4[4][3]
        = { { 233.00, 220.00, 0.0 },
            { 265.00, 275.00, 0.0 },
            { 275.00, 275.00, 0.0 },
            { 330.00, 220.00, 0.0 } };
    draw(ctrlpoints4,0.23137 , 0.23137 , 0.23137);

    GLfloat ctrlpoints2[4][3]
        = { { 185.00, 220.00, 0.0 },
            { 210.00, 260.00, 0.0 },
            { 210.00, 260.00, 0.0 },
            { 235.00, 220.00, 0.0 } };
    draw(ctrlpoints2,0.23137 , 0.23137 , 0.23137);

    glBegin(GL_QUADS);
        //green grass
        glColor3f(0.07451,  0.52157 , 0.06275);
        glVertex3f(0,0,0);
        glVertex3f(350,0,0);
        glVertex3f(350,220,0);
        glVertex3f(0,220,0);
        //house 1
        //floor
        glColor3f(0.62353,  0.45882,  0.45882);
        glVertex3f(75,150,0);
        glVertex3f(170,150,0);
        glVertex3f(170,155,0);
        glVertex3f(60,155,0);
        //wall
        glColor3f(0.7,0.8,0.8);
        glVertex3f(60,155,0);
        glVertex3f(165,155,0);
        glVertex3f(165,190,0);
        glVertex3f(60,190,0);
        //roof
        glColor3f(1.00000,  0.7,  0.00000);
        glVertex3f(60,190,0);
        glVertex3f(170,190,0);
        glVertex3f(150,225,0);
        glVertex3f(60,225,0);

        //door
        glColor3f(0.21961,  0.23529,  0.29020);
        glVertex3f(95,155,0);
        glVertex3f(115,155,0);
        glVertex3f(115,180,0);
        glVertex3f(95,180,0);

        //window
        glColor3f(0.21961,  0.23529,  0.29020);
        glVertex3f(125,165,0);
        glVertex3f(150,165,0);
        glVertex3f(150,185,0);
        glVertex3f(125,185,0);
        //house 1 end
        //house 2
        //door
        glColor3f(0.21961,  0.23529,  0.29020);
        glVertex3f(0,155,0);
        glVertex3f(18,155,0);
        glVertex3f(18,180,0);
        glVertex3f(0,180,0);
        //wall
        glColor3f(0.8,0.8,0.9);
        glVertex3f(18,155,0);
        glVertex3f(60,155,0);
        glVertex3f(60,180,0);
        glVertex3f(18,180,0);
        //window
        glColor3f(0.21961,  0.23529,  0.29020);
        glVertex3f(30,165,0);
        glVertex3f(50,165,0);
        glVertex3f(50,180,0);
        glVertex3f(30,180,0);
        //roof
        glColor3f(1.00000,  0.64706,  0.00000);
        glVertex3f(0,180,0);
        glVertex3f(100,180,0);
        glVertex3f(60,230,0);
        glVertex3f(0,230,0);
        //column
        glColor3f(0.66275,  0.66275,  0.66275);
        glVertex3f(85,140,0);
        glVertex3f(90,140,0);
        glVertex3f(90,180,0);
        glVertex3f(85,180,0);
        //floor
        glColor3f(0.62353,  0.45882,  0.45882);
        glVertex3f(0,140,0);
        glVertex3f(90,140,0);
        glVertex3f(90,145,0);
        glVertex3f(0,145,0);
        //floor
        glColor3f(0.68235,  0.54510,  0.54510);
        glVertex3f(0,145,0);
        glVertex3f(90,145,0);
        glVertex3f(60,155,0);
        glVertex3f(0,155,0);
        //house 2 end
    glEnd();
    //khor
    GLfloat ctrlpoints7[4][3]
        = { { 230.00, 160.00, 0.0 },
            { 230.00, 230.00, 0.0 },
            { 280.00, 230.00, 0.0 },
            { 280.00, 160.00, 0.0 } };
    draw(ctrlpoints7,0.79216 , 0.74118 , 0.40000);
    //bamboo
    glBegin(GL_QUADS);
        glColor3f(0.56863,  0.47843,  0.20392);
        glVertex3f(240,155,0);
        glVertex3f(242,155,0);
        glVertex3f(242,195,0);
        glVertex3f(240,195,0);

        glVertex3f(249,155,0);
        glVertex3f(251,155,0);
        glVertex3f(251,195,0);
        glVertex3f(249,195,0);

        glVertex3f(260,155,0);
        glVertex3f(262,155,0);
        glVertex3f(262,195,0);
        glVertex3f(260,195,0);

        glVertex3f(269,155,0);
        glVertex3f(271,155,0);
        glVertex3f(271,195,0);
        glVertex3f(269,195,0);

        glVertex3f(220,168,0);
        glVertex3f(290,168,0);
        glVertex3f(290,170,0);
        glVertex3f(220,170,0);

        glVertex3f(220,178,0);
        glVertex3f(290,178,0);
        glVertex3f(290,180,0);
        glVertex3f(220,180,0);
    glEnd();

    //river
    GLfloat ctrlpoints8[4][3]
        = { { -40, 60, 0.0 },
            { 680, 260, 0.0 },
            { 480, 122, 0.0 },
            { -40, -40, 0.0 } };
    draw(ctrlpoints8,0.60784,  0.46275,  0.32549);
    GLfloat ctrlpoints6[4][3]
        = { { -40, 40, 0.0 },
            { 680, 260, 0.0 },
            { 480, 122, 0.0 },
            { -40, -40, 0.0 } };
    draw(ctrlpoints6,0.61569,  0.84314,  0.93725);
    //Big Tree
    GLfloat ctrlpoints9[4][3]
        = { { 0, 230, 0.0 },
            { 50, 340, 0.0 },
            { 0, 330, 0.0 },
            { 30, 230, 0.0 } };
    draw(ctrlpoints9,0.60784,  0.46275,  0.32549);

    GLfloat ctrlpoints10[4][3]
        = { { 0, 230, 0.0 },
            { 10, 340, 0.0 },
            { 0, 330, 0.0 },
            { 30, 230, 0.0 } };
    draw(ctrlpoints10,0.60784,  0.46275,  0.32549);

    treeleaf(10,330);
    treeleaf1(0,300);
    //crop
    glBegin(GL_TRIANGLES);
        glColor3f( 0.60784,  0.46275,  0.32549);
        glVertex3f(120,0,0);
        glVertex3f(350,0,0);
        glVertex3f(350,90,0);

        glColor3f(0.67451,  0.67451,  0.67451);
        glVertex3f(130,0,0);
        glVertex3f(350,0,0);
        glVertex3f(350,85,0);
    glEnd();
    int l = 160;
    for (int j = 0; j < 80; j=j+8) {
        for (int k = 0; k < 200; k=k+10) {
            crop(l+k,5+j,5);

        }
        l=l+20;
    }
    //Big Tree End
    glFlush();
}

// Function perform the reshaping of the curve
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w,
        (GLsizei)h);

 // Matrix mode
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h)
        glOrtho(0.0, 350.0, 0.0
        * (GLfloat)h / (GLfloat)w,
            350.0 * (GLfloat)h / (GLfloat)w, 0.0, 350.0);
    else
        glOrtho(350.0 * (GLfloat)w / (GLfloat)h,
                350.0 * (GLfloat)w / (GLfloat)h,
                0.0, 350.0,
                0.0, 350.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Driver Code
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(
        GLUT_SINGLE | GLUT_RGB);

// Specifies the window size
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

// Creates the window as specified by the user
    glutCreateWindow(argv[0]);
    init();
 // Links display event with the display event handler(display)
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

 // Loops the current event
    glutMainLoop();

    return 0;
}
