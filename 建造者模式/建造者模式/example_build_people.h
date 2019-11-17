//
//  example_build_people.h
//  建造者模式
//
//  Created by 翁一帆 on 2019/11/17.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef example_build_people_h
#define example_build_people_h

class PersonBuilder
{
public:
    virtual void BuildHead() = 0;
    virtual void BuildBody() = 0;
    virtual void BuildArmLeft() = 0;
    virtual void BuildArmRight() = 0;
    virtual void BuildLegLeft() = 0;
    virtual void BuildLegRight() = 0;
};

class Person1 : public PersonBuilder
{
public:
    void BuildHead(){
        cout<<"Person1_Head"<<endl;
    };
    void BuildBody(){
        cout<<"Person1_Body"<<endl;
    };
    void BuildArmLeft(){
        cout<<"Person1_ArmLeft"<<endl;
    };
    void BuildArmRight(){
        cout<<"Person1_ArmRight"<<endl;
    };
    void BuildLegLeft(){
        cout<<"Person1_LegLeft"<<endl;
    };
    void BuildLegRight(){
        cout<<"Person1_LegRight"<<endl;
    };
};

class Person2 : public PersonBuilder
{
public:
    void BuildHead(){
        cout<<"Person2_Head"<<endl;
    };
    void BuildBody(){
        cout<<"Person2_Body"<<endl;
    };
    void BuildArmLeft(){
        cout<<"Person2_ArmLeft"<<endl;
    };
    void BuildArmRight(){
        cout<<"Person2_ArmRight"<<endl;
    };
    void BuildLegLeft(){
        cout<<"Person2_LegLeft"<<endl;
    };
    void BuildLegRight(){
        cout<<"Person2_LegRight"<<endl;
    };
};

class PersonDirector{
private:
        PersonBuilder *pb;
public:
    PersonDirector(PersonBuilder * pb){
        this->pb = pb;
    }
    void Construct(){
        pb->BuildHead();
        pb->BuildBody();
        pb->BuildArmLeft();
        pb->BuildArmRight();
        pb->BuildLegLeft();
        pb->BuildLegRight();
    }
};

void person_test(){
    PersonBuilder * pb1 = new Person1();
    PersonDirector * pd1 = new PersonDirector(pb1);
    pd1->Construct();
    
    PersonBuilder * pb2 = new Person2();
    PersonDirector *pd2 = new PersonDirector(pb2);
    pd2->Construct();
}

#endif /* example_build_people_h */
