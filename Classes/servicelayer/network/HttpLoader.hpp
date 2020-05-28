//
//  HttpLoader.hpp
//  myGame
//
//  Created by Youssef Hanna on 9/6/19.
//

#ifndef HttpLoader_hpp
#define HttpLoader_hpp

#include <stdio.h>
#include <cocos2d.h>
#include <network/HttpClient.h>
#include "CommonMacros.hpp"
#include <iostream>
#include "../exception/GameException.hpp"
class HttpLoader : public cocos2d::Ref {


private:
    HttpLoader();
    
    /*Vector to save the request list*/
    cocos2d::Vector<cocos2d::network::HttpRequest *> *m_requestList;
    /* Constructor to init the request list*/
    
    /* Send a request and return the response*/
    void sendRequest(cocos2d::network::HttpRequest *httpRequest);
    void onResponseCompleted(cocos2d::network::HttpClient* client, cocos2d::network::HttpResponse* response);
    static HttpLoader * m_instance;
    
public:
    ~HttpLoader();

    static HttpLoader * getInstance(){
        
        if(m_instance == nullptr){
            m_instance = new HttpLoader();
        }
        return m_instance;
        
    }
    
    
};


#endif /* HttpLoader_hpp */
