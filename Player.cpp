#include <iostream>
#include "Player.h"
#include "Shoe.h"

using namespace std;

//�Q�[�����s
Player::Player(const char* Pnum):Person(Pnum)
{
	
}

void Player::playBase(Shoe* shoe) {
	//�o�[�X�g����܂Ń��[�v����
	while (getScore()) {
		cout << Pnam_ << endl;;
		cout << "hit or stand >> ";

		//����
		char str[16]; //������^
		cin >> str; //����������
		//hit�����͂��ꂽ�ꍇ
		if (strcmp(str, "hit") == 0) {
			//�J�[�h�̔z�z
			hit(shoe);

			//��D�̕\��
			cout << "====================" << endl;
			cout << "player" << endl;
			showHands();
			cout << "====================" << endl;
		}
		else if (strcmp(str, "stand") == 0) {
			//�I������
			break;
		}
	}
}
