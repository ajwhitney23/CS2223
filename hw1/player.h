//h file for player

/*
zero - condition wins
A XOR B XOR C == 0 <-- win
function to xor numLeft(heart) numLeft(spade) numLeft(diamond)
need to figure out what to do based on result

*/

class player
{
public:
    player();
    virtual ~player();
    int makeMove(board *b);
};
