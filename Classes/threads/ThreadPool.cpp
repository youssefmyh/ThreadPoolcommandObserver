//
//  ThreadPool.cpp
//  myGame
//
//  Created by Youssef Hanna on 12/2/19.
//

#include "ThreadPool.hpp"
ythreadPool::ThreadPool *ythreadPool::ThreadPool::m_instance = nullptr;
std::mutex ythreadPool::ThreadPool::m_pool_lock;
static int count = 0;


ythreadPool::ThreadPool::~ThreadPool(){
    this->notifyAll();
    this->m_avaible = false;

    std::for_each(m_threads->begin(),m_threads->end(),[](std::thread *thread){
        bool isJoinable= thread->joinable();
        if(isJoinable){
        thread->join();
        }
    });
    
    std::for_each(m_workers->begin(),m_workers->end(),[](ThreadWorker *worker){
        delete worker;
    });
    
    m_threads->clear();

    m_workers->clear();

     delete m_threads;
     delete m_workers;
     count = 0;
}

void ythreadPool::ThreadPool::init(){
    m_workers = new std::vector<ythreadPool::ThreadWorker*>();
    m_threads = new std::vector<std::thread*>();
    m_avaible = true;
}

void ythreadPool::ThreadPool::destroy(){
    delete m_instance;
    m_instance = nullptr;
}

bool ythreadPool::ThreadPool::isNewThreadPossible(){

    unsigned int nThread = std::thread::hardware_concurrency();
    
    if(nThread > m_threads->size()){
        return true;
    }
    return false;
    
}

void ythreadPool::ThreadPool::addNewThread(){

    if(!isNewThreadPossible()){
        return;
    }

    if(m_workers == nullptr)
        m_workers = new std::vector<ythreadPool::ThreadWorker*>();

    if(m_threads == nullptr)
        m_threads = new std::vector<std::thread*>();
    count++;
    ThreadWorker *worker = new ThreadWorker(count,std::ref(*this));
    std::thread *th = new std::thread(std::ref(*worker));
    m_threads->push_back(std::move(th));
    m_workers->push_back(std::move(worker));

}

   
