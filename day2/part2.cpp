#include <algorithm>  // std::min
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int find_distance(const std::string& s1, const std::string& s2);
int main(int argc, char* argv[]) {
    ifstream f("./input/barcodes.log");
    string line;
    vector<string> lines;
    while (std::getline(f, line)) {
        lines.push_back(line);
    }
    for (int i = 0; i < lines.size(); i++) {
        for (int j = i + 1; j < lines.size(); j++) {
            if (find_distance(lines.at(i), lines.at(j)) == 1)
                cout << lines.at(i) << " " << lines.at(j) << endl;
        }
    }
    f.close();
    return 0;
}
// Levenshtein distance algorithm. (is there an easy way in STL to do this?)
int find_distance(const std::string& s1, const std::string& s2) {
    const std::size_t len1 = s1.size(), len2 = s2.size();
    std::vector<std::vector<unsigned int>> d(len1 + 1, std::vector<unsigned int>(len2 + 1));

    d[0][0] = 0;
    for (unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
    for (unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

    for (unsigned int i = 1; i <= len1; ++i)
        for (unsigned int j = 1; j <= len2; ++j)
            d[i][j] = std::min({d[i - 1][j] + 1, d[i][j - 1] + 1,
                                d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1)});
    return d[len1][len2];
}
