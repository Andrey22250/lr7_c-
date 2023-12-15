#pragma once
#include <string>
#include <iostream>

using namespace std;

enum Status { create, working, finished };

string StatusToString(Status status);
static istream& operator >> (istream& in, Status& status);
static ostream& operator << (ostream& out, Status& status);