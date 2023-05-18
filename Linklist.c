//*************************************************************************************************************
//
//Probem Statement: Write a linked list program in c for inserting,deleting and displaying elements in linklist
//
//**************************************************************************************************************

#include<stdio.h>
#include<stdlib.h>

//*************************************************************************************************************
//
//Function Name : insertfirst, insertlast, display, count, deletefirst, deletelast, insertatpos, deleteatpos.
//Description   : Perform the inserting, deleting, display and count the element in linklist. 
//Auther        : Mayuri Kakade
//Date          : 18 May 2023
// 
//**************************************************************************************************************

struct node
{
	int data;
	struct node * next;
	
};


typedef struct node HEAD;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

//*************************************INSERT FIRST*************************************************************************


void insertfirst(PPNODE head,int data)
{
	PNODE newn=NULL;                     // Create newNode with given value
	newn=(PNODE)malloc(sizeof(int));     // malloc function to allocate memory for newn
	newn->data=data;
	newn->next=NULL;
	if(*head==NULL)                     // If head is empty
	{
		*head=newn;
	}
	else
	{
		newn->next=*head;
		*head=newn;
	}
	
}
//*******************************INSERTLAST****************************************************************

void insertlast(PPNODE head,int data)
{
	PNODE newn=NULL;                      //create newNode with give value
	PNODE temp=*head;                     //define a node pointer temp
	newn=(PNODE)malloc(sizeof(int));
	newn->data=data;
	newn->next=NULL;
	
	if(*head==NULL)                       //If it is empty then set head = newn
	{
		*head=newn;
	}
	else
	{
		while(temp->next!=NULL)             //then pointer temp initialized with head
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
}

//*************************DISPLAY********************************************************************

void display(PNODE head)
{
	while(head!=NULL)                    // if Head != Null (true)
	{
		printf("|%d|->",head->data);
		head=head->next;
	}
	printf("\n");
}

//****************************COUNT********************************************************************


int count(PNODE head)
{
	int count=0;                    //create one count variable with initialized 0.
	while(head!=NULL)               // if Head != Null (true)
	{
		count++;
		head=head->next;
	}
	return  count;
}
//********************************DELETE FIRST********************************************************

void deletefirst(PPNODE head)
{
	PNODE temp=*head;                    // define a node pointer temp is initialized with head
	
	if((*head)==NULL)                   
	{
		return;                         // terminate the function
	}
	else if((*head)->next==NULL)
	{
		free(*head);
		*head=NULL;
	}
	else
	{
		(*head)=(*head)->next;
		free(temp);
	}
}

//******************************** DELETELAST********************************************************


void deletelast(PPNODE head)
{
	PNODE temp=*head;
	if(*head==NULL)
	{
		return;
	}
	else if((*head)->next==NULL)
	{
		
		free(*head);
		*head=NULL;
	}
	else
	{
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}
}

//***********************INSERT AT POSITION************************************************************************************

void insertatpos(PPNODE head,int data,int pos)
{
	PNODE newn=NULL;                        //create a newNode with given value
	PNODE temp=*head;
	int size=count(*head);

	
	if((pos<1)||(pos>size+1))
	{
		return;
	}
	if(pos==1)
	{
		insertfirst(head,data);
	}
	else if(pos==size+1)
	{
	    insertlast(head,data);
	}
	else  
	{
		newn=(PNODE)malloc(sizeof(int));
		newn->data=data;
		newn->next=NULL;
		int i=0;
		 for(i=1;i<pos-1;i++)
		 {
		 	temp=temp->next;
		 }
		 newn->next=temp->next;
		 temp->next=newn;
	}
		
}
//*****************************DELETE AT POS************************************************************

void deleteatpos(PPNODE head,int pos)
{
	int size=0;
	PNODE temp=*head;
	PNODE target=NULL;
	size=count(*head);

	if(pos<1||pos>size)
    {
    	return; 
	}
    if(pos==1)
	{
		deletefirst(head);
	}
	else if(pos==size)
	{
		deletelast(head);
	}
	else
	{
		int i=0;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		target=temp->next;
		temp->next=target->next;
		free(target);
	}
	
}


//*************************ENTRY POINT FUNCTION(MAIN)**************************************************** 
int main()
{
	PNODE first=NULL;
	int ch=1;
	int res=0;
	int data=0;
	int pos=0;
	
	
	
	while(ch!=0)
	{
		printf("\n________________________\n");
		printf("1.INSERT THE FIRST NODE\n");
		printf("2.INSERT THE LAST NODE \n");
		printf("3.DISPLAY\n");
		printf("4.COUNT\n");
		printf("5.DELETE FIRST\n");
		printf("6.DELETE LAST\n");
		printf("7.INSERT AT POSITION\n");
		printf("8.DELETE AT POSITION\n");
		printf("0.end\n");
		printf("\n________________________\n");
		
		printf("enter  the choice\n");
		scanf("%d",&ch);
      switch(ch)
      {
      	case 1:
      		    printf("enter the data into node\n");
      		    scanf("%d",&data);
      			insertfirst(&first,data);
      			break;
      	case 2:
      		    printf("enter the data into node\n");
      		    scanf("%d",&data);
      		    insertlast(&first,data);
      		    break;
		case 3:
			    display(first);	
			    break;
				
		case 4:
                 res=count(first);
                 printf("\ncount is:%d\n",res);
				 break;	
		case 5:
			     deletefirst(&first);
			     break;
		case 6:
		         deletelast(&first);
				 break;	
		case 7:
			     printf("enter the data into node\n");
      		     scanf("%d",&data);
      		     printf("Insert the position\n");
      		     scanf("%d",&pos);
		         insertatpos(&first,data,pos);
				 break;
		case 8:
                 printf("Insert the position\n");
      		     scanf("%d",&pos);
      		     deleteatpos(&first,pos);
      		     break;
				   		         		 	      
		case 0:
		        printf("Thanks for use the Mayuri linkedlist\n");
				break;
				
		default:
		        printf("PLEASE ENTER THE VALID INPUT\n");
				break;				 		    	
			    		                		
      		
	  }
    
	}
	
	return 0;
}
//*****************************************************************************************************************************