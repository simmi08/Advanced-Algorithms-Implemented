//FIBONACCI HEAP AND OPERATIONS ON IT//

#include<iostream>
#include<math.h>
using namespace std;

struct node
	    {
	      int n;
	      int degree;
	      node* parent;
	      node* child;
	      node* left;
	      node* right;
	      char mark;
	      char C;
	    };

int nH;
node* MAKE_FIB_HEAP();
int FIB_HEAP_LINK(node*,node*,node*);
node* CREATE_NODE(int);
node* FIB_HEAP_INSERT(node*,node*);
node* FIB_HEAP_UNION(node*,node*);
node* FIB_HEAP_EXTRACT_MIN(node*);
int CONSOLIDATE(node*);
int DISPLAY(node*);
int DISPLAY_1(node*);
node* H=MAKE_FIB_HEAP();
node* FIND_NODE(node*,int);
int FIB_HEAP_DECREASE_KEY(node*,int,int);
int FIB_HEAP_DELETE_KEY(node*,int);
int CUT(node*,node*,node*);
int CASCADE_CUT(node*,node*);
int PRESENT_NODE(node*);

int main()
  {
    char ch='y';
    int n,m,l;
    node* p;
    cout<<"\nENTER THE NUMBER OF ELEMENTS: ";
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
      cin>>m;
      p=CREATE_NODE(m);
      H=FIB_HEAP_INSERT(H,p);
    }
    cout<<"\nYOU HAVE ENTERED FOLLOWING HEAP :";
    DISPLAY(H);
    do
      {
	cout<<"\nENTER YOUR CHOICES:-\n";
	cout<<"\n >> 1)INSERT AN ELEMENT\n >> 2)EXTRACT THE MINIMUM KEY NODE\n >> 3)DECREASE A NODE KEY\n >> 4)DELETE A NODE\n >> 5)EXIT  >> 6) Union\n";
	cin>>l;
	switch(l)
	  {
	  case 1:do{
		 cout<<"\nENTER THE ELEMENT TO BE INSERTED:";
		 cin>>m;
		 p=CREATE_NODE(m);
		 H=FIB_HEAP_INSERT(H,p);
		 cout<<"\nNOW THE HEAP IS:\n";
		 DISPLAY(H);
		 cout<<"\nINSERT MORE??\n";
		 cin>>ch;
		   }while(ch=='Y'||ch=='y');
		 break;
	  case 2:do{
		 cout<<"\nEXTRACTING THE MINIMUM KEY NODE!!";
		 p=FIB_HEAP_EXTRACT_MIN(H);
		 if(p!=NULL)
		   cout<<"\nTHE EXTRACTED NODE IS "<<p->n;
		 cout<<"\nNOW THE HEAP IS:\n";
		 DISPLAY(H);
		 cout<<"\nEXTRACT MORE??\n";
		 cin>>ch;
		   }while(ch=='Y'||ch=='y');
		 break;
	  case 3:do{
		 cout<<"\nENTER THE KEY OF THE NODE TO BE DECREASED:";
		 cin>>m;
		 cout<<"\nENTER THE NEW KEY VALUE: ";
		 cin>>l;
		 FIB_HEAP_DECREASE_KEY(H,m,l);
		 cout<<"\nNOW THE HEAP IS:\n";
		 DISPLAY(H);
		 cout<<"\nDECREASE MORE??\n";
		 cin>>ch;
	           }while(ch=='Y'||ch=='y');
		 break;
	  case 4:do{
		 cout<<"\nENTER THE KEY TO BE DELETED: ";
		 cin>>m;
		 FIB_HEAP_DELETE_KEY(H,m);
		 cout<<"\nNOW THE HEAP IS:\n";
		 DISPLAY(H);
		 cout<<"\nDELETE MORE??\n";
		 cin>>ch;
		    }while(ch=='y'||ch=='Y');
		 break;
	  case 5:cout<<"\nGOOD BYE!!!\n";break;
          case 6 :
                 cout << "Enter elements in other heap";
                 int t;
                 cin >> t;node* J;
                for(int i=1;i<=t;i++)
    {
      cin>>m;
      p=CREATE_NODE(m);
      J=FIB_HEAP_INSERT(H,p);
    }
    H = FIB_HEAP_UNION(H,J);
    DISPLAY(H);
    break;
	  default :cout<<"\nINVALID ENTRY!!!!TRY AGAIN!!!!\n";
	  }
      }while(l!=5);

  }
  
  
