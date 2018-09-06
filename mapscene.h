#ifndef MAPSCENE_H
#define MAPSCENE_H

#include <QGraphicsScene>
#include "insigitem.h"
#include "selectitem.h"

class MapScene : public QGraphicsScene
{
public:
    MapScene();

private:
    InsigItem item;
    InsigItem item1;
    InsigItem item2;
    InsigItem item3;

    SelectItem selectItem;
    QRectF selectArea;
    QPainterPath selectPath;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
};

#endif // MAPSCENE_H
