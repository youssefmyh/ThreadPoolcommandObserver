//
//  TestCommand.cpp
//  myGame
//
//  Created by Youssef Hanna on 12/29/19.
//

#include "TestCommand.hpp"
#include "../observer/CommandObserver.hpp"
void TestCommand::execute(int worker){
    
    
    std::string key = getCommandKey();
    command::CommandResponse response = getCommandResponse();
    response.setCommandKey(key);
    response.setWorkerId(worker);
    getCommandPromise()->set_value(response);
    setCommmandStatus(command::COMMAND_PASSED);

    
    

}
