//
//  TestCommand2.hpp
//  myGame
//
//  Created by Youssef Hanna on 4/30/20.
//

#ifndef TestCommand2_hpp
#define TestCommand2_hpp

#include <stdio.h>
#include "../commandbase/Command.hpp"
class TestCommand2 : public command::Command{

public:
    TestCommand2()
    {
    }
public:
    virtual void execute(int worker);

    
};
#endif /* TestCommand2_hpp */
