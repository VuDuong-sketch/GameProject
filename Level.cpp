#include <vector>
#include <string>

using namespace std;

vector<string> Level ( int level ) {
	vector<string> v;
	if( level == 1 ) {
    	v.push_back("1 1 219");
        v.push_back("1 2 120");
        v.push_back("1 3 219");
        v.push_back("1 4 219");
        v.push_back("2 1 219");
        v.push_back("2 2 98");
        v.push_back("2 3 15");
        v.push_back("2 4 219");
        v.push_back("3 1 120");
        v.push_back("3 2 98");
        v.push_back("3 4 219");
        v.push_back("4 1 219");
        v.push_back("4 2 219");
        v.push_back("4 3 219");
        v.push_back("4 4 219");	
	}
	else if( level == 2 ) {
        v.push_back("1 1 219");
        v.push_back("1 2 219");
        v.push_back("1 3 120");
        v.push_back("1 4 219");
        v.push_back("1 5 219");
        v.push_back("1 6 120");
        v.push_back("1 7 219");
        v.push_back("2 3 98");
        v.push_back("2 4 15");
        v.push_back("2 5 98");
        v.push_back("2 7 219");
        v.push_back("3 4 98");
        v.push_back("3 6 120");
        v.push_back("3 7 219");
        v.push_back("4 1 219");
        v.push_back("4 2 219");
        v.push_back("4 3 219");
        v.push_back("4 4 219");
        v.push_back("4 5 219");
        v.push_back("4 6 219");
        v.push_back("4 7 219");
	}
	else if( level == 3 ) {
        v.push_back("1 1 15");
        v.push_back("1 2 120");
        v.push_back("1 3 219");
        v.push_back("1 6 219");
        v.push_back("2 3 98");
        v.push_back("2 6 219");
        v.push_back("3 1 219");
        v.push_back("3 3 219");
        v.push_back("3 4 219");
        v.push_back("3 6 219");
        v.push_back("4 1 219");
        v.push_back("4 3 219");
        v.push_back("4 4 219");
        v.push_back("4 7 219");
        v.push_back("5 1 219");
        v.push_back("5 2 120");
        v.push_back("5 4 98");
        v.push_back("5 7 219");
        v.push_back("6 1 219");
        v.push_back("6 4 219");
        v.push_back("6 7 219");
	}
	else if( level == 4 ) {
		v.push_back("1 3 219");
        v.push_back("1 7 219");
        v.push_back("2 3 98");
        v.push_back("2 5 120");
        v.push_back("2 6 120");
        v.push_back("2 7 219");
        v.push_back("3 1 120");
        v.push_back("3 2 120");
        v.push_back("3 3 120");
        v.push_back("3 4 98");
        v.push_back("3 4 120");
        v.push_back("3 5 98");
        v.push_back("3 5 120");
        v.push_back("3 7 219");
        v.push_back("4 1 98");
        v.push_back("4 3 219");
        v.push_back("4 5 120");
        v.push_back("4 5 98");
        v.push_back("4 7 219");
        v.push_back("5 1 15");
        v.push_back("5 2 98");
        v.push_back("5 4 98");
        v.push_back("5 5 98");
        v.push_back("5 7 219");
        v.push_back("6 3 219");
        v.push_back("6 7 219");
	}
	return v;
}
