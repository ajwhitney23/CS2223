//h file for bot

/*
zero - condition wins
A XOR B XOR C == 0 <-- win
function to xor numLeft(heart) numLeft(spade) numLeft(diamond)
need to figure out what to do based on result

*/

class bot
{
private:
    board *b;

public:
    bot(board *aBoard);
    virtual ~bot();
    int makeMove(board *b);
    int hasWinning(board *aBoard);
    int randomFromBoard(board *b);
};
