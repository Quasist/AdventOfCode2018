#include <fstream>
#include <iostream>
#include <map>
using namespace std;

void countDuplicates(map<int, int>& cmap, int& cnt2, int& cnt3);

int main(int argc, char* argv[]) {
    ifstream f("./input/barcodes.log");
    int cntTwo = 0;
    int cntThree = 0;
    string line;
    std::map<int, int> cntMap;

    while (std::getline(f, line)) {
        for (char c : line) {
            auto result = cntMap.insert(std::pair<int, int>(c, 1));
            if (result.second == false)
                result.first->second++;
        }
        countDuplicates(cntMap, cntTwo, cntThree);
        cntMap.clear();
    }
    cout << cntTwo * cntThree << endl;
    f.close();
    return 0;
}

void countDuplicates(map<int, int>& cmap, int& cnt2, int& cnt3) {
    bool fnd2 = false;
    bool fnd3 = false;
    for (auto& elem : cmap) {
        if (elem.second == 2) {
            if (!fnd2) {
                cnt2++;
                fnd2 = true;
            }
        } else if (elem.second == 3) {
            if (!fnd3) {
                cnt3++;
                fnd3 = true;
            }
        }
    }
}
