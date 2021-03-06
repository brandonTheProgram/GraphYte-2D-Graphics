#include "createshape.h"
#include "ui_CreateShape.h"

//Constructor
CreateShape::CreateShape(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateShape)
{
    ui->setupUi(this);

    //Set the values for the UI
    InitializeUIValues();

    //Create the first page
    SetFirstPgValues();

    //Get the index whenever the shape combobox changes
    connect(shapeCBox, SIGNAL(activated(int)), this, SLOT(ShapeComboBox(int)));

    //Connect the button to go to the next page
    connect(page2, SIGNAL(clicked()), this, SLOT(GoToSecPage()));

    //Connect the button to go to finish the shape
    connect(finished, SIGNAL(clicked()), this, SLOT(CompleteShape()));

    //Get the value whenever the spinbox changes
    connect(polySidesBox, SIGNAL(valueChanged(int)),
            this, SLOT(EnablePolySides(int)));

    //Block input from other windows exccept this main one
    setWindowModality(Qt::ApplicationModal);
}

//Deconstructor
CreateShape::~CreateShape()
{
    delete ui;
    delete pickShape;
    delete shapeInfo;
    delete pickShapeLayout;
    delete shapeValuesLayout;
    delete mainLayout;
    delete shapeLabel;
    delete shapeNameLabel;
    delete penWidthLabel;
    delete penStyleLabel;
    delete penCapLabel;
    delete penJoinLabel;
    delete penColorLabel;
    delete brushColorLabel;
    delete brushStyleLabel;
    delete textStringLabel;
    delete textColorLabel;
    delete textAlignmentLabel;
    delete textPointSizeLabel;
    delete textFontFamilyLabel;
    delete textFontStyleLabel;
    delete textFontWeightLabel;
    delete polySidesLabel;
    delete page2;
    delete finished;
    delete shapeCBox;
    delete penStyleCBox;
    delete penCapCBox;
    delete penJoinCBox;
    delete penColorCBox;
    delete brushColorCBox;
    delete brushStyleCBox;
    delete textColorCBox;
    delete textAllignmentCBox;
    delete textFontFamilyCBox;
    delete textFontStyleCBox;
    delete textFontWeightCBox;
    delete penWidthBox;
    delete textPointBox;
    delete polySidesBox;
    delete shapeName;
    delete textString;

    for(auto it: *dimensionsLabels)
        delete it;

    for(auto nextIt: *dimensionsSpinBox)
        delete nextIt;

    delete dimensionsLabels;
    delete dimensionsSpinBox;
}

//Constructor shortcut
void CreateShape::InitializeUIValues()
{
    pickShape           = new QGroupBox;
    shapeInfo           = new QGroupBox;

    mainLayout          = new QVBoxLayout;
    pickShapeLayout     = new QFormLayout;
    shapeValuesLayout   = new QFormLayout;

    shapeLabel          = new QLabel;
    shapeNameLabel      = new QLabel;
    penWidthLabel       = new QLabel;
    penStyleLabel       = new QLabel;
    penJoinLabel        = new QLabel;
    penCapLabel         = new QLabel;
    penColorLabel       = new QLabel;
    brushColorLabel     = new QLabel;
    brushStyleLabel     = new QLabel;
    textStringLabel     = new QLabel;
    textColorLabel      = new QLabel;
    textAlignmentLabel  = new QLabel;
    textPointSizeLabel  = new QLabel;
    textFontFamilyLabel = new QLabel;
    textFontStyleLabel  = new QLabel;
    textFontWeightLabel = new QLabel;
    polySidesLabel      = new QLabel;

    page2               = new QPushButton;
    finished            = new QPushButton;

    shapeCBox           = new QComboBox;
    penStyleCBox        = new QComboBox;
    penCapCBox          = new QComboBox;
    penJoinCBox         = new QComboBox;
    penColorCBox        = new QComboBox;
    brushColorCBox      = new QComboBox;
    brushStyleCBox      = new QComboBox;
    textColorCBox       = new QComboBox;
    textAllignmentCBox  = new QComboBox;
    textFontFamilyCBox  = new QComboBox;
    textFontStyleCBox   = new QComboBox;
    textFontWeightCBox  = new QComboBox;

    penWidthBox         = new QSpinBox;
    textPointBox        = new QSpinBox;
    polySidesBox        = new QSpinBox;

    shapeName           = new QLineEdit;
    textString          = new QLineEdit;

    dimensionsLabels    = new Vector<QLabel*>;
    dimensionsSpinBox   = new Vector<QSpinBox*>;

    //Add the widgets to the UI
    mainLayout->addWidget(pickShape);
    mainLayout->addWidget(shapeInfo);

    //Disable the second page
    shapeInfo ->setEnabled(false);

    setLayout(mainLayout);
}

