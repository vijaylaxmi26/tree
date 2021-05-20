#include<stdio.h>
struct Node
{
  int data; 
  struct Node *left,*right;
};


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
        else 
		    return(rDepth + 1);  
    }  
}  
int main(){
	
	return 1;
}
