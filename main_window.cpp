#include "main_window.h"
#include "qboxlayout.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->myCustomGraphicsView=new CustomGraphicsView(this);
    myCustomGraphicsView->setFixedSize(800, 800);
    myCustomGraphicsView->setMaximumSize(800,800);
    myCustomGraphicsView->setCursor(Qt::CrossCursor);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(this->myCustomGraphicsView);
    setLayout(layout);
}



MainWindow::~MainWindow()
{
    delete ui;
    delete myCustomGraphicsView;
}

