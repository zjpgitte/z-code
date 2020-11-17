#include <stdio.h>
#include <malloc.h>
typedef struct Node
{
	int number;
	int secret;
	struct Node *Next;
}Node, *Linklist;
typedef struct
{
	Node *Head;
	Node *Rear;
}Link;
void Menu()
{
	printf("1.PLAY\n");
	printf("2.EXIT\n");
}
void InitList(Link *L)
{
   L -> Head = NULL;
   L -> Rear = NULL;
}
void InputSecret(Link *L, int n)
{
	Linklist s;
	int i = 0 ;
	int e = 0 ; 
	printf("������%d���˳��е�����:\n", n );
	
	for(i = 0 ; i < n ;i++ )
	{
		       scanf("%d", &e );
		       //if( e >= 1 && e <= n)
			
		        s = (Node*)malloc(sizeof(Node)) ;
				if( s == NULL) return;
	            s -> Next = NULL ;
		        s -> number = i+1 ;
		        s -> secret = e ;
				if(i == 0)
				{
			       L -> Head = s ;
				   L -> Rear = s ;
				   L -> Rear -> Next =L -> Head ;
				}
				else
				{
				   L -> Rear -> Next = s ;
		           L -> Rear = L -> Rear -> Next ;
				   L -> Rear -> Next = L -> Head ; 
				}
			
		  
		   /*{
			    printf("����������ÿ���˵�����(1 - %d )��", n ) ;
			    break;
		     }*/
		   

	
	} 
	printf("����ɹ�\n" );

}
void Input(Link *L,int *m , int *n)
{
	printf("�������������");
	scanf("%d" , &(*m) );
	printf("������Լɪ���е�������");
	scanf("%d", &(*n) );
	InputSecret(L,*n);//����ÿ���˵�����

}
void DeletNode( Link *L , Node *p, Node *q)
{
	q -> Next = p -> Next ;
	free( p );
}
/*void ReNumber(Link *L , Linklist p , int n)
{
	int i=0;
	for( i = 0 ; i < n ; i++ )
	{
         p -> number = i+1 ;
		 p =p -> Next   ; 
	}
 
}*/
void Start(Link *L, int m , int n)
{
	int i = 0;
	Linklist p,q;
	printf("�������У�\n");
	q = L -> Head ;
	p = L -> Rear ; 
    while(n > 0)
	{
        for(i = 0; i < m; i++)
		{
          p = p -> Next ;  
		}
		printf( "%d " , p -> number );
		m = p -> secret ;
		while( q -> Next != p )
		{
			q = q-> Next ; 
		}
		DeletNode( L , p ,q );
        n-- ;
		
		//ReNumber( L , p , n );
		p =q;
	}
	printf("\n");
}
void Game()
{
	int m = 0;
	int n = 0;
	Link L;
	InitList( &L );// ��ʼ������
	Input( &L , &m , &n );// ����Լɪ�򻷵�һϵ����Ϣ�������m������n��ÿ���˵�����secret
    Start( &L , m ,n);//��ʼ������Ϸ
    
}
int main()
{
	int Flag = 1;
	int select = 0;
   
	while(Flag)
		{
          Menu();
		 scanf("%d",&select);
         switch (select)
		 {
	    	case 1:Game();
			      break;
		    case 2:Flag=0;
			      break;
		    default:printf("����������\n");
			      break;

		}
	}







	return 0;
}