#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;

struct Appliance {
    string name;
    double powerW;
    double hoursPerDay;

    double energyKWhPerDay() const {
        return (powerW * hoursPerDay) / 1000.0;
    }

    double energyKWhPerMonth() const {
        return energyKWhPerDay() * 30;
    }
};

static void clearBadInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int menu() {
    cout << "\n==============================\n";
    cout << "     Electrical Load Monitoring\n";
    cout << "==============================\n";
    cout << "1. Register appliance\n";
    cout << "2. View all appliances\n";
    cout << "3. Energy summary\n";
    cout << "4. Billing summary\n";
    cout << "0. Exit\n";
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if (cin.fail()) {
        clearBadInput();
        return -1;
    }
    return choice;
}

Appliance registerAppliance() {
    Appliance a{};

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    do {
        cout << "Enter appliance name: ";
        getline(cin, a.name);
    } while (a.name.empty());

    while (true) {
        cout << "Enter power rating (W): ";
        cin >> a.powerW;
        if (!cin.fail() && a.powerW > 0) break;
        clearBadInput();
    }

    while (true) {
        cout << "Enter usage hours per day (0 - 24): ";
        cin >> a.hoursPerDay;
        if (!cin.fail() && a.hoursPerDay >= 0 && a.hoursPerDay <= 24) break;
        clearBadInput();
    }

    return a;
}

double calculateTotalEnergyPerDay(const vector<Appliance>& appliances) {
    double total = 0.0;
    for (const auto& a : appliances)
        total += a.energyKWhPerDay();
    return total;
}

void showEnergySummary(const vector<Appliance>& appliances) {
    if (appliances.empty()) {
        cout << "No appliances registered.\n";
        return;
    }

    cout << "\n=========== LOAD REPORT ===========\n";

    for (const auto& a : appliances) {
        cout << "Appliance: " << a.name << endl;
        cout << "Daily Energy: " << a.energyKWhPerDay() << " kWh\n";
        cout << "Monthly Energy: " << a.energyKWhPerMonth() << " kWh\n";
        cout << "-----------------------------------\n";
    }

    cout << "Total Daily Energy: "
         << calculateTotalEnergyPerDay(appliances)
         << " kWh\n";
}

void calculateBill(const vector<Appliance>& appliances) {
    if (appliances.empty()) {
        cout << "No appliances registered.\n";
        return;
    }

    double tariff;

    while (true) {
        cout << "Enter tariff per kWh: ";
        cin >> tariff;
        if (!cin.fail() && tariff > 0) break;
        clearBadInput();
    }

    double totalDaily = calculateTotalEnergyPerDay(appliances);
    double totalMonthly = totalDaily * 30;
    double totalCost = totalMonthly * tariff;

    cout << "\n=========== BILLING SUMMARY ===========\n";
    cout << "Total Monthly Energy: " << totalMonthly << " kWh\n";
    cout << "Tariff: " << tariff << "\n";
    cout << "Total Monthly Cost: " << totalCost << "\n";
}

int main() {
    vector<Appliance> appliances;

    while (true) {
        int choice = menu();

        switch (choice) {
            case 1:
                appliances.push_back(registerAppliance());
                break;

            case 2:
                showEnergySummary(appliances);
                break;

            case 3:
                showEnergySummary(appliances);
                break;

            case 4:
                calculateBill(appliances);
                break;

            case 0:
                cout << "Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }
}