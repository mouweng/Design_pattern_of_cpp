//
//  Decorator_simple.h
//  装饰模式
//
//  Created by 翁一帆 on 2019/11/15.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef Decorator_simple_h
#define Decorator_simple_h

/*
 
 简洁版的模板ConcreteComponent有两个
 ConcreteDecorator也有两个
 
 */

class Component
{
public:
    virtual void Operation() = 0;
};

class ConcreteComponentA : public Component
{
public:
    virtual void Operation(){
        cout<<"ConcreteComponentA Operation"<<endl;
    }
};

class ConcreteComponentB : public Component
{
public:
    virtual void Operation(){
        cout<<"ConcreteComponentB Operation"<<endl;
    }
};

class Decorator : public Component{
protected:
    Component *mCp;
public:
    Decorator(Component *cp):mCp(cp){}
    virtual void Operation(){
        mCp->Operation();
    }
};

class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA(Component *cp):Decorator(cp){}
    virtual void Operation(){
        cout<<"ConcreteDecoratorA Operation"<<endl;
        this->mCp->Operation();
    }
};

class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB(Component *cp):Decorator(cp){}
    virtual void Operation(){
        cout<<"ConcreteDecoratorB Operation"<<endl;
        this->mCp->Operation();
    }
};

void Decorator_simple_test(){
    ConcreteComponentA *cc1 = new ConcreteComponentA();
    ConcreteComponentB *cc2 = new ConcreteComponentB();
    
    cout<<endl;
    ConcreteDecoratorA *cd1 = new ConcreteDecoratorA(cc1);
    ConcreteDecoratorB *cd2 = new ConcreteDecoratorB(cd1);
    cd2->Operation();
    cout<<endl;
    
    cout<<endl;
    ConcreteDecoratorA *cd3 = new ConcreteDecoratorA(cc2);
    ConcreteDecoratorB *cd4 = new ConcreteDecoratorB(cd3);
    cd4->Operation();
    cout<<endl;
    
}

#endif /* Decorator_simple_h */
