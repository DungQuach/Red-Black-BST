#include<iostream>
#include "Node.h"
#include "BST.h"

void main()
{
	BST* control = new BST();
	int select = 1;
	bool flag = true;
	while (flag)
	{
		std::cout << "Your option: \n";
		std::cout << "0. Exit\n";
		std::cout << "1. Insert node\n";
		std::cout << "2. Print value\n";
		std::cout << "3. Delete value\n";
		std::cout << "4. Search for value\n";
		std::cout << "5. Find the successor\n";
		std::cout << "7. Return root\n";
		std::cin >> select;
		std::cout << std::endl;
		switch (select)
		{
			case 0:
			{
				flag = false;
				break; 
			}
			case 1:
			{
				int value;
				std::cout << "Value of new node: ";
				std::cin >> value;
				control->Insert(value);
				break;
			}
			case 2:
			{
				control->Travel();
				std::cout << std::endl;
			}
			case 3:
			{

				break;
			}
			case 4:
			{
				int value;
				std::cout << "Value for search: ";
				std::cin >> value;
				control->Search(value);
				break;
			}
			case 5:
			{
				/*int value;
				std::cout << "Value for finding: ";
				std::cin >> value;*/
				control->Min();
				break;
			}
			case 7:
			{
				control->ReturnRoot();
				std::cout << std::endl;
				break;
			}

			default:
				break;
		}
	}


}