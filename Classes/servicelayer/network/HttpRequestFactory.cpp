//
//  QueueLoader.cpp
//  myGame
//
//  Created by Youssef Hanna on 9/20/19.
//

#include "HttpRequestFactory.hpp"
#include <json/rapidjson.h>
using namespace cocos2d;

cocos2d::network::HttpRequest * HttpRequestFactory::createRequestFromMap(std::string url, network::HttpRequest::Type reuqestType , std::map<std::string, rapidjson::Value*> *requestMap, bool multipart = false){
    
    std::vector<std::string> headers;
    if(!multipart){
        
    headers.push_back("Content-Type:application/json; charset=utf-8");
    headers.push_back("Accept:application/json");
        
    }else{
        
    headers.push_back("Content-Type: application/x-www-form-urlencoded");
        
    }

    cocos2d::network::HttpRequest *clientRequest = new cocos2d::network::HttpRequest();
    clientRequest->setRequestType(reuqestType);
    clientRequest->setHeaders(headers);
    if(reuqestType == network::HttpRequest::Type::POST || reuqestType == network::HttpRequest::Type::PUT){
        std::string params = JsonUtilites::jsonStringFromMap(requestMap);
        clientRequest->setRequestData(params.c_str(), strlen(params.c_str()));
    }else
    if(reuqestType == network::HttpRequest::Type::GET)
    {
        url.append(JsonUtilites::urlStringFromMap(requestMap)); // URL Modified to contain formatted URL
    }
    clientRequest->setUrl(url);
    
    return clientRequest;
}



