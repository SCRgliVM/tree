#include "class_descriptor.hpp"

CLASS_DESCRIPTOR::CLASS_DESCRIPTOR(void){};

unsigned char CLASS_DESCRIPTOR::Initialize(char const *)
{
    this->self = reinterpret_cast<__int64>(this);
    return 1;
};