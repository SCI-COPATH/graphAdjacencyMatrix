#include <stdio.h>
#define MAX 10
int top=-1;
int stack[MAX];
int graph[20][20];
int frond=-1,rear=-1;
int queue[MAX];
int ar[MAX];
int isNull(){
    if(frond==-1&&rear==-1)
        return 1;
    return 0;
}
void enQueue(int value){
    if(isNull()==1){
        frond=0;
        rear=0;
    }
    else{
        rear=(rear+1)%MAX;
    }
    queue[rear]=value;
}
int deQueue(){
    if(isNull()==1)
        return 0;
    if(frond==rear){
        int data=queue[frond];
        frond=-1;
        rear=-1;
        return data;
    }
    else{
        int data=queue[frond];
        frond=(frond+1)%MAX;
        return data;
    }
}
void push(int data){
    if(top<MAX-1){
        stack[++top]=data;
    }
}
int pop(){
    if(top!=-1){
        top--;
    return stack[top+1];
    }
}
void viewGraph(int n){
    printf("\nGraphs is \n");
    int i,j;
    printf("   ");
    for(i=0;i<n;i++)
        printf("%d ",i);
    printf("\n");
    printf("---");
    for(i=0;i<n;i++)
        printf("--");
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d | ",i);
        for(j=0;j<n;j++)
            printf("%d ",graph[i][j]);
        printf("\n");
    }
}
void BFS(int n){
    int i,value;
    printf("BFS : ");
    for(i=0;i<n;i++)
        ar[i]=0;
    enQueue(0);
    ar[0]=1;
    while(isNull()==0){
        value=deQueue();
        printf("%d,",value);
        for(i=0;i<n;i++){
            if(graph[value][i]==1&&ar[i]==0){
                enQueue(i);
                ar[i]=1;
            }  
        }
    }
    printf("\n");
}
void DFS(int n){
    printf("DFS : ");
    int i,flag;
    for(i=0;i<n;i++)
        ar[i]=0;
    push(0);
    ar[0]=1;
    printf("%d,",0);
    while(top!=-1){
        flag=0;
        for(i=0;i<n;i++){
            if(graph[stack[top]][i]==1&&ar[i]==0){
                printf("%d,",i);
                ar[i]=1;
                push(i);
                flag=1;
                break;
            }
        }
        if(flag==0)
            pop();
    }
    printf("\n");
}
void main(){
    int n;
    printf("Enter Maximam Elements of graphs\n");
    scanf("%d",&n);
    int i,j,dis,con,data;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            graph[i][j]=0;
    printf("1-Add Element\n2-Delete Elements\n3-BFS\n4-DFS\n5-View\n6-Exit");
    do{
        printf("\nEnter Choice : ");
        scanf("%d",&dis);
        switch(dis){
            case 1: printf("Enter element : ");
                    scanf("%d",&data);
                    printf("Connection : ");
                    scanf("%d",&con);
                    graph[data][con]=1;;
                    break;
            case 2: printf("Enter element : ");
                    scanf("%d",&data);
                    printf("Connection : ");
                    scanf("%d",&con);
                    graph[data][con]=0;
                    break;
            case 3: BFS(n);
                    break;
            case 4:DFS(n);
                    break;
            case 5:viewGraph(n);
                    break;
            case 6:break;
        }

    }while(dis!=6);
}