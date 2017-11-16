
#include <iostream>
#include <cassert>
#include <string>
#include <stack>


using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL){}
};


class Solution{

public:
	bool isValid(string s){
		//栈:先进后出
		stack<char> stack;
		
		for(int i =0 ; i<s.size() ; i++){
			
			if(s[i] == '(' || s[i] == '{' || s[i] == '['){
				stack.push( s[i] );
			}else{
				
				if(stack.size() == 0){
					return false;
				}
				char c = stack.top();
				
				stack.pop();
				
				char match;
				if(s[i] == ')'){
					match = '(';
				}else if(s[i] == ']'){
					match = '[';
				}else{ //s[i] == '}'
					assert( s[i] == '}' );
					match = '{';		
				}
				
				if(c != match){
					return false;
				}
				
			}
			
		}
		
		if(stack.size() != 0){
			return false;
		}
		
		return true;		
	}
};

int main(){
	
	return 0;
}

