#include "libRowMajorr.h"


 RowMajorGrid::RowMajorGrid()
 {

 }
 RowMajorGrid::RowMajorGrid(const RowMajorGrid& otherObj)
 {

 }
 RowMajorGrid::RowMajorGrid(int intRows,int intCols)
 {

 }

///Setting the number of rows
void  RowMajorGrid::setRows(int intNumber)
{
    _rows = intNumber;
}

///Setting the number of columns
void  RowMajorGrid::setCols(int intNumber)
{
    _cols = intNumber;
}

///Enforcing the strange
void RowMajorGrid::enforceRange(int intValue,int intMin,int intMax) const
{
    if(intValue < intMin)
    {
        exit(Return_Codes::ERROR_RANGE);
    }

    if(intValue > intMax)
    {
        exit(Return_Codes::ERROR_RANGE);
    }

}

///Dealloacating memory
void RowMajorGrid::freeState()
{
    for(int r = 0;r < _rows;r++)
    {
        delete[] data[r];
    }
    delete[] data;

}

///Initialising the array
void RowMajorGrid::setUp(int intRows,int intCols,char chDefault)
{
    enforceRange(intRows,MIN_ROWS,MAX_ROWS);
    enforceRange(intCols,MIN_COLS,MAX_COLS);

    setRows(intRows);
    setCols(intCols);


    data = new char*[_rows];

    for(int r = 0;r < _rows;r++)
    {
        data[r] = new char[_cols];
    }

}
