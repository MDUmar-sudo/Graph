#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define rep(n) for(int i=0;i<n;i++)
#define V 50


int AdjMatrix[V][V]={0};
char G[V];

char insertEdgeAdjMatrix();
void findMST();

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
            printf("\nCHOOSE AN OPTION\n\n(1)INSERT GRAPH EDGES\n(2)ENTER GRAPH VERTICES\n(3)DISPLAY GRAPH\n(4)CREATE A MST\n(5)EXIT\n");
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

            case '4': findMST(n);
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

int selectMinVertex(int value[],bool setMST[],int n){

    int min_edge = INT_MAX;
    int vertex;
    for(int i=0;i<n;i++){
        if(setMST[i]==false && value[i]<min_edge){
            vertex=i;
            min_edge = value[i];
        }
    }

    return vertex;
}

void findMST(int n){

    int parent[V]={-1}; //Stores MST
    int value[V]; //Used for edge relaxation. Initially, Set to infinity.
    bool setMST[V]; //1->Vertex is included in MST

    for (int i = 0; i < n; i++) value[i] = INT_MAX, setMST[i] = false;


    //Assuming start point to be node 0
    parent[0]=-1; //Start node has no parent;
    value[0]=0;  //Start node has value = 0, so that it's picked up first

    //Forming MSt with (V-1) edges
    for(int i=0;i<n-1;i++){

        //Selecting best vertex (i.e. minimum edge) by applying greedy method
        int u = selectMinVertex(value,setMST,n);
        setMST[u]=true;

        //Relaxing adjacent vertices (not in MST)
        for(int j=0;j<n;j++){

            //Constraints  to relax:
            //1.Edge is present in u to j
            //2.Vertex j is not in MST
            //3.Edge weight is smaller than current edge weight


            if(AdjMatrix[u][j] && setMST[j]==false && AdjMatrix[u][j]<value[j]){

                parent[j]=u;
                value[j]=AdjMatrix[u][j];

            }
        }
    }

    printf("Edge \t\tWeight\n");
    for(int i=1;i<n;i++){

        printf("%d --> %d \t%d \n", parent[i], i,AdjMatrix[parent[i]][i]);
    }


}
