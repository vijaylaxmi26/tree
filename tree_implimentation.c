#include<stdio.h>
#include <stdlib.h> 

struct Node
{
  int data; 
  struct Node *left,*right;
};

struct Node* create(int x)
{
	struct Node* new_node;
	int value,lx,ly;
	new_node= (struct Node*) malloc(sizeof(struct Node));
	printf("enter the value for %dnth level(-1 for no node)\n",x);
	scanf("%d",&value);
	lx=x;
	ly=x;
	if(value==-1)
	    return 0;
	    
	new_node->data=value;
	printf("Value for left node:\n");
	new_node->left=create(++lx);
	
	printf("value of right node:\n");
	new_node->right=create(++ly);
	
	
  return new_node;
	
}
 
 

void preorder(struct Node* root)
{
	if(root!=0){
		printf("%d ",root->data);
       	preorder(root->left);
	    preorder(root->right);
	}
 
}

void Inorder(struct Node* root)
{
	if(root!=0){
       	Inorder(root->left);
       	printf("%d ",root->data);
	    Inorder(root->right);
	}
 
}

void postorder(struct Node* root)
{
	if(root!=0){
       	postorder(root->left);
       	postorder(root->right);
       	printf("%d ",root->data);
	}
 
}

struct Node* insertion(struct Node *node)
{
	struct Node* new_node;
	new_node= (struct Node*) malloc(sizeof(struct Node));
	 
	printf("Enter the value.\n");
	scanf("%d",&new_node->data); 
	new_node->left=0;
	new_node->right=0;
	
	struct Node* temp;
	temp=node;
	if(temp==0)
	{
	    return new_node;
	}
	else{
		 while(1)
        {
    	  if(temp->data>new_node->data){
    		   if(temp->left!=0)
    		       temp=temp->left;
    		   else{
    			   temp->left=new_node;
    			   break;
			    }
		   }
		   else if(temp->data<new_node->data){
			    if(temp->right!=0)
    		       temp=temp->right;
    		    else{
    		    	temp->right=new_node;
    			    break;
			    }
	    	}
	    	else
		   {
	 		    printf("Can't add duplicate in BST.\n");
	 		    break;
		   }
	    }
	    return node;	
   }
  
	 
}

void del(struct Node* node,int value)
{
	struct Node *temp,*pre;
	temp=node;
	int n=0;
	while(temp!=0)
	{
		if(temp->data==value)
		{
			break;
		}
		else if(temp->data>value)
		{
			pre=temp;
			temp=temp->left;
			n=0;
		}
		else
		{
			pre=temp;
			temp=temp->right;
			n=1;
		}
	}
	
	if(temp!=0)
	{
		if(temp->left==0 && temp->right==0)
		{
			 if(n==0)
			 	pre->left=0;
			else
			    pre->right=0;
			
			free(temp);
		}  
		else if(temp->left==0 || temp->right==0)
		{
			if(n==0)
			{
				if(temp->left!=0)
				   pre->left=temp->left;
				else
				   pre->left=temp->right;				
			}
			else
			{
				if(temp->left!=0)
				   pre->right=temp->left;
				else
				   pre->right=temp->right;				
			}
			free(temp);
			
		}
		else
		{
			struct Node *max_node,*pre_node;
			max_node=temp->left;
			int max;
			max=max_node->data;
			pre_node=temp;
			while(max_node!=0)
			{
				max=max_node->data;
				
				if(max_node->right!=0)					
				   pre_node=max_node;
				   	
				max_node=max_node->right;
			}
			temp->data=max;
			struct Node* t=pre->right;
			free(t);
			pre_node->right=0;
		}
		
	}
}

void update(struct Node* node)
{
	int old_value,new_value;
	printf("Enter the which you want to update.\n");
	scanf("%d",&old_value);
	printf("Enter the updated value.\n");
	scanf("%d",&new_value);
	
	while(node!=0)
	{
		if(node->data==old_value)
		{
		    node->data=new_value;
		    break;
	    }
		
		else if(node->data>old_value)
		     node = node->left;
		
		else
		     node = node->right;
	}
	
	
}

int hight(struct Node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
       
        int lDepth = hight(node->left);  
        int rDepth = hight(node->right);  
        
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}  

int main()
{
	struct Node *root=0;
	root=create(0);
	int q=1;
	while(q)
	{
		int choise,value;
		printf("choose the opration.\n1.insertion\n2.deletion\n3.update.\n4.level\n");
		scanf("%d",&choise);
		
		switch(choise)
		{
			case 1:
				insertion(root);
				printf("\nPreorder: ");
				preorder(root);
				printf("\nInorder: ");
				Inorder(root);
				printf("\nPostorder: ");
				postorder(root);
				break;
			
			case 2:
				printf("\nWhich value u want to delet value.\n");
				scanf("%d",&value);
				del(root,value);
	            printf("\nInorder: ");
	            Inorder(root);
	             
				break;
			
			case 3:
				update(root);
				printf("\nInorder: ");
	            Inorder(root);
	            printf("\nPreorder: ");
	            preorder(root);
	            printf("\nPostorder: ");
				postorder(root);
				break;
			
			case 4:
				printf("Hight of Tree: %d",hight(root));
				break;
			default:
				printf("\nInvalid opration.");		
					
		}
		printf("\ncontinue(1) or exit(0).\n");
		scanf("%d",&q);
	}
	
	
   return 0;	
}
