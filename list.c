#include"list.h"

void CreatList (List *pl){
pl->head=NULL ;
pl->size=0;
}
void ListEmpty (List *pl){
return (pl->size ==0);

 }
void ListSize  (List *pl){
return pl->size ;
}
void ListFull (List *pl){
    return 0 ;
}
void DestroyList (List *pl){
    ListNode *q ;
    while(pl->head){
        q=pl->head->next;
        free(pl->head);
        pl->head=q;
    }
    pl->size=0;
}
int InsertList (int pos , ListEntry e , List * pl){
    ListNode *p ,*q ;
    int i ;

  if( p=(ListNode *)malloc(sizeof(ListNode)) ){
   p->entry=e;
   p->next=NULL;
   if(pos==0){
    p->next=pl->head;
    pl->head=p ;
   }
   else{
    for(q=pl->head ,i=0 ;i<pos-1 ; i++){
        q=q->next;
    }
    p->next=q->next;
    q->next=p ;
   }
   pl->size++;
   return 1 ;
  }
  else
  return 0;
}
void DelateList (int pos , ListEntry *pe , List *pl){
    int i ;
    ListNode *q ,*t ;

    if(pos==0){
        *pe=pl->head->entry ;
        t=pl->head->next;
        free(pl->head);
        pl->head=t;
    }
    else{
        for(q=pl->head,i=0 ;i<pos-1;i++ ){
            q=q->next;
        }
        *pe=q->next->entry;
        t=q->next->next;
        free(q->next);
        q->next=t;
    }
    pl->size-- ;
}
void TraverseList (List *pl ,void (*Visit)(ListEntry)){
 ListNode *p=pl->head;
 while(p){
    (*Visit)(p->entry);
    p=p->next;
 }
}
void RetrieveList (int pos , ListEntry *pe , List *pl){
int i ;
ListNode *q ;
for(q=pl->head ,i=0 ;i<pos ; i++)
    q=q->next ;

    *pe=q->entry;
}
void ReplaseList (int pos, ListEntry e, List *pl){
int i ;
ListNode *q ;
for(q=pl->head , i=0 ; i<pos ; i++)
    q=q->next;
q->entry=e ;
}
