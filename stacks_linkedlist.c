// STACK IMPLEMENTATION USING LINKED LIST
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


void display()
{

p=root;

  if(p==NULL)
  {
         printf("\nTHE LINKED LIST ID EMPTY\n");
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


	
int main()
{

int ch;
	while(1)
	{
	printf("\n\nPLEASE ENTER YOUR CHOICE: \n1.INSERTEND\n2.DISPLAY\n3.DELETEEND\n4.EXIT");
	scanf("%d",&ch);
		switch(ch)
		{
			
			case 1:
					insertend();
					break;
			case 2:
					display();
					break;
		        case 3:
					deleteend();
					break;
		        default:
					printf("\n\nTHANK YOU\n\n");
	 				return 0;

		}


	}

}