//Initialize the values for the first page
void CreateShape::SetFirstPgValues()
{
    shapeLabel          ->setText("Shape:");
    shapeNameLabel      ->setText("Shape Name:");
    penColorLabel       ->setText("Pen Color:");
    penWidthLabel       ->setText("Pen Width:");
    penStyleLabel       ->setText("Pen Style:");
    penCapLabel         ->setText("Pen Cap Style:");
    penJoinLabel        ->setText("Pen Join Style:");
    brushColorLabel     ->setText("Brush Color:");
    brushStyleLabel     ->setText("Brush Style:");
    textStringLabel     ->setText("Text Message:");
    textColorLabel      ->setText("Text Color:");
    textAlignmentLabel  ->setText("Text Allignment:");
    textPointSizeLabel  ->setText("Text Point Size:");
    textFontFamilyLabel ->setText("Text Font Family:");
    textFontStyleLabel  ->setText("Text Font Style:");
    textFontWeightLabel ->setText("Text Font Weight:");

    shapeCBox   ->addItem("No Shape");
    shapeCBox   ->addItem("Line");
    shapeCBox   ->addItem("Polyline");
    shapeCBox   ->addItem("Polygon");
    shapeCBox   ->addItem("Rectangle");
    shapeCBox   ->addItem("Square");
    shapeCBox   ->addItem("Ellipse");
    shapeCBox   ->addItem("Circle");
    shapeCBox   ->addItem("Text");

    penColorCBox->addItem("No Color");
    penColorCBox->addItem("White");
    penColorCBox->addItem("Black");
    penColorCBox->addItem("Red");
    penColorCBox->addItem("Green");
    penColorCBox->addItem("Blue");
    penColorCBox->addItem("Cyan");
    penColorCBox->addItem("Magenta");
    penColorCBox->addItem("Yellow");
    penColorCBox->addItem("Gray");

    penStyleCBox->addItem("No Pen");
    penStyleCBox->addItem("Solid Line");
    penStyleCBox->addItem("Dash Line");
    penStyleCBox->addItem("Dot Line");
    penStyleCBox->addItem("Dash Dot Line");
    penStyleCBox->addItem("Dash Dot Dot Line");

    penCapCBox  ->addItem("Flat");
    penCapCBox  ->addItem("Square");
    penCapCBox  ->addItem("Round");

    penJoinCBox->addItem("Miter");
    penJoinCBox->addItem("Bevel");
    penJoinCBox->addItem("Round");

    brushColorCBox->addItem("No Color");
    brushColorCBox->addItem("White");
    brushColorCBox->addItem("Black");
    brushColorCBox->addItem("Red");
    brushColorCBox->addItem("Green");
    brushColorCBox->addItem("Blue");
    brushColorCBox->addItem("Cyan");
    brushColorCBox->addItem("Magenta");
    brushColorCBox->addItem("Yellow");
    brushColorCBox->addItem("Gray");

    brushStyleCBox->addItem("None");
    brushStyleCBox->addItem("Solid");
    brushStyleCBox->addItem("Horizontal");
    brushStyleCBox->addItem("Vertical");

    textColorCBox ->addItem("No Color");
    textColorCBox ->addItem("White");
    textColorCBox ->addItem("Black");
    textColorCBox ->addItem("Red");
    textColorCBox ->addItem("Green");
    textColorCBox ->addItem("Blue");
    textColorCBox ->addItem("Cyan");
    textColorCBox ->addItem("Magenta");
    textColorCBox ->addItem("Yellow");
    textColorCBox ->addItem("Gray");

    textAllignmentCBox->addItem("Allign Left");
    textAllignmentCBox->addItem("Allign Right");
    textAllignmentCBox->addItem("Allign Top");
    textAllignmentCBox->addItem("Allign Bottom");
    textAllignmentCBox->addItem("Allign Center");

    textFontFamilyCBox->addItem("Comic Sans MS");
    textFontFamilyCBox->addItem("Courier");
    textFontFamilyCBox->addItem("Helvetica");
    textFontFamilyCBox->addItem("Times");

    textFontStyleCBox->addItem("Normal Style");
    textFontStyleCBox->addItem("Italic Style");
    textFontStyleCBox->addItem("Oblique Style");

    textFontWeightCBox->addItem("Thin");
    textFontWeightCBox->addItem("Light");
    textFontWeightCBox->addItem("Normal");
    textFontWeightCBox->addItem("Bold");

    page2->setText("CONTINUE");

    penWidthBox ->setRange(0, 20);
    textPointBox->setRange(0, 50);

    //Disable all features until a shape is chosen
    shapeName           ->setEnabled(false);
    penColorCBox        ->setEnabled(false);
    penStyleCBox        ->setEnabled(false);
    penCapCBox          ->setEnabled(false);
    penJoinCBox         ->setEnabled(false);
    brushColorCBox      ->setEnabled(false);
    brushStyleCBox      ->setEnabled(false);
    textColorCBox       ->setEnabled(false);
    textAllignmentCBox  ->setEnabled(false);
    textFontFamilyCBox  ->setEnabled(false);
    textFontStyleCBox   ->setEnabled(false);
    textFontWeightCBox  ->setEnabled(false);
    penWidthBox         ->setEnabled(false);
    textPointBox        ->setEnabled(false);
    textString          ->setEnabled(false);

    //Add each row to the screen
    pickShapeLayout->addRow(shapeLabel,          shapeCBox);
    pickShapeLayout->addRow(shapeNameLabel,      shapeName);
    pickShapeLayout->addRow(penColorLabel,       penColorCBox);
    pickShapeLayout->addRow(penWidthLabel,       penWidthBox);
    pickShapeLayout->addRow(penStyleLabel,       penStyleCBox);
    pickShapeLayout->addRow(penCapLabel,         penCapCBox);
    pickShapeLayout->addRow(penJoinLabel,        penJoinCBox);
    pickShapeLayout->addRow(brushColorLabel,     brushColorCBox);
    pickShapeLayout->addRow(brushStyleLabel,     brushStyleCBox);
    pickShapeLayout->addRow(textStringLabel,     textString);
    pickShapeLayout->addRow(textColorLabel,      textColorCBox);
    pickShapeLayout->addRow(textAlignmentLabel,  textAllignmentCBox);
    pickShapeLayout->addRow(textPointSizeLabel,  textPointBox);
    pickShapeLayout->addRow(textFontFamilyLabel, textFontFamilyCBox);
    pickShapeLayout->addRow(textFontStyleLabel,  textFontStyleCBox);
    pickShapeLayout->addRow(textFontWeightLabel, textFontWeightCBox);
    pickShapeLayout->addWidget(page2);

    //Set the allignment for the rows
    pickShapeLayout->setFormAlignment(Qt::AlignCenter);
    pickShapeLayout->setVerticalSpacing(25);

    //Set the layout
    pickShape->setLayout(pickShapeLayout);
}

