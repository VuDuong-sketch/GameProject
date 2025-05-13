#include <iostream>
#include <vector>

using namespace std;

const int K = 100;

int char_to_int( char c ) {
	return int(c) - 48;
}

char int_to_char( int n ) {
	return char(n + 48);
}

int string_to_int (string s) {
    int sm = 0, sc;
    
    for(int i = ( s[0] == '-' ? 1 : 0 ); s[i] != '\0'; i++) {
        sc = char_to_int(s[i]);
        sm = sm * 10 + sc;
    }
    if( s[0] == '-' ) sm *= -1;
    return sm;
}

string reverse(string& s) {
	int len = s.length();
	for(int i = 0; i < len / 2; i++) {
		swap(s[i], s[len - 1 - i]);
	}
	return s;
}

string int_to_string(int n) {
	string s;
	bool flag = false;
	if( n == 0 ) return "0";
	if( n < 0 ) {
		flag = true;
		n *= -1;
	}
	while( n != 0 ) {
		s += int_to_char(n % 10);
		n /= 10;
	}
	if( flag ) s += '-';
	reverse(s);
	return s;
}

vector<int> string_to_vector ( string s ) {
	vector<int> v;
	if( s == "" ) return v;
	string num;
	for(int i = 0; s[i] != '\0'; i++) {
		if( s[i] == ' ' ) {
			int val = string_to_int( num );
			v.push_back(val);
			num = "";
			continue;
		}
		num += s[i];
	}
	v.push_back(string_to_int( num ));
	return v;
}

int number_in_string ( string s, int k) {
	int index = --k;
	vector<int> v = string_to_vector(s);
	if( index < v.size() ) return v[index];
	return -1;
}

bool Click ( int i, int j, int x, int y ) {
	int x1 = (j - 1) * K,
		y1 = (i - 1) * K,
		x2 = j * K - 1,
		y2 = i * K - 1;
		
	return ( x1 <= x && x <= x2 && y1 <= y && y <= y2 );
}

void Delete_Dynamic_Array(int** ptr) {
	for(int i = 0; i < 8; i++) {
		delete[] ptr[i];
	}
	delete[] ptr;
}



char* string_to_CharPointer (const string& s) {
	char* ptr = new char[s.length() + 1];
	for(int i = 0; s[i] != '\0'; i++) {
		ptr[i] = s[i];
	}
	ptr[s.length()] = '\0';
	return ptr;
}

int coor_convert_x (int x, int j) {
	
	return K * (j - 1) + x - 1;
	
}

int coor_convert_y (int y, int i) {
	
	return K * (i - 1) + y - 1;
	
}

