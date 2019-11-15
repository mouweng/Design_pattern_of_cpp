//
//  main.cpp
//  简单工厂模式
//
//  Created by 翁一帆 on 2019/11/13.
//  Copyright © 2019 mouweng. All rights reserved.
//

#include <iostream>
#include "simplefactory.h"
#include "Calculator.h"
#include <string>
using namespace std;


//客户类
int main(){
    //BWMcar test
    SimpleFactory bmwFactory;
    BMW *carA = bmwFactory.CreateCar("BMW320");
    BMW *carB = bmwFactory.CreateCar("BMW520");
    carA->GetCar();
    carB->GetCar();
    
    //operator test
    OperationFactory optFactory;
    Operation *oper = optFactory.createOperation("*");
    oper->numberA = 1;
    oper->numberB = 2;
    double result = oper->GetResult();
    cout<<result<<endl;
}
