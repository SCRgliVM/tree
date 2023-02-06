#include "class_descriptor.hpp"

CLASS_DESCRIPTOR::CLASS_DESCRIPTOR(void){};

uchar CLASS_DESCRIPTOR::Initialize(char const *)
{
    this->self = reinterpret_cast<uint64_t>(this);
    return 1;
};