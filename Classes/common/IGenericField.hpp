//
//  GenericField.hpp
//  myGame
//
//  Created by Youssef Hanna on 11/7/19.
//

#ifndef GenericField_h
#define GenericField_h
enum GenericType {
    GNullType   = 0,      //!< null
    GFalseType  = 1,     //!< false
    GTrueType   = 2,      //!< true
    GObjectType = 3,    //!< object
    GArrayType  = 4,     //!< array
    GStringType = 5,    //!< string
    GINTType = 6,     //!< Int
    GDoubleType = 7     //!< double
};

/*
 Generic Interface to be implement for all Fields
 */
class IGenericField{
public:
    int m_Size; // field size
    IGenericField(GenericType type):m_type(type){}
    virtual ~IGenericField() = default;
    GenericType GetType(){return m_type;}
private:
    GenericType m_type; // Field type
};

/*
 @ Generic Template for Generic Field to be used for Command request and response
 */
template<typename T>
class GenericField : public IGenericField{
public:
    GenericField(T value, GenericType type):m_value(value),IGenericField(type){}
    
    T getValue(){
        return m_value;
    }
    
    ~GenericField(){}
private:
    T m_value; // Field value

};

#endif /* GenericField_h */
