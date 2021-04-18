#include <iostream>

using namespace std;

void printArray(const int array[], const int length);


int main()
{
    /*                      value(값)   index(array에 저장된 위치)
    3   5   2   1   4         1           3        //0번 위치의 3을 3번 위치의 1과 바꿔줌
    1   5   2   3   4         2           2        //1번 위치의 5를 2번 위치의 2와 바꿔줌
    1   2   5   3   4         3           3
    1   2   3   5   4         4           4
    1   2   3   4   5
    */
    
    const int length(5);

    int array[length] = { 3, 5, 2, 1, 4 };
    
    printArray(array, length);
    
    //swap
//    int ter = 0;
//    ter = array[0];
//    array[0] = array[1];
//    array[1] = ter;
//    printArray(array, length);
    

    static int terminal = -1;
    int index = 0;
    int ter = 0;
    
    for(int i = 0; i < length - 1; i++)
    {
        terminal = array[i];
        
        for(int j = i; j < length - 1; j++)
        {
            terminal = terminal < array[j+1] ? terminal : array[j+1];
        }
        
        for(int k = 0; k < length; k++)
        {
            if (terminal == array[k])
            {
                index = k;
                ter = array[i];
                array[i] = array[k];
                array[k] = ter;
            }
        }
        printArray(array, length);
    }

    cout << endl << endl;
    
    
    //강의 정답
    // swap
    //int temp = array[0];
    //array[0] = array[1];
    //array[1] = temp;
    //printArray(array, length);
    // 같은기능 : std::swap(...)
    int array2[length] = { 3, 5, 2, 1, 4 };
    printArray(array2, length);
    
    for(int startIndex = 0; startIndex < length -1; ++startIndex)
    {
        int smallestIndex = startIndex;
        
        for(int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
        {
            if(array2[smallestIndex] > array2[currentIndex])
            {
                smallestIndex = currentIndex;
            }
        }
        
        //swap
        int temp = array2[smallestIndex];
        array2[smallestIndex] = array[startIndex];
        array2[startIndex] = temp;
        
        printArray(array2, length);
    }
    
    
    return 0;
}




void printArray(const int array[], const int length)
{
    for (int index = 0; index < length; ++index)
    {
        cout << array[index] << "\t";
    }
    cout << endl;
}
