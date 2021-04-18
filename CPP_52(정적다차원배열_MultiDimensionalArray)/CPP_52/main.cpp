#include <iostream>

using namespace std;

int main()
{
    
    //2차원 array
    
    const int num_rows = 3;
    const int num_columns = 5;
    
    for(int row = 0; row < num_rows; ++row)
    {
        for(int col = 0; col < num_columns; ++col)
        {
            cout << '[' << row << ']' << '[' << col << ']' << '\t';
        }
        
        cout << endl;
    }
    cout << endl << endl;
    
    
    
    int array[num_rows][num_columns];   // row-major <-> column-major
    
    array[0][0] = 1;                    // 일일이 초기화 하는 방법
    array[0][1] = 2;
    
    int array1[num_rows][num_columns] = // cpp11 이후로는 등료를 빼도 정상적으로 사용 가능함!
    {
        {1, 2, 3, 4, 5},                // row 0
        {6, 7, 8, 9, 10},               // row 1
        {11, 12, 13, 14, 15}            // row 2
    };
    
    for(int row = 0; row < num_rows; ++row)
    {
        for(int col = 0; col < num_columns; ++col)
//            cout << array1[row][col] << '\t';
            cout << (long long)&array1[row][col] << '\t';
        cout << endl;
    }
    cout << endl << endl;

    
    
    int array2[num_rows][num_columns]
    {
        {1, 2, },                       // 빈칸은 0으로 자동으로 채워줌
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };
    
    for(int row = 0; row < num_rows; ++row)
    {
        for(int col = 0; col < num_columns; ++col)
            cout << array2[row][col] << '\t';
        cout << endl;
    }
    cout << endl << endl;

    
    
    int array3[][num_columns]   // row는 굳이 쓰지 않아도 되지만, column은 생략불가!!
    {
        {1, 2, },
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };
    
    for(int row = 0; row < num_rows; ++row)
    {
        for(int col = 0; col < num_columns; ++col)
            cout << array3[row][col] << '\t';
        cout << endl;
    }
    cout << endl << endl;

    
    
    int array4[num_rows][num_columns]{0}; // 한번에 0으로도 초기화 가능
    
    for(int row = 0; row < num_rows; ++row)
    {
        for(int col = 0; col < num_columns; ++col)
            cout << array4[row][col] << '\t';
        cout << endl;
    }
    cout << endl << endl;


    
    //3차원 이상 array! // 쓰는 방법은 동일: 뒤에서 더 자세히!
    int array3d[5][4][3];
    
    
    
    
    
    cout << endl << endl;
    return 0;
}
