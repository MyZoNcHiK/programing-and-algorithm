#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

struct TM {
    using State = string;
    using Symbol = char;
    using Move   = char; 
    using Transition = tuple<State, Symbol, Move>;

    map<pair<State, Symbol>, Transition> rules;
    State start;
    State accept;
    Symbol blank = '_';

    string run(const string& input, bool trace = true) {
        map<long long, Symbol> tape;
        for (long long i = 0; i < (long long)input.size(); i++)
            tape[i] = input[i];

        long long head = 0;
        State state = start;
        long long step = 0;

        auto read = [&](long long pos) {
            return tape.count(pos) ? tape[pos] : blank;
        };

        auto write = [&](long long pos, Symbol s) {
            if (s == blank && tape.count(pos)) tape.erase(pos);
            else tape[pos] = s;
        };

        auto tapeToString = [&](long long headPos) {
            if (tape.empty()) return string("_");

            long long L = tape.begin()->first;
            long long R = tape.rbegin()->first;

            string out;
            for (long long i = L; i <= R; i++) {
                if (i == headPos) out += "[" + string(1, read(i)) + "]";
                else out += read(i);
            }
            return out;
        };

        if (trace) {
            cout << "Step\tState\tHead\tTape\n";
            cout << "----------------------------------------\n";
        }

        while (true) {
            if (trace) {
                cout << step << "\t" << state << "\t" << head
                     << "\t" << tapeToString(head) << "\n";
            }

            if (state == accept) break;

            Symbol s = read(head);
            auto key = make_pair(state, s);

            if (!rules.count(key)) {
                if (trace) cout << "No transition. Halt.\n";
                break;
            }

            auto [newState, writeSym, move] = rules[key];
            write(head, writeSym);

            if (move == 'L') head--;
            else if (move == 'R') head++;

            state = newState;
            step++;
        }

        if (tape.empty()) return "_";

        long long L = tape.begin()->first;
        long long R = tape.rbegin()->first;

        string res;
        for (long long i = L; i <= R; i++) res += read(i);

        while (!res.empty() && res.front() == blank) res.erase(res.begin());
        while (!res.empty() && res.back() == blank) res.pop_back();

        return res.empty() ? "_" : res;
    }
};

int main() {
    TM tm;

    tm.start  = "q0";
    tm.accept = "qf";
    tm.blank  = '_';

    tm.rules[{"q0", '0'}] = {"q0", '0', 'R'};
    tm.rules[{"q0", '1'}] = {"q0", '1', 'R'};
    tm.rules[{"q0", '_'}] = {"q1", '_', 'L'};

    tm.rules[{"q1", '0'}] = {"qf", '1', 'S'};
    tm.rules[{"q1", '1'}] = {"q1", '0', 'L'};
    tm.rules[{"q1", '_'}] = {"qf", '1', 'S'};

    string input = "1011";
    cout << "Input: " << input << "\n\n";

    string result = tm.run(input, true);

    cout << "\nResult: " << result << "\n";
}

