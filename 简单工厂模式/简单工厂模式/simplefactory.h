//
//  simplefactory.h
//  简单工厂模式
//
//  Created by 翁一帆 on 2019/11/13.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef simplefactory_h
#define simplefactory_h

#include <string>
using namespace std;
//抽象产品类
class BMW
{
public:
    virtual void GetCar() = 0;
};

//具体产品类1
class BMW320 : public BMW
{
public:
    BMW320(){}
    void GetCar(){
        printf("BMW320 \n");
    }
};

//具体产品类2
class BMW520 : public BMW
{
public:
    BMW520(){}
    void GetCar(){
        printf("BMW520 \n");
    }
};


//简单工厂
class SimpleFactory
{
public:
    SimpleFactory(){}
    BMW *CreateCar(string name){
        if(name == "BMW320")
            return new BMW320();
        else if(name == "BMW520")
            return new BMW520();
        else
            return NULL;
    }
};

#endif /* simplefactory_h */
