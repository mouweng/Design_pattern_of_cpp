//
//  example_adapter.h
//  适配器模式
//
//  Created by 翁一帆 on 2019/11/21.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef example_adapter_h
#define example_adapter_h

class Player
{
public:
    virtual void Attack(){
        cout<<"进攻"<<endl;
    }
    virtual void Defense(){
        cout<<"防守"<<endl;
    }
};

class Forwards : public Player
{
    void Attack(){
        cout<<"前锋 进攻"<<endl;
    }
    void Defense(){
        cout<<"前锋 防守"<<endl;
    }
};

class Center : public Player
{
    void Attack(){
        cout<<"中锋 进攻"<<endl;
    }
    void Defense(){
        cout<<"中锋 防守"<<endl;
    }
};

class Guards : public Player
{
    void Attack(){
        cout<<"后卫 进攻"<<endl;
    }
    void Defense(){
        cout<<"后卫 防守"<<endl;
    }
};

class ForeignPlayer
{
public:
    void 进攻(){
        cout<<"外籍球员 进攻"<<endl;
    }
    void 防守(){
        cout<<"外籍球员 防守"<<endl;
    }
};

class interpreter : public Player
{
private:
    ForeignPlayer * fp = new ForeignPlayer();
public:
    void Attack(){
        fp->进攻();
    }
    void Defense(){
        fp->防守();
    }
};


void player_test(){
    Player *p1 = new Forwards();
    Player *p2 = new Center();
    Player *p3 = new Guards();
    Player *p4 = new interpreter();
    p1->Attack();
    p2->Attack();
    p3->Attack();
    p4->Attack();
    
    p1->Defense();
    p2->Defense();
    p3->Defense();
    p4->Defense();
}

#endif /* example_adapter_h */
