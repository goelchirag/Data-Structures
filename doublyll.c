\\Doubly linked list
#include<stdio.h>
#include<stdlib.h>
int n,count=0;
struct node
{
   int data;
   struct node *rlink,*llink;

}*root=NULL,*temp=NULL,*p;

void insertend()
{

	temp=(struct node *)malloc(sizeof(struct node));

	printf("\nEnter the no. ");
	scanf("%d",&temp->data);
	temp->rlink=NULL;

		if(root==NULL)
		{

			root=temp;
	
		}
		else
		{
			 p=root;
				while(p->rlink!=NULL)
				   p=p->rlink;  
		p->rlink=temp;
		temp->llink=p;
		}
	count++;
	}

void insertbeg()
{

	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the no. ");
        scanf("%d",&temp->data);
        temp->llink=NULL;      
	if(count==0)
        {
		root=temp;
	}
	else
	{
		temp->rlink=root;
		root->llink=temp;
		root=temp;
	}
count++;
}
void insertpos()
{	printf("Enter the position");
	scanf("%d",&n);
	if(n<=count){
	if(n==1)
	insertbeg();
	else if(n==count)
	insertend();
	else{int i;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nenter the no. ");
        scanf("%d\n",&temp->data);
        temp->rlink=NULL;
	temp->llink=NULL;
	p=root;
	for(i=1;i<n;i++)
	p=p->rlink;
	temp->rlink=p->rlink;
	p->rlink=temp;
	temp->llink=p;
	count++;	
	}}
	else
	printf("Wrong Position");
}
void display()
{

p=root;

  if(p==NULL)
  {
         printf("\nTHE LIST IS EMPTY\n");
  }
  else
  {
	while(p!=NULL)
	{
	
	   printf("%d -->",p->data);
	   p=p->rlink;

	}

  }
}
void deletebeg(){
	if(count==0)
		printf("\nTHE LIST IS EMPTY");
	else if(count==1)
	{
	printf("\n Deleted %d",root->data);
	free(root);
	
	count--;	
	}	
	else{ 
	temp=root;
	root=root->rlink;
	printf("\n Deleted %d",temp->data);
	free(temp);
	root->llink=NULL;
	count--;
	}
	
}
void deleteend(){
	if(count==0)
	printf("THE LIST IS EMPTY");
	else if(count==1){
	printf("\nDeleted %d",root->data);
	free(root);
	root=NULL;count--;
	}
	else{
	p=root;int i=1;
	while(i<count-1){
	   p=p->rlink;
		i++;
	}
	temp=p->rlink;
	printf("\nDeleted %d",temp->data);
	free(temp);
	p->rlink=NULL;
	count--;
	}	
}	
void deletepos(){
	printf("\nEnter the postion");
	scanf("%d",&n);
	if(n<=count){
	if(n==1)
	deletebeg();
	else if(n==count)
	deleteend();
	else{int i;p=root;
	for(i=1;i<n-1;i++)
	p=p->rlink;
	temp=p->rlink;
	p->rlink=temp->rlink;
	temp->rlink->llink=p;
	printf("\nDeleted %d",temp->data);	
	free(temp);
	count--;
	}}
	else
	printf("Position incorrect");
}
void reverse(){
	if(root==NULL)
	printf("The list is Empty");
	else{
 	p=root;
	while(p->rlink!=NULL)
	  p=p->rlink;
	while(p->llink!=NULL)  
	{
	printf("%d -->",p->data);
	p=p->llink;
	}
	printf("%d -->",p->data);
	}
}	
int main()
{

int ch;
	while(1)
	{
	printf("\n\nPLEASE ENTER YOUR CHOICE: \n1.INSERTBEG \n2.INSERTEND\n3.INSERTPOS \n4.DISPLAY\n5.DELETEBEG\n6.DELETEEND\n7.DELETEPOS\n8.REVERSE\n9.EXIT");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertbeg();
				break;
			case 2:
				insertend();
				break;
			  
		        
		        case 3:			
				insertpos();
				break;

			case 4:
				display();
				break;
		      
			case 5:
				deletebeg();
				break;
			case 6:
				deleteend();
				break;
			case 7:
				deletepos();
				break;
			case 8:
				reverse();
				break;
			default:
				printf("\n\nTHANK YOU\n\n");
 				return 0;

		}


	}
}
