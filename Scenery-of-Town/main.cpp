#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <windows.h>
#include <glut.h>
#define PI 3.1416



static GLfloat spin = 0.0;
GLint a=10,b=-10,flag=1,traffic_regulator=1,control_keyl,control_keyr;
GLfloat gr=1,yel=0,r=0,sx=1,sy=5,bx=0,by=-8,gx=0,gy=15,cx=0,bc=.1,cg=.2,sc=0,gc=0,gsx=1,gsy=.9;//signal color change

void circle(float radius_x, float radius_y)
{
	int i = 0;
	float angle1 = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 200; i++)
		{
			angle1 = 2 * PI * i / 200;
			glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
		}

	glEnd();
}

void halfcircle(float radius_x, float radius_y)
{
	int i = 0;
	float angle1 = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 101; i++)
		{
			angle1 = 2 * PI * i / 200;
			glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
		}

	glEnd();
}


void girl()
{
    glPushMatrix();
    glTranslatef(gx,gy,1);
    glScalef(gsx,gsy,1);
        ///hair
        glPushMatrix();
        glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_POLYGON);
            glVertex2f(-2.0,0);
            glVertex2f(2.0,0);
            glVertex2f(2.0,-3.0);
            glVertex2f(-2.0,-3.0);
        glEnd();
        circle(2,2);
        glPopMatrix();
        ///upper
        glColor3f(.85f,0.43f,0.84f);
        glPushMatrix();
        glBegin(GL_QUADS);
            glVertex2f(2.5,-2.5);
            glVertex2f(4,-6);
            glVertex2f(3,-6);
            glVertex2f(2,-3.5);

            glVertex2f(4,-6);
            glVertex2f(3,-6);
            glVertex2f(1,-9);
            glVertex2f(1,-10);

            glVertex2f(-1,-9);
            glVertex2f(-1,-10);
            glVertex2f(-4,-6);
            glVertex2f(-3,-6);

            glVertex2f(-4,-6);
            glVertex2f(-3,-6);
            glVertex2f(-2,-3.5);
            glVertex2f(-2.5,-2.5);


            glVertex2f(-2.5,-2.5);
            glVertex2f(2.5,-2.5);
            glVertex2f(2,-3.5);
            glVertex2f(-2,-3.5);


        glEnd();
        glPopMatrix();
        ///neck
        glPushMatrix();
        glColor3f(1.0f,0.87f,0.68f);
        glBegin(GL_POLYGON);
            glVertex2f(-.5,0);
            glVertex2f(.5,0);
            glVertex2f(.5,-3);
            glVertex2f(-.5,-3);
        glEnd();
        glPopMatrix();
        ///body
        glPushMatrix();
        glColor3f(0.85,0.43,0.84);
        glBegin(GL_POLYGON);
            glVertex2f(2,-3);
            glVertex2f(2,-7);
            glVertex2f(-2,-7);
            glVertex2f(-2,-3);
        glEnd();
        glPopMatrix();
        ///skirt
        glPushMatrix();
        glColor3f(1,0,0);
        glBegin(GL_POLYGON);
            glVertex2f(2,-7);
            glVertex2f(3,-14);
            glVertex2f(-3,-14);
            glVertex2f(-2,-7);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0f,0.0f,0.0f);///head
        circle(1.55,1.85);
        glColor3f(1.0f,0.87f,0.68f);///head
        circle(1.5,1.8);

        glPopMatrix();
        ///shoe
        glPushMatrix();
        glColor3f(.55f,0.0f,0.0f);
        glBegin(GL_POLYGON);
            glVertex2f(-.5,-17);
            glVertex2f(-1.5,-17);
            glVertex2f(-1.5,-17.5);
            glVertex2f(0,-17.5);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2f(.5,-17);
            glVertex2f(1.5,-17);
            glVertex2f(2,-17.5);
            glVertex2f(0.5,-17.5);
        glEnd();
        glPopMatrix();
        ///legs
        glPushMatrix();
        glColor3f(1.0f,0.87f,0.68f);
        glBegin(GL_POLYGON);
            glVertex2f(-.5,-17);
            glVertex2f(-1.5,-17);
            glVertex2f(-1.5,-14);
            glVertex2f(-.5,-14);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2f(.5,-17);
            glVertex2d(1.5,-17);
            glVertex2f(1.5,-14);
            glVertex2f(.5,-14);
        glEnd();
        glPopMatrix();
        ///hair extension
        glPushMatrix();
        glTranslatef(0,1.4,0),
        glColor3f(0.0f,0.0f,0.0f);
        circle(1.3,.8);
        glPopMatrix();
        ///eyes
        glPushMatrix();
        glTranslatef(0.7,0.1,0),
        glColor3f(0.0f,0.0f,0.0f);
        circle(.2,.2);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-0.7,0.1,0),
        glColor3f(0.0f,0.0f,0.0f);
        circle(.2,.2);
        glPopMatrix();
        ///lips
        glPushMatrix();
        glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(.4,-.9);
        glVertex2f(-.4,-.9);
        glVertex2f(-.4,-1.2);
        glVertex2f(.4,-1.2);
        glEnd();
        glPopMatrix();


    glPopMatrix();
}

void sky()
{
    glBegin(GL_QUADS);

    glColor3f(0.36f,0.67f,0.93f);
    glVertex2f(-100,50);
    glColor3f(0.22f,0.37f,0.80f);
    glVertex2f(100,50);
    glColor3f(0.75f,0.94f,1.0f);
    glVertex2f(100,20);
    glColor3f(0.88f,1.0f,1.0f);
    glVertex2f(-100,20);
    glEnd();
}

