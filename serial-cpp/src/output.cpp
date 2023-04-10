#include <iostream>
#include <fstream>

const int WIDTH = 256;
const int HEIGHT = 256;
const int PIXEL_MAX = 255;

using namespace std;

int main() {
    string file_name;
    cout << "enter file name: ";
    getline(cin, file_name);

    ofstream ppm_out; 
    ppm_out.open(file_name);

    ppm_out << "P3" << endl;
    ppm_out << WIDTH << " " << HEIGHT << endl;
    ppm_out << PIXEL_MAX << endl;

    for (int j = HEIGHT - 1; j >= 0; j--) {
        for (int i = 0; i < WIDTH; i++) {
            double r = double(i) / (WIDTH - 1);
            double g = double(j) / (HEIGHT - 1);
            double b = 0.25;

            int pixel_r = static_cast<int>(255 * r);
            int pixel_g = static_cast<int>(255 * g);
            int pixel_b = static_cast<int>(255 * b);

            ppm_out << pixel_r << " " << pixel_g << " " << pixel_b << endl;
        }
    }
}