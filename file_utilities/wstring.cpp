#include "wstring.hpp"
#include "data.hpp"

bool WSTRING::operator>=(class WSTRING const &wstring) const
{
    return _wcsicmp(this->string, wstring.string) >= 0;
}

bool WSTRING::operator>(class WSTRING const &wstring) const
{
    return _wcsicmp(this->string, wstring.string) > 0;
}

bool WSTRING::operator==(class WSTRING const &wstring) const
{
    return _wcsicmp(this->string, wstring.string) == 0;
}

bool WSTRING::operator<=(class WSTRING const &wstring) const
{
    return _wcsicmp(this->string, wstring.string) <= 0;
}

bool WSTRING::operator!=(class WSTRING const &wstring) const
{
    return _wcsicmp(this->string, wstring.string) != 0;
}

bool WSTRING::operator<(class WSTRING const &wstring) const
{
    return _wcsicmp(this->string, wstring.string) < 0;
}

class WSTRING &WSTRING::operator=(class WSTRING &wstring)
{
    this->class_descriptor = wstring.class_descriptor;
    this->string = wstring.string;
    this->length = wstring.length;
    return *this;
}

WSTRING::WSTRING(void)
{
    this->string = nullptr;
    this->length = 0;
    this->class_descriptor = WSTRING_cd;
}

WSTRING::WSTRING(class WSTRING const &wstring)
{
    this->class_descriptor = wstring.class_descriptor;
    this->string = wstring.string;
    this->length = wstring.length;
}