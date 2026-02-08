#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2) {
        cout << "Please provide a filename." << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);

    if (!inputFile.is_open()) {
        cout << "File could not be opened." << endl;
        return 2;
    }

    string line;
    int line_index = 0;
    int width=0, height=0, depth=0;
    float target_sum;
    int line_count;
    while (line_index<3 && getline(inputFile, line)) {
        if (line_index == 0) {
            stringstream ss(line);
            ss >> width >> height >> depth;
        }
        else if (line_index == 1) {
           target_sum = stof(line);
        }
        else if (line_index == 2) {
            line_count = stoi(line);
        }

        line_index++;
    }

    vector<float> dogru(width, 0.0);
    vector<vector<float>> square(height, dogru);
    vector<vector<vector<float>>> cube(depth, square);

    for (int i = 0;i < line_count;i++) {
        float sum = 0;
        if (getline(inputFile, line)) {
            stringstream ss(line);
            ss >> width >> height >> depth >> sum;
            cube[depth][height][width] = sum;
        }
    }

    inputFile.close();

    return 0;
}
