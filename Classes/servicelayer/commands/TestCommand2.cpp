//
//  TestCommand2.cpp
//  myGame
//
//  Created by Youssef Hanna on 4/30/20.
//

#include "TestCommand2.hpp"
#include "../observer/CommandObserver.hpp"

void TestCommand2::execute(int worker){
    
    std::string key = getCommandKey();
    command::CommandResponse response = getCommandResponse();
    response.setCommandKey(key);
    response.setWorkerId(worker);
    setCommmandStatus(command::COMMAND_PASSED);

    CommandObserver::getInstance()->notifyObservers(this);
    
}
