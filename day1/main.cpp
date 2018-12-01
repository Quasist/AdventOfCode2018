#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
using namespace std;

int main(int argc, char* argv[]) {
    ifstream f("./input/frequencies.log");
    string line;
    int freq = 0;
    if (argc > 1) {
        bool isDone = false;
        set<int> freqList;
        while (!isDone) {
            while (std::getline(f, line)) {
                freq += stoi(line);
                if (freqList.count(freq)) {
                    cout << freq << endl;
                    isDone = true;
                    break;
                } else {
                    freqList.insert(freq);
                }
            }
            f.clear();
            f.seekg(0, ios::beg);
        }
    } else {
        while (std::getline(f, line)) {
            freq += stoi(line);
        }
        cout << freq << endl;
    }
    f.close();
    return 0;
}
