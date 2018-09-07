#include "insigitem.h"
#include <QPen>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QDebug>

InsigItem::InsigItem()
    :selectedType(0)
{

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
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QPen pen;
    if(selectedType == 0){
        pen.setColor(Qt::black);
    }else if(selectedType == 1){
        pen.setColor(Qt::red);
    }else if(selectedType == 2){
        pen.setColor(Qt::green);
    }else{
        ;
    }

    painter->setPen(pen);
    painter->drawEllipse(-10,-10,20,20);
}

void InsigItem::onSetSelectType(int type)
{
    ChangeSelectType(type);
}

void InsigItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->modifiers() == Qt::CTRL){
        ChangeSelectType(1);
    }else if(event->modifiers() == Qt::SHIFT){
        ChangeSelectType(2);
    }else{
        ;
    }
    update();
    QGraphicsItem::mousePressEvent(event);
}

void InsigItem::ChangeSelectType(int type)
{
    if(selectedType == 0){
        selectedType = type;
    }else if(selectedType == type){
        selectedType = 0;
    }else{
        ;
    }
}
