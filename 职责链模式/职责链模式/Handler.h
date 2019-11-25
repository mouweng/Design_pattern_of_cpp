//
//  Handler.h
//  职责链模式
//
//  Created by 翁一帆 on 2019/11/25.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef Handler_h
#define Handler_h

class Handler
{
protected:
    Handler * successor;
public:
    void SetSuccessor(Handler * successor){
        this->successor = successor;
    }
    virtual void HandleRequest(int request) = 0;
};

class ConcreteHandler1 : public Handler
{
    void HandleRequest(int request){
        if(request >=0 && request <10){
            cout<<"ConcreteHandler1 处理请求 "<<request<<endl;
        }else if(successor != NULL){
            successor->HandleRequest(request);
        }
    }
};

class ConcreteHandler2 : public Handler
{
    void HandleRequest(int request){
        if(request >=10 && request <20){
            cout<<"ConcreteHandler2 处理请求 "<<request<<endl;
        }else if(successor != NULL){
            successor->HandleRequest(request);
        }
    }
};

class ConcreteHandler3 : public Handler
{
    void HandleRequest(int request){
        if(request >=20 && request <30){
            cout<<"ConcreteHandler3 处理请求 "<<request<<endl;
        }else if(successor != NULL){
            successor->HandleRequest(request);
        }
    }
};

void test(){
    Handler *h1 = new ConcreteHandler1();
    Handler *h2 = new ConcreteHandler2();
    Handler *h3 = new ConcreteHandler3();
    h1->SetSuccessor(h2);
    h2->SetSuccessor(h3);
    
    int request[10] = {2,3,14,22,18,3,27,20,50,100};
    for(int i=0;i<10;i++){
        h1->HandleRequest(request[i]);
    }
    
}
#endif /* Handler_h */
