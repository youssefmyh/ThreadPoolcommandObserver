//
//  CommandAsyncInvoker.hpp
//  myGame
//
//  Created by youssef hanna on 11/14/19.
//

#ifndef CommandManager_hpp
#define CommandManager_hpp

#include <stdio.h>
#include "../commandbase/Command.hpp"


class CommandManager : public cocos2d::Ref{
    
static std::mutex manager_lock;

private:
    CommandManager(){
        m_commandsQueue = new std::queue<command::Command *>;
        m_executedcommandsMap = new std::map<std::string,command::Command *> ();
    }
    static CommandManager * m_instance;
    std::queue<command::Command *> *m_commandsQueue;
    std::map<std::string,command::Command *> *m_executedcommandsMap;
    std::mutex queue_lock;
    std::mutex add_queue_lock;

    
public:
    ~CommandManager(){
        
        while(!m_commandsQueue->empty())
            m_commandsQueue->pop();
        
        m_executedcommandsMap->erase(m_executedcommandsMap->begin(),m_executedcommandsMap->end());
        
        delete m_commandsQueue;
        delete m_executedcommandsMap;
    }
    
    static CommandManager* getInstance(){
        
        std::lock_guard<std::mutex> lock(manager_lock);
        
        if(m_instance == nullptr){
            
            m_instance = new CommandManager();
        }
        return m_instance;
    }
    /*
     Add Command
     **/
    void addCommand(command::Command *command);
    
    /*
     get Next Command to be executed
     */
    command::Command * getNextCommand();
    
    /*
     return the command Queue Size
     @return size
     */
    long size(){
        return m_commandsQueue->size();
    }
    
    void destroy(){
        delete m_instance;
        m_instance = nullptr;
    }
    
};


#endif /* CommandAsyncInvoker_hpp */
