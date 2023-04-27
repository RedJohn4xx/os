#include <iostream>

using namespace std;
int main()
{
    int referenceString[10], pageFaults = 0, pages, frames;
    cout << "\nEnter the number of Pages: ";
    cin >> pages;
    cout << "\nEnter reference string values:-" << endl;
    for (int i = 0; i < pages; i++)
    {
        cin >> referenceString[i];
    }
    cout << "\nEnter number of frames: ";
    cin >> frames;
    int temp[frames];
    for (int i = 0; i < frames; i++)
    {
        temp[i] = -1;
    }
    int s;
    cout << "\nreference string\tPage Frames" << endl;
    for (int i = 0; i < pages; i++)
    {
        s = 0;
        for (int j = 0; j < frames; j++)
        {
            if (referenceString[i] == temp[j])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        if ((pageFaults <= frames) && (s == 0))
        {
            temp[i] = referenceString[i];
        }
        else if (s == 0)
        {
            temp[(pageFaults - 1) % frames] = referenceString[i];
        }
        cout << referenceString[i] << "\t\t\t";
        for (int j = 0; j < frames; j++)
        {
            cout << temp[j] << " ";
        }
        cout << endl;
    }
    cout << "\nTotal Page Faults: " << pageFaults << endl
         << endl;
    return 0;
}