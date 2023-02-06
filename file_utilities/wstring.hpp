#ifndef _WSTRING_H
#define _WSTRING_H

#include <cwchar>

#include "defs.h"

#include "object.hpp"

class WSTRING : OBJECT
{
private:
    wchar_t *string;
    ulong length;
private:
    static uchar ConvertUnicodeToOemN(char *, ulong, ulong *, ushort *, ulong);
    static uchar ConvertOemToUnicodeN(ushort *, ulong, ulong *, char *, ulong);
    static int CheckSpace(ushort *);

protected:
    WSTRING(void);
    void PutString(ushort *, ulong);
    void PutString(ushort *);
    void Construct(void);

public:
    WSTRING(class WSTRING const &);

    class WSTRING &operator=(class WSTRING &);
    bool operator>=(class WSTRING const &) const;
    bool operator>(class WSTRING const &) const;
    bool operator==(class WSTRING const &) const;
    bool operator<=(class WSTRING const &) const;
    bool operator!=(class WSTRING const &) const;
    bool operator<(class WSTRING const &) const;

    //ulong Truncate(ulong);
    ulong SyncLength(void);

    ulong Strstr(class WSTRING const *) const;
    ulong Strspn(class WSTRING const *, ulong) const;

    ulong Strchr(ushort, ulong) const;
    ulong Strrchr(ushort, ulong) const;

    class WSTRING *Strlwr(void);
    class WSTRING *Strlwr(ulong, ulong);

    class WSTRING *Strupr(void);
    class WSTRING *Strupr(ulong, ulong);

    static int Stricmp(ushort *, ushort *);
    long Stricmp(class WSTRING const *, ulong, ulong, ulong, ulong) const;
    long Stricmp(class WSTRING const *, ulong) const;
    long Stricmp(class WSTRING const *) const;

    ulong Strcspn(class WSTRING const *, ulong) const;

    static int Strcmps(ushort *, ushort *);
    static int Strcmpis(ushort *, ushort *);
    static int Strcmp(ushort *, ushort *);
    long Strcmp(class WSTRING const *, ulong, ulong, ulong, ulong) const;
    long Strcmp(class WSTRING const *, ulong) const;
    long Strcmp(class WSTRING const *) const;
    
    uchar Strcat(ushort const *);
    uchar Strcat(class WSTRING const *);

    uchar Split(class ARRAY *, class WSTRING const *, uchar) const;

    static ushort *SkipWhite(ushort *);

    static void SetOemConversions(void);
    static void SetConsoleConversions(void);
    static void SetAnsiConversions(void);
    static void ResetConversions(void);

    ushort SetChAt(ushort, ulong);
    ushort QueryChAt(ulong) const;
    void DeleteChAt(ulong, ulong);
    
    uchar ReplaceWithChars(ulong, ulong, ushort, ulong);
    uchar Replace(ulong, ulong, class WSTRING const *, ulong, ulong);

    ushort const *GetWSTR(void) const;
    ushort *QueryWSTR(ulong, ulong, ushort *, ulong, uchar) const;

    class WSTRING *QueryString(ulong, ulong) const;
    char *QuerySTR(ulong, ulong, char *, ulong, uchar) const;
    uchar QueryNumber(long *, ulong, ulong) const;
    ulong QueryByteCount(void) const;

    uchar InsertString(ulong, class WSTRING const *, ulong, ulong);

    uchar Initialize(void);
    uchar Initialize(ushort const *, ulong);
    uchar Initialize(long);
    uchar Initialize(char const *, ulong);
    uchar Initialize(class WSTRING const *, ulong, ulong);

};

#endif