void sky1()
{
    glBegin(GL_QUADS);

    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-100,50);
    //glColor3f(0.22f,0.37f,0.80f);
    glVertex2f(100,50);
    //glColor3f(0.75f,0.94f,1.0f);
    glVertex2f(100,20);
    //glColor3f(0.88f,1.0f,1.0f);
    glVertex2f(-100,20);
    glEnd();
}

void divider()
{
    glColor3f(0.54,0.35,0);
    glBegin(GL_POLYGON);
    glVertex2f(100,24);
    glVertex2f(-100,24);
    glVertex2f(-100,23);
    glVertex2f(100,23);
    glEnd();
}

void river()
{
    glBegin(GL_POLYGON);
       glColor3f(0.69f, 0.77f, 0.87f);
    glVertex2f(100,23);
     glColor3f(0.06f, 0.31f, 0.54f);
    glVertex2f(-100,23);
    glColor3f(0.69f, 0.77f, 0.87f);
    glVertex2f(-100,3);
     glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(100,3);
    glEnd();
}

void car()
{
glPushMatrix(); //making color for outer line
glTranslatef(cx,-35.0,0.0);
glScaled(3.0,3.0,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(2.5,2.5);
glVertex2f(3.0,3.5);
glVertex2f(3.5,3.75);
glVertex2f(4.0,4.0);
glVertex2f(4.5,4.0);
glVertex2f(5.0,3.75);
glVertex2f(5.5,3.5);
glVertex2f(5.75,3.0);
glVertex2f(6.0,2.5);
glVertex2f(16.5,2.5);
glVertex2f(16.75,3.0);
glVertex2f(17.0,3.5);
glVertex2f(17.5,3.75);
glVertex2f(18.0,4.0);
glVertex2f(18.5,4.0);
glVertex2f(19.0,3.75);
glVertex2f(19.5,3.5);
glVertex2f(19.75,3.0);
glVertex2f(20.0,2.5);
glVertex2f(21.0,2.5);
glVertex2f(21.0,4.0);
glVertex2f(21.5,4.0);
glVertex2f(21.0,4.5);
glVertex2f(20.0,5.0);
glVertex2f(15.0,5.0);
glVertex2f(14.0,5.5);
glVertex2f(13.0,6.0);
glVertex2f(12.0,6.5);
glVertex2f(11.0,7.0);
glVertex2f(6.0,7.0);
glVertex2f(5.0,6.5);
glVertex2f(4.5,6.25);
glVertex2f(4.25,6.0);
glVertex2f(4.0,5.75);
glVertex2f(3.5,5.5);
glVertex2f(3.0,5.5);
glVertex2f(1.9,5.45);
glVertex2f(1.8,5.4);
glVertex2f(1.7,5.35);
glVertex2f(1.6,5.3);
glVertex2f(1.5,5.25);
glVertex2f(1.4,5.15);
glVertex2f(1.3,5.0);
glVertex2f(1.2,4.85);
glVertex2f(1.1,4.7);
glVertex2f(1.0,4.3);
glVertex2f(1.0,3.2);
glVertex2f(1.1,3.05);
glVertex2f(1.2,2.9);
glVertex2f(1.3,2.9);
glVertex2f(1.4,2.75);
glVertex2f(1.5,2.65);
glVertex2f(1.6,2.6);
glVertex2f(1.7,2.55);
glVertex2f(1.8,2.5);
glVertex2f(1.9,2.45);
glVertex2f(2.0,2.5);
glEnd();

glColor3f(1.0,1.0,1.0); //color for outer window
glBegin(GL_POLYGON);
glVertex2f(5.0,5.0);
glVertex2f(14.0,5.0);
glVertex2f(11.5,6.5);
glVertex2f(10.5,6.75);
glVertex2f(7.0,6.75);
glEnd();

glColor3f(0.0,0.0,0.0); //making outer line for car
glBegin(GL_LINE_LOOP);
glVertex2f(2.5,2.5);
glVertex2f(3.0,3.5);
glVertex2f(3.5,3.75);
glVertex2f(4.0,4.0);
glVertex2f(4.5,4.0);
glVertex2f(5.0,3.75);
glVertex2f(5.5,3.5);
glVertex2f(5.75,3.0);
glVertex2f(6.0,2.5);
glVertex2f(16.5,2.5);
glVertex2f(16.75,3.0);
glVertex2f(17.0,3.5);
glVertex2f(17.5,3.75);
glVertex2f(18.0,4.0);
glVertex2f(18.5,4.0);
glVertex2f(19.0,3.75);
glVertex2f(19.5,3.5);
glVertex2f(19.75,3.0);
glVertex2f(20.0,2.5);
glVertex2f(21.0,2.5);
glVertex2f(21.0,4.0);
glVertex2f(21.5,4.0);
glVertex2f(21.0,4.5);
glVertex2f(20.0,5.0);
glVertex2f(15.0,5.0);
glVertex2f(14.0,5.5);
glVertex2f(13.0,6.0);
glVertex2f(12.0,6.5);
glVertex2f(11.0,7.0);
glVertex2f(6.0,7.0);
glVertex2f(5.0,6.5);
glVertex2f(4.5,6.25);
glVertex2f(4.25,6.0);
glVertex2f(4.0,5.75);
glVertex2f(3.5,5.5);
glVertex2f(3.0,5.5);
glVertex2f(1.9,5.45);
glVertex2f(1.8,5.4);
glVertex2f(1.7,5.35);
glVertex2f(1.6,5.3);
glVertex2f(1.5,5.25);
glVertex2f(1.4,5.15);
glVertex2f(1.3,5.0);
glVertex2f(1.2,4.85);
glVertex2f(1.1,4.7);
glVertex2f(1.0,4.3);
glVertex2f(1.0,3.2);
glVertex2f(1.1,3.05);
glVertex2f(1.2,2.9);
glVertex2f(1.3,2.9);
glVertex2f(1.4,2.75);
glVertex2f(1.5,2.65);
glVertex2f(1.6,2.6);
glVertex2f(1.7,2.55);
glVertex2f(1.8,2.5);
glVertex2f(1.9,2.45);
glVertex2f(2.0,2.5);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP); //outer line for design a car
glVertex2f(8.0,3.0);
glVertex2f(16.0,3.0);
glVertex2f(16.5,3.5);
glVertex2f(17.0,4.0);
glVertex2f(16.5,4.25);
glVertex2f(16.0,4.5);
glVertex2f(15.0,4.5);
glVertex2f(15.0,5.0);
glVertex2f(14.0,5.0);
glVertex2f(11.5,6.5);
glVertex2f(10.5,6.75);
glVertex2f(7.0,6.75);
glVertex2f(5.0,5.0);
glVertex2f(7.0,5.0);
glVertex2f(6.5,4.5);
glEnd();


glBegin(GL_LINES); //connecting outer line
glVertex2d(7.0,5.0);
glVertex2d(15.0,5.0);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(15.0,4.0);
glVertex2d(17.0,4.0);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(15.0,3.5);
glVertex2d(16.5,3.5);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(15.0,5.0);
glVertex2d(14.0,3.0);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(12.0,5.0);
glVertex2d(12.0,6.2);
glEnd();

glColor3f(0.0,0.0,0.0); //connecting outer line
glBegin(GL_LINES);
glVertex2d(7.0,5.0);
glVertex2d(7.0,6.7);
glEnd();

glBegin(GL_POLYGON); //drawing a back tyre
glVertex2f(3.0,2.5);
glVertex2f(3.0,2.6);
glVertex2f(3.15,3.1);
glVertex2f(3.2,3.2);
glVertex2f(3.3,3.35);
glVertex2f(3.4,3.4);
glVertex2f(3.5,3.45);
glVertex2f(3.6,3.55);
glVertex2f(3.7,3.6);
glVertex2f(3.8,3.63);
glVertex2f(4.0,3.65);
glVertex2f(4.2,3.7);
glVertex2f(4.4,3.7);
glVertex2f(4.6,3.65);
glVertex2f(4.8,3.55);
glVertex2f(5.0,3.45);
glVertex2f(5.1,3.4);
glVertex2f(5.2,3.25);
glVertex2f(5.3,3.2);
glVertex2f(5.4,3.0);
glVertex2f(5.5,2.5);

glVertex2f(5.45,2.15);
glVertex2f(5.4,1.9);
glVertex2f(5.35,1.8);
glVertex2f(5.2,1.6);
glVertex2f(5.0,1.5);
glVertex2f(4.9,1.4);
glVertex2f(4.7,1.3);
glVertex2f(4.6,1.27);
glVertex2f(4.4,1.25);
glVertex2f(4.0,1.25);
glVertex2f(3.9,1.3);
glVertex2f(3.75,1.35);
glVertex2f(3.6,1.4);
glVertex2f(3.45,1.55);
glVertex2f(3.3,1.7);
glVertex2f(3.2,1.8);
glVertex2f(3.1,2.2);
glEnd();


glBegin(GL_POLYGON); //drawing front tyre
glVertex2f(17.0,2.5);
glVertex2f(17.0,2.6);
glVertex2f(17.15,3.1);
glVertex2f(17.2,3.2);
glVertex2f(17.3,3.35);
glVertex2f(17.4,3.4);
glVertex2f(17.5,3.45);
glVertex2f(17.6,3.55);
glVertex2f(17.7,3.6);
glVertex2f(17.8,3.63);
glVertex2f(18.0,3.65);
glVertex2f(18.2,3.7);
glVertex2f(18.4,3.7);
glVertex2f(18.6,3.65);
glVertex2f(18.8,3.55);
glVertex2f(19.0,3.45);
glVertex2f(19.1,3.4);
glVertex2f(19.2,3.25);
glVertex2f(19.3,3.2);
glVertex2f(19.4,3.0);

glVertex2f(19.5,2.5);
glVertex2f(19.45,2.15);
glVertex2f(19.4,1.9);
glVertex2f(19.35,1.8);
glVertex2f(19.2,1.6);
glVertex2f(19.0,1.5);
glVertex2f(18.9,1.4);
glVertex2f(18.7,1.3);
glVertex2f(18.6,1.27);
glVertex2f(18.4,1.25);
glVertex2f(18.0,1.25);
glVertex2f(17.9,1.3);
glVertex2f(17.75,1.35);
glVertex2f(17.6,1.4);
glVertex2f(17.45,1.55);
glVertex2f(17.3,1.7);
glVertex2f(17.2,1.8);
glVertex2f(17.1,2.2);
glEnd();
glPopMatrix();
}

