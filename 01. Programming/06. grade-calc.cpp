
#include <iostream>
#include <string>
#include <iomanip>

struct GradeData {
    float assignments;
    float tests;
    float exam;
    float participation;
};

GradeData getGradesFromUser();
float calculateFinalGrade(const GradeData& scores, const GradeData& weights);
void displaySummary(const GradeData& scores, const GradeData& weights, float finalGrade);

int main() {
    const GradeData WEIGHTS = {15.0f, 50.0f, 30.0f, 5.0f};

    std::cout << "Grade Calculator - Computer Programming I\n";
    std::cout << "------------------------------------------\n";
    std::cout << "Weight Distribution:\n"
              << "\tAssignments:   " << WEIGHTS.assignments << "%\n"
              << "\tChapter Tests: " << WEIGHTS.tests << "%\n"
              << "\tFinal Exam:    " << WEIGHTS.exam << "%\n"
              << "\tParticipation: " << WEIGHTS.participation << "%\n";

    GradeData userScores = getGradesFromUser();
    float finalGrade = calculateFinalGrade(userScores, WEIGHTS);
    displaySummary(userScores, WEIGHTS, finalGrade);
}

GradeData getGradesFromUser() {
    GradeData input;
    std::cout << "\nEnter your scores (0-100):\n";
    
    std::cout << "Programming Assignments: ";
    std::cin >> input.assignments;

    std::cout << "Chapter Tests:           ";
    std::cin >> input.tests;

    std::cout << "Final Exam:              ";
    std::cin >> input.exam;

    std::cout << "Class Participation:     ";
    std::cin >> input.participation;

    return input;
}

float calculateFinalGrade(const GradeData& scores, const GradeData& weights) {
    float weightedSum = (scores.assignments * weights.assignments) +
                        (scores.tests * weights.tests) +
                        (scores.exam * weights.exam) +
                        (scores.participation * weights.participation);
    
    return weightedSum / 100.0f;
}

void displaySummary(const GradeData& scores, const GradeData& weights, float finalGrade) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n--- Grade Breakdown ---\n";
    
    std::cout << "Assignments:   " << (scores.assignments * weights.assignments / 100.0f) << " pts\n";
    std::cout << "Tests:         " << (scores.tests * weights.tests / 100.0f) << " pts\n";
    std::cout << "Final Exam:    " << (scores.exam * weights.exam / 100.0f) << " pts\n";
    std::cout << "Participation: " << (scores.participation * weights.participation / 100.0f) << " pts\n";
    
    std::cout << "\nFINAL GRADE: " << finalGrade << "%\n";
}