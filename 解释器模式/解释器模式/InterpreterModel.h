//
//  InterpreterModel.h
//  解释器模式
//
//  Created by 翁一帆 on 2019/11/25.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef InterpreterModel_h
#define InterpreterModel_h
#include <string>

class Context
{
private:
    string m_strInput;
    string m_strOutput;
public:
    void setExpression(string str){
        this->m_strInput = str;
    }
};

class Expression
{
public:
    virtual void Interpret(Context * context) = 0;
};

class TerminalExpression : public Expression
{
public:
    void Interpret(Context * content){
        cout<<"TerminalExpression!"<<endl;
    }
};

class NonterminalExpression : public Expression
{
public:
    void Interpret(Context * content){
        cout<<"NonterminalExpression!"<<endl;
    }
};

void test(){
    Context * pContext = new Context();
    pContext->setExpression("Expression....");
    Expression * pNon = new NonterminalExpression();
    Expression * p = new TerminalExpression();
    
    // 根据Expression中的内容判断采用那种表达式解析
    pNon->Interpret(pContext);
    p->Interpret(pContext);

    
}

#endif /* InterpreterModel_h */
