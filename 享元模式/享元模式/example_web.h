//
//  example_web.h
//  享元模式
//
//  Created by 翁一帆 on 2019/11/25.
//  Copyright © 2019 mouweng. All rights reserved.
//

#ifndef example_web_h
#define example_web_h
#include<string>
#include<map>

class User
{
private:
    string name;
public:
    User(string name){
        this->name = name;
    }
    string GetName(){
        return (this->name);
    }
};


class WebSite
{
public:
    virtual void Use(User * user) = 0;
};

//具体网站类
class ConcreteWebSite : public WebSite
{
private:
    string name = "";
public:
    ConcreteWebSite(string name){
        this->name = name;
    }
    void Use(User * user){
        cout<<"网站分类："<<name<<"  用户：" <<user->GetName()<<endl;
    }
};

//网站工厂类
class WebSiteFactory
{
private:
    map<string, ConcreteWebSite *> flyweights;
public:
    //获得网站的分类
    WebSite * GetWebSiteCategory(string key)
    {
        if(flyweights.count(key)==0){
            flyweights[key] = new ConcreteWebSite(key);
        }
        return flyweights[key];
    }
    int GetWebSiteCount()
    {
        return flyweights.size();
    }
};


void example_test(){
    WebSiteFactory *f = new WebSiteFactory();
    
    WebSite *fx = f->GetWebSiteCategory("产品展示");
    fx->Use(new User("wyf"));
    
    WebSite *fy = f->GetWebSiteCategory("产品展示");
    fy->Use(new User("yf"));
    
    WebSite *fz = f->GetWebSiteCategory("产品展示");
    fz->Use(new User("wf"));
    
    WebSite *fl = f->GetWebSiteCategory("博客");
    fl->Use(new User("ff"));
    
    WebSite *fm = f->GetWebSiteCategory("博客");
    fm->Use(new User("kk"));
    
    WebSite *fn = f->GetWebSiteCategory("博客");
    fn->Use(new User("zz"));
    
    cout<<"网站的总数:"<<f->GetWebSiteCount()<<endl;
}


#endif /* example_web_h */
