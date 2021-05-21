#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "SWM320.h"

#define HOR_RES_MAX (480)
#define VER_RES_MAX (272)

#define TEXT_RED "\x1B[1;31m"
#define TEXT_GREEN "\x1B[1;32m"
#define TEXT_YELLOW "\x1B[1;33m"

//调试信息
#define _DEBUG
#ifdef _DEBUG
#define debug(...) printf(TEXT_GREEN __VA_ARGS__)
#define debugwarn(...) printf(TEXT_YELLOW __VA_ARGS__)
#define debugerror(...) printf(TEXT_RED __VA_ARGS__)

// #define debug(...) printf(__VA_ARGS__)
// #define debugwarn(...) printf(__VA_ARGS__)
// #define debugerror(...) printf(__VA_ARGS__)

#else
#define debug(...) ;
#define debugwarn(...) ;
#define debugerror(...) ;
#endif

#endif //__MAIN_H__
