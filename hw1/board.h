#define HEA 0
#define DIA 1
#define SPA 2
class board
{
private:
    int numOf[3];

public:
    board();
    virtual ~board();
    void printBoard();
    int alterBoard(int type, int num); //0 for fail alter, 1 for alter pass
};

/*

    /x\     //4 spaces
   /x|x\    //3 spaces
  /+|+|+\   //2 spaces
 /+|+|+|+\  //1 space
/o|o|o|o|o\ //0 spaces

*/
