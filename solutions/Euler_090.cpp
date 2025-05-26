#include <iostream>
#include <vector>

using namespace std;

bool check_90(vector <bool> &a, vector <bool> &b){
    bool ans = 1;
    ans = ans && ((a[0] && b[1]) || (a[1] && b[0]));
    ans = ans && ((a[0] && b[4]) || (a[4] && b[0]));
    ans = ans && ((a[0] && b[6]) || (a[6] && b[0]));
    ans = ans && ((a[8] && b[1]) || (a[1] && b[8]));
    ans = ans && ((a[6] && b[1]) || (a[1] && b[6]));
    ans = ans && ((a[2] && b[5]) || (a[5] && b[2]));
    ans = ans && ((a[3] && b[6]) || (a[6] && b[3]));
    ans = ans && ((a[4] && b[6]) || (a[6] && b[4]));//64 is equal to 49, cube-speaking
    return ans;
}

string next_cube_90(string initial){
    string answer = initial;
    int tmp = 0;
    while(answer[answer.size()-1-tmp]>='9'-tmp){
        tmp++;
        if(tmp==answer.size()){ cout<<tmp<<endl;return "";}
    }
    answer[answer.size()-1-tmp] += 1;
    for(int i = answer.size()-tmp;i<answer.size();i++){
        answer[i] = answer[i-1]+1;
    }
    return answer;
}

void fill_vector_90(vector <bool> &a, string sample){
    for(int i=0;i<a.size();i++){
        a[i]=0;
    }
    for(int i=0;i<sample.size();i++){
        if(sample[i]<='8'){a[sample[i]-'0'] = 1;}
        if(sample[i]=='9'){a[6] = 1;}
    }
    return;
}

void problem_90(){
    string first_cube = "012345", second_cube = next_cube_90(first_cube);
    int final_count = 0, total = 0;
    vector <bool> l1(9,0);
    vector <bool> l2(9,0);
    while(first_cube[0]=='0'){
        second_cube = next_cube_90(first_cube);
        fill_vector_90(l1,first_cube);
        while(second_cube[0]!='2'){
            fill_vector_90(l2,second_cube);
            if(check_90(l1,l2)){cout<<final_count<<" "<<total<<" | "<<first_cube<<" "<<second_cube<<endl;}
            final_count+=check_90(l1,l2);
            total++;
            second_cube = next_cube_90(second_cube);
        }
        first_cube = next_cube_90(first_cube);
    }
    cout<<"Final: "<<final_count<<"; Total: "<<total<<"."<<endl;
    return;
}

int main()
{
    problem_90();
    return 0;
}
