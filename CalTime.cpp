#include <iostream>
using namespace std;

int main(){
	int c_num, m_num;
	int i, j;
	int h1, m1, s1, h2, m2, s2;
	int day, hour, minute, second;
	for(cin >> c_num, i = 0; i < c_num; i++){
		day = 0, hour = 0, minute = 0, second = 0;
		for (cin >> m_num, j = 0; j < m_num; j++){
			cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
			if (s1 > s2){
				m2 -= 1;
				s2 += 60;
			}
			if (m1 > m2){
				h2 -= 1;
				m2 += 60;
			}
			hour += (h2 - h1);
			minute += (m2 - m1);
			second += (s2 - s1);
			}
		while(second >= 60){
			minute += 1;
			second -= 60;
		}
		while(minute >= 60){
			hour += 1;
			minute -= 60;
		}
		while(hour >= 24){
			day += 1;
			hour -= 24;
		}
		cout << day << " " << hour << " " << minute << " " << second << endl;
	}
	return 0;
}
