//
//  Calculator.h
//  简单工厂模式
//
//  Created by 翁一帆 on 2019/11/13.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef Calculator_h
#define Calculator_h
#include <string>
class Operation{
public:
    double numberA;
    double numberB;
    virtual double GetResult()
    {
        double result = 0;
        return result;
    }
};

class OperationAdd : public Operation{
public:
    double GetResult(){
        double result = 0;
        result = numberA + numberB;
        return result;
    }
};

class OperationSub : public Operation{
public:
    double GetResult(){
        double result = 0;
        result = numberA - numberB;
        return result;
    }
};

class OperationMul : public Operation{
public:
    double GetResult(){
        double result = 0;
        result = numberA * numberB;
        return result;
    }
};

class OperationDiv : public Operation{
public:
    double GetResult(){
        double result = 0;
        if(numberB == 0)
            throw "Division by zero condition!";
        result = numberA / numberB;
        return result;
    }
};

class OperationFactory{
public:
    Operation *createOperation(string operate){
        Operation *oper = NULL;
        if(operate == "+"){
            oper = new OperationAdd;
        }else if(operate == "-"){
            oper = new OperationSub;
        }else if(operate == "*"){
            oper = new OperationMul;
        }else if(operate == "/"){
            oper = new OperationDiv;
        }else{
            oper = NULL;
        }
        return oper;
    }
};

#endif /* Calculator_h */
