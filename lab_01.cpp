#include <iostream>
#include <cmath>
#include <vector>
#include  <fstream>
#include <algorithm>
using namespace std;

double f(double x) {
    return sqrt(x);
}

void g(int width, int height, double x0, double x1) {
    double step = (x1 - x0) / width;
    vector<double> values;
    auto segment = x0;

    for (int i = 0; i < width; ++i) {
        values.push_back(f(segment));
        segment += step;
    }
    double min= *min_element(begin(values), end(values));
    double max= *max_element(begin(values), end(values));

    min = (max > 0 & min > 0) ? 0 : min;
    max = (max < 0 & min < 0) ? 0 : max;

    double scale = height / (max - min);
    double zero_height = floor(-min * scale);
    double rel_height = height;
    fstream fout;
    fout.open("output.txt");
    for (int i = 0; i < height + 1; i++) {
        for (auto value : values) {
            value = floor((value - min) * scale);
            if (rel_height == zero_height)
                fout << '-';
            else if (value > rel_height && rel_height > zero_height)
                fout << '#';
            else if (value <= rel_height && rel_height < zero_height)
                fout << '#';
            else
                fout << ' ';

        }
        fout << endl;
        rel_height--;
    }
}


int main() {
    int width, height;
    double x0, x1;
    cin >> width >> height >> x0 >> x1;
    g(width, height, x0, x1);
}