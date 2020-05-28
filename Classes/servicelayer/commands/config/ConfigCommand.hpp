//
//  ConfigCommand.hpp
//  myGame
//
//  Created by Youssef Hanna on 5/25/20.
//

#ifndef ConfigCommand_hpp
#define ConfigCommand_hpp

#include <stdio.h>
#include "../../commandbase/Command.hpp"
#include "../../commandbase/CommandConstant.hpp"
#include "../../commandrequests/HttpCommandRequest.hpp"
#include ""
class ConfigCommand: public command::Command{

public:
    ConfigCommand():command::Command(){
        
        setCommandType(command::HTTP_COMMAND);
        setCommandKey(command::CommandConstant::commandKeyById(command::CommandIDS::LOAD_CONFIG));
        
        m_CommandRequest = HttpCommandRequest::commandRequest(<#std::string methodPath#>, <#network::HttpRequest::Type reuqestType#>, <#std::map<std::string, rapidjson::Value *> *data#>)
    }


public:
    virtual void execute(int worker);
    
    
};
#endif /* ConfigCommand_hpp */
