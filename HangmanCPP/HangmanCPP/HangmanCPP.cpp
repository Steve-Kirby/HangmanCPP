#include <iostream>
#include <random>
#include <time.h>

using namespace std;
string words[9] = { "pig", "cat", "dog", "fish", "horse", "parrot", "laptop", "water", "football"};


string GenerateWord();
vector<char> SeperateWord(string);
vector<char> HideWord(vector<char>);
void UserGuess(char);

vector<char> hiddenWord;
vector<char> seperatedWord;
string generatedWord;

bool gamewon = false;
int lives = 5;

int main()
{

    cout << "Welcome to Hangman, written in C++" << endl; 
    srand(time(NULL));
    generatedWord = GenerateWord();
    seperatedWord = SeperateWord(generatedWord);

    cout << "Guess this word!" << endl;
    hiddenWord = HideWord(seperatedWord);

    char userguess;

    while (!gamewon) {
        cin >> userguess;
        
        UserGuess(userguess);
        
        for (char c : hiddenWord) {
            cout << c;
            cout << " ";
        }

        cout << endl << endl;
    }

    cout << "You Won!" << endl;
   
   
}

string GenerateWord() {
    string generatedWord;

    vector<string> wordList(words, words + sizeof(words) / sizeof(string));
 
    int randomWordIndex = rand() % (int)(wordList.size());
        
    generatedWord = wordList[randomWordIndex];

    return generatedWord;
}

vector<char> SeperateWord(string generatedWord) {
    vector<char> seperatedWord;
    
    for (char c : generatedWord) {
        seperatedWord.push_back(c);
    }
        
    return seperatedWord;
}

vector<char> HideWord(vector<char> seperatedWord) {
    vector<char> hiddenWord;
    for (char c : seperatedWord) {
        hiddenWord.push_back('_');
        cout << "_ ";
    }
    cout << endl;
    return hiddenWord;
}

void UserGuess(char userGuess)
{

    bool guessSuccessful = false;
    gamewon = true;
    for (int i = 0; i < seperatedWord.size(); i++) {
        if (seperatedWord[i] == userGuess) {
            hiddenWord[i] = userGuess;
            guessSuccessful = true;
        }

        if (hiddenWord[i] == '_') {
            gamewon = false;
        }
    }

    if (guessSuccessful == false) {
        printf("\nLives Left %d\n", --lives);
        if (lives < 1) {
            cout << "You Lose!" << endl;
            cout << "The word was.... " << generatedWord << endl;
            exit(1);
            
        }
    }
        


}
