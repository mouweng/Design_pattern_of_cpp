//
//  Iterator.h
//  迭代器模式
//
//  Created by 翁一帆 on 2019/11/24.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef Iterator_h
#define Iterator_h
#include <string>
#include <vector>

class Iterator
{
public:
    Iterator(){};
    virtual ~Iterator(){};
    virtual string First() = 0;
    virtual string Next() = 0;
    virtual string GetCur() = 0;
    virtual bool IsEnd() = 0;
};

class Aggregate
{
public:
    virtual int Count() = 0;
    virtual void Push(const string& strValue)=0;
    virtual string Pop(const int nIndex)=0;
    virtual Iterator* CreateIterator() = 0;
};

class ConcreteIterator : public Iterator
{
private:
    Aggregate * m_Aggregate;
    int m_nCurrent;
public:
    ConcreteIterator(Aggregate * p_Aggregate):m_nCurrent(0),Iterator()
    {
        m_Aggregate = p_Aggregate;
    }
    string First(){
        return m_Aggregate->Pop(0);
    }
    string Next(){
        string strRet;
        m_nCurrent++;
        if(m_nCurrent < m_Aggregate->Count())
        {
            strRet = m_Aggregate->Pop(m_nCurrent);
        }
        return strRet;
    }
    string GetCur(){
        return m_Aggregate->Pop(m_nCurrent);
    }
    bool IsEnd(){
        return ((m_nCurrent >= m_Aggregate->Count()) ? true: false);
    }
};

class ConcreteAggregate : public Aggregate
{
public:
    ConcreteAggregate():m_pIterator(NULL)
    {
        m_vecItems.clear();
    }
    ~ConcreteAggregate()
    {
        if(NULL != m_pIterator)
        {
            delete m_pIterator;
            m_pIterator = NULL;
        }
    }
    Iterator* CreateIterator()
    {
        if(NULL == m_pIterator)
        {
            m_pIterator = new ConcreteIterator(this);
        }
        return m_pIterator;
    }
    int Count()
    {
        return m_vecItems.size();
    }
    void Push(const string& strValue)
    {
        m_vecItems.push_back(strValue);
    }
    string Pop(const int nIndex)
    {
        string strRet;
        if(nIndex < Count())
        {
            strRet = m_vecItems[nIndex];
        }
        return strRet;
    }
private:
    vector<string> m_vecItems;
    Iterator* m_pIterator;
};

void test(){
    ConcreteAggregate* pName = NULL;
    pName = new ConcreteAggregate();
    if(NULL != pName)
    {
        pName->Push("hello");
        pName->Push("word");
        pName->Push("cxue");
    }
    Iterator* iter = pName->CreateIterator();
    if(NULL != iter)
    {
        string strItem = iter->First();
        while(!iter->IsEnd())
        {
            cout << iter->GetCur() << " is ok" << endl;
            iter->Next();
        }
    }
}



#endif /* Iterator_h */
