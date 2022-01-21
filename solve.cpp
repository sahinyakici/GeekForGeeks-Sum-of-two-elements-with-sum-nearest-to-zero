#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int closestToZero(int arr[], int n);

int main()
{
    int N = 5;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            arr[i] = 29;
        }
        else if (i == 1)
        {
            arr[i] = 13;
        }
        else if (i == 2)
        {
            arr[i] = -6;
        }
        else if (i == 3)
        {
            arr[i] = -32;
        }
        else if (i == 4)
        {
            arr[i] = -12;
        }
    }
    cout << closestToZero(arr, N) << endl;
    return 0;
}

int closestToZero(int arr[], int n)
{
    if (n == 2)
    {
        return arr[0] + arr[1];
    }
    else
    {
        int small = 0;
        vector<int> vect;
        vector<int> vect2;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] + arr[j] < 0)
                {
                    vect.push_back(-(arr[i] + arr[j]));
                }
                else
                {
                    vect.push_back((arr[i] + arr[j]));
                }
                vect2.push_back((arr[i] + arr[j]));
            }
        }
        int smallTest=*min_element(vect.begin(), vect.end());
        for (int i = 0; i < vect.size(); i++)
        {
            if(vect2.at(i)==smallTest||vect2.at(i)==-smallTest){
                small=vect2.at(i);
            }
        }
        return small;
    }
}