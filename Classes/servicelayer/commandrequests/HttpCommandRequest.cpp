//
//  HttpCommandRequest.cpp
//  myGame
//
//  Created by Youssef Hanna on 1/1/20.
//

#include "HttpCommandRequest.hpp"

cocos2d::Ref *HttpCommandRequest::commandRequest(std::string methodPath,network::HttpRequest::Type httpType ,std::map<std::string, rapidjson::Value*> *data)
{
    this->m_CommandRequestData = data;
    return HttpRequestFactory::createRequestFromMap(methodPath, httpType, data, false);
}
