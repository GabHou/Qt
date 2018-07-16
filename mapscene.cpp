#include "mapscene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

MapScene::MapScene()
{
    addItem(&item);
//    item1.setPos(50,50);
//    addItem(&item1);
    item2.setPos(30,30);
    addItem(&item2);
//    item3.setPos(20,20);
//    addItem(&item3);
    //clearFocus();
}

void MapScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QList<QGraphicsItem *> list;
    list = selectedItems();
    qDebug()<<list.size();
//    itemAt(mouseEvent->screenPos());
//    QPainterPath path;
//    setSelectionArea(path);
//    list = selectedItems();
//    qDebug()<<list.size();
    return QGraphicsScene::mousePressEvent(mouseEvent);
}
