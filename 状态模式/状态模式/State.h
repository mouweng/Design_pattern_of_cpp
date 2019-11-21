//
//  State.h
//  状态模式
//
//  Created by 翁一帆 on 2019/11/21.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef State_h
#define State_h

class Context;
class State
{
public:
    virtual void display() = 0;
    virtual void Handle(Context * cotext) = 0;
};

class Context
{
private:
    State * state;
public:
    void setState(State * state){
        this->state = state;
    }
    Context(State * state){
        this->state = state;
    }
    void Request(){
        cout<<"当前状态: ";
        state->display();
        state->Handle(this);//对请求做处理，并设置下一状态
    }
};

class ConcreteStateA : public State
{
public:
    void Handle(Context * context){
        context->setState(new ConcreteStateA());
    }
    virtual void display(){
        cout<<"ConcreteStateA"<<endl;
    }
};

class ConcreteStateB : public State
{
    public:
    void Handle(Context * context){
        context->setState(new ConcreteStateA());
    }
    virtual void display(){
        cout<<"ConcreteStateB"<<endl;
    }
};


class ConcreteStateC : public State
{
    public:
    void Handle(Context * context){
        context->setState(new ConcreteStateB());
    }
    virtual void display(){
        cout<<"ConcreteStateC"<<endl;
    }
};

void state_test(){
    Context * c = new Context(new ConcreteStateC());
    c->Request();
    c->Request();
    c->Request();
    c->Request();
}

#endif /* State_h */
