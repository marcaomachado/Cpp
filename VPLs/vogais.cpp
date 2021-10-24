#include <iostream>
using namespace std;

int main()
{
    string word;
    string vowels = "aeiou";
    int vowelsQuantity [5] = {0};
    cin >> word;
    int wordLength = word.size();
    //Escrevendo comentário para fazer testes Git.
    for (int i = 0; i < wordLength; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (word[i] == vowels[j])
            {
                vowelsQuantity[j]++;
                break;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if(vowelsQuantity[i] > 0)
            cout << vowels[i] << " " << vowelsQuantity[i] << endl;
    }
    return 0;
}
