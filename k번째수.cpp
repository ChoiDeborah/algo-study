/*
*   2021.01.25
*   [Programmers] K번째 수 
*   https://programmers.co.kr/learn/courses/30/lessons/42748
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const int& a, const int& b)
{
    return a < b;
}

int parse(const int& i, const int&  j, const int& k, vector<int>& array)
{
        vector<int> answer;

        for(int index = 0; index < array.size(); ++index)
        {
            if((i <= index+1) && (index+1 <= j))
                answer.push_back(array[index]);
        }

        sort(answer.begin(), answer.end(), compare);

        for(int index = 0; index < answer.size(); ++index)
        {
            if(k <= index+1)
                return answer[index];
        }
        cout << endl;
        
        return 0;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int x = 0; x < commands.size(); ++x)
    {
        int i, j, k = 0;

        const vector<int>& temp = commands[x];
        for(int y = 0; y < temp.size(); ++y)
        {
            const int value = temp[y];
            if(0 == y)
                i = value;
            else if (1 == y)
                j = value;
            else if(2 == y)
                k = value;
        }

        answer.push_back(parse(i, j, k, array));
    }
    return answer;
}

int main(void)
{
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    solution(array, commands);

    return 0;
}