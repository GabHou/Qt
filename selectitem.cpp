#include "selectitem.h"
#include <QPainter>
#include <QDebug>

SelectItem::SelectItem():
    selectedType(0)
{

}

void SelectItem::SetPath(QPainterPath path)
{
    drawPath = path;
    update();
}

void SelectItem::SetSelectedType(int type)
{
    selectedType = type;
}

QRectF SelectItem::boundingRect() const
{
    qDebug()<<drawPath.boundingRect();
    return QRectF(-1000.0,-1000.0,2000.0,2000.0);
    return drawPath.boundingRect();
}

void SelectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QPen pen(Qt::DotLine);
    if(selectedType == 0){
        pen.setColor(Qt::darkYellow);
    }else if(selectedType == 1){
        pen.setColor(Qt::red);
    }else if(selectedType == 2){
        pen.setColor(Qt::green);
    }else{
        ;
    }
    painter->setPen(pen);
    painter->drawPath(drawPath);
}
