//
//  Decorator.h
//  装饰模式
//
//  Created by 翁一帆 on 2019/11/15.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef Decorator_h
#define Decorator_h


//Component
class Component
{
public:
    Component(){};
    virtual ~Component(){};
    virtual void operation() = 0;
};

//ConcreteComponent
class ConcreteComponent : public Component
{
public:
    ConcreteComponent(){};
    ~ConcreteComponent(){};
    
    void operation(){
        cout<<"ConcreteComponent's operation!"<<endl;
    }
};

class Decorator : public Component
{
protected:
    Component *mComponent;
    
public:
    Decorator(){};
    virtual ~Decorator(){};
    virtual void setComponent(Component* pComponent){
        this->mComponent = pComponent;
    };
    virtual void operation(){
        mComponent->operation();
    };
};

class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA(){};
    virtual ~ConcreteDecoratorA(){};
    virtual void operation(){
        cout<<"ConcreteDecoratorA's addBehavior!"<<endl;
        mComponent->operation();
    };
};

class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB(){};
    virtual ~ConcreteDecoratorB(){};
    virtual void operation(){
        cout<<"ConcreteDecoratorB's addBehavior!"<<endl;
        mComponent->operation();
    };
};



void Decorator_template(){
    Component *pComponent = new ConcreteComponent();
    
    ConcreteDecoratorA* pConDecoratorA = new ConcreteDecoratorA();
    ConcreteDecoratorB* pConDecoratorB = new ConcreteDecoratorB();
    
    pConDecoratorA->setComponent(pComponent);
    pConDecoratorB->setComponent(pConDecoratorA);
    pConDecoratorB->operation();
}




#endif /* Decorator_h */
