//
//  UtilitesTest.cpp
//  myGame
//
//  Created by Youssef Hanna on 9/24/19.
//
#include <gtest/gtest.h>
#include <stdio.h>
#include "../../Classes/utilities/JsonUtilites.hpp"
#include <map>
#include <json/rapidjson.h>
#include <json/document.h>
#include <json/stringbuffer.h>
#include <json/writer.h>
#include <iostream>
#include "../../Classes/servicelayer/exception/GameException.hpp"

class JsonUtilitesTest : public testing::Test
{
    
public:

JsonUtilitesTest(){
}
    
virtual void SetUp() override {
    
}

void TearDown() override
{
    
}

};


TEST_F(JsonUtilitesTest,convertmaptoJson_StringValue_ShouldReturnJson){

    rapidjson::Document document;
    document.SetObject();
    
    std::string key = "test";
    rapidjson::Value value(rapidjson::kStringType);
    value = "Hello Man";

    std::map<std::string, rapidjson::Value*> map;
    
    map.insert(std::pair<std::string, rapidjson::Value*> (key,&value));
    std::string jsonString = JsonUtilites::jsonStringFromMap(&map);
    
    document.Parse(jsonString.c_str());
    
    EXPECT_TRUE(document["test"].IsString());
        
    EXPECT_EQ(document["test"],value);
}

TEST_F(JsonUtilitesTest,convertmaptoJson_NullValue_ShouldThrowGameException){

    std::map<std::string, rapidjson::Value*> *map = nullptr;
          
    EXPECT_THROW(
    {
       JsonUtilites::jsonStringFromMap(map);
        
    }, GameException );
}

TEST_F(JsonUtilitesTest,convertmaptoJson_IntValue_ShouldReturnJsonWithInt){

    rapidjson::Document document;
    document.SetObject();
    
    std::string key = "test";
    rapidjson::Value value(rapidjson::kNumberType);
    value = 1;

    std::map<std::string, rapidjson::Value*> map;
    
    map.insert(std::pair<std::string, rapidjson::Value*> (key,&value));
    std::string jsonString = JsonUtilites::jsonStringFromMap(&map);
    
    document.Parse(jsonString.c_str());
    
    EXPECT_TRUE(document["test"].IsInt());
        
    EXPECT_EQ(document["test"],value);
}

TEST_F(JsonUtilitesTest,convertmaptoJson_DoubleValue_ShouldReturnJsonWithDouble){

    rapidjson::Document document;
    document.SetObject();
    
    std::string key = "test";
    rapidjson::Value value(rapidjson::kNumberType);
    value = 1.0;

    std::map<std::string, rapidjson::Value*> map;
    
    map.insert(std::pair<std::string, rapidjson::Value*> (key,&value));
    std::string jsonString = JsonUtilites::jsonStringFromMap(&map);
    
    document.Parse(jsonString.c_str());
    
    EXPECT_TRUE(document["test"].IsDouble());
        
    EXPECT_EQ(document["test"],value);
}

TEST_F(JsonUtilitesTest,convertmaptoJson_FloatValue_ShouldReturnJsonWithFloat){

    rapidjson::Document document;
    document.SetObject();
    
    std::string key = "test";
    rapidjson::Value value(rapidjson::kNumberType);
    value = 1.0f;

    std::map<std::string, rapidjson::Value*> map;
    
    map.insert(std::pair<std::string, rapidjson::Value*> (key,&value));
    std::string jsonString = JsonUtilites::jsonStringFromMap(&map);
    
    document.Parse(jsonString.c_str());
    
    EXPECT_TRUE(document["test"].IsFloat());
        
    EXPECT_EQ(document["test"],value);
}


TEST_F(JsonUtilitesTest,convertmaptoJson_UIntValue_ShouldReturnJsonWithUInt){

    rapidjson::Document document;
    document.SetObject();
    
    std::string key = "test";
    rapidjson::Value value(rapidjson::kNumberType);
    uint v = 3;
    value = v;

    std::map<std::string, rapidjson::Value*> map;
    
    map.insert(std::pair<std::string, rapidjson::Value*> (key,&value));
    std::string jsonString = JsonUtilites::jsonStringFromMap(&map);
    
    document.Parse(jsonString.c_str());
    
    EXPECT_TRUE(document["test"].IsUint());
        
    EXPECT_EQ(document["test"],value);
}


TEST_F(JsonUtilitesTest,convertmaptoJson_Int64Value_ShouldReturnJsonWithInt64){

    rapidjson::Document document;
    document.SetObject();
    
    std::string key = "test";
    rapidjson::Value value(rapidjson::kNumberType);
    int64_t v = 3;
    value = v;

    std::map<std::string, rapidjson::Value*> map;
    
    map.insert(std::pair<std::string, rapidjson::Value*> (key,&value));
    std::string jsonString = JsonUtilites::jsonStringFromMap(&map);
    
    document.Parse(jsonString.c_str());
    
    EXPECT_TRUE(document["test"].IsUint());
        
    EXPECT_EQ(document["test"],value);
}


TEST_F(JsonUtilitesTest,getOptionalWithBoolTrueShouldReturnBoolTrue){

    rapidjson::Document document;
    document.SetObject();
    
    std::string key = "test";
    rapidjson::Value value(rapidjson::kNumberType);
    bool v = true;
    value = v;

    std::map<std::string, rapidjson::Value*> map;
    
    map.insert(std::pair<std::string, rapidjson::Value*> (key,&value));
    std::string jsonString = JsonUtilites::jsonStringFromMap(&map);
    
    document.Parse(jsonString.c_str());
    
    EXPECT_TRUE(document["test"].IsBool());
        
    EXPECT_EQ(document["test"],value);
    
    std::shared_ptr<bool> ptr = JsonUtilites::getOptional<bool>(document, "test",false);
    
    EXPECT_TRUE(*ptr);
}




TEST_F(JsonUtilitesTest,getOptionalWithWrongKeyShouldReturnOptionalValue){

    rapidjson::Document document;
    document.SetObject();
    
    std::string key = "test";
    rapidjson::Value value(rapidjson::kNumberType);
    int v = 25;
    value = v;

    std::map<std::string, rapidjson::Value*> map;
    
    map.insert(std::pair<std::string, rapidjson::Value*> (key,&value));
    std::string jsonString = JsonUtilites::jsonStringFromMap(&map);
    
    document.Parse(jsonString.c_str());
    
    std::shared_ptr<double> ptr = JsonUtilites::getOptional<double>(document, "tes2t",1.0);
    
    EXPECT_EQ(*ptr,1.0);
}


TEST_F(JsonUtilitesTest,getOptionalWithStringValue){

    rapidjson::Document document;
    document.SetObject();
    
    std::string key = "test";
    rapidjson::Value value(rapidjson::kStringType);
    value = "A";

    std::map<std::string, rapidjson::Value*> map;
    
    map.insert(std::pair<std::string, rapidjson::Value*> (key,&value));
    std::string jsonString = JsonUtilites::jsonStringFromMap(&map);
    
    document.Parse(jsonString.c_str());
  
    std::shared_ptr<std::string> ptr = JsonUtilites::getOptional<std::string>(document, "test","A");
    
    EXPECT_EQ(*ptr,"A");
}


