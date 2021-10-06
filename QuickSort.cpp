/*
Quick Sort 알고리즘 (by Hoare and Lomuto)
Quick Sort 알고리즘은 1959 년에 영국의 Tony Hoare 에 의하여 개발되었으며, 1961 년에 발표되
었다. 이 알고리즘은 현재에도 가장 많이 사용되는 정렬 알고리즘이다. Quick Sort 는 효율적으로 구
현이 된다면, Merge Sort 보다는 상당히 빠르며, Heapsort 보다는 2~3 배 빠른 것으로 알려져 있다.
Quick Sort 알고리즘이 Merge Sort 보다 빠른 이유 중의 하나는, 정렬과정에서 데이터를 이동시키
는 회수가 Quick Sort 알고리즘이 훨씬 적기 때문이다. 본 문제에서는 Quick Sort 알고리즘 수행 과
정에서 실행되는 데이터 이동의 횟수를 구해 보고자 한다. 또한 Quick Sort 알고리즘의 점근적 분석
(asymptotic analysis)에 사용되는 비교 연산자의 실행 횟수도 구해 보고자 한다.
Quick Sort 알고리즘은 Divide-and-Conquer 전략 알고리즘으로서, 다음과 같은 과정으로 실행된
다.
(1) Divide
A. Pivot 선택 : 정렬하고자 하는 배열의 가장 왼쪽 (가장 낮은 인덱스를 가지는) 원소를
pivot 으로 선택한다. (참고로 pivot 을 선택하는 방법은 여러가지 있지만, 본 문제에서
는 가장 왼쪽 원소를 선택하는 방법을 사용한다.)
B. Pivot 을 제외한 나머지 배열의 원소를 pivot 보다 작은 (혹은 작거나 같은) 원소들의
그룹과 pivot 보다 큰 (혹은 크거나 같은) 원소들의 그룹으로 나눈다.
(*) Quick Sort 알고리즘에서의 divide 과정을 특별히 partition 이라고 부른다.
(2) Conquer
A. Partition 과정에서 나누어진 두 개의 원소들의 그룹에 대하여 재귀적(recursion)으로
Quick Sort 알고리즘을 수행한다.
Quick Sort 의 partion 과정에는 여러가지 방법이 있으나, 대표적으로 Tony Hoare 와 Nico Lomuto
가 개발한 partition 을 많이 사용한다.
Tony Hoare 가 개발한 Hoare Partition 을 이용한 Quick Sort 알고리즘의 pseudo code 는 다음과
같다

주어진 정수를 정렬하는 Quick Sort 알고리즘을 Hoare Partition 과 Lomuto Partition 을 이용하여
구현하고, 각 partition 방법을 사용할 떄의 swap 연산과 비교 연산자의 실행 횟수를 구하는 프로그
램을 구현하시오. 단, 위에서 제시된 pseudo-code 와 논리적으로 동일하게 구현하여야 한다. Hoare
Partition 에서의 swap 연산은 pseudo-code 의 line 16 에 나타나며, 비교 연산자는 line 13, 14 에
나타난다. 또한 Lomuto Partition 에서의 swap 연산은 pseudo-code 의 line 14, 16 에 나타나며, 비
교 연산자는 line 12 에 나타난다.
*/

#include <iostream>
#include <vector>
using namespace std;

struct ANSWER{
    int swap;
    int compare;
};

void QUICKSORT(vector<int> *, int, int, int, ANSWER *);
int TONY_QUICKSORT(vector<int> *, int, int, ANSWER *);
int NICO_QUICKSORT(vector<int>* , int, int, ANSWER *);

int main(){
    int t, len;
    vector<int>  tony_ary, nico_ary;
    ANSWER tony, nico;

    cin >> t;
    while(t--){
        cin >> len;
        for (int i = 0; i < len; i++) {
            int tmp;
            cin >> tmp;
            tony_ary.push_back(tmp);
            nico_ary.push_back(tmp);
        }
        tony.compare = 0; tony.swap = 0;
        nico.compare = 0; nico.swap = 0;

        QUICKSORT(&tony_ary, 0, tony_ary.size() - 1, 1, &tony);
        QUICKSORT(&nico_ary, 0, nico_ary.size() - 1,- 1,&nico);

        cout << tony.swap << " "  << nico.swap << " " << tony.compare << " " << nico.compare << endl;
        tony_ary.clear();
        nico_ary.clear();
    }
    return 0;
}

void QUICKSORT(vector<int> *v, int low, int high, int flag, ANSWER *answer){
    int mid;

    if (low >= high) return;
    if (flag > 0){
        mid = TONY_QUICKSORT(v, low, high, answer);
        //cout << " TONY MID : " << high<< endl;
        QUICKSORT(v, low, mid, 1, answer);
        QUICKSORT(v, mid + 1, high, 1, answer);
    }
    else {
        mid = NICO_QUICKSORT(v, low, high, answer);
        //cout << " NICO MID : " << mid << endl;
        QUICKSORT(v, low, mid - 1, -1, answer);
        QUICKSORT(v, mid + 1, high, -1, answer);
    } 
}

 int TONY_QUICKSORT(vector<int> *v, int low, int high, ANSWER *tony){
     int pivot = v->at(low);
     int tmp,  i = low - 1, j = high + 1;

    while(true){
        do{
            i += 1;
            tony->compare += 1;
        } while(v->at(i) < pivot);
        do{
            j -= 1;
            tony->compare += 1;
        } while(v->at(j) >pivot);

        if (i < j) {
            tmp = v->at(i);
            v->at(i) = v->at(j);
            v->at(j) = tmp;
            tony->swap += 1;
        }
        else return j;
    }
}
 int NICO_QUICKSORT(vector<int> *v, int low, int high, ANSWER *nico){
     int pivot = v->at(low);
     int tmp, j = low;

     for (int i  = low + 1; i <= high; i++){
        nico->compare += 1;
         if (v->at(i) < pivot) {
             j += 1;
            tmp = v->at(i);
            v->at(i) = v->at(j);
            v->at(j) = tmp;
            nico->swap += 1;
         }
     }
     nico->swap += 1;
     tmp = v->at(j);
     v->at(j) = v->at(low);
     v->at(low) = tmp;

     return j;
 }