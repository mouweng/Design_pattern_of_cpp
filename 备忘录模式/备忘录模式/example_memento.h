//
//  example_memento.h
//  备忘录模式
//
//  Created by 翁一帆 on 2019/11/21.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef example_memento_h
#define example_memento_h

class RoleMemento{
public:
    int life;
    int attack;
    int guard;
    RoleMemento(int life, int attack, int guard){
        this->life = life;
        this->attack = attack;
        this->guard = guard;
    }
};

//originator
class GameRole
{
public:
    int life;
    int attack;
    int guard;
    
    GameRole(int life, int attack, int guard ){
        this->life = life;
        this->attack = attack;
        this->guard = guard;
    }
    
    void show(){
        cout<<"生命力:"<<life<<"; 攻击力:"<<attack<<"; 防御力:"<<guard<<endl;
    }
    RoleMemento * saveRole(){
        return new RoleMemento(life, attack, guard);
    }
    void setRole(RoleMemento * rm){
        this->life = rm->life;
        this->attack = rm->attack;
        this->guard = rm->guard;
    }
    void Change(int life, int attack, int guard){
        this->life = life;
        this->attack = attack;
        this->guard = guard;
    }
};

class RoleManager
{
private:
    RoleMemento * rolememento;
public:
    void setRoleManager(RoleMemento * rolememento){
        this->rolememento = rolememento;
    }
    RoleMemento * GetRoleManager(){
        return rolememento;
    }
};

void game_test(){
    GameRole * gr = new GameRole(1, 2, 3);
    gr->show();
    
    RoleManager * rm = new RoleManager();
    rm->setRoleManager(gr->saveRole());
    
    gr->Change(0,0,0);
    gr->show();

    
    gr->setRole(rm->GetRoleManager());
    gr->show();
}



#endif /* example_memento_h */
