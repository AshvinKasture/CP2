#include<bits/stdc++.h>
using namespace std;

int sum(vector<int> team)
{
    int add = 0;
    for(int i=0;i<team.size();i++)
    {
        add = add + team[i];
    }
    return add;
}

void tugofwar(int *arr,int m)
{
    vector<int> team1;
    vector<int> team2;

    team1.push_back(arr[0]);
    for(int i=1;i<m;i++)
    {
        if(sum(team1)>=sum(team2))
        {
            team2.push_back(arr[i]);
        }
        else
        {
            team1.push_back(arr[i]);
        }
    }

    (sum(team1) < sum(team2))?cout<<sum(team1)<<" "<<sum(team2)<<endl:cout<<sum(team2)<<" "<<sum(team1)<<endl;
}

int main()
{
    int N,m;
    int *arr;

    cin>>N;
    cin.get();

    for(int i=0;i<N;i++)
    {
        cin>>m;
        cin.get();

        arr = new int[m];
        for(int i=0;i<m;i++)
        {
            cin>>arr[i];
            cin.get();
        }
        sort(arr,arr+m,greater<int>());
        tugofwar(arr,m);
        delete(arr);
        arr = NULL;
    }
    return 0;
}
