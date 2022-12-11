#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define rep(n) for(int i=0;i<n;i++)
#define V

char G[V];

typedef struct Nodes nd;
typedef struct LinkedList ll;
typedef struct Graph g;
char insertEdgeAdjList();


//Structure for representing individual nodes in Adjacency List

struct Nodes{

    int dest;
    int cost;
    struct Nodes *next;

};

//Structure for representing each vertices linked list in Adjacency List

struct LinkedList{

    struct Nodes *head;

};

//Structure for representing graph

struct Graph{

    int v; //vertices in the graph
    struct LinkedList *arr;

};

nd *createNode(int dest,int cost){

    nd *node = (nd*)malloc(sizeof(nd));
    node->dest = dest;
    node->cost = cost;
    node->next = NULL;
    return node;

}


g *createGraph(int n){

    g *graph = (g*)malloc(sizeof(g));
    graph->v = n;
    graph->arr = (ll*)malloc(sizeof(ll)*n);
    rep(n) graph->arr[i].head = NULL; //Initializing each vertices Adjacency List to empty
    return graph;

}

bool isGraphEmpty(g *grp){

    for(int i=0;i<grp->v;++i){
        if(grp->arr[i].head!=NULL) return false;
    }
    return true;

}

int main()
{

    int n;
    printf("\n");
    rep(40) printf("=");
    printf("\nENTER NO. OF NODES IN THE GRAPH : ");
    scanf("%d",&n);
    g *graph = createGraph(n);
    printf("\n");
    while(1){
            printf("\n");
            rep(40) printf("=");
            printf("\n");
            rep(40) printf("-");
            char choice;
            printf("\nCHOOSE AN OPTION\n\n(1)INSERT GRAPH EDGES\n(2)ENTER GRAPH VERTICES\n(3)DISPLAY GRAPH\n(4)EXIT\n");
            printf("\nSELECT OPTION : ");
            scanf(" %c",&choice);
            printf("\n");
            rep(40) printf("-");
            printf("\n");
           switch(choice){

            case '1': {
                      char e='y';
                      while(e!='n'){

                          e = insertEdgeAdjList(graph,n);

                      }
                    }
                      break;

            case '2': enterGraphVertex(n);
                      break;

            case '3': printAdjList(graph,n);
                      break;

            case '4': exit(0);
                      break;

            default: printf("\nWRONG SELECTION!!! CHOOSE A CORRECT OPTION\n");

        }
    }
    rep(40) printf("=");
    printf("\n");
    getch();
    return 0;
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

//Function for inserting edge cost into the adjacency list

char insertEdgeAdjList(g *grp,int n){

    int src=0,dest=0,cost=0;
    char e;
    printf("\nENTER SOURCE AND DESTINATION : ");
    scanf("%d %d",&src,&dest);
    if(src>=n||dest>=n) printf("\nUNABLE TO UPDATE VERTEX!!\n");
    else{
        printf("\nEDGE COST : ");
        scanf("%d",&cost);

        nd* temp=NULL;
        nd* newNode = createNode(dest,cost);

        if(grp->arr[src].head==NULL){
            newNode->next = NULL;
            grp->arr[src].head=newNode;
        }
        else{
            temp = grp->arr[src].head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;

        }

        /*
            If graph is undirected than execute this block
        */
        newNode = createNode(src,cost);
        if(grp->arr[dest].head==NULL){
            newNode->next = NULL;
            grp->arr[dest].head=newNode;
        }
        else{
            temp = grp->arr[dest].head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;

        }


    }
    printf("\nCONTINUE (y/n) : ");
    scanf(" %c",&e);
    return e;

}

void printAdjList(g *grp,int n){

    if(isGraphEmpty(grp)) printf("\nGRAPH ISN'T AVAILABLE!!\n");
    else{
        printf("\n<-<-<-ADJACENCY LIST OF GRAPH->->->\n\n");
        for(int i=0;i<n;++i){
        nd *ptr=grp->arr[i].head;
        printf("\nVERTEX %c(%d): HEAD",G[i],i);
        while(ptr){
            printf("--[%d]->%d ",ptr->cost,ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
     }
    }

}