void footpath()
{
    glBegin(GL_QUADS);
    glColor3f(0.55,0.27,0.0745);
    glVertex2f(-100.0,3);
    glVertex2f(100,3);
    glVertex2f(100,0);
    glVertex2f(-100,0);
    glEnd();
}

void footpath1()
{
    glBegin(GL_QUADS);
    glColor3f(0.54,0.35,0.16);
    glVertex2f(-100.0,-50);
    glColor3f(0,0.54,0);
    glVertex2f(100,-50);
    glColor3f(0,0.54,0);
    glVertex2f(100,-40);
    glColor3f(0.54,0.35,0.16);
    glVertex2f(-100,-40);
    glEnd();
}


void zigzag()
{
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(10,-35);
    glVertex2f(-10,-35);
    glVertex2f(-10,-32);
    glVertex2f(10,-32);

    glVertex2f(10,-29);
    glVertex2f(-10,-29);
    glVertex2f(-10,-26);
    glVertex2f(10,-26);

    glVertex2f(10,-23);
    glVertex2f(-10,-23);
    glVertex2f(-10,-20);
    glVertex2f(10,-20);

    glVertex2f(10,-17);
    glVertex2f(-10,-17);
    glVertex2f(-10,-14);
    glVertex2f(10,-14);

    glVertex2f(10,-11);
    glVertex2f(-10,-11);
    glVertex2f(-10,-8);
    glVertex2f(10,-8);

    glVertex2f(10,-5);
    glVertex2f(-10,-5);
    glVertex2f(-10,-2);
    glVertex2f(10,-2);
    glEnd();

}

