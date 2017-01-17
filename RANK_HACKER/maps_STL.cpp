#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	map<string, int> m;
	unsigned int Q;

	cin >> Q;
	if (Q<1 | Q>100000) {
    		return 0;
	}

	int type, y;
	string name;
	for (int i = 0; i < Q; i++) {

    		cin >> type;
    		if (type<1 | type>3) {
        		return 0;
    		}

    		cin >> name;
    		map<string, int>::iterator itr = m.find(name);

    		if (type == 1) {
        		cin >> y;
        		if (itr == m.end()) {
            			m.insert(make_pair(name, y));
        		}
        		else {
            			itr->second += y;
        		}
    		}
    		else if (type == 2) {
        		if (itr != m.end()) {
            			m.erase(name);
        		}
    		}
    		else {
        		if (itr == m.end()) {
            			cout << 0 << "\n";
        		}
        		else
        		{
            			cout << itr->second << "\n";
        		}
    		}
	}
	return 0;
}
