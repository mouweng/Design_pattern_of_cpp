//
//  Command.h
//  命令模式
//
//  Created by 翁一帆 on 2019/11/25.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef Command_h
#define Command_h
#include <vector>

class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command(){};
};

class Hello : public Command
{
public:
    void execute(){
        cout<<"Hello"<<endl;
    }
    virtual ~Hello(){};
};

class World : public Command
{
public:
    void execute(){
        cout<<"World"<<endl;
    }
    virtual ~World(){};
};

class IAm : public Command
{
    public:
    void execute(){
        cout<<"I'm the command pattern"<<endl;
    }
    virtual ~IAm(){};
};

class Macro
{
private:
    vector<Command *> commands;
public:
    void add(Command * c){
        commands.push_back(c);
    }
    void run(){
        for(int i=0;i<commands.size();i++){
            commands[i]->execute();
        }
    }
};

void test(){
    Macro macro;
    macro.add(new Hello());
    macro.add(new World());
    macro.add(new IAm());
    macro.run();
}

#endif /* Command_h */
