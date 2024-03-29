#ifndef LIBROWMAJORR_H_INCLUDED
#define LIBROWMAJORR_H_INCLUDED
#include <iostream>
#include <vector>


enum Return_Codes
{
    SUCCESS,
    ERROR_RANGE
};

struct Coordinates
{
    int row;
    int col;
};


using namespace std;
 class RowMajorGrid
 {
     public:
         RowMajorGrid();
         RowMajorGrid(const RowMajorGrid& otherObj);
         RowMajorGrid(int intRows,int intCols);
         ~RowMajorGrid();

         ///Mutator methods
         void setRows(int intNumber);
         void setCols(int intNUmber);

         ///Accessor methods
         int getCols() const;
         int getRows() const;


         ///Operator overloading
         RowMajorGrid& operator=(const RowMajorGrid& objRHS);
         bool operator==(const RowMajorGrid& objRHS);
         bool operator!=(const RowMajorGrid& objRHS);
         char& operator()(int intRow,int intCol);
         char& operator[](int intIndex);
         friend ostream& operator<<(ostream& objLHS,const RowMajorGrid& objRHS);
         friend ostream& operator>>(ostream& objLHS,const RowMajorGrid& objRHS);

         static const int DEFAULT_ROWS=10;
         static const int DEFAULT_COLS=10;
         const char DEFAULT_CHAR='\0';
         static const int MAX_ROWS=500;
         static const int MAX_COLS=500;
         static const int MIN_ROWS=5;
         static const int MIN_COLS=6;



     private:
        void enforceRange(int intValue,int intRows,int intCols) const;
        void duplicate(const RowMajorGrid& objOther);
        void freeState();
        void setUp(int intRows,int intCols,char chDefault);
        vector<Coordinates>vCoord;
        int _rows;
        int _cols;
        char** data;


 };



#endif // LIBROWMAJORR_H_INCLUDED
