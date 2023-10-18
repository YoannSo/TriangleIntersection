#include "custom_qgraphics_view.h"

CustomGraphicsView::CustomGraphicsView(QWidget *parent) : QGraphicsView(parent) { //creation d'un graphicsview custom pour handle le onmousePress
    _scene = std::make_shared<QGraphicsScene>(this);
    QRectF viewRect = QRectF(0, 0, 500, 500);
    _scene->setSceneRect(viewRect);
    setScene(_scene.get());

    //creation de nos deux triangles, un fix et une qui va changer

    _firstTriangle=std::make_unique<Triangle>(_scene);
    _secondTriangle=std::make_unique<Triangle>(_scene);


}


void CustomGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPointF clickPos = mapToScene(event->pos());

        if(_nbCLicks<3){// 3 premier clics = premier triangle

            _firstTriangle->addPoint(clickPos);

            ++_nbCLicks;

            if(_nbCLicks==3)
                _firstTriangle->display();
        }
        else{

            if(_resultArea!=nullptr){ //quand on va recliquer alors qu'on a notre zone d'intersection, il faut reinit les membres et remettre le compteur a 3
                _resultArea->removeDisplay();
                _resultArea=nullptr;

                _secondTriangle=std::make_unique<Triangle>(_scene);

                _nbCLicks=3;
            }

            _secondTriangle->addPoint(clickPos);

            _nbCLicks++;

            if(_nbCLicks==6){

                _secondTriangle->display();

                _resultArea=std::make_unique<Polygone>(_secondTriangle->intersect(_firstTriangle));
                _resultArea->display();

            }


        }

    }
    QGraphicsView::mousePressEvent(event);
}
