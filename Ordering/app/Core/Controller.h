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
 *            2018/03/21 -> 添加了线程锁
*/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMutex>
#include <QObject>
#include <QSqlDatabase>
#ifndef QT_NO_DEBUG
#include <QDebug>
#endif


/**
 * @class   : LoginController
 * @extends : QObject -> Qt对象的祖先类
 * @brief   : 控制器的基础类, 提供共有的属性和方法, 如:
 *             1. 数据库对象
 *             2. 线程锁
*/
class Controller : public QObject
{
    Q_OBJECT
public:
    /**
     * @function : Controller
     * @brief    : 构造函数
     * @param    : parent -> QObject* -> 本类的父对象
     * @data     : 2018/03/20
     */
    explicit Controller(QObject *parent = 0)
        : QObject(parent)
    {
        /// 使用sqlite数据库
        /// 数据文件名称order.db
        /// 无法打开在debug模式下输出一些信息
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("order.db");
        if(!db.open()) {
            #ifndef QT_NO_DEBUG
            qDebug() << "数据库无法打开";
            #endif
        }
    }

    /**
     * @function : ~Controller
     * @brief    : 析构函数
     * @param    : void
     * @data     : 2018/03/20
     */
    ~Controller()
    {
        /// 关闭数据库连接
        db.close();
    }

protected:

    /**
     * @var    : db
     * @object : QSqlDatabase
     * @brief  : 数据库对象
     * @data   : 2018/03/20
     */
    QSqlDatabase db;

    /**
     * @var    : dbMutex
     * @object : QMutex
     * @brief  : 线程锁对象
     * @data   : 2018/03/21
     */
    QMutex dbMutex;

};

#endif // CONTROLLER_H
