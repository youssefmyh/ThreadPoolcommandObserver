//
//  HttpLoader.cpp
//  myGame
//
//  Created by Youssef Hanna on 9/6/19.
//

#include "HttpLoader.hpp"

HttpLoader *HttpLoader::m_instance = nullptr;

void HttpLoader::sendRequest(cocos2d::network::HttpRequest *httpRequest)
{
    httpRequest->setResponseCallback(this, httpresponse_selector(HttpLoader::onResponseCompleted));
    cocos2d::network::HttpClient::getInstance()->send(httpRequest);
    m_requestList->pushBack(httpRequest);
}

void HttpLoader::onResponseCompleted(cocos2d::network::HttpClient* client, cocos2d::network::HttpResponse* response){
    
    if(response == nullptr){
        return;
    }
    
}





HttpLoader::HttpLoader()
{
    m_requestList = new cocos2d::Vector<cocos2d::network::HttpRequest*>();
    
}

HttpLoader::~HttpLoader(){

    std::vector<cocos2d::network::HttpRequest*>::iterator iterator = m_requestList->end();
   
    while(iterator != m_requestList->begin()){
        delete *iterator;
        iterator--;
    }
    
}