//Initialize the values for the second page
void CreateShape::SetSecondPgValues()
{
    QLabel   *newLabel;                                 //The new label

    QSpinBox *newSpinBox;                               //The new spinbox

    ShapeType shapeType;                                //The enumerated shape

    int       index;                                    //The index in the array
    int       cordCounter   = 1;                        //The counter for the
                                                        //amount of cordiantes

    shapeValuesLayout->setSpacing(0);

    polySidesLabel->setText("# of Sides:");

    polySidesBox->setRange(0, (MAX_POLY_SIDES / 2));

    polySidesBox->setValue(0);

    polySidesBox->setEnabled(false);

    //Change the shape index into an enumerated type matching
    shapeType = static_cast<ShapeType>(shapeCBox->currentIndex());

    //Find out how many labels are needed for each shape
    switch(shapeType)
    {
    case ShapeType::NoShape:          break;

    case ShapeType::Polyline:
    case ShapeType::Polygon:     for(index = 0; index < MAX_POLY_SIDES; index++)
                            {
                                newLabel = new QLabel;
                                if(index % 2 == 0)
                                {
                                    newLabel->setText
                                           ("X" + QString::number(cordCounter)
                                                + ":");
                                }
                                else
                                {
                                    newLabel->setText
                                           ("Y" + QString::number(cordCounter)
                                                + ":");
                                    cordCounter++;
                                }
                                dimensionsLabels->push_back(newLabel);
                            }
                            break;

    case ShapeType::Line:
    case ShapeType::Rectangle:
    case ShapeType::Text:
    case ShapeType::Ellipse:for(index = 0; index < 4; index++)
                            {
                                newLabel = new QLabel;

                                switch(index)
                                {
                                case 0:     newLabel->setText("X1:");
                                            break;

                                case 1:     newLabel->setText("Y1:");
                                            break;

                                case 2:     if(shapeType == ShapeType::Text)
                                                newLabel->setText("X2:");

                                            else if(shapeType ==
                                                    ShapeType::Ellipse)
                                            {
                                                newLabel->setText
                                                        ("Semi Major Axis:");
                                            }

                                            else
                                                newLabel->setText("Length:");

                                            break;

                                case 3:     if(shapeType == ShapeType::Text)
                                                newLabel->setText("Y2:");

                                            else if(shapeType ==
                                                    ShapeType::Ellipse)
                                            {
                                                newLabel->setText
                                                        ("Semi Minor Axis:");
                                            }

                                            else
                                                newLabel->setText("Width:");
                                            break;

                                default:    break;
                                }

                                dimensionsLabels->push_back(newLabel);
                            }
                            break;

    case ShapeType::Square:
    case ShapeType::Circle: for(index = 0; index < 3; index++)
                            {
                                newLabel = new QLabel;

                                switch(index)
                                {
                                case 0:     newLabel->setText("X1:");
                                            break;

                                case 1:     newLabel->setText("Y1:");
                                            break;

                                case 2:     if(shapeType == ShapeType::Square)
                                                newLabel->setText("Length:");
                                            else
                                                newLabel->setText("Radius:");
                                            break;

                                default:    break;
                                }

                                dimensionsLabels->push_back(newLabel);
                            }
                            break;
    }

    shapeValuesLayout->addRow(polySidesLabel,polySidesBox);

    //Create a new spinbox for every label that was created
    for(index = 0; index < dimensionsLabels->size(); index++)
    {
        newSpinBox = new QSpinBox;
        newSpinBox->setRange(-1, MAX_DIMENSION);
        newSpinBox->setValue(-1);

        //Disable the spinbox if they are a Polyline or Polygon
        if(shapeType == ShapeType::Polyline || shapeType == ShapeType::Polygon)
            newSpinBox->setEnabled(false);

        dimensionsSpinBox->push_back(newSpinBox);
        shapeValuesLayout->addRow(dimensionsLabels->operator[](index),
                                  newSpinBox);
    }

    finished->setText("Finished!");

    shapeValuesLayout->addWidget(finished);

    shapeValuesLayout->setFormAlignment(Qt::AlignCenter);

    shapeValuesLayout->setVerticalSpacing(10);

    //Enable the poly spinbox if the shape is part of the Poly family
    if(shapeType == ShapeType::Polyline || shapeType == ShapeType::Polygon)
        polySidesBox->setEnabled(true);

    shapeInfo->setLayout(shapeValuesLayout);
}

