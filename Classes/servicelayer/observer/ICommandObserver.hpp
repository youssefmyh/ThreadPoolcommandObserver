//
//  ICommandObserver.h
//  myGame
//
//  Created by Youssef Hanna on 4/28/20.
//

#ifndef ICommandObserver_h
#define ICommandObserver_h
#include "../commandbase/Command.hpp"
class ICommandObserver {
     
public:
    virtual void notify(command::Command * command) = 0;
};

#endif /* ICommandObserver_h */
