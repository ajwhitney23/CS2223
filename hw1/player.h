//h file for player

/*
zero - condition wins
A XOR B XOR C == 0 <-- win
function to xor numLeft(heart) numLeft(spade) numLeft(diamond)
need to figure out what to do based on result

*/

class player
{
private:
    board *b;

public:
    player(board *aBoard);
    virtual ~player();
    int makeMove(board *b);
};
