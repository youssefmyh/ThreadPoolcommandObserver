//
//  CommandResponse.hpp
//  myGame-mobile
//
//  Created by Youssef Hanna on 11/7/19.
//

#ifndef CommandResponse_hpp
#define CommandResponse_hpp

#include <stdio.h>
#include <json/rapidjson.h>
#include <json/document.h>
namespace command{

class CommandResponse : public cocos2d::Ref{

public:
    CommandResponse(){
        m_CommandResponseData = new std::map<std::string,rapidjson::Value*>();
        }
        
        ~CommandResponse(){
            if(m_CommandResponseData != nullptr){
                m_CommandResponseData->erase(m_CommandResponseData->begin(), m_CommandResponseData->end());
            }
        }
    
    
    void setCommandKey(std::string key){
        m_commandKey = key;
    }
    
    std::string getCommandKey(){
        return m_commandKey;        
    }
    
    void setWorkerId(int id){
        m_workerId = id;
    }
       
   int getWorkerId(){
           return m_workerId;
   }
    
protected:
        std::map<std::string, rapidjson::Value*> * m_CommandResponseData;
        std::string m_commandKey;
        int m_workerId;
    
};
}
#endif /* CommandResponse_hpp */
