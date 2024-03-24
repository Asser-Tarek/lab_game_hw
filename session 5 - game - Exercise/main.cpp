
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // *******  Create the View ********
    QGraphicsView view;
    view.setFixedSize(800,600);
    view.show();
    view.setHorizontalScrollBarPolicy (Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy (Qt::ScrollBarAlwaysOff);


    // ******* Create the Scene ********

    QGraphicsScene scene;
    scene.setSceneRect(0,0,800,600);


    // *******  Create the Player ********

    Player * player = new Player ();
    player->setPixmap(QPixmap(":/images/jet_qt.png"));
    scene.addItem(player);



    // *******  Setting the foucs to the Player ********

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // *******  Adjust the location of the Player (middle of the screen) ********

    player->setPos(400,500);

    // *******   Assign scene to the view   ***************

    view.setScene(&scene);

    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time->start(2000);


    return a.exec();
}
