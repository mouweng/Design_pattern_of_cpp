//
//  example_phone.h
//  桥接模式
//
//  Created by 翁一帆 on 2019/11/25.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef example_phone_h
#define example_phone_h

class HandsetSoft
{
public:
    virtual void Run() = 0;
};

class HandsetGame : public HandsetSoft
{
public:
    void Run(){
        cout<<"运行手机游戏"<<endl;
    }
};

class HandsetAddressList : public HandsetSoft
{
public:
    void Run(){
        cout<<"运行手机通讯录"<<endl;
    }
};

class HandsetBrand
{
protected:
    HandsetSoft * soft;
public:
    void SetHandsetSoft(HandsetSoft * soft){
        this->soft = soft;
    }
    virtual void Run() = 0;
};

class HandsetBrandN : public HandsetBrand
{
public:
    void Run(){
        soft->Run();
    }
};

class HandsetBrandM : public HandsetBrand
{
public:
    void Run(){
        soft->Run();
    }
};


void example_test(){
    HandsetBrand * ab = new HandsetBrandN();
    ab->SetHandsetSoft(new HandsetGame());
    ab->Run();
    
    ab->SetHandsetSoft(new HandsetAddressList());
    ab->Run();
    
    ab = new HandsetBrandM();
    ab->SetHandsetSoft(new HandsetGame());
    ab->Run();
    
    ab->SetHandsetSoft(new HandsetAddressList());
    ab->Run();
}

#endif /* example_phone_h */
