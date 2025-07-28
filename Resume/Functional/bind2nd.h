#pragma once
#include <iostream>
#include <functional>
#include <algorithm>

static void _bind2nd() {
	int numbers[] = {10,-20,-30,40,-50};
	int cx;
	cx = count_if(numbers, numbers+5, bind2nd(std::less<int>(), 0));
	std::cout << "There are " << cx << " negative elements.\n";
}