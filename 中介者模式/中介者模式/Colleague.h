//
//  Colleague.h
//  中介者模式
//
//  Created by 翁一帆 on 2019/11/25.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef Colleague_h
#define Colleague_h
#include <string>

class Colleague;

class Mediator
{
public:
    virtual void Send(string message, Colleague * colleague) = 0;
};



class Colleague
{
protected:
    Mediator * mediator;
public:
    Colleague(Mediator * mediator){
        this->mediator = mediator;
    }
};

class ConcreteColleague1 : public Colleague
{
public:
    ConcreteColleague1(Mediator * mediator):Colleague(mediator){
    }
    void Send(string message){
        mediator->Send(message,this);
    }
    void Notify(string message){
        cout<<"同事1得到信息: "<<message<<endl;
    }
};

class ConcreteColleague2 : public Colleague
{
public:
    ConcreteColleague2(Mediator * mediator):Colleague(mediator){
    }
    void Send(string message){
        mediator->Send(message,this);
    }
    void Notify(string message){
        cout<<"同事2得到信息: "<<message<<endl;
    }
};


class ConcreteMediator : public Mediator
{
private:
    ConcreteColleague1 * colleague1;
    ConcreteColleague2 * colleague2;
public:
    void SetConcreteMediator(ConcreteColleague1 * colleague1, ConcreteColleague2 * colleague2){
        colleague1 = colleague1;
        colleague2 = colleague2;
    }
    void Send(string message, Colleague * colleague){
        if(colleague == colleague1){
            colleague2->Notify(message);
        }
        else{
            colleague1->Notify(message);
        }
    }
};

void test(){
    ConcreteMediator * m = new ConcreteMediator();
    ConcreteColleague1 *c1 = new ConcreteColleague1(m);
    ConcreteColleague2 *c2 = new ConcreteColleague2(m);
    m->SetConcreteMediator(c1,c2);
    
    c1->Send("你吃饭了嘛？");
    c2->Send("你要请客吗？");
    
}


#endif /* Colleague_h */
