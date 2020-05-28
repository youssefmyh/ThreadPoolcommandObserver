//
//  TestCommand.hpp
//  myGame
//
//  Created by Youssef Hanna on 12/29/19.
//

#ifndef TestCommand_hpp
#define TestCommand_hpp

#include <stdio.h>
#include <iostream>
#include "../commandbase/Command.hpp"
#include "../commandbase/CommandRequest.hpp"

class TestCommand :public command::Command{
    
    
public:
    TestCommand():command::Command()
    {
    }
    
    ~TestCommand()
     {
     }
   virtual void execute(int worker);

};
#endif /* TestCommand_hpp */