void roadlines()
{
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-90,-16);
    glVertex2f(-40,-16);
    glVertex2f(-40,-17);
    glVertex2f(-90,-17);

    glVertex2f(90,-16);
    glVertex2f(40,-16);
    glVertex2f(40,-17);
    glVertex2f(90,-17);
    glEnd();
}


void ship(){

    glPushMatrix();
        glTranslated(sx,sy,0);
        glScaled(3.5,1.5,0);
        glBegin(GL_QUADS);
            glColor3f(0.22f,0.22f,0.22f); ///ship body front
            glVertex2d(0.0f,0.0f);
            glVertex2d(-3.0f,6.0f);
            glVertex2d(10.0f,6.0f);
            glVertex2d(8.0f,0.0f);

            glColor3f(1.0f,1.0f,0.0f); ///yellow box front
            glVertex2d(2.0f,6.0f);
            glVertex2d(2.0f,8.0f);
            glVertex2d(8.0f,8.0f);
            glVertex2d(8.0f,6.0f);

            glColor3f(0.0f,1.0f,0.0f); ///green box front
            glVertex2d(3.0f,8.0f);
            glVertex2d(3.0f,10.0f);
            glVertex2d(7.0f,10.0f);
            glVertex2d(7.0f,8.0f);

            glColor3f(1.0f,0.0f,0.0f); ///red stand front
            glVertex2d(4.0f,8.0f);
            glVertex2d(4.0f,13.0f);
            glVertex2d(6.0f,13.0f);
            glVertex2d(6.0f,8.0f);

        glEnd();
        glPopMatrix();
}


void Tree1(){
    glPushMatrix();
        glTranslated(90,33,0);
        glScaled(2,1,0);
        glPushMatrix();
            glTranslated(-1,-10,1);
            glColor3f(0.55,0.27,0.0745);
            glBegin(GL_QUADS);
                glVertex2d(0.0,0.0);
                glVertex2d(0.0,10.0);
                glVertex2d(1.0,10.0);
                glVertex2d(1.0,0.0);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.5,0,0);
            glScaled(0.4,1,1);
            glPushMatrix();
                glColor3f(0.0,0.39,0.0);
                glTranslatef(0,5,0);
                circle(7,6);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-5.5,1.0,1);
            glColor3f(0.0,0.39,0);
            glTranslatef(0,5,0);
            circle(3,2);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-5.0,4.0,1);
            glColor3f(0.0,0.39,0);
            glTranslatef(0,5,0);
            circle(3,2);
        glPopMatrix();

        glPushMatrix();
            glTranslated(5.5,-0.5,1);
            glColor3f(0.0,0.39,0);
            glTranslatef(0,5,0);
            circle(4,3);
        glPopMatrix();

        glPushMatrix();
            glTranslated(5.0,4.0,1);
            glColor3f(0.0,0.39,0);
            glTranslatef(0,5,0);
            circle(3,2);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.0,6.0,1);
            glColor3f(0.0,0.39,0);
            glTranslatef(0,5,0);
            circle(4,2);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-5.5,-3.0,1);
            glColor3f(0.0,0.39,0);
            glTranslatef(0,5,0);
            circle(4,3);
        glPopMatrix();

        glPushMatrix();
        glTranslated(5.5,-3.5,1);
        glColor3f(0.0,0.39,0);
        glTranslatef(0,5,0);
        circle(3,2);
        glPopMatrix();

    glPopMatrix();
    glPopMatrix();

}


void Tree2(void)
{
    glPushMatrix();
    glColor3f(0.59,0.29,0.0);
    glTranslatef(73.5,33,0);
    glScalef(5,4,0);
    glPushMatrix();
    ///leaves
        glPushMatrix();
            glTranslatef(0,1,0);
            glColor3f(0.0,0.35,0.0);
            circle(0.8,0.8);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0,2,0);
            glColor3f(0.0,0.35,0.0);
            circle(1,1);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-0.9,1.6,0);
            glColor3f(0.4,0.8,0.0);
            circle(0.9,0.9);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.9,1.6,0);
            glColor3f(0.4,0.8,0.0);
            circle(0.9,0.9);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-0.9,2.7,0);
            glColor3f(0,0.65,0.0);
            circle(0.9,0.9);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0,3.2,0);
            glColor3f(0,1,0);
            circle(1,1);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.9,2.7,0);
            glColor3f(0.0,0.65,0.0);
            circle(0.9,0.9);
        glPopMatrix();
    ///trunk
    glColor3f(0.59,0.29,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.3, -2.5);
        glVertex2f(-0.3, 1);
        glVertex2f(0.3, 1);
        glVertex2f(0.3, -2.5);
    glEnd();
    ///branch 1
    glPushMatrix();
        glTranslatef(0.26,-13,0);
        glBegin(GL_POLYGON);
            glVertex2f(-0.5, 14);
            glVertex2f(-1.2, 16);
            glVertex2f(0.04, 14);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2f(-0.5, 14);
            glVertex2f(1, 16);
            glVertex2f(0.04, 14);
        glEnd();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}


