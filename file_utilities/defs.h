#ifndef _DEFS_H
#define _DEFS_H

#include <cstdint>

#define ulong unsigned long
#define uchar unsigned char
#define ushort unsigned short

// for little endian machine!
#define LODWORD(x) *(uint32_t *)&(x)


#endif