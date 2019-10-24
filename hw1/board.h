
class board {
    public:
    int num = 0;
    int maxNum = 15;

    board();
    virtual ~board();
    void printBoard();
};

/*

    /x\     //4 spaces
   /x|x\    //3 spaces
  /+|+|+\   //2 spaces
 /+|+|+|+\  //1 space
/o|o|o|o|o\ //0 spaces

*/
