//
//  QueueLoader.hpp
//  myGame
//
//  Created by Youssef Hanna on 9/20/19.
//

#ifndef QueueLoader_hpp
#define QueueLoader_hpp

#include <stdio.h>
#include "CommonMacros.hpp"
#include "HttpLoader.hpp"
#include <cocos2d.h>
#include <json/rapidjson.h>
#include <json/document.h>
#include "../../utilities/JsonUtilites.hpp"

USING_NS_CC;

class HttpRequestFactory{
      
public:
    
    HttpRequestFactory(){
        
        
    }
    
    ~HttpRequestFactory(){
        
    }
    /*Create a request from Map
     @param map
     */
    static cocos2d::network::HttpRequest * createRequestFromMap(std::string url,network::HttpRequest::Type reuqestType,std::map<std::string, rapidjson::Value*> *requestMap,bool multipart) ;
    

    
};

#endif /* QueueLoader_hpp */
