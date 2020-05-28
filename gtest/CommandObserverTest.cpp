//
//  CommandPatternTest.cpp
//  myGame
//
//  Created by Youssef Hanna on 11/7/19.
//

#include <gtest/gtest.h>
#include "Command.hpp"
#include "CommandObserver.hpp"
#include "CommandFactory.hpp"
#include "TestSubject.hpp"
#include "TestCommand2.hpp"

class CommandObserverTest : public testing::Test
{

public:
    CommandObserverTest(){}
    virtual void SetUp() override{}
    virtual void TearDown() override{}
    
};

TEST_F(CommandObserverTest,subscribeNullCommandShouldReturnZero){
    
    CommandObserver::getInstance()->subscribe(nullptr, nullptr);
    EXPECT_EQ(CommandObserver::getInstance()->size(),0);
    CommandObserver::getInstance()->destroy();
}


TEST_F(CommandObserverTest,subscribeWithNullObserverShouldReturnSizeZero){
    
    std::string test = "test";
    command::Command *testCommand = CommandFactory::getInstance()->getCommandByString(test);
    CommandObserver::getInstance()->subscribe(testCommand, nullptr);
    EXPECT_EQ(CommandObserver::getInstance()->size(),0);
    CommandObserver::getInstance()->destroy();
}


TEST_F(CommandObserverTest,subscribeWithCommandAndObserverShouldReturnSizeOne){
    
    std::string test = "test";
    command::Command *testCommand = CommandFactory::getInstance()->getCommandByString(test);
    CommandObserver::getInstance()->subscribe(testCommand, new TestSubject());
    EXPECT_EQ(CommandObserver::getInstance()->size(),1);
    CommandObserver::getInstance()->destroy();
}


TEST_F(CommandObserverTest,subscribeThenUnSubscribeShouldReturnSizeZero){
    
    std::string test = "test";
    command::Command *testCommand = CommandFactory::getInstance()->getCommandByString(test);
    TestSubject *subject = new TestSubject();
    CommandObserver::getInstance()->subscribe(testCommand, subject);
    
    CommandObserver::getInstance()->unsubscribe(testCommand, subject);

    EXPECT_EQ(CommandObserver::getInstance()->size(),0);
    CommandObserver::getInstance()->destroy();
}


TEST_F(CommandObserverTest,subscribeWithTheSameCommandMultipleTimeShouldReturnOne){
    
    std::string test = "test";
    command::Command *testCommand = CommandFactory::getInstance()->getCommandByString(test);
    TestSubject *subject = new TestSubject();
    CommandObserver::getInstance()->subscribe(testCommand, subject);
    
    CommandObserver::getInstance()->subscribe(testCommand, subject);

    EXPECT_EQ(CommandObserver::getInstance()->size(),1);
    CommandObserver::getInstance()->destroy();
}


TEST_F(CommandObserverTest,subscribeAndNotifyWithDefaultStatusShouldReturnOne){
    
    std::string test = "test";
    command::Command *testCommand = CommandFactory::getInstance()->getCommandByString(test);
    TestSubject *subject = new TestSubject();
    
    
    CommandObserver::getInstance()->subscribe(testCommand, subject);

    CommandObserver::getInstance()->notifyObservers(testCommand);
    
    EXPECT_EQ(CommandObserver::getInstance()->size(),1);
    CommandObserver::getInstance()->destroy();
}

TEST_F(CommandObserverTest,subscribeAndNotifyWithFAILEDStatusShouldReturnZero){
    
    std::string test = "test";
    command::Command *testCommand = CommandFactory::getInstance()->getCommandByString(test);
    TestSubject *subject = new TestSubject();
    
    
    CommandObserver::getInstance()->subscribe(testCommand, subject);
    testCommand->setCommmandStatus(command::COMMAND_FAILED);
    CommandObserver::getInstance()->notifyObservers(testCommand);
    
    EXPECT_EQ(CommandObserver::getInstance()->size(),0);
    CommandObserver::getInstance()->destroy();
}

