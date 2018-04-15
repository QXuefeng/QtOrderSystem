#ifndef INDEXWIDGET_H
#define INDEXWIDGET_H

#include "BaseWidget.h"
#include <QWidget>

namespace Ui {
class IndexWidget;
}

// 首页窗口界面类
class IndexWidget : public BaseWidget
{
    Q_OBJECT

public:
    explicit IndexWidget(QWidget *parent = 0);
    ~IndexWidget();

    /* 设置当前位置 */
    void setLocation(const QString& location);

    /* 添加商家项 */
    void addItems();

private:
    Ui::IndexWidget *ui;

    void init();

signals:

};

#endif // INDEXWIDGET_H