node* MAKE_FIB_HEAP()
  {
    node* np;
    np=NULL;
    return np;
  }
  
node* CREATE_NODE(int k)
  {
    node* x=new node;
    x->n=k;
    return x;
  }
  
node* FIB_HEAP_INSERT(node* H,node* x)
  {
    x->degree=0;
    x->parent=NULL;
    x->child=NULL;
    x->left=x;
    x->right=x;
    x->mark='F';
    x->C='N';
    if(H!=NULL)
      {
	(H->left)->right=x;
	x->right=H;
	x->left=H->left;
	H->left=x;
	if(x->n<H->n)
	  H=x;
      }
    else
      {
	H=x;
      }
    nH=nH+1; 
    
    return H;
  }
  
int FIB_HEAP_LINK(node* H1,node* y,node* z)
  { //cout<<"\n in link";
    (y->left)->right=y->right;
    (y->right)->left=y->left;
    if(z->right==z)
      H1=z;
     y->left=y;
     y->right=y;
    y->parent=z;
    if(z->child==NULL)
      z->child=y;
    y->right=z->child;
    y->left=(z->child)->left;
    ((z->child)->left)->right=y;
    (z->child)->left=y;
    if(y->n<(z->child)->n)
      z->child=y;
   
    z->degree++;
    
    
  }

node* FIB_HEAP_UNION(node* H1,node* H2)
  {
    node* np;
    node* H=MAKE_FIB_HEAP();
    H=H1;
    (H->left)->right=H2;
    (H2->left)->right=H;
    np=H->left;
    H->left=H2->left;
    H2->left=np;
    return H;
  }
  
int DISPLAY(node* H)
  {
    node* p=H;
    if(p==NULL)
      {
      cout<<"\nHEAP EMPTY!!!\n";
      return 0;
      }
    cout<<"\nTHE ROOT NODES OF THE HEAP ARE:\n";
    do{
       cout<<p->n;
      
       p=p->right;
       
       
       if(p!=H)
       {cout<<"-->";}
    }while(p!=H);
    cout<<"\n";
  }

node* FIB_HEAP_EXTRACT_MIN(node* H1)
  {
    node* p;node* ptr;
    node* z=H1;
    p=z;
    
    ptr=z;
    if(z==NULL)
     return z;
    node* x;
    node* np;
    x=NULL;
    if(z->child!=NULL)
	x=z->child;
    if(x!=NULL)
      {
	ptr=x;
	do
	  {
	    np=x->right;
	  (H1->left)->right=x;
	  x->right=H1;
	  x->left=H1->left;
	  H1->left=x;
	  if(x->n<H1->n)
	    H1=x;
	  x->parent=NULL;
	 
	  x=np;
	 
	  }while(np!=ptr);
      }  
    (z->left)->right=z->right;
    (z->right)->left=z->left;
     H1=z->right;
    
    if(z==z->right&&z->child==NULL)
    {
      H=NULL;
    }
    
    else
      {
	H1=z->right;
	CONSOLIDATE(H1);
	
      }
    nH=nH-1;
    return p;
  }
  
int CONSOLIDATE(node* H1)
  {
    int d;
    float f=(log(nH))/(log(2));
    int D=f;
    node* A[D];
    for(int i=0;i<=D;i++)
	A[i]=NULL;
    node* x=H1;
    node* y;
    node* np;
    node* pt=x;
    do
      {
	pt=pt->right;
	d=x->degree;
	while(A[d]!=NULL)
	  {
	    y=A[d];
	    if(x->n>y->n)
	      {
		np=x;
		x=y;
		y=np;
		
	      }
	    if(y==H1)
	      H1=x;
	    //cout<<"\nx="<<x->n<<" y="<<y->n;
	    FIB_HEAP_LINK(H1,y,x);  
	    if(x->right==x)
	      H1=x;
	   // DISPLAY(H1);
	    A[d]=NULL;
	    d=d+1;
	   //cout<<"\namrendra!!";
	      
	  }
	
	A[d]=x;
	
	x=x->right;
      }while(x!=H1);
   H=NULL;
  
   for(int j=0;j<=D;j++)
    {
      if(A[j]!=NULL)
	{
	  A[j]->left=A[j];
	  A[j]->right=A[j];
	
	  if(H!=NULL)
	{
	(H->left)->right=A[j];
	A[j]->right=H;
	A[j]->left=H->left;
	H->left=A[j];
	if(A[j]->n<H->n)
	  H=A[j];
	}
    else
	{
	H=A[j];
	}
	  if(H==NULL)
	    H=A[j];
	  else if(A[j]->n<H->n)
	    H=A[j];
	 
	}
    }
    
  }
  
