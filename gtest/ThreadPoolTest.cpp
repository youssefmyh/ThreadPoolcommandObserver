//
//  ThreadPoolTest.cpp
//  myGame
//
//  Created by Youssef Hanna on 12/28/19.
//

#include <gtest/gtest.h>
#include "ThreadPool.hpp"
#include "CommandDispatcher.hpp"
class ThreadPoolTest : public testing::Test{
    
public:
    ThreadPoolTest(){}
    virtual void SetUp() override{}
    virtual void TearDown() override{}
    
};


TEST_F(ThreadPoolTest, InitThreadPoolThreadCountAndWorkerShouldbeZero){
    
    ythreadPool::ThreadPool * threadPool = ythreadPool::ThreadPool::getInstance();
    EXPECT_EQ(threadPool->threadCount() ,0);
    EXPECT_EQ(threadPool->workerCount() ,0);
    threadPool->destroy();

    
}

TEST_F(ThreadPoolTest, InitThreadPoolWith3ThreadShouldCreateThreeWorkersand3Thread){
    
    ythreadPool::ThreadPool * threadPool = ythreadPool::ThreadPool::getInstance();
    threadPool->addNewThread();
    threadPool->addNewThread();
    threadPool->addNewThread();
    
    EXPECT_EQ(threadPool->threadCount() ,3);
    EXPECT_EQ(threadPool->workerCount() ,3);
    
    threadPool->destroy();
    
    ythreadPool::ThreadPool * threadPool2 = ythreadPool::ThreadPool::getInstance();
    threadPool2->addNewThread();
    threadPool2->addNewThread();
    threadPool2->addNewThread();
      
     EXPECT_EQ(threadPool2->threadCount() ,3);
     EXPECT_EQ(threadPool2->workerCount() ,3);
     threadPool2->destroy();
       
}


TEST_F(ThreadPoolTest, InitWithOneThreadAndPushedOneCommand){
    
    ythreadPool::ThreadPool * threadPool = ythreadPool::ThreadPool::getInstance();
    threadPool->addNewThread();
    
    EXPECT_EQ(threadPool->threadCount() ,1);
    EXPECT_EQ(threadPool->workerCount() ,1);
    
    std::string commandKey = "test";
    
    std::promise<command::CommandResponse> *commandResponse = CommandDispatcher::getInstance()->dispatchCommand(commandKey, nullptr);
    std::future<command::CommandResponse> cmd_future= commandResponse->get_future();
    cmd_future.wait();
    command::CommandResponse response = cmd_future.get();
    EXPECT_EQ(response.getCommandKey(), commandKey);
    
    threadPool->destroy();
       
}


TEST_F(ThreadPoolTest, InitWith1ThreadAndPushedand2CommandAndShouldReturnCorrectCommandKeyAndOneWorker){
    
    ythreadPool::ThreadPool * threadPool = ythreadPool::ThreadPool::getInstance();
    threadPool->addNewThread();

    EXPECT_EQ(threadPool->threadCount() ,1);
    EXPECT_EQ(threadPool->workerCount() ,1);
    
    std::string commandKey = "test";
    std::string commandKeytest1 = "test1";

    
    std::promise<command::CommandResponse> *commandResponse = CommandDispatcher::getInstance()->dispatchCommand(commandKey, nullptr);
    std::future<command::CommandResponse> cmd_future= commandResponse->get_future();
    cmd_future.wait();
    command::CommandResponse response = cmd_future.get();
    EXPECT_EQ(response.getCommandKey(), commandKey);
    EXPECT_EQ(response.getWorkerId(), 1);

    std::promise<command::CommandResponse> *commandResponsetest2 = CommandDispatcher::getInstance()->dispatchCommand(commandKeytest1, nullptr);
    std::future<command::CommandResponse> cmd_future_forTest2= commandResponsetest2->get_future();
    cmd_future_forTest2.wait();
    command::CommandResponse responseforTest2 = cmd_future_forTest2.get();
    EXPECT_EQ(responseforTest2.getCommandKey(), commandKeytest1);
    EXPECT_EQ(responseforTest2.getWorkerId(), 1);

    threadPool->destroy();
       
}


