//
//  Command.hpp
//  myGame
//
//  Created by Youssef Hanna on 9/19/19.
//  Command class encapsulate all the command data
//  

#ifndef Command_hpp
#define Command_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "CommandResponse.hpp"
#include "CommandRequest.hpp"
#include "CommandConstant.hpp"
/*
 Command namesoace to handle the Command pattern
 */
namespace command{




class Command{
    
public:
    
    Command(){
        setCommmandStatus(COMMAND_WAITING);
        m_CommandRequest = nullptr;
    }
    
    ~Command(){
        if(m_CommandRequest != nullptr)
        delete m_CommandRequest;
    }
    
     /*
      @return * Ref command response
     */
     CommandRequest * getCommandRequest(){
         return m_CommandRequest;
     }
    
    /*
     @return * Ref command response
    */
    CommandResponse  getCommandResponse(){
        return m_commandResponse;
    }
    
    /*
     @return String Command unique key
    */
    std::string getCommandKey(){
        return m_commandkey;
    }
    
    /*
     @return String Command unique key
     */
     void setCommandKey(std::string key){
           this->m_commandkey = key;
    }
    
    /*
     Set Command Status
     */
    void setCommmandStatus(CommandStatus status){
        m_status = status;
    }
    /*
     Get Command Status
     */
     CommandStatus getCommmandStatus(){
        return m_status;
    }
    /*
     Set Command type
     */
    void setCommandType(CommandType type){
        m_type = type;
    }
    /*
     Get Command Type
     */
    CommandType getCommandType(){
        return m_type;
    }
    
    std::promise<CommandResponse> *getCommandPromise()  {
        return &m_promise;
    }
    
    
    /*
    execute the command
     */
    virtual void execute(int worker) = 0;

private:
    /*Command Response*/
    CommandResponse m_commandResponse;
    /*Command Request*/
    CommandRequest * m_CommandRequest;
    /*Command Key*/
    std::string m_commandkey;
    /* Command status */
    CommandStatus m_status;
    /*Command Type for dispatcher*/
    CommandType m_type;
    /* Command Promise*/
    std::promise<CommandResponse> m_promise;
    
    
    /*Test Data for Thread and worker Number*/
    long m_threadNumber;
    /**/
    int m_workerNumber;
    
public:
    void setThreadNumber(uint64_t threadNumber){
        m_threadNumber = threadNumber;
    }
    
    void setWorkerNumber(int worker_number){
        m_workerNumber = worker_number;
    }
    
    uint64_t getThreadNumber(){
        return  m_threadNumber;
      }
     
    int getWorkerNumber(){
        return  m_workerNumber;
    }
    
};
}
#endif /* Command_hpp */
