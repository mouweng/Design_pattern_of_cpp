//
//  Memento.h
//  备忘录模式
//
//  Created by 翁一帆 on 2019/11/21.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef Memento_h
#define Memento_h
#include <string>

class Memento
{
private:
    string state;
public:
    Memento(string state){
        this->state = state;
    }
    string GetState(){
        return this->state;
    }
};

class Originator
{
private:
    string state;
public:
    void setState(string state){
        this->state = state;
    }
    
    Memento * CreateMemento(){
        return new Memento(state);
    }
    
    void SetMemento(Memento * memento){
        state = memento->GetState();
    }
    
    void Show(){
        cout<<"state = "<<state<<endl;
    }
};


class Caretaker
{
private:
    Memento * memento;
public:
    Memento * GetMemento(){
        return memento;
    }
    void SetMemento(Memento * memento){
        this->memento = memento;
    }
};


void memento_test(){
    Originator * o = new Originator();
    o->setState("On");
    o->Show();
    
    Caretaker * c = new Caretaker();
    c->SetMemento(o->CreateMemento());
    
    o->setState("Off");
    o->Show();
    
    o->SetMemento(c->GetMemento());
    o->Show();
    
    
}

#endif /* Memento_h */
