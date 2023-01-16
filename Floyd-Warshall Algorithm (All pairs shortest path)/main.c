#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define rep(n) for(int i=0;i<n;i++)
#define V 50



/*

Floyd Warshall Algorithm is used compute all pairs shortest path from source node to all other nodes individually in the graph
and work with both negative as well as positive weighted edge directed graph only.
And can detect negative edge cycle in graph if diagonal element of matrix are AdjMatrix[0][0]<0.
Time Complexity : O(V^3)
Space Complexity : O(V^2)

(i) AdjMatrix[i][k]+AdjMatrix[k][j] < AdjMatrix[i][j]
(ii) AdjMatrix[i][j] = AdjMatrix[i][k]+AdjMatrix[k][j]

*/

int AdjMatrix[V][V]={0};
char G[V];

char insertEdgeAdjMatrix();
void Floyd_Warshall_All_Pairs_Shortest_Path();

int main()
{


    int n;
    printf("\n");
    rep(40) printf("=");
    printf("\nENTER NO. OF NODES IN THE GRAPH : ");
    scanf("%d",&n);
    printf("\n");
    while(1){
            printf("\n");
            rep(40) printf("=");
            printf("\n");
            rep(40) printf("-");
            char choice;
            printf("\nCHOOSE AN OPTION\n\n(1)INSERT GRAPH EDGES\n(2)ENTER GRAPH VERTICES\n(3)DISPLAY GRAPH\n(4)COMPUTE ALL PAIRS SHORTEST PATH\n(5)EXIT\n");
            printf("\nSELECT OPTION : ");
            scanf(" %c",&choice);
            printf("\n");
            rep(40) printf("-");
            printf("\n");
           switch(choice){

            case '1': {
                      char e='y';
                      while(e!='n'){

                          e = insertEdgeAdjMatrix(n);

                      }
                      for(int i =0;i<n;i++){
                        for(int j=0;j<n;j++){
                            if(AdjMatrix[i][j]==0 && i!=j){

                                AdjMatrix[i][j]=INT_MAX;
                            }
                        }
                      }
                    }
                     break;

            case '2': enterGraphVertex(n);
                      break;

            case '3': printAdjMatrix(n);
                      break;

            case '4': Floyd_Warshall_All_Pairs_Shortest_Path(n);
                      break;

            case '5': exit(0);
                      break;

            default: printf("\nWRONG SELECTION!!! CHOOSE A CORRECT OPTION\n");

        }
    }
    rep(40) printf("=");
    printf("\n");
    getch();
    return 0;


}


//Function for inserting edge cost into the adjacency matrix

char insertEdgeAdjMatrix(int n){

    int row=0,col=0,cost=0;
    char e;
    printf("\nENTER ROW AND COLUMN : ");
    scanf("%d %d",&row,&col);
    if(row>=n||col>=n) printf("\nUNABLE TO UPDATE VERTEX!!\n");
    else{
        printf("\nEDGE COST : ");
        scanf("%d",&cost);
        AdjMatrix[row][col]=cost;
    }
    printf("\nCONTINUE (y/n) : ");
    scanf(" %c",&e);
    return e;

}

//Function for entering graph vertex

void enterGraphVertex(int n){

    printf("\n");
    rep(40) printf("*");
    printf("\nENTERING GRAPH VERTICES\n");
    for(int i=0;i<n;i++){
      printf("\nENTER NODE %d: ",(i+1));
      scanf(" %c",&G[i]);
    }
    rep(40) printf("*");
    printf("\n");

}

//Function for printing graph

void printAdjMatrix(int n){

    printf("\n<-<-<-ADJACENCY MATRIX OF GRAPH->->->\n\n");
    for(int i=0;i<n;i++){
        printf("\n VERTEX %c:  ",G[i]);
        for(int j=0;j<n;j++){
          if(AdjMatrix[i][j]!=INT_MAX)
                printf("%7d",AdjMatrix[i][j]);
          else
            printf("%7s","INF");
        }
        printf("\n");
    }

}


void Floyd_Warshall_All_Pairs_Shortest_Path(int n){

    int dist[V][V];
    //Copying the original matrix to new matrix dist
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dist[i][j] = AdjMatrix[i][j];

    //Finding all pairs shortest path by trying all possible paths
    for(int k=0;k<n;k++){ //Try all intermediate nodes
        for(int i=0;i<n;i++){ //Try for all possible starting positions
            for(int j=0;j<n;j++){ //Try for all possible ending positions

                if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
                    continue;

                else if(dist[i][k]+dist[k][j]<dist[i][j]){

                    dist[i][j] = dist[i][k]+dist[k][j];

                }

            }
        }
    }

    //Checking for negative edge weight cycle
    for(int i =0;i<n;i++){

        if(dist[i][i]<0){

            printf("\nGRAPH HAS NEGATIVE EDGE CYCLE");
            return;

        }

    }

    for(int i=0;i<n;i++){
        printf("\n VERTEX %c:  ",G[i]);
        for(int j=0;j<n;j++){
          if(dist[i][j]!=INT_MAX)
                printf("%7d",dist[i][j]);
          else
            printf("%7s","INF");
        }
        printf("\n");
    }


}
