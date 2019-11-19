//
//  example_observer.h
//  观察者模式
//
//  Created by 翁一帆 on 2019/11/19.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef example_observer_h
#define example_observer_h


class ITeacherListenner{
public:
    virtual void onTecherComming(int value) = 0;
};

class INotifier
{
public:
    virtual void registerListenner(ITeacherListenner *l) =0 ;
    virtual void removeListenner(ITeacherListenner *l) =0 ;
    virtual void notify() =0 ;
};


class MonitorNotifier : public INotifier
{
private:
    list<ITeacherListenner *> listenners;
    int mValue;
public:
    void registerListenner(ITeacherListenner *l){
        listenners.push_back(l);
    }
    void removeListenner(ITeacherListenner *l){
        list<ITeacherListenner *>::iterator it;
        for(it = listenners.begin(); it != listenners.end(); it++){
            if(*it == l){
                listenners.remove(l);
                break;
            }
        }
    }
    void notify(){
        list<ITeacherListenner *>::iterator it;
        for(it = listenners.begin(); it != listenners.end(); it++){
            (*it)->onTecherComming(mValue);
        }
    }
    void setValue(int value){
        mValue = value;
        notify();
    }
};


class ZhangSan : public ITeacherListenner
{
public:
    void onTecherComming(int value){
        stopCopyWork(value);
    }
    void stopCopyWork(int value)
    {
        cout<<"zhangsan stopCopyWork + "<<value<<endl;
    }
};

class LiSi : public ITeacherListenner
{
public:
    void onTecherComming(int value){
        stopPlayGame(value);
    }
    void stopPlayGame(int value)
    {
        cout<<"lisi stopPlayGame + "<<value<<endl;
    }
};

void test(){
    MonitorNotifier monitor;
    ZhangSan zs;
    LiSi ls;
    monitor.registerListenner(&zs);
    monitor.registerListenner(&ls);
    monitor.setValue(1);
    
    monitor.removeListenner(&ls);
    monitor.setValue(2);
}

#endif /* example_observer_h */
