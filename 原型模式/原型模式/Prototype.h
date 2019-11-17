//
//  Prototype.h
//  原型模式
//
//  Created by 翁一帆 on 2019/11/16.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef Prototype_h
#define Prototype_h


/*
 
 原型模式的标准c写法
 */

class Prototype{
public:
    Prototype(){};
    virtual Prototype * clone() = 0;
};

class ConcretePrototype : public Prototype{
private:
    ConcretePrototype(const ConcretePrototype&){
        cout<<"ConcretePrototype copy construct!"<<endl;
        //这个地方可以进行赋值
    };
public:
    ConcretePrototype(){};
    Prototype * clone(){
        return new ConcretePrototype(*this);
    }
};

void Prototype_test(){
    Prototype * p = new ConcretePrototype();
    Prototype * a = p->clone();
}


#endif /* Prototype_h */



