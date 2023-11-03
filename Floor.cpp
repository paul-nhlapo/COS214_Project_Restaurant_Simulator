#include "Floor.h"
#include <string>
#include <vector>
using namespace std;

Floor::Floor(int numRows, int numCols)
{
    if ((numRows > 0 && numCols > 0) && (numRows < 10 && numCols < 10))
    {
        tables = new Table *[numRows];
        for (int i = 0; i < numRows; i++)
        {
            tables[i] = new Table[numCols];
        }
        this->numRows = numRows;
        this->numCols = numCols;

        int ids = 0;
        for (int x = 0; x < numRows; x++)
        {
            for (int y = 0; y < numCols; y++)
            {
                tables[x][y].tableID = ids;
                ids++;
            }
        }
    }
    else
    {
        cout << "Invalid Parameters" << endl;
    }
}

Floor::~Floor()
{
    for (int i = 0; i < numRows; i++)
    {
        delete[] tables[i];
    }
    delete[] tables;
}

Table *Floor::getTable(int row, int col)
{
    if (row >= 0 && col >= 0)
    {
        return &tables[row][col];
    }
    else
    {
        cout << "Invalid Parameters" << endl;
        return nullptr;
    }
}

void Floor::printFloor()
{
    for (int i = 0; i < this->numRows; i++)
    {
        for (int j = 0; j < this->numCols; j++)
        {
            if (!tables[i][j].hasCustomer)
            {
                cout << "|" << tables[i][j].tableID << "| ";
            }
            else
            {
                cout << "|" << tables[i][j].tableID << "[C]| ";
            }
        }
        cout << endl;
    }
}