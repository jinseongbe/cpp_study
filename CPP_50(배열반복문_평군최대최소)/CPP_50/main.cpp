#include <iostream>
#include <limits>

using namespace std;

int main()
{
//    const int num_students(5);
//    int scores[num_students] = {84, 92, 76, 81, 56};

    int scores[] = {84, 92, 76, 81, 56};
    const int num_students = sizeof(scores) / sizeof(int); // 이런방식으로도 배열의 크기를 계산가능!
                                                           // 파라머티러 넘어간 array는 4 or 8byte 주의!!
                                                           // 포인터주소가 넘어간거랑 실제 배열인지 구별!!!
    
    int total_score = 0;
    for(int i = 0; i < num_students; i++)
    {
        total_score += scores[i];
    }
    double avg_score = static_cast<double>(total_score) / num_students;
    cout << avg_score << endl << endl;
    
    
    int max_score(0);
    for(int i = 0; i < num_students; i++)
    {
        max_score = (max_score < scores[i] ? scores[i] : max_score);
    }
    cout << max_score << endl << endl;

    
    int min_score = numeric_limits<int>::max();
    
    for(int i = 0; i < num_students; i++)
    {
        min_score = (min_score > scores[i] ? scores[i] : min_score);
    }
    cout << min_score << endl << endl;
    
    
    return 0;
}
