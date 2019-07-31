#include<bits/stdc++.h>
using namespace std;
struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* start=NULL;


void add(int new_data,struct node* ptr)
{
    //RIGHT TREE
   if(new_data > ptr->data)
   {
   	if(ptr->right==NULL)
   	{
   	struct node* new_node=new node;
   new_node->data=new_data;
   new_node->left=NULL;
   new_node->right=NULL;
   ptr->right=new_node;	
	}
	
	else{
     ptr=ptr->right;
	 add(new_data, ptr);
       }
   }
   //LEFT TREE
   else
   {
   	if(ptr->left==NULL)
   	{
   		struct node* new_node=new node;
        new_node->data=new_data;
        new_node->left=NULL;
        new_node->right=NULL;
        ptr->left=new_node;	
	   }
   	else{
   	ptr=ptr->left;
   	add(new_data,ptr);
   }
   }

   	
}
void insert(int new_data)
{
  
   if(start==NULL)
   {
   	 struct node* new_node=new node;
     new_node->data=new_data;
     new_node->left=NULL;
     new_node->right=NULL;
   	 start=new_node;
   }
   else
   {
   	add(new_data,start);
   }
}
void display_in(struct node* ptr)
{
	if(ptr==NULL)
	{
		return;
	}
	display_in(ptr->left);
	
	cout<<ptr->data<<" ";
	display_in(ptr->right);
	
	
}
void display_pre(struct node* ptr)
{
	if(ptr==NULL)
	{
		return;
	}
	cout<<ptr->data<<" ";
	display_pre(ptr->left);
	
	
	display_pre(ptr->right);
	
	
	
}
void display_post(struct node* ptr)
{
	if(ptr==NULL)
	{
		return;
	}
	display_post(ptr->left);
	
	
	display_post(ptr->right);
	cout<<ptr->data<<" ";
	
	
}

main()
{
	insert(8);
	insert(9);
	insert(10);
	insert(11);
	insert(12);
	insert(1);
	insert(2);
	
	display_in(start);
	cout<<endl;
	display_pre(start);
	cout<<endl;
	display_post(start);
}
