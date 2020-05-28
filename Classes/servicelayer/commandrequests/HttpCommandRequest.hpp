//
//  HttpCommandRequest.hpp
//  myGame
//
//  Created by Youssef Hanna on 1/1/20.
//

#ifndef HttpCommandRequest_hpp
#define HttpCommandRequest_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "../commandbase/CommandRequest.hpp"
#include "../../utilities/JsonUtilites.hpp"
#include "../../servicelayer/network/HttpRequestFactory.hpp"
class HttpCommandRequest : public command::CommandRequest
{

public:
    HttpCommandRequest(){

    }
    ~HttpCommandRequest(){}
    cocos2d::Ref* commandRequest(std::string methodPath,network::HttpRequest::Type reuqestType,std::map<std::string, rapidjson::Value*> *data);
private:

};
#endif /* HttpCommandRequest_hpp */
