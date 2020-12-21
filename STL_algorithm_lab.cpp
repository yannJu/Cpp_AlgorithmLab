#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include "STL_Team.h"
using namespace std;

template <class T>
void print_container(const T& container, string s = ""){
    cout << s << "(" << container.size() << ")";
    auto it = container.begin();
    for (; it != container.end(); it++) cout << *it << " ";
    cout << endl;
}

bool teamCmp_byName (const Team& a, const Team& b) {
    return a.name < b.name;
}

struct TeamCmp_byVictory{
    bool operator() (const Team& a, const Team& b){
        return a.victory < b.victory;
    }
};

int main(){
    Team t[] = {Team("Bulls", 7), Team("Warriors", 5), Team("Spurs", 2)};
    vector<Team> v(&t[0], &t[3]);
    print_container(v, "1. v = ");
    sort(v.begin(), v.end(), teamCmp_byName);
    print_container(v, "2. v = ");
    sort(v.begin(), v.end(), TeamCmp_byVictory());
    print_container(v, "3. v = ");
    auto it_v = v.begin();
    it_v = v.insert(it_v, Team("Lakers", 3));
    print_container(v, "4. v = ");

    set<Team, TeamCmp_byVictory> s(&t[0], &t[3]);
    print_container(s, "1. s = ");
    s.insert(Team("Lakers", 3));
    print_container(s, "2. s = ");

    priority_queue<Team, vector<Team>, TeamCmp_byVictory> p(&t[0], &t[3]);
    p.push(Team("Lakers", 3));
    cout << "priority queue : ";
    while (!p.empty()){
        cout << p.top().name << "(" << p.top().victory << ") ";
        p.pop();
    }
    cout << endl;
}