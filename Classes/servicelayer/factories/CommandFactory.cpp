//
//  CommandFactory.cpp
//  myGame
//
//  Created by Youssef Hanna on 12/29/19.
//

#include "CommandFactory.hpp"
std::mutex CommandFactory::m_factoryLock;
CommandFactory * CommandFactory::m_instance = nullptr;


command::Command * CommandFactory::getCommandByString(std::string commandKey){
    
    TestCommand * testCommand = new TestCommand();
    testCommand->setCommandKey(commandKey);
    return testCommand;
}
