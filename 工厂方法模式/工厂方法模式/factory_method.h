//
//  factory_method.h
//  工厂方法模式
//
//  Created by 翁一帆 on 2019/11/16.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef factory_method_h
#define factory_method_h

/*
 工厂模式模板
 */
class Product{
public:
    virtual void function() = 0;
};

class ConcreteProduct : public Product{
public:
    void function(){
        cout<<"This is ConcreteProduct"<<endl;
    }
};

class Creator{
public:
    virtual Product * FactoryMethod() = 0;
};

class ConcreteCreator : public Creator{
public:
    Product * FactoryMethod(){
        ConcreteProduct *cp = new ConcreteProduct;
        return cp;
    }
};

void client(){
    Creator *creator = new ConcreteCreator;
    Product *product = creator->FactoryMethod();
    
    product->function();
}


#endif /* factory_method_h */
