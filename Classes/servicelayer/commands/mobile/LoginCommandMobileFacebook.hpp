//
//  LoginCommand.hpp
//  myGame
//
//  Created by Youssef Hanna on 5/1/20.
//

#ifndef LoginCommandMobileFacebook_hpp
#define LoginCommandMobileFacebook_hpp

#include <stdio.h>
#include "../../commandbase/Command.hpp"
#ifdef SDKBOX_ENABLED
#include "PluginFacebook/PluginFacebook.h"
#endif
class LoginCommandMobileFacebook : public command::Command, public sdkbox::FacebookListener{

public:
    LoginCommandMobileFacebook()
    :command::Command()
    {
        
    }
    
    void execute(int worker);

    
public:
     void onLogin(bool isLogin, const std::string& msg);
     void onSharedSuccess(const std::string& message);
     void onSharedFailed(const std::string& message);
     void onSharedCancel();
     void onAPI(const std::string& key, const std::string& jsonData);
     void onPermission(bool isLogin, const std::string& msg);
     void onFetchFriends(bool ok, const std::string& msg);
     void onRequestInvitableFriends( const sdkbox::FBInvitableFriendsInfo& friends );
     void onInviteFriendsWithInviteIdsResult( bool result, const std::string& msg );
     void onInviteFriendsResult( bool result, const std::string& msg );

     void onGetUserInfo( const sdkbox::FBGraphUser& userInfo );
  
    
};

#endif /* LoginCommand_hpp */
