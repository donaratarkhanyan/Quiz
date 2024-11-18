#ifndef QUIZ_H
#define QUIZ_H
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>

enum class Difficulty { EASY, MEDIUM, HARD }; // questions levels

struct Student {
    int id; // for student id
    std::string name; // for student name
    std::unordered_map<int, std::pair<int, bool>> quizAnswers; //int-y harceri id-n, pair-i inty patasxani hamary, bool-y  patasxani true kam false linely
};

struct Question {
    int id; //This is a unique identifier for the question.
    std::string text; // pahanjy Example: "What is the capital of Armenia?"
    std::vector<std::string> options; // list of four answer options
    int correctOption; // index (0 to 3) of the correct answer in options
    Difficulty dif; // harci level
};

class Quiz {
public:
    void addStudent(int id, const std::string& name);
    void addQuestion(const std::string& category, int id, const std::string& text, const std::vector<std::string>& options, int options_num, Difficulty dif);
    void displayCategories();
    std::vector<Question> getRandomQuestion(const std::string& category);
    void displayResults(const Student& student, const std::vector<Question>& questions);
    void takeQuiz(Student& student, const std::string& category);
    void Certificate(const Student& student, const std::string& category, int percentage);
    std::unordered_map<int, Student> students; // int -> student
    std::unordered_map<std::string, std::vector<Question>> questions; // catigory -> list of questions
};

#endif // QUIZ_H