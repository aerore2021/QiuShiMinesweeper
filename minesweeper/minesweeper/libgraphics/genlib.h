/*
 * File: genlib.h
 * Version: 1.0
 * Last modified on Sun Jul 24 10:32:49 1994 by eroberts
 * -----------------------------------------------------
 * This file contains several definitions that form the						���ļ������������壬��Щ���幹������ Eric Roberts ������ͨ�� ANSI C ��ĺ��ġ�
 * core of a general-purpose ANSI C library developed by Eric				�ÿ��Ŀ�����ṩһ������Ĺ��ߺ�Լ��������� C ����Ŀɶ��ԣ�
 * Roberts.  The goal of this library is to provide a basic					�������ڽ�ѧ������ʹ������ʱ��
 * set of tools and conventions that increase the readability	
 * of C programs, particularly as they are used in a teaching
 * environment.
 *
 * The basic definitions provided by genlib.h are:							genlib.h �ṩ�Ļ��������ǣ�
 *
 *    1.  Declarations for several new "primitive" types						1. ���������µġ�ԭʼ�����ͣ�����Ҫ���� bool �� string����
 *        (most importantly bool and string) that are							   ���������Ӧ�ó����������������͡�
 *        used throughout the other libraries and
 *        applications as fundamental types.
 *
 *    2.  A new set of functions for memory allocation.							2. һ���µ��ڴ���亯����
 *
 *    3.  A function for error handling.										3. �������ܡ�
 *
 *    4.  A repeat statement for loops with interior exits.						4. �����ڲ����ڵ�ѭ�����ظ���䡣
 */

#ifndef _genlib_h
#define _genlib_h
                                                                           
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "boolean.h"

/* Section 1 -- Define new "primitive" types */                             /*��һ���� -- �����µġ�ԭʼ������*/

/*
 * Type: string                                                             ���ͣ�string
 * ------------                                                             ------------    
 * The type string is identical to the type char *, which is                �ַ��������봫ͳ������ C ����� char * ������ͬ��
 * traditionally used in C programs.  The main point of defining a          ���������͵���ҪĿ������߳���Ŀɶ��ԡ�
 * new type is to improve program readability.   At the abstraction         ��ʹ���ַ������͵ĳ��󼶱��ϣ����ַ����ֽ�Ϊ������ַ�ͨ��������Ҫ��
 * levels at which the type string is used, it is usually not               ��������Ϊ�ַ���ǿ��������ԭ���ԡ�
 * important to take the string apart into its component characters.        �ҿ�����������ɨ��Ҳ�ò�����
 * Declaring it as a string emphasizes this atomicity.
 */

typedef char *string;

/*
 * Type: stream                                                             ���ͣ�stream
 * ------------                                                             ------------    
 * Like string, the stream type is used to provide additional               ��stringһ����stream���������ṩ����Ŀɶ��ԣ�
 * readability and is defined to be equivalent to FILE *                    ���ұ�����Ϊ��ͬ�� FILE *�����ر�����������Ϊ��Υ���˱�׼��СдԼ������
 * (which is particularly confusing because it violates                     �����������ı���û��ʹ�ã��������� genlib.h �У�
 * standard case conventions).  This type is not used in                    ��˿����ڲ���¶�κ�ָ�������½������� CS1��
 * the text but is preserved in genlib.h, so it is possible                 
 * to teach all of CS1 without exposing any pointers.
 */

typedef FILE *stream;

/*
 * Constant: UNDEFINED                                                      ������UNDEFINED
 * -------------------                                                      -------------------
 * Besides NULL, the only other constant of pointer type is                 ���� NULL ֮�⣬Ψһ������ָ�����ͳ����� UNDEFINED��
 * UNDEFINED, which is used in certain packages as a special                ����ĳЩ�������������ǣ���ָʾδ�����ָ��ֵ��
 * sentinel to indicate an undefined pointer value.  In many                ���������������£�NULL ��һ���Ϸ�������ֵ����˲��ʺ���Ϊ������(�ô�����)��
 * such contexts, NULL is a legitimate data value and is
 * therefore inappropriate as a sentinel.
 */

#define UNDEFINED ((void *) undefined_object)

extern char undefined_object[];

/* Section 2 -- Memory allocation */                                        /*�ڶ����� -- �ڴ����*/

/*
 * General notes:                                                           һ��ע�����
 * --------------                                                           --------------
 * These functions provide a common interface for memory                    ��Щ����Ϊ�ڴ�����ṩ��һ��ͨ�ýӿڡ�
 * allocation.  All functions in the library that allocate                  �������з����ڴ�ĺ�����ʹ�� GetBlock �� FreeBlock��
 * memory do so using GetBlock and FreeBlock.  Even though                  ���� ANSI ��׼������ͬĿ�Ķ����� malloc �� free��
 * the ANSI standard defines malloc and free for the same                   ��ʹ�� GetBlock �� FreeBlock �ṩ����� ANSI ʵ�ֵĸ�������ԡ�
 * purpose, using GetBlock and FreeBlock provides greater                   �Զ��ڴ治��������Լ�����������շ������Ŀ����ԡ�
 * compatibility with non-ANSI implementations, automatic
 * out-of-memory error detection, and the possibility of
 * substituting a garbage-collecting allocator.
 */

