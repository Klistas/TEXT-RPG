
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string>


using namespace std;

#define INPUTKEY char key = _getch();

class Player
{
public:



	void Info()
	{
		if (EXP == 100)
		{
			Level++;
		}
		cout << "=========플레이어 정보=========" << endl << endl;
		cout << job[jobIndex] << endl << endl;

		cout << "1.Level : " << Level << endl << endl;
		cout << "2.HP : " << HP << endl << endl;
		cout << "3.MP : " << MP << endl << endl;
		cout << "4.EXP : " << EXP << endl << endl;
		cout << "5.소지 골드 : " << Gold << "G" << endl << endl;
		cout << "6.돌아가기" << endl << endl;
	}
	void FightWithMonster()
	{
		srand(time(NULL));
		int _HP = HP;
		Damage = rand() % 5;
		_HP -= Damage;
		cout << "플레이어 체력 : " << _HP << endl << endl;
		HP = _HP;
	}
	void Class(int key)
	{
	Class:
		if (key == '1' || key == '2' || key == '3' || key == '4')
		{
			switch (key) // 입력받은 키를 바탕으로 직업 선택 칸으로 넘어감
			{
			case '1':
				jobIndex = Job_Barbarian;
				break;

			case '2':
				jobIndex = Job_Sorceress;
				break;

			case '3':
				jobIndex = Job_Paladin;
				break;

			case '4':
				jobIndex = Job_Assassin;
				break;
			}
		}
		else // 그외의 키는 무반응
			goto Class;
	}
	void playerItem()
	{
		cout << "=====플레이어 인벤토리=====" << endl << endl;
		cout << "갑옷 : " << endl << endl;
		cout << "무기 : " << endl << endl;
		cout << "포션 : " << endl << endl;
	}

	void Shop()
	{

	}

private:
	int Level = 1;
	int EXP = 0;
	int HP = 100;
	int	MP = 100;
	int Gold = 100;
	int jobIndex = 0;
	int Damage = 0;

	string job[4] = { "바바리안", "소서리스", "팔라딘", "어쌔신" }; // 직업을 선택하기 위한 변수
	enum Job // 직업을 선택함
	{
		Job_Barbarian,
		Job_Sorceress,
		Job_Paladin,
		Job_Assassin,
	};

};

class Monster
{
public:

	void Wood()
	{
		srand(time(NULL));
		MonsterIndex = rand() % 3;
		switch (MonsterIndex)
		{
		case 0: HP = 100;
			GivenExp = 10;
			GivenGold = 50;
			break;

		case 1: HP = 150;
			GivenExp = 20;
			GivenGold = 75;
			break;

		case 2: HP = 200;
			GivenExp = 30;
			GivenGold = 100;
			break;
		}
		cout << WoodMonster[MonsterIndex] << "를 만났습니다!" << endl << endl;
		cout << "체력 : " << HP << endl << endl;

	}
	void Port()
	{
		srand(time(NULL));
		MonsterIndex = rand() % 3 + 3;
		switch (MonsterIndex)
		{
		case 3: HP = 125;
			GivenExp = 15;
			GivenGold = 60;
			break;

		case 4: HP = 250;
			GivenExp = 40;
			GivenGold = 125;
			break;

		case 5: HP = 400;
			GivenExp = 75;
			GivenGold = 200;
			break;
		}
		cout << WoodMonster[MonsterIndex] << "를 만났습니다!" << endl << endl;
		cout << "체력 : " << HP << endl << endl;
	}
	void FightMonster()
	{
		Player player;
		cout << "현재 몬스터 : " << WoodMonster[MonsterIndex] << endl << endl;
		cout << "체력 : " << HP << endl << endl;
		
			
		while (true)
			{
				cout << "1. 공격한다." << endl << endl;
				cout << "2. 도망친다." << endl;
				INPUTKEY
					if (HP > 0)
					{
						if (key == '1')
						{
							Damage = rand() % 6 + 1;
							if (Damage <= 2)
							{
								system("cls");
								cout << "주사위의 수는 " << Damage << "입니다" << endl << endl;
								cout << "MISS!" << endl << endl;
								cout << "몬스터 체력 : " << HP << endl << endl;
								player.FightWithMonster();
							}
							else if (Damage > 2 && Damage <= 4)
							{
								system("cls");
								cout << "주사위의 수는 " << Damage << "입니다" << endl << endl;
								HP -= 10;
								cout << "공격이 통했다!!" << endl << endl;
								cout << "몬스터 체력 : " << HP << endl << endl;
								player.FightWithMonster();
							}
							else if (Damage >= 5)
							{
								system("cls");
								cout << "주사위의 수는 " << Damage << "입니다" << endl << endl;
								HP -= 20;
								cout << "치명타가 들어갔다!!" << endl << endl;
								cout << "몬스터 체력 : " << HP << endl << endl;
								player.FightWithMonster();
							}
						}
						else if (key == '2')
							break;
						else
							continue;
					}
					else if (HP <= 0)
					{
						system("cls");
						BeatMonster();
						INPUTKEY
							break;
					}
			}
	}
	void BeatMonster()
	{
		cout << WoodMonster[MonsterIndex] << " 을(를) 물리쳤습니다!" << endl << endl;
		cout << "경험치를 " << GivenExp << " 획득했습니다." << endl << endl;
		cout << "골드를 " << GivenGold << " G 획득했습니다." << endl << endl;
		cout << "돌아가려면 아무키나 누르세요.";
	}


private:
	int HP = 0;
	int GivenExp = 0;
	int GivenGold = 0;
	string WoodMonster[6] = { "스켈레톤", "좀비", "유령", "해적", "미라", "크라켄" };
	int MonsterIndex = 0;
	int Damage = 0;
	enum WoodMonster
	{
		Wood_Skeleton,
		Wood_Zombie,
		Wood_Ghost,
	};
	enum PortMonster
	{
		Port_Pirate,
		Port_Mumies,
		Port_Kraken,

	};
};

