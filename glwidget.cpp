#include "glwidget.h"


GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent), d_xRot(0), d_yRot(0), d_zRot(0) {}

void GLWidget::initializeGL()
{
    glClearColor(0.2, 0.2, 0.2, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}



void GLWidget::setXRotation(int angle)
{



   qNormalizeAngle(angle);
   if (angle != d_xRot)
   {
        d_xRot = angle;
        paintGL();
        emit xRotationChanged(angle);
   }
}

void GLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != d_yRot)
    {
        d_yRot = angle;
        paintGL();
        emit yRotationChanged(angle);

    }
}

void GLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != d_zRot)
    {
        d_zRot = angle;
        paintGL();
        emit zRotationChanged(angle);
    }
}

void xRotationChanged(int angle)
{

}

void yRotationChanged(int angle)
{



}

void zRotationChanged(int angle)
{

}


void GLWidget::loadObj(char const *fileName)
{

}

void GLWidget::qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;

    while (angle > 360)
        angle -= 360 * 16;
}


void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glRotatef(0.5, 1, 1, 1);
    glColor3f(1, 0.6, 0);
    glutSolidTeapot(0.6);


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(d_xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(d_yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(d_zRot / 16.0, 0.0, 0.0, 1.0);
    glutSolidTeapot(0.6);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 0.01, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,5,0,0,0,0,1,0);
}
