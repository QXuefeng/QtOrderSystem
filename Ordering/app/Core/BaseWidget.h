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
 *            2018/03/24 -> 添加了窗口大小改变信号
 *
*/

#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QFile>
#include <QWidget>
#ifndef QT_NO_DEBUG
#include <QDebug>
#endif

/**
 * @class   : LoginController
 * @extends : QWidget -> Qt对象的祖先类
 * @brief   : 基础窗口, 提供共有的属性和方法, 如:
 *             1. 加载样式表文件
*/
class BaseWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @function : BaseWidget
     * @brief    : 构造函数
     * @param    : parent -> QWidget* -> 本类的父窗口
     * @data     : 2018/03/20
     */
    explicit BaseWidget(QWidget *parent = 0) :
        QWidget(parent) { }

    /**
     * @function : loadStyleSheet
     * @brief    : 加载样式表文件
     * @param    : sheetName -> const QString& -> qss文件名
     * @return   : void
     * @data     : 2018/03/20
     */
    void loadStyleSheet(const QString& sheetName) {

        /// 加载文件qss 文件
        /// 如果文件能打开, 不覆盖当前样式表添加给窗口
        QFile file(sheetName);
        file.open(QFile::ReadOnly);
        if (file.isOpen()) {
            this->setStyleSheet(this->styleSheet() + file.readAll());
        }
        /// 打开失败debug模式下提示信息
        #ifndef QT_NO_DEBUG
        else {
            qDebug() << sheetName + "打开失败";
        }
        #endif

    }

signals:
    /**
     * @function : windowSizeChanged
     * @brief    : 窗口大小改变信号
     * @param    : QSize -> 窗口变化后的大小
     * @return   : void
     * @data     : 2018/03/24
     */
    void windowSizeChanged(QSize);

};

#endif // BASEWIDGET_H
