#include <iostream>

using namespace std;

#include "ListContainer.h"

int main()
{
	{
		ListContainer<int> L;

		L.PushElement(5);
		L.PushElement(51);
		L.PushElement(522);
		L.PushElement(5333);

		L.RemoveElement(522);

		L[0] = -1;
		L[2] = -11;

		int Length = L.GetLength();

		for (size_t i = 0; i < Length; i++)
		{
			cout << L.NextValue() << endl;
		}
	}

	system("pause");
}
