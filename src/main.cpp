#include <iostream>
#include "core/Card.cpp"

int main (void)
{
    Card *card = new Card();

    delete card;
    return 0;
}