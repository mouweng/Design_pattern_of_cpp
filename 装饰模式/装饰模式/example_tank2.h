//
//  example_tank2.h
//  装饰模式
//
//  Created by 翁一帆 on 2019/11/15.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef example_tank2_h
#define example_tank2_h

/*
因为只有一个T50，故可以把T50和Tank合并
也就是大概Concrete Component只有一个的时候，可以和component合并
同理，当Concrete Decorator只有一个的时候，也可以和Decorator合并
 */

//坦克抽象类别 component
class T50
{
public:
    virtual void shot(){
        cout<<"T50开炮"<<endl;
    }
};


//Decorator
class TankDecorator : public T50
{
protected:
    T50 *tank;
public:
    void setComponent(T50 *tank){
        this->tank = tank;
    }
    void shot(){
        tank->shot();
    }
};

//Decorator A 加大火力
class BigShot : public TankDecorator
{
public:
    void shot(){
        cout<<"大火力准备完毕"<<endl;
        tank->shot();
    }
};

//Decorator B 消音
class SlientShot : public TankDecorator
{
public:
    void xiaoyin(){
        cout<<"消音完毕"<<endl;
    }
    void shot(){
        xiaoyin();
        tank->shot();
    }
};

void tank_test(){
    T50 *ptank = new T50();
    
    BigShot *pBigShot = new BigShot();
    SlientShot *pSlientShot = new SlientShot();
    
    pBigShot->setComponent(ptank);
    pSlientShot->setComponent(pBigShot);
    
    pSlientShot->shot();
}

#endif /* example_tank2_h */
