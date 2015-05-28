/****************************************************************************
**
**  Copyright (C) 2011~2015 Deepin, Inc.
**                2011~2015 Zhe Wang
**
**  Author:     Zhe Wang <wzedmund@gmail.com>
**  Maintainer: 
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QMouseEvent>
#include "DButton.h"
#include "DSwitchbutton.h"
#include "dimage.h"
#include "dbus.h"
#include <qdesktopwidget.h>
#include <QGraphicsTextItem>
#include <QGraphicsColorizeEffect>


const char *pressIcon[50] = {
    "../dde-control-center/resources/icons/account_press.png",
    "../dde-control-center/resources/icons/display_press.png",
    "../dde-control-center/resources/icons/default_applications_press.png",
    "../dde-control-center/resources/icons/personalization_press.png",
    "../dde-control-center/resources/icons/network_press.png",
    "../dde-control-center/resources/icons/sound_press.png",
    "../dde-control-center/resources/icons/date_time_press.png",
    "../dde-control-center/resources/icons/power_press.png",
    "../dde-control-center/resources/icons/mouse_touchpad_press.png",
    "../dde-control-center/resources/icons/keyboard_press.png",
    "../dde-control-center/resources/icons/shortcuts_press.png",
    "../dde-control-center/resources/icons/grub_press.png",
    "../dde-control-center/resources/icons/system_info_press.png"
};

const char *releaseIcon[50] = {
    "../dde-control-center/resources/icons/account_normal.png",
    "../dde-control-center/resources/icons/display_normal.png",
    "../dde-control-center/resources/icons/default_applications_normal.png",
    "../dde-control-center/resources/icons/personalization_normal.png",
    "../dde-control-center/resources/icons/network_normal.png",
    "../dde-control-center/resources/icons/sound_normal.png",
    "../dde-control-center/resources/icons/date_time_normal.png",
    "../dde-control-center/resources/icons/power_normal.png",
    "../dde-control-center/resources/icons/mouse_touchpad_normal.png",
    "../dde-control-center/resources/icons/keyboard_normal.png",
    "../dde-control-center/resources/icons/shortcuts_normal.png",
    "../dde-control-center/resources/icons/grub_normal.png",
    "../dde-control-center/resources/icons/system_info_normal.png"
};

const char *hoverIcon[50] = {
    "../dde-control-center/resources/icons/account_hover.png",
    "../dde-control-center/resources/icons/display_hover.png",
    "../dde-control-center/resources/icons/default_applications_hover.png",
    "../dde-control-center/resources/icons/personalization_hover.png",
    "../dde-control-center/resources/icons/network_hover.png",
    "../dde-control-center/resources/icons/sound_hover.png",
    "../dde-control-center/resources/icons/date_time_hover.png",
    "../dde-control-center/resources/icons/power_hover.png",
    "../dde-control-center/resources/icons/mouse_touchpad_hover.png",
    "../dde-control-center/resources/icons/keyboard_hover.png",
    "../dde-control-center/resources/icons/shortcuts_hover.png",
    "../dde-control-center/resources/icons/grub_hover.png",
    "../dde-control-center/resources/icons/system_info_hover.png"
};

const char * itemName[20] ={
    "账户",
    "显示",
    "默认程序",
    "个性化",
    "网络",
    "声音",
    "日期和时间",
    "电源管理",
    "鼠标",
    "键盘和语言",
    "快捷键",
    "启动菜单",
    "系统信息"



};
int main(int argc,char* argv[ ])
{
    QApplication app(argc,argv);

    QGraphicsScene scene;
    scene.setSceneRect(-150,-300,300,600);

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            DButton *button = new DButton;
            button->setPos(-100 + j*80 + 20 ,-200 + 20 + i*80);
            button->setHoverEnableFlag(true);
            button->setBackgroundEnable(true);
            button->boundImageToPress(pressIcon[j+i*3]);
            button->boundImageToRelease(releaseIcon[j+i*3]);
            button->boundImageToHover(hoverIcon[j+i*3]);
            button->setBounds(-40,-40,80,80);
            scene.addItem(button);
            QGraphicsTextItem*item = new QGraphicsTextItem(itemName[j+i*3]);
            item->setPos(-105 + j*80  ,-200+30 + i*80);
            item->setDefaultTextColor(QColor(250,250,250,100));
            scene.addItem(item);

        }
    }
    //最后一个系统信息
    DButton *button = new DButton;
    button->setPos(-100 + 0*80 + 20 ,-200 + 20 + 4*80);
    button->setHoverEnableFlag(true);
    button->setBackgroundEnable(true);
    button->boundImageToPress(pressIcon[12]);
    button->boundImageToRelease(releaseIcon[12]);
    button->boundImageToHover(hoverIcon[12]);
    button->setBounds(-40,-40,80,80);
    scene.addItem(button);
    QGraphicsTextItem*item = new QGraphicsTextItem(itemName[0+4*3]);
    item->setPos(-105 + 0*80  ,-200+30 + 4*80);
    //item->setDefaultTextColor(QColor(Qt::white));
    item->setDefaultTextColor(QColor(250,250,250,100));
    scene.addItem(item);
   // DSwitchbutton *sb = new DSwitchbutton;
   // sb->setPos(-80,150);
   // scene.addItem(sb);



    //电源键
    dbus *powerButton = new dbus;
    powerButton->setPos(0 ,200);
    powerButton->setBounds(-49,-50,80,80);
    powerButton->setHoverEnableFlag(true);
    powerButton->boundImageToPress("../dde-control-center/resources/images/shutdown_hover.png");
    powerButton->boundImageToRelease("../dde-control-center/resources/images/shutdown_normal.png");
    powerButton->boundImageToHover("../dde-control-center/resources/images/shutdown_hover.png");
    //powerButton->
    DImage * dimage =new DImage("../dde-control-center/resources/images/shutdown_bg.png");
    dimage->setPos(0,215);
   //账户



    scene.addItem(dimage);

    scene.addItem(powerButton);


    QGraphicsView view(&scene);
   // view.setForegroundBrush(QColor(255, 255, 255, 100));
    view.resize(360, 700);
    QDesktopWidget* desktopWidget = QApplication::desktop();
      //获取可用桌面大小
    QRect deskRect = desktopWidget->availableGeometry();
    //view.raise(int(deskRect.width()),int(deskRect.height()));
   view.setBackgroundBrush(QColor(Qt::darkGray));


    view.show();

    return app.exec();
}

