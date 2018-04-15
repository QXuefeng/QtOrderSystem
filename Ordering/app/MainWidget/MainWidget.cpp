#include "MainWidget.h"
#include "ui_MainWidget.h"
#include "IndexWidget.h"
#include "ProfileWidget.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::init()
{
    qDebug() << "xx";
    indexWidget = new IndexWidget;

    // 设置导航栏
    ui->tabWidget->addTab(indexWidget, QIcon(), "首页");
    ui->tabWidget->addTab(new ProfileWidget, QIcon(), "个人中心");

    connect(indexWidget, SIGNAL(windowSizeChanged(QSize)), this, SLOT(doResize(QSize)));

    indexWidget->setLocation("仙霞西路635弄1-48号小区");
    indexWidget->addItems();

    loadStyleSheet(":/qss/MainWidget.css");

}

void MainWidget::doResize(QSize sz)
{
    resize(sz.width(), sz.height()+60);
    ui->tabWidget->resize(sz.width(), sz.height()+60);

    emit windowSizeChanged(size());
}
