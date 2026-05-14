#pragma once
#include <vector>
#include <string>
using namespace std;

// ─── Métricas ──────────────────────────────────────────────────────────────────

int totalMovement(const vector <int> &path);

double avgSeek(const vector <int> &path);

int maxJump(const vector <int> &path);

vector <int> cumulativeMovement(const vector <int> &path);

// ─── Salida ────────────────────────────────────────────────────────────────────

void writeDataJS(const string &filename, int initialHead, int numRequests, int maxCylinder, const vector <int> &pathFcfs, const vector <int> &pathScan, const vector <int> &pathCscan);