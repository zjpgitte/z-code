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
	printf("请输入%d个人持有的密码:\n", n );
	
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
			    printf("请重新输入每个人的密码(1 - %d )：", n ) ;
			    break;
		     }*/
		   

	
	} 
	printf("输入成功\n" );

}
void Input(Link *L,int *m , int *n)
{
	printf("请输入随机数：");
	scanf("%d" , &(*m) );
	printf("请输入约瑟夫环中的人数：");
	scanf("%d", &(*n) );
	InputSecret(L,*n);//输入每个人的密码

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
	printf("出队序列：\n");
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
	InitList( &L );// 初始化链表
	Input( &L , &m , &n );// 输入约瑟夫环的一系列信息：随机数m，人数n，每个人的密码secret
    Start( &L , m ,n);//开始数数游戏
    
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
		    default:printf("请重新输入\n");
			      break;

		}
	}







	return 0;
}