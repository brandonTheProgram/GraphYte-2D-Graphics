#include "Polyline.h"

Polyline::~Polyline()
{
}

void Polyline::AddPoint(const QPoint& NEW_POINT)
{
    linePoints.push_back(NEW_POINT);
}

void Polyline::Draw()
{
    QPointF lineFloatPoints[linePoints.size()];

    for (int index = 0; index < linePoints.size(); index++)
        lineFloatPoints[index] = linePoints[index];

    GetPainter().save();

    GetPainter().drawPolyline(lineFloatPoints, linePoints.size());

    GetPainter().restore();
}

void Polyline::Move(const int& X, const int& Y)
{
    QPointF lineFloatPoints[linePoints.size()];

    for (int index = 0; index < linePoints.size(); index++)
        lineFloatPoints[index] = linePoints[index];

    GetPainter().translate(X, Y);
    GetPainter().drawPolyline(lineFloatPoints, linePoints.size());
}