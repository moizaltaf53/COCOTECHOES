#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Expense {
    string title;
    string payer;
    vector<string> parties;
};

void splitExpenses(map<int, Expense>& expenses, int numParties) {
    srand(time(0));

    for (int i = 1; i <= 10; ++i) {
        Expense expense;
        expense.title = "Expense " + to_string(i);

        // Randomly select a payer
        int payerIndex = rand() % numParties;
        expense.payer = "Person " + to_string(payerIndex + 1);

        // Assign all parties
        for (int j = 0; j < numParties; ++j) {
            if (j != payerIndex) {
                expense.parties.push_back("Person " + to_string(j + 1));
            }
        }

        // Add the expense to the map
        expenses[i] = expense;
    }
}

void printExpenses(const map<int, Expense>& expenses) {
    for (const auto& entry : expenses) {
        cout << entry.second.title << ":\n";
        cout << "  Payer: " << entry.second.payer << "\n";
        cout << "  Parties: ";
        for (const auto& party : entry.second.parties) {
            cout << party << " ";
        }
        cout << "\n\n";
    }
}

int main() {
    int numParties = 5; // You can change this to the desired number of parties
    map<int, Expense> expenses;

    splitExpenses(expenses, numParties);
    printExpenses(expenses);
   
    return 0;
}
