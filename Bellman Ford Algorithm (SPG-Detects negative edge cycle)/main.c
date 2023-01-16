#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define rep(n) for(int i=0;i<n;i++)
#define V 50

/*

Bellman Ford Algorithm for computing Shortest path from source node to all the node.
It does work with negative weight edge directed graph only and detects negative edge cycle.
But does not work with graph having effective edge weight negative (i.e. negative edge cycle exist in graph).
Time Complexity: O(VE)

(i) d(x)+c(x,y) <d(y)
(ii) d(y) = d(x)+c(x,y)

*/

typedef struct Nodes nd;
void insertEdgeAdjList();
void Bellman_Ford_Shortest_Path();


//Structure for representing individual edges in Adjacency List

struct Nodes{

    int src;
    int dest;
    int cost;

};

//Function to create graph edges

nd createGraphEdge(int src,int dest,int cost){

    nd node;
    node.src = src;
    node.dest = dest;
    node.cost = cost;
    return node;

}


int main()
{

    int n,e;
    printf("\n");
    rep(45) printf("=");
    printf("\nENTER NO. OF VERTICES & EDGES IN THE GRAPH : ");
    scanf("%d %d",&n,&e);
    nd edges[e];
    printf("\n");
    while(1){
            printf("\n");
            rep(45) printf("=");
            printf("\n");
            rep(45) printf("-");
            char choice;
            printf("\nCHOOSE AN OPTION\n\n(1)INSERT GRAPH EDGES\n(2)DISPLAY GRAPH\n(3)COMPUTE SHORTEST PATH\n(4)EXIT\n");
            printf("\nSELECT OPTION : ");
            scanf(" %c",&choice);
            printf("\n");
            rep(45) printf("-");
            printf("\n");
           switch(choice){

            case '1': insertEdgeAdjList(edges,n,e);
                      break;

            case '2': printAdjList(edges,e);
                      break;

            case '3': {
                        int src;
                        printf("ENTER SOOURCE NODE TO COMPUTE SHORTEST PATH : ");
                        scanf("%d",&src);
                        if(src>=0 && src<n)
                            Bellman_Ford_Shortest_Path(edges,e,n,src);
                        else
                            printf("\nNODE DOESN'T EXIST IN THE GRAPH\n");
                      }
                      break;

            case '4': exit(0);
                      break;

            default: printf("\nWRONG SELECTION!!! CHOOSE A CORRECT OPTION\n");

        }
    }
    rep(45) printf("=");
    printf("\n");
    getch();
    return 0;
}

//Function for inserting edge cost into the adjacency list

void insertEdgeAdjList(nd edges[],int n,int e){

    int src=0,dest=0,cost=0;
    for(int i;i<e;i++){

        printf("\nENTER SOURCE AND DESTINATION : ");
        scanf("%d %d",&src,&dest);
        if(src>=n||dest>=n){
          printf("\nUNABLE TO UPDATE VERTEX!!\n");
          i--;
        }
        else{
                printf("\nEDGE COST : ");
                scanf("%d",&cost);

                nd newNode = createGraphEdge(src,dest,cost);
                edges[i] = newNode;

            }
    }


}

//Function for printing adjacency list of graph

void printAdjList(nd edges[],int e){

        printf("\n<-<-<-ADJACENCY LIST OF GRAPH->->->\n\n");
        for(int i=0;i<e;++i){
          printf("   (%d)\n",edges[i].cost);
          printf("%d------>%d\n\n",edges[i].src,edges[i].dest);
        }
        printf("\n");

}


void Bellman_Ford_Shortest_Path(nd edges[], int e, int n,int src){

    int parent[V]={-1}; //Stores Shortest path graph from source
    int cost_parent[V];
    int value[V]; //Used for edge relaxation. Initially, Set to infinity.

    for(int i=0;i<n;i++) parent[i] = -1, value[i] = INT_MAX;

    parent[src] = -1; //Starting node has no parents
    value[src] = 0; //Starting node has value 0. So, that it's picked first


    bool updated;
    //Included (V-1) edges to cover all V vertices
    for(int i=0;i<n-1;i++){

        updated = false;
        for(int j = 0; j<e;j++){

            int x = edges[j].src;
            int y = edges[j].dest;
            int wt = edges[j].cost;
            if(value[x]!=INT_MAX && value[x]+wt<value[y]){

                value[y] = value[x] + wt;
                parent[y] = x;
                updated = true;

            }


        }
        if(!updated){
                break;
            }

    }

    //Checking V time for negative edge cycle in graph
    for(int j=0;j<e && updated==true; j++){

            int x = edges[j].src;
            int y = edges[j].dest;
            int wt = edges[j].cost;
            if(value[x]!=INT_MAX && value[x]+wt<value[y]){

                printf("\nGRAPH HAS NEGATIVE EDGE CYCLE");
                return;
            }

    }

    //Printing Shortest Path to every node from the source using Bellman Ford Algorithm
    printf("Edge \t\t\tWeight\n");
    for(int i=0;i<n;i++){

        if(parent[i]!=-1){

            printf("%d --> %d \tCost from %d to node = %7d \n", parent[i], i,src,value[i]);

        }

    }

}

