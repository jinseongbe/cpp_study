#include <iostream>

using namespace std;

int main()
{
    int *ptr = nullptr;
    int **ptrptr = nullptr; // 이중 포인터,, 포인터의 포인터(원래 변수는 integer)
    
    int value = 5;
    
    ptr = &value;
    ptrptr = &ptr;
    
    cout << ptr << "\t" << *ptr << "\t" << &ptr << endl;
    cout << ptrptr << "\t" << *ptrptr << "\t" << &ptrptr << endl;
    cout << **ptrptr << endl; // == *(*ptrptr)
    
    cout << value   << " == " << *ptr   << endl; // *(dereference)는 그것이 가리키는 값이라고 생각하면 이해 잘됨
    cout << &value  << " == " << ptr    << endl;
    cout << &ptr    << " == " << ptrptr << endl;
    cout << *ptrptr << " == " << ptr    << endl;
    cout << **ptrptr<< " == " << value  << endl;
    cout << endl;
    
    int ***ptrptrptr, ****ptrptrptrptr;// 삼중 사중 포인터도 사용 가능하지만 거의 쓰지는 않음!
    
    // 이중포인터 사용하는 경우
    const int row = 3;
    const int col = 5;
    
    const int s2da[row][col] = //stack 2D array줄임말
    {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };
    
    int *r1 = new int [col] {1, 2, 3, 4, 5};
    int *r2 = new int [col] {6, 7, 8, 9, 10};
    int *r3 = new int [col] {11, 12, 13, 14, 15};
    
    int **rows = new int *[row] { r1, r2, r3};
    
    for(int r = 0; r < row; ++r)
    {
        for( int c = 0; c < col; ++c)
            cout << rows[r][c] << "\t";
        cout << endl;
    }
    
    delete[] r1;
    delete[] r2;
    delete[] r3;
    delete[] rows;
    
    cout << endl << endl << endl;
    
    
    
    int **matrix = new int *[row];
    
    for (int r(0); r < row; ++r)
    {
        matrix[r] = new int[col];
    }
    
    for (int r = 0; r < row; ++r)
    {
        for(int c = 0; c < col; ++c)
        {
            matrix[r][c] = s2da[r][c];
        }
    }
    
    for(int r = 0; r < row; ++r)
    {
        for( int c = 0; c < col; ++c)
        {
            cout << matrix[r][c] << "\t";
        }
        cout << endl;
    }

    for(int r = 0; r < row; ++r)
        delete[] matrix[r];
    delete[] matrix;
    
    cout << endl << endl << endl;
    
    
    
    int *matrix2 = new int [row*col];
    
    for(int r = 0; r < row; ++r)
        for(int c = 0; c < col; ++c)
            matrix2[c + col*r] = s2da[r][c];
    
    for(int r = 0; r < row; ++r)
    {
        for( int c = 0; c < col; ++c)
        {
            cout << matrix2[c + col*r] << "\t";
        }
        cout << endl;
    }

    delete[] matrix2;
    
    return 0;
}
