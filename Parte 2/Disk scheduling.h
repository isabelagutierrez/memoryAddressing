#pragma once
#include <vector>
using namespace std;

extern const int maxCylinder;

// First-Come First-Served
vector <int> fcfs(vector <int> &requests, int head);

// SCAN
vector <int> scan(vector <int> &requests, int head);

// C-SCAN
vector <int> cScan(vector <int> &requests, int head);