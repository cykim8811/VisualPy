#include "RefInt.h"

#include <iostream>

using namespace std;

RefInt::RefInt(int data) {
    isLiteral = true;
    value = data;
}

RefInt::RefInt(RefInt* link) {
    isLiteral = true;
    target = link;
    link->linked.push_back(this);
}

RefInt::~RefInt() {
    // Change value of readers to get() of this on remove
    for (auto iter = linked.begin(); iter != linked.end(); ++iter) {
        (*iter)->target = nullptr;
        (*iter)->value = get();
        (*iter)->isLiteral = true;
    }
}

int RefInt::get(){
    RefInt* track = this;
    while (!track->isLiteral) {
        if (track->target == nullptr) {
            cerr << "Referencing deleted RefInt" << endl;
            return track->value;
        }
        else if (track->target == this) {
            cerr << "Self reference Detected" << endl;
            return -1;
        }
        track = track->target;
    }
    return track->value;
}
