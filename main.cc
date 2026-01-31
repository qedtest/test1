#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

void calc(string inputstr) {

    stringstream ss(inputstr);
    stack<string> calc;

    for (string instr; ss >> instr; ) {
        calc.push(instr);

        // For each input value, we exhaust the stack
        while (calc.size() > 2) {
            string word1;
            word1 = calc.top();
            if (word1 == "+" || word1 == "-" || word1 == "*" || word1 == "/") {
                break;
            }
            int val1 = stoi(word1);
            calc.pop();

            string word2 = calc.top();
            if (word2 == "+" || word2 == "-" || word2 == "*" || word2 == "/") {
                calc.push(word1);
                break;
            }
            int val2 = stoi(word2);
            calc.pop();

            string oper = calc.top();
            calc.pop();
            int res;
            if (oper == "+") {
                res = val2 + val1;
            } else if (oper == "-") {
                res = val2 - val1;
            } else if (oper == "*") {
                res = val2 * val1;
            } else if (oper == "/") {
                res = val2 / val1;
            }
            calc.push(to_string(res));
        }
    }

    cout << calc.top() << endl;
}

int main(void) {
    calc("+ 2 3");
    calc("+ 1 * 2 3");
    calc("+ * 1 2 3");
    calc("/ 10 2");
    calc("+ + + 1 2 3 4");
    calc("+ 1 + 2 + 3 4");
    calc("/ - 15 5 - 3 1");
    calc("+ + 1 + 2 + 3 4 5");
    calc("- 4 1");
}
