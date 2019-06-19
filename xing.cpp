  //单链表的插入和删除         单链表就是线性链表
#include <stdio.h> 
#include<malloc.h>    //动态存储分配
typedef struct Lnode
{
	int data;
    struct Lnode *Link;
}Lnode,*Linklist;
Linklist create(int n)
{
	Linklist list=(Linklist)malloc(sizeof(Lnode));    //为指针list申请空间   list链表
	Lnode *p,*q;
	int x,i;
	p=list;   //p指向表头
	for(i=1;i<=n;i++)
	{
		q=(Linklist)malloc(sizeof(Lnode));
		scanf("%d",&x);   //x为表中数据
		q->data=x;    //将数据x复制给q指向的数据域
		p->Link=q;    //q指向p的下一个节点
		p=q;         //让p指向q
	}
	p->Link=NULL;          //最后一个节点的指针域为空
	list=list->Link;          //多个
    printf("success!\n");
	return list;               //返回一个表
	
}
int insert(Linklist &list,int i,int x)     //list为表头，第i个位置，x为插入的数
{
	Linklist p,q;
	int j=1;
	p=list;
    while(p!=NULL && j<i-1) //p非空且j在下标范围之内       寻找第i个结点
    { 
		p=p->Link;
        j++;         //j计数      j为p要插入的位置，在i之后	
    }
    if(p==NULL||j>i)      //p为空或者j超出下标 都插入失败     带入数不成立才可进行下步
	{ 
		printf("无法插入");
        return 0;
	}
	if(i!=1)
    {
		q=(Linklist)malloc(sizeof(Lnode));     //为q申请新空间
        q->data=x;                       //将x赋给q指向的数据域
        q->Link=p->Link;              //
        p->Link=q;                    //将新链结点插在第i个结点之后   p->Link为p的后一个结点,所以p在前，q在后
	    printf("success!\n");
        return 1;
	}
	else
	{
		q=(Linklist)malloc(sizeof(Lnode));     //为q申请新空间
        q->data=x;                       //将x赋给q指向的数据域
		q->Link=list;
		list=p;
		return 1;
	}

}
void show(Linklist list)
{
	
	while(list)
	{
		printf("%d\t",list->data);
	    list=list->Link;
	}
	printf("\n");
	/*if(list==NULL)
		printf("表为空\n");*/

}
int delet(Linklist &list,int i)
{
	Linklist p,q;
	int j=1,item;
	p=list;
    while(p->Link && j<i-1)
	{ 
		p=p->Link ;
        ++j;
    }
    if(!(p->Link)||j>i-1)    //当p->next不为空或j超出下标范围
	{ 
		printf("无法删除");
        return 0;
	}
    q=p->Link ;
	p->Link =q->Link;
    item=q->data;            //将要删除的结点的数值保存下来
    free(q);
    return 1;
}

void main()
{
	Linklist list;
	list=NULL;
	int n,x,i,m=2;
	printf("please input n:\n");
	scanf("%d",&n);
	printf("创建单链表\n");
	list=create(n);    //一开始list为空，所以创建后要赋值给list
    show(list);

    printf("输入插入位置和插入数据\n");
	scanf("%d%d",&i,&x);
	insert(list,i,x);
    show(list);
	
	printf("\n");
    printf("删除第%d个数据\n",m);
	delet(list,m);
	show(list);
	
}