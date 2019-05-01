#ifndef CREATESHAPE_H
#define CREATESHAPE_H

#include <QDialog>
#include <QGroupBox>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QDebug>

#include "Ellipse.h"
#include "Line.h"
#include "Polygon.h"
#include "Polyline.h"
#include "Rectangle.h"
#include "Textbox.h"

const int MAX_DIMENSION  = 1000;
const int MAX_POLY_SIDES = 12;
const int IdRole = Qt::UserRole;

enum ShapeValues
{
    NO_SHAPE        = 0,
    LINE_VALUE      = 1,
    POLYLINE_VALUE  = 2,
    POLYGON_VALUE   = 3,
    RECTANGLE_VALUE = 4,
    SQUARE_VALUE    = 5,
    ELLIPSE_VALUE   = 6,
    CIRCLE_VALUE    = 7,
    TEXT_VALUE      = 8
};

struct newShapeInfo
{
    int           shapeId;
    QPen          shapePen;
    QBrush        brush;
    QFont         font;
    Vector<int>   dimensions;
    QString       text;
    Qt::Alignment allignment;
    QPen          textPen;
};

namespace Ui {
class CreateShape;
}

class CreateShape : public QDialog
{
    Q_OBJECT

public:
    explicit CreateShape(QWidget *parent = nullptr);
    ~CreateShape();

    void InitializeUIValues();
    void SetFirstPgValues();
    void SetSecondPgValues();

    newShapeInfo GenerateShape();

    Qt::GlobalColor StrToColor(QString) const;
    Qt::PenStyle StrToPenStyle(const QString&) const;
    Qt::PenCapStyle StrToCapStyle(const QString&)const;
    Qt::PenJoinStyle StrToJoinStyle(const QString&)const;
    Qt::BrushStyle StrToBrushStyle(const QString&)const;
    QFont::Style StrToFontStyle(const QString&)const;
    QFont::Weight StrToFontWeight(const QString&)const;
    Qt::Alignment StrToAllignment(const QString&) const;

signals:
    void shapeGenerated(const newShapeInfo& NEW_SHAPE);

private slots:
    void ShapeComboBox(const int& ARGUMENT);
    void GoToSecPage();
    void EnablePolySides(const int& ARGUMENT);
    void CompleteShape();


private:
    Ui::CreateShape *ui;

    QGroupBox *pickShape;
    QGroupBox *shapeInfo;

    QVBoxLayout *mainLayout;
    QFormLayout *pickShapeLayout;
    QFormLayout *shapeValuesLayout;

    QLabel *shapeLabel;
    QLabel *penWidthLabel;
    QLabel *penStyleLabel;
    QLabel *penCapLabel;
    QLabel *penJoinLabel;
    QLabel *penColorLabel;
    QLabel *brushColorLabel;
    QLabel *brushStyleLabel;
    QLabel *textStringLabel;
    QLabel *textColorLabel;
    QLabel *textAlignmentLabel;
    QLabel *textPointSizeLabel;
    QLabel *textFontFamilyLabel;
    QLabel *textFontStyleLabel;
    QLabel *textFontWeightLabel;
    QLabel *polySidesLabel;

    QPushButton *page2;
    QPushButton *finished;

    QComboBox *shapeCBox;
    QComboBox *penStyleCBox;
    QComboBox *penCapCBox;
    QComboBox *penJoinCBox;
    QComboBox *penColorCBox;
    QComboBox *brushColorCBox;
    QComboBox *brushStyleCBox;
    QComboBox *textColorCBox;
    QComboBox *textAllignmentCBox;
    QComboBox *textFontFamilyCBox;
    QComboBox *textFontStyleCBox;
    QComboBox *textFontWeightCBox;

    QSpinBox *penWidthBox;
    QSpinBox *textPointBox;
    QSpinBox *polySidesBox;

    QLineEdit *textString;

    Vector<QLabel*> *dimensionsLabels;
    Vector<QSpinBox*> *dimensionsSpinBox;
};

#endif // CREATESHAPE_H