TEST_F(CommandObserverTest,subscribeAndNotifyWithPASSESStatusShouldReturnZero){
    
    std::string test = "test";
    command::Command *testCommand = CommandFactory::getInstance()->getCommandByString(test);
    TestSubject *subject = new TestSubject();
    
    
    CommandObserver::getInstance()->subscribe(testCommand, subject);
    testCommand->setCommmandStatus(command::COMMAND_PASSED);
    CommandObserver::getInstance()->notifyObservers(testCommand);
    
    EXPECT_EQ(CommandObserver::getInstance()->size(),0);
    CommandObserver::getInstance()->destroy();
}


TEST_F(CommandObserverTest,subscribeAndNotifyWithINPrgressStatusShouldReturnOne){
    
    std::string test = "test";
    command::Command *testCommand = CommandFactory::getInstance()->getCommandByString(test);
    TestSubject *subject = new TestSubject();
    
    
    CommandObserver::getInstance()->subscribe(testCommand, subject);
    testCommand->setCommmandStatus(command::COMMAND_IN_PORGRESS);
    CommandObserver::getInstance()->notifyObservers(testCommand);
    
    EXPECT_EQ(CommandObserver::getInstance()->size(),1);
    CommandObserver::getInstance()->destroy();
}


TEST_F(CommandObserverTest,executeCommandAndNotifyObserverCountShouldbeZero){
    
    std::string test = "test";
    command::Command *testCommand = CommandFactory::getInstance()->getCommandByString(test);
    TestSubject *subject = new TestSubject();
    
    
    CommandObserver::getInstance()->subscribe(testCommand, subject);
    testCommand->setCommmandStatus(command::COMMAND_IN_PORGRESS);
    testCommand->execute(0);
    //CommandObserver::getInstance()->notifyObservers(testCommand);
    
    EXPECT_EQ(CommandObserver::getInstance()->size(),1);
    CommandObserver::getInstance()->destroy();
}


TEST_F(CommandObserverTest,executeCommandAndNotifyObserverCountShouldReturnZero){
    
    std::string test = "test";
    TestCommand2 *command2 = new TestCommand2();
    command2->setCommandKey(test);
   // command::Command *testCommand = CommandFactory::getInstance()->getCommandByString(&test);
    TestSubject *subject = new TestSubject();
    
    
    CommandObserver::getInstance()->subscribe(command2, subject);
    command2->setCommmandStatus(command::COMMAND_PASSED);
    command2->execute(0);
    command2->getCommandPromise()->get_future().wait();
    //CommandObserver::getInstance()->notifyObservers(testCommand);
    
    EXPECT_EQ(CommandObserver::getInstance()->size(),0);
    CommandObserver::getInstance()->destroy();
}


TEST_F(CommandObserverTest,subscribeListOfTenCommandsShouldReturnTen){
    
    for (int i=0; i< 10; i++) {
       std::string test = "test";
       
        TestCommand2 *command2 = new TestCommand2();
        command2->setCommandKey(test);
        TestSubject *subject = new TestSubject();
            
        CommandObserver::getInstance()->subscribe(command2, subject);
        command2->setCommmandStatus(command::COMMAND_PASSED);
                
    }
  
    
    
    //CommandObserver::getInstance()->notifyObservers(testCommand);
    
    EXPECT_EQ(CommandObserver::getInstance()->size(),10);
    CommandObserver::getInstance()->destroy();
}

TEST_F(CommandObserverTest,subscribeListOfCommands2WithNotifyShouldReturnSizeZero){
    
    for (int i=0; i< 1000; i++) {
       std::string test = "test";
       
        TestCommand2 *command2 = new TestCommand2();
        command2->setCommandKey(test);
        TestSubject *subject = new TestSubject();
            
        CommandObserver::getInstance()->subscribe(command2, subject);
        command2->setCommmandStatus(command::COMMAND_PASSED);
        command2->execute(0);
        
        command2->getCommandPromise()->get_future().wait();
        
    }
  
    
    
    //CommandObserver::getInstance()->notifyObservers(testCommand);
    
    EXPECT_EQ(CommandObserver::getInstance()->size(),0);
    CommandObserver::getInstance()->destroy();
}



