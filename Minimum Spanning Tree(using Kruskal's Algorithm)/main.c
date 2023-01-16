#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define rep(n) for(int i=0;i<n;i++)
#define V 50

typedef struct Nodes nd;
void insertEdgeAdjList();
void findMST();


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
            printf("\nCHOOSE AN OPTION\n\n(1)INSERT GRAPH EDGES\n(2)DISPLAY GRAPH\n(3)CREATE A MST\n(4)EXIT\n");
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

            case '3': findMST(edges,n,e);
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

//Comparator function for qsort()

bool comparator(nd n1,nd n2)
{
	return n1.cost > n2.cost;
}

//Function to find the absolute parent of a vertex

int find_parent(int edge,int parent[]){

    if(parent[edge]==-1) return edge;

    return parent[edge] = find_parent(parent[edge],parent);

}

//Function to union two disjoint subset

void union_of_subset(int from_v, int to_v, int parent[],int rank[]){

    from_v = find_parent(from_v,parent);
    to_v = find_parent(to_v,parent);

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

//Function for finding Minimum Spanning Tree using Disjoint Set Algorithm

void findMST(nd edge[], int n,int e){

    qsort(edge,e,sizeof(edge[0]),comparator);

    int parent[V];
    int rank[V];

    for (int i = 0; i < n; i++) parent[i] = -1,rank[i] = 0;

    int i = 0,j = 0;
    while(i<n-1&& j<e){

     //Finding absolute parents of subset
     int from_v = find_parent(edge[i].src,parent);
     int to_v = find_parent(edge[i].dest,parent);

     if(from_v==to_v){
        j++;
        continue;
     }

     //Union of two subsets
     union_of_subset(from_v,to_v,parent,rank);
     printf("   (%d)\n",edge[i].cost);
     printf("%d------>%d\n\n",edge[i].src,edge[i].dest);
     i++;

    }
}

