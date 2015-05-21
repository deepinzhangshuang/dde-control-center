#include "myitem.h"
#include <QPainter>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
//QTdbus 通信机制头文件
#include <QtDBus/qdbusabstractadaptor.h>
#include <QtDBus/qdbusabstractinterface.h>
#include <QtDBus/qdbusconnection.h>
#include <QDBusMessage>

MyItem::MyItem()
{
    brushColor = Qt::red;

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setAcceptHoverEvents(true);

}

QRectF MyItem::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-70 - adjust, 210 - adjust,
                  32 + adjust, 32 + adjust);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{
    if(hasFocus()) {
        painter->setPen(QPen(QColor(255,255,255,200)));
    } else {
        painter->setPen(QPen(QColor(100,100,100,100)));
    }
   // painter->setBrush(brushColor);

    //painter->drawRect(-10, -10, 20, 20);
    painter->drawPixmap(-70,210,49,50,QPixmap("../myScene/shutdown_normal.png"));
    //  painter->(QPixmap("../myScene/shutdown_normal.png");
   //QGraphicsPixmapItem *item3 =new QGraphicsPixmapItem(QPixmap("../myScene/shutdown_normal.png"));
    // item3->setPos(-70,210);

}
//void MyItem::paint1(int a)
//{
 //    QGraphicsPixmapItem *item3 =new QGraphicsPixmapItem(QPixmap("../myScene/shutdown_normal.png"));
   //  item3->setPos(-70,210);
     //scene.addItem(item3);

//}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   // setFocus();
   // setCursor(Qt::ClosedHandCursor);
   // QGraphicsPixmapItem *item3 =new QGraphicsPixmapItem(QPixmap("../myScene/shutdown_normal.png"));
   // item3->setPos(-70,210);
   // QGraphicsScene scene1;

   // scene.addItem(item3);
  // QGraphicsView view(&scene1);
   // painter->drawPixmap(-70,210,49,50,QPixmap("../myScene/shutdown_hover.png"));
   //QPixmap * pixmap =new QPixmap;
   // QPixmap pixmap("123");
    //pixmap = pixmap.scaledToWidth(32);
   // QGraphicsPixmapItem *item = scene.addPixmap("../myScene/shutdown_hover.png");

    //system("poweroff");
    //调用dbus实现进程中通信，poweroffchoose.
    QDBusMessage m = QDBusMessage::createMethodCall("com.deepin.SessionManager",
                                                    "/com/deepin/SessionManager",
                                                    "com.deepin.SessionManager",
                                                    "PowerOffChoose");
    //m<<this->ui->checkInlineEdit->text().toInt();
    QDBusMessage response = QDBusConnection::sessionBus().call(m);

}


void MyItem::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Down)
        moveBy(0, 10);
}


void MyItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(Qt::OpenHandCursor);
    setToolTip("I am item");

}

void MyItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu menu;
    QAction *moveAction = menu.addAction("move back");
    QAction *selectedAction = menu.exec(event->screenPos());
    if(selectedAction == moveAction) {
        setPos(0, 0);
    }
}
