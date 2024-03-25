#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPLayer>
#include <QAudioOutput>

class Bullet: public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT
public:
    Bullet();

public slots:
    void move();
private:
    QMediaPlayer * chicken_death_sound;
    QAudioOutput * chicken_death_output;
};

#endif // BULLET_H
