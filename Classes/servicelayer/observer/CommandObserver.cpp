//
//  CommandObserver.cpp
//  myGame
//
//  Created by Youssef Hanna on 12/31/19.
//

#include "CommandObserver.hpp"
CommandObserver * CommandObserver::m_instance = nullptr;
std::mutex CommandObserver::m_commandObserverLock;

/* Subscribe Command
 subscribe done with Command Pointer not Value
 */
void CommandObserver::subscribe(command::Command * command , ICommandObserver *observer){
    
    if(command == nullptr || observer == nullptr)
        return;
    
    m_observers->insert(std::pair<command::Command*, ICommandObserver*>(command,observer));
        
    
}

/* unsubscribe Command with Observer
 unsubscribe done with Command Pointer not Value
 */
void CommandObserver::unsubscribe(command::Command * command , ICommandObserver *observer){
   
    if(command == nullptr || observer == nullptr)
           return;
    m_observers->erase(command);
    
}
/* Notify by command*/
void CommandObserver::notifyObservers(command::Command *command){
    
    std::lock_guard<std::mutex> _lock(m_commandObserverLock);

    if(command == nullptr)
        return;
    if(command->getCommmandStatus() == command::CommandStatus::COMMAND_IN_PORGRESS
       || command->getCommmandStatus() == command::CommandStatus::COMMAND_WAITING)
        return;
    
    try {
        
        ICommandObserver * observer = m_observers->at(command);

        if(observer != nullptr){
             observer->notify(command);
         }
         unsubscribe(command, observer);
        
    } catch(const std::out_of_range &e) {

    }
    
    
}

