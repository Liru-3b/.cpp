
#include <string>
#include <iomanip>
#include <iostream>

// Function Prototypes
double getValidScore(const std::string& category);
std::string getLetterGrade(double score);

int main() {
    // Constants for grade weights
    const double ASSIGN_WEIGHT = 0.15;
    const double TEST_WEIGHT   = 0.50;
    const double EXAM_WEIGHT   = 0.30;
    const double PARTIC_WEIGHT = 0.05;

    std::cout << "Grade Calculator - Computer Programming I\n";
    std::cout << "------------------------------------------\n";

    // Data Collection
    // We calculate the contribution of each category immediately
    double assignScore = getValidScore("Programming Assignments") * ASSIGN_WEIGHT;
    double testScore   = getValidScore("Chapter Tests")           * TEST_WEIGHT;
    double examScore   = getValidScore("Final Exam")              * EXAM_WEIGHT;
    double particScore = getValidScore("Class Participation")     * PARTIC_WEIGHT;

    // Total Calculation
    double finalNumericGrade = assignScore + testScore + examScore + particScore;

    // Output Results
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nCategory Contributions to Final Grade:\n"
              << "\tAssignments:   " << assignScore << "%\n"
              << "\tTests:         " << testScore   << "%\n"
              << "\tFinal Exam:    " << examScore   << "%\n"
              << "\tParticipation: " << particScore << "%\n";

    std::cout << "\nFinal Numeric Grade: " << finalNumericGrade << "%";
    std::cout << "\nLetter Grade:        " << getLetterGrade(finalNumericGrade) << std::endl;
}

// Helper function to handle input and basic validation
double getValidScore(const std::string& category) {
    using namespace std;
    cout << "Enter the percentage earned for " 
         << category << " (0-100): ";

    double score; 
    cin >> score;
    return score;}

// Logic for determining letter grade
std::string getLetterGrade(double score) {
    if (score >= 97) return "A+";
    if (score >= 94) return "A";
    if (score >= 90) return "A-";
    if (score >= 87) return "B+";
    if (score >= 84) return "B";
    if (score >= 80) return "B-";
    if (score >= 77) return "C+";
    if (score >= 74) return "C";
    if (score >= 70) return "C-";
    if (score >= 60) return "D";
    return "F";}