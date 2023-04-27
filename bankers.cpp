#include <iostream>

using namespace std;
int main()
{
    int n, m;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;
    int available[m];
    int allocation[n][m];
    int maxNeed[n][m];
    cout << "Enter the maximum number of instances for each resource:-" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> available[i];
    }
    cout << "Enter Allocation:-" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> allocation[i][j];
            available[j] -= allocation[i][j];
        }
    }
    cout << "Enter Maximum Needs:-" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maxNeed[i][j];
        }
    }
    // for keeping current requirements
    int currReq[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            currReq[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }
    int ans[n];
    // keeps the processes which have been added in safe state
    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    // count is the number of processes in safe state
    int count = 0;
    int flag;
    while (count < n)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            flag = 0;
            if (visited[i])
            {
                continue;
            }
            for (int j = 0; j < m; j++)
            {
                if (available[j] < currReq[i][j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                break;
            }
        }
        if (flag == 1)
        {
            cout << "Deadlock Occured!" << endl;
            break;
        }
        else
        {
            for (int j = 0; j < m; j++)
            {
                available[j] += allocation[i][j];
            }
            visited[i] = true;
            ans[count] = i;
            count++;
        }
    }
    if (flag == 0)
    {
        cout << "Deadlock didn't occur! Hence,the safe state is:-" << endl;
        for (int i = 0; i < n - 1; i++)
        {
            cout << "P" << ans[i] << "->";
        }
        cout << "P" << ans[n - 1];
    }
    return 0;
}