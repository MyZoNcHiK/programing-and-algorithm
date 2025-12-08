#include<iostream>
#include<cstring>
#include<fstream>
#include<regex>
using namespace std;

int main() {
    ofstream ofile("sample1.txt");
    ofile <<"111.111.111.111\ngsfehlkdgahklasglhkdxklhdvhk 123.5124.35.534 222.121.125.137\n wihgslrhglhs l11.111.111.111  gsr 555.555.555.555\n 222.121.125.133" << endl;
    ofile.close();
    ifstream file("sample1.txt");
    string line;
    regex ip_regex(R"(\b((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\b)");
    int uniq=0;
    if(file.is_open()) {
        while (std::getline(file, line)) {     
           smatch match;
           if(regex_search(line, match, ip_regex)) {
                cout << "Found IP: " << match.str(0) << endl;
                uniq++;
            }
        }       
    }
    file.close();
    cout << "unique: " << uniq << endl;
    return 0;
}
