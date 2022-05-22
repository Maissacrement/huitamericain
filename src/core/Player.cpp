#include <iostream>

class Player
{
    private:
        /* data */
    public:
        Player(/* args */);
        ~Player();
};

Player::Player(/* args */)
{
    std::cout << "hello" << std::endl;
}

Player::~Player()
{
    std::cout << "Player has killed" << std::endl;
}

int main(void) {
    Player* p1 = new Player();

    delete p1;
    return 0;
}

