#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Mob {
protected:
    int hp;
public:
    Mob(int h) : hp(h) {}
    virtual ~Mob(){
    cout << "Mob deleted" << endl;
    }
    virtual int takeDamage(int damage) {
        hp -= damage;
        if (hp < 0) hp = 0;
        return hp;
    }
    int getHp() const {
        return hp;
    }

    virtual bool isCreeper() const {
        return false;
    }
    virtual void action(){}
};

class Zombie : public Mob {
public:
    Zombie() : Mob(20) {}
    ~Zombie(){
    cout << "Zombie deleted" << endl;
    }
    int takeDamage(int damage) override {
        cout << "grrrr" << endl;
        return Mob::takeDamage(damage);
    }
};

class Skeleton : public Mob {
public:
    Skeleton() : Mob(15) {}
    ~Skeleton(){
    cout << "Skeleton deleted" << endl;
    }
    int takeDamage(int damage) override {
        cout << "clack clack" << endl;
        return Mob::takeDamage(damage);
    }
};

class Creeper : public Mob {
public:
    Creeper() : Mob(25) {}
    ~Creeper(){
    cout << "Creeper deleted" << endl;
    }
    int takeDamage(int damage) override {
        cout << "sssss" << endl;
        int hp_left = Mob::takeDamage(damage);
        if(hp_left < 5){
            action();
        } return hp_left;
    }
    bool isCreeper() const override {
        return true;
    }
    void action() override {
        cout << "Creeper: BOOM" << endl;
    }
};

Mob* getRandomMob() {
    int r = rand() % 3;
    if (r == 0) return new Zombie();
    if (r == 1) return new Skeleton();
    return new Creeper();
}

vector<Mob*> spawnMobs() {
    vector<Mob*> mobs;
    for (int i = 0; i < 5; i++) {
        mobs.push_back(getRandomMob());
    }
    return mobs;
}

int main() {
    srand(time(nullptr));
    vector<Mob*> mobs = spawnMobs();
    int damage = 0;
    cin >> damage;
    for (Mob* mob : mobs) {
        int hp = *mob.takeDamage(damage);
        cout << "HP left: " << hp << endl;
        delete mob;
        cout << endl;
    }
    return 0;
}
