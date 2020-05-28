//
//  CommandConstant.hpp
//  myGame
//
//  Created by Youssef Hanna on 5/25/20.
//

#ifndef CommandConstant_hpp
#define CommandConstant_hpp

#include <stdio.h>
namespace command{


#define CMD_CONFIG_NAME "cmd_load_config"
#define CMD_GUEST_LOGIN "cmd_guest_login"
#define CMD_EMAIL_LOGIN "cmd_email_login"

enum CommandStatus{
  
    COMMAND_WAITING,
    COMMAND_IN_PORGRESS,
    COMMAND_PASSED,
    COMMAND_FAILED
    
};

enum CommandType{
        
    HTTP_COMMAND=0,
    GAMECOMMAND,
    SCREENCOMMAND
    
};

enum CommandIDS {
    LOAD_CONFIG = 0,
    GUEST_LOGIN,
    LOGIN_WITH_EMAIL_PASSWORD
};


class CommandConstant
{
public:
    static std::string commandKeyById(CommandIDS id){
        
        switch (id) {
            case CommandIDS::LOAD_CONFIG:
                return CMD_CONFIG_NAME;
                break;
            case CommandIDS::GUEST_LOGIN:
                return CMD_GUEST_LOGIN;
                break;
            case CommandIDS::LOGIN_WITH_EMAIL_PASSWORD:
                return CMD_EMAIL_LOGIN;
                break;
            default:
                break;
        }
        
    }
    
    
};
}
#endif /* CommandConstant_hpp */