int DISPLAY_1(node* H)
  {cout<<"\nthrough display 1";
  
     node* p=H;
    if(p==NULL)
      {
      cout<<"\nHEAP EMPTY!!!\n";
      return 0;
      }
    cout<<"\nTHE ROOT NODES OF THE HEAP ARE:\n";
    do{
       cout<<p->n;
       if(p->child!=NULL)cout<<" child="<<(p->child)->n;else cout<<" child="<<0;
       p=p->left;
       
       
       if(p!=H)
       {cout<<"-->";}
    }while(p!=H);
    cout<<"\n";
  }
  
int FIB_HEAP_DECREASE_KEY(node*H1,int x,int k)
  {
    node* y;
    if(H1==NULL)
      {
	cout<<"\nNO NODE IN THE HEAP!!! ABORTING!!!!";
	return 0;
      }
    node* ptr=FIND_NODE(H1,x);
    if(ptr==NULL)
      {
	cout<<"\nTHE TARGET NODE NOT FOUND!!!!!";
	return 1;
      }
  
    if(ptr->n<k)
      {
	cout<<"\nTHE ENTERED KEY IS GREATER THAN THE CURRENT VALUE!!!";
	return 0;
      }
    ptr->n=k;
    y=ptr->parent;
    if(y!=NULL&&ptr->n<y->n)
      {
	CUT(H1,ptr,y);
	CASCADE_CUT(H1,y);
      }
   if(ptr->n<H->n)
    H=ptr;
   return 0;
  }
  
int CUT(node* H1,node* x,node* y)
  {
    
    if(x==x->right)
      y->child=NULL;
    (x->left)->right=x->right;
    (x->right)->left=x->left;
    if(x==y->child)
      y->child=x->right;
    y->degree=y->degree-1;
    x->right=x;
    x->left=x;
    (H1->left)->right=x;
    x->right=H1;
    x->left=H1->left;
    H1->left=x;
    x->parent=NULL;
    x->mark='F';
  }
  
  
int CASCADE_CUT(node* H1,node* y)
  {
    node* z=y->parent;
    if(z!=NULL)
      {
	if(y->mark=='F')
	    {
	      y->mark='T';
	    }
	else
	  {
	    CUT(H1,y,z);
	    CASCADE_CUT(H1,z);
	  }
	      
      }
  }
  
  
node* FIND_NODE(node* H,int k)
  {
    node* x=H;
    x->C='Y';
    node* p=NULL;
    if(x->n==k)
      {
	p=x;
	x->C='N';
	return p;
      }
    if(x->child!=NULL&&p==NULL)
      {
      p=FIND_NODE(x->child,k);
      }
    if((x->right)->C!='Y'&&p==NULL)
      {
      p=FIND_NODE(x->right,k);
      }
    x->C='N';  
    return p; 
  }
 
int FIB_HEAP_DELETE_KEY(node* H1,int k)
  {
    node* np=NULL;
    int t;
    t=FIB_HEAP_DECREASE_KEY(H1,k,-5000);
   
    if(!t)
      np=FIB_HEAP_EXTRACT_MIN(H);
    if(np!=NULL)
      cout<<"\nTHE KEY DELETED SUCCESSFULLY!!";
    else 
      cout<<"\nA PROBLEM OCCURED DURIING DELETION!!!";
    return 0;
  }
  
int PRESENT_NODE(node* H)
  {
    node* x=H;
    cout<<"("<<x->n<<") ";
    x->C='Y';
    
    if(x->child!=NULL)
      {
      PRESENT_NODE(x->child);
      }
    if((x->right)->C!='Y')
      {
      PRESENT_NODE(x->right);
      }
    x->C='N';  
   
  }
