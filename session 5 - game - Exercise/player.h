#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QPixmap>
#include <QKeyEvent>
#include <QTimer>

class Player : public QWidget
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private slots:
    void movePlayer();

private:
    QPixmap playerPixmap;
    int dx = 0;
    int dy = 0;
    QTimer *timer;
    QList<QPoint> bullets;
};

#endif // PLAYER_H
