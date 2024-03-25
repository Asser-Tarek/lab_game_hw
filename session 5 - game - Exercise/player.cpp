#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include <QMediaPLayer>
#include <QAudioOutput>
//********* adding blast sound effect after key press event ********
Player::Player() {
    blast_audio = new QAudioOutput();
    blast_audio->setVolume(50);
    blast_sound = new QMediaPlayer();
    blast_sound->setAudioOutput(blast_audio);
    blast_sound->setSource(QUrl("qrc:/SOUNDS/BLAST.mpeg"));
};

void Player::keyPressEvent(QKeyEvent *event)
{
    // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
            setPos(x()-15,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent the player from getting out of the screen
            setPos(x()+15,y());
    }
    else if(event->key()== Qt::Key_Space)
    {      
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+45,y()-20);
        scene()->addItem(bullet);
        blast_sound->play();
    }


}
// CreateEnemy function used to create the eneimes
void Player::createEnemy()
{ Enemy* enemy = new Enemy();
    scene()->addItem(enemy);

}

