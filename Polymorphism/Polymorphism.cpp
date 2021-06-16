//
// Created by helianhaodong on 2021/6/5.
//

#include "../all.h"

/* 多态实现的条件 */
// 1. 父类中有虚函数，即共用接口。
// 2. 子类 override(覆写)父类中的虚函数，子类中"同名"，"同参"，"同返回"；shadow只需要"同名"
// 3. 通过"己被子类对象赋值"的父类指针，调用"共用接口"(虚函数)。

// virtual是"声明型关键字"
