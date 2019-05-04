#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QLabel>
#include <QLayout>
#include <QInputDialog>
#include <vector.h>
#include "RenderArea.h"
#include "createshape.h"
#include "login.h"
#include "contactinfo.h"
#include "comment.h"
#include "aboutus.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void shapeChanged();
    void penChanged();
    void brushChanged();

    void GenerateShape(const newShapeInfo&);

    void on_actionNew_Shape_triggered();

    void on_actionDelete_Shape_triggered();

    void on_actionMove_Shape_triggered();

    void on_actionContact_Us_triggered();

    void on_actionSupport_triggered();

    void on_actionComments_triggered();

    void on_actionAbout_Us_triggered();

private:
    Ui::MainWindow *ui;
    RenderArea *renderArea;
    CreateShape *createShape;
    Login *login;
    ContactInfo* contactInfo;
    Comment* comment;
    AboutUs* aboutUs;
};

#endif // MAINWINDOW_H
