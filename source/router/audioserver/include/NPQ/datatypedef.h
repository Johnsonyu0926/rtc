/*******************************************************************************************************************************
* 
* ��Ȩ��Ϣ����Ȩ���� (c) 2010, ���ݺ�������������޹�˾, ��������Ȩ��
* 
* �ļ����ƣ�datatypedef.h
* ժ    Ҫ���������� �������Ͷ��� �淶�ļ�
*
* ��ǰ�汾��
* ��    �ߣ� 
* ��    �ڣ�
* ��    ע���淶�������Ͷ��壬����ϸ����Ӧϵͳ���±�

����ϵͳ    LP64    ILP64   LLP64   ILP32   LP32
char        8       8       8       8       8   
short       16      16      16      16      16 
_int32      N/A     32      N/A     N/A     N/A
int         32      64      32      32      16
long        64      64      32      32      32
long long   N/A     N/A     64      N/A     N/A
pointer     64      64      64      32      32
*******************************************************************************************************************************/

#ifndef _HIK_DATATYPE_DEFINITION_
#define _HIK_DATATYPE_DEFINITION_

#if defined(__linux__) || defined(__APPLE__) || defined(ANDROID)
#include "stdint.h"

typedef uint64_t U64;
typedef int64_t  S64;

typedef uint32_t U32;
typedef int32_t  S32;

#elif defined(_WIN32) || defined(WIN32) 
typedef unsigned __int64 U64;
typedef signed __int64 S64;

typedef unsigned int U32;
typedef signed int S32;

#elif defined(_WIN64) || defined(WIN64)
typedef unsigned long U64;
typedef signed   long S64;

typedef unsigned int U32;
typedef signed int S32;

#else
typedef unsigned long long U64;
typedef signed long long S64;

typedef unsigned int U32;
typedef signed int S32;
#endif


typedef unsigned short U16;
typedef signed short S16;

typedef unsigned char U08;
typedef signed char S08;

#endif /* _HIK_DATATYPE_DEFINITION_ */
/*******************************************************************************************************************************
* �淶�������Ͷ������
*******************************************************************************************************************************/

