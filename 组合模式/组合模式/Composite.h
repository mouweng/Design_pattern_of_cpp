//
//  Composite.h
//  组合模式
//
//  Created by 翁一帆 on 2019/11/21.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef Composite_h
#define Composite_h
#include<vector>
#include<string>

class Component
{
public:
    string name;
    Component(string s){
        this->name = s;
    }
    virtual void Add(Component *c) = 0;
    virtual void Remove(Component *c) = 0;
    virtual void Display(int depth) = 0;
};

class Leaf : public Component
{
public:
    Leaf(string s):Component(s){}
    void Add(Component *c){}
    void Remove(Component *c){}
    void Display(int depth){
        for(int i=0;i<depth;i++){
            cout<<"-";
        }
        cout<<name<<endl;
    }
};

class Composite : public Component
{
private:
    vector<Component *> children;
public:
    Composite(string s):Component(s){}
    void Add(Component * c){
        children.push_back(c);
    }
    void Remove(Component * c){
        for(int i=0;i<children.size();i++){
            if(c->name == children[i]->name){
                children.erase(children.begin() + i);
            }
        }
    }
    void Display(int depth){
        for(int i=0;i<depth;i++){
            cout<<"-";
        }
        cout<<name<<endl;
        for(int i=0;i<children.size();i++){
            children[i]->Display(depth + 2);
        }
    }
};

void Composite_test(){
    Composite * root = new Composite("root");
    root->Add(new Leaf("Leaf A"));
    root->Add(new Leaf("Leaf B"));
    
    Composite *comp1 = new Composite("Composite X");
    comp1->Add(new Leaf("Leaf XA"));
    comp1->Add(new Leaf("Leaf XB"));
    root->Add(comp1);
    
    Composite *comp2 = new Composite("Composite Y");
    comp2->Add(new Leaf("Leaf XYB"));
    comp2->Add(new Leaf("Leaf XYB"));
    comp1->Add(comp2);
    
    root->Add(new Leaf("Leaf C"));
    root->Add(new Leaf("Leaf D"));
    root->Remove(new Leaf("Leaf D"));
    root->Display(1);
}

#endif /* Composite_h */
