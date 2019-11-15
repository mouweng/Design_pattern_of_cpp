//
//  example.h
//  策略模式
//
//  Created by 翁一帆 on 2019/11/15.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef example_h
#define example_h

//现金收费抽象类
class CashSuper
{
public:
    virtual double acceptCash(double money) = 0;
};

//正常收费子类
class CashNormal : public CashSuper
{
public:
    double acceptCash(double money){
        return money;
    }
};

//打折收费子类
class CashRebate : public CashSuper
{
private:
    double moneyRebate = 0.0;
public:
    CashRebate(double moneyRebate)
    {
        this->moneyRebate = moneyRebate;
    }
    double acceptCash(double money){
        return money * this->moneyRebate;
    }
};

//返利收费子类
class CashReturn : public CashSuper
{
private:
    double moneyCondition = 0.0;
    double moneyReturn = 0.0;
public:
    CashReturn(double moneyCondition, double moneyReturn){
        this->moneyCondition = moneyCondition;
        this->moneyReturn = moneyReturn;
    }
    double acceptCash(double money){
        if(money >= this->moneyCondition)
            return money - moneyReturn;
        else
            return money;
    }
};




class CashContext{
private:
    CashSuper *cs = NULL;
public:
    //策略模式和简单工厂相结合
    CashContext(string type){
        if(type == "正常收费")
            cs = new CashNormal();
        else if(type == "满300返200")
            cs = new CashReturn(300,100);
        else if(type == "打8折")
            cs = new CashRebate(0.8);
        else
            cs = NULL;
    }
    double GetResult(double money){
        return cs->acceptCash(money);
    }
};

void example_test(){
    
    CashContext *cc1 = new CashContext("打8折");
    double result1 = cc1->GetResult(200);
    cout<<"result1:"<<result1<<endl;

    CashContext *cc2 = new CashContext("满300返200");
    double result2 = cc2->GetResult(320);
    cout<<"result2:"<<result2<<endl;

    CashContext *cc3 = new CashContext("打8折");
    double result3 = cc3->GetResult(300);
    cout<<"result3:"<<result3<<endl;
    
}


#endif /* example_h */
