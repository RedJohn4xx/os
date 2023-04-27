#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Process
{
    int pid;
    int bt;
    int priority;
};
bool compare(Process a, Process b)
{
    return (a.priority > b.priority);
}
void waitingtime(Process pro[], int n, int wt[])
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = pro[i - 1].bt + wt[i - 1];
    }
}
void turnarround(Process pro[], int n, int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = pro[i].bt + wt[i];
    }
}
void avgtime(Process pro[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    waitingtime(pro, n, wt);
    turnarround(pro, n, wt, tat);
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "P" << i + 1 << " -> WT = " << wt[i] << ", TAT = " << tat[i] << endl;
    }
    cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
    8 cout << "\nAverage turnaround time = " << (float)total_tat / (float)n;
}
void scheduling(Process pro[], int n)
{
    sort(pro, pro + n, compare);
    cout << endl
         << "Order in which processes gets executed = ";
    for (int i = 0; i < n; i++)
        cout << pro[i].pid << " ";
    cout << endl;
    avgtime(pro, n);
}
int main()
{
    int n;
    cout << "Enter number of Processes : ";
    cin >> n;
    Process pro[100];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Process ID : ";
        cin >> pro[i].pid;
        cout << "Enter Burst Time of P[" << i + 1 << "] : ";
        cin >> pro[i].bt;
        cout << "Enter Priority of P[" << i + 1 << "] : ";
        cin >> pro[i].priority;
        cout << endl;
    }
    scheduling(pro, n);
    return 0;
}
