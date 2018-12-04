#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;
struct point {
    int x, y;
};
std::map<std::pair<int, int>, int> fabric;

void claimSquare(point startPoint, int w, int h);
int countOverlap(map<std::pair<int, int>, int>& fabmap);
void sanitizeString(string st, point& startPoint, int& index, int& w, int& h);
bool claimWithoutOverlap(point startPoint, int w, int h);

int main(int argc, char* argv[]) {
    ifstream f("../input/claims.txt");
    string line;
    while (std::getline(f, line)) {
        point startpoint;
        int index;
        int widthSqr;
        int heightSqr;
        sanitizeString(line, startpoint, index, widthSqr, heightSqr);
        claimSquare(startpoint, widthSqr, heightSqr);
    }
    int total = countOverlap(fabric);
    std::cout << "part 1 solution: " << total << std::endl;
    f.clear();
    f.seekg(0, ios::beg);
    while (std::getline(f, line)) {
        point startpoint;
        int index;
        int widthSqr;
        int heightSqr;
        sanitizeString(line, startpoint, index, widthSqr, heightSqr);
        if (!claimWithoutOverlap(startpoint, widthSqr, heightSqr))
            continue;
        std::cout << "no overlap in ID: " << index << std::endl;
    }
    f.close();
    return 0;
}

void claimSquare(point startPoint, int w, int h) {
    for (int i = startPoint.y; i < h + startPoint.y; i++) {
        for (int j = startPoint.x; j < w + startPoint.x; j++) {
            std::pair<int, int> tmp = {i, j};
            auto result = fabric.insert(std::pair<std::pair<int, int>, int>(tmp, 1));
            if (result.second == false)
                result.first->second++;
        }
    }
}

int countOverlap(map<std::pair<int, int>, int>& fabmap) {
    int cnt = 0;
    for (auto& elem : fabmap) {
        if (elem.second > 1) {
            cnt++;
        }
    }
    return cnt;
}

void sanitizeString(string st, point& startPoint, int& index, int& w, int& h) {
    std::stringstream ss;
    std::replace(st.begin(), st.end(), '#', ' ');
    std::replace(st.begin(), st.end(), '@', ' ');
    std::replace(st.begin(), st.end(), ',', ' ');
    std::replace(st.begin(), st.end(), ':', ' ');
    std::replace(st.begin(), st.end(), 'x', ' ');
    ss.str(st);
    ss >> index >> startPoint.x >> startPoint.y >> w >> h;
}

bool claimWithoutOverlap(point startPoint, int w, int h) {
    for (int i = startPoint.y; i < h + startPoint.y; i++) {
        for (int j = startPoint.x; j < w + startPoint.x; j++) {
            std::pair<int, int> tmp = {i, j};
            auto result = fabric.insert(std::pair<std::pair<int, int>, int>(tmp, 1));
            if (result.second == false)
                result.first->second++;
            if (result.first->second > 2)
                return false;
        }
    }
    return true;
}
