#include "quiz.h"

void Quiz::addStudent(int id, const std::string& name){
    if (students.contains(id)) {
        std::cerr << "Already Contains that id, pls change your id!!!" << std::endl;
        return;
    }
    students[id] = Student{id, name, {}};
}

void Quiz::addQuestion(const std::string& category, int id, const std::string& text, const std::vector<std::string>& options, int options_num, Difficulty dif){
    for (const auto& question : questions[category]) {
        if (question.id == id) {
            std::cerr << "Question ID already exists in this category. Please use a different ID!" << std::endl;
            return; // duplicate question ID in the same category
        }
    }
    questions[category].push_back(Question{id, text, options, options_num, dif});
}

void Quiz::displayCategories() {
    std::cout << "Available Categories: Math, History, English\n";
}


std::vector<Question> Quiz::getRandomQuestion (const std::string& category) {
    if (questions.find(category) == questions.end()) {
        std::cerr << "Category not found!!" << std::endl;
        return {};
    }
    return questions[category];
}

void Quiz::displayResults(const Student& student, const std::vector<Question>& quest){ // quest quizi yntacqum questionseri cank
    std::cout << "\nResults:\n";
    int questionNumber = 1; // 1), 2) harceri hamarnery
    int score = 0; // true patasxanneri miavornery

    for (const auto& question : quest) {
        int chosenAnswer = student.quizAnswers.at(question.id).first;  // studenti yntrac patasxany
        bool wascorrect = student.quizAnswers.at(question.id).second; // the answer correct or not

        if (wascorrect){
            ++score;
        }

        std::cout << questionNumber << ") " << question.text << std::endl;
        std::cout << "Your answer: " << question.options[chosenAnswer] << " - " << (wascorrect ? "TRUE" : "FALSE") << std::endl;
        std::cout << "True answer -> " << question.options[question.correctOption] << std::endl << std::endl;

        ++questionNumber;
    }
    std::cout << "You scored " << score << " out of " << quest.size() << "!" << std::endl;
}
 
void Quiz::Certificate(const Student& student, const std::string& category, int percentage) {
    std::cout << "\nCongratulations, " << student.name << "! You passed the " << category << " quiz.\n";
    std::cout << "Certificate of Completion awarded for achieving a score of " << percentage << "%  or higher.\n\n";
}

void Quiz::takeQuiz(Student& student, const std::string& category) {
    if (questions.find(category) == questions.end()){ 
        std::cerr << "Category not found!!" << std::endl;
        return;
    }

    std::vector<Question> quest = getRandomQuestion(category);
    int questionNumber = 1; // harceri hamarakalum 
    int score = 0; // havaqac miavorner(chisht patasxanneric)
    int totalQuestions = quest.size(); // testi yntacqum yndhanur harceri qanaky

    for (const auto& question : quest) { // ancnum e harceri mijov
        std::cout << questionNumber << ") " << question.text << std::endl; // tpum e harci hamary u harcy
        for (int i = 0; i < question.options.size(); ++i) {
            std::cout << i + 1 << ". " << question.options[i] << std::endl; // ancnum e harci pataxnaneri vrayov ev tpum
        }

        auto start = std::chrono::steady_clock::now();
        std::cout << "You have 10 seconds to answer. Enter your answer number: ";
        
        int answer = 0;
        std::cin >> answer; // nermucum e patasxany
        answer -= 1; // 0akan indexaciayi enq berum -1 anelov

        auto end = std::chrono::steady_clock::now(); // hashvarkum e usanoxi patasxani jamanaky 
        std::chrono::duration<double> elapsed = end - start; // pahum e patasxani jamanaky 

        bool isCorrect = (answer == question.correctOption);
        if (elapsed.count() > 15.0){
            std::cout << "Time's up! Moving to the next question." << std::endl;
            isCorrect = false; // 15 vayrkyani yntacqum patasxan chi exel, ayd patasxany hashvum e sxal ev ancnum enq hajord harcin
        } else {
            if(isCorrect) ++score; // jamanaki mej texavorvelov patasxany chisht e exel ev havaqum enq mivor
            student.quizAnswers[question.id] = {answer, isCorrect}; // init enq anum studenti pairy arden chisht patasxanov
        }
        ++questionNumber; // ancanq hajord harcin
    }
    displayResults(student, quest);
    int percentage = (static_cast<double>(score) / totalQuestions) * 100;
    if (score >= totalQuestions * 0.6) { // score petqa lini % certeficate stanalu hamar
        Certificate(student, category, percentage); 
    }
}