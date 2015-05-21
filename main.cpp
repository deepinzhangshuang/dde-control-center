#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
//#include <QDebug>
#include <QGraphicsView>
#include <QMouseEvent>
#include <myitem.h>

int main(int argc,char* argv[ ])
{
    QApplication app(argc,argv);

    //新建场景
    QGraphicsScene scene;
    //创建矩形图形项
    QGraphicsRectItem *item = new QGraphicsRectItem(-200,-305, 297, 150);
    item->setBrush(QColor(Qt::black));
    QGraphicsRectItem * item1= new QGraphicsRectItem(-200,240,297,150);
    item1->setBrush(QColor(Qt::black));
   // QGraphicsPixmapItem *item2 =new QGraphicsPixmapItem(QPixmap("../myScene/shutdown_normal.png"));
    //item2->setPos(-70,210);
    //MyItem *item = new MyItem
    MyItem * item2 = new MyItem;


    //item2->mousePressEvent();
    //将图形项添加到场景中

    scene.addItem(item1);
    scene.addItem(item);
    scene.addItem(item2);
    //实现点击后变亮效果
    //QPixmap pixmap("../myScene/shutdown_hover.png");
     //pixmap = pixmap.scaledToWidth(32);
    //QGraphicsPixmapItem *item3 = scene.addPixmap(pixmap);
    //scene.addItem(item3);

    //scene.addItem(item3);
    //输出(50, 50)点处的图形项
    //qDebug() << scene.itemAt(50, 50);


    //为场景创建视图
    QGraphicsView view(&scene);
    //设置场景的前景色
    view.setForegroundBrush(QColor(255, 255, 255, 100));
    //设置场景的背景图片
   // view.setBackgroundBrush(QPixmap("../myScene/background.png"));
    view.resize(300, 700);
    view.setBackgroundBrush(QColor(Qt::white));
    view.show();

    return app.exec();
}

