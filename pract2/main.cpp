#include <iostream>
#include <cmath>
#include <cstdlib>
#include <getopt.h>
using namespace std;

const double g = 9.81; // Ускорение свободного падения 

void calculateHeight(double angle, double velocity) {
    // Высота 
    double radianAngle = angle * M_PI / 180.0; // Преобразование градусов в радианы
    double height = (pow(velocity, 2) * pow(sin(radianAngle), 2)) / (2 * g);
    cout << "Максимальная высота: " << height << " метров" << endl;
}

void calculateRange(double angle, double velocity) {
    // Дальность 
    double radianAngle = angle * M_PI / 180.0; // Преобразование градусов в радианы
    double range = (pow(velocity, 2) * sin(2 * radianAngle)) / g;
    cout << "Дальность полета: " << range << " метров" << endl;
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "Справочный материал." << endl <<
            "Для вычисления максимальной высоты напишите: -o height угол начальная_скорость" << endl <<
            "Для вычисления дальности напишите: -o range угол начальная_скорость" << endl;
        exit(0);
    }

    int opt;
    while ((opt = getopt(argc, argv, "o:")) != -1) {
        string operation = optarg;

        if (operation == "height") {
            if (argc != 5) {
                cout << "Ошибка: требуется два аргумента (угол и начальная скорость)." << endl;
                exit(1);
            }
            double angle = atof(argv[3]);
            double velocity = atof(argv[4]);
            calculateHeight(angle, velocity);
            exit(0);
        }

        if (operation == "range") {
            if (argc != 5) {
                cout << "Ошибка: требуется два аргумента (угол и начальная скорость)." << endl;
                exit(1);
            }
            double angle = atof(argv[3]);
            double velocity = atof(argv[4]);
            calculateRange(angle, velocity);
            exit(0);
        }
    }

    return 0;
}
