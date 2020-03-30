#include <iostream>
#include <cmath>
#include  <fstream>
using namespace std;

double f(double x) {
    return sqrt(x);
}

void g(int width, int height, double x0, double x1) {
    double step = (x1 - x0) / width;
    double *values = new double[width];
    auto segment = x0;

    for (int i = 0; i < width; ++i) {
        values[i] = f(segment);
        segment += step;
    }
    double min= values[0];
    double max= values[0];
    for (int i=0;i<width;i++)
    {
        if (values[i] < min) {
            min = values[i];
        }

        if (values[i] > max) {
            max = values[i];
        }
    }
    min = (max > 0 & min > 0) ? 0 : min;
    max = (max < 0 & min < 0) ? 0 : max;

    double scale = height / (max - min);
    double zero_height = floor(-min * scale);
    double rel_height = height;
    fstream fout;
    fout.open("output.txt");
    int value;
    for (int i = 0; i < height + 1; i++) {
        for (int val = 0; val != width; val++) {

            value = floor((values[val] - min) * scale);
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
    delete [] values;
}


int main() {
    int width, height;
    double x0, x1;
    cin >> width >> height >> x0 >> x1;
    g(width, height, x0, x1);
}
