//
//  templatecode.h
//  策略模式
//
//  Created by 翁一帆 on 2019/11/15.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef templatecode_h
#define templatecode_h
using namespace std;

/*
 模板写法，不结合工厂方法
 */

class Strategy
{
protected:
    Strategy(){};
public:
    virtual void doSomething() = 0;
};

class ConcreteStrategy1 : public Strategy
{
public:
    void doSomething(){
        cout<<"具体策略1的运算法则"<<endl;
    }
};

class ConcreteStrategy2 : public Strategy
{
public:
    void doSomething(){
        cout<<"具体策略2的运算法则"<<endl;
    }
};

//封装角色
class Context
{
private:
    Strategy * _str;
public:
    Context(Strategy *st){
        _str = st;
    }
    void doAnything(){
        _str->doSomething();
    }
};


void templatecode_Test(){
    Strategy * st1 = new ConcreteStrategy1();
    Context *con1 = new Context(st1);
    con1->doAnything();

    Strategy * st2 = new ConcreteStrategy2();
    Context *con2 = new Context(st2);
    con2->doAnything();
}

#endif /* templatecode_h */
