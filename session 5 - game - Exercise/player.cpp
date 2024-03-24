#include "player.h"
#include <QPainter>
#include <QApplication>

Player::Player(QWidget *parent) : QWidget(parent)
{
    playerPixmap.load("/Users/asser/Desktop/CSCE 1101/plane.jpeg"); // Adjust the path according to your project structure

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::movePlayer);
}

void Player::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.drawPixmap(400,600, width(), height(), playerPixmap);

    // Draw bullets
    painter.setBrush(Qt::red);
    for (const QPoint &bullet : bullets)
        painter.drawEllipse(bullet, 5, 5);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        dx = -1;
        timer->start(20);
    }
    else if (event->key() == Qt::Key_Right) {
        dx = 1;
        timer->start(20);
    }
    else {
        QWidget::keyPressEvent(event);
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_Right) {
        dx = 0;
    }
    else {
        QWidget::keyPressEvent(event);
    }

    if (dx == 0 && dy == 0)
        timer->stop();
}

void Player::movePlayer()
{
    int newX = x() + dx * 5; // Adjust movement speed as needed
    int newY = y() + dy * 5;

    if (newX >= 0 && newX + width() <= parentWidget()->width() &&
        newY >= 0 && newY + height() <= parentWidget()->height())
    {
        move(newX, newY);
    }
}
