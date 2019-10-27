#define HEA 0
#define DIA 1
#define SPA 2
/*
solid symbols
*/
#define SYM_HEA "\u2665"
#define SYM_DIA "\u2666"
#define SYM_SPA "\u2660"
/*
inverse symbols
*/
#define SYM_HEA_f "\u2661"
#define SYM_DIA_f "\u2662"
#define SYM_SPA_f "\u2664"

class board
{
private:
    int numOf[3];

public:
    board();
    virtual ~board();
    void printBoard();
    int alterBoard(int type, int num); //0 for fail alter, 1 for alter pass
    int numLeft(int type); //need to code
};

/*

    /x\     //4 spaces
   /x|x\    //3 spaces
  /+|+|+\   //2 spaces
 /+|+|+|+\  //1 space
/o|o|o|o|o\ //0 spaces

*/
