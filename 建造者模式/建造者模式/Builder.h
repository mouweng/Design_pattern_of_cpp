//
//  Builder.h
//  建造者模式
//
//  Created by 翁一帆 on 2019/11/17.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef Builder_h
#define Builder_h

class Product
{
private:
    string parts;
public:
    void Add(string part){
        parts += part;
    }
    void Show(){
        cout<<parts<<endl;
    }
};

class Builder
{
public:
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual Product * GetResult() = 0;
};

class ConcreteBuilder1 : public Builder
{
private:
    Product * product = new Product();
public:
    void BuildPartA(){
        product->Add(" 部件A ");
    }
    void BuildPartB(){
        product->Add(" 部件B ");
    }
    Product * GetResult(){
        return product;
    }
};

class ConcreteBuilder2 : public Builder
{
private:
    Product * product = new Product();
public:
    void BuildPartA(){
        product->Add(" 部件X ");
    }
    void BuildPartB(){
        product->Add(" 部件Y ");
    }
    Product * GetResult(){
        return product;
    }
};

class Director
{
public:
    void Construct(Builder * builder){
        builder->BuildPartA();
        builder->BuildPartB();
    }
};

void Builder_test(){
    Director *director = new Director();
    
    Builder * b1 = new ConcreteBuilder1();
    Builder * b2 = new ConcreteBuilder2();
    
    director->Construct(b1);
    Product * p1 = b1->GetResult();
    p1->Show();
    
    director->Construct(b2);
    Product * p2 = b2->GetResult();
    p2->Show();
    
}

#endif /* Builder_h */
