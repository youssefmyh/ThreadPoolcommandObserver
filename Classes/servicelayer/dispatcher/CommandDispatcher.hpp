//
//  CommandDispatcher.hpp
//  myGame
//
//  Created by youssef hanna on 11/14/19.
//

#ifndef CommandDispatcher_hpp
#define CommandDispatcher_hpp

#include <stdio.h>
#include "../commandbase/Command.hpp"

class CommandDispatcher{
static std::mutex dispatchermutex;

private:
    CommandDispatcher(){

    };

static CommandDispatcher * m_instance;

public:
    static CommandDispatcher * getInstance(){
        
        std::lock_guard<std::mutex> lock(dispatchermutex);
        
        if( m_instance != nullptr)
        {
            m_instance =  new CommandDispatcher();
        }
        return m_instance;
    }
    void dispatchCommand(command::Command *command);
    std::promise<command::CommandResponse> *dispatchCommand(std::string commandKey,command::CommandRequest *CommandRequest);
};
#endif /* CommandDispatcher_hpp */
