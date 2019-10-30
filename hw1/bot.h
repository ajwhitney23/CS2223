//h file for bot

/*
zero - condition wins
A XOR B XOR C == 0 <-- win
function to xor numLeft(heart) numLeft(spade) numLeft(diamond)
need to figure out what to do based on result

*/

class bot
{
public:
    bot();
    virtual ~bot();
    int makeMove(board *b);
    int hasWinning(board *b);
    int randomFromBoard(board *b);
};
