#include<stdio.h>
int a[50][50], n, visited[50];
int q[20], front = -1,rear = -1;
int s[20], top = -1, count=0;
void bfs(int v)
{
         int i, cur;
         visited[v] = 1;
         q[++rear] = v;
         while(front!=rear)
        {
                cur = q[++front];
                for(i=1;i<=n;i++)
               {
                        if((a[cur][i]==1)&&(visited[i]==0))
                       {
                                 q[++rear] = i;
                                  visited[i] = 1;
                                  printf("%d ", i);
                        }
               }
        }
}
void dfs(int v)
{
         int i;
         visited[v]=1;
         s[++top] = v;
         for(i=1;i<=n;i++)
        {
                 if(a[v][i] == 1&& visited[i] == 0 )
                 {
                           printf("%d ", i);
                           dfs(i);
                  }
         }
}
int main()
{
int ch, start, i,j;
char c,dummy; 
printf("ENTER THE NUMBER VERTICES "); 
scanf("%d",&n); 
for(i=1;i<=n;i++) 
{ 
for(j=1;j<=n;j++) 
{ 
printf(" %d --> %d : ",i,j); 
scanf("%d",&a[i][j]); 
} 
} 
printf("THE ADJACENCY MATRIX IS\n"); 
for(i=1;i<=n;i++) 
{ 
for(j=1;j<=n;j++) 
{ 
printf(" %d",a[i][j]); 
} 
printf("\n"); 
} 
do{
    for(i=1;i<=n;i++)
           visited[i]=0;
        printf("\n********** MENU **************\n");
        printf("\n1. Breadth First Search");
        printf("\n2. Depth First Search");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
        printf("\nEnter The Starting Vertex: ");
        scanf("%d",&start);
        switch(ch)
        {
            case 1:
                       printf("\nNodes Reachable From Starting Vertex %d Are: ", start);
                    bfs(start);
                    for(i=1;i<=n;i++)
                    {
                        if(visited[i]==0)
                            printf("\nThe Vertex That Is Not Reachable Is %d" ,i);
                    }
                    break;
            case 2:
       printf("\nNodes Reachable From Starting Vertex %d Are:\n",start);
                    dfs(start);
                    break;
           default: printf("\nPlease Enter Valid Choice: ");
           }printf("\nDO U WANT TO CONTINUE(Y/N) ? : "); 
scanf("%c",&dummy); 
scanf("%c",&c); 
}
while((c=='y')||(c=='Y'));        
}