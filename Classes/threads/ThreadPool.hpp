//
//  ThreadPool.hpp
//  myGame
//
//  Created by Youssef Hanna on 12/2/19.
//

#ifndef ThreadPool_hpp
#define ThreadPool_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <mutex>
#include <future>
#include <condition_variable>
#include "ThreadWorker.hpp"

namespace ythreadPool{

class ThreadWorker;

class ThreadPool{

public:
    static std::mutex m_pool_lock;

    static ThreadPool * getInstance(){
        std::lock_guard<std::mutex> guard(m_pool_lock);
        if(m_instance == nullptr){
            m_instance = new ThreadPool();
            m_instance->init();
        }
        return m_instance;
    }
    
    ~ThreadPool();
   
    /*
     Check The Max number of threads
     Init with half of the max Threads
    */
    void init();
    
    /*
     destroy item
     */
    void destroy();
    /*
     Check if we can init new thread
     Get the Max thread - Vector size
     */
    bool isNewThreadPossible();
    
    /*
     add new thread to the pool
     */
    void addNewThread();
    
    /*
     Check if the thread should still running
     */
    bool isAvaiable(){
        return m_avaible;
    }
    
    /*
     Notify one thread
     */
    void notifyOne(){
        m_condition.notify_one();
    }
    /*
      Notify All threads
    */
    void notifyAll(){
        m_condition.notify_all();
    }
    
    /*
      Number of thread
    */
    unsigned long threadCount(){
        return m_threads->size();
    }
    
    /*
         Number of thread
    */
    unsigned long  workerCount(){
        return m_workers->size();
    }
    
private:
    friend class ThreadWorker;
    std::mutex queue_mutex;
    static ThreadPool *m_instance; // thread Instance
    bool m_avaible; // this to disable the workers
    std::vector<std::thread*> *m_threads; // threads vector
    std::vector<ythreadPool::ThreadWorker*> *m_workers; // threads vector
    ThreadPool(){}
    std::condition_variable m_condition; // condition to handle the worker
};
}

#endif /* ThreadPool_hpp */


