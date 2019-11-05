#include<stdio.h>
#include<stdlib.h>
int n,count=0;
struct node
{
   int data;
   struct node *link;

}*root=NULL,*temp=NULL,*p;

void insertend()
{

	temp=(struct node *)malloc(sizeof(struct node));

	printf("\nenter the no. ");
	scanf("%d",&temp->data);
	temp->link=NULL;

		if(root==NULL)
		{

			root=temp;
	
		}
		else
		{
			 p=root;
				while(p->link!=NULL)
				   p=p->link;  
		p->link=temp;
		}
	count++;
	}

void insertbeg()
{

	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the no. ");
        scanf("%d",&temp->data);
        temp->link=NULL;      
	if(count==0)
        {
		root=temp;
	}
	else
	{
		temp->link=root;
		root=temp;
	}
count++;
}
void insertpos()
{	 printf("Enter the position");
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
        temp->link=NULL;
	p=root;
	for(i=1;i<n;i++)
	p=p->link;
	temp->link=p->link;
	p->link=temp;
	count++;	
	}
	}
 	else
	printf("Wrong position");
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
	   p=p->link;

	}

  }
}
void deletebeg(){
	if(count==0)
		printf("\nTHE LIST IS EMPTY");
	if(count==1){
		printf("\n Deleted %d",root->data);
		free(root);
		count--;
	}
	else{ 
	temp=root;
	root=root->link;
	printf("\n Deleted %d",temp->data);
	free(temp);count--;
	}
	
}
void deleteend(){
	if(count==0)
	printf("The list is empty");
	else if(count==1){
	printf("\nDeleted %d",root->data);
	free(root);
	root=NULL;count--;
	}
	else{
	p=root;int i=1;
	while(i<count-1){
	   p=p->link;
		i++;
	}
	temp=p->link;
	printf("\nDeleted %d",temp->data);
	free(temp);
	p->link=NULL;
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
	p=p->link;
	temp=p->link;
	p->link=temp->link;
	printf("\nDeleted %d",temp->data);	
	free(temp);
	count--;
	}
	}
	else
	printf("Wrong input");
}

	
int main()
{

int ch;
	while(1)
	{
	printf("\n\nPLEASE ENTER YOUR CHOICE: \n1.INSERTBEG \n2.INSERTEND\n3.INSERTPOS \n4.DISPLAY\n5.DELETEBEG\n6.DELETEEND\n7.DELETEPOS\n8.EXIT");
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
			default:
				printf("\n\nTHANK YOU\n\n");
 				return 0;

		}


	}

}
