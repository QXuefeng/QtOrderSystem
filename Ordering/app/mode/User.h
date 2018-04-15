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
 * @note    : 2018/03/21 -> 创建了本类
*/

#ifndef USER_H
#define USER_H

#include <QObject>

/**
 * @class   : User
 * @extends :
 * @brief   : 用户的模型类, 保存登陆成功的用户信息
*/
class User
{
public:
    /**
     * @function : User
     * @brief    : 构造函数
     * @param    : void
     * @data     : 2018/03/21
     */
    User() : userId(0) {}

    /**
     * @function : User
     * @brief    : 拷贝构造函数
     * @param    : user -> const User& -> 需要拷贝的User类
     * @data     : 2018/03/21
     */
    User(const User& user) :
        userId(user.userId)
    {}

    /**
     * @function : LoginController
     * @brief    : 拷贝构造函数
     * @param    : user -> const User& -> 需要拷贝的User类
     * @data     : 2018/03/21
     */
    const User& operator =(const User& user)
    {
        userId = user.userId;
    }

    /**
     * @function : getUserId
     * @brief    : 获取用户id
     *             ID: 0 表示无此user
     * @param    : void
     * @return   : quint32 -> 用户的id
     * @data     : 2018/03/21
     */
    quint32 getUserId() const
    {
        return userId;
    }

    /**
     * @function : setUserId
     * @brief    : 获取用户id
     *             ID: 0 表示无此user
     * @param    : userId -> quint32 -> 用户的id
     * @return   : void
     * @data     : 2018/03/21
     */
    void setUserId(quint32 userId)
    {
        this->userId = userId;
    }


private:
    /**
     * @var   : userId
     * @type  : quint32
     * @brief : 保存用户id, 默认为0
     * @data  : 2018/03/21
     */
    quint32 userId;
};

#endif // USER_H
