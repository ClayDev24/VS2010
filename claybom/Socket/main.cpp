#include "iostream"
#include "SimpleSocket\client.h"
#include "SimpleSocket\server.h"
using namespace std;

int main() {
	simpleServer();
	simpleClient();

	system("pause");
	return(0);
}