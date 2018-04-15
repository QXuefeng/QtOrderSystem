#include "ProfileWidget.h"
#include "ui_ProfileWidget.h"

ProfileWidget::ProfileWidget(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::ProfileWidget)
{
    ui->setupUi(this);

    loadStyleSheet(":/qss/IndexWidget.css");
}

ProfileWidget::~ProfileWidget()
{
    delete ui;
}

void ProfileWidget::setLocation(const QString& location)
{
    ui->labelLocation->setText(location);
}
