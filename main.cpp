#include <GL/glut.h>
#include<iostream>
#include <math.h>
#define PI 3.1416
using namespace std;

GLfloat shake=0,cloud_movement=0,apple_rotate=0,apple_movement=0;

GLboolean flag = false, apple_activate = false;

string planet = "Earth";
string welcome1 = "Welcome to gravity app.";
string welcome2 = "Here you can compare gravity of different planets.";
string welcome3 = "Consider the apple at the edge is 10 meters from the ground. How much time it will take to drop?";
string welcome4 = "Press (E) for Earth Gravity, (M) for Mars gravity, (N) for Neptune gravity";
string msg = "";


/* Models */

/*
* Function to draw circle
* @params rad (radius of the circle)
*/
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 5.0;

    glBegin(GL_POLYGON);
    {
        for(GLint i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}

/*
* Function to draw house
*/
void house()
{
    // House Roof
    glBegin(GL_POLYGON);
    glColor3f(.990, 0.0, 0.0);
    glVertex2i(285, 105);
    glVertex2i(285, 130);
    glVertex2i(380, 115);
    glVertex2i(380, 105);

    glEnd();
    // House Roof Shadow
    glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
    glVertex2i(285, 105);
    glVertex2i(285, 120);
    glVertex2i(380, 105);
    glVertex2i(380, 105);

    glEnd();
    // House Fence
    glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
    glVertex2i(290, 70);
    glVertex2i(290, 104);
    glVertex2i(375, 104);
    glVertex2i(375, 70);

    glEnd();
    // House Fence Shadow
    glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
    glVertex2i(310, 70);
    glVertex2i(350, 104);
    glVertex2i(375, 104);
    glVertex2i(375, 70);

    glEnd();
    // House Door
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
    glVertex2i(330, 70);
    glVertex2i(330, 100);
    glVertex2i(350, 100);
    glVertex2i(350, 70);

    glEnd();
    // House Window 1
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2i(295, 75);
    glVertex2i(295, 90);
    glVertex2i(310, 90);
    glVertex2i(310, 75);

    glEnd();
    // House Window2
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2i(312, 75);
    glVertex2i(312, 90);
    glVertex2i(327, 90);
    glVertex2i(327, 75);

    glEnd();
    // House Window3
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2i(355, 75);
    glVertex2i(355, 90);
    glVertex2i(370, 90);
    glVertex2i(370, 75);

    glEnd();
    // House Small Roof
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(250, 90);
    glVertex2i(257, 104);
    glVertex2i(290, 104);
    glVertex2i(290, 90);

    glEnd();
    // House Small Fence
    glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
    glVertex2i(255, 70);
    glVertex2i(255, 90);
    glVertex2i(290, 90);
    glVertex2i(290, 70);

    glEnd();
    // House Small Door
    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
    glVertex2i(260, 70);
    glVertex2i(260, 80);
    glVertex2i(285, 80);
    glVertex2i(285, 70);

    glEnd();
}

/*
* Function to draw front field
*/
void field()
{
    // Field
    glBegin(GL_POLYGON);
    glColor3f(0.533, 1.293, 0.0);
    glVertex2i(0, 50);
    glVertex2i(0, 100);
    glVertex2i(1000, 70);
    glVertex2i(1000, 50);

    glEnd();
    // Field Shadow
    glBegin(GL_POLYGON);
    glColor3f(0.1, 1.293, 0.0);
    glVertex2i(0, 0);
    glVertex2i(0, 70);
    glVertex2i(1000, 50);
    glVertex2i(1000, 0);

    glEnd();
}

/*
* Function to draw apple
*/
void apple()
{
    // Apple left side
    glPushMatrix();
    glColor3f(1.0, 0.2, 0.0);
    glTranslatef(0+shake,0,0);
    circle(10);
    glPopMatrix();

    // Apple right side
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(10+shake,0,0);
    circle(10);
    glPopMatrix();


    // Leaf
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.8, 0.0);

    glVertex2i(3+shake, 5);
    glVertex2i(15+shake, 10);
    glVertex2i(20+shake, 20);
    glVertex2i(3+shake, 5);

    glEnd();
}

/*
* Function to draw cloud
*/
void cloud()
{

    glColor3f(1.25, 0.924, 0.930);
    // Top Left
    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    // Top
    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    // Right
    glPushMatrix();
    glTranslatef(360,210,0);
    circle(16);
    glPopMatrix();


    // Middle Fill
    glPushMatrix();
    glTranslatef(355,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305,204,0);
    circle(10);
    glPopMatrix();

}

/*
* Function to draw tree
*/
void tree()
{
    // Upper Branch
    glPushMatrix();
    glColor3f(0.6, 1.293, 0.0);
    glTranslatef(110,350,0);
    circle(100);
    glPopMatrix();

    // Lower Branch
    glPushMatrix();
    glColor3f(0.533, 1.293, 0.0);
    glTranslatef(110,200,0);
    circle(100);
    glPopMatrix();

    // Side Branch
    glPushMatrix();
    glColor3f(0.55, 1.293, 0.0);
    glTranslatef(shake,300,0);
    circle(100);
    glPopMatrix();

    // Root
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(100, 70);
    glVertex2f(100, 150);
    glVertex2f(112, 150);
    glVertex2f(112, 70);

    glEnd();
}

/* ------------------------------------------------------------------------ Models End */

/* ------------------------------------------------------------------------ Objects */

/*
* Function to place tree in view
* @params x (x point) y (y point)
*/

void place_tree(float x, float y)
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(x,y,0);
    tree();
    glPopMatrix();
}

/*
* Function to place cloud in view
* @params x (x point) y (y point)
*/
void place_cloud(float x,float y,float speed)
{
    glPushMatrix();
    glTranslatef(x+cloud_movement*speed,y,0);
    cloud();
    glPopMatrix();

}

/*
* Function to place house in view
* @params
*/
void place_house(float x, float y)
{
    glPushMatrix();
    glTranslatef(x,y,0);
    house();
    glPopMatrix();
}

/*
* Function to place apple in view
* @params
*/
void place_apple(float x, float y,bool active)
{
    glPushMatrix();
    if(active)
    {
        glTranslatef(x,y+apple_movement,0);
        glRotatef(15+apple_rotate, 0.0, 0.0, 1.0);
    }
    else
    {
        glTranslatef(x,y,0);
    }
    apple();
    glPopMatrix();
}

/*
* Function to place text in view
* @params
*/
void place_text_const(float x, float y,string text)
{
    glRasterPos2f(x, y);
    glColor3f(0.0, 0.0, 0.0);
    for (char c : text)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
}

void place_text(float x, float y)
{
    glRasterPos2f(x, y);
    for (char c : msg)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
}

/* Objects End */

/* Utility Functions */

/*
* Function to handle animation
*/
void animation()
{
    cloud_movement += .025;

    if(shake > 5)
    {
        flag = true;
    }
    else if(shake < 0) flag = false;
    if(!flag) shake += .001;
    if(flag) shake -= .001;

    if(cloud_movement>700) cloud_movement= -400;



    if(apple_activate)
    {
        int p = 0;
        if(planet == "Earth") p = 0;
        if(planet == "Mars") p = 1;
        if(planet == "Neptune") p = 2;

        switch(p)
        {
        case 0:
            apple_movement -= 0.2;
            apple_rotate += 0.5;
            break;

        case 1:
            apple_movement -= 0.15;
            apple_rotate += 0.4;
            break;

        case 2:
            apple_movement -= 0.25;
            apple_rotate += 0.6;
            break;
        }
    }

    if(250+apple_movement < 50 && apple_activate)
    {
        apple_activate = false;

        if(planet == "Earth")
        {
            GLfloat res = (sqrt(20) * 1 / sqrt(9.81));
            msg += " Time = " + to_string(res) + " sec";
        }
        if(planet == "Mars")
        {
            GLfloat res = (sqrt(20) * 1 / sqrt(3.72076));
            msg += " Time = " + to_string(res) + " sec";
        }
        if(planet == "Neptune")
        {
            GLfloat res = (sqrt(20) * 1 / sqrt(11.15));
            msg += " Time = " + to_string(res) + " sec";
        }
    }

    glutPostRedisplay();
}


/*
* Function to display all objects
*/
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0);

    place_house(0,17);
    place_house(250,10);

    field();

    place_cloud(-100,100,2.5);
    place_tree(800,3);
    place_cloud(0,200,1);

    place_apple(720,250,true);

    place_apple(800,280,false);
    place_apple(900,350,false);

    glColor3f(0.0, 0.0, 0.0);
    place_text_const(50,450,welcome1);
    place_text_const(50,430,welcome2);
    place_text_const(50,410,welcome3);
    place_text_const(50,390,welcome4);
    place_text(50, 370);

    glFlush();
    glutSwapBuffers();
}

/*
* Function to set some default values
*/
void init(void)
{
    glClearColor(0.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

/*
* Function to handle mouse press
*/
void mouse(int key, int state, int x, int y)
{
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(animation);
        }
        break;
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    default:
        break;
    }
}

/*
* Function to handle keyboard press
*/
void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) // ASCII code for escape key
    {
        exit(0);
    }
    else if (key == 69 || key == 101) // ASCII code for e,E
    {
        apple_activate = true;
        apple_movement = 0;
        planet = "Earth";
        msg = "Selected Planet = " + planet + ".";
    }
    else if (key == 109 || key == 77) // ASCII code for space m,M
    {
        apple_activate = true;
        apple_movement = 0;
        planet = "Mars";
        msg = "Selected Planet = " + planet + ".";
    }
    else if (key == 78 || key == 110) // ASCII code for space n,N
    {
        apple_activate = true;
        apple_movement = 0;
        planet = "Neptune";
        msg = "Selected Planet = " + planet + ".";
    }
}

/* Main Function */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Gravity");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse); // Mouse click handler
    glutKeyboardFunc(keyboard); // keyboard click handler
    glutMainLoop();
}
