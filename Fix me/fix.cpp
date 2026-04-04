#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <iomanip> 

/*Data Structure*/
struct User {
    std::string name;
    int accountID;
    double balance = 0;
    double invested = 0;
    double loanBalance = 0;
    std::vector<double> history; 
    std::vector<std::string> logs;};

int generateID(std::string name) {
    int id = 0;
    for(char c : name) 
        id += (int)c;
    return id;}

int secureMask(int val) {
    int key = 123;
    return val ^ key;}

double predictLoan(double P, double r, double t) {
    return P * std::pow((1 + r/100), t);}

void applyLoanPayment(User &u, double payment) {
    if (u.loanBalance > 0) {
        u.balance -= payment;
        u.loanBalance -= payment;
        u.logs.push_back("Loan Pay: -$" + std::to_string(payment));
    }}

/*Amortization: $$M = P frac{r(1+r)^n} {(1+r)^n - 1}$$ */
double calculateMonthlyPayment(double P, double annualRate, int months) {
    double r = annualRate / 12 / 100; // Monthly decimal rate
    return P * (r * std::pow(1 + r, months)) / (std::pow(1 + r, months) - 1);}

void processDataBlock(User &u, const std::vector<double>& block) {
    for (size_t i = 0; i < block.size(); i += 2) {
        int action = (int)block[i];
        double amount = block[i+1];
        
        std::string saved, invst, spent;
        saved = "Saved: +" + std::to_string(amount);
        invst = "invst: -" + std::to_string(amount);
        spent = "Spent: -" + std::to_string(amount);

        saved += " (Balance: $" + std::to_string(u.balance) + ")";
        invst += " (Balance: $" + std::to_string(u.balance) + ")";
        spent += " (Balance: $" + std::to_string(u.balance) + ")";

        switch (action) { /*1: Save, 2: Invest, 3: Spend*/
            case 0: u.balance = amount; break; /*0: Balance*/
            case 1: u.balance += amount; u.logs.push_back(saved); break;
            case 2: u.balance -= amount; u.invested += amount; u.logs.push_back(invst); break;
            case 3: u.balance -= amount; u.history.push_back(amount); u.logs.push_back(spent); break;
        }}}

void showVisuals(const User &u) {
    std::cout << "\n--- SPENDING VISUALIZATION FOR " << u.name << " ---\n";
    for (double val : u.history) {
        std::cout << std::setw(8) << std::fixed 
        << std::setprecision(2) << "$" << val << " | ";
        
        int bars = (int)val / 50; 
        for (int i = 0; i < bars; i++) 
            std::cout << "#"; 
        std::cout << "\n";
    }}

int main1() {
    std::vector<User> users;
    
    // Initializing User 1
    User user;
    user.name = "Brian Liru";
    user.accountID = generateID(user.name);
    
    std::vector<double> data = { 
        /*0: Balance, 1: Save, 2: Invest, 3: Spend*/
        0, 5000,    1, 1000,    2, 4000,    3, 1000,
        3, 100,     1, 5900,    2, 800,     2, 1000,
        1, 1000,    2, 4000,    3, 1000,    1, 400,

    }; processDataBlock(user, data);

    // Simulation Output
    std::cout << "User: " << user.name << " (ID: " << user.accountID << ")\n";
    std::cout << "Current Balance: $" << user.balance << "\n";
    
    // Visual History
    showVisuals(user);

    // Loan Prediction Logic
    double totalDue = predictLoan(1000, 5, 2); 
    std::cout << "\nLoan Prediction (1000 at 5% for 2yrs): $" << totalDue << "\n";

    return 0;
}

/*-----------------------------------------------------------------------------------------------*/
struct User2 {
    std::string name;
    double balance = 0;
    double investedAmount = 0;
    double loanBalance = 0;
    std::vector<double> history; 
    std::vector<std::string> log;};

// 1. Data Block Processor
void processDataBlock(User2 &u, const std::vector<double>& data) {
    for (size_t i = 0; i < data.size(); i += 2) {
        int type = (int)data[i];
        double val = data[i+1];

        if (type == 0) u.balance = val;
        else if (type == 1) { u.balance += val; u.log.push_back("Save: +" + std::to_string(val)); }
        else if (type == 2) { u.balance -= val; u.investedAmount += val; u.log.push_back("Invest: -" + std::to_string(val)); }
        else if (type == 3) { u.balance -= val; u.history.push_back(val); u.log.push_back("Spend: -" + std::to_string(val)); }
    }}

