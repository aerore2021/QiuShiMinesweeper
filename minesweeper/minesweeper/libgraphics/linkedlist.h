/*
 * File: LinkedList.h
 * -------------
 * This file provides an interface to a simple linked list abstraction.             ����ļ��ṩ��һ���򵥵��������Ľӿڡ�
 *                                                                                  ��˼�����������������������pta����ô�鷳�ˡ�    
 *typedef struct linkedlistCDT *linkedlistADT;                                              
 *
 *linkedlistADT NewLinkedList(void);
 *void FreeLinkedList(linkedlistADT linkedlist);
 *linkedlistADT SearchNode(linkedlistADT linkedlist, void *obj,
 *                         bool (*equalfunptr)(void *obj1, void *obj2));
 *void InsertNode(linkedlistADT linkedlist, linkedlistADT nodeptr, void *obj);
 *linkedlistADT DeleteNode(linkedlistADT linkedlist, void *obj,
 *                         bool (*equalfunptr)(void *obj1, void *obj2));
 *void TraverseLinkedList(linkedlistADT linkedlist,
 *                        void (*traversefunptr)(void *obj));
 *void *ithNodeobj(linkedlistADT head, int index);
 *linkedlistADT NextNode(linkedlistADT head, linkedlistADT nodeptr);
 *void *NodeObj(linkedlistADT head, linkedlistADT nodeptr);
 */

#ifndef _LinkedList_h
#define _LinkedList_h

#include "boolean.h"

/*
 * Type: linkedlistADT                                                              ���ͣ�linkedlistADT
 * --------------                                                                   --------------
 * This line defines the abstract linked list type as a pointer to                  ��һ�н������������Ͷ���Ϊָ��������Ӧ���ָ�롣
 * its concrete counterpart.  Clients have no access to the                         �ͻ���Ȩ���ʻ�����ʾ��
 * underlying representation.                                                      
 */

typedef struct linkedlistCDT *linkedlistADT;

/*
 * Function: NewLinkedList                                                          ������NewLinkedList
 * Usage: linkedlist = NewLinkedList();                                             ʹ�ã�linkedlist = NewLinkedList();
 * --------------------------                                                       --------------------------
 * This function allocates and returns an empty linked list (including a head       �ú������䲢����һ��������������һ��ͷ�ڵ㣩��
 * node only).
 */

linkedlistADT NewLinkedList(void);

/*
 * Function: FreeLinkedList                                                         ������FreeLinkedList
 * Usage: FreeLinkedList(linkedlist);                                               ʹ�ã�FreeLinkedList(linkedlist);
 * ------------------------                                                         ------------------------
 * This function frees the storage associated with linked list.                     �˺����ͷ�����������Ĵ洢�ռ䡣
 */

void FreeLinkedList(linkedlistADT linkedlist);

/*
 * Function: SearchNode                                                             ������SearchNode
 * Usage: nodeptr = SerachNode(linkedlist, obj, equalfunptr);                       ʹ�ã�nodeptr = SerachNode(linkedlist, obj, equalfunptr);
 * ---------------------------                                                      ---------------------------
 * This function searches the obj in the linked list, return the node pointer if    �ú����������в���Ŀ�꣬����ҵ��򷵻ؽڵ�ָ�룬���򷵻�NULL��    
 * find out the obj, renturn NULL otherwise.
 */

linkedlistADT SearchNode(linkedlistADT linkedlist, void *obj, bool (*equalfunptr)(void *obj1, void *obj2));

/*
 * Function: InsertNode                                                             ������InsertNode
 * Usage: InsertNode(linkedlist, nodeptr, obj);                                     ʹ�ã�InsertNode(linkedlist, nodeptr, obj);
 * ----------------------------                                                     ----------------------------
 * This function ineserts the data value after the nodeptr node of the linked       �ú����������nodeptr�ڵ�֮���������ֵ��
 * list. if nodeptr is NULL, append the obj to the tail of the linked list.         ��� nodeptr Ϊ NULL���� obj ���ӵ������β����
 *
 * return the node inserted                                                         ���ز���Ľڵ�
 */

linkedlistADT InsertNode(linkedlistADT linkedlist, linkedlistADT nodeptr, int obj);

/*
 * Function: DeleteNode                                                             ������DeleteNode
 * Usage: nodeptr = DeleteNode(linkedlist, obj, equalfunptr);                       ʹ�ã�nodeptr = DeleteNode(linkedlist, obj, equalfunptr);
 * ------------------------------                                                   ------------------------------
 * This function deletes the node with the data obj of the linked list. it returns  �ú���ɾ����������Ϊobj�Ľڵ㡣
 * the pointer of the node if found, NULL otherwise.                                ����ҵ������ؽڵ��ָ�룬���򷵻�NULL��
 */

linkedlistADT DeleteNode(linkedlistADT linkedlist, void *obj,
                         bool (*equalfunptr)(void *obj1, void *obj2));

/*
 * Function: TraverseList                                                           ������TraverseList ��traverse--������
 * Usage: TraverseList(linkedlist, void (*traversefunptr)(void *obj));              ʹ�ã�TraverseList(linkedlist, void (*traversefunptr)(void *obj));
 * ------------------------------                                                   ------------------------------
 * This function traverses the linked list, and process the node value obj using    �ú�������������ʹ��funptrָ��ĺ�������ڵ�ֵobj��
 * the function which funptr points to.
 */

void TraverseLinkedList(linkedlistADT linkedlist, void (*traversefunptr)(void *obj));

/*
 * Function: ithNode                                                                ������ithNode
 * Usage: obj = ithNode(linkedlist, index);                                         ʹ�ã�obj = ithNode(linkedlist, index);    
 * ------------------------------                                                   ------------------------------        
 * This function return the pointer of the index-th node of the linked list.        �ú������������ index ���ڵ��ָ�롣
 */

void *ithNodeobj(linkedlistADT head, int index);

/*
 * Function: NextNode                                                               ������NextNode
 * Usage: nextnodeptr = NextNode(linkedlist, nodeptr);                              ʹ�ã�nextnodeptr = NextNode(linkedlist, nodeptr);
 * ------------------------------                                                   ------------------------------
 * This function return the pointer of the next node of the node nodeptr.           �ú������ؽڵ�nodeptr����һ���ڵ��ָ�롣
 */

linkedlistADT NextNode(linkedlistADT head, linkedlistADT nodeptr);

/*
 * Function: NodeObj                                                                ������NodeObj
 * Usage: obj = NodeObj(linkedlist, nodeptr);                                       ʹ�ã�obj = NodeObj(linkedlist, nodeptr);
 * ------------------------------                                                   ------------------------------
 * This function return the dataptr of the node nodeptr points to.                  �ú������� nodeptr ָ��Ľڵ�� dataptr��
 */

void *NodeObj(linkedlistADT head, linkedlistADT nodeptr);

/*
 * Type: linkedlistCDT                                                              ���ͣ�linkedlistCDT
 * --------------                                                                   --------------
 * This type provides the concrete counterpart to the linkedlistADT.                ���������ṩ������ADT �ľ����Ӧ�
 */

struct linkedlistCDT {
    int dataptr;
    struct linkedlistCDT *next;
};  

#endif
