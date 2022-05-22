#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "MathC.cpp"

struct Bank
{
    /* data */
    int card;
    const char* familly;
};


class Card: public MathC
{
    private:
        static const int _NB_PLAYER {2};
        static const int _LIMIT = 52;
        // nombre de carte de la meme famille 52 carte
        static const int dataset[];
        // famille 52 carte
        static const char* familly[];
        Bank cardWhoHaveBeenAlreadydistibute[_LIMIT] {Bank {0,"hello"}};
    public:
        void setBankArrayOfProvidedCard();
        bool haveBeenDistributed();
        Card(/* args */);
        ~Card();
};
const int Card::dataset[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
const char* Card::familly[] = {"pique","trefle","coeur","carreau"};



void Card::setBankArrayOfProvidedCard()
{
    std::cout << this->cardWhoHaveBeenAlreadydistibute[0].familly << std::endl;
}

bool Card::haveBeenDistributed()
{
    return false;
}


Card::Card(/* args */)
{
    
    int** arr = this->getArray2x2();
    int card = this->getArrayPosition(arr, 0, 0);

    int groupe_id = this->getArrayPosition(arr, 0, 1);
    std::cout << this->familly[groupe_id] << std::endl;

    cardWhoHaveBeenAlreadydistibute[0] = Bank { this->dataset[card],this->familly[groupe_id] };
    std::cout << cardWhoHaveBeenAlreadydistibute[0].card << std::endl;
    //std::cout << arr[0] << std::endl;
    //std::cout << arr[1] << std::endl;
    
    /*
    this->setBankArrayOfProvidedCard();
    int** arr = this->Distribute();
    std::cout << *((int*)arr + (0 * 2) + 0) << " == " << *((int*)arr + (1 * 2) + 0) << std::endl;
    std::cout << *((int*)arr + (0 * 2) + 1) << " == " << *((int*)arr + (1 * 2) + 1) << std::endl;
    //int* res = this->Distribute();
    //std::cout << res[1] << std::endl;
    std::cout << this->familly[0] << std::endl;
    std::cout << this->dataset[0] << std::endl;*/
}

Card::~Card()
{
    std::cout << "delete" << std::endl;
}
