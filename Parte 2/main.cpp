#include <iostream>
#include <vector>
#include <random>
#include "Disk scheduling.h"
#include "report.h"

const int numRequests = 1000;

int main(int argc, char* argv[]){
    if(argc != 2){
        cerr << "Uso: " << argv[0] << " PosicionInicial\n";
        return 1;
    }

    int initialHead;
    try {
        initialHead = stoi(argv[1]);
    } catch (...) {
        cerr << "Error: posicion invalida.\n";
        return 1;
    }

    if(initialHead < 0 || initialHead > maxCylinder){
        cerr << "Error: la cabeza debe estar entre 0 y " << maxCylinder << ".\n";
        return 1;
    }

    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution <int> dist(0, maxCylinder);

    vector <int> requests(numRequests);
    for(int i = 0; i < requests.size(); ++i)
        requests[i] = dist(rng);

    auto pathFcfs = fcfs (requests, initialHead);
    auto pathScan = scan (requests, initialHead);
    auto pathCscan = cScan(requests, initialHead);

    cout << "\n=== Disk Scheduling (head = " << initialHead << ", requests =" << numRequests << ") ===\n";
    cout << fixed;
    cout.precision(1);
    cout << "FCFS total: " << totalMovement(pathFcfs) << " avg: " << avgSeek(pathFcfs) << "\n";
    cout << "SCAN total: " << totalMovement(pathScan) << " avg: " << avgSeek(pathScan) << "\n";
    cout << "C-SCAN total: " << totalMovement(pathCscan) << " avg: " << avgSeek(pathCscan) << "\n\n";

    writeDataJS("data.js", initialHead, numRequests, maxCylinder, pathFcfs, pathScan, pathCscan);

    #ifdef _WIN32
        { int r = system("start index.html");    (void)r; }
    #elif __APPLE__
        { int r = system("open index.html");     (void)r; }
    #else
        { int r = system("xdg-open index.html"); (void)r; }
    #endif

    return 0;
}