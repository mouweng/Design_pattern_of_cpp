//
//  agent.h
//  代理模式
//
//  Created by 翁一帆 on 2019/11/16.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef agent_h
#define agent_h

/*
代理模式模板
*/

class Subject{
public:
    virtual void Request() = 0;
};

class RealSubject : public Subject{
public:
    void Request(){
        cout<<"This is real subject！"<<endl;
    }
};


class Proxy : public Subject{
private:
    RealSubject *rs;
public:
    Proxy(){
        rs = new RealSubject();
    }
    void Request(){
        rs->Request();
    }
};

void agent_test(){
    Proxy *proxy = new Proxy;
    proxy->Request();
    
}

#endif /* agent_h */