int main()
{
	enum Scene // 씬을 선택함
	{
		Scene_Start,
		Scene_Select,
		Scene_Town,
		Scene_MapWood,
		Scene_MapPort,

	};

	

	enum Town
	{
		Town_Priest,
		Town_BlackSmith,
		Town_Portal,
		PlayerInfo
	};

	enum Shop
	{
		Shop_Potion,
		Shop_Recovery,
		Shop_Weapon,
		Shop_Armor,
	};

	enum Map
	{
		Map_Town,
		Map_DeepWood,
		Map_CusedPort,
	};


	int scene = Scene_Start; // 씬을 선택하기 위한 변수
	int townAction = Town_Priest;
	int shop = Shop_Potion;
	int map = Map_Town;
	
	Player player;
	Monster monster;

	while (1) // 게임 루프
	{
		
		if (scene == Scene_Start) // 게임 시작씬
		{
			system("cls");
			cout << "========================================" << endl;
			cout << "            Marlboro    RPG            " << endl;
			cout << "========================================" << endl;
			cout << endl << endl << endl << endl << endl << endl << endl;
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
			
			player.Class(key);

			if (key == '1') // 바바리안 선택칸
			{
			Sel_Barbarian:
				system("cls");
				cout << "바바리안은 접근전에서는 견줄 자가 없는 무기의 달인입니다." << endl;
				cout << endl << endl << endl << endl << endl;
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

			else if (key == '2') // 소서리스 선택칸
			{
			Sel_Sorceress:
				system("cls");
				cout << "소서리스는 불, 번개, 얼음 등 원소 마법의 달인입니다." << endl;
				cout << endl << endl << endl << endl << endl;
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

			else if (key == '3') // 팔라딘 선택칸
			{
			Sel_Paladin:
				system("cls");
				cout << "팔라딘은 천부적인 지휘자이자 성스럽고 축복받은 전사입니다." << endl;
				cout << endl << endl << endl << endl << endl;
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

			else if (key == '4') // 어쌔신 선택칸
			{
			Sel_Assassin:
				system("cls");
				cout << "어쌔신은 무도를 수련하여 몸과 마음 모두가 치명적인 무기입니다." << endl;
				cout << endl << endl << endl << endl << endl;
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
			else
				continue;
		}
		
		if (scene == Scene_Town)
		{
			Town :
			system("cls");
			cout << "========데커트빌========" << endl << endl;

			cout << "당신은 데커트빌에 도착했습니다." << endl << endl;

			cout << "무엇을 하시겠습니까?" << endl << endl;
			
			cout << "1. 사제에게 간다" << endl << endl;
			
			cout << "2. 대장장이에게 간다" << endl << endl;
			
			cout << "3. 포탈을 작동시킨다" << endl << endl;
			
			cout << "4. 나에 대해 알아가는 시간" << endl << endl;
			INPUTKEY
				switch (key)
				{
				case'1': townAction = Town_Priest;
					break;
				case'2': townAction = Town_BlackSmith;
					break;
				case'3': townAction = Town_Portal;
					break;
				case'4': townAction = PlayerInfo;
					break;
				default: continue;
					break;
				}
		


			if (townAction == Town_Priest)
			{
				Priest :
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
					if (key == '1')
					{
						shop = Shop_Potion;
					}
					else if (key == '2')
					{
						shop = Shop_Recovery;
					}
					else if (key == '3')
					{
						goto Town;
					}
					else
					{
						goto Priest;
					}
			if (shop == Shop_Potion)
			{
				Potion :
				system("cls");
				cout << "필요한 것을 선택하세요." << endl << endl;
				cout << "1. 체력 포션 - 50G" << endl << endl;
				cout << "2. 마나 포션 - 50G" << endl << endl;
				cout << "3. 돌아가기" << endl << endl;
				INPUTKEY
					if (key == '1')
					{
						goto Town;
					}
					else if (key == '2')
					{
						goto Town;
					}
					else if (key == '3')
					{
						goto Town;
					}
					else
					{
						goto Potion;
					}
			}
			else if (shop == Shop_Recovery)
			{
				Recovery :
				system("cls");
				cout << "치료를 하시겠습니까?" << endl << endl;
				cout << "1. 한다 - 70G" << endl << endl;
				cout << "2. 안한다." << endl << endl;
				INPUTKEY
					if (key == '1')
					{
						shop = Shop_Weapon;
					}
					else if (key == '2')
					{
						goto Town;
					}
					else
					{
						goto Recovery;
					}
			}
			}
			
			if (townAction == Town_BlackSmith)
			{
				BlackSmith : 
				system("cls");
				cout << "========대장장이 찰시========" << endl << endl;
				cout << "당신은 대장장이 찰시에게 다가갑니다." << endl << endl;
				cout << "대장장이가 망치질을 하며 당신을 바라봅니다." << endl << endl;
				cout << "모험가는 오랜만이구만!" << endl << endl;
				cout << "반갑네, 구경이나 해보시게. 품질은 보증하지." << endl << endl;
				cout << "아 참, 도둑질할 생각은 말라고!" << endl << endl;
				cout << "1. 무기를 본다." << endl << endl;
				cout << "2. 방어구를 본다." << endl << endl;
				cout << "3. 돌아간다." << endl << endl;
				INPUTKEY
					if (key == '1')
					{
						shop = Shop_Weapon;
					}
					else if (key == '2')
					{
						shop = Shop_Armor;
					}
					else if (key == '3')
					{
						goto Town;
					}
					else
					{
						goto BlackSmith;
					}
			if (shop == Shop_Weapon)
			{
				system("cls");
				cout << "필요한 것을 선택하세요." << endl << endl;
				cout << "1. 브로드 소드 - 150G" << endl << endl;
				cout << "2. 토마호크 - 250G" << endl << endl;
				cout << "3. 본 쉴드 - 350G" << endl << endl;
				cout << "4. 호라드릭 스태프 - 200G" << endl << endl;
				cout << "5. 돌아가기" << endl << endl;
				INPUTKEY

			}
			else if (shop == Shop_Armor)
			{
				system("cls");
				cout << "필요한 것을 선택하세요." << endl << endl;
				cout << "1. 레더 아머 - 150G" << endl << endl;
				cout << "2. 스틸 아머 - 250G" << endl << endl;
				cout << "3. 미스릴 아머 - 450G" << endl << endl;
				cout << "4. 드래곤 아머 - 700G" << endl << endl;
				cout << "5. 돌아가기" << endl << endl;
				INPUTKEY
			}
			}
			if (townAction == Town_Portal)
			{
				Portal :
				system("cls");
				cout << "========포탈========" << endl << endl;
				cout << "당신은 포탈에 다가갑니다." << endl << endl;
				cout << "다가가자 푸른 빛이 타오릅니다." << endl << endl;
				cout << "포탈에 올라서자 어딘가로 갈 수 있을 것 같습니다." << endl << endl;
				cout << "어디로 가시겠습니까?" << endl << endl;
				cout << "1. 어두운 숲" << endl << endl;
				cout << "2. 저주받은 항구" << endl << endl;
				cout << "3. 포탈을 사용하지 않고 돌아간다." << endl << endl;
				INPUTKEY
					switch (key)
					{
					case '1': map = Map_DeepWood;
						break;
					case '2': map = Map_CusedPort;
						break;
					default:
						goto Portal;
						break;
					}
				if (map == Map_Town)
				{
					scene = Scene_Town;
				}
				else if (map == Map_DeepWood)
				{
					scene = Scene_MapWood;
				}
				else if (map == Map_CusedPort)
				{
					scene = Scene_MapPort;
				}
			}
		}
		if (townAction == PlayerInfo)
		{
			Info :
			system("cls");
			player.Info();
			INPUTKEY
				if (key == '6')
				{
					scene = Scene_Town;
				}
				else
					goto Info;
		}
		if (scene == Scene_MapWood)
		{
			MapWood:
			system("cls");
			cout << "======어두운 숲======" << endl << endl;
			cout << "당신은 어두운 숲에 진입했습니다." << endl << endl;
			monster.Wood();
			cout << "1. 공격" << endl << endl;;
			cout << "2. 도망치기" << endl << endl;;
			INPUTKEY
				if (key == '1')
				{
					system("cls");
					monster.FightMonster();
					

				}
				else if (key == '2')
				{
					scene = Scene_Town;
				}
				else
					goto MapWood;
		}
		if (scene == Scene_MapPort)
		{
		MapPort:
			system("cls");
			cout << "======저주받은 항구======" << endl << endl;
			cout << "당신은 저주받은 항구에 진입했습니다." << endl << endl;
			monster.Port();
			cout << "1. 공격" << endl << endl;;
			cout << "2. 도망치기" << endl << endl;;
			INPUTKEY
				if (key == '1')
				{
					system("cls");
					monster.FightMonster();


				}
				else if (key == '2')
				{
					scene = Scene_Town;
				}
				else
					goto MapPort;

		}
		system("cls");
	
	}



























}

