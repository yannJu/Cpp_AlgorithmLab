#include <iostream>
#include <cstring>
using namespace std;
#define StackSize 100

class Stack{
	private:
		char sarr[StackSize]; int top;
	public:
		Stack() {top = -1;}
		void reset() {top = -1;}
		void PUSH(char val){sarr[++top] = val;}
		char POP() {return sarr[top--];}
		bool StackEmpty(){return top == -1;}
		bool StackFull(){return top == StackSize - 1;}
		void DisplayStack();
};
void Stack::DisplayStack(){
	int sp; sp = top;
	while (sp != -1){cout << sarr[sp--] << " ";}
	cout << endl;
}; //Stack

int Check(Stack s,char exp[]);
bool Match(char tmp, char s);

int main(){
	Stack s;
	int c_Num;
	char exp[100];

	cin >> c_Num;
	while(c_Num--){
		cin >> exp;
		cout << Check(s,exp) << endl;
		s.reset();
	}
}

int Check(Stack s,char exp[]){
	
	char temp;
	for (int j = 0; j < strlen(exp); j++){
		if (exp[j] == '(' || exp[j] == '{' || exp[j] == '[') s.PUSH(exp[j]);
		else if (exp[j] == ')' || exp[j] == '}' || exp[j] == ']') {
			if (s.StackEmpty()) {
				return 0;
			}
			else {
				temp = s.POP();
				if (!Match(temp, exp[j])) return 0;
			}
		}
	}
	if (s.StackEmpty()) return 1;
	else return 0;
}

bool Match(char tmp, char s){
	if ((tmp == '(' && s == ')') || (tmp == '{' && s == '}') || (tmp == '[' && s == ']')) return true;
	else return false;
}
