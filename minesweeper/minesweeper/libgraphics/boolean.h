
#ifndef ___boolean___h____
#define ___boolean___h____

/*
* Type: bool
* ----------
* This type has ��������, FALSE(0) �� TRUE(1) 
* ���������ĺô��ǳ���Ŀɶ���
*/

#ifdef THINK_C
   typedef int bool;
#else
#  ifdef TRUE
#    ifndef bool
#      define bool int
#    endif
#  else
#    ifdef bool
#      define FALSE 0
#      define TRUE 1
#    else
       typedef enum {FALSE, TRUE} bool;
#    endif
#  endif
#endif

#endif // #ifndef ___boolean___h____
