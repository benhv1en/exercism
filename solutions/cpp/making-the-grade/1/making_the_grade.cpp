#include <array>
#include <string>
#include <vector>
#include <cmath>
// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> scores;
    for (double score : student_scores) scores.push_back(floor(score));
    return scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int count = 0;
    for (const int& score : student_scores) if (score <= 40) ++count;
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    std::array <int, 4> grades;
    for (int i = 0; i < grades.size(); ++i) grades [i] = 41 + (highest_score - 40) * i / 4; 
    return grades;
}
#include <stack>
std::string Stringify(int number) {
    std::stack<int> digits;
    std::string stringified;
    while (number != 0) {
        digits.push(number % 10);
        number /= 10;
    }
    while (!digits.empty()) {
        stringified.push_back(digits.top() + '0');
        digits.pop();
    }
    return stringified;
}
// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> rankings;
    for (int i = 0; i < student_names.size(); ++i) {
        rankings.push_back(Stringify(i + 1) + ". " + student_names[i] + ": " + Stringify(student_scores[i]));
    };
    return rankings;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    for (int i = 0; i < student_scores.size(); ++i) if (student_scores[i] == 100) return student_names[i];
    return "";
}