void Tree3(){
    glPushMatrix();
        glTranslated(-28,33,0);
        glScaled(2,1,0);
        glPushMatrix();
            glTranslated(-1,-10,1);
            glColor3f(0.55,0.27,0.0745);
            glBegin(GL_QUADS);
                glVertex2d(0.0,0.0);
                glVertex2d(0.0,10.0);
                glVertex2d(1.0,10.0);
                glVertex2d(1.0,0.0);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.5,0,0);
            glScaled(0.4,1,1);
            glPushMatrix();
                glColor3f(0.0,0.54,0.0);
                glTranslatef(0,5,0);
                circle(7,6);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-5.5,1.0,1);
            glColor3f(0.0,0.54,0);
            glTranslatef(0,5,0);
            circle(3,2);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-5.0,4.0,1);
            glColor3f(0.0,0.54,0);
            glTranslatef(0,5,0);
            circle(3,2);
        glPopMatrix();

        glPushMatrix();
            glTranslated(5.5,-0.5,1);
            glColor3f(0.0,0.54,0);
            glTranslatef(0,5,0);
            circle(4,3);
        glPopMatrix();

        glPushMatrix();
            glTranslated(5.0,4.0,1);
            glColor3f(0.0,0.54,0);
            glTranslatef(0,5,0);
            circle(3,2);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.0,6.0,1);
            glColor3f(0.0,0.54,0);
            glTranslatef(0,5,0);
            circle(4,2);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-5.5,-3.0,1);
            glColor3f(0.0,0.54,0);
            glTranslatef(0,5,0);
            circle(4,3);
        glPopMatrix();

        glPushMatrix();
        glTranslated(5.5,-3.5,1);
        glColor3f(0.0,0.54,0);
        glTranslatef(0,5,0);
        circle(3,2);
        glPopMatrix();

    glPopMatrix();
    glPopMatrix();

}

void sun()
{
    glPushMatrix();
        glTranslated(-50,40,0);
        glRotatef(spin, 0.0, 0.0, 1.0);
        glColor3f(1,1,0);
        circle(5.5,5.5);
        glBegin(GL_TRIANGLES);
        glVertex2f(-1,4);
        glVertex2f(1,4);
        glVertex2f(0,12);

        glVertex2f(-1,-4);
        glVertex2f(1,-4);
        glVertex2f(0,-12);

        glVertex2f(4,1);
        glVertex2f(4,-1);
        glVertex2f(12,0);
        glVertex2f(-4,1);
        glVertex2f(-4,-1);
        glVertex2f(-12,0);

        glVertex2f(4,2);
        glVertex2f(2,4);
        glVertex2f(10,10);

        glVertex2f(-4,2);
        glVertex2f(-2,4);
        glVertex2f(-10,10);

        glVertex2f(4,-2);
        glVertex2f(2,-4);
        glVertex2f(10,-10);

        glVertex2f(-4,-2);
        glVertex2f(-2,-4);
        glVertex2f(-10,-10);



        glEnd();
        glPopMatrix();
    glPopMatrix();
}

void spinsun()
{
   spin = spin - .1;
   if (spin < 0.0)
      spin = spin +360.0;
    bx=bx-bc;
    if(bx<-200)
        bx=bx+500;
    sx=sx-sc;
    if(sx<-200)
        sx=sx+500;
    gx=gx-gc;
    if(gx<-200)
        gx=gx+500;
    cx = cx +cg;
    if(cx>200)
        cx=cx-500;
   glutPostRedisplay();
}



void gobus()
{
    bx=bx-.1;
    if(bx<-300)
        bx=bx+600;
    glutPostRedisplay();
}

