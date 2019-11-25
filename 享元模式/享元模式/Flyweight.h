//
//  Flyweight.h
//  享元模式
//
//  Created by 翁一帆 on 2019/11/25.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef Flyweight_h
#define Flyweight_h
#include <vector>
class Flyweight
{
public:
    virtual void operation() = 0;
};


class ConcreteFlyweight : public Flyweight
{
public:
    void operation(){
        cout<<"具体的Flyweight "<<endl;
    }
};

class UnsharedConcreteFlyweight : public Flyweight
{
public:
    void operation(){
        cout<<"不共享的的Flyweight "<<endl;
    }
};

class FlyweightFactory
{
private:
    vector<Flyweight *> m_flyWeights;
public:
    FlyweightFactory(){
        Flyweight * tmp1 = new ConcreteFlyweight();
        m_flyWeights.push_back(tmp1);
        Flyweight * tmp2 = new ConcreteFlyweight();
        m_flyWeights.push_back(tmp2);
        Flyweight * tmp3 = new ConcreteFlyweight();
        m_flyWeights.push_back(tmp3);
    }
    Flyweight * GetFlyWeight(int key){
        return m_flyWeights.at(key);
    }
};

void test(){
    FlyweightFactory * factory = new FlyweightFactory();
    Flyweight * flyweight = factory->GetFlyWeight(0);
    flyweight->operation();
    
    flyweight = factory->GetFlyWeight(1);
    flyweight->operation();
    
    flyweight = factory->GetFlyWeight(2);
    flyweight->operation();
}

#endif /* Flyweight_h */
