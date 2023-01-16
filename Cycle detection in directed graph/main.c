#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define rep(n) for(int i=0;i<n;i++)
#define V 50


int AdjMatrix[V][V]={0};
char G[V];

char insertEdgeAdjMatrix();
bool isCycle();

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
            printf("\nCHOOSE AN OPTION\n\n(1)INSERT GRAPH EDGES\n(2)ENTER GRAPH VERTICES\n(3)DISPLAY GRAPH\n(4)CHECK CYCLE IN GRAPH\n(5)EXIT\n");
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

            case '4': {
                        if(isCycle(n))
                            printf("\nCYCLE EXIST IN GRAPH\n");
                        else
                            printf("\nNO CYCLE EXIST IN GRAPH\n");
                      }
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
        //For directed graph
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
        for(int j=0;j<n;j++) printf(" %d ",AdjMatrix[i][j]);
        printf("\n");
    }

}

//DFS function to traverse the Adjacency Matrix and detect a cycle in the graph

bool dfs(int i,bool visited[], bool curr_path[],int n){

    visited[i] = true;
    curr_path[i] = true;
    for(int j=0;j<n;j++){
            if(AdjMatrix[i][j]!=0 && visited[j]==false ){

                if(dfs(j,visited,curr_path,n)) return true;

            }
            else if(AdjMatrix[i][j]!=0 && curr_path[j]){
                  return true;
                }


    }
    curr_path[i]=false; //back-tracking if current traversed path have no cycle
    return false;

}

//Function for finding Cycle in directed graph

bool isCycle(int n){

    bool visited[V]; //Keeps a log of all the visited vertices in the graph
    bool curr_path[V]; //Keeps a log of current traversing path
    for (int i = 0; i < n; i++) visited[i] = false,curr_path[i] = false;

    for(int i=0;i<n;i++){

            if(!visited[i]){
                if(dfs(i,visited,curr_path,n)) return true;
            }
    }
   return false;

}

