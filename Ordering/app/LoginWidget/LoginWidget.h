#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include "BaseWidget.h"

namespace Ui {
class LoginWidget;
}

class QPushButton;

// 登陆界面类
class LoginWidget : public BaseWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();

private:
    /**
     * @function : init
     * @brief    : 对界面进行部分初始化工作
     * @param    : void
     * @return   : void
     * @date     : 2018/03/20
     */
    void init();

private:
    Ui::LoginWidget *ui;



private slots:
    /**
     * @function : doLoginAck
     * @brief    : 由登陆按钮触发的槽
     * @param    : void
     * @return   : void
     * @date     : 2018/03/20
     */
    void doLoginAck();

signals:
    /**
     * @function : doLoginAck
     * @brief    : 通过本信号, 把用户名和密码交由登陆控制器处理
     * @param    : loginName -> const QString -> 用户名,
     *             loginPsd  -> const QString -> 用户密码
     * @return   : void
     * @date     : 2018/03/20
     */
    void loginAction(const QString loginName, const QString loginPsd);
};

#endif // LOGINWIDGET_H
