
#include "../Global_File/global.h"
#define NULL 0
typedef struct listnode {
ListEntry entry ;
struct listnode *next ;
}ListNode;

typedef struct list {
ListNode *head ;
int size ;
}List;
void CreatList (List *);
void ListEmpty (List *);
void ListSize  (List *);
void ListFull (List *);
void DestroyList (List *);
int InsertList (int , ListEntry , List *);
void DelateList (int , ListEntry *, List *);
void TraverseList (List *,void (*Visit)(ListEntry));
void RetrieveList (int , ListEntry * , List *);
void ReplaseList (int , ListEntry , List *);
