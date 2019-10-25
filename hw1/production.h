
class production
{
private:
    int turn = 0;

public:
    void gameStart();
    void printValidMoves();
    //will probably want helper functions for botMove

    production();
    virtual ~production();
};