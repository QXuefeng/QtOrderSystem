#include "IndexWidget.h"
#include "ui_IndexWidget.h"
#include "BusinessWidgetItem.h"
#include <QHBoxLayout>
#include <QDebug>

IndexWidget::IndexWidget(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::IndexWidget)
{
    ui->setupUi(this);
    resize(1120, 800);


    setAutoFillBackground(true);

    init();

    loadStyleSheet(":/qss/IndexWidget.css");
}

IndexWidget::~IndexWidget()
{
    delete ui;
}

void IndexWidget::setLocation(const QString& location)
{
    ui->labelLocation->setText(location);
}

void IndexWidget::init()
{
    ui->btnChangeLocation->setCursor(Qt::PointingHandCursor);

    /*搜索按钮 */
    QPushButton* btnSearch = new QPushButton(this);
    btnSearch->setObjectName("btnSearch");
    btnSearch->setCursor(Qt::PointingHandCursor);
    btnSearch->setFixedSize(32, 28);

    QMargins margins = ui->editSearch->textMargins();
    ui->editSearch->setTextMargins(margins.left(), margins.top(), btnSearch->width(), margins.bottom());
    ui->editSearch->setPlaceholderText("搜索商家");

    /* 布局 */
    QHBoxLayout* layoutSearch = new QHBoxLayout;
    layoutSearch->addStretch();
    layoutSearch->addWidget(btnSearch);
    layoutSearch->setSpacing(0);
    layoutSearch->setContentsMargins(0, 0, 0, 0);
    ui->editSearch->setLayout(layoutSearch);
}

void IndexWidget::addItems()
{
    resize(1100, 100 + 5 * 140);

    int i, j, x, y;
    for(i = 0; i < 3; ++ i) {
        x = 100 + i * 300;
        for(j = 0; j < 5; ++ j) {
            y = 100 + j * 140;
            BusinessWidgetItem* item = new BusinessWidgetItem(this);
            item->move(x, y);
            item->setBusinessName("重庆鸡公煲(协和路店)");
            item->setBusinessLevel(2.5);
            item->setArrivalTime("31 分钟");
            item->setBusinessCost(5);
        }
    }
    emit windowSizeChanged(size());
}
