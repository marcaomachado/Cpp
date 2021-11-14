#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

//using namespace std;
std::vector<int> randomVector(int n, int upperBound);
void printVector(std::vector<int> const& vec);

int main()
{
    int numValues = 10000;
    int upperBound = 11;
    std::vector<int> vector = randomVector(numValues, upperBound);
    printVector(vector);
}

std::vector<int> randomVector(int n, int upperBound)
{
    std::vector<int> vec(n);
    srand((unsigned int)time(NULL));
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = rand() % upperBound;
    }
    return vec;
}

void printVector(std::vector<int> const& vec)
{
    double sum = 0;
    for(int i : vec){
        sum += i;
    }
    std::cout << sum/vec.size() << std::endl;
}