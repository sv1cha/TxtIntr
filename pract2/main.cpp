#include <iostream>
#include <cmath>
#include <cstdlib>
#include <getopt.h>
#include <stdexcept> // Для обработки исключений

using namespace std;

const double g = 9.81; // Ускорение свободного падения 

void calculateHeight(double angle, double velocity) {
    double radianAngle = angle * M_PI / 180.0; // Преобразование градусов в радианы
    double height = (pow(velocity, 2) * pow(sin(radianAngle), 2)) / (2 * g);
    cout << "Максимальная высота: " << height << " метров" << endl;
}

void calculateRange(double angle, double velocity) {
    double radianAngle = angle * M_PI / 180.0; // Преобразование градусов в радианы
    double range = (pow(velocity, 2) * sin(2 * radianAngle)) / g;
    cout << "Дальность полета: " << range << " метров" << endl;
}

bool validateInput(double angle, double velocity) {
    if (angle < 0 || angle > 90) {
        cout << "Ошибка: угол должен быть в диапазоне от 0 до 90 градусов." << endl;
        return false;
    }
    if (velocity < 0) {
        cout << "Ошибка: начальная скорость не может быть отрицательной." << endl;
        return false;
    }
    return true;
}

bool isNumber(const string& str) {
    try {
        std::stod(str); // Попробуем преобразовать строку в число
        return true;
    } catch (std::invalid_argument&) {
        return false; // Если не удалось преобразовать, это не число
    } catch (std::out_of_range&) {
        return false; // Если число выходит за пределы диапазона
    }
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

        if (operation == "height" || operation == "range") {
            if (argc != 5) {
                cout << "Ошибка: требуется два аргумента (угол и начальная скорость)." << endl;
                exit(1);
            }

            string angleStr = argv[3];
            string velocityStr = argv[4];

            if (!isNumber(angleStr) || !isNumber(velocityStr)) {
                cout << "Ошибка: оба аргумента должны быть числами." << endl;
                exit(1);
            }

            double angle = std::stod(angleStr);
            double velocity = std::stod(velocityStr);

            if (validateInput(angle, velocity)) {
                if (operation == "height") {
                    calculateHeight(angle, velocity);
                } else if (operation == "range") {
                    calculateRange(angle, velocity);
                }
            }
            exit(0);
        }
    }

    return 0;
}
