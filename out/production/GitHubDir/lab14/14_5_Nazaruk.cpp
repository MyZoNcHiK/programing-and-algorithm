#include <iostream>
#include <vector>
#include <string>
using namespace std;
template <typename T> size_t findPosition(const vector<T>& v, const T& value){
    size_t left = 0;
    size_t right = v.size();

    while (left < right){
        size_t mid = left + (right - left) / 2;
        if (v[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}
class Person{
    private:
        string name;
        int height;
    public:
        Person(string n, int h) : name(n), height(h) {}
        bool operator<(Person other) const{
            return height < other.height;
        }
};
int main(){
    vector<int> heights = {160, 170, 175, 180};
    int newHeight = 172;
    cout << "int position: " << findPosition(heights, newHeight) << endl;

    vector<double> doubles = {1.5, 2.3, 3.7};
    double newDouble = 2.0;
    cout << "double position: " << findPosition(doubles, newDouble) << endl;

    vector<char> chars = {'a', 'c', 'e'};
    char newChar = 'd';
    cout << "char position: " << findPosition(chars, newChar) << endl;

    vector<Person> group = {
        Person("Ivan", 175),
        Person("Oleh", 178),
        Person("Illa", 177)
    };

    Person newPerson("Maksym", 193);
    size_t pos = findPosition(group, newPerson);
    cout << "Person position: " << pos << endl;

    return 0;
}
