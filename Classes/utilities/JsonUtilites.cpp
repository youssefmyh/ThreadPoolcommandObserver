//
//  Utilites.cpp
//  myGame
//
//  Created by Youssef Hanna on 9/24/19.
//

#include "JsonUtilites.hpp"
#include "../servicelayer/exception/GameException.hpp"

std::string JsonUtilites::jsonStringFromMap(std::map<std::string, rapidjson::Value *> *map){
    
    
    if(map == nullptr)
        throw GameException("map can't be null",G_NULLPOINTER);
    
    assert(map != NULL);

   //-------------Document creattion-------------
    rapidjson::Document document; // create the rapidjson Document
    rapidjson::Document::AllocatorType& allocator = document.GetAllocator(); // create document allocator
    document.SetObject(); // set Object
    //-------------End of Document creattion-------------

    
    //-------------Start Buffer creattion-------------
    rapidjson::StringBuffer stringBuffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(stringBuffer);
    stringBuffer.Clear();
    //-------------End Buffer creattion-------------

    //-------------Iterate the Map -------------
    
    std::map<std::string , rapidjson::Value*>::iterator iterator = map->begin();
    
    while (iterator != map->end()) {
        std::string key = iterator->first;
        rapidjson::Value * mapValue = iterator->second;
        addValueToDocument(document , key , mapValue , allocator);
        iterator++;
    }
    //-------------End of Iterate the Map -------------

    document.Accept(writer);
    
    return stringBuffer.GetString();
}

std::string JsonUtilites::urlStringFromMap(std::map<std::string, rapidjson::Value *> *map){
    if(map == nullptr)
         throw GameException("map can't be null",G_NULLPOINTER);
     
     assert(map != NULL);
     
     //-------------Start Buffer creattion-------------
     std::string urlString = "?";
     //-------------Iterate the Map -------------
     
     std::map<std::string , rapidjson::Value*>::iterator iterator = map->begin();
     
     while (iterator != map->end()) {
         std::string key = iterator->first;
         rapidjson::Value * mapValue = iterator->second;
         urlString.append(key.c_str());
         urlString.append("=");
         switch (mapValue->GetType()) {
             case kFalseType:
             case kTrueType:
                  urlString.append(std::to_string(mapValue->GetBool()));
                 break;
            case kStringType:
                   urlString.append(mapValue->GetString());
             break;
             case kNumberType:{
                 if(mapValue->IsInt()){
                     urlString.append(std::to_string(mapValue->GetInt()));
                 }else
                 if(mapValue->IsDouble())
                 {
                      urlString.append(std::to_string(mapValue->GetDouble()));
                 }else
                  if(mapValue->IsFloat())
                  {
                      urlString.append(std::to_string(mapValue->GetFloat()));
                  }else
                   if(mapValue->IsUint64())
                   {
                       urlString.append(std::to_string(mapValue->GetUint64()));
                   }
                   else
                   if(mapValue->IsUint())
                   {
                      urlString.append(std::to_string(mapValue->GetUint()));
                   }
             }
            break;
             default:
                 break;
         }
         if(iterator != map->end())
         urlString.append("&");
         
         iterator++;
     }
     //-------------End of Iterate the Map -------------

     
     return urlString;
    
}


void JsonUtilites::addValueToDocument(rapidjson::Document &document , std::string key,rapidjson::Value * value,rapidjson::Document::AllocatorType& allocator){
    
    switch (value->GetType()) {
            
        case kNullType:
            
            break;
        case kFalseType: // Funny to have false and true check but this how the type is being checked in RapidJson
            
            document.AddMember(StringRef(key.c_str()),value->GetBool(),allocator);
            
           break;
        case kTrueType:
            
            document.AddMember(StringRef(key.c_str()),value->GetBool(),allocator);

            break;
       
        case kObjectType:
       
            document.AddMember(StringRef(key.c_str()),value->GetObject(),allocator);

           break;
        case kArrayType:
            
            document.AddMember(StringRef(key.c_str()),value->GetArray(),allocator);

            break;
        case kStringType:
            
            document.AddMember(StringRef(key.c_str()),StringRef(value->GetString()),allocator);

           break;
        case kNumberType:
            //TODO I don't like all this if statements need to be checked in the future
            if(value->IsInt()){
            
                document.AddMember(StringRef(key.c_str()),value->GetInt(),allocator);
                
            }else
            if(value->IsDouble())
            {
                document.AddMember(StringRef(key.c_str()),value->GetDouble(),allocator);
            }else
            if(value->IsFloat())
            {
                document.AddMember(StringRef(key.c_str()),value->GetFloat(),allocator);
            }else
            if(value->IsUint64())
            {
                document.AddMember(StringRef(key.c_str()),value->GetUint64(),allocator);
            }
            else
            if(value->IsUint())
            {
                document.AddMember(StringRef(key.c_str()),value->GetUint(),allocator);
            }
           break;
            
        default:
            break;
    }
    
}


std::string JsonUtilites::jsonStringFromMap(std::map<std::string, IGenericField *> *map){
    
    
    if(map == nullptr)
        throw GameException("map can't be null",G_NULLPOINTER);
    
    assert(map != NULL);

   //-------------Document creattion-------------
    rapidjson::Document document; // create the rapidjson Document
    rapidjson::Document::AllocatorType& allocator = document.GetAllocator(); // create document allocator
    document.SetObject(); // set Object
    //-------------End of Document creattion-------------

    
    //-------------Start Buffer creattion-------------
    rapidjson::StringBuffer stringBuffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(stringBuffer);
    stringBuffer.Clear();
    //-------------End Buffer creattion-------------

    //-------------Iterate the Map -------------
    
    std::map<std::string , IGenericField*>::iterator iterator = map->begin();
    
    while (iterator != map->end()) {
        std::string key = iterator->first;
        IGenericField * mapValue = iterator->second;
        addValueToDocument(document , key , mapValue , allocator);
        iterator++;
    }
    //-------------End of Iterate the Map -------------

    document.Accept(writer);
    
    return stringBuffer.GetString();
}


void JsonUtilites::addValueToDocument(rapidjson::Document &document , std::string key,IGenericField * value,rapidjson::Document::AllocatorType& allocator){
    
    if(value == nullptr){
             return;
         }
    switch (value->GetType()) {
        case GNullType:
            
            break;
        case GFalseType:
        {
            GenericField<bool> *field = dynamic_cast<GenericField<bool>*>(value);
            document.AddMember(StringRef(key.c_str()), field->getValue(),allocator);
        }
           break;
        case GTrueType:
        {
           GenericField<bool> *field = dynamic_cast<GenericField<bool>*>(value);
           document.AddMember(StringRef(key.c_str()), field->getValue(),allocator);
         }
          break;
      case GObjectType:
        {
           
        }
          break;
      case GArrayType:
        {
           
        }
      break;
      case GStringType:
        {
          
        }
          break;
      case GINTType:
        {
        }
          break;
                
        default:
            break;
    }

}


