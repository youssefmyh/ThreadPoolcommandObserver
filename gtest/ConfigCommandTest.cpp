//
//  ConfigCommandTest.cpp
//  myGame
//
//  Created by Youssef Hanna on 5/27/20.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include "ConfigCommand.hpp"
class ConfigCommandTest: public testing::Test
{
    
    
};

TEST_F(ConfigCommandTest , CreateNewConfigCommandShouldReturnConfigKey){
    
    ConfigCommand config_cmd;
    EXPECT_EQ(config_cmd.getCommandKey(), CMD_CONFIG_NAME);
}
