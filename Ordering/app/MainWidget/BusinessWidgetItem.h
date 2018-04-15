#ifndef BUSINESSWIDGETITEM_H
#define BUSINESSWIDGETITEM_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include "ui_BusinessWidgetItem.h"

namespace Ui {
class BusinessWidgetItem;
}

// 商家项类
class  BusinessWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit BusinessWidgetItem(QWidget *parent = 0) :
        QWidget(parent),
        ui(new Ui::BusinessWidgetItem)
    {
        ui->setupUi(this);

        // 不从父窗口继承背景色
        this->setAutoFillBackground(true);

        this->setFixedSize(300, 140);
        this->setPalette(QPalette(QColor(Qt::white)));
    }

    // 设置商家图片
    void setBusinessPixmap(const QString& pixName) {
        // 加载图片
        ui->labelBusinessPic->setPixmap(pixName);
    }

    // 设置到达信息
    void setArrivalTime(const QString& at_time) {
        ui->labelArrivalTime->setText(at_time);
    }

    // 设置商家名称
    void setBusinessName(const QString& businessName) {
        ui->labelBusinessName->setText(businessName);
    }

    // 设置商家级别
    void setBusinessLevel(double businessLevel) {
        for(int i = 0; i < 5; ++ i) {
            QLabel* labelStar = new QLabel(this);
            labelStar->resize(20, 20);
            labelStar->move(105+20*i, 53);

            // 绘制星级
            if(businessLevel > 1) labelStar->setPixmap(QPixmap(":/img/fullstar.png"));
            else if(businessLevel > 0.005) labelStar->setPixmap(QPixmap(":/img/halfstar.png"));
            else labelStar->setPixmap(QPixmap(":/img/emptystar.png"));

            -- businessLevel;
        }
    }

    // 设置商家配送费
    void setBusinessCost(quint32 cost) {
        ui->labelCost->setText("配送费¥" + QString().number(cost));
    }

    // 设置商家id
    void setBusinessId(quint32 businessId) {
        this->businessId = businessId;
    }

    ~BusinessWidgetItem() { delete ui; }

protected:
    // 进入事件
    void enterEvent(QEvent* evt) {
        QWidget::enterEvent(evt);

        // 商家名称设为蓝色
        QPalette txtPalette;
        txtPalette.setColor(QPalette::WindowText, QColor(0, 137, 220));
        ui->labelBusinessName->setPalette(txtPalette);

        setPalette(QPalette(QColor(245, 245, 245)));
        // 进入时改成手势鼠标
        setCursor(Qt::PointingHandCursor);
    }

    // 离开事件
    void leaveEvent(QEvent* evt) {
        QWidget::leaveEvent(evt);

        // 商家名称设为黑色
        QPalette txtPalette;
        txtPalette.setColor(QPalette::WindowText, Qt::black);
        ui->labelBusinessName->setPalette(txtPalette);

        setPalette(QPalette(QColor(Qt::white)));
    }

    // 鼠标单击事件
    void mousePressEvent(QMouseEvent* evt) {
        QWidget::mousePressEvent(evt);

        // 左键单击发送进入商家信号
        if(evt->button() & Qt::LeftButton)
            emit enterBusiness(businessId);
    }

signals:
    void enterBusiness(quint32);

private:
    Ui::BusinessWidgetItem *ui;

    qint32 businessId;
};

#endif // BUSINESSWIDGETITEM_H
