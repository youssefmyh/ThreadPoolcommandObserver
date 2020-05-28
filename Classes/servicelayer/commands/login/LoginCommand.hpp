//
//  LoginCommand.hpp
//  myGame
//
//  Created by Youssef Hanna on 5/23/20.
//

#ifndef LoginCommand_hpp
#define LoginCommand_hpp

#include <stdio.h>
#include "../../commandbase/Command.hpp"
class LoginCommand : public command::Command{
    
public:
    LoginCommand():command::Command()
    {
        setCommandType(command::HTTP_COMMAND);
    }
    
    ~LoginCommand(){
        
    }
    
    virtual void execute(int worker);
    void loginWithFacebook(std::string * facebookToken);
    void loginWithEmail(std::string *email,std::string *password);
    void loginWithGuestAccount();
    

};
#endif /* LoginCommand_hpp */
