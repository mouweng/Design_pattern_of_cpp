//
//  template_factory_code.h
//  策略模式
//
//  Created by 翁一帆 on 2019/11/15.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef template_factory_code_h
#define template_factory_code_h

/*
 模板写法，结合工厂方法
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
    //结合工厂方法的入口点！！！
    Context(string str){
        if(str == "str1")
            _str = new ConcreteStrategy1();
        else if(str == "str2")
            _str = new ConcreteStrategy2();
        else
            _str = NULL;
    }
    
    void doAnything(){
        _str->doSomething();
    }
};


void template_factory_Test(){
    cout<<"template_factory_Test"<<endl;
    Context *con1 = new Context("str1");
    con1->doAnything();

    Context *con2 = new Context("str2");
    con2->doAnything();
}

#endif /* template_factory_code_h */
