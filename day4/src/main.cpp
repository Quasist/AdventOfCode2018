#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

struct guard {
    int id;
    int totalMinutesSlept;
    std::map<int, int> asleepAtMinute;
};

int main(int argc, char* argv[]) {
    ifstream f("../input/GuardsGuardsGuards.txt");
    string line;
    f.close();
    return 0;
}
