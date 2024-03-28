#include "health.h"
#include <QFont>

Health::Health(){
    // **** initialize the health to 3 ****
    health = 3;

    // **** draw the text *****
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}
// ***** set health to current health after decrement ****
void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
}

int Health::getHealth(){
    return health;
}
