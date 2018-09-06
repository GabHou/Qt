#ifndef SELECTITEM_H
#define SELECTITEM_H

#include <QGraphicsItem>
#include <QPainterPath>

class SelectItem : public QGraphicsItem
{
public:
    SelectItem();

    void SetPath(QPainterPath path);
    void SetSelectedType(int type);

public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPainterPath drawPath;
    int selectedType;
};

#endif // SELECTITEM_H
