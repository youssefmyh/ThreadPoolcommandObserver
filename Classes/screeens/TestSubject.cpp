//
//  TestSubject.cpp
//  myGame
//
//  Created by Youssef Hanna on 4/30/20.
//

#include "TestSubject.hpp"

void TestSubject::notify(command::Command * command){
    command::CommandResponse response;
    command->getCommandPromise()->set_value(response);
}
