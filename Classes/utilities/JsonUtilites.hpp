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
#include <memory>
#include <vector>
#include <json/rapidjson.h>
#include <json/document.h>
#include <json/stringbuffer.h>
#include <json/writer.h>
#include <iostream>
#include <cassert>
#include "../common/IGenericField.hpp"
#include "../model/common/JsonObject.hpp"
#include "../common/IModel.hpp"

using namespace rapidjson;

class JsonUtilites{

    
//private:
    //JsonUtilites(){} // prevent Objet creation
  
public:
    
    /*Convert a map to json
     @param[in] map std::map is a (string) key and rapisJson Value
     @return json string std::string
     */
    static std::string jsonStringFromMap(std::map<const char *, rapidjson::Value *> *map);
    static std::string jsonStringFromMap(std::map<std::string, rapidjson::Value *> *map);
    static std::string jsonStringFromMap(std::map<std::string, IGenericField *> *map);
    static std::string jsonStringFromMap(std::map<const char *, std::string *> *map);

    /*
     Convert Map to string url
     @param[in] map std::map is a (string) key and rapisJson Value
     @return json string std::string
     */
    static std::string urlStringFromMap(std::map<const char *, rapidjson::Value *> *map);
    static std::string urlStringFromMap(std::map<const char *, std::string *> *map);

    /* Add value to the rapidjson document based on the value type
     @param[in,out]  document RapidJson which will be modified with the key and value
     @param[in]      key std:string. the json key
     @param[in]      value rapidjson:Value. the json value
     @param[in]      allocator apidjson::Document::AllocatorType
     */
    static void addValueToDocument(rapidjson::Document &document , std::string  key,rapidjson::Value * value,rapidjson::Document::AllocatorType& allocator);
    
    static void addValueToDocument(rapidjson::Document &document , std::string  key,IGenericField * value,rapidjson::Document::AllocatorType& allocator);
    static void addValueToDocument(rapidjson::Document &document , char *key,rapidjson::Value * value,rapidjson::Document::AllocatorType& allocator);
 
    /*-----------------------------------------------------------*/
    
    template <typename T>
       static T getValue(const rapidjson::Value & value){

        T *vObject = new T();

        if(std::is_base_of<IModel, T>::value){
            
           IModel *model2 = (IModel*)vObject;
           model2->from_json(value);
        }
           return *vObject;
       }
   
       template<>  std::string getValue(const rapidjson::Value & value){

            return  value.GetString();
        }
       
       template<> bool getValue(const rapidjson::Value & value){
            
            return value.GetBool();
        }
       
       template<> int getValue(const rapidjson::Value & value){
             
             return  value.GetInt();
         }
       
       template<>  float getValue(const rapidjson::Value & value){
             
             return value.GetFloat();
         }
       
       template<>  double getValue(const rapidjson::Value & value){
             
             return value.GetDouble();
         }
       
       template<>  int64_t getValue(const rapidjson::Value & value){
             
             return  value.GetInt64();
         }
       
       template<>  uint64_t getValue(const rapidjson::Value & value){
             
           return  value.GetUint64();
         }
    
   
    /*-----------------------------------------------------------*/
    
    template <typename T, typename V = T>
    static std::shared_ptr<T> getValuefromGenricRapidValue(const rapidjson::Value & value){
           
           return nullptr;
    }
    
    template <class IModel>
    static std::shared_ptr<IModel> getValuefromGenricRapidT(const rapidjson::Value & v, IModel *model){
        
        model->from_json(v);

        return nullptr;
    }
    
    template<>  std::shared_ptr<std::string> getValuefromGenricRapidValue(const rapidjson::Value & value){

        if(value.IsString())
         return  std::make_shared<std::string>(value.GetString());
        
        return nullptr;
     }
    
    template<> std::shared_ptr<JsonObject> getValuefromGenricRapidValue(const rapidjson::Value & value){
            
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
    
    template<>
    std::shared_ptr<IModel> getValuefromGenricRapidValue(const rapidjson::Value & value){
         
        return nullptr;
          //return  std::make_shared<IModel>(value.GetUint64());
        }
   

    /**/
    template<typename T, typename V = T>
    static std::shared_ptr<T> get_optional(const rapidjson::Document &document,const char * key, T *optionalValue) {

        if(!document.HasMember(key)){
            return std::make_shared<T>(optionalValue);
        }
        const rapidjson::Value &t = document[key];
        
        return getValuefromGenricRapidValue<T>(t);
    }
    
   template <typename T, typename V = T>
   static std::shared_ptr<T> getOptional(const rapidjson::Document &doc,const char * key, T optional = T()){
       return  get_optional<T,V>(doc, key,optional);
    }
    
    
    /**/
    template<typename T, typename V = T>
    static std::shared_ptr<T> get_optional(const rapidjson::Value &t,const char * key, T optionalValue) {
        
        if(!t.HasMember(key))
            return nullptr;

        const rapidjson::Value &vs = t[key];

        if(std::is_base_of<IModel, T>::value){
            
            return std::make_shared<T>(getValue<T>(vs));

        }else
        if(vs.IsArray()){
            
            T *t = new T();
            std::vector<V> *mVector = (std::vector<V>*)t;

                for (auto& v : vs.GetArray()){
                  V vs = getValue<V>(v);
                    mVector->push_back(vs);
                }
                return std::make_shared<T>(*t);

        }
        else
        if(vs.IsObject()){

            T *t = new T();

            std::map<std::string , V> *map = (std::map<std::string , V> *)t;
            
            for (auto &vobj : vs.GetObject()){
                V v = getValue<V>(vobj.value);
                map->insert(std::pair<std::string,V>(vobj.name.GetString(), v));
            }
            
            
            return std::make_shared<T>(*t);

        }
        else
        {
        return getValuefromGenricRapidValue<T>(vs);
        }
        
      }
    
   template <typename T, typename V = T>
   static std::shared_ptr<T> getOptional(const rapidjson::Value &t,std::string key, T optional = T()){
         return  get_optional<T,V>(t, key.c_str(),optional);
   }

};

#endif /* JsonUtilites_hpp */
