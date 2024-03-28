#include "Score.h"
#include <QFont>

Score::Score(){
    // *********** initialize the score to 0 **********
    score = 0;

    // ********* display the text **********
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Score::increase(){
    score = score +100;
    setPlainText(QString("Score: ") + QString::number(score)); //Score increments by 100
}

int Score::getScore(){
    return score;
}
