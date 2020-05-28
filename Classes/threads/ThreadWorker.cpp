//
//  ThreadWorker.cpp
//  myGame
//
//  Created by Youssef Hanna on 12/16/19.
//

#include "ThreadWorker.hpp"
#include "ThreadPool.hpp"
void ythreadPool::ThreadWorker::operator ()(){
    
    
    while(m_pool.isAvaiable()){
        
        //std::lock_guard<std::mutex> lock(m_pool.queue_mutex);
        std::unique_lock<std::mutex> lock(queue_mutex);
        CommandManager *commandManager = CommandManager::getInstance();

        command::Command *command = commandManager->getNextCommand();
        if(command != nullptr){
            command->execute(id);
        }
      
        std::cout<< "before wait worker"<< std::this_thread::get_id()<< "  With ID "<< id <<std::endl;
        if(!m_pool.isAvaiable())
            return;
        m_pool.m_condition.wait(lock,[this]{return m_pool.isAvaiable();}); // add lock flag
        
        std::cout<< "\nthis comming After from worker"<< std::this_thread::get_id()<< "  With ID "<< id <<std::endl;
        
     //   m_pool.queue_mutex.unlock();
      //  std::this_thread::sleep_for(std::chrono::seconds(1));
    }
        std::cout<< "\nShutdown worker worker"<< std::this_thread::get_id()<<std::endl;
    
}

