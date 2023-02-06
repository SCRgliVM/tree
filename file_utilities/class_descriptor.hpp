#ifndef _CLASS_DESCRIPTOR_H
#define _CLASS_DESCRIPTOR_H

#include "defs.h"

class CLASS_DESCRIPTOR
{
public:
        uint64_t self;
        CLASS_DESCRIPTOR(void);
        uchar Initialize(char const *);
};

#endif