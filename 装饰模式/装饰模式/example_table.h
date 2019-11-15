//
//  example_table.h
//  装饰模式
//
//  Created by 翁一帆 on 2019/11/15.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef example_table_h
#define example_table_h


void print(char* str)
{
    cout<<"├───────────────────────────────"<<endl
        <<"│"<<str<<":"<<endl;
}

// Componennt
class absTable
{
public:
    virtual void putTable() = 0;
};

//具体定义的表格 Concrete Component A
class BaseTableA : public absTable
{
public:
    virtual void putTable(){
        print("姓名");
        print("性别");
        print("学历");
        print("年龄");
        cout<<"└───────────────────────────────"<<endl;
    }
};

class BaseTableB : public absTable
{
public:
    virtual void putTable(){
        print("name");
        print("sex");
        print("age");
        cout<<"└───────────────────────────────"<<endl;
    }
};

//定义抽象 Decorator
class Decorator : public absTable
{
private:
    absTable *mabsTable;
public:
    Decorator(absTable *pabsTable):mabsTable(pabsTable){}
    virtual void putTable(){
        mabsTable->putTable();
    }
};

//Concrete Decorator A
class EnglishDcrt:public Decorator
{
public:
    EnglishDcrt(absTable* pTb):Decorator(pTb){}

    virtual void putTable()
    {
        print("英语等级");
        Decorator::putTable();
    }
};
//Concrete Decorator B
class CurWage:public Decorator
{
public:
    CurWage(absTable* pTb):Decorator(pTb){}

    virtual void putTable()
    {
        print("当前薪水");
        Decorator::putTable();
    }
};
//Concrete Decorator C
class Experience:public Decorator
{
public:
    Experience(absTable* pTb):Decorator(pTb){}

    virtual void putTable()
    {
        print("项目经验");
        Decorator::putTable();
    }
};

void table_test(){
    BaseTableA proA;
    cout<<"初始表格A"<<endl<<endl;
    proA.putTable();
    BaseTableB proB;
    cout<<"初始表格B"<<endl<<endl;
    proB.putTable();
    
    cout<<"新表格1："<<endl<<endl;
    EnglishDcrt eng(&proA);
    eng.putTable();

    cout<<"新表格2："<<endl<<endl;
    CurWage wg(&eng);
    wg.putTable();

    cout<<"新表格3："<<endl<<endl;
    Experience ex(&proB);
    ex.putTable();
    
}

#endif /* example_table_h */
