#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit()
#include <sstream>

using namespace std;

int main()
{
    const string filename = "my_file.txt";
    
    // make a file
    {
        ofstream ofs(filename);
        
        for (char i = 'a'; i <= 'z'; ++i)
        {
            ofs << i;
        }
        ofs << endl;
    }
    
    // read the file
    {
        ifstream ifs(filename);
        
        // seekg : file 처음부터 5바이트 이동한 다음에 읽어라
        ifs.seekg(5);   //ifs.seekg(5, ios::beg);
        cout << (char)ifs.get() << endl;
        
        // 현재 읽었던 위치(커서위치)에서 부터 5바이트 이동해서 읽어라
        ifs.seekg(5, ios::cur);
        cout << (char)ifs.get() << endl;
        
//        ifs.seekg(-5, ios::end);  // end로 부터 5바이트
        
//        ifs.seekg(0, ios::end);
//        cout << ifs.tellg() << endl;

        string str;
        getline(ifs, str);
        
        cout << str << endl;
    }
    
    // file을 한번 열어서 읽기도하고 쓰기도 하는 방법
    {
        //fstream iofs(filename, ios::in | ios::out);
        fstream iofs(filename);
        
        iofs.seekg(5);
        cout << (char)iofs.get() << endl; //read
        
        iofs.seekg(5);
        iofs.put('A'); // write
        
    }
    
    return 0;
}
