//
//  IModel.hpp
//  myGame
//
//  Created by Youssef Hanna on 6/7/20.
//

#ifndef IModel_hpp
#define IModel_hpp

#include <stdio.h>
#include <json/document.h>
class IModel{
public:
    IModel() = default;
    virtual void from_json(const rapidjson::Value & j) = 0;

};
#endif /* IModel_hpp */
