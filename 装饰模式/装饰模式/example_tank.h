//
//  example_tank.h
//  装饰模式
//
//  Created by 翁一帆 on 2019/11/15.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef example_tank_h
#define example_tank_h

/*
 和模板一致，所有元素都有，可以在T50大炮l那里多扩展几个大炮
 */

//坦克抽象类别 component
class Tank
{
public:
    virtual void shot(){
        cout<<"向我开炮"<<endl;
    }
};

//Concrete component
class T50 : public Tank
{
public:
    void shot(){
        cout<<"T50开炮"<<endl;
    }
};

//Decorator
class TankDecorator : public Tank
{
protected:
    Tank *tank;
public:
    void setComponent(Tank *tank){
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
    Tank *ptank = new T50();
    
    BigShot *pBigShot = new BigShot();
    SlientShot *pSlientShot = new SlientShot();
    
    pBigShot->setComponent(ptank);
    pSlientShot->setComponent(pBigShot);
    
    pSlientShot->shot();
}
#endif /* example_tank_h */
