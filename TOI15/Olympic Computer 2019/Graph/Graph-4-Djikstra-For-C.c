//PROGRAM TO FIND THE SHORTEST WAY AND FIND THE LEAST WEIGHT BY DIJKSTRA ALGORITHM BY XeNON
#include<stdio.h>

#define inf 99999 //TO Define The Infinity Value

int djikstra(int node, int cost[node][node], int start, int terminal);    //TO Declare Djikstra Function
/*  Djikstra Function Includes 4 Type Of Data
    1. node (Amounts Of Vertex)
    2. cost[node][node] (Weight Of All Edges)
    3. start (Starter Vertex)
    4. terminal (End Vertex)
    And Return The Least Weight in Int and Display How To Traversal */

int main()
{
    int vertex,i,j,x,y,w,co,chk=0,max_edges,chk_w=0;

    printf("========== Djikstra Program || Searching For The Shortest Paths ==========\n\n");
    printf("Enter Amount Of Vertex : ");
    scanf("%d",&vertex); //TO Input Amount Of Vertex
    while(vertex<=1) //TO Check Possible Amount Of Vertex , Not 1 or Less Than!
    {
        printf("\nYou Can't Enter That , Please Enter Again\n");
        printf("Enter Amount Of Vertex : ");
        scanf("%d",&vertex);
    }
    printf("\n");

    max_edges = ((vertex*vertex)-vertex)/2; //TO Find The Max Edges Can Be In Graph
    vertex++; //TO Set The Last Vertex
    int cost[vertex][vertex],stver,tmnver;

    for(i=1; i<vertex; i++) //TO Set All Weight to inf
    {
        for(j=1; j<vertex; j++)
        {
            cost[i][j]=inf;
        }
    }

    printf("========== Weight Of Edges ==========\n*Enter -1 If They're Not Connected\n\n");
    for(x=1; x<vertex; x++) //TO Input Weight Of Each Edge
    {
        for(y=x+1; y<vertex; y++)
        {
            printf("Weight [%d <---> %d] : ",x,y);
            scanf("%d",&w);
            if(w== -1) //TO Check If Between 2 Vertexes Doesn't Connect Then Input -1
            {
                chk++;
                cost[x][y] = cost[y][x] = inf;
            }
            else
            {
                if(w>0)
                {
                    cost[x][y] = cost[y][x] = w;
                }
                else //TO Check If Weight Is Less Than or Equal 0 And Not -1
                {
                    chk_w++;
                    break; //TO End Loop
                }
            }
        }

        if(chk_w!=0) //TO Check If It's ERROR
        {
            break; //TO End Loop
        }
    }

    if(chk_w!=0) //TO Check If Weight Input ERROR , Then End Of Program
    {
        printf("\nERROR , Incorrect Weight! , Please Check Your Input and Try Again\n");
    }
    else
    {
        if(chk<max_edges) //TO Check If There's Connection In Graph
        {
            printf("\n========== Start And Terminal ==========\n\n");
            printf("Enter Start Vertex : "); //TO Input Starter Vertex
            scanf("%d",&stver);
            printf("Enter Terminal Vertex : "); //TO Input End Vertex
            scanf("%d",&tmnver);
            printf("\n");

            co = djikstra(vertex,cost,stver,tmnver); //TO Receive The Shortest Weight From dijkstra Function And Display The Best Way
            printf("The Shortest Paths From %d To %d is %d\n",stver,tmnver,co);

            return 0;
        }
        else //To Check If There's No Connection In Graph , Then End Of Program
        {
            printf("\nERROR , No Vertex Connected! , Please Check Your Input and Try Again\n");
        }
    }
}

int djikstra(int node, int cost[node][node],int start,int terminal) //TO Create Djikstra Function
{
    int distance[node], prev[node], selected[node], m, shortest, bgin, d, i, j ;
    /*  distance = The Distance You Can Walk From Vertex to Vertex
        prev = The Checking Array To Check If You Used to Traverse That Vertex
        selected = The Checking Array To Check If You Used To Receive Weight Of That Vertex
        bgin = The New Starter Node
        d = The Sum Distance
    */

    int path[node]; //TO Receive The Best Way

    for(i=1; i<node; i++) //TO Set ALL selected TO 0
    {
        selected[i]=0;
        /*  If selected = 0 , Then Vertex's Not Selected
            If selected = 1 , Then Vertex's Selected
        */
    }

    for(i=1; i<node; i++)
    {
        distance[i]=inf; //TO Set Infinity Value In distance
        prev[i]= -1; //TO Set prev With -1 To Delete Vertex
    }

    bgin = start; //TO Set Starter Vertex
    selected[bgin] = 1; //TO Set Starter Vertex Has Selected
    distance[bgin] = 0; //TO Set Distance Of Path (Default : 0)

    while(selected[terminal] == 0) //TO Check If End Vertex's Not Selected
    {
        shortest = inf; //TO Set The Least Weight To Infinity , Like Finding Minimal Value
        m = 0; //TO Set Temporary Variable

        for(i=1; i<node; i++) //TO Check All Vertexes
        {
            d = distance[bgin] + cost[bgin][i]; //TO Find The Sum Distance From Weight

            if(d<distance[i] && selected[i]==0) //TO Check If The Sum Distance Is Less Than Distance Of That Edge , And Check If It's Not Selected
            {
                distance[i] = d; //TO Set New Value Of Distance From Sum Distance
                prev[i] = bgin; //TO Set The Previous Vertex To Starter Vertex
            }

            if(shortest > distance[i] && selected[i]==0) //TO Check If The Least Weight Is More Than Distance Of That Edge , And Check If It's Not Selected
            {
                shortest = distance[i]; //TO Set The Least Weight To Distance Of That Edge
                m = i; //TO Set This Vertex To Temporary Vertex
            }
        }

        bgin = m; //TO Set Temporary Vertex To New Starter Vertex
        selected[bgin] = 1; //TO Set Starter Vertex's Selected
    }

    bgin = terminal; //TO Set End Vertex To Starter Vertex
    j = 0; //TO Create Array To Find The Paths

    while(bgin != -1) //TO Check If It's The Traversal Edge
    {
        path[j] = bgin; //TO Set Path With Vertex
        bgin = prev[bgin]; //TO Set Previous Vertex To Starter Vertex
        j++; //TO Count All Possible Vertex
    }

    printf("====== The Best Way To Get To %d From %d ======\n",start,terminal);
    for(i=j-1; i>=0; i--) //TO Display The Best Paths By Reverse Paths
    {
        if(i!=0)
        {
            printf("%d -> ",path[i]);
        }
        else
        {
            printf("%d\n",path[i]);
        }
    }
    printf("\n");

    return distance[terminal]; //TO Return The Least Weight
}
