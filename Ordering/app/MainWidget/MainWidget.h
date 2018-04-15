#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "BaseWidget.h"

class IndexWidget;

namespace Ui {
class MainWidget;
}

// 主界面窗口类
class MainWidget : public BaseWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);

    void init();

    ~MainWidget();

private:
    Ui::MainWidget *ui;

    IndexWidget* indexWidget; // 首页



private slots:
    /* 改变本窗口大小 */
    void doResize(QSize);

};

#endif // MAINWIDGET_H
