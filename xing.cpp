  //������Ĳ����ɾ��         �����������������
#include <stdio.h> 
#include<malloc.h>    //��̬�洢����
typedef struct Lnode
{
	int data;
    struct Lnode *Link;
}Lnode,*Linklist;
Linklist create(int n)
{
	Linklist list=(Linklist)malloc(sizeof(Lnode));    //Ϊָ��list����ռ�   list����
	Lnode *p,*q;
	int x,i;
	p=list;   //pָ���ͷ
	for(i=1;i<=n;i++)
	{
		q=(Linklist)malloc(sizeof(Lnode));
		scanf("%d",&x);   //xΪ��������
		q->data=x;    //������x���Ƹ�qָ���������
		p->Link=q;    //qָ��p����һ���ڵ�
		p=q;         //��pָ��q
	}
	p->Link=NULL;          //���һ���ڵ��ָ����Ϊ��
	list=list->Link;          //���
    printf("success!\n");
	return list;               //����һ����
	
}
int insert(Linklist &list,int i,int x)     //listΪ��ͷ����i��λ�ã�xΪ�������
{
	Linklist p,q;
	int j=1;
	p=list;
    while(p!=NULL && j<i-1) //p�ǿ���j���±귶Χ֮��       Ѱ�ҵ�i�����
    { 
		p=p->Link;
        j++;         //j����      jΪpҪ�����λ�ã���i֮��	
    }
    if(p==NULL||j>i)      //pΪ�ջ���j�����±� ������ʧ��     �������������ſɽ����²�
	{ 
		printf("�޷�����");
        return 0;
	}
	if(i!=1)
    {
		q=(Linklist)malloc(sizeof(Lnode));     //Ϊq�����¿ռ�
        q->data=x;                       //��x����qָ���������
        q->Link=p->Link;              //
        p->Link=q;                    //�����������ڵ�i�����֮��   p->LinkΪp�ĺ�һ�����,����p��ǰ��q�ں�
	    printf("success!\n");
        return 1;
	}
	else
	{
		q=(Linklist)malloc(sizeof(Lnode));     //Ϊq�����¿ռ�
        q->data=x;                       //��x����qָ���������
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
		printf("��Ϊ��\n");*/

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
    if(!(p->Link)||j>i-1)    //��p->next��Ϊ�ջ�j�����±귶Χ
	{ 
		printf("�޷�ɾ��");
        return 0;
	}
    q=p->Link ;
	p->Link =q->Link;
    item=q->data;            //��Ҫɾ���Ľ�����ֵ��������
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
	printf("����������\n");
	list=create(n);    //һ��ʼlistΪ�գ����Դ�����Ҫ��ֵ��list
    show(list);

    printf("�������λ�úͲ�������\n");
	scanf("%d%d",&i,&x);
	insert(list,i,x);
    show(list);
	
	printf("\n");
    printf("ɾ����%d������\n",m);
	delet(list,m);
	show(list);
	
}