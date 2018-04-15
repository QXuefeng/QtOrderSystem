#include "LoginWidget.h"
#include "ui_LoginWidget.h"

LoginWidget::LoginWidget(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    init();

    connect(ui->btnLoginAck, SIGNAL(clicked()), this, SLOT(doLoginAck()));

    loadStyleSheet(":/qss/StartWidget.css");
}

void LoginWidget::init()
{
    // 设置提示
    ui->editUname->setPlaceholderText("用户名");
    ui->editPwd->setPlaceholderText("密码");
}

void LoginWidget::doLoginAck()
{
    /// 提交由登陆控制器处理
    emit loginAction(ui->editUname->text(), ui->editPwd->text());
}

LoginWidget::~LoginWidget()
{
    delete ui;
}
