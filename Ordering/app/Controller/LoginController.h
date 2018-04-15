/**
 * Copyright [yyyy] [江涛]

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @author  : 雪风
 * @date    : 2018/03
 * @version : 1.0
 * @remark  : 本软件仅用于学习交流
 * @note    : 2018/03/20 -> 创建了本类
 *
*/

#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include "User.h"
#include "Controller.h"

#include <QRegExp>
#include <QSqlQuery>
#ifndef QT_NO_DEBUG
#include <QDebug>
#endif


/**
 * @name  : LOGINSTATE
 * @type  : enum
 * @brief : 登陆返回的各种状态
 *          SUCCESS  -> 状态码0 -> 成功登陆
 *          UOPEMPTY -> 状态码1 -> 用户名或密码为空
 *          INVALID  -> 状态码2 -> 用户名或密码非法
 *          UOPERROR -> 状态码3 -> 用户名或密码不正确
 */
enum LOGINSTATE { SUCCESS, UOPEMPTY, INVALID, UOPERROR};

/**
 * @class   : LoginController
 * @extends : Controller -> 所有控制器的基类
 * @brief   : 登陆控制器, 提供登陆功能所需要的全部功能:
 *             1. 处理用户登陆
 *             2. 查询用户数据库, 检索登陆前后所必要的一些数据
 *             3. 返回登陆状态码和模型
*/
class LoginController : public Controller
{
    Q_OBJECT

public:
    /**
     * @function : LoginController
     * @brief    : 构造函数
     * @param    : parent -> QWidget* -> 本类的父窗口
     * @data     : 2018/03/20
     */
    explicit LoginController(QObject *parent = 0) :
        Controller(parent) { }

private:
    /**
     * @function : checkEmpty
     * @brief    : 检查密码是否为空
     * @param    : username -> const QString -> 用户名
     *             password -> const QString -> 密码
     * @return   : bool     -> true表示密码和用户名至少一个为空,
     *                         false表示都不为空
     * @data     : 2018/03/21
     */
    inline bool checkEmpty(const QString& username, const QString& password)
    {
        /// 有一个为空就return true
        /// 否则return false
        if(username.isEmpty() || password.isEmpty()) {
            return true;
        }
        return false;
    }

    /**
     * @function : checkValid
     * @brief    : 检查用户名和密码的合法性,
     *             用户名只能是字母或数字
     *             密码也只能是字母或数字
     * @param    : username -> const QString -> 用户名
     *             password -> const QString -> 密码
     * @return   : bool     -> true表示合法,
     *                          false表示用户名或密码非法字符
     * @data     : 2018/03/21
     */
    inline bool checkValid(const QString& username, const QString& password)
    {
        /// 有一个为空就return true
        /// 否则return false
        QRegExp regexp("[a-zA-Z1-9]+");

        /// 用户名的合法性判断
        /// 匹配到的长度不等于用户名长度表示包含非法字符
        regexp.indexIn(username);
        if(regexp.matchedLength() != username.length()) {
            return false;
        }

        /// 密码的合法性判断
        /// 匹配到的长度不等于密码长度表示包含非法字符
        regexp.indexIn(password);
        if(regexp.matchedLength() != password.length()) {
            return false;
        }

        return true;
    }

    /**
     * @function : checkExistUsername
     * @brief    : 检查数据库是否存在此用户名
     * @param    : username -> const QString -> 用户名
     * @return   : bool     -> 是否存在此用户名
     *             true     -> 存在
     *             false    -> 不存在
     * @data     : 2018/03/21
     */
    inline bool checkExistUsername(const QString& username)
    {
        QString sql = "select id from user where username='%1' limit 0,1";
        QSqlQuery query(db);
        query.exec(sql.arg(username));
        if(query.next()) {
            return true;
        }
        return false;
    }

    /**
     * @function : doSignIn
     * @brief    : 在用户名不存在的情况下进行注册
     * @param    : username -> const QString -> 用户名
     *             password -> const QString -> 密码
     * @return   : void
     * @data     : 2018/03/21
     */
    inline void doSignIn(const QString& username, const QString& password)
    {
        QString sql = "insert into user(username, password) values('%1', '%2')";
        QSqlQuery query(db);
        query.exec(sql.arg(username, password));
    }

    /**
     * @function : queryToUser
     * @brief    : 查询用户, 获取数据库中登陆用户信息
     * @param    : username   -> const QString -> 用户名
     *             password   -> const QString -> 密码
     * @return   : const User -> 用户信息
     *             存在        -> 返回用户信息
     * @data     : 2018/03/21
     */
    inline const User queryToUser(const QString& username, const QString& password)
    {
        User user;

        /// 如果用户不存在, 注册
        if(!checkExistUsername(username)) {
            doSignIn(username, password);
        }

        /// 查询用户信息
        QString sql = "select id from user where username='%1' and password='%2' limit 0,1";
        QSqlQuery query(db);
        query.exec(sql.arg(username, password));
        if(query.next()) {
            user.setUserId(query.value(0).toInt());
        }
        return user;
    }

signals:
    /**
     * @function : loginStatus
     * @brief    : 把用户登陆后构成登陆码
     * @param    : LOGINSTATE -> 登陆状态码
     *             User       -> 成功登陆后保存检索到用户部分信息
     * @return   : void
     * @data     : 2018/03/20
     */
    void loginStatus(LOGINSTATE, User);

public slots:
    /**
     * @function : doLogin
     * @brief    : 处理用户登陆行为
     * @param    : loginName -> const QString -> 用户名
     *             loginPsd  -> const QString -> 密码
     * @return   : void
     * @data     : 2018/03/20
     */
    void doLogin(const QString loginName, const QString loginPsd)
    {
        /// user  成功登陆会保存用户的信息
        ///       失败登陆为空
        /// state 会保存登陆的状态码
        User user;
        LOGINSTATE state;

        /// 登陆情况判断
        ///     1. 检查密码和用户名是否为空,
        ///        空登陆状态码为LOGINSTATE::UOPEMPTY,
        ///        用户信息为空
        ///     2. 检查密码和用户名是否合法
        ///        不合法登陆状态码LOGINSTATE::INVALID,
        ///        用户信息为空
        ///     3. 用户存在但密码不正确, 登陆失败
        ///        状态码为LOGINSTATE::UOPERROR,
        ///        用户信息为空
        ///     4. 用户和密码都不存在, 注册 -> 登陆成功
        ///        状态码为LOGINSTATE::SUCCESS,
        ///        获取到用户信息
        ///     5. 用户和密码都正确, 登陆成功
        ///        状态码为LOGINSTATE::SUCCESS,
        ///        获取到用户信息
        if(checkEmpty(loginName, loginPsd)) {
            state = LOGINSTATE::UOPEMPTY;
            user = User();
        }
        else if(!checkValid(loginName, loginPsd)) {
            state = LOGINSTATE::INVALID;
            user = User();
        }
        else {
            /// 保证线程安全
            dbMutex.lock();

            user = queryToUser(loginName, loginPsd);
            if(user.getUserId()) {
                state = LOGINSTATE::SUCCESS;
            }
            else {
                state = LOGINSTATE::UOPERROR;
            }

            /// 解锁, 防止死锁
            dbMutex.unlock();
        }
        emit loginStatus(state, user);
    }


};

#endif // LOGINCONTROLLER_H
