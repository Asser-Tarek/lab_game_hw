#include "enemy.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>
#include "game.h"
#include <QMediaPLayer>
#include <QAudioOutput>

extern Game * game;
Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {
    // *******  Setting the size of the enemy ********
    setPixmap(QPixmap(":/images/enemy_qt.png"));

    // *******  Setting the postion of the enemy within the view dimensions ********
    int random_number = rand() % 700;
    setPos(random_number,0);


    // *******  Moving the enemies downwards automatically every 50 milli second ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

    //********* Adding Damage Sound Effect ***************
    ouch_output = new QAudioOutput();
    ouch_output->setVolume(50);
    ouch_sound = new QMediaPlayer();
    ouch_sound->setAudioOutput(ouch_output);
    ouch_sound->setSource(QUrl("qrc:/HURT_SOUND/ouch"));

}
// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Enemy:: move()
{
    setPos(x(),y()+5);
    if(y()+200 > 800)
    {
        //decrease the health and output sound for damage
        game->health->decrease();
        ouch_sound -> play();

        scene()->removeItem(this);
        delete this;
    }
}
