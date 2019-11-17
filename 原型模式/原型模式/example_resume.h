//
//  example_resume.h
//  原型模式
//
//  Created by 翁一帆 on 2019/11/17.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef example_resume_h
#define example_resume_h

class Resume{
public:
    string name;
    string sex;
    string age;
    string timeArea;
    string company;
    Resume(){};
    void setName(string name){
        this->name = name;
    }
    //设置个人信息
    void setPersonalInfo(string sex, string age){
        this->sex = sex;
        this->age = age;
    }
    //设置工作经历
    void setWorkExperience(string timeArea, string company){
        this->timeArea = timeArea;
        this->company = company;
    }
    //显示
    void Display(){
        cout<<name<<" "<<sex<<" "<<age<<" "<<endl;
        cout<<timeArea<<" "<<company<<endl;
    }
    virtual Resume * clone() = 0;
};

class ConcreteResume : public Resume{
public:
    ConcreteResume(const ConcreteResume& cr){
        this->setPersonalInfo(cr.sex, cr.age);
        this->setWorkExperience(cr.timeArea, cr.company);
        this->name = cr.name;
    }
    ConcreteResume(string name, string sex, string age, string timeArea, string company){
        this->setName(name);
        this->setPersonalInfo(age, timeArea);
        this->setWorkExperience(timeArea, company);
    };
    Resume * clone(){
        return new ConcreteResume(*this);
    }
};

void resume_test(){
    Resume * re = new ConcreteResume("wyf", "m", "21", "2018", "zx");
    Resume * re_clone1 = re->clone();
    Resume * re_clone2 = re->clone();
    
    re_clone1->setPersonalInfo("f","22");
    re_clone2->setWorkExperience("2019","bt");
    
    re->Display();
    re_clone1->Display();
    re_clone2->Display();
}


#endif /* example_resume_h */
