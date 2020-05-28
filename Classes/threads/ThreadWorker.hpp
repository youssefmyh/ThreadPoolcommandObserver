//
//  ThreadWorker.hpp
//  myGame
//
//  Created by Youssef Hanna on 12/16/19.
//

#ifndef ThreadWorker_hpp
#define ThreadWorker_hpp

#include <stdio.h>
#include <iostream>
#include <mutex>
#include "ThreadPool.hpp"
#include "../servicelayer/invoker/CommandManager.hpp"
namespace ythreadPool{

class ThreadPool;

class ThreadWorker : public cocos2d::Ref{
public:

    ThreadWorker(int _id,ThreadPool &th_pool):id(_id),m_pool(th_pool){
    }
    
    ~ThreadWorker(){
     }

    void operator ()();
    
private:
    int id;
    ThreadPool & m_pool;
    std::mutex queue_mutex;
};

};
#endif /* ThreadWorker_hpp */
