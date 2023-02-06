#include "object.hpp"
#include "defs.h"

OBJECT::OBJECT(void){};

OBJECT::OBJECT(class OBJECT const &object)
{
    this->class_descriptor = object.class_descriptor;
}

class OBJECT &OBJECT::operator=(class OBJECT const &object)
{
    this->class_descriptor = object.class_descriptor;
    return *this;
}

uint64_t OBJECT::QueryClassId(void)const
{
    return this->class_descriptor->self;
}

void OBJECT::SetClassDescriptor(class CLASS_DESCRIPTOR const *class_descriptor)
{
    this->class_descriptor = class_descriptor;
}

class CLASS_DESCRIPTOR const *OBJECT::GetClassDescriptor(void)
{
    return this->class_descriptor;
}

uchar OBJECT::IsSameObject(class OBJECT const *object)const
{
    return this == object;
}

uchar OBJECT::IsSameClass(class OBJECT const *object)const
{
    return this->class_descriptor->self == object->class_descriptor->self;
}

void OBJECT::DebugDump(uchar)const
{
    ;
}

/**
 * @brief I don't know why its implement using LODWORD
 * 
 * @param object 
 * @return long 
 */
long OBJECT::Compare(class OBJECT const *object)const
{
    long result = LODWORD(this->class_descriptor->self) -
                  LODWORD(object->class_descriptor->self);
    if (LODWORD(this->class_descriptor->self) == 
        LODWORD(object->class_descriptor->self))
        result = this - object;
    return result;
}