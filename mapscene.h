#ifndef MAPSCENE_H
#define MAPSCENE_H

#include <QGraphicsScene>
#include "insigitem.h"

class MapScene : public QGraphicsScene
{
public:
    MapScene();

private:
    InsigItem item;
    InsigItem item1;
    InsigItem item2;
    InsigItem item3;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
};

#endif // MAPSCENE_H
