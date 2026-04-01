#include <iostream>
#include <string>
using namespace std;

class DataCarrier {
protected:
    float capacity;

public:
    DataCarrier(float capacity = 0.0f) : capacity(capacity) {}

    virtual void printInfo() const {
        cout << "Capacity: " << capacity << " GB\n";
    }

    virtual ~DataCarrier() {
        cout << "DataCarrier destroyed\n";
    }
};

class HardDrive : public DataCarrier {
private:
    int cylinders;
    int tracks;
    int sectors;
    string brand;

public:
    HardDrive(float capacity, int cylinders, int tracks, int sectors, string brand)
        : DataCarrier(capacity),
          cylinders(cylinders),
          tracks(tracks),
          sectors(sectors),
          brand(brand) {}

    void printInfo() const override {
        cout << "Hard Drive (" << brand << ")\n";
        cout << "Capacity: " << capacity << " GB\n";
        cout << "Cylinders: " << cylinders
             << ", Tracks: " << tracks
             << ", Sectors: " << sectors << endl;
    }

    ~HardDrive() override {
        cout << "HardDrive destroyed\n";
    }
};

class OpticalDisk : public DataCarrier {
private:
    int cylinders;
    int tracks;
    int sectors;
    string brand;

public:
    OpticalDisk(float capacity, int cylinders, int tracks, int sectors, string brand)
        : DataCarrier(capacity),
          cylinders(cylinders),
          tracks(tracks),
          sectors(sectors),
          brand(brand) {}

    void printInfo() const override {
        cout << "Optical Disk (" << brand << ")\n";
        cout << "Capacity: " << capacity << " GB\n";
        cout << "Cylinders: " << cylinders
             << ", Tracks: " << tracks
             << ", Sectors: " << sectors << endl;
    }

    ~OpticalDisk() override {
        cout << "OpticalDisk destroyed\n";
    }
};

int main() {
    DataCarrier* hdd = new HardDrive(1024.0f, 2000, 150, 63, "KingStone");
    DataCarrier* disk = new OpticalDisk(4.7f, 300, 50, 20, "Sony");

    cout << endl;
    hdd->printInfo();
    cout << endl;
    disk->printInfo();

    delete hdd;
    delete disk;
    
    cout << endl;
    return 0;
}
