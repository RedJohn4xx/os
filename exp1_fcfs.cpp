#include <iostream>
using namespace std;
float calcawt(int wt[20], int n)
{
    int i;
    float avwt = 0;
    for (i = 0; i < n; i++)
    {
        avwt = avwt + wt[i];
    }
    return (avwt / n);
}
float calcatat(int tat[20], int n)
{
    int i;
    float avtat = 0;
    for (i = 0; i < n; i++)
    {
        avtat = avtat + tat[i];
    }
    return (avtat / n);
}
int main()
{
    int n, bt[20], wt[20], tat[20], i, j;
    cout << "Enter number of Processes (maximum 20) : ";
    cin >> n;
    cout << "Enter the process Burst Time : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "p[" << (i + 1) << "] : ";
        cin >> bt[i];
    }
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j];
                }
    }
    cout << "Process Burst time Waiting time Turnaround time " << endl;
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
    float avwt = calcawt(wt, n);
    float avtat = calcatat(tat, n);
    for (i = 0; i < n; i++)
    {
        cout << "P[" << (i + 1) << "]"
             << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i]
             << endl;
    }
    cout << "Average waiting time : " << avwt << endl;
    cout << "Average turnaround time : " << avtat;
}
