#include <iostream>
#include <fstream>  // file_stream
#include <string>
#include <cstdlib> // exit()
#include <sstream>

using namespace std;

int main()
{
    // writing
    if(true)
    {
        // 아스키 코드로 저장하면 너무 느림
        // 그래서 binary로 저장해야함!
        
//        ofstream ofs("my_first_file.txt");
        ofstream ofs("my_first_file.txt", ios::app);  // ios::app : 이미 존재할 경우에는 이어서 작업
//        , ios::binary
        //ofs.open("my_first_file.dat");
        
        if (!ofs)
        {
            cerr << "Couldn't open file " << endl;
            exit(1);
        }
        
        // 1. 아스키로 저장하는 방식(느림)
        /*
        ofs << "Line 1" << endl;
        ofs << "Line 2" << endl;
        */
        
        // 2. binary로 저장하는 방식(빠름)
        /*
         const unsigned num_data = 10;   // 데이터의 크기를 알고 있어야함!
        ofs.write((char*)&num_data, sizeof(num_data));

        for(int i = 0; i < num_data; ++i)
        {
            ofs.write((char*)&i, sizeof(i));
        }
        */
        
        // 3. 출력할 데이터를 문자열 하나에 담아서 저장하는 경우
        stringstream ss;
        ss << "Line 1" << endl;
        ss << "Line 2" << endl;
        string str = ss.str();

        unsigned str_length = str.size();
        ofs.write((char*)&str_length, sizeof(str_length));
        ofs.write(str.c_str(), str_length);

        
//        ofs.close();    // not necessary, 대부분의 경우 영역으로 나누어 코딩하기 떄문에 영역을 벗어나면 알아서 사라지므로 필수는 아님!
    }
    
    
    // reading
    if(true)
    {
        ifstream ifs("my_first_file.txt");
        
        if(!ifs)
        {
            cerr << "Cannot open file" << endl;
            exit(1);
        }
        
        // 1.아스키 코드를 읽는 방식
        /*
        while(ifs)
        {
            std::string str;
            getline(ifs, str);

            std::cout << str << endl;
        }
        */
        
        // 2.바이너리 파일 읽는 방식(바이너리 방식의 경우 파일을 열어봤을때 우리가 내용을 알 수 없음)
        /*
        unsigned num_data = 0;
        ifs.read((char*)&num_data, sizeof(num_data));
        
        for (unsigned i = 0; i < num_data; ++i)
        {
            int num;
            ifs.read((char*)&num, sizeof(num));
            
            std::cout << num << std::endl;
        }
        */
        
        // 3. 출력할 데이터를 문자열 하나에 담아서 저장한것을 읽는 방식
        unsigned str_len = 0;
        ifs.read((char*)&str_len, sizeof(str_len));
        
        string str;
        str.resize(str_len);
        ifs.read(&str[0], str_len);
        
        cout << str << endl;
        
        // ifs.close(); // not necessary
    }
    
    
    
    return 0;
}
