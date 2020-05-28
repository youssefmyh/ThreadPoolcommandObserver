//
//  HttpFactoryTest.cpp
//  myGame-desktopTests
//
//  Created by Youssef Hanna on 2/4/20.
//

#include <gtest/gtest.h>

/*
 static cocos2d::network::HttpRequest * createRequestFromMap
 (
 std::string url,
 network::HttpRequest::Type,
 reuqestType,std::map<std::string*, rapidjson::Value*> *requestMap,
 bool multipart);
 */

class HttpFactoryTest : public testing::Test{
    
public:
    HttpFactoryTest(){}
    virtual void setup(){}
    virtual void TearDown(){}
    
};

TEST_F(HttpFactoryTest, CreateRequestWithNullURLShouldThrowExcepion){
    
    
}

TEST_F(HttpFactoryTest, CreateRequestWithNullEmptyTypeShouldThrowExcepion){
    
    
}


TEST_F(HttpFactoryTest, CreateRequestWithNullMapShouldThrowExcepion){
    
    
}

TEST_F(HttpFactoryTest, CreateRequestWithFalseMultipartMapShouldbeOk){
    
    
}

TEST_F(HttpFactoryTest, CreateRequestWithTrueMultipartMapShouldbeOk){
    
    
}


TEST_F(HttpFactoryTest, CreateRequestWithEmptyMapShouldBeOk){
    
    
}


TEST_F(HttpFactoryTest, CreateRequestWithMapAndGetFunction){
    
    
}


TEST_F(HttpFactoryTest, CreateRequestWithMapAndPOSTFunction){
    
    
}


TEST_F(HttpFactoryTest, CreateRequestWithMapAndMultiPart){
    
    
}
