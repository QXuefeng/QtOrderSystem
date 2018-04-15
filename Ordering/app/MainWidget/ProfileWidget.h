#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include "BaseWidget.h"

namespace Ui {
class ProfileWidget;
}

class ProfileWidget : public BaseWidget
{
    Q_OBJECT

public:
    explicit ProfileWidget(QWidget *parent = 0);
    ~ProfileWidget();

    // 设置当前位置
    void setLocation(const QString& location);

private:
    Ui::ProfileWidget *ui;
};

#endif // PROFILEWIDGET_H
