#include "App.h"
#include "MainWidget.h"
#include "LoginWidget.h"

#include <QScrollArea>

App::App(QObject *parent) : loginWidget(NULL),
    mainWidget(NULL),
    scrollArea(NULL),
    loginController(NULL),
    QObject(parent)
{
    init();
}

App::~App()
{
    // 内存回收
    if(loginController) { delete loginController; loginController = 0; }

    if(loginWidget) { delete loginWidget; loginWidget = 0; }
    if(mainWidget) { delete mainWidget; mainWidget = 0; }
    if(scrollArea) { delete scrollArea; scrollArea = 0; }
}

void App::init()
{
    // 创建登陆控制器
    if(!loginController) {
        loginController = new LoginController;

        // appController->this 处理登陆结果
        QObject::connect(loginController, SIGNAL(loginStatus(LOGINSTATE, User)), this, SLOT(doLoginStatus(LOGINSTATE, User)));
    }

    // 创建登陆窗口
    if(!loginWidget) {
        loginWidget = new LoginWidget;
        loginWidget->show();

        QObject::connect(loginWidget, SIGNAL(loginAction(QString, QString)), loginController, SLOT(doLogin(QString,QString)));
    }


}

void App::doLoginStatus(LOGINSTATE state, User user)
{
    // 登陆成功显示主界面
    if(!mainWidget) mainWidget = new MainWidget;

    if(!scrollArea) {
        scrollArea = new QScrollArea;

        connect(mainWidget, SIGNAL(windowSizeChanged(QSize)), this, SLOT(doResizeScroll(QSize)));

        scrollArea->setFixedSize(1120, 665);
        scrollArea->setWidget(mainWidget);
        scrollArea->widget()->resize(1100, 665);
        mainWidget->init();

        //加载样式
        QFile file(":/qss/QScrollArea.css");
        file.open(QFile::ReadOnly);
        if (file.isOpen()) scrollArea->setStyleSheet(file.readAll());
        scrollArea->show();
    }

    // 删除登陆控制器
    if(loginController) { delete loginController; loginController = 0; }

    // 删除登陆窗口
    if(loginWidget) { delete loginWidget; loginWidget = 0; }

}

void App::doResizeScroll(QSize sz)
{
    scrollArea->widget()->resize(sz);
}
