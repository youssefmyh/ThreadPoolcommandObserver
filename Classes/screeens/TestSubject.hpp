//
//  TestSubject.hpp
//  myGame
//
//  Created by Youssef Hanna on 4/30/20.
//

#ifndef TestSubject_hpp
#define TestSubject_hpp
#include "../servicelayer/observer/ICommandObserver.hpp"
#include <stdio.h>
class TestSubject: public cocos2d::Ref , public ICommandObserver{
  
public:
    TestSubject(){
        
    }
    ~TestSubject(){
        
    }
    
    
    virtual void notify(command::Command * command);

};
#endif /* TestSubject_hpp */
