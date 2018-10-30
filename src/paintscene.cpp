#include "paintscene.h"

paintScene::paintScene(QObject *parent) : QGraphicsScene(parent) {

}

paintScene::~paintScene() {

}

void paintScene::setDrawDot(bool temp) {
    DrawDot = temp;
}

void paintScene::setDrawLine(bool temp) {
    DrawLine = temp;
}

void paintScene::setDrawRound(bool temp) {
    DrawRound = temp;
}

void paintScene::setDrawSqure(bool temp) {
    DrawSqure = temp;
}

bool paintScene::getDrawDot() {
    return DrawDot;
}

bool paintScene::getDrawLine() {
    return DrawLine;
}

bool paintScene::getDrawRound() {
    return DrawLine;
}

bool paintScene::getDrawSqure() {
    return DrawLine;
}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent * event){
    previousPoint = event->scenePos();
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(DrawDot) {
        addLine(previousPoint.x(),
                    previousPoint.y(),
                    event->scenePos().x(),
                    event->scenePos().y(),
                    QPen(Qt::red,5,Qt::SolidLine,Qt::RoundCap));
        previousPoint = event->scenePos();
    }
}

void paintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(DrawLine) {
        addLine(previousPoint.x(),
                previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(Qt::red,5,Qt::SolidLine,Qt::RoundCap));
    }
    if(DrawSqure) {
        addRect(previousPoint.x(),
                previousPoint.y(),
                event->scenePos().x()-previousPoint.x(),
                event->scenePos().y()-previousPoint.y(),
                QPen(Qt::red,5,Qt::SolidLine,Qt::RoundCap));
    }
}
