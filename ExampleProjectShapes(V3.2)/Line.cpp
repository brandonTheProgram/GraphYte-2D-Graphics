#include "Line.h"

Line::~Line()
{

}

void Line::SetCordinates(const QPoint &START, const QPoint &END)
{
    startingPoint = START;
    endingPoint   = END;
}

void Line::Draw(QPaintDevice* device)
{
    QPainter painter(device);
    QPen newPen = GetPen();
    QBrush newBrush = GetBrush();

    painter.setPen(newPen);
    painter.setBrush(newBrush);

    painter.save();

    painter.drawLine(startingPoint, endingPoint);

    painter.restore();
}

void Line::Move(const int& X, const int& Y)
{
    GetPainter().translate(X, Y);
    GetPainter().drawLine(startingPoint, endingPoint);
}
