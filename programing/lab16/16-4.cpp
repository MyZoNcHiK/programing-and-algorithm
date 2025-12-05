#include <iostream>
#include <string>
using namespace std;

struct Game {
    string name;
    string developer;
    int reviews[4];

    void init(string n, string d, int r1, int r2, int r3, int r4) {
        name = n;
        developer = d;
        reviews[0] = r1;
        reviews[1] = r2;
        reviews[2] = r3;
        reviews[3] = r4;
    }

    double getAverage() {
        int sum = 0;
        for(int i = 0; i < 4; i++) {
            sum += reviews[i];
        }
        return sum / 4.0;
    }

    void showInfo() {
        cout << "Назва гри: " << name << endl;
        cout << "Розробник: " << developer << endl;

        cout << "Оцінки: ";
        for(int i = 0; i < 4; i++) {
            cout << reviews[i] << " ";
        }

        cout << "\nСередня оцінка: " << getAverage() << endl;
    }
};

int main() {
    Game game1, game2;
    game1.init("Dead cells", "Motion Twin", 9, 10, 8, 9);
    game2.init("Terraria", "Re-Logic", 9, 10, 10, 9);
    game1.showInfo();
    game2.showInfo();
    return 0;
}

