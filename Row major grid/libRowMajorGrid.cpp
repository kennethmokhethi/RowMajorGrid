#include "libRowMajorr.h"
#include <iostream>

 RowMajorGrid::RowMajorGrid():RowMajorGrid(DEFAULT_ROWS,DEFAULT_COLS)
 {

 }

 ///Copy constructor
 RowMajorGrid::RowMajorGrid(const RowMajorGrid& otherObj)
 {
    duplicate(otherObj);

 }

 ///
 RowMajorGrid::RowMajorGrid(int intRows,int intCols)
 {
    setUp(intRows,intCols,DEFAULT_CHAR);
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

///Return the number of columns
int RowMajorGrid::getCols() const
{
    return _cols;
}

///Return the number of rows
int RowMajorGrid::getRows() const
{
    return _rows;
}

///Check equality
RowMajorGrid& RowMajorGrid::operator==(const RowMajorGrid& objRHS)
{
    if(_rows != objRHS._rows) return false;
    if(_cols != objRHS.getCols()) return false;

    for(int r = 0;r < _rows;r++)
    {
        for(int c = 0;c < _cols;c++)
        {
            if(data[r][c] != objRHS.data[r][c]) return false;
        }
    }

    return true;

}


///Check inequality
RowMajorGrid& RowMajorGrid::operator!=(const RowMajorGrid& objRHS)
{

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
    vector<Coordinates>tempCoordinates;

    data = new char*[_rows];

    for(int r = 0;r < _rows;r++)
    {
        data[r] = new char[_cols];
        for(int c = 0;c < _cols;c++)
        {
            Coordinates recCord ={r,c};
            data[r][c]=chDefault;
            tempCoordinates.push_back(recCord);
        }

    }
    vCoord.push_back(tempCoordinates);

}


///Destructor
RowMajorGrid::~RowMajorGrid()
{
   freeState();

}
///Copy constructor
void RowMajorGrid::duplicate(const RowMajorGrid& objOther)
{
  freeState();
  setUp(objOther._rows,objOther._cols,DEFAULT_CHAR);

  for(int r = 0;r < objOther.getRows();r++)
  {
      for(int c = 0;c < objOther.getCols();c++)
      {
          data[r][c] = objOther.data[r][c];
      }
  }


}
