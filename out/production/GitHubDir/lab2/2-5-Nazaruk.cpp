#include <iostream>
using namespace std;

class MarathonRunner {
private:
    float distance_km, time_hours;
public:
    MarathonRunner(double distance, double time){
    distance_km = distance;
    time_hours = time;
}

    float average_speed() const {
        if (time_hours == 0) {
            cerr << "Error: час не може бути рівний нулю" << endl;
            return 0;
        }
        return distance_km / time_hours;
    }
};

int main() {
    float l, t;
    cin >> l >> t; 
    MarathonRunner run (l, t);
    cout << "Середня швидкість: "<< run.average_speed() << " km/h" << endl;
    return 0;
}