//Create a new shape using the information stored from the user choices
newShapeInfo CreateShape::GenerateShape()
{
    newShapeInfo newShape;  //The new shape

    ShapeType shapeType;    //The enumerated type to match the shape

    newShape.shapeId = shapeCBox->currentIndex();
    newShape.name    = shapeName->text();
    shapeType        = static_cast<ShapeType>(newShape.shapeId);

    for(int index = 0; index < dimensionsSpinBox->size(); index++)
    {
        newShape.dimensions.push_back
                (dimensionsSpinBox->operator[](index)->value());
    }

    if(shapeType != ShapeType::Text)
    {
        newShape.shapePen.setColor(StrToColor(penColorCBox->currentText()));
        newShape.shapePen.setWidth(penWidthBox->value());
        newShape.shapePen.setStyle(StrToPenStyle(penStyleCBox->currentText()));
        newShape.shapePen.setCapStyle(StrToCapStyle(penCapCBox->currentText()));
        newShape.shapePen.setJoinStyle(StrToJoinStyle
                                       (penJoinCBox->currentText()));
        if(shapeType == ShapeType::Polyline || shapeType == ShapeType::Polygon)
        {
            newShape.brush.setColor(StrToColor(brushColorCBox->currentText()));
            newShape.brush.setStyle(StrToBrushStyle
                                    (brushStyleCBox->currentText()));
        }
    }
    else
    {
        newShape.text = textString->text();
        newShape.textPen.setColor(StrToColor(textColorCBox->currentText()));
        newShape.allignment =StrToAllignment(textAllignmentCBox->currentText());
        newShape.font.setFamily(textFontFamilyCBox->currentText());
        newShape.font.setStyle(StrToFontStyle
                               (textFontStyleCBox->currentText()));
        newShape.font.setWeight(StrToFontWeight
                                (textFontWeightCBox->currentText()));
    }

    return newShape;
}

