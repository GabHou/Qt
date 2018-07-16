#include "insigitem.h"
#include <QPen>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

InsigItem::InsigItem()
{
    setFlag(QGraphicsItem::ItemIsSelectable);
    //setFlag(QGraphicsItem::ItemIsFocusable);
}

InsigItem::~InsigItem()
{

}

QRectF InsigItem::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void InsigItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setColor(Qt::red);
    painter->setPen(pen);
    painter->drawEllipse(-10,-10,20,20);
    if(isSelected()){
        pen.setColor(Qt::green);
        painter->setPen(pen);
        painter->drawRect(-10,-10,20,20);
    }
}

void InsigItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(isSelected()){
        //setSelected(false);
        event->ignore();
        QGraphicsItem::mousePressEvent(event);
    }else{
        setFocus();
        setSelected(true);
        QGraphicsItem::mousePressEvent(event);
    }

}
