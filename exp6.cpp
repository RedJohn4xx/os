#include <iostream>
using namespace std;
int main()
{
    int NOP, flag = 0, y, tq, wt = 0, tat = 0, at[10], bt[10], temp[10];
    int queue[100];
    float avg_wt, avg_tat;
    cout << "Total number of processes in the system: ";
    cin >> NOP;
    y = NOP;
    for (int i = 0; i < NOP; i++)
    {
        cout << "Arrival time Burst time: ";
        cin >> at[i] >> bt[i];
        temp[i] = bt[i];
    }
    cout << "Enter the Time Quantum: ";
    cin >> tq;
    cout << "\nProcess No BT TAT WT" << endl;
    int maxlimit = 1;
    int i = 0;
    int totalTime = 0;
    queue[maxlimit - 1] = i;
    int j = 1;
    while (i < maxlimit)
    {
        if (temp[queue[i]] <= tq && temp[queue[i]] > 0)
        {
            totalTime = totalTime + temp[queue[i]];
            temp[queue[i]] = 0;
            flag = 1;
        }
        else if (temp[queue[i]] > 0)
        {
            temp[queue[i]] = temp[queue[i]] - tq;
            totalTime = totalTime + tq;
        }
        for (; j < NOP; j++)
        {
            if (totalTime >= at[j])
            {
                queue[maxlimit++] = j;
            }
            else
            {
                break;
            }
        }
        if (temp[queue[i]] == 0 && flag == 1)
        {
            // decrement the process no.
            y--;
            cout << queue[i] + 1 << " " << bt[queue[i]] << " " << totalTime - at[queue[i]] << " " << totalTime - at[queue[i]] - bt[queue[i]];
            cout << endl;
            wt = wt + totalTime - at[queue[i]] - bt[queue[i]];
            tat = tat + totalTime - at[queue[i]];
            flag = 0;
        }
        else if (flag == 0)
        {
            queue[maxlimit++] = queue[i];
        }
        i++;
    }
    avg_wt = wt * 1.0 / NOP;
    avg_tat = tat * 1.0 / NOP;
    cout << "\nAverage Turn Around Time: " << avg_tat;
    cout << "\nAverage Waiting Time: " << avg_wt;
}