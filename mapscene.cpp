#include "mapscene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

MapScene::MapScene()
{
    addItem(&item);
    item1.setPos(50,50);
    addItem(&item1);
    item2.setPos(30,30);
    addItem(&item2);
    item3.setPos(20,20);
    addItem(&item3);

    addItem(&selectItem);

    setSceneRect(-1000,-1000,2000,2000);
}

void MapScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    selectArea.setTopLeft(mouseEvent->scenePos());
    selectArea.setBottomRight(mouseEvent->scenePos());
    selectItem.setPos(mouseEvent->pos());
    return QGraphicsScene::mousePressEvent(mouseEvent);
}

void MapScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->modifiers() == Qt::CTRL){
       selectItem.SetSelectedType(1);
    }else if(mouseEvent->modifiers() == Qt::SHIFT){
        selectItem.SetSelectedType(2);
    }else{
        selectItem.SetSelectedType(0);
        return QGraphicsScene::mouseMoveEvent(mouseEvent);
    }
    selectArea.setBottomRight(mouseEvent->scenePos());
    selectPath -= selectPath;
    selectPath.addRect(selectArea);
    selectItem.SetPath(selectPath);
    return QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void MapScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    int selectedType = 0;
    if(mouseEvent->modifiers() == Qt::CTRL){
       selectedType = 1;
    }else if(mouseEvent->modifiers() == Qt::SHIFT){
        selectedType = 2;
    }else{
        return QGraphicsScene::mouseReleaseEvent(mouseEvent);
    }
    QList<QGraphicsItem*> list = items(selectArea);
    foreach (item, list) {
        InsigItem* insigItem = (InsigItem*)item;
        insigItem->onSetSelectType(selectedType);
    }
    selectPath -= selectPath;
    selectItem.SetPath(selectPath);
    return QGraphicsScene::mouseReleaseEvent(mouseEvent);
}
