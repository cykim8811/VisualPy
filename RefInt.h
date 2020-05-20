#pragma once
#include <vector>

using namespace std;


class RefInt {
private:
	bool isLiteral = true;
	int value;
	RefInt* target;
	vector<RefInt*> linked;
public:
	RefInt(int data);
	RefInt(RefInt* link);
	~RefInt();
	int get();
};
