//
//  CommandFactory.hpp
//  myGame
//
//  Created by Youssef Hanna on 12/29/19.
//

#ifndef CommandFactory_hpp
#define CommandFactory_hpp

#include <stdio.h>
#include "../commandbase/Command.hpp"
#include "../commands/TestCommand.hpp"
class CommandFactory:public cocos2d::Ref{

static std::mutex m_factoryLock;

public:
    static CommandFactory * getInstance(){
        std::lock_guard<std::mutex> lock(m_factoryLock);
        if(m_instance == nullptr){
            m_instance = new CommandFactory();
        }
        return m_instance;
    }
    
    command::Command * getCommandByString(std::string commandKey);
    
    
   void destroy(){
        delete m_instance;
    }
    
    
private:
    static CommandFactory * m_instance;
    CommandFactory(){}
    
};
#endif /* CommandFactory_hpp */
