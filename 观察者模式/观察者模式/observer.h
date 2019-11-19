//
//  observer.h
//  观察者模式
//
//  Created by 翁一帆 on 2019/11/19.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef observer_h
#define observer_h

class Observer
{
public:
    virtual void Update(string message) = 0;
};



class Subject
{
public:
    virtual void Attach(Observer *observer) = 0;
    virtual void Detach(Observer *observer) = 0;
    virtual void Notify() = 0;
};

class ConcrteSubject : public Subject
{
private:
    list<Observer *> ObserverList;
    string Message;
public:
    void Attach(Observer *observer){
        ObserverList.push_back(observer);
    }
    void Detach(Observer *observer){
        if(find(ObserverList.begin(), ObserverList.end(), observer) != ObserverList.end()){
            ObserverList.remove(observer);
        }
        
    }
    void Notify(){
        list<Observer *>::iterator it;
        for(it = ObserverList.begin(); it != ObserverList.end(); it++){
            (*it)->Update(Message);
        }
    }
    void setMessage(string message){
        Message = message;
        Notify();
    }
};

class ConcreteObserver1 : public Observer
{
public:
    void Update(string message){
        ConcreteObserver_1_state(message);
    }
    void ConcreteObserver_1_state(string message){
        cout<<"ConcreteObserver_1_state + "<<message<<endl;
    }
};

class ConcreteObserver2 : public Observer
{
private:
    void Update(string message){
        ConcreteObserver_2_state(message);
    }
    void ConcreteObserver_2_state(string message){
        cout<<"ConcreteObserver_2_state + "<<message<<endl;
    }
};


void observer_test(){
//    ConcreteObserver1 co1;
//    ConcreteObserver2 co2;
//    ConcrteSubject cs;
//    cs.Attach(&co1);
//    cs.Attach(&co2);
//    cs.setMessage("hello");
//
//    cs.Detach(&co2);
//    cs.setMessage("mouweng");
    ConcreteObserver1 * co1 = new ConcreteObserver1();
    ConcreteObserver2 * co2 = new ConcreteObserver2();
    ConcrteSubject * cs = new ConcrteSubject();;
    cs->Attach(co1);
    cs->Attach(co2);
    cs->setMessage("hello");
    
    cs->Detach(co2);
    cs->setMessage("mouweng");
}

#endif /* observer_h */

