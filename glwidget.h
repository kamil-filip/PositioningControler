#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>
#include <vector>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
using namespace std;

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);


public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

private:

    int d_xRot;
    int d_yRot;
    int d_zRot;
    GLuint elephant;
    float elephantrot;


    static void qNormalizeAngle(int &angle);
    static void loadObj(char const *fileName);


};

#endif // GLWIDGET_H
