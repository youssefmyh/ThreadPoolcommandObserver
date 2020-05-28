//
//  CommonMacros.hpp
//  myGame
//
//  Created by Youssef Hanna on 9/17/19.
//

#ifndef CommonMacros_hpp
#define CommonMacros_hpp

#include <stdio.h>

/*
 Create A Macro to generate a getter and setter
 
 */
#define CREATE_SYNTHESIS_RETAIN_GENERAL(varType, varName, funName,protecion) \
private: varType varName; \
protecion: void set##funName(varType varName) \
{ \
if(this->varName != varName){ \
    this->varName = varName; \
} \
} \
protecion: varType get##funName () const { return this->varName;}

/*
 Create A Macro to generate a getter and setter with different protections
 */
#define CREATE_SYNTHISIS_PRIVATE(varType, varName, funName) CREATE_SYNTHESIS_RETAIN_GENERAL(varType, varName, funName,private)
#define CREATE_SYNTHISIS_PUBLIC(varType, varName, funName) CREATE_SYNTHESIS_RETAIN_GENERAL(varType, varName, funName,public)
#define CREATE_SYNTHISIS_PROTECTED(varType, varName, funName) CREATE_SYNTHESIS_RETAIN_GENERAL(varType, varName, funName,protected)

#endif /* CommonMacros_hpp */
