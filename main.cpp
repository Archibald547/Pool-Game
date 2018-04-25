#include "dialog.h"
#include "concreteballbuilder.h"
#include "concretetablebuilder.h"
#include <QApplication>
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>


int main(int argc, char *argv[])
{
    QFile file("/Users/ArchibaldWeng/Google Drive/USYD/INFO3220/Pool/pool.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonObject object = document.object();
    //to get the table value and object
    QJsonValue tableValue = object.value("table");
    qWarning() << tableValue;
    QJsonObject tableObject = tableValue.toObject();
    QJsonValue colourValue = tableObject["colour"];
    qWarning() << colourValue;
    QJsonValue sizeValue = tableObject["size"];
    qWarning() << sizeValue;
    QJsonValue xValue = sizeValue.toObject()["x"].toInt();
    qWarning() << xValue;
    QJsonValue yValue = sizeValue.toObject()["y"].toInt();
    qWarning() << yValue;
    QJsonValue frictionValue = tableObject["friction"];
    QJsonValue ballsValue = object.value("balls");
    QJsonArray ballsArray = ballsValue.toArray();

    QApplication a(argc, argv);

    Table *table;
    Stage1Factory *stage1factory = new Stage1Factory();
    ConcreteTableBuilder* tablebuilder= new ConcreteTableBuilder(stage1factory);
    tablebuilder->buildTable();
    tablebuilder->buildWidth(xValue.toInt());
    tablebuilder->buildHeight(yValue.toInt());
    tablebuilder->buildBackgroundColor(colourValue.toString());
    tablebuilder->buildFriction(frictionValue.toDouble());
    table = tablebuilder->getTable();

    std::vector<Ball*> balls;

    Dialog w;

    foreach (const QJsonValue & b, ballsArray){
        Ball* ball;
        concreteBallBuilder* ballbuilder = new concreteBallBuilder(stage1factory);
        ballbuilder->buildBall();
        ballbuilder->buildColor(b.toObject().value("colour").toString());
        int b_pos_x = b.toObject().value("position").toObject().value("x").toInt();
        int b_pos_y = b.toObject().value("position").toObject().value("y").toInt();
        ballbuilder->buildCoordinate(Coordinate(b_pos_x,b_pos_y,table->getWidth(),table->getHeight()));
        ballbuilder->buildMass(b.toObject().value("mass").toDouble());
        ballbuilder->buildRadius(b.toObject().value("radius").toInt());
        ballbuilder->buildXVelocity(b.toObject().value("velocity").toObject().value("x").toDouble());
        ballbuilder->buildYVelocity(b.toObject().value("velocity").toObject().value("y").toDouble());
        ball=ballbuilder->getBall();
        balls.push_back(ball);
    }



    w.resize(table->getWidth(),table->getHeight());
    w.setStyleSheet("background-color: "+table->getColor());
    w.setFriction(table->getFriction());
    w.setBalls(balls);
    w.show();

//    Dialog w;
//    w.resize(xValue.toInt(),yValue.toInt());
//    w.setStyleSheet("background-color: "+colourValue.toString());
//    QJsonValue ballsValue = object.value("balls");
//    QJsonArray ballsArray = ballsValue.toArray();
//    foreach (const QJsonValue & b, ballsArray){
//        QString b_colour = b.toObject().value("colour").toString();
//        int b_pos_x = b.toObject().value("position").toObject().value("x").toInt();
//        int b_pos_y = b.toObject().value("position").toObject().value("y").toInt();
//        double b_velo_x = b.toObject().value("velocity").toObject().value("x").toDouble();
//        double b_velo_y = b.toObject().value("velocity").toObject().value("y").toDouble();
//        double b_mass = b.toObject().value("mass").toDouble();
//        int b_r = b.toObject().value("radius").toInt();
//        w.addBall(Ball(b_colour,Coordinate(b_pos_x, b_pos_y, xValue.toInt(),yValue.toInt()), b_r, b_mass, b_velo_x, b_velo_y));
//    }
//    w.show();

    return a.exec();
}
