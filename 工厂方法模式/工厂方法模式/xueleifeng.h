//
//  xueleifeng.h
//  工厂方法模式
//
//  Created by 翁一帆 on 2019/11/16.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef xueleifeng_h
#define xueleifeng_h

/*
 大话设计模式 学雷锋 案例
 */

class LeiFeng{
public:
    virtual void Sweep(){
        cout<<"扫地"<<endl;
    }
    virtual void Wash(){
        cout<<"洗衣"<<endl;
    }
    virtual void BuyRice(){
        cout<<"买米"<<endl;
    }
};

class Undergraduate : public LeiFeng
{
public:
    void print(){
        cout<<"大学生 ";
    }
    void Sweep(){
        print();
        LeiFeng ::Sweep();
    }
    void Wash(){
        print();
        LeiFeng ::Wash();
    }
    void BuyRice(){
        print();
        LeiFeng ::BuyRice();
    }
};

class Volunteer : public LeiFeng
{
    void print(){
        cout<<"志愿者 ";
    }
    void Sweep(){
        print();
        LeiFeng ::Sweep();
    }
    void Wash(){
        print();
        LeiFeng ::Wash();
    }
    void BuyRice(){
        print();
        LeiFeng ::BuyRice();
    }
};

class LeiFengFactory
{
public:
    virtual LeiFeng * CreateLeiFeng() = 0;
};

class UndergraduateFactory : public LeiFengFactory
{
public:
    LeiFeng * CreateLeiFeng(){
        Undergraduate *lf = new Undergraduate;
        return lf;
    }
};

class VolunteerFactory : public LeiFengFactory
{
public:
    LeiFeng * CreateLeiFeng(){
        Volunteer *lf = new Volunteer;
        return lf;
    }
};



void xueleifeng_test(){
    LeiFengFactory *factory = new UndergraduateFactory();
    
    LeiFeng *student = factory->CreateLeiFeng();
    student->BuyRice();
    student->Wash();
    student->Sweep();
    
    factory = new VolunteerFactory();
    LeiFeng * volunteer = factory->CreateLeiFeng();
    volunteer->BuyRice();
    volunteer->Wash();
    volunteer->Sweep();
}
#endif /* xueleifeng_h */
