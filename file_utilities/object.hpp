#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include "class_descriptor.hpp"

class OBJECT
{
private:
    const CLASS_DESCRIPTOR *class_descriptor;

protected:
    void SetClassDescriptor(class CLASS_DESCRIPTOR const *class_descriptor);
    OBJECT(void);

public:
    OBJECT(class OBJECT const &object);

    virtual void DebugDump(unsigned char)const;
    class OBJECT &operator=(class OBJECT const &object);
    class CLASS_DESCRIPTOR const *GetClassDescriptor(void);
    unsigned __int64 QueryClassId(void)const;
    unsigned char IsSameObject(class OBJECT const *object)const;
    unsigned char IsSameClass(class OBJECT const *object)const;
    virtual long Compare(class OBJECT const *object)const;
};

#endif