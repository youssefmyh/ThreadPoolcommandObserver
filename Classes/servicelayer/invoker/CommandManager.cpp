//
//  CommandAsyncInvoker.cpp
//  myGame
//
//  Created by youssef hanna on 11/14/19.
//

#include "CommandManager.hpp"
#include "../../threads/ThreadPool.hpp"
CommandManager *CommandManager::m_instance = nullptr;
std::mutex CommandManager::manager_lock;

void CommandManager::addCommand(command::Command *command){
    std::lock_guard<std::mutex> lock(add_queue_lock);
    if(command != nullptr){
        m_commandsQueue->push(command);
        ythreadPool::ThreadPool *pool =  ythreadPool::ThreadPool::getInstance();
        pool->notifyOne();
    }
}

command::Command * CommandManager::getNextCommand(){
    command::Command * command = nullptr;
    std::lock_guard<std::mutex> lock(queue_lock);
    if(!m_commandsQueue->empty()){
    command = m_commandsQueue->front();
        if(command->getCommandKey().empty()){
            m_commandsQueue->pop();
        return nullptr;
        }
    m_executedcommandsMap->insert(std::pair<std::string, command::Command*>(command->getCommandKey(),command));
    m_commandsQueue->pop();
    return command;
    }
    return command;
}

