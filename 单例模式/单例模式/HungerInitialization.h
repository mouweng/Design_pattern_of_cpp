//
//  HungerInitialization.h
//  单例模式
//
//  Created by 翁一帆 on 2019/11/24.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef HungerInitialization_h
#define HungerInitialization_h

/*
 饿汉式
 一开始就创建了实例，所以每次用到的之后直接返回就行
 在多线程的情况下会出现问题
 
 */
class CSingleton
{
private:
    CSingleton(){};
public:
    static CSingleton * GetInstance()
    {
        static CSingleton instance;
        return &instance;
    }
}

#endif /* HungerInitialization_h */
