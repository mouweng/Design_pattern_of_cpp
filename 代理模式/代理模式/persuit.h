//
//  persuit.h
//  代理模式
//
//  Created by 翁一帆 on 2019/11/16.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef persuit_h
#define persuit_h

/*
 大话设计模式中的例子
 */

class SchoolGirl{
protected:
    string name;
public:
    SchoolGirl(string n){
        name = n;
    }
    string GetGirlName(){
        return name;
    }
};

//subject interface
class GiveGift{
public:
    virtual void GiveDolls() = 0;
    virtual void GiveFlowers() = 0;
    virtual void GiveChocolate() = 0;
};

class Persuit : GiveGift{
protected:
    SchoolGirl *mm;
public:
    Persuit(SchoolGirl *mm){
        this->mm = mm;
    }
    void GiveDolls(){
        cout<<mm->GetGirlName()<<" 送你娃娃"<<endl;
    }
    void GiveFlowers(){
        cout<<mm->GetGirlName()<<" 送你鲜花"<<endl;
    }
    void GiveChocolate(){
        cout<<mm->GetGirlName()<<" 送你巧克力"<<endl;
    }
};

class PersuitProxy : GiveGift{
private:
    Persuit *gg;
public:
    PersuitProxy(SchoolGirl *mm){
        gg = new Persuit(mm);
    }
    void GiveDolls(){
        gg->GiveDolls();
    }
    void GiveFlowers(){
        gg->GiveFlowers();
    }
    void GiveChocolate(){
        gg->GiveChocolate();
    }
};

void persuit_test(){
    SchoolGirl *jiaojiao = new SchoolGirl("娇娇");
    
    PersuitProxy *daili = new PersuitProxy(jiaojiao);
    
    daili->GiveDolls();
    daili->GiveFlowers();
    daili->GiveChocolate();
    
}

#endif /* persuit_h */
