#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
int main()
{
	srand(time(0));


	string Three_Ones("Three ones, lose all holdings, and lose turn");
	string Two_Ones("Two ones, lose half of holdings, and lose turn");
	string One("Single one, lose turn");
	int round_count = 1;
	int sum = 0;
	string turn("human");
	int Computer_Score = 0;
	int Human_Score = 0;
	int count = 0;
	while (Computer_Score <= 150 && Human_Score <= 150)
	{

		if (turn == "human")
		{
			int	Dice_A = 1 + rand() % 6;
			int Dice_B = 1 + rand() % 6;
			int Dice_C = 1 + rand() % 6;

			cout << "Rolled " << Dice_A << ", " << Dice_B << ", " << Dice_C << endl;
			int One_Count = 0;

			if (Dice_A == 1)
				One_Count++;

			if (Dice_B == 1)
				One_Count++;

			if (Dice_C == 1)
				One_Count++;

			if (One_Count == 1)
			{
				cout << One << endl;
				turn = "Computer";
				cout << "Computer's turn" << endl;
			}
			else if (One_Count == 2)
			{
				cout << Two_Ones << endl;
				Human_Score = Human_Score / 2;
				turn = "Computer";
				cout << "Computer's turn" << endl;
			}
			else if (One_Count == 3)
			{
				cout << Three_Ones << endl;
				Human_Score = 0;
				turn = "Computer";
				cout << "Computer's turn" << endl;
			}
			else
			{
				char choice = '?';
				int sum = Dice_A + Dice_B + Dice_C;
				cout << "sum = " << sum << endl;

				do
				{
					cout << "Bank(y\\n)? ";
					cin >> choice;

					if (choice == 'n')
					{

						break;
					}
					else if (choice == 'y')
					{
						turn = "Computer";
						Human_Score += sum;
						cout << "Computer's turn" << endl;

					}
					else
					{
						choice = '?';
					}
				} while (choice == '?');
			}
		}
		else if (turn == "Computer")
		{


			int	Dice_A = 1 + rand() % 6;
			int Dice_B = 1 + rand() % 6;
			int Dice_C = 1 + rand() % 6;

			cout << "Rolled " << Dice_A << ", " << Dice_B << ", " << Dice_C << endl;
			int One_Count = 0;

			if (Dice_A == 1)
				One_Count++;

			if (Dice_B == 1)
				One_Count++;

			if (Dice_C == 1)
				One_Count++;

			if (One_Count == 1)
			{
				cout << One;
				turn = "human";
			}
			else if (One_Count == 2)
			{
				cout << Two_Ones;
				Computer_Score = Computer_Score / 2;
				turn = "human";
			}
			else if (One_Count == 3)
			{
				cout << Three_Ones;
				Computer_Score = 0;
				turn = "human";
			}
			else
			{
				char choice = '?';
				int sum = Dice_A + Dice_B + Dice_C;
				cout << "sum = " << sum << endl;
				if (sum > 10)
					choice = 'y';
				else
				{
					if (Computer_Score > Human_Score)
					{
						choice = 'y';
					}
					else if (Computer_Score < Human_Score)
					{
						choice = 'n';
					}
				}
				do
				{
					cout << "Bank(y\\n)? ";


					if (choice == 'n')
					{
						cout << " no bank" << endl;
						break;
					}
					else if (choice == 'y')
					{
						turn = "human";
						Computer_Score += sum;
						cout << " bank";
					}
					else
					{
						cout << choice;
						choice = '?';
						cout << endl;
					}
				} while (choice == '?');

			}

			if (turn == "human")
			{
				cout << endl << "After round " << round_count << " human has " << Human_Score << " and computer has " << Computer_Score << endl << endl << endl;
				round_count++;
			}
		}

	}
	if (Human_Score > Computer_Score)

		cout << endl << endl << "Human won";

	else if (Human_Score < Computer_Score)

		cout << endl << endl << "Computer won";

	else
		cout << endl << endl << "Tie";


	return 0;
}