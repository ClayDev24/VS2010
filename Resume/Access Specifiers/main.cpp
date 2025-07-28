//#include "vld.h" // No memory leaks DETECTED!!!
#include "public.h"
#include "private.h"
#include "protected.h"
#include "friend.h"
#include "friend_nested.h"
using namespace std;

// Access (Specifiers) Control (or Implementation Hiding/Encapsulation):
// 1- Establish what client programmer CAN n' CANNOT use;
// 2- Separate INTERFACE from IMPLEMENTATION. The users can clearly see what they can use/ignore
// 3- Prevents you from crossin'boundaries durin'development.
// 4- The ability to change (optimizin'code|fixin'bugs/mistakes) w/ the assurance that
//    no client programmer becomes dependent on any part of the underlying implementation
//	  of a class('cus they cannot access'em), thus not breakin'up any 3rd party codes.
int main() {

	_public();
	_private();
	//_protected();
	_friend();
	_friend_nested();

	system("pause");
	return(0);
}