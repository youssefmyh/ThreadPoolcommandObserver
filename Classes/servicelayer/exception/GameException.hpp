//
//  GameException.hpp
//  myGame
//
//  Created by Youssef Hanna on 10/9/19.
//

#ifndef GameException_hpp
#define GameException_hpp

#include <stdio.h>
#include <exception>
enum ExceptionCode {
    
     G_NULLPOINTER = 1400,
     G_INCORRECT_VALUE = 1401,
     G_INVALID_INDEX = 1402,
     G_INVALID_COMMAND_STATUS = 1403
};

class GameException: public std::exception {
     
    public:
    GameException(const char * description,int codeError):m_description(description),m_errorCode(codeError){
    }
    ~GameException(){}
    /* return what reason*/
    virtual const char *  what() const throw () { return m_description.c_str();}
    virtual int const code()const { return m_errorCode;}

   
    
private:
    std::string m_description;
    int m_errorCode;
    
};

#endif /* GameException_hpp */
