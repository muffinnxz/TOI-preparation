#include<iostream>
#include<queue>

using namespace std;

struct batch_job
{
    char name;
    int time,priority;
};

int main()
{
    int total_time = 0;
    struct batch_job work[5];
    priority_queue<int> work_order;

    for(int i=0; i<5; i++)
    {
        cin>>work[i].name>>work[i].time>>work[i].priority;
        work[i].priority*=-1;
        work_order.push(work[i].priority);
        total_time += work[i].time;
    }

    cout<<endl;
    while(!work_order.empty())
    {
        for(int i=0; i<5; i++)
        {
            if(work_order.top()==work[i].priority)
            {
                cout<<work[i].name<<" ";
                break;
            }
        }
        work_order.pop();
    }
    cout<<endl<<"Turnaround Time = "<<total_time<<" Minute"<<endl;
}
