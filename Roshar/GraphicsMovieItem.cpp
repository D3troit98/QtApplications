#include "GraphicsMovieItem.h"

GraphicsMovieItem::GraphicsMovieItem(QGraphicsItem *parent)
    :QGraphicsPixmapItem(parent), m_movie(0) {

}

void GraphicsMovieItem::setMovie(QMovie *movie)
{
    if (m_movie) {
        disconnect(m_movie,SIGNAL(frameChanged(int)),this,SLOT(frameChanged()));
    }
    m_movie = movie;
    if (m_movie) {
        connect(m_movie,SIGNAL(frameChanged(int)),this,SLOT(frameChanged()));
    }
    frameChanged();
}

void GraphicsMovieItem::frameChanged()
{
    if(!m_movie) {return;}
    setPixmap(m_movie->currentPixmap());
}

