//
//  LoginCommandMobileFacebook.cpp
//  myGame
//
//  Created by Youssef Hanna on 5/1/20.
//

#include "LoginCommandMobileFacebook.hpp"



void LoginCommandMobileFacebook::execute(int worker){
  
#ifdef SDKBOX_ENABLED
    sdkbox::PluginFacebook::login();
    sdkbox::PluginFacebook::setListener(this);
#endif
    
    
}


void LoginCommandMobileFacebook::onLogin(bool isLogin, const std::string& msg){
    
    
}

void LoginCommandMobileFacebook::onSharedSuccess(const std::string& message){
    
    
}

void LoginCommandMobileFacebook::onSharedFailed(const std::string& message){
    
    
}

void LoginCommandMobileFacebook::onSharedCancel(){
    
    
}

void LoginCommandMobileFacebook::onAPI(const std::string& key, const std::string& jsonData){
    
    
}

void LoginCommandMobileFacebook::onPermission(bool isLogin, const std::string& msg){
    
}

void LoginCommandMobileFacebook::onFetchFriends(bool ok, const std::string& msg){
    
}

void LoginCommandMobileFacebook::onRequestInvitableFriends( const sdkbox::FBInvitableFriendsInfo& friends ){
    
}

void LoginCommandMobileFacebook::onInviteFriendsWithInviteIdsResult( bool result, const std::string& msg ){
    
}

void LoginCommandMobileFacebook::onInviteFriendsResult( bool result, const std::string& msg ){
    
}

void LoginCommandMobileFacebook::onGetUserInfo( const sdkbox::FBGraphUser& userInfo ){
    
    
}

