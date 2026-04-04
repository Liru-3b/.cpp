#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

void logMessage(std::ostream& os1, std::ostream& os2, const std::string& msg, bool endLine = true) {
    os1 << msg;
    os2 << msg;
    if (endLine) {
        os1 << std::endl;
        os2 << std::endl;
    }}

int main() {
    const int MAX_FINGERS = 5;
    const int MIN_FINGERS = 1;
    const int MAX_GUESS = 10;
    const int MIN_GUESS = 1; 
    const int TOTAL_GAMES = 10;

    int p1Fingers, p1Guess, p2Fingers, p2Guess, sum;
    int p1Wins = 0, p2Wins = 0;

    std::ofstream outFile("morraSeriesResults.txt");
    if (!outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int game = 1; game <= TOTAL_GAMES; ++game) {
        p1Fingers = std::rand() % (MAX_FINGERS - MIN_FINGERS + 1) + MIN_FINGERS;
        p2Fingers = std::rand() % (MAX_FINGERS - MIN_FINGERS + 1) + MIN_FINGERS;
        
        p1Guess = std::rand() % (MAX_GUESS - MIN_GUESS + 1) + MIN_GUESS;
        p2Guess = std::rand() % (MAX_GUESS - MIN_GUESS + 1) + MIN_GUESS;
        sum = p1Fingers + p2Fingers;

        std::cout << "\n--- GAME " << game << " ---" << std::endl;
        std::cout << std::left << std::setw(10) << "PLAYER" << " | " 
                  << std::setw(8) << "FINGERS" << " | " << "GUESS" << std::endl;
        std::cout << std::string(30, '-') << std::endl;

        std::cout << std::setw(10) << "Player 1" << " | " 
                  << std::setw(8) << p1Fingers << " | " << p1Guess << std::endl;
        std::cout << std::setw(10) << "Player 2" << " | " 
                  << std::setw(8) << p2Fingers << " | " << p2Guess << std::endl;

        std::cout << "Correct Total: " << sum << std::endl;

        std::string result;
        if (p1Guess == sum && p2Guess == sum) result = "Result: DRAW (Both guessed correctly!)";
        else if (p1Guess == sum) {result = "Result: PLAYER 1 WINS!"; p1Wins++;}
        else if (p2Guess == sum) {result = "Result: PLAYER 2 WINS!"; p2Wins++;}
        else result = "Result: lNO ONE WINS (Both guessed wrong)";
        
        logMessage(std::cout, outFile, result);
    }

    std::string line = "=====================================";
    logMessage(std::cout, outFile, "\n" + line);
    logMessage(std::cout, outFile, "       MORRA SERIES SUMMARY");
    logMessage(std::cout, outFile, line);
    logMessage(std::cout, outFile, "Player 1 Wins: " + std::to_string(p1Wins));
    logMessage(std::cout, outFile, "Player 2 Wins: " + std::to_string(p2Wins));

    std::string finalWinner;
    if (p1Wins > p2Wins) finalWinner = "SERIES WINNER: PLAYER 1";
    else if (p2Wins > p1Wins) finalWinner = "SERIES WINNER: PLAYER 2";
    else finalWinner = "SERIES RESULT: OVERALL TIE";

    logMessage(std::cout, outFile, "\n" + finalWinner);
    logMessage(std::cout, outFile, line);

    outFile.close();
    return 0;
}