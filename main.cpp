#include <iostream>
#include <random>
#include <cstdlib>

using std::cout; using std::cin; using std::endl;

class Number
{
    int CorrectNumber;
    int YourNumber;
    int GuessCount = 0;
    bool the_same_numbers = false;
public:
    void setYourNumber(){
        system ("Color 9");
        cout << "\nEnter your number: "<<endl;
        cin >> YourNumber;
    };
    void setCorrectNumber()
    {
        std::random_device r;
        std::mt19937 mt(r());
        std::uniform_real_distribution<double> dist(0, 1000);
        CorrectNumber = dist(mt);
    };
    void compareNumbers()
    {
        system ("Color C");
        if (YourNumber > CorrectNumber) cout<< "Too high!\nTry again.\n";
        else if (YourNumber < CorrectNumber) cout<< "Too low!\nTry again.\n";
        else {
            system ("Color A");
            cout << "Congratulation! You have guessed the number after " <<GuessCount<< " tries."<<endl;
            the_same_numbers = true;
        }

    };

    Number () {
        setCorrectNumber();
        while (!(the_same_numbers))
        {
            setYourNumber();
            GuessCount++;
            compareNumbers();
        }

    };
};

void welcome ()
{
    system ("Color 1");
    cout << "Hi! Welcome in the game "
            "your goal is to guess the correct number as many times you need."
            "\nThe number range is from 0 to 1000."
            "\nEnjoy my program!" <<endl;
    system ("Color 9");
};

void goodbye ()
{
    system ("Color 1");
    cout << "\nThank you for using my program.\nPlease leave your feedback "
            "on my github in case you want to help me improve my programming "
            "skills:\n"
            "https://github.com/kamwro" <<endl;
    system ("Color 9");
};
int main() {
    welcome();
    Number();
    goodbye();
    return 0;
}
