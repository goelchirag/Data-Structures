#include<stdio.h>
#include<stdlib.h>
int n,count=0;
struct node
{
   int data;
   struct node *link;

}*root=NULL,*temp=NULL,*p;

void insert()
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
         printf("\nTHE  QUEUE IS EMPTY\n");
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
void delete(){
	if(count==0)
		printf("\nTHE QUEUE IS EMPTY");
	else{ 
	temp=root;
	root=root->link;
	printf("\n Deleted %d",temp->data);
	free(temp);count--;
	}
	
}

	
int main()
{

int ch;
	while(1)
	{
	printf("\n\nPLEASE ENTER YOUR CHOICE: \n1.INSERT\n2.DISPLAY\n3.DELETE\n4.EXIT");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
		      
			case 3:
				delete();
				break;
			default:
				printf("\n\nTHANK YOU\n\n");
 				return 0;

		}


	}

}
