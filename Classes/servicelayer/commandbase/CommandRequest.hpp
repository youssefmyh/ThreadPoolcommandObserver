//
//  CommandData.hpp
//  myGame-mobile
//
//  Created by Youssef Hanna on 11/7/19.
//

#ifndef CommandRequest_hpp
#define CommandRequest_hpp

#include <stdio.h>
#include <json/rapidjson.h>
#include <json/document.h>
namespace command{

class CommandRequest : public cocos2d::Ref{

public:
    CommandRequest(){
        m_CommandRequestData = new std::map<std::string, rapidjson::Value*>();
    }
    
    ~CommandRequest(){
        if(m_CommandRequestData != NULL){
            m_CommandRequestData->erase(m_CommandRequestData->begin(), m_CommandRequestData->end());
            delete m_CommandRequestData;
        }
    }
    
    virtual Ref* commandRequest(std::map<std::string, std::unique_ptr<rapidjson::Value*>> *m_CommandRequestData);
    virtual Ref* commandRequest(std::string *methodPath,std::map<std::string, std::unique_ptr<rapidjson::Value*>> *m_CommandRequestData);

protected:
    std::map<std::string, rapidjson::Value*> * m_CommandRequestData;

};
}
#endif /* CommandRequest_hpp */
