#include <iostream>

using namespace std;

void printArr(char* arr[], int m, int n) {
	for(int i = 0; i < m + 2; i++) {
		for(int j = 0; j < n + 2; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int convert(string s) {
    int sm = 0, sc;
    if(s[0] == '-') {
    	for(int i = 1; s[i] != '\0'; i++) {
        	sc = int(s[i]) - 48;
        	sm = sm * 10 + sc;
    	}
    	return -sm;
	}
    
    for(int i = 0; s[i] != '\0'; i++) {
        sc = int(s[i]) - 48;
        sm = sm * 10 + sc;
    }
    return sm;
}

int number_in_string(string s, int n) {
	string number;
	n--;
	int index = 0, count = 0, num;
	for(int i = 0;; i++) {
		if( count == n ) {
			break;
		}
		if( s[i] == ' ' ) {
			count++;
		}
		index++;
	}
	for(int i = index; s[i] != ' '; i++) {
		number += s[i];
	}
	num = convert(number);
	return num;
}
