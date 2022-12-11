#include <stdio.h>
#include <stdlib.h>
#define rep(n) for(int i=0;i<n;i++)
#define V 50
typedef struct Node sq;

int AdjMatrix[V][V]={0};
char G[V];

char insertEdgeAdjMatrix();

//Structure for implementing queue for BFS

struct Node
{
    int data;
    struct Node *next;
};
sq *front=NULL;
sq *rear=NULL;

//return queue status: Empty or Not

int isEmpty(){
    if(front==NULL&&rear==NULL) return 1;

    return 0;
}

//return queue status: Full or Not

int isFull(){
    sq *newnode = (sq*)malloc(sizeof(sq));
    if(newnode==NULL) return 1;

    return 0;
}



void enque(int x)
{
    if(isFull()){
        printf("\nQUEUE OVERFLOW!!!\n");
        return;
      }

      sq *newnode;
      newnode = (sq*)malloc(sizeof(sq));
      newnode->data =x;
      newnode->next = 0;

      if(front==0 && rear==0)
      {

          front=rear=newnode;

      }
      else
      {
          rear->next = newnode;
          rear = newnode;

      }

}



int deque()
{
    if(isEmpty())
    {
        printf("\nQUEUE UNDERFLOW!!!\n");
    }
    else
    {
       int x;
       sq *temp;
       temp = front;
       x = temp->data;
       if(front->next==NULL){
           front=rear=NULL;
           free(temp);
           return x;
       }
       else{

            front = front->next;
            free(temp);
            return x;
       }

    }
}


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
            printf("\nCHOOSE AN OPTION\n\n(1)INSERT GRAPH EDGES\n(2)ENTER GRAPH VERTICES\n(3)DISPLAY GRAPH\n(4)BREADTH FIRST SEARCH\n(5)EXIT\n");
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

            case '4': BFS(n);
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

void BFS(int n){

    int i=1;
    printf("\nBFS RESULT: %d",i);
    enque(i);
    int visited_que[V]={0};
    while(!isEmpty()){

        int vertex = deque();
        visited_que[i]=1;
        for(int j=0;j<n;j++){
            if(AdjMatrix[vertex][j]==1  && visited_que[j]==0){
              printf(" %d ",j);
              visited_que[j]=1;
              enque(j);
            }
        }
    }

}
