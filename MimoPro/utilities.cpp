#include <QObject>
#include <QApplication>
#include <QDateTime>
#include <QDir>
#include <QStandardPaths>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QHostInfo>
#include <QDebug>

#include "utilities.h"

void Utilities::notifyMobile()
{
    QString endpoint = "https://maker.ifttt.com/trigger/Motion-Detected-by-Mimopro/with/key/jhyeF2YedlRr3K60jmGm3o5RiDP4CuwhKCrmaHSHQ90";
    // CHANGE endpoint TO YOURS HERE: https://maker.ifttt.com/trigger/Motion-Detected-by-Mimopro /with/key/jhyeF2YedlRr3K60jmGm3o5RiDP4CuwhKCrmaHSHQ90
    // https://maker.ifttt.com/trigger/Motion-Detected-by-Gazer/with/key/-YOUR_KEY
    // QString endpoint = QUrl("https://maker.ifttt.com/YOUR_END PIOIN");
    QNetworkRequest request = QNetworkRequest(QUrl(endpoint));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject json;
    json.insert("value1", QString("%1").arg(0));
    json.insert("value2", QHostInfo::localHostName());
    QNetworkAccessManager nam;
    QNetworkReply *rep = nam.post(request, QJsonDocument(json).toJson());
    while(!rep->isFinished()) {
        QApplication::processEvents();
    }
    // QString strReply = (QString)rep->readAll();
    // qDebug()<<"Test: "<<strReply;
    rep->deleteLater();
}