// 2. Dynamic Investment (P/L)
void runMarketCycle(User2 &u) {
    // Simulates a range between -10% and +15%
    double change = ((rand() % 26) - 10) / 100.0; 
    double profit = u.investedAmount * change;
    u.investedAmount += profit;
    u.balance += profit; 
    std::cout << u.name << "'s Investment changed by: " << (change * 100) << "%\n";}

// 3. Text-Based Visualization
void showVisualHistory(const User2 &u) {
    std::cout << "\n--- Spending Visualization ---\n";
    for (double val : u.history) {
        int bars = (int)(val / 10); // 1 # per $10 spent
        std::cout << std::setw(6) << val << " | ";
        for (int i = 0; i < bars; ++i) std::cout << "#";
        std::cout << "\n";
    }}

// 4. Loan Deductions
void applyLoanPayment(User2 &u, double payment) {
    if (u.loanBalance > 0) {
        u.balance -= payment;
        u.loanBalance -= payment;
        u.log.push_back("Loan Pay: -$" + std::to_string(payment));
    }}

/*Amortization: $$M = P frac{r(1+r)^n} {(1+r)^n - 1}$$ */
double calculateMonthlyPayment(double P, double annualRate, int months) {
    double r = annualRate / 12 / 100; // Monthly decimal rate
    return P * (r * std::pow(1 + r, months)) / (std::pow(1 + r, months) - 1);}

int main2() {
    srand(time(0)); // Seed for random P/L
    
    // Creating Users
    User2 user1; user1.name = "Brian";
    
    // Example Data Block: [0 (Set Bal): 1000, 1 (Save): 500, 3 (Spend): 50, 3 (Spend): 120]
    std::vector<double> block = {0, 1000, 1, 500, 3, 50, 3, 120};
    processDataBlock(user1, block);

    // Simulate interactions
    runMarketCycle(user1);
    showVisualHistory(user1);

    std::cout << "Final Balance for " << user1.name << ": $" << user1.balance << "\n";
    
    return 0;
}

/*-----------------------------------------------------------------------------------------------*/
// Use a vector to store history 
std::vector<std::string> history;
double balance = 1000.0;
double totalSpent = 0.0;

void ShowHistory() {
    std::cout << "--- Transaction History ---\n";
    if (history.empty()) 
        std::cout << "No transactions yet.\n";
  
    for (const std::string& record : history) 
        std::cout << "- " << record << "\n";

    std::cout << "- Balance : $" << balance << "\n";
    std::cout << "---------------------------\n";}

void LoanPredictor() {
    double loanAmount, rate, years;
    std::cout << "Enter Loan Amount: "; std::cin >> loanAmount;
    std::cout << "Enter Interest Rate (%): "; std::cin >> rate;
    std::cout << "Enter Years: "; std::cin >> years;

    double total = loanAmount * std::pow((1 + (rate / 100)), years);
    std::cout << "Total to pay back: $" << total << "\n";}

void ProcessTransaction(int choice) {
    double amount;
    std::cout << "Enter amount: "; std::cin >> amount;

    if (choice == 1) { /*Save*/
        balance += amount;
        history.push_back(
            "Saved   : +$" + std::to_string(amount) + " "
            "(Balance: $" + std::to_string(balance) + ")");} 

    else if (choice == 2) { /*Invest*/
        balance -= amount; 
        history.push_back(
            "Invested: -$" + std::to_string(amount) + " "
            "(Balance: $" + std::to_string(balance) + ")");}

    else if (choice == 3) { /*Spend*/
        if (amount > balance) 
            std::cout << "Insufficient funds!\n";

        else {
            balance -= amount;
            totalSpent += amount;
            history.push_back(
                "Spent   : -$" + std::to_string(amount) + " "
                "(Balance: $" + std::to_string(balance) + ")");
            
            // Trajectory Warning
            if (totalSpent > (balance * 0.5)) 
                std::cout << 
                "!! WARNING: Spending has exceeded"
                " 50% of current balance !!\n";
            }}}

int main() {
    main1();
    main2();

    int choice = 0;

    while (choice != 6) {
        std::cout << "\n--- ATM MENU (Balance: $" << balance << ") ---\n";
        std::cout << "1. Save | 2. Invest | 3. Spend | 4. History | 5. Loan Tool | 6. Exit\n";
        std::cout << "Selection: "; std::cin >> choice;

        switch (choice) {
            case 1: case 2: case 3: ProcessTransaction(choice); break;
            case 4: ShowHistory(); break;
            case 5: LoanPredictor(); break;
            case 6: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice.\n";
        }}

    return 0;}