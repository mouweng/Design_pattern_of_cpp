//
//  Bridge.h
//  桥接模式
//
//  Created by 翁一帆 on 2019/11/25.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef Bridge_h
#define Bridge_h
/*
 标准写法
 */

class Implementor
{
public:
    virtual void OperationImp() = 0;
};

class ConcreteImplementorA : public Implementor
{
public:
    void OperationImp(){
        cout<<"ConcreteImplementorA！"<<endl;
    }
};

class ConcreteImplementorB : public Implementor
{
public:
    void OperationImp(){
        cout<<"ConcreteImplementorB！"<<endl;
    }
};

class Abstraction
{
protected:
    Implementor * imp;
public:
    virtual void Operation() = 0;
    void setImplementor(Implementor * imp){
        this->imp = imp;
    }
};

class RefinedAbstraction : public Abstraction
{
public:
    void Operation(){
        imp->OperationImp();
    }
};

void test(){
    Abstraction * ra = new RefinedAbstraction();
    ra->setImplementor(new ConcreteImplementorA());
    ra->Operation();
    
    ra->setImplementor(new ConcreteImplementorB());
    ra->Operation();
}

#endif /* Bridge_h */
