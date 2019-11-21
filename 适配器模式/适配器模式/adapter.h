//
//  adapter.h
//  适配器模式
//
//  Created by 翁一帆 on 2019/11/21.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef adapter_h
#define adapter_h

class Target
{
public:
    virtual void Request(){
        cout<<"普通请求!"<<endl;
    }
};

class Adaptee
{
public:
    void SpecificRequest(){
        cout<<"特殊请求!"<<endl;
    }
};

class Adapter : public Target
{
private:
    Adaptee * adaptee = new Adaptee();
public:
    void Request(){
        adaptee->SpecificRequest();
    }
};

void adapter_test(){
    Target * target = new Adapter();
    target->Request();
}

#endif /* adapter_h */
