#ifndef GRAPHICSMOVIEITEM_H
#define GRAPHICSMOVIEITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QMovie>

class GraphicsMovieItem:public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    GraphicsMovieItem(QGraphicsItem* parent=0);
    void setMovie(QMovie* movie);

private:
    QMovie* m_movie;

private slots:
    void frameChanged();
};

#endif // GRAPHICSMOVIEITEM_H
