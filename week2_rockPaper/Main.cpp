#include <iostream>
#include <string>

using namespace std;

bool isBitSet(int value, int position);
void randomChoice(int& choice, int& pos, string& move);
void setChoice(int& choice, int& pos, string& move);

int main()
{
	//--	R	P	Sc	L	Sp	=bits	= value		= position
	//R		-	0	1	1	0	=00110	=  6		= 4
	//P		1	-	0	0	1	=10001	= 17		= 3
	//Sc	0	1	-	1	0	=01010	= 10		= 2
	//L		0	1	0	-	1	=01001	=  9		= 1
	//Sp	1	0	1	0	-	=10100	= 20		= 0

	//check if both are the same			= draw
	//check if resulting bit is positive	= win
	//if not positive						= lose

	int compScore = 0, comp = 0, compPos = 0, playerScore = 0, player = 0, playerPos = 0, playAgain = 1;
	string compMove, playerMove;
	bool result, playGame = true;
	
	cout << "RockPaperScissorsLizardSpock!" << endl;
	cout << "............................" << endl;
	cout << "Spock smashes scissors and vaporizes rock;" << endl;
	cout << " he is poisoned by lizard and disproven by paper. " << endl;
	cout << "Lizard poisons Spock and eats paper;" << endl;
	cout << "it is crushed by rock and decapitated by scissors" << endl;


	while (playGame)
	{
		cout << "Computer score : "<< compScore << " Player score : " << playerScore << endl;
		cout << "Computer - Enter your choice" << endl;
		cout << "............................" << endl;
		randomChoice(comp, compPos, compMove);
		cout << "Choice selected" << endl;
		cout << "............................" << endl;

		cout << " Please choose your choice: 1 = Rock, 2 = Paper " << endl;
		cout << " 3 = Scissors, 4 = Lizard, 5 = Spock " << endl;
		cout << "............................" << endl;
		cout << "Player   - Enter your choice" << endl;
		cout << "............................" << endl;
		cin >> player;
		setChoice(player, playerPos, playerMove);
		cout << "............................" << endl;

		if (comp - player != 0){
			result = isBitSet(player, compPos);
			cout << "Computer Chose: " << compMove << " and Player Chose: " << playerMove << endl;
			cout << "............................" << endl;
			if (result)
			{
				cout << "Player wins!" << endl;
				playerScore++;
			}
			else
			{
				cout << "Computer wins!" << endl;
				compScore++;
			}

			cout << "............................" << endl;
		}
		else
		{
			cout << "Computer Chose: " << compMove << " and Player Chose: " << playerMove << endl;
			cout << "............................" << endl;
			cout << "It's a draw!" << endl;
			cout << "............................" << endl;
		}


		cout << "Would you like to play again? (y=1/n=0)" << endl;
		cout << "............................" << endl;
		cin >> playGame;
	}

	cout << "Final scores!" << endl;
	cout << "Computer : " << compScore << endl;
	cout << "Player score : " << playerScore << endl;
	if (compScore > playerScore)
		cout << "Computer wins overall!!!" << endl;
	else
		cout << "Player wins Overall!!!" << endl;

system("pause");
	return 0;
}


void randomChoice(int& choice, int& pos, string& move)
{
	choice = rand() % 5 + 1;
	setChoice(choice, pos, move);
}
void setChoice(int& choice, int& pos, string& move)
{
	switch (choice)
	{
	case 1:
		choice = 6;
		pos = 4;
		move = "Rock";
		break;
	case 2:
		choice = 17;
		pos = 3;
		move = "Paper";
		break;
	case 3:
		choice = 10;
		pos = 2;
		move = "Scissors";
		break;
	case 4:
		choice = 9;
		pos = 1;
		move = "Lizard";
		break;
	case 5:
		choice = 20;
		pos = 0;
		move = "Spock";
		break;
	default:
		choice = 20;
		pos = 0;
		move = "Spock";
	}
}

bool isBitSet(int value, int position)
{
	int mask = 1 << position;
	if ((mask & value) > 0)
		return true;
	else
		return false;
}
