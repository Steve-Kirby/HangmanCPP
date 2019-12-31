#include <iostream>
#include <random>
#include <time.h>

using namespace std;
string words[6] = { "pig", "cat", "dog", "fish", "horse", "parrot"};

string GenerateWord();
vector<char> SeperateWord(string);


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
        
    generatedWord = wordList[randomWordIndex];

    cout << "Generated word : " + generatedWord << endl;


    return generatedWord;
}

vector<char> SeperateWord(string generatedWord) {
    vector<char> seperatedWord;
    
    for (char c : generatedWord) {
        seperatedWord.push_back(c);
        cout << c << endl;
    }
    
    return seperatedWord;
}