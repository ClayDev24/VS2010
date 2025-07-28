#include <iostream>
#include
using namespace std;

int main() {
	CString str1 = "clailton";
	CString str2 = "clailton";
	cout << str1 << endl;
	cout << str2 << endl;
	// 1 se diferente e 0 se igual:
	cout << "str1.Compare(str2) = " << str1.Compare(str2) << endl;
	cout << "str1.CompareNoCase(str2) = " << str1.CompareNoCase(str2) << endl;
	// 1 se igual e 0 se diferente:
	cout << "str1 == str2 = " << (str1 == str2) << endl;

	str1.Delete(0, 2);
	cout << str1 << endl;

	str1.Empty();

	cout << str1 << endl;

	//retorna a posição se ouver a ocorrencia. senão retorna -1:
	int i = str2.Find('t', 0);
	cout << i << endl;
	i = str2.Find('t');
	cout << i << endl;
	cout << "str2.Find(\"tol\") = " << str2.Find("la", 0) << endl;
	str2.Find("ton");

	//str2.FindOneOf(
	cout << str2.GetAt(0);
	cout << str2.GetAt(1);
	cout << str2.GetAt(2);
	cout << str2.GetAt(3);
	cout << str2.GetAt(4);
	cout << str2.GetAt(5);
	cout << str2.GetAt(6);
	cout << str2.GetAt(7);
	cout << endl;

	cout << "length: " << str2.GetLength() << endl;
	str2.Insert(5, "ferreira");
	cout << str2 << endl;
	str2.Empty();
	cout << "str2.Empty() = " << str2.GetLength() << endl;
	str2 = "clailton";
	cout << str2 << endl;
	//TRUE if zero length:
	cout << str2.IsEmpty() << endl;
	//return first nCount characters on string:
	cout << str2.Left(3) << endl;
	str2.MakeUpper();
	str2.MakeReverse();
	cout << str2 << endl;
	str2.MakeLower();
	str2.MakeReverse();
	cout << str2 << endl;
	cout << str2.Mid(2, 3) << endl;
	str2.Remove('l');
	cout << str2 << endl;
	str2.Replace('o', 'z');
	cout << str2 << endl;
	str2.ReverseFind('a');
	cout << str2.Right(5) << endl;
	str2.SetAt(4, 'w');
	cout << str2 << endl;

	CString str3 = "  aaa   ";
	cout << "bbb" << str3 << "ccc" << endl;
	str3.TrimLeft();
	str3.TrimRight();
	cout << "bbb" << str3 << "ccc" << endl;

	return(0);
}