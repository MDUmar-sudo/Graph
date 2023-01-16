#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define rep(n) for(int i=0;i<n;i++)
#define V 50

/*

Cycle in Undirected graph can be  modified by using path compression in
union and generating absolute parent of a element in graph

Time Complexity(Naive Approach):O(E*V)
Time Complexity(Modified Approach):O(E*logV)

*/

typedef struct Nodes nd;
void insertEdgeAdjList();
bool isCycle();


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
            printf("\nCHOOSE AN OPTION\n\n(1)INSERT GRAPH EDGES\n(2)DISPLAY GRAPH\n(3)CHECK CYCLE IN GRAPH\n(4)EXIT\n");
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
                        if(isCycle(edges,n,e))
                            printf("\nCYCLE EXIST IN GRAPH\n");
                        else
                            printf("\nNO CYCLE EXIST IN GRAPH\n");
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

//Function to find the absolute parent of a vertex

int find_parent(int edge,int parent[]){

    if(parent[edge]==-1) return edge;

    return parent[edge]=find_parent(parent[edge],parent);

}

//Function to union two disjoint subset

void union_of_subset(int from_v, int to_v, int parent[],int rank[]){

    if(rank[from_v]<rank[to_v])
        parent[from_v] = to_v;

    else if(rank[from_v]>rank[to_v])
        parent[to_v] = from_v;

    else{
        parent[from_v] = to_v;
        //the rank increases if the ranks of two sets are same
        rank[to_v]++;
    }

}

//Function for finding Cycle in undirected graph

bool isCycle(nd edge[],int n,int e){

    int parent[V];
    int rank[V]    ;
    for (int i = 0; i < n; i++) parent[i] = -1,rank[i] = 0;

    for(int i=0;i<e;i++){

     //Finding absolute parents of subset
     int from_v = find_parent(edge[i].src,parent);
     int to_v = find_parent(edge[i].dest,parent);

     if(from_v==to_v) return true;

     //Union of two subsets
     union_of_subset(from_v,to_v,parent,rank);

    }
    return false;
}

