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

public slots:
    void onSetSelectType(int type);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    int selectedType;//0:未选中

    void ChangeSelectType(int type);

};

#endif // INSIGITEM_H
