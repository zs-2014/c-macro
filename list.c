#define BEGIN_DEFINE(listname)  \
typedef struct listname         \
{                               \
    struct listname *next ;     \
    struct listname *pre ;      

#define END_DEFINE(listname)    \
}listname;

//链表是否为空
#define IS_EMPTY(head) (head && head->next == NULL)

#define insert(head, mem, val) ({                               \
    if(head == NULL)                                            \
    {                                                           \
        head = (typeof(head))malloc(sizeof(typeof(*head))) ;    \
        head ->pre = NULL ;                                     \
        head ->next = NULL ;                                    \
    }                                                           \
    typeof(head) tmp = head ;                                   \
    while(tmp ->next != NULL)                                   \
    {                                                           \
        tmp = tmp ->next ;                                      \
    }                                                           \
    tmp ->next = (typeof(head))malloc(sizeof(typeof(*head))) ;  \
    if(tmp ->next != NULL)                                      \
    {                                                           \
        tmp ->next ->pre = tmp ;                                \
        tmp ->next ->next = NULL ;                              \
        tmp ->next ->mem = val ;                                \
    }                                                           \
    tmp == head ?head:tmp->next ;                               \
})

#define search(head, mem, val) ({           \
    typeof(head) tmp = head ->next ;        \
    while(tmp != NULL)                      \
    {                                       \
       if(tmp ->mem  == val)                \
       {                                    \
            break ;                         \
       }                                    \
       tmp = tmp ->next ;                   \
    }                                       \
    tmp ;                                   \
})

#define delete(head, mem, val) ({           \
    typeof(head) tmp = head ->next ;        \
    while(tmp != NULL)                      \
    {                                       \
       if(tmp ->mem == val)                 \
       {                                    \
            break ;                         \
       }                                    \
       tmp = tmp ->next ;                   \
    }                                       \
    if(tmp != NULL)                         \
    {                                       \
        typeof(head) pre = tmp ->pre ;      \
        pre ->next = tmp ->next ;           \
        if(tmp ->next != NULL)              \
        {                                   \
            tmp ->next ->pre = pre ;        \
        }                                   \
        free(tmp) ;                         \
    }                                       \
    tmp != NULL ;                           \
})

#define freeList(head) {                     \
    typeof(head) tmp = head ;                \
    while(tmp != NULL)                       \
    {                                        \
        head = tmp ->next ;                  \
        free(tmp) ;                          \
        tmp = head ;                         \
    }                                        \
} 

BEGIN_DEFINE(T1)
    int x;
    int x1;
    int x2;
END_DEFINE(T1)

struct Test
{
   int a ;
   int b ;
};

BEGIN_DEFINE(T2)
    struct Test t ;
END_DEFINE(T2) 


#if 1
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    T1 *head = NULL ;
    int i = 0 ;
    for(i = 0 ;i < 100 ;i++)
    {
        if(head == NULL) 
        {
            head = insert(head, x, i) ;
        }
        else
        {
            insert(head, x, i) ;
        }
    }
    for(i = 0 ;i < 100 ;i++)
    {
        if(search(head, x, i) == NULL)
        {
            printf("%d is not found in the list\n", i) ;
        }
    }
    for(i = 0 ;i < 100 ;i++)
    {
        delete(head, x, i) ;
    }
    if(IS_EMPTY(head))
    {
        printf("head is null\n") ;
    }
    for(i = 0 ;i < 100 ;i++)
    {
        if(search(head, x, i) == NULL)
        {
            printf("%d is not found in the list\n", i) ;
        }
    }
    T2 *testhdr = NULL ;
    testhdr = insert(testhdr, t.a, 10) ;
    T2 *tnode = search(testhdr, t.a, 10) ;
    printf("list ->t.a = %d\n", tnode ->t.a) ;
    struct Test t1 ;
    t1.a = 20 ;
    t1.b = 30 ; 
    insert(testhdr, t, t1) ;
    tnode = search(testhdr, t.a, 20) ;
    printf("list ->t.a = %d\n", tnode ->t.a) ;
    freeList(head) ;
    freeList(testhdr) ;
    return 0 ;
}
#endif
