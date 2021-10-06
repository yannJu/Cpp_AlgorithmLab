/*
Quick Sort �˰��� (by Hoare and Lomuto)
Quick Sort �˰����� 1959 �⿡ ������ Tony Hoare �� ���Ͽ� ���ߵǾ�����, 1961 �⿡ ��ǥ��
����. �� �˰����� ���翡�� ���� ���� ���Ǵ� ���� �˰����̴�. Quick Sort �� ȿ�������� ��
���� �ȴٸ�, Merge Sort ���ٴ� ����� ������, Heapsort ���ٴ� 2~3 �� ���� ������ �˷��� �ִ�.
Quick Sort �˰����� Merge Sort ���� ���� ���� ���� �ϳ���, ���İ������� �����͸� �̵���Ű
�� ȸ���� Quick Sort �˰����� �ξ� ���� �����̴�. �� ���������� Quick Sort �˰��� ���� ��
������ ����Ǵ� ������ �̵��� Ƚ���� ���� ������ �Ѵ�. ���� Quick Sort �˰����� ������ �м�
(asymptotic analysis)�� ���Ǵ� �� �������� ���� Ƚ���� ���� ������ �Ѵ�.
Quick Sort �˰����� Divide-and-Conquer ���� �˰������μ�, ������ ���� �������� �����
��.
(1) Divide
A. Pivot ���� : �����ϰ��� �ϴ� �迭�� ���� ���� (���� ���� �ε����� ������) ���Ҹ�
pivot ���� �����Ѵ�. (����� pivot �� �����ϴ� ����� �������� ������, �� ��������
�� ���� ���� ���Ҹ� �����ϴ� ����� ����Ѵ�.)
B. Pivot �� ������ ������ �迭�� ���Ҹ� pivot ���� ���� (Ȥ�� �۰ų� ����) ���ҵ���
�׷�� pivot ���� ū (Ȥ�� ũ�ų� ����) ���ҵ��� �׷����� ������.
(*) Quick Sort �˰��򿡼��� divide ������ Ư���� partition �̶�� �θ���.
(2) Conquer
A. Partition �������� �������� �� ���� ���ҵ��� �׷쿡 ���Ͽ� �����(recursion)����
Quick Sort �˰����� �����Ѵ�.
Quick Sort �� partion �������� �������� ����� ������, ��ǥ������ Tony Hoare �� Nico Lomuto
�� ������ partition �� ���� ����Ѵ�.
Tony Hoare �� ������ Hoare Partition �� �̿��� Quick Sort �˰����� pseudo code �� ������
����

�־��� ������ �����ϴ� Quick Sort �˰����� Hoare Partition �� Lomuto Partition �� �̿��Ͽ�
�����ϰ�, �� partition ����� ����� ���� swap ����� �� �������� ���� Ƚ���� ���ϴ� ���α�
���� �����Ͻÿ�. ��, ������ ���õ� pseudo-code �� �������� �����ϰ� �����Ͽ��� �Ѵ�. Hoare
Partition ������ swap ������ pseudo-code �� line 16 �� ��Ÿ����, �� �����ڴ� line 13, 14 ��
��Ÿ����. ���� Lomuto Partition ������ swap ������ pseudo-code �� line 14, 16 �� ��Ÿ����, ��
�� �����ڴ� line 12 �� ��Ÿ����.
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