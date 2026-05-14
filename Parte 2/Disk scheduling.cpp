#include "Disk scheduling.h"
#include <algorithm>

const int maxCylinder = 4999;

// ─── FCFS ──────────────────────────────────────────────────────────────────────

vector <int> fcfs(vector <int> &requests, int head){
    vector <int> path;
    path.reserve(requests.size() + 1);
    path.push_back(head);
    for(int i = 0; i < requests.size(); ++i)
        path.push_back(requests[i]);
    return path;
}

// ─── SCAN ──────────────────────────────────────────────────────────────────────

vector <int> scan(vector <int> &requests, int head){
    vector <int> lower, upper;
    for(int i = 0; i < requests.size(); ++i){
        if(requests[i] < head)
            lower.push_back(requests[i]);
        else
            upper.push_back(requests[i]);
    }

    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());

    vector <int> path;
    path.reserve(requests.size() + 1);
    path.push_back(head);

    for(int i = 0; i < upper.size(); ++i)
        path.push_back(upper[i]);

    for(int i = lower.size(); i-- > 0;)
        path.push_back(lower[i]);

    return path;
}

// ─── C-SCAN ────────────────────────────────────────────────────────────────────

vector <int> cScan(vector <int> &requests, int head){
    vector <int> lower, upper;
    for(int i = 0; i < requests.size(); ++i){
        if(requests[i] < head)
            lower.push_back(requests[i]);
        else
            upper.push_back(requests[i]);
    }

    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());

    vector <int> path;
    path.reserve(requests.size() + 3);
    path.push_back(head);

    for(int i = 0; i < upper.size(); ++i)
        path.push_back(upper[i]);

    if(!lower.empty()){
        path.push_back(maxCylinder);
        path.push_back(0);
        for(int i = 0; i < lower.size(); ++i)
        path.push_back(lower[i]);
    }

    return path;
}