#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t_case, s, f, k;
    vector<int> start, finish;
    vector<pair<int, int> > result;

    cin >> t_case;
    while(t_case--){
        cin >> s >> f;
        start.push_back(s);
        finish.push_back(f);
    }

    result.push_back(make_pair(start[0], finish[0]));
    k = 0;
    for (int i = 1; i < start.size(); i++){
        if (finish[k] <= start[i]){
            result.push_back(make_pair(start[i], finish[i]));
            k = i;
        }
    }

     for (int i = 0; i < result.size(); i++){
         cout << " ( " << result[i].first << ", " << result[i].second << " ) , ";
    }
    cout << endl;
}