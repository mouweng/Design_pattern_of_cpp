//
//  appearance.h
//  外观模式
//
//  Created by 翁一帆 on 2019/11/17.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef appearance_h
#define appearance_h

class SubSystemOne
{
public:
    void methodOne(){
        cout<<"子系统方法一"<<endl;
    }
};

class SubSystemTwo
{
public:
    void methodTwo(){
        cout<<"子系统方法二"<<endl;
    }
};

class SubSystemThree
{
public:
    void methodThree(){
        cout<<"子系统方法三"<<endl;
    }
};

class SubSystemFour
{
public:
    void methodFour(){
        cout<<"子系统方法四"<<endl;
    }
};

class Facade{
private:
    SubSystemOne *one;
    SubSystemTwo *two;
    SubSystemThree *three;
    SubSystemFour *four;
public:
    Facade(){
        one = new SubSystemOne();
        two = new SubSystemTwo();
        three = new SubSystemThree();
        four = new SubSystemFour();
    }
    void MethodA(){
        cout<<"方法组A:"<<endl;
        one->methodOne();
        two->methodTwo();
        three->methodThree();
        four->methodFour();
    }
    void MethodB(){
        cout<<"方法组B:"<<endl;
        three->methodThree();
        four->methodFour();
    }
};

void appearance_test(){
    Facade * facade = new Facade();
    facade->MethodA();
    facade->MethodB();
}

#endif /* appearance_h */