void signal()
{
    glPushMatrix();
    glTranslatef(-60,-20,0);
    glScaled(2.5,2.5,0.0);

    ///stand
    glColor3f(0.1,0.2,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(15,7);
    glVertex2f(15,8);
    glVertex2f(18,8);
    glVertex2f(18,7);
    glEnd();

    ///pole
    glBegin(GL_POLYGON);
    glVertex2f(16,7);
    glVertex2f(17,8);
    glVertex2f(17,15);
    glVertex2f(16,15);
    glEnd();

    ///board
    glBegin(GL_POLYGON);
    glVertex2f(15.5,15);
    glVertex2f(17.5,15);
    glVertex2f(17.5,10);
    glVertex2f(15.5,10);
    glEnd();

    ///red
    glColor3f(r,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(16,14.5);
    glVertex2f(17,14.5);
    glVertex2f(17,14);
    glVertex2f(16,14);
    glEnd();

    ///yellow
    glColor3f(yel,yel,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(16,13.5);
    glVertex2f(17,13.5);
    glVertex2f(17,13);
    glVertex2f(16,13);
    glEnd();

    ///green
    glColor3f(0.0,gr,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(16,12.5);
    glVertex2f(17,12.5);
    glVertex2f(17,12);
    glVertex2f(16,12);
    glEnd();
    glPopMatrix();
}

void bus()
{
    glPushMatrix();
    glTranslatef(bx,by,0);

    glPushMatrix();
    glTranslatef(-100,-50,0);
    glScaled(6,6,1);
    glColor3f(0.8,0.61,.11);

    ///bus out line
    glBegin(GL_POLYGON);
    glVertex2f(25,8);
    glVertex2f(25,9.5);
    glVertex2f(26,11);
    glVertex2f(32,11);
    glVertex2f(32,8);
    glEnd();

    ///window frame
    glColor3f(0.5,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(26.1,9.5);
    glVertex2f(26.1,10.5);
    glVertex2f(31.8,10.5);
    glVertex2f(31.8,9.5);
    glEnd();

    ///Doors
    glColor3f(0.55,0.41,.08);
    glBegin(GL_POLYGON);
    glVertex2f(26.2,9);
    glVertex2f(26.2,10.4);
    glVertex2f(27.7,10.4);
    glVertex2f(27.7,9);
    glEnd();


    glColor3f(.3,.3,.3);
    glBegin(GL_POLYGON);
    glVertex2f(27,8.4);
    glVertex2f(27,10.4);
    glVertex2f(27.7,10.4);
    glVertex2f(27.7,8.4);
    glEnd();

    ///small windows
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(27.8,9.6);
    glColor3f(0,1,1);
    glVertex2f(27.8,10.4);
    glColor3f(1,1,0);
    glVertex2f(29,10.4);
    glColor3f(0,1,1);
    glVertex2f(29,9.6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(29.1,9.6);
    glColor3f(0,1,1);
    glVertex2f(29.1,10.4);
    glColor3f(1,1,0);
    glVertex2f(30.2,10.4);
    glColor3f(0,1,1);
    glVertex2f(30.2,9.6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex2f(30.3,9.6);
    glColor3f(0,1,1);
    glVertex2f(30.3,10.4);
    glColor3f(1,1,0);
    glVertex2f(31.7,10.4);
    glColor3f(0,1,1);
    glVertex2f(31.7,9.6);
    glEnd();


    ///driver window
    glColor3f(0,0.8,1);
    glBegin(GL_POLYGON);
    glVertex2f(25,9.5);
    glVertex2f(26,11);
    glVertex2f(26,9.5);
    glEnd();
    glPopMatrix();

    ///tyre
    glPushMatrix();
    glTranslatef(60,-1.5,0);
    glColor3f(.36,.36,.36);
    circle(4,4);
    glColor3f(0.55,0,0);
    circle(2,2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(85,-1.5,0);
    glColor3f(.36,.36,.36);
    circle(4,4);

    glColor3f(0.55,0,0);
    circle(2,2);
    glPopMatrix();

    glPopMatrix();

}



void moon()
{
    glPushMatrix();
        glTranslated(-50,40,0);
        glRotatef(spin, 0.0, 0.0, 1.0);
        glColor3f(1,1,1);

        circle(5.5,5.5);
    glPopMatrix();
}


void cloud1()
{
    /*cloudleftx=cloudleftx-0.01;
    if(cloudleftx<-4)
        {
        cloudleftx=40;
    }*/


    glPushMatrix();
     //   glTranslated(-20+cloudleftx,8.5,1);
        glTranslated(-20,43,0);
        glScalef(3,1,0);
        glColor3f(1.0f,1.0f,1.0f);
        glPushMatrix();
            glTranslated(0,0,1),
            circle(1.5,2.5);
        glPopMatrix();

        glPushMatrix();
            glTranslated(1.5,1,1),
            circle(2,3);
        glPopMatrix();

        glPushMatrix();
            glTranslated(4,1.5,1),
            circle(2,3);
        glPopMatrix();

        glPushMatrix();
            glTranslated(4.5,-0.7,1),
            circle(2.5,2.0);
        glPopMatrix();

        glPushMatrix();
            glTranslated(2.0,-1.0,1),
            circle(1.5,2.5);
        glPopMatrix();
    glPopMatrix();


}

void cloud2()
{

   /*cloudrightx-=0.02;
    if(cloudrightx<-35){
        cloudrightx=2;
    }*/


    glPushMatrix();
   // glTranslated(12+cloudrightx,16,1);
    glTranslated(48,80,0);
    glScaled(3,1,0);
    glColor3f(1.0f,1.0f,1.0f);
    glPushMatrix();
    glTranslated(0,-38,1),
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1,-35,1),
    circle(2,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3,-35,1),
    circle(2,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.5,-37.5,1),
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5,-38.5,1),
    circle(1.5,2.5);
    glPopMatrix();
glPopMatrix();
}



void cloud3()
{
   /* cloudmiddlex=cloudmiddlex-0.03;
    if(cloudmiddlex<-20){
        cloudmiddlex=30;
            }*/
    glPushMatrix();
   // glTranslated(-3.5+cloudmiddlex,16,1);
    glTranslated(-80,80,0);
    glScaled(3,1,1);
    glColor3f(1.0f,1.0f,1.0f);
    glPushMatrix();
    glTranslated(0,-38,1),
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1,-35,1),
    circle(2,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3,-35,1),
    circle(2,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.5,-37.5,1),
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5,-38.5,1),
    circle(1.5,2.5);
    glPopMatrix();
glPopMatrix();


}


void building1(){
glPushMatrix();
                glTranslatef(63,39,0);
                glScaled(4,2,0);
                glColor3f(1,0,0);
                 glPushMatrix();
                    glBegin(GL_QUADS);
                        glColor3f(1,1,0); glVertex2d(-1.5,-2.5);
                        glColor3f(1,0.84,0); glVertex2d(1.5,-2.5);
                        glColor3f(0.93,0.83,0.51); glVertex2d(1.5,-7.5);
                        glColor3f(0.85,0.64,0.12); glVertex2d(-1.5,-7.5);
                    glEnd();

                    glBegin(GL_LINES);
                        glColor3f(0,0,0); glVertex2d(-1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-6.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-6.5);
                    glEnd();

                glPopMatrix();
            glPopMatrix();
}

void building2()
{
   glPushMatrix();
                glTranslatef(50,46.5,0);
                glScaled(3,3,0);
                glColor3f(1,0,0);
                 glPushMatrix();
                    glBegin(GL_QUADS);
                        glColor3f(0.48,0.21,0.54); glVertex2d(-1.5,-2.5);
                        glColor3f(0.75,0.24,1); glVertex2d(1.5,-2.5);
                        glColor3f(0.6,0.19,0.8); glVertex2d(1.5,-7.5);
                        glColor3f(0.53,0.4,0.8); glVertex2d(-1.5,-7.5);
                    glEnd();

                    glBegin(GL_LINES);
                        glColor3f(0,0,0); glVertex2d(-1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-6.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-6.5);
                    glEnd();

                glPopMatrix();
            glPopMatrix();

}

void building3(){
glPushMatrix();
                glTranslatef(38,46.5,0);
                glScaled(4,3,0);
                glColor3f(1,0,0);
                 glPushMatrix();
                    glBegin(GL_QUADS);
                        glColor3f(0.4,0.8,0); glVertex2d(-1.5,-2.5);
                        glColor3f(0.75,1,0); glVertex2d(1.5,-2.5);
                        glColor3f(0.6,0.8,0.19); glVertex2d(1.5,-7.5);
                        glColor3f(0.63,0.8,0.35); glVertex2d(-1.5,-7.5);
                    glEnd();

                    glBegin(GL_LINES);
                        glColor3f(0,0,0); glVertex2d(-1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-6.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-6.5);
                    glEnd();

                glPopMatrix();
            glPopMatrix();
}

void building4(){
glPushMatrix();
                glTranslatef(25,54,0);
                glScaled(3,4,0);
                glColor3f(1,0,0);
                 glPushMatrix();
                    glBegin(GL_QUADS);
                        glColor3f(0.545,0,0); glVertex2d(-1.5,-2.5);
                        glColor3f(1,0,0); glVertex2d(1.5,-2.5);
                        glColor3f(0.545,0,0); glVertex2d(1.5,-7.5);
                        glColor3f(0.545,0,0); glVertex2d(-1.5,-7.5);
                    glEnd();

                    glBegin(GL_LINES);
                        glColor3f(0,0,0); glVertex2d(-1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-6.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-6.5);
                    glEnd();

                glPopMatrix();
            glPopMatrix();
}

void building5(){
glPushMatrix();
                glTranslatef(10,46.5,0);
                glScaled(6,3,0);
                glColor3f(1,0,0);
                 glPushMatrix();
                    glBegin(GL_QUADS);
                        glColor3f(1,0.07,0.57); glVertex2d(-1.5,-2.5);
                        glColor3f(1,0.20,0.7); glVertex2d(1.5,-2.5);
                        glColor3f(1,0.68,0.77); glVertex2d(1.5,-7.5);
                        glColor3f(1,0.51,0.67); glVertex2d(-1.5,-7.5);
                    glEnd();

                    glBegin(GL_LINES);
                        glColor3f(0,0,0); glVertex2d(-1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-6.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-6.5);
                    glEnd();

                glPopMatrix();
            glPopMatrix();
}

void building6(){
glPushMatrix();
                glTranslatef(-6,39,0);
                glScaled(4,2,0);
                glColor3f(1,0,0);
                 glPushMatrix();
                    glBegin(GL_QUADS);
                        glColor3f(1,0.18,0.18); glVertex2d(-1.5,-2.5);
                        glColor3f(1,0.25,0.25); glVertex2d(1.5,-2.5);
                        glColor3f(0.8,0.2,0.2); glVertex2d(1.5,-7.5);
                        glColor3f(1,0.62,0.48); glVertex2d(-1.5,-7.5);
                    glEnd();

                    glBegin(GL_LINES);
                        glColor3f(0,0,0); glVertex2d(-1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-6.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-6.5);
                    glEnd();

                glPopMatrix();
            glPopMatrix();
}


void building7(){
glPushMatrix();
                glTranslatef(-18,46.5,0);
                glScaled(3,3,0);
                glColor3f(1,0,0);
                 glPushMatrix();
                    glBegin(GL_QUADS);
                        glColor3f(0,1,0.5); glVertex2d(-1.5,-2.5);
                        glColor3f(0.18,0.54,0.34); glVertex2d(1.5,-2.5);
                        glColor3f(0.48,0.8,0.48); glVertex2d(1.5,-7.5);
                        glColor3f(0,0.54,0.27); glVertex2d(-1.5,-7.5);
                    glEnd();

                    glBegin(GL_LINES);
                        glColor3f(0,0,0); glVertex2d(-1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-6.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-6.5);
                    glEnd();

                glPopMatrix();
            glPopMatrix();
}

void building8(){
glPushMatrix();
                glTranslatef(-40,39,0);
                glScaled(4,2,0);
                glColor3f(1,0,0);
                 glPushMatrix();
                    glBegin(GL_QUADS);
                        glColor3f(0.54,0.52,0.3); glVertex2d(-1.5,-2.5);
                        glColor3f(1,0.96,0.56); glVertex2d(1.5,-2.5);
                        glColor3f(0.8,0.74,0.44); glVertex2d(1.5,-7.5);
                        glColor3f(0.93,0.9,0.52); glVertex2d(-1.5,-7.5);
                    glEnd();

                    glBegin(GL_LINES);
                        glColor3f(0,0,0); glVertex2d(-1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-6.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-6.5);
                    glEnd();

                glPopMatrix();
            glPopMatrix();
}

void building9(){
glPushMatrix();
                glTranslatef(-67,46.5,0);
                glScaled(3,3,0);
                glColor3f(1,0,0);
                 glPushMatrix();
                    glBegin(GL_QUADS);
                        glColor3f(0.37,0.37,0.37); glVertex2d(-1.5,-2.5);
                        glColor3f(0.57,0.57,0.57); glVertex2d(1.5,-2.5);
                        glColor3f(0.48,0.48,0.48); glVertex2d(1.5,-7.5);
                        glColor3f(0.78,0.78,0.78); glVertex2d(-1.5,-7.5);
                    glEnd();

                    glBegin(GL_LINES);
                        glColor3f(0,0,0); glVertex2d(-1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-6.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-6.5);
                    glEnd();

                glPopMatrix();
            glPopMatrix();
}

void building10(){
glPushMatrix();
                glTranslatef(-79,39,0);
                glScaled(4,2,0);
                glColor3f(1,0,0);
                 glPushMatrix();
                    glBegin(GL_QUADS);
                        glColor3f(0,0,1); glVertex2d(-1.5,-2.5);
                        glColor3f(0.51,0.43,1); glVertex2d(1.5,-2.5);
                        glColor3f(0,0,1); glVertex2d(1.5,-7.5);
                        glColor3f(0.51,0.43,1); glVertex2d(-1.5,-7.5);
                    glEnd();

                    glBegin(GL_LINES);
                        glColor3f(0,0,0); glVertex2d(-1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-6.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-6.5);
                    glEnd();

                glPopMatrix();
            glPopMatrix();
}



void building11(){
glPushMatrix();
                glTranslatef(-92,54,0);
                glScaled(4,4,0);
                glColor3f(1,0,0);
                 glPushMatrix();
                    glBegin(GL_QUADS);
                        glColor3f(1,0.75,0.75); glVertex2d(-1.5,-2.5);
                        glColor3f(0.8,0.61,0.61); glVertex2d(1.5,-2.5);
                        glColor3f(0.54,0.41,0.41); glVertex2d(1.5,-7.5);
                        glColor3f(0.93,0.7,0.7); glVertex2d(-1.5,-7.5);
                    glEnd();

                    glBegin(GL_LINES);
                        glColor3f(0,0,0); glVertex2d(-1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-3.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-4.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-5.5);
                        glColor3f(0,0,0); glVertex2d(-1.5,-6.5);
                        glColor3f(0,0,0); glVertex2d(1.5,-6.5);
                    glEnd();

                glPopMatrix();
            glPopMatrix();
}

void display1(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    sky1();
    glutIdleFunc(gobus);
    glutIdleFunc(spinsun);
    moon();
    river();
    divider();
    footpath();
    footpath1();
    zigzag();
    roadlines();
    ship();
    signal();
    girl();
 //   cloud1();
   // cloud2();
   // cloud3();
    building1(); building2(); building3(); building4();
    building5(); building6(); building7(); building8();
    building9(); building10(); building11();
    bus();
    car();

    Tree1();
    Tree2();
    Tree3();
    //night();
	glFlush();
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    glutIdleFunc(gobus);
    glutIdleFunc(spinsun);
    sun();
    river();
    divider();
    footpath();
    footpath1();
    zigzag();
    roadlines();
    ship();
    signal();
    girl();
    cloud1();
    cloud2();
    cloud3();
    building1(); building2(); building3(); building4();
    building5(); building6(); building7(); building8();
    building9(); building10(); building11();
    bus();
    car();

    Tree1();
    Tree2();
    Tree3();
    //night();
	glFlush();
}

void init(void)
{
	glClearColor (0.57, 0.57, 0.57, 1.0);
	glOrtho(-100, 100, -50, 50, -1.0, 1.0);
}


void myKeyboard( unsigned char key, int x, int y )
{
    switch(key)
    {
    case 's':
        if(flag==1){
            sc=.5;
            gc=.5;
            gx=sx;
            gy=20;
            gsx=gsx/1.5;
            gsy=gsy/1.5;
            flag=0;
            glutPostRedisplay();
        }
        else
        {
            sc=0;
            sx=1;
            gx=0;
            gy=15;
            gsx=1;
            gsy=.9;
            gc=0;
            flag=1;
            glutPostRedisplay();
        }
        break;

    case 'b':
        if(flag==1)
        {
            gx=-200;
            flag=0;
        }
        else
        {
            gx=0;
            flag=1;
        }
        break;
    case 'r':
        {
            bc=0;
            cg = 0;
            r=1;
            gr=0;
            yel=0;
        }
        break;
        case 'y':
        {
            bc=0;
            cg = 0;
            yel=1;
            gr=0;r=0;
        }
        break;
        case 'g':
        {
            bc=.1;
            cg = .2;
            gr=1;
            yel=0;
            r=0;
        }
        break;
        case 'n':
            glutDisplayFunc(display1);
            break;
        case 'd':
            glutDisplayFunc(display);
            break;


    default:break;

    }
}

void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:
		    if(gx>=-90){
				gx -=5;
				glutPostRedisplay();
		    }
				break;

		case GLUT_KEY_RIGHT:
		    if(gx<=90){
				gx +=5;
				glutPostRedisplay();
		    }
				break;

        case GLUT_KEY_DOWN:
            if(gy>=-40){
				gy -=5;
				gsx=gsx*1.08;
				gsy=gsy*1.08;
				glutPostRedisplay();
            }
				break;

		case GLUT_KEY_UP:
		    if(gy<=15){
				gy +=5;
				gsx=gsx/1.08;
				gsy=gsy/1.08;
				glutPostRedisplay();
	}
				break;
	  default:
			break;
	}
}

int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1350, 700);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Scenery of Town");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(spe_key);
    glutMainLoop();
	return 0;
}