/*
 * Function: GetBlock                                                       ������GetBlock
 * Usage: ptr = (type) GetBlock(nbytes);                                    Usage: ptr = (type) GetBlock(nbytes);
 * -------------------------------------                                    -------------------------------------
 * GetBlock allocates a block of memory of the given size.  If              GetBlock ���������С���ڴ�顣
 * no memory is available, GetBlock generates an error.                     ���û�п����ڴ棬GetBlock �����ɴ���
 */

void *GetBlock(size_t nbytes);

/*
 * Function: FreeBlock                                                      ������FreeBlock
 * Usage: FreeBlock(ptr);                                                   ʹ�ã�FreeBlock(ptr);
 * ----------------------                                                   ----------------------
 * FreeBlock frees the memory associated with ptr, which must               FreeBlock �ͷ��� ptr �������ڴ棬
 * have been allocated using GetBlock, New, or NewArray.                    ���ڴ������ʹ�� GetBlock��New �� NewArray ���䡣
 */

void FreeBlock(void *ptr);

/*
 * Macro: New                                                               �꣺New   (�����JAVA��ͦ���)
 * Usage: p = New(pointer-type);                                            ʹ�ã�p = New(pointer-type);
 * -----------------------------                                            -----------------------------
 * The New pseudofunction allocates enough space to hold an                 New α���������㹻�Ŀռ�������ָ������ָ������͵Ķ���
 * object of the type to which pointer-type points and returns              ������һ��ָ���·����ָ���ָ�롣
 * a pointer to the newly allocated pointer.  Note that                     ��ע�⣬��New���� C++ ��ʹ�õġ�new���������ͬ��
 * "New" is different from the "new" operator used in C++;                  ǰ�߲���ָ�����ͣ����߲���Ŀ�����͡�
 * the former takes a pointer type and the latter takes the
 * target type.
 */

#define New(type) ((type) GetBlock(sizeof *((type) NULL)))

/*
 * Macro: NewArray                                                          �꣺NewArray
 * Usage: p = NewArray(n, element-type);                                    ʹ�ã�p = NewArray(n, element-type);
 * -------------------------------------                                    -------------------------------------    
 * NewArray allocates enough space to hold an array of n                    NewArray �����㹻�Ŀռ�������ָ��Ԫ�����͵� n ��ֵ�����顣
 * values of the specified element type.
 */

#define NewArray(n, type) ((type *) GetBlock((n) * sizeof (type)))

/* Section 3 -- Basic error handling */                                     /*�������� -- ����������*/

/*
 * Function: Error                                                          ������Error
 * Usage: Error(msg, ...)                                                   ʹ�ã�Error(msg, ...)
 * ----------------------                                                   ----------------------
 * Error generates an error string, expanding % constructions               Error ����һ�������ַ�������չ�����ڴ�����Ϣ�ַ����е� % �ṹ������ printf һ����
 * appearing in the error message string just as printf does.               ��������˴���������쳣������ġ�exception.h�����ߣ���
 * If an error handler exception has been introduced (see the               ������� ErrorException �쳣��������չ�Ĵ����ַ�����Ϊ������
 * "exception.h" facility), the ErrorException exception is                 ���û�ж��� ErrorException��
 * raised with the expanded error string as argument.  If                   ������˳�������ָʾʧ�ܵ�״̬���루�ɳ��� ErrorExitStatus ��������
 * there is no ErrorException defined, the program exits                    ��չ��Ĵ�����Ϣ�ַ����ĳ��Ȳ��ܳ��� MaxErrorMessage�����ǿͻ��˵����Ρ�
 * with a status code indicating failure (as given by the   
 * constant ErrorExitStatus).  The length of the error
 * message string following expansion must not exceed
 * MaxErrorMessage, and it is the client's responsibility
 * to ensure this.
 */

void Error(string msg, ...);

/* Section 4 -- The repeat pseudo-statement */                          /*���Ĳ��� -- �ظ���α���*/

/*
 * Statement form: repeat { ... }                                       �����ʽ��repeat { ... }
 * ------------------------------                                       ------------------------------
 * Some instructors who have taught CS1 using this library              һЩʹ�øÿ���� CS1 �Ľ�ʦ���֣�
 * have found that using                                                ʹ�� while (TRUE) ���������ڲ����ڵ�ѭ������ѧ���е������������ڿγ̿�ʼʱ��
 *                                                                      ����꽫��repeat������Ϊһ������ѭ���ṹ������Щ�����������׽��͵Ľ�ʦʹ�ã�������û�����ı���ʹ�á�
 *     while (TRUE)                                                     ���Ƶĺ�۶����ڹ�ҵ�кܳ�����
 *
 * to initiate a loop with an interior exit is confusing to
 * students, particularly when it comes at the beginning of
 * the course.  This macro defines "repeat" as an infinite
 * loop construct for instructors who find it easier to
 * explain, although it is not used in the text.   Similar
 * macro definitions are common in industry.
 */

#define repeat for (;;)

#endif
