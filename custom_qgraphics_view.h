#ifndef CUSTOM_QGRAPHICS_VIEW_H
#define CUSTOM_QGRAPHICS_VIEW_H

#include "triangle.h"
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <iostream>
#include <ostream>

class CustomGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    CustomGraphicsView(QWidget *parent = nullptr);
    ~CustomGraphicsView()=default;
protected:
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void mouseClicked(const QPointF &pos);

private:
    std::shared_ptr<QGraphicsScene> _scene{nullptr};

    uint _nbCLicks{0};

    std::unique_ptr<Triangle> _firstTriangle{nullptr};

    std::unique_ptr<Triangle> _secondTriangle{nullptr};

    std::unique_ptr<Polygone> _resultArea{nullptr};

};

#endif // CUSTOM_QGRAPHICS_VIEW_H
