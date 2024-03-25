#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include <player.h>
#include <typeinfo>
#include <QtMultimedia>
#include <QMediaPLayer>
#include <QAudioOutput>
Bullet::Bullet():QObject(), QGraphicsPixmapItem() {

    setPixmap(QPixmap(":/images/bullet_qt.png"));
    //****** Creating Chicken Death Sound Effect *********
    chicken_death_output = new QAudioOutput();
    chicken_death_output->setVolume(50);
    chicken_death_sound = new QMediaPlayer();
    chicken_death_sound->setAudioOutput(chicken_death_output);
    chicken_death_sound->setSource(QUrl("qrc:/SOUNDS/chicken-single-alarm-call-6056.mp3"));
    // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}

// Move function is used to 1-  move the bullet upwards
// 2- Handle the collision of the bullets with enemies
void Bullet::move()
{
    // *******  Getting the colliding items with the Bullet ********
    // ******* Adding Sound effect for destroyed chicken *******

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n;++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            chicken_death_sound -> play();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;
            return;
        }


    }



    // *******  Moving the bullets upward ********

    setPos(x(),y()-10);

    if(pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;

    }
}
