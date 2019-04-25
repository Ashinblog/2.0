#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>

using namespace std;
#define LIST_INIT_SIZE 100/*线性表初始长度*/
#define LISTINCREMENT 10 /*线性表分配增量*/

typedef struct stri
{
    char st[20];
    int p;
}str;
typedef struct
{
stri *elem;    /*储存空间基址*/
int length;    /*当前长度*/
int listsize;/*当前分配储存容量*/
}SqList;

char InitList_Sq(SqList &H)/*构建一个空的线性表*/
{
 H.elem=(stri *)malloc(LIST_INIT_SIZE*sizeof(stri));
 H.length=0;
 H.listsize=LIST_INIT_SIZE;
 return 1;
}
void fuzhi(SqList &H)/*给顺序表赋值*/
{
void digui(SqList &H,char sg[],int e);
char sg[20];

 do
 {
  if(H.length==0)
  {
H.length=1;
cin>>H.elem[H.length].st;
H.elem[H.length].p=1;
  }
else
{
    cin>>sg;
      H.length=1;
    digui(H,sg,H.length);
 }
 }while(getchar()!='\n');
}

void digui(SqList &H,char sg[],int e)
{
    H.length=e;
    if(strcmp(sg,H.elem[H.length].st)<0)
    {
     H.length=2*H.length;
     if(H.elem[H.length].p==1)
     {
        digui(H,sg,H.length);
     }
     else
      {
        strcpy(H.elem[H.length].st,sg);
           H.elem[H.length].p=1;
      }
    }
 if(strcmp(sg,H.elem[H.length].st)>0)
    {
     H.length=2*H.length+1;
     if(H.elem[H.length].p==1)
     {
        digui(H,sg,H.length);
     }
     else
     {
          strcpy(H.elem[H.length].st,sg);
      H.elem[H.length].p=1;
     }
    }
}
int bitbin(SqList &H)
{
 char s[20];
 cin>>s;
 H.length=1;
 do
 {
    if(strcmp(s,H.elem[H.length].st)==0)
   {
       return H.length;
   }
   if(strcmp(s,H.elem[H.length].st)<0)
    H.length=2*H.length;
   else if(strcmp(s,H.elem[H.length].st)>0)
     H.length=2*H.length+1;
if(strcmp(s,H.elem[H.length].st)==0)
   {
       return H.length;
   }
 }while(strcmp(s,H.elem[H.length].st)==0);
 return 0;
}



 int main()
 {
  SqList h;
  int num;
  InitList_Sq(h);
  fuzhi(h);
  num=bitbin(h);
  cout<<num;

return 0;
 }
