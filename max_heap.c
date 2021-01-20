#include<stdio.h>

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void heapify(int a[],int n,int i)
{
	int large=i;
	int left=2*i+1;
	int right=2*i+2;
	
	
    	if(left<n && a[left]>a[large])
	      large = left;
	
	   if(right<n && a[right]>a[large])
	      large = right; 
	
	   if(large!=i){
		   swap(&a[large],&a[i]);
		   heapify(a,n,i+1);
	   } 
 
	
}

void heapify_child(int a[],int n)
{
	int i=n-1;
	int prent=(i-1)/2;
	
	if(prent>=0 && a[i]>a[prent])
	{
		swap(&a[i],&a[prent]);
	}
	if(prent>=0)
	{
		heapify_child(a,n-1);
	}
}

void max_heap(int a[],int n)
{
	int i=n-1;
	
	while(i>=0)
	{
	    int prent=(i-1)/2;
		if(a[i]>a[prent])
		{
			swap(&a[i],&a[prent]);
			i=prent;
		}
		else
		{
			return;
		}
	}
	
}

int build_heap(int a[])
{
	 int i=1,j=0;
	 while(i)
	 {
	 	printf("Enter the value.\n");
	 	scanf("%d",&a[j]);
	 	j++;
	 	
	 	max_heap(a,j);
	 	printf("continue(1) or end(0)\n");
	 	scanf("%d",&i);
	 }
	 
   return j; 
}

 
int insert(int a[],int n,int value)
{
	if(n>=20)
	{
		printf("Overflow!!");
	}
	else if(n==0)
	{
		a[0]=value;
		n=n+1;
	}
	else
	{
	    a[n]=value;
	    n=n+1;
	    max_heap(a,n); 
   }
	 	
   return n;	
}


int extract_max(int a[],int n)
{
	if(n<=0)
	{
		printf("Underflow!!");
	}
	else{
		
	    a[0]=a[n-1];
	    a[n-1]=0;
	    n=n-1;
	    heapify(a,n,0);
    	heapify_child(a,n);
    }
	
	return n;
}

void heap_sort(int a[],int n)
{
 	while(n>0)
	{
		int temp=a[0];
		n=extract_max(a,n);
		a[n]=temp;	
	}
}

int print(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main()
{
	int arr[20];
	int n=0,q=1;
	while(q)
	{
		int choice,value;
		printf("Choose the opration.\n1.build heap\n2.heapify\n3.insert\n4.extract max\n5.Heap sort\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				   n=build_heap(arr);
				   printf("\nBuild heap: ");
	               print(arr,n);
	               break;
	        
	        case 2:
	        	  heapify(arr,n,0);
    	          heapify_child(arr,n);
    	          printf("\nheapify: ");
	              print(arr,n);
    	          break;
    	    
    	    case 3:
    	    	  printf("Enter the value you want to insert.\n");
    	    	  scanf("%d",&value);
    	    	  n=insert(arr,n,value);
    	    	  printf("\ninserted value heap: ");
    	    	  print(arr,n);
    	          break;
    	          
    	    case 4:
    	    	  n=extract_max(arr,n);
    	    	  printf("\nExtracted max heap: ");
    	    	  print(arr,n);
    	    	  break;
    	    	  
    	    case 5:
    	    	  heap_sort(arr,n);
    	    	  printf("\nsorted heap: ");
    	    	  print(arr,n);
    	    	  break;
			
			default:
			     printf("Invaid opration.\n");
				
		}
		
		printf("continue(1) or exit(0).\n");
		scanf("%d",&q);
	}
	
 
	
	return 0;
}
