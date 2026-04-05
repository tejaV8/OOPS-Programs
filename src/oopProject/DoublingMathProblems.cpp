#include <iostream>
using namespace std;

class Fraction {
    int num;
    int den;

public:
    Fraction(int n = 0, int d = 1) {
        num = n;
        den = (d == 0) ? 1 : d;
        simplify();
    }

    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    void simplify() {
        int g = gcd(abs(num), abs(den));
        num /= g;
        den /= g;

        if (den < 0) {
            den = -den;
            num = -num;
        }
    }

    Fraction operator+(Fraction f) {
        return Fraction(num * f.den + f.num * den, den * f.den);
    }

    Fraction operator-(Fraction f) {
        return Fraction(num * f.den - f.num * den, den * f.den);
    }

    Fraction operator*(Fraction f) {
        return Fraction(num * f.num, den * f.den);
    }

    Fraction operator/(Fraction f) {
        return Fraction(num * f.den, den * f.num);
    }

    bool operator==(Fraction f) {
        return (num == f.num && den == f.den);
    }

    void input() {
        cin >> num >> den;
        simplify();
    }

    void display() {
        cout << num << "/" << den;
    }
};

class MathProblem {
    Fraction f1;
    Fraction f2;
    Fraction userAnswer;
    Fraction correctAnswer;
    char op;
    bool isAnswerCorrect;

public:
    void setProblem(Fraction a, Fraction b, char oper) {
        f1 = a;
        f2 = b;
        op = oper;

        if (op == '+')
            correctAnswer = f1 + f2;
        else if (op == '-')
            correctAnswer = f1 - f2;
        else if (op == '*')
            correctAnswer = f1 * f2;
        else if (op == '/')
            correctAnswer = f1 / f2;

        userAnswer = Fraction(0,1);
        isAnswerCorrect = false;
    }

    void displayProblem() {
        f1.display();
        cout << " " << op << " ";
        f2.display();
        cout << " = ?" << endl;
    }

    void askUserForAnswer() {
        cout << "Enter answer (num den): ";
        userAnswer.input();

        if (userAnswer == correctAnswer)
            isAnswerCorrect = true;
        else
            isAnswerCorrect = false;
    }

    void showResult() {
        f1.display();
        cout << " " << op << " ";
        f2.display();
        cout << endl;

        cout << "Your Answer: ";
        userAnswer.display();
        cout << endl;

        cout << "Correct Answer: ";
        correctAnswer.display();
        cout << endl;

        if (isAnswerCorrect)
            cout << "Correct\n";
        else
            cout << "Wrong\n";

        cout << "--------------------\n";
    }

    bool getResult() {
        return isAnswerCorrect;
    }
};

int main() {

    MathProblem problems[5];
    int score = 0;

    problems[0].setProblem(Fraction(1,2), Fraction(1,4), '+');
    problems[1].setProblem(Fraction(3,5), Fraction(2,5), '+');
    problems[2].setProblem(Fraction(4,7), Fraction(1,7), '+');
    problems[3].setProblem(Fraction(5,6), Fraction(1,3), '+');
    problems[4].setProblem(Fraction(2,9), Fraction(4,9), '+');

    cout << "===== Fraction Test =====\n\n";

    for (int i = 0; i < 5; i++) {
        cout << "Problem " << i + 1 << ": ";
        problems[i].displayProblem();
        problems[i].askUserForAnswer();
        cout << endl;
    }

    cout << "\n===== RESULTS =====\n\n";

    for (int i = 0; i < 5; i++) {
        problems[i].showResult();
        if (problems[i].getResult())
            score++;
    }

    cout << "Final Score: " << (score * 20) << "%\n";

    return 0;
}