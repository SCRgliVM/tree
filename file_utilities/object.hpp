#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include "defs.h"

#include "class_descriptor.hpp"

class OBJECT
{
protected:
    const CLASS_DESCRIPTOR *class_descriptor;
    void SetClassDescriptor(class CLASS_DESCRIPTOR const *class_descriptor);
    OBJECT(void);

public:
    OBJECT(class OBJECT const &object);

    virtual void DebugDump(uchar)const;
    class OBJECT &operator=(class OBJECT const &object);
    class CLASS_DESCRIPTOR const *GetClassDescriptor(void);
    unsigned __int64 QueryClassId(void)const;
    uchar IsSameObject(class OBJECT const *object)const;
    uchar IsSameClass(class OBJECT const *object)const;
    virtual long Compare(class OBJECT const *object)const;
};

#endif