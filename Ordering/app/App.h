#ifndef APP_H
#define APP_H

#include "User.h"
#include "LoginController.h"

#include <QSize>
#include <QObject>


/* 类声明 */
class LoginWidget;
class MainWidget;
class QScrollArea;

// 本项目的应用类
class App : public QObject
{
    Q_OBJECT
public:
    explicit App(QObject *parent = 0);
    ~App();

private:
    void init();    // run()中调用的方法

private:
    // 窗口类
    LoginWidget* loginWidget;
    QScrollArea* scrollArea;
    MainWidget* mainWidget;

    LoginController* loginController;    // 登陆行为的控制器类


private slots:
    void doLoginStatus(LOGINSTATE, User);    // 处理登陆状态

    void doResizeScroll(QSize);     // 改变滚动区域大小
};

#endif // APP_H
