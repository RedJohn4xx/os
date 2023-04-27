#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of processes :";
    cin >> n;
    int tq1, tq2;
    cout << "Enter time quantum for queue 1: ";
    cin >> tq1;
    cout << "Enter time quantum for queue 2: ";
    cin >> tq2;
    int at[n], bt[n], temp[n];
    cout << "Enter arrival time burst time for " << n << " processes :-" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> at[i] >> bt[i];
        temp[i] = bt[i];
    }
    int timeElapsed1 = 0;
    int timeElapsed2 = 0;
    int timeElapsed3 = 0;
    int wt = 0, tat = 0;
    cout << "\nProcess No BT TAT WT" << endl;
    for (int i = 0; i < n;)
    {
        if (temp[i] <= tq1 && temp[i] > 0)
        {
            timeElapsed1 += temp[i];
            temp[i] = 0;
            cout << i + 1 << " " << bt[i] << " " << timeElapsed1 - at[i] << " " << timeElapsed1 - at[i] - bt[i];
            cout << endl;
            wt = wt + timeElapsed1 - at[i] - bt[i];
            tat = tat + timeElapsed1 - at[i];
        }
        else
        {
            timeElapsed1 += tq1;
            temp[i] -= tq1;
        }
        if (temp[i] != 0)
        {
            if (temp[i] <= tq2)
            {
                timeElapsed2 += temp[i];
                temp[i] = 0;
                cout << i + 1 << " " << bt[i] << " " << timeElapsed2 + timeElapsed1 - at[i] << " " << timeElapsed1 - at[i] - tq1;
                cout << endl;
                wt = wt + timeElapsed1 - at[i] - tq1;
                tat = tat + timeElapsed2 + timeElapsed1 - at[i];
            }
            else
            {
                timeElapsed2 += tq2;
                temp[i] -= tq2;
            }
        }
        if (temp[i] != 0)
        {
            timeElapsed3 += temp[i];
            temp[i] = 0;
            cout << i + 1 << " " << bt[i] << " " << timeElapsed3 + timeElapsed2 + timeElapsed1 - at[i] << " " << timeElapsed1 - at[i] - tq1;
            cout << endl;
            wt = wt + timeElapsed1 - at[i] - tq1;
            tat =
                tat + timeElapsed3 + timeElapsed2 + timeElapsed1 - at[i];
        }
        if (i != n - 1 && at[i + 1] >= timeElapsed1)
        {
            timeElapsed1 = at[i + 1];
        }
        i++;
    }
    float avgTT = tat / (float)n;
    float avgWT = wt / (float)n;
    cout << "Average Turnaround Time : " << avgTT << endl;
    cout << "Average Waiting Time : " << avgWT << endl;
    return 0;
}
