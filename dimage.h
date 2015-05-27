#ifndef DIMAGE_H
#define DIMAGE_H
#include "DComponent.h"
class DImage:public DComponent
{
public:
    DImage();

    DImage(QString path);

    QPixmap image;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget);
};


#endif // DIMAGE_H


