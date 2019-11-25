//
//  Visitor.h
//  访问者模式
//
//  Created by 翁一帆 on 2019/11/25.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef Visitor_h
#define Visitor_h
#include <vector>

class Man;
class Woman;
class Action
{
public:
    virtual void GetManConclusion(Man * concreteElementA) = 0;
    virtual void GetWomanConclusion(Woman * concreteElementA) = 0;
};

class Success : public Action
{
    void GetManConclusion(Man * concreteElementA){
        cout<<"男人成功时，背后多半有个伟大的女人!"<<endl;
    }
    void GetWomanConclusion(Woman * concreteElementA){
        cout<<"女人成功时，背后多半有个不成功的男人!"<<endl;
    }
};

class Failing : public Action
{
    void GetManConclusion(Man * concreteElementA){
        cout<<"男人失败时，闷头喝酒，谁也劝不动!"<<endl;
    }
    void GetWomanConclusion(Woman * concreteElementA){
        cout<<"女人失败时，眼泪汪汪，谁也劝不了!"<<endl;
    }
};

class Person
{
public:
    virtual void Accept(Action *visitor) = 0;
};

class Man : public Person
{
public:
    void Accept(Action *visitor){
        visitor->GetManConclusion(this);
    }
};

class Woman : public Person
{
public:
    void Accept(Action *visitor){
        visitor->GetWomanConclusion(this);
    }
};

class ObjectStructure
{
private:
    vector<Person *> elements;
public:
    void Attach(Person * element){
        elements.push_back(element);
    }
    void Display(Action * visitor){
        for(int i=0;i<elements.size();i++){
            elements[i]->Accept(visitor);
        }
    }
};

void test(){
    ObjectStructure * o = new ObjectStructure();
    o->Attach(new Man());
    o->Attach(new Woman());
    
    Success * v1 = new Success();
    o->Display(v1);
    
    Failing * v2 = new Failing();
    o->Display(v2);
}

#endif /* Visitor_h */
