#include "Status.h"

string StatusToString(Status status)
{
	string strStatus;

	switch (status)
	{
	case create:
		strStatus = "создан";
		break;
	case working:
		strStatus = "в сборке";
		break;
	case finished:
		strStatus = "готов к выдаче";
		break;
	default:
		break;
	}
	return strStatus;
}

static istream& operator >> (istream& in, Status& status) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		status = Status::create;
		break;
	case 1:
		status = Status::working;
		break;
	case 2:
		status = Status::finished;
		break;
	default:
		break;
	}
	return in;
};

static ostream& operator << (ostream& out, Status& status) {
	out << StatusToString(status);
	return out;
};