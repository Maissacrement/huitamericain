#include <iostream>
#include <stdlib.h>

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

        int *returnRandomIntArray(int start, int end);
    public:
        void setBankArrayOfProvidedCard();
        bool haveBeenDistributed();
        int* Distribute();
        Card(/* args */);
        ~Card();
};
const int Card::dataset[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
const char* Card::familly[] = {"pique","trefle","coeur","carreau"};

int *Card::returnRandomIntArray(int start, int end)
{
    int a = rand() % end + start;
    int b = rand() % end + start;
    std::cout << a << " " << b << std::endl;
    
    static int res[] = {a, b};
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

int *Card::Distribute ()
{
    static int test[] = {5,3};
    return test;
}

Card::Card(/* args */)
{
    std::cout << this->returnRandomIntArray(5,16)[0] << std::endl;
    this->setBankArrayOfProvidedCard();
    int* res = this->Distribute();
    std::cout << res[1] << std::endl;
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
