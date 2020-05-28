//
//  CommandDispatcher.cpp
//  myGame
//
//  Created by youssef hanna on 11/14/19.
//

#include "CommandDispatcher.hpp"
#include "../invoker/CommandManager.hpp"
#include "../factories/CommandFactory.hpp"
std::mutex CommandDispatcher::dispatchermutex;
CommandDispatcher * CommandDispatcher::m_instance = nullptr;

void CommandDispatcher::dispatchCommand(command::Command *command){
    
    if(command == nullptr)
          return ;
    
   CommandManager::getInstance()->addCommand(std::move(command));
    
}

std::promise<command::CommandResponse> * CommandDispatcher::dispatchCommand(std::string commandKey,command::CommandRequest *CommandRequest){
    
    if(commandKey.empty())
        return nullptr;
    
    command::Command * command = CommandFactory::getInstance()->getCommandByString(commandKey);
    std::promise<command::CommandResponse> *cmd_promise = command->getCommandPromise();
    CommandManager::getInstance()->addCommand(std::move(command));
     return cmd_promise;
    
}

