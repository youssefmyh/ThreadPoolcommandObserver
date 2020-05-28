//
//  CommandObserver.hpp
//  myGame
//
//  Created by Youssef Hanna on 12/31/19.
//

#ifndef CommandObserver_hpp
#define CommandObserver_hpp

#include <stdio.h>
#include "ICommandObserver.hpp"
#include <map>

class CommandObserver : public cocos2d::Ref{
    static std::mutex m_commandObserverLock;
public:
    
    static CommandObserver * getInstance(){
        std::lock_guard<std::mutex> _lock(m_commandObserverLock);
        if(m_instance == nullptr)
        {
            m_instance = new CommandObserver();
        }
        return m_instance;
    }
    
    void destroy(){
        delete m_instance;
    }
    
    ~CommandObserver(){
        if(m_observers == nullptr)
            return;
        
        m_observers->erase(m_observers->begin(),m_observers->end());
        m_observers = nullptr;
        m_instance = nullptr;
      }
    
public :
    
    /* Subscribe Command
     subscribe done with Command Pointer not Value
     */
    void subscribe(command::Command * command , ICommandObserver *observer);
    
    /* unsubscribe Command with Observer
     unsubscribe done with Command Pointer not Value
     */
    void unsubscribe(command::Command * command , ICommandObserver *observer);
    
    /*Notify Observer by command**/
    void notifyObservers(command::Command *command);
    
public:
    long size(){
        if(m_observers == nullptr)
            return 0;
            
        return m_observers->size();
    }
    
private:
    
    CommandObserver(){
        m_observers = new std::map<command::Command *, ICommandObserver *>();
    }
    
    static CommandObserver *m_instance;
    std::map<command::Command *, ICommandObserver *> *m_observers;
    
    
    
};
#endif /* CommandObserver_hpp */
