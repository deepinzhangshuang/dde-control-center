#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>

class MyItem : public QGraphicsItem
{
public:
    MyItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget);
    void setColor(const QColor &color) { brushColor = color; }
   // void paint1(int a);
protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

private:
    QColor brushColor;

};

#endif // MYITEM_H
