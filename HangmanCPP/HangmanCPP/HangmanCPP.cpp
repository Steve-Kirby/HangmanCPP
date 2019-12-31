#include <iostream>
#include <random>
#include <time.h>

using namespace std;
string words[6] = { "pig", "cat", "dog", "fish", "horse", "parrot"};

string GenerateWord();
vector<char> SeperateWord(char*);


int main()
{
    cout << "Welcome to Hangman, written in C++\n";
    srand(time(NULL));
    SeperateWord(GenerateWord());
}

string GenerateWord() {
    string generatedWord;

    vector<string> wordList(words, words + sizeof(words) / sizeof(string));
 
    int randomWordIndex = rand() % (int)(wordList.size());
    
    cout << "Generated word : " + wordList[randomWordIndex];


    return generatedWord;
}

vector<char> SeperateWord(string generatedWord) {
    vector<char> seperatedWord;
    for (int i = 0; i < generatedWord.length(); i++) {
        seperatedWord.push_back(generatedWord[i]);
        cout << generatedWord[i];
    }

    

    return seperatedWord;
}