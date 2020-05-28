//
//  CommandPatternTest.cpp
//  myGame
//
//  Created by Youssef Hanna on 11/7/19.
//

#include <gtest/gtest.h>
#include "Command.hpp"
#include "CommandDispatcher.hpp"
#include "CommandManager.hpp"
class CommandDispatcherTest : public testing::Test
{

public:
    CommandDispatcherTest(){}
    virtual void SetUp() override{}
    virtual void TearDown() override{}
    
};

TEST_F(CommandDispatcherTest,addCommandWithNullPointerShouldReturnCountZero){
    CommandDispatcher::getInstance()->dispatchCommand(nullptr);
    EXPECT_EQ(CommandManager::getInstance()->size(),0);
    CommandManager::getInstance()->destroy();


}

TEST_F(CommandDispatcherTest,addCommandWithNullCommandKeyReturnCountZero){
    
    CommandDispatcher::getInstance()->dispatchCommand("",nullptr);
    EXPECT_EQ(CommandManager::getInstance()->size(),0);
    CommandManager::getInstance()->destroy();

}

TEST_F(CommandDispatcherTest,addCommandWithTestKeyCountOne){
    
    std::string key = "test";
    CommandDispatcher::getInstance()->dispatchCommand(key,nullptr);
    EXPECT_EQ(CommandManager::getInstance()->size(),1);
    CommandManager::getInstance()->destroy();

}

TEST_F(CommandDispatcherTest,addCommandWithListOfKeyShouldReturnSameSize){
    
    for (int i = 0; i< 10 ; i++) {
        std::string key("test");
        CommandDispatcher::getInstance()->dispatchCommand(key,nullptr);
       

    }
    EXPECT_EQ(CommandManager::getInstance()->size(),10);
    
    CommandManager::getInstance()->destroy();
}