TEST_F(ThreadPoolTest, InitWith1ThreadAndPushedand3CommandAndShouldReturnOneWorkerId){
    
    ythreadPool::ThreadPool * threadPool = ythreadPool::ThreadPool::getInstance();
    threadPool->addNewThread();

    EXPECT_EQ(threadPool->threadCount() ,1);
    EXPECT_EQ(threadPool->workerCount() ,1);
    
    std::string commandKey = "test";
    std::string commandKeytest1 = "test1";

    
    std::promise<command::CommandResponse> *commandResponse = CommandDispatcher::getInstance()->dispatchCommand(commandKey, nullptr);
    std::future<command::CommandResponse> cmd_future= commandResponse->get_future();
    cmd_future.wait();
    command::CommandResponse response = cmd_future.get();
    EXPECT_EQ(response.getCommandKey(), commandKey);
    EXPECT_LE(response.getWorkerId(), threadPool->threadCount());

    std::promise<command::CommandResponse> *commandResponsetest2 = CommandDispatcher::getInstance()->dispatchCommand(commandKeytest1, nullptr);
    std::future<command::CommandResponse> cmd_future_forTest2= commandResponsetest2->get_future();
    cmd_future_forTest2.wait();
    command::CommandResponse responseforTest2 = cmd_future_forTest2.get();
    EXPECT_EQ(responseforTest2.getCommandKey(), commandKeytest1);
    EXPECT_LE(responseforTest2.getWorkerId(), threadPool->threadCount());
    
    
    std::promise<command::CommandResponse> *commandResponsetest3 = CommandDispatcher::getInstance()->dispatchCommand(commandKeytest1, nullptr);
    std::future<command::CommandResponse> cmd_future_forTest3= commandResponsetest3->get_future();
    cmd_future_forTest3.wait();
    command::CommandResponse responseforTest3 = cmd_future_forTest3.get();
    EXPECT_EQ(responseforTest2.getCommandKey(), commandKeytest1);
    EXPECT_LE(responseforTest2.getWorkerId(), threadPool->threadCount());

    threadPool->destroy();
       
}


TEST_F(ThreadPoolTest, InitWithAlistof100RandomCommandsAndApredefinedCommandShouldReturnCorrectCommandKeyAndWorkerCount){
    
    ythreadPool::ThreadPool * threadPool = ythreadPool::ThreadPool::getInstance();
    threadPool->addNewThread();
    threadPool->addNewThread();

    EXPECT_EQ(threadPool->threadCount() ,2);
    EXPECT_EQ(threadPool->workerCount() ,2);
    
    std::string commandKey = "test";
    std::string commandKeytest1 = "test1";

    for (int i=0; i<100; i++) {
     std::string commandr(cocos2d::StringUtils::format("test %d",i));
     CommandDispatcher::getInstance()->dispatchCommand(commandr, nullptr);
    }
    
    std::promise<command::CommandResponse> *commandResponse = CommandDispatcher::getInstance()->dispatchCommand(commandKey, nullptr);
    std::future<command::CommandResponse> cmd_future= commandResponse->get_future();
    cmd_future.wait();
    command::CommandResponse response = cmd_future.get();
    EXPECT_EQ(response.getCommandKey(), commandKey);
    EXPECT_LE(response.getWorkerId(), threadPool->threadCount());

    std::promise<command::CommandResponse> *commandResponsetest2 = CommandDispatcher::getInstance()->dispatchCommand(commandKeytest1, nullptr);
    std::future<command::CommandResponse> cmd_future_forTest2= commandResponsetest2->get_future();
    cmd_future_forTest2.wait();
    command::CommandResponse responseforTest2 = cmd_future_forTest2.get();
    EXPECT_EQ(responseforTest2.getCommandKey(), commandKeytest1);
    EXPECT_LE(responseforTest2.getWorkerId(), threadPool->threadCount());
    
    
    std::promise<command::CommandResponse> *commandResponsetest3 = CommandDispatcher::getInstance()->dispatchCommand(commandKeytest1, nullptr);
    std::future<command::CommandResponse> cmd_future_forTest3= commandResponsetest3->get_future();
    cmd_future_forTest3.wait();
    command::CommandResponse responseforTest3 = cmd_future_forTest3.get();
    EXPECT_EQ(responseforTest2.getCommandKey(), commandKeytest1);
    EXPECT_LE(responseforTest2.getWorkerId(), threadPool->threadCount());

    threadPool->destroy();
       
}
