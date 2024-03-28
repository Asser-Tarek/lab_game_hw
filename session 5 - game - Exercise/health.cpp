#include "health.h"
#include "QtWidgets/qgraphicsscene.h"
#include <QFont>
#include <QMediaPLayer>
#include <QAudioOutput>

Health::Health(){
    // **** initialize the health to 3 ****
    health = 3;

    // **** draw the text *****
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

    // ****** Game Over Sound effect *********
    //********* Adding Damage Sound Effect ***************
    womp_womp_output = new QAudioOutput();
    womp_womp_output->setVolume(50);
    womp_womp_sound = new QMediaPlayer();
    womp_womp_sound->setAudioOutput(womp_womp_output);
    womp_womp_sound->setSource(QUrl("qrc:/LoseSound/videogame-death-sound-43894.mp3"));
}
// ***** set health to current health after decrement ****
void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
    if (health == 0)
    {
        gameover();
    }
}



int Health::getHealth()
{
    return health;
}


void Health::gameover()
{
    for (size_t i = 0, n = scene()->items().size(); i < n; i++){
        scene()->items()[i]->setEnabled(false);
    }
    QGraphicsTextItem *gameover = new QGraphicsTextItem;
    gameover->setFont (QFont ("times", 40)) ;
    gameover->setDefaultTextColor(Qt::red);
    gameover->setPlainText("Game Over");
    gameover->setPos (300, 250) ;

    scene()->addItem (gameover);
    womp_womp_sound ->play();

}
