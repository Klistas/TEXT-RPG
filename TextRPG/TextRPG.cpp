
#include <iostream>
#include <conio.h>

using namespace std;

#define INPUTKEY char key = _getch();

class Player
{
public:


private:
};



int main()
{
	enum Scene // 씬을 선택함
	{
		Scene_Start,
		Scene_Select,
		Scene_Town,
		Scene_Map,

	};

	enum Job // 직업을 선택함
	{
		Job_Barbarian,
		Job_Sorceress,
		Job_Paladin,
		Job_Assassin,
	};

	enum Town
	{
		Town_Mayor,
		Town_Priest,
		Town_BlackSmith,
		Town_Portal,
		PlayerInfo
	};



	int scene = Scene_Start; // 씬을 선택하기 위한 변수
	int job = Job_Barbarian; // 직업을 선택하기 위한 변수
	int townAction = Town_Mayor;

	while (1) // 게임 루프
	{
		
		if (scene == Scene_Start) // 게임 시작씬
		{
			system("cls");
			cout << "========================================" << endl;
			cout << "            Marlboro    RPG            " << endl;
			cout << "========================================" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "    	  - PRESS ANY KEY -			  " << endl;
			INPUTKEY // 키입력
				if (key) // 키를 입력받으면 넘어감
				{
					scene = Scene_Select;
				}
				
		}

		if (scene == Scene_Select) // 직업 선택 씬
		{
			system("cls");

			cout << "======직업선택======" << endl << endl;

			cout << "1. 바바리안" << endl << endl;

			cout << "2. 소서리스" << endl << endl;
			
			cout << "3. 팔라딘" << endl << endl;
			
			cout << "4. 어쌔신" << endl;
			int key = _getch();
			if (key == '1' || key == '2' || key == '3' || key == '4') 
			{
				switch (key) // 입력받은 키를 바탕으로 직업 선택 칸으로 넘어감
				{
				case '1':
					job = Job_Barbarian;
					break;

				case '2':
					job = Job_Sorceress;
					break;

				case '3':
					job = Job_Paladin;
					break;

				case '4':
					job = Job_Assassin;
					break;
				}
			}
			else // 그외의 키는 무반응
				continue;

			if (job == Job_Barbarian) // 바바리안 선택칸
			{
				Sel_Barbarian :
				system("cls");
				cout << "바바리안은 접근전에서는 견줄 자가 없는 무기의 달인입니다." << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "선택하시겠습니까?" << endl;
				cout << " Y / N";
				INPUTKEY
					if (key == 'y')
					{
						scene = Scene_Town;
					}
					else if (key == 'n')
					{
						scene = Scene_Select;
					}
					else
						goto Sel_Barbarian;
			}

			else if (job == Job_Sorceress) // 소서리스 선택칸
			{
				Sel_Sorceress :
				system("cls");
				cout << "소서리스는 불, 번개, 얼음 등 원소 마법의 달인입니다." << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "선택하시겠습니까?" << endl;
				cout << " Y / N";
				INPUTKEY
					if (key == 'y')
					{
						scene = Scene_Town;
					}
					else if (key == 'n')
					{
						scene = Scene_Select;
					}
					else
						goto Sel_Sorceress;
			}

			else if (job == Job_Paladin) // 팔라딘 선택칸
			{
				Sel_Paladin :
				system("cls");
				cout << "팔라딘은 천부적인 지휘자이자 성스럽고 축복받은 전사입니다." << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "선택하시겠습니까?" << endl;
				cout << " Y / N";
				INPUTKEY
					if (key == 'y')
					{
						scene = Scene_Town;
					}
					else if (key == 'n')
					{
						scene = Scene_Select;
					}
					else
						goto Sel_Paladin;
			}

			else if (job == Job_Assassin) // 어쌔신 선택칸
			{
				Sel_Assassin :
				system("cls");
				cout << "어쌔신은 무도를 수련하여 몸과 마음 모두가 치명적인 무기입니다." << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "선택하시겠습니까?" << endl;
				cout << " Y / N";
				INPUTKEY
					if (key == 'y')
					{
						scene = Scene_Town;
					}
					else if (key == 'n')
					{
						scene = Scene_Select;
					}
					else
						goto Sel_Assassin;
		
			}
		}

		if (scene == Scene_Town)
		{
			system("cls");
			cout << "========데커트빌========" << endl << endl;

			cout << "당신은 데커트빌에 도착했습니다." << endl << endl;

			cout << "무엇을 하시겠습니까?" << endl << endl;
			
			cout << "1. 촌장에게 간다" << endl << endl;
			
			cout << "2. 사제에게 간다" << endl << endl;
			
			cout << "3. 대장장이에게 간다" << endl << endl;
			
			cout << "4. 포탈을 작동시킨다" << endl << endl;
			
			cout << "5. 나에 대해 알아가는 시간" << endl << endl;
			INPUTKEY
				switch (key)
				{
				case'1': townAction = Town_Mayor;
					break;
				case'2': townAction = Town_Priest;
					break;
				case'3': townAction = Town_BlackSmith;
					break;
				case'4': townAction = Town_Portal;
					break;
				case'5': townAction = PlayerInfo;
					break;
				}

			if (townAction == Town_Mayor)
			{
				system("cls");
				cout << "========데커트 촌장========" << endl << endl;
				cout << "당신은 데커트 촌장에게 다가갑니다." << endl << endl;
				cout << "촌장이 당신에게 말합니다." << endl << endl;
				cout << "반갑네, 모험가여." << endl << endl;
				cout << "우리 데커트빌은 지금 악마들의 침략으로 고통받고 있다네." << endl << endl;
				cout << "우리를 도와주겠나?" << endl << endl;
				cout << "1. 예" << endl << endl;
				cout << "2. 아니오" << endl << endl;
				INPUTKEY
			}
			if (townAction == Town_Priest)
			{
				system("cls");
				cout << "========사제 아카샤========" << endl << endl;
				cout << "당신은 아카샤 사제에게 다가갑니다." << endl << endl;
				cout << "사제는 당신을 뚫어지게 보며 말합니다." << endl << endl;
				cout << "모험가님, 당신을 기다리고 있었습니다." << endl << endl;
				cout << "당신이 올 것을 이미 알고 있었습니다." << endl << endl;
				cout << "신께서 당신을 도울 것입니다." << endl << endl;
				cout << "1. 포션이 필요하다고 한다." << endl << endl;
				cout << "2. 치료해달라고 한다." << endl << endl;
				cout << "3. 돌아간다." << endl << endl;
				INPUTKEY
			}
		}

		system("cls");
	}



























}

