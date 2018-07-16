#ifndef INSIGITEM_H
#define INSIGITEM_H

#include <QGraphicsItem>

class InsigItem : public QGraphicsItem
{
public:
    InsigItem();
    ~InsigItem();

public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // INSIGITEM_H
