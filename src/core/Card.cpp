#include <iostream>
#include <stdlib.h>
#include <stdio.h>

struct Bank
{
    /* data */
    int card;
    const char* familly;
};


class Card
{
    private:
        static const int _NB_PLAYER {2};
        static const int _LIMIT = 8;
        // nombre de carte de la meme famille 52 carte
        static const int dataset[];
        // famille 52 carte
        static const char* familly[];
        Bank cardWhoHaveBeenAlreadydistibute[_LIMIT] {Bank {0,"hello"}};

        int *returnRandomIntArray(int* res, int start, int size_dt, int size_fm);
    public:
        void setBankArrayOfProvidedCard();
        bool haveBeenDistributed();
        int** Distribute();
        Card(/* args */);
        ~Card();
};
const int Card::dataset[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
const char* Card::familly[] = {"pique","trefle","coeur","carreau"};


int *Card::returnRandomIntArray(int* res, int start, int size_dt, int size_fm)
{
    srand(time(0));
    for (size_t i = 0; i < 2; i++)
    {
        /* code */
        res[i] = i == 0 ? rand() % 4 : rand() % 13;
        std::cout << res[i] << std::endl;
    }
    
    return res;
}

void Card::setBankArrayOfProvidedCard()
{
    std::cout << this->cardWhoHaveBeenAlreadydistibute[0].familly << std::endl;
}

bool Card::haveBeenDistributed()
{
    return false;
}

int** Card::Distribute ()
{
    int dt_length = sizeof(this->dataset)/sizeof(int);
    int fm_length = sizeof(this->familly)/sizeof(char);
    // static int cards[2][2] {{1,5}, {3,25}};
    static int cards[2][2];
    for (size_t i = 0; i < 2; i++)
    {
        /* code */
        int rd[2];
        int* card = this->returnRandomIntArray(
            rd,0,dt_length, fm_length
        );
        cards[0][0]=card[0];
        cards[i][1]=card[1];
    }
    
    return reinterpret_cast<int **>(cards);
}

Card::Card(/* args */)
{
    
    //std::cout << arr[0] << std::endl;
    //std::cout << arr[1] << std::endl;
    this->setBankArrayOfProvidedCard();
    int** arr = this->Distribute();
    std::cout << *((int*)arr + (1 * 2) + 1) << " ::: ress" << std::endl;
    //int* res = this->Distribute();
    //std::cout << res[1] << std::endl;
    std::cout << this->familly[0] << std::endl;
    std::cout << this->dataset[0] << std::endl;
}

Card::~Card()
{
    std::cout << "delete" << std::endl;
}

int main() {
    Card *card = new Card();

    delete card;
    return 0;
}
