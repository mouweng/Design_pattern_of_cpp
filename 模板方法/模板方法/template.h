//
//  template.h
//  模板方法
//
//  Created by 翁一帆 on 2019/11/17.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef template_h
#define template_h

class AbstractClass{
public:
    virtual void PrimitiveOperation1(){}
    virtual void PrimitiveOperation2(){}
    void TemplateMethod(){
        PrimitiveOperation1();
        PrimitiveOperation2();
        cout<<"ABS"<<endl;
    }
};

class ConcreteClassA : public AbstractClass
{
public:
    void PrimitiveOperation1(){
        cout<<"具体类A方法1实现"<<endl;
    }
    void PrimitiveOperation2(){
        cout<<"具体类A方法2实现"<<endl;
    }
};

class ConcreteClassB : public AbstractClass
{
public:
    void PrimitiveOperation1(){
        cout<<"具体类B方法1实现"<<endl;
    }
    void PrimitiveOperation2(){
        cout<<"具体类B方法2实现"<<endl;
    }
};

void template_test(){
    AbstractClass *c;
    
    c = new ConcreteClassA();
    c->TemplateMethod();
    
    c = new ConcreteClassB();
    c->TemplateMethod();
    
}



#endif /* template_h */
