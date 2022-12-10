#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef long cycle_t;
typedef long data_t;

data_t X = 1;

void addx(cycle_t cycle, data_t arg) {
    X += arg;
}

char get_pixel(cycle_t cycle) {
    int draw_pixel_idx = (cycle - 1) % 40;
    bool lit = abs(draw_pixel_idx - X) <= 1;
    return lit ? '#' : '.';
}

int main() {

    ifstream is("day10.in");
    cycle_t cycle = 1;
    data_t sum = 0;
    string screen = "";

    for (size_t i = 0; i < 140; ++i) {
        string op;
        int arg;
        is >> op;

        if (op == "addx") {
            is >> arg;
            cycle_t c = (cycle - 20) % 40;
            if (c == 39 || c == 0) {
                cycle_t mul_cycle = (c == 39 ? cycle + 1 : cycle);
                data_t addition = mul_cycle * X;
                cout << "cycle\t" << cycle << " " << mul_cycle << " * " << X  << " = " << addition << endl;
                sum += addition;
            }
            
            screen += get_pixel(cycle);
            cycle += 1;
            if (((cycle - 1) % 40) == 0 && cycle > 1) screen += '\n';

            screen += get_pixel(cycle);
            cycle += 1;
            if (((cycle - 1) % 40) == 0 && cycle > 1) screen += '\n';

            addx(cycle, arg);
        } else {
            cycle_t c = (cycle - 20) % 40;
            if (c == 0) {
                cycle_t mul_cycle = cycle;
                data_t addition = mul_cycle * X;
                cout << "cycle\t" << cycle << " " << mul_cycle << " * " << X  << " = " << addition << endl;
                sum += addition;
            }

            screen += get_pixel(cycle);
            cycle += 1;
            if (((cycle - 1) % 40) == 0 && cycle > 1) screen += '\n';
        }
    }

    cout << "sum=" << sum << endl;
    cout << screen << endl;
}