//
//  abstract_factory.h
//  抽象工厂模式
//
//  Created by 翁一帆 on 2019/11/19.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef abstract_factory_h
#define abstract_factory_h

/*
 以大话设计模式上的数据库的例子为举例
 */


class IUser
{
public:
    virtual void Insert() = 0;
    virtual void GetUser() = 0;
};

class SqlServerUser : public IUser
{
public:
    void Insert(){
        cout<<"在SQL server中给User表增加一条记录"<<endl;
    }
    void GetUser(){
        cout<<"在SQL server中得到一条User记录"<<endl;
    }
};

class AccessUser : public IUser
{
public:
    void Insert(){
        cout<<"在Access中给User表增加一条记录"<<endl;
    }
    void GetUser(){
        cout<<"在Access中得到一条User记录"<<endl;
    }
};


class IDepartment
{
public:
    virtual void Insert() = 0;
    virtual void GetDepartment() = 0;
};

class SqlServerDepartment : public IDepartment
{
public:
    void Insert(){
        cout<<"在SQL server中给Department表增加一条记录"<<endl;
    }
    void GetDepartment(){
        cout<<"在SQL server中得到一条Department记录"<<endl;
    }
};

class AccessDepartment : public IDepartment
{
public:
    void Insert(){
        cout<<"在Access中给Department表增加一条记录"<<endl;
    }
    void GetDepartment(){
        cout<<"在Access中得到一条Department记录"<<endl;
    }
};


class IFactory
{
public:
    virtual IUser * CreateUser() = 0;
    virtual IDepartment * CreateDepartment() = 0;
};

class SqlServerFactory : public IFactory
{
public:
    IUser * CreateUser(){
        return new SqlServerUser();
    }
    IDepartment * CreateDepartment(){
        return new SqlServerDepartment();
    }
};

class AccessFactory : public IFactory
{
public:
    IUser * CreateUser(){
        return new AccessUser();
    }
    IDepartment * CreateDepartment(){
        return new AccessDepartment();
    }
};

void abstract_factory_test(){
    IFactory * factory = new SqlServerFactory();
    
    IUser *iu = factory->CreateUser();
    iu->Insert();
    iu->GetUser();
    
    IDepartment *ip = factory->CreateDepartment();
    ip->Insert();
    ip->GetDepartment();
    
    factory = new AccessFactory();
    iu = factory->CreateUser();
    iu->Insert();
    iu->GetUser();
    
    ip = factory->CreateDepartment();
    ip->Insert();
    ip->GetDepartment();
    
}


#endif /* abstract_factory_h */
