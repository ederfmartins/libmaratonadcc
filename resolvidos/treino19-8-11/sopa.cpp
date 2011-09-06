#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
using namespace std;

bool comp(string& pattern, string &all){
	int j = 0;
	for (int i = 0; i < all.size(); i++){
		if (pattern[j] == all[i]){
			j++;
		}
		if (j == pattern.size()) return true;
	}
	return false;
}

int main()
{
	string s, t;
	
	while(cin >> s >> t){
		
		if (s.size() > t.size()){
			if (comp(t,s))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}else{
			if (s.size() < t.size()){
				if (comp(s,t))
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			}else{
				if (s == t)
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			}
		}
	}

	return 0;
}
