
//
//  example_testpaper.h
//  模板方法
//
//  Created by 翁一帆 on 2019/11/17.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef example_testpaper_h
#define example_testpaper_h

class TestPaper{
public:
    void TestQuestion1(){
        cout<<"TestQuestion1...."<<endl;
        cout<<"答案："<<Answer1()<<endl;
    }
    virtual string Answer1(){
        return "";
    }
    void TestQuestion2(){
        cout<<"TestQuestion2...."<<endl;
        cout<<"答案："<<Answer2()<<endl;
    }
    virtual string Answer2(){
        return "";
    }
    void TestQuestion3(){
        cout<<"TestQuestion3...."<<endl;
        cout<<"答案："<<Answer3()<<endl;
    }
    virtual string Answer3(){
        return "";
    }
};

class TestPaperA : public TestPaper{
public:
    string Answer1(){
        return "b";
    }
    string Answer2(){
        return "c";
    }
    string Answer3(){
        return "d";
    }
};

class TestPaperB : public TestPaper{
public:
    string Answer1(){
        return "a";
    }
    string Answer2(){
        return "b";
    }
    string Answer3(){
        return "c";
    }
};

void example_testpaper(){
    cout<<"学生A的试卷:"<<endl;
    TestPaper * studentA = new TestPaperA();
    studentA->TestQuestion1();
    studentA->TestQuestion2();
    studentA->TestQuestion3();
    
    cout<<"学生B的试卷:"<<endl;
    TestPaper * studentB = new TestPaperB();
    studentB->TestQuestion1();
    studentB->TestQuestion2();
    studentB->TestQuestion3();
}

#endif /* example_testpaper_h */
