#include "Rectangle.h"

Rectangle::~Rectangle()
{
}

void Rectangle::SetDimensions(const int &LENGTH, const int &WIDTH)
{
    length = LENGTH;
    width  = WIDTH;
    square = false;
}

void Rectangle::SetDimensions(const int &LENGTH)
{
    length = LENGTH;
    width  = 0;
    square = true;
    SetShape(ShapeType::Square);
}

void Rectangle::Draw(QPaintDevice* device)
{
    QPainter painter(device);
    QPen newPen = GetPen();
    QBrush newBrush = GetBrush();

    painter.setPen(newPen);
    painter.setBrush(newBrush);

    painter.save();

    if(square != true)
        painter.drawRect(cordinates.x(), cordinates.y(), width, length);
    else
        painter.drawRect(cordinates.x(), cordinates.y(), length, length);

    painter.restore();
}

void Rectangle::Move(const int &X, const int &Y)
{
    SetCordiantes(QPoint(X, Y));
}

float Rectangle::Area() const
{
    if(square != true)
        return (length * width);
    else
        return (length * length);
}

float Rectangle::Perimeter() const
{
    if(square != true)
        return ((2 * length) + (2 * width));
    else
        return (4 * length);
}

void Rectangle::Print(ostream& os)
{

    os << "ShapeId: " << GetId() << endl;
//    if() //check to see if the shape is a rectangle or square
//    {
//        os << "ShapeType: Rectangle";
//        os << "ShapeDimensions: ";
//    }
//    else
//    {
//        os << "ShapeType: Square";
//        os << "ShapeDimensions: ";
//    }

    os << "PenColor: " << ColortoStr(GetPen()) << endl;
    os << "PenWidth: " << GetPen().width() << endl;
    os << "PenStyle: " << PenStyleToStr(GetPen()) << endl;
    os << "PenCapStyle: " << CapStyleToStr(GetPen()) << endl;
    os << "PenJoinStyle: " << JoinStyleToStr(GetPen()) << endl;
    os << "BrushColor: " << BrushColorToStr(GetBrush()) << endl;
    os << "BrushStyle: " << BrushStyleToStr(GetBrush()) << endl;
}
