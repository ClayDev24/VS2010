#include <iostream>
#include "utils.h"
using namespace std;

static void _test1();
static void _test2();
static void _test3();
static void _test4();
static vetorInt ChangeVector(vetorInt);
static void ChangeVector2(vetorInt&);
static void ChangeVector3(int ar[]);

static const long MAX  = 10000000;
static const long MAX2 = 10000000000;

static vetorInt  vGeral;
static vetorInt *vGeral2;
static int arr[MAX];

int main() {

	utils::PrintColour_("<<_Colection Performance Tests_>>\n\n", FRI);
	vGeral2 = new vetorInt();

	// fullfilling vector:
	for(int i=0; i<MAX; i++) {
		vGeral.push_back(i);
		vGeral2->push_back(i);
		arr[i]=i;
	}

	//P_(utils::_chronometer(&_test1))
	P_(utils::_chronometer(&_test2))
	P_(utils::_chronometer(&_test3))
	P_(utils::_chronometer(&_test4))

	P_(vGeral[3332])
	P_(vGeral[3333])
	P_(vGeral[3334])

	P_(vGeral2->at(3332))
	P_(vGeral2->at(3333))
	P_(vGeral2->at(3334))

	P_(arr[3332])
	P_(arr[3333])
	P_(arr[3334])

	delete vGeral2;
	system("pause");
	return(0);
}

static void _test1() {
	for(int i=0; i<MAX2; i++)
		vGeral=ChangeVector(vGeral);
}

static void _test2() {
	for(int i=0; i<MAX2; i++)
		ChangeVector2(*vGeral2);
}

static void _test3() {
	for(int i=0; i<MAX2; i++)
		ChangeVector2(*vGeral2);
}

static void _test4() {
	for(int i=0; i<MAX2; i++)
		ChangeVector3(arr);
}

static vetorInt ChangeVector(vetorInt _v) {
	_v[3333]=4444;
	return _v;
}

static void ChangeVector2(vetorInt &_v) {
	_v.at(3333)=1111;
}

static void ChangeVector3(int ar[]) {
	ar[3333]=7777;
}
