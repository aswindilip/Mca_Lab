//program to implement prim's alogritham 
#include<stdio.h>
#include<stdlib.h>

int i,j,u,v,a,b,n,ne=1;
int visited[10]={0},min,cost[10][10],mincost;

void main(){
    
    printf("\n Enter the number of nodes :");
    scanf("%d",&n);

    printf("\n Enter the adjacency matrix :\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j]=999;
            }
        }

    visited[1]=1;
    while(ne<n){
        for(i=1,min=999;i<=n;i++)
            for(j=1;j<=n;j++){
                if(cost[i][j]<min)
                    if(visited[i]!=0){
                        min = cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
            }

        if(visited[u]==0||visited[v]==0){
            printf("edge %d :(%d,%d) cost %d \n",ne++,a,b,min);
            mincost+=min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\n Minimum cost = %d",mincost);
}