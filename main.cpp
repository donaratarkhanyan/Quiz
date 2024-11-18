#include <iostream>
#include "quiz.h"

int main() {
    int studentId;
    std::string studentName;
    
    std::cout << "Enter your name: ";
    std::cin >> studentName;
    std::cout << "Enter your student ID: ";
    std::cin >> studentId;

    Quiz quiz;
    quiz.addStudent(studentId, studentName);

    // Math quesions
    quiz.addQuestion("Math", 101, "What is 2 + 2?", {"3", "4", "5", "6"}, 1, Difficulty::EASY);
    quiz.addQuestion("Math", 102, "What is 5 * 2?", {"7", "8", "9", "10"}, 3, Difficulty::HARD);
    quiz.addQuestion("Math", 103, "What is 10 / 2?", {"4", "5", "6", "7"}, 1, Difficulty::MEDIUM);
    quiz.addQuestion("Math", 104, "What is 6 + 3?", {"7", "8", "9", "10"}, 2, Difficulty::HARD);
    quiz.addQuestion("Math", 105, "What is 8 - 3?", {"5", "6", "7", "8"}, 0, Difficulty::EASY);
    quiz.addQuestion("Math", 106, "What is 3 * 3?", {"6", "7", "8", "9"}, 3, Difficulty::HARD);
    quiz.addQuestion("Math", 107, "What is 12 / 3?", {"2", "3", "4", "5"}, 2, Difficulty::MEDIUM);
    quiz.addQuestion("Math", 108, "What is 4 + 5?", {"7", "8", "9", "10"}, 2, Difficulty::MEDIUM);
    quiz.addQuestion("Math", 109, "What is 7 - 2?", {"4", "5", "6", "7"}, 1, Difficulty::EASY);
    quiz.addQuestion("Math", 110, "What is 3 + 6?", {"8", "9", "10", "11"}, 1, Difficulty::EASY);

    // History questions
    quiz.addQuestion("History", 201, "When did the Armenian Genocide begin?", {"1915", "1920", "1945", "1988"}, 0, Difficulty::EASY);
    quiz.addQuestion("History", 202, "Who is considered the founder of the Armenian alphabet?", {"Saint Vardan", "Mesrop Mashtots", "Movses Khorenatsi", "Saint Gregory"}, 1, Difficulty::MEDIUM);
    quiz.addQuestion("History", 203, "When did Armenia gain independence from the Soviet Union?", {"1988", "1991", "1994", "1999"}, 1, Difficulty::EASY);
    quiz.addQuestion("History", 204, "Who was the first President of independent Armenia?", {"Robert Kocharyan", "Levon Ter-Petrosyan", "Serzh Sargsyan", "Aram Manukyan"}, 1, Difficulty::MEDIUM);
    quiz.addQuestion("History", 205, "In which year was the Treaty of Sèvres signed?", {"1915", "1920", "1945", "1988"}, 1, Difficulty::EASY);
    quiz.addQuestion("History", 206, "Which city is known as the first capital of Armenia?", {"Gyumri", "Van", "Yerevan", "Artashat"}, 3, Difficulty::HARD);
    quiz.addQuestion("History", 207, "What was the name of the medieval Armenian kingdom founded by the Bagratuni dynasty?", {"Kingdom of Cilicia", "Kingdom of Armenia", "Urartu", "Artashesian Kingdom"}, 1, Difficulty::MEDIUM);
    quiz.addQuestion("History", 208, "Who led the Armenian forces at the Battle of Sardarapat in 1918?", {"Garegin Nzhdeh", "Andranik Ozanian", "Dro", "Vazgen Sargsyan"}, 2, Difficulty::HARD);
    quiz.addQuestion("History", 209, "When did Armenia officially adopt Christianity as its state religion?", {"301 AD", "451 AD", "600 AD", "1001 AD"}, 0, Difficulty::EASY);
    quiz.addQuestion("History", 210, "Who is known as the 'Father of the Armenian Nation'?", {"Tigran the Great", "Mesrop Mashtots", "Aram Manukyan", "Ashot II"}, 2, Difficulty::MEDIUM);

    // English questions
    quiz.addQuestion("English", 301, "What is the synonym of 'happy'?", {"Sad", "Elated", "Angry", "Tired"}, 1, Difficulty::EASY);
    quiz.addQuestion("English", 302, "What is the past tense of 'run'?", {"Running", "Ran", "Runs", "Runned"}, 1, Difficulty::EASY);
    quiz.addQuestion("English", 303, "Which of these is an adjective?", {"Quickly", "Beautiful", "Run", "Happily"}, 1, Difficulty::MEDIUM);
    quiz.addQuestion("English", 304, "What is the plural of 'child'?", {"Children", "Childs", "Childes", "Child"}, 0, Difficulty::HARD);
    quiz.addQuestion("English", 305, "Which of these is a noun?", {"Quickly", "Big", "Happiness", "Run"}, 2, Difficulty::MEDIUM);
    quiz.addQuestion("English", 306, "What is the opposite of 'hot'?", {"Warm", "Cool", "Cold", "Humid"}, 2, Difficulty::EASY);
    quiz.addQuestion("English", 307, "Which of these is a verb?", {"Sky", "Eat", "Fast", "Table"}, 1, Difficulty::HARD);
    quiz.addQuestion("English", 308, "What is the comparative form of 'good'?", {"Best", "Better", "Gooder", "More Good"}, 1, Difficulty::HARD);
    quiz.addQuestion("English", 309, "What is the synonym of 'smart'?", {"Dull", "Intelligent", "Slow", "Weak"}, 1, Difficulty::EASY);
    quiz.addQuestion("English", 310, "What is the correct spelling?", {"Recieve", "Receive", "Recive", "Receeve"}, 1, Difficulty::HARD);

    Student& student = quiz.students[studentId];
    std::cout << "Hello, " << student.name << "! Please choose a category!" << std::endl;
    quiz.displayCategories();
    std::string category;
    std::cin >> category;
    quiz.takeQuiz(student, category);
    return 0;
}