#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <iostream>

class MathC
{
    private:
        /* data */
    public:
        int getRandom(int start, int end);
        int** getArray2x2();
        int getArrayPosition(int** cards, int arrayCase, int target);
        MathC(/* args */);
        ~MathC();
};

int MathC::getRandom(int start, int end)
{
    std::random_device r;
 
    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(start, end);
    int mean = uniform_dist(e1);

    return mean;
}

int** MathC::getArray2x2()
{
    static int arr[2][2];

    for (size_t i = 0; i < 4; i++)
    {
        /* code */
        arr[i%2][0] = this->getRandom(0,12);
        arr[i%2][1] = this->getRandom(0,3);
    }
    
    return reinterpret_cast<int **>(arr);
}

int MathC::getArrayPosition(int** cards, int arrayCase, int target)
{
    return *((int*)cards + (arrayCase * 2) + target);
}

MathC::MathC(/* args */)
{
}

MathC::~MathC()
{
}