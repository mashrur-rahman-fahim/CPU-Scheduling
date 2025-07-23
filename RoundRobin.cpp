#include <bits/stdc++.h>
using namespace std;
struct container
{
    int pid, at, ct, tt, wt, rt, st, ft;
};

int main()
{
    int n, q;
    cout << "Enter number of processes and quantum time: " << endl;
    cin >> n >> q;
    vector<container> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].pid = i + 1;
        v[i].st = -1;
        cin >> v[i].at >> v[i].ct;
    }
    cout << endl
         << "Gantt Chart" << endl;
    sort(v.begin(), v.end(), [](const container &a, const container &b)
         { return a.at < b.at; });

    vector<container> v_copy = v;
    vector<int> queue;
    for (int i = 0; i < n; i++)
    {
        if (v[i].ct > 0)
        {
            queue.push_back(i);
            break;
        }
    }

    int current_time = v_copy[queue[0]].at;
    cout << current_time;
    int i = 0, j = queue[0] + 1;

    while (1)
    {
        if (v_copy[queue[i]].st == -1)
        {
            v_copy[queue[i]].st = current_time;
        }

        current_time += min(v_copy[queue[i]].ct, q);
        v_copy[queue[i]].ft = current_time;
        v_copy[queue[i]].ct -= min(v_copy[queue[i]].ct, q);
        if (j < n)
        {
            int k;
            for (k = j; k < n; k++)
            {
                if (v_copy[k].at <= current_time && v_copy[k].ct > 0)
                {
                    queue.push_back(k);
                }
                else
                {

                    break;
                }
            }
            j = k;
        }

        if (v_copy[queue[i]].ct > 0)
        {
            queue.push_back(queue[i]);
        }

        cout << "---(" << v_copy[queue[i]].pid << ")---";
        cout << current_time;
        i++;
        if (i >= queue.size())
        {
            break;
        }
    }
    long long int total_waiting_time = 0;
    long long int total_turnaround_time = 0;
    cout << endl
         << endl
         << setw(8) << "FT"
         << setw(8) << "TT"
         << setw(8) << "WT"
         << setw(8) << "RT"
         << setw(8) << "ST" << endl;
    for (i = 0; i < n; i++)
    {
        v[i].ft = v_copy[i].ft;
        v[i].st = v_copy[i].st;
        v[i].tt = v[i].ft - v[i].at;
        v[i].wt = v[i].tt - v[i].ct;
        v[i].rt = v[i].st - v[i].at;
        total_waiting_time += v[i].wt;
        total_turnaround_time += v[i].tt;
        cout << setw(8) << v[i].ft
             << setw(8) << v[i].tt
             << setw(8) << v[i].wt
             << setw(8) << v[i].rt
             << setw(8) << v[i].st << endl;
    }
    cout << endl;
    cout << "Average Waiting Time: " << (double)total_waiting_time / n << endl;
    cout << "Average Turnaround Time: " << (double)total_turnaround_time / n << endl;
}

// Example Input:
// 6 3

// 0 10
// 3 4
// 5 1
// 7 5
// 10 4
// 11 5