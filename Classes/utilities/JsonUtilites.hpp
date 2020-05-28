//
//  Utilites.hpp
//  Utilites Class created to generate a json string from Map
//
//  Created by Youssef Hanna on 9/24/19.
//

#ifndef JsonUtilites_hpp
#define JsonUtilites_hpp

#include <cocos2d.h>
#include <stdio.h>
#include <json/rapidjson.h>
#include <json/document.h>
#include <json/stringbuffer.h>
#include <json/writer.h>
#include <iostream>
#include <cassert>
#include "../common/IGenericField.hpp"
#include "../model/common/JsonObject.hpp"
using namespace rapidjson;

class JsonUtilites{

    
//private:
    //JsonUtilites(){} // prevent Objet creation
  
public:
    
    /*Convert a map to json
     @param[in] map std::map is a (string) key and rapisJson Value
     @return json string std::string
     */
    static std::string jsonStringFromMap(std::map<std::string, rapidjson::Value *> *map);
    static std::string jsonStringFromMap(std::map<std::string, IGenericField *> *map);
    
    /*
     Convert Map to string url
     @param[in] map std::map is a (string) key and rapisJson Value
     @return json string std::string
     */
    static std::string urlStringFromMap(std::map<std::string, rapidjson::Value *> *map);

    /* Add value to the rapidjson document based on the value type
     @param[in,out]  document RapidJson which will be modified with the key and value
     @param[in]      key std:string. the json key
     @param[in]      value rapidjson:Value. the json value
     @param[in]      allocator apidjson::Document::AllocatorType
     */
    static void addValueToDocument(rapidjson::Document &document , std::string  key,rapidjson::Value * value,rapidjson::Document::AllocatorType& allocator);
    
    static void addValueToDocument(rapidjson::Document &document , std::string  key,IGenericField * value,rapidjson::Document::AllocatorType& allocator);
    
 
    
    template <typename T>
    static std::shared_ptr<T> getValuefromGenricRapidValue(const rapidjson::Value & value){
        return nullptr;
    }
    
    template<>  std::shared_ptr<std::string> getValuefromGenricRapidValue(const rapidjson::Value & value){
         
         return  std::make_shared<std::string>(value.GetString());
     }
    
    template<>  std::shared_ptr<JsonObject> getValuefromGenricRapidValue(const rapidjson::Value & value){
            
             return  std::make_shared<JsonObject>(value);
        }
    
    template<>  std::shared_ptr<std::vector<JsonObject>> getValuefromGenricRapidValue(const rapidjson::Value & value){
             
              return  std::make_shared<std::vector<JsonObject>>();
         }
    
    template<>  std::shared_ptr<bool> getValuefromGenricRapidValue(const rapidjson::Value & value){
         
         return  std::make_shared<bool>(value.GetBool());
     }
    
    template<>  std::shared_ptr<int> getValuefromGenricRapidValue(const rapidjson::Value & value){
          
          return  std::make_shared<int>(value.GetInt());
      }
    
    template<>  std::shared_ptr<float> getValuefromGenricRapidValue(const rapidjson::Value & value){
          
          return  std::make_shared<float>(value.GetFloat());
      }
    
    template<>  std::shared_ptr<double> getValuefromGenricRapidValue(const rapidjson::Value & value){
          
          return  std::make_shared<double>(value.GetDouble());
      }
    
    template<>  std::shared_ptr<int64_t> getValuefromGenricRapidValue(const rapidjson::Value & value){
          
          return  std::make_shared<int64_t>(value.GetInt64());
      }
    
    template<>  std::shared_ptr<uint64_t> getValuefromGenricRapidValue(const rapidjson::Value & value){
          
        return  std::make_shared<uint64_t>(value.GetUint64());
      }
    
    /**/
    template<typename T>
    static std::shared_ptr<T> get_optional(const rapidjson::Document &document,const char * key, T optionalValue) {

        if(!document.HasMember(key)){
            return std::make_shared<T>(optionalValue);
        }
        const rapidjson::Value &t = document[key];
        
        return getValuefromGenricRapidValue<T>(t);
    }
    
   template <typename T>
   static std::shared_ptr<T> getOptional(const rapidjson::Document &doc,std::string key, T optional){
       return  get_optional<T>(doc, key.c_str(),optional);
    }

};

#endif /* JsonUtilites_hpp */
