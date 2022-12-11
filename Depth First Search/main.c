#include <stdio.h>
#include <stdlib.h>
#define rep(n) for(int i=0;i<n;i++)
#define V 50

int AdjMatrix[V][V]={0};
char G[V];
int visited_que[V]={0};

char insertEdgeAdjMatrix();


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
            printf("\nCHOOSE AN OPTION\n\n(1)INSERT GRAPH EDGES\n(2)ENTER GRAPH VERTICES\n(3)DISPLAY GRAPH\n(4)DEPTH FIRST SEARCH\n(5)EXIT\n");
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
                    }
                      break;

            case '2': enterGraphVertex(n);
                      break;

            case '3': printAdjMatrix(n);
                      break;

            case '4': DFS(0,n);
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

//Function to initializing the adjacency matrix

void initializeAdjMatrix(int arr[][V],int n){

   for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=0;

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
        AdjMatrix[row][col]=AdjMatrix[col][row]=cost;
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
        for(int j=0;j<n;j++) printf(" %d ",AdjMatrix[i][j]);
        printf("\n");
    }

}

//Function implements Breadth First Search utilizing adjacency matrix

void DFS(int v,int n){

        printf(" %d ",v);
        visited_que[v]=1;
        for(int j=0;j<n;j++){
            if(AdjMatrix[v][j]==1  && visited_que[j]==0){
              DFS(j,n);
            }
        }

}