//Enable or Disable the boxs based on the current index of the Combobox
void CreateShape::ShapeComboBox(const int& ARGUMENT)
{
    ShapeType shapeType; //The enumerated type to match the shape

    shapeType = static_cast<ShapeType>(ARGUMENT);

    switch(shapeType)
    {
    case ShapeType::NoShape://Disable all features until a shape is chosen
                            shapeName           ->setEnabled(false);
                            penColorCBox        ->setEnabled(false);
                            penStyleCBox        ->setEnabled(false);
                            penCapCBox          ->setEnabled(false);
                            penJoinCBox         ->setEnabled(false);
                            brushColorCBox      ->setEnabled(false);
                            brushStyleCBox      ->setEnabled(false);
                            textColorCBox       ->setEnabled(false);
                            textAllignmentCBox  ->setEnabled(false);
                            textFontFamilyCBox  ->setEnabled(false);
                            textFontStyleCBox   ->setEnabled(false);
                            textFontWeightCBox  ->setEnabled(false);
                            penWidthBox         ->setEnabled(false);
                            textPointBox        ->setEnabled(false);
                            textString          ->setEnabled(false);
                            break;

    case ShapeType::Line:
    case ShapeType::Polyline://Enable all options needed for lines
                            shapeName           ->setEnabled(true);
                            penColorCBox        ->setEnabled(true);
                            penStyleCBox        ->setEnabled(true);
                            penCapCBox          ->setEnabled(true);
                            penJoinCBox         ->setEnabled(true);
                            brushColorCBox      ->setEnabled(false);
                            brushStyleCBox      ->setEnabled(false);
                            textColorCBox       ->setEnabled(false);
                            textAllignmentCBox  ->setEnabled(false);
                            textFontFamilyCBox  ->setEnabled(false);
                            textFontStyleCBox   ->setEnabled(false);
                            textFontWeightCBox  ->setEnabled(false);
                            penWidthBox         ->setEnabled(true);
                            textPointBox        ->setEnabled(false);
                            textString          ->setEnabled(false);
                            break;
    case ShapeType::Polygon:
    case ShapeType::Rectangle:
    case ShapeType::Square:
    case ShapeType::Ellipse:
    case ShapeType::Circle: //Enable all options needed for the necessary shapes
                            shapeName           ->setEnabled(true);
                            penColorCBox        ->setEnabled(true);
                            penStyleCBox        ->setEnabled(true);
                            penCapCBox          ->setEnabled(true);
                            penJoinCBox         ->setEnabled(true);
                            brushColorCBox      ->setEnabled(true);
                            brushStyleCBox      ->setEnabled(true);
                            textColorCBox       ->setEnabled(false);
                            textAllignmentCBox  ->setEnabled(false);
                            textFontFamilyCBox  ->setEnabled(false);
                            textFontStyleCBox   ->setEnabled(false);
                            textFontWeightCBox  ->setEnabled(false);
                            penWidthBox         ->setEnabled(true);
                            textPointBox        ->setEnabled(false);
                            textString          ->setEnabled(false);
                            break;
    case ShapeType::Text:   //Enable all options needed for text box
                            shapeName           ->setEnabled(true);
                            penColorCBox        ->setEnabled(false);
                            penStyleCBox        ->setEnabled(false);
                            penCapCBox          ->setEnabled(false);
                            penJoinCBox         ->setEnabled(false);
                            brushColorCBox      ->setEnabled(false);
                            brushStyleCBox      ->setEnabled(false);
                            textColorCBox       ->setEnabled(true);
                            textAllignmentCBox  ->setEnabled(true);
                            textFontFamilyCBox  ->setEnabled(true);
                            textFontStyleCBox   ->setEnabled(true);
                            textFontWeightCBox  ->setEnabled(true);
                            penWidthBox         ->setEnabled(false);
                            textPointBox        ->setEnabled(true);
                            textString          ->setEnabled(true);
                    break;
    }
}

//Check to see if the user is ready to go to the second page and take them there
void CreateShape::GoToSecPage()
{
    bool      completed;    //The condition to continue

    ShapeType shapeType;    //The enumerated type to match the shape

    completed = false;
    shapeType = static_cast<ShapeType>(shapeCBox->currentIndex());

    //Based on the shape chosen, check if they have completed all the
    //necessary fields
    switch(shapeType)
    {
    case ShapeType::NoShape:          break;

    case ShapeType::Line:
    case ShapeType::Polyline: if(penColorCBox->currentIndex() != 0 &&
                                 penStyleCBox->currentIndex() != 0 &&
                                 penWidthBox ->value()        != 0 &&
                                 shapeName->text().isEmpty()   == false)
                                    {completed = true;}

                              break;

    case ShapeType::Polygon:
    case ShapeType::Rectangle:
    case ShapeType::Square:
    case ShapeType::Ellipse:
    case ShapeType::Circle:   if(penColorCBox->currentIndex()   != 0 &&
                                 penStyleCBox->currentIndex()   != 0 &&
                                 penWidthBox  ->value()         != 0 &&
                                 brushColorCBox->currentIndex() != 0 &&
                                 brushStyleCBox->currentIndex() != 0 &&
                                 shapeName->text().isEmpty()    == false)
                                    {completed = true;}
                            break;

    case ShapeType::Text:   if(textColorCBox->currentIndex()   != 0     &&
                               textPointBox ->value()          != 0     &&
                               textString   ->text().isEmpty() == false &&
                               shapeName    ->text().isEmpty() == false)
                                    {completed = true;}
                            break;
    }

    //If they haven't completed, do not let the user move on
    if(completed == false)
        QMessageBox::warning(this, "Warning", "invalid fields");
    else
    {
        shapeCBox           ->setEnabled(false);
        shapeName           ->setEnabled(false);
        penColorCBox        ->setEnabled(false);
        penStyleCBox        ->setEnabled(false);
        penCapCBox          ->setEnabled(false);
        penJoinCBox         ->setEnabled(false);
        brushColorCBox      ->setEnabled(false);
        brushStyleCBox      ->setEnabled(false);
        textColorCBox       ->setEnabled(false);
        textAllignmentCBox  ->setEnabled(false);
        textFontFamilyCBox  ->setEnabled(false);
        textFontStyleCBox   ->setEnabled(false);
        textFontWeightCBox  ->setEnabled(false);
        penWidthBox         ->setEnabled(false);
        textPointBox        ->setEnabled(false);
        textString          ->setEnabled(false);
        shapeInfo           ->setEnabled(true);
        page2               ->setEnabled(false);

        //Initiailize the second page
        SetSecondPgValues();
    }
}

//Enable and Diable the polyspinboxs
void CreateShape::EnablePolySides(const int& ARGUMENT)
{
    int index;  //The index in the array

    //Diable all the spinboxes
    for(index = 0; index < dimensionsSpinBox->size(); index++)
        dimensionsSpinBox->operator[](index)->setEnabled(false);

    //Enable all the necessary spinboxes
    if(ARGUMENT > 1)
    {
        for(index = 0; index < (ARGUMENT*2);index++)
            dimensionsSpinBox->operator[](index)->setEnabled(true);
    }
}

//Check to see if the user is ready to go to complete the shape
void CreateShape::CompleteShape()
{
    bool completed;     //The condition if the user has finished

    int index;          //The index in the array

    ShapeType shapeType;//The enumerated type to match the shape

    index      = 0;
    completed = true;
    shapeType = static_cast<ShapeType>(shapeCBox->currentIndex());

    //Check if all the necessary information has been filled out
    if(shapeType == ShapeType::Polyline || shapeType == ShapeType::Polygon)
    {
        if(polySidesBox->value() == 0){completed = false;}

        while(index < polySidesBox->value() && completed)
        {
            if(dimensionsSpinBox->operator[](index)->value() != -1){index++;}
            else{completed = false;}
        }
    }
    else
    {
        while(index < dimensionsSpinBox->size() && completed)
        {
            if(dimensionsSpinBox->operator[](index)->value() != -1){index++;}
            else{completed = false;}
        }
    }

    if(completed == true)
    {
        QMessageBox::information(this, "Shape Created!", "The Shape has "
                                                        "been fully generated");

        //Send the generated shape as a Signal
        emit shapeGenerated(GenerateShape());

        close();
    }
    else{QMessageBox::warning(this, "Warning", "invalid fields");}
}

//Turn string to color
Qt::GlobalColor CreateShape::StrToColor(QString info) const
{
    info = info.toLower();

    Qt::GlobalColor color = Qt::white;

         if(info == "blue")   {color = Qt::blue;}
    else if(info == "red")    {color = Qt::red;}
    else if(info == "cyan")   {color = Qt::cyan;}
    else if(info == "yellow") {color = Qt::yellow;}
    else if(info == "magenta"){color = Qt::magenta;}
    else if(info == "black")  {color = Qt::black;}
    else if(info == "green")  {color = Qt::green;}
    else if(info == "gray")   {color = Qt::gray;}

    return color;
}

//Turn string to pen style
Qt::PenStyle CreateShape::StrToPenStyle(const QString & INFO) const
{
    Qt::PenStyle penStyle = Qt::NoPen;

         if(INFO == "Dash Dot Line")   {penStyle = Qt::DashDotLine;}
    else if(INFO == "Solid Line")     {penStyle = Qt::SolidLine;}
    else if(INFO == "Dash Line")      {penStyle = Qt::DashLine;}
    else if(INFO == "Dot Line")       {penStyle = Qt::DotLine;}
    else if(INFO == "Dash Dot Dot Line"){penStyle = Qt::DashDotDotLine;}

    return penStyle;
}

//Turn string to cap style
Qt::PenCapStyle CreateShape::StrToCapStyle(const QString& INFO) const
{
    Qt::PenCapStyle style = Qt::FlatCap;

         if(INFO == "Square"){style = Qt::SquareCap;}
    else if(INFO == "Round") {style = Qt::RoundCap;}
    else if(INFO == "Flat")  {style = Qt::FlatCap;}

    return style;
}

//Turn string to join style
Qt::PenJoinStyle CreateShape::StrToJoinStyle(const QString& INFO) const
{
    Qt::PenJoinStyle style = Qt::MiterJoin;

         if(INFO == "Miter"){style = Qt::MiterJoin;}
    else if(INFO == "Round"){style = Qt::RoundJoin;}
    else if(INFO == "Bevel"){style = Qt::BevelJoin;}

    return style;
}

//Turn string to brush style
Qt::BrushStyle CreateShape::StrToBrushStyle(const QString& INFO) const
{
    Qt::BrushStyle style = Qt::NoBrush;

        if(INFO == "Solid"){style = Qt::SolidPattern;}
   else if(INFO == "Vertical")  {style = Qt::VerPattern;}
   else if(INFO == "Horizontal")  {style = Qt::HorPattern;}

   return style;
}

//Turn string to font style
QFont::Style CreateShape::StrToFontStyle(const QString& INFO) const
{
    QFont::Style style = QFont::StyleNormal;

         if(INFO == "Normal Style") {style = QFont::StyleNormal;}
    else if(INFO == "Italic Style") {style = QFont::StyleItalic;}
    else if(INFO == "Oblique Style"){style = QFont::StyleOblique;}

    return style;
}

//Turn string to font weight
QFont::Weight CreateShape::StrToFontWeight(const QString& INFO) const
{
    QFont::Weight weight = QFont::Normal;

         if(INFO == "Thin")  {weight = QFont::Thin;}
    else if(INFO == "Light") {weight = QFont::Light;}
    else if(INFO == "Normal"){weight = QFont::Normal;}
    else if(INFO == "Bold")  {weight = QFont::Bold;}

    return weight;
}

//Turn string to allignment
QString CreateShape::StrToAllignment(const QString &INFO) const
{
    QString allignment;

    if(INFO == "Allign Center")     {allignment = "AlignCenter";}
    else if(INFO == "Allign Right") {allignment = "AlignRight";}
    else if(INFO == "Allign Left")  {allignment = "AlignLeft";}
    else if(INFO == "Allign Top")   {allignment = "AlignTop";}
    else if(INFO == "Allign Bottom"){allignment = "AlignBottom";}

    return allignment;
}
