//
//  LazyInitialization.h
//  单例模式
//
//  Created by 翁一帆 on 2019/11/24.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef LazyInitialization_h
#define LazyInitialization_h

//懒汉式
class CSingleton
{
private:
    CSingleton(){};
    static CSingleton * m_pInstance;
public:
    static CSingleton * GetInstance()
    {
        if ( m_pInstance == NULL )
            m_pInstance = new CSingleton();
        return m_pInstance;
    }
}

#endif /* LazyInitialization_h */
