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
#include "TestCommand.hpp"
class CommandManagerTest : public testing::Test
{

public:
    CommandManagerTest(){}
    virtual void SetUp() override{}
    virtual void TearDown() override{}
    
};

TEST_F(CommandManagerTest,addCommandWithNullPointerShouldReturnCountZero){
    CommandManager::getInstance()->addCommand(nullptr);
    EXPECT_EQ(CommandManager::getInstance()->size(),0);
    CommandManager::getInstance()->destroy();


}



TEST_F(CommandManagerTest,addCommandWithTestKeyCountOne){
    
    std::string key("test");
    TestCommand testCommand;
    testCommand.setCommandKey(std::move(key));
    CommandManager::getInstance()->addCommand(&testCommand);
    EXPECT_EQ(CommandManager::getInstance()->size(),1);
    CommandManager::getInstance()->destroy();

}

TEST_F(CommandManagerTest,addCommandWithListOfKeyShouldReturnSameSize){
    
    for (int i = 0; i< 10 ; i++) {
        std::string key("test");
        TestCommand testCommand;
        testCommand.setCommandKey(std::move(key));
        CommandManager::getInstance()->addCommand(&testCommand);
    }
    EXPECT_EQ(CommandManager::getInstance()->size(),10);
     CommandManager::getInstance()->destroy();
}


TEST_F(CommandManagerTest,addCommandAndGetNextShouldReturnSizeZero){
    
    std::string key("test1");
    TestCommand testCommand;
    testCommand.setCommandKey(std::move(key));
    CommandManager::getInstance()->addCommand(&testCommand);
    EXPECT_EQ(CommandManager::getInstance()->size(),1);
    CommandManager::getInstance()->getNextCommand();
    EXPECT_EQ(CommandManager::getInstance()->size(),0);

    CommandManager::getInstance()->destroy();
}

TEST_F(CommandManagerTest,addCommandPushTwoCommandGetNextShouldReturntheFirstOne){
    
    std::string key ("test1");
    TestCommand testCommand;
    testCommand.setCommandKey(std::move(key));
    std::string key2("test2");
    TestCommand testCommand2;
    testCommand2.setCommandKey(std::move(key2));

    CommandManager::getInstance()->addCommand(&testCommand);
    CommandManager::getInstance()->addCommand(&testCommand2);

    EXPECT_EQ(CommandManager::getInstance()->size(),2);
    command::Command *firstCommand = CommandManager::getInstance()->getNextCommand();
    EXPECT_EQ(firstCommand->getCommandKey(), "test1");
    EXPECT_EQ(CommandManager::getInstance()->size(),1);

    CommandManager::getInstance()->destroy();
}

