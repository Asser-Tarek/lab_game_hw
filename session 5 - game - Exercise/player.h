#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPLayer>
#include <QAudioOutput>
class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void createEnemy();
private:
    QMediaPlayer * blast_sound;
    QAudioOutput * blast_audio;
};

#endif // PLAYER_H
