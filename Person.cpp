#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

#include "Person.h"
#include "Shoe.h"

using namespace std;

Person::Person(const char* Pnam)
{
	fill_n(_hand, HAND_SIZE, -1);
	_cardNum = 0;
	_calcUpdate = false;
	_score = 0;
	Pnam_ = new char[strlen(Pnam) + 1];
	strcpy(Pnam_, Pnam);
}

//�X�R�A�̌v�Z
int Person::getScore()
{
	if (_calcUpdate == true)
	{// �Čv�Z�t���O�������Ă�����Čv�Z����
		int* data = NULL; //�X�R�A�v�Z�p�z��p�|�C���^

		data = new(nothrow) int[_cardNum]; //��D�����m��
		if (data == NULL)
		{
			// �������s���͍���̓o�[�X�g�Ƃ��ďI������B
			cout << "�������̊m�ۂɎ��s���܂����B�ċN�����Ă��������B" << endl;
			return 0;
		}

		//��D�z�񂩂�f�[�^���擾,1-10�̒l�Ƃ��Ċi�[
		for (int i = 0; i < _cardNum; i++) {
			if (_hand[i] % 13 < 10) {
				//�z��̒l��10�ȉ�(0-9)�ł����1�������Ċi�[
				*(data + i) = _hand[i] % 13 + 1;
			}
			else {
				//������10���i�[���Ă���̂�,11-13�̃J�[�h�̂���
				*(data + i) = 10;
			}
		}

		//�\�[�g�iA�����Ԃ肾�����߁j
		sort(data, data + _cardNum);

		//�Ԃ�l�p�ϐ�(�v�Z����)
		_score = 0;
		//2�Ԗڂ��珇�ɃX�R�A�𑫂��Ă���
		//1�Ԗڂ�0�̏ꍇ(�܂�A�ł���B2�������\���͂��邪2���ڂ�A�͕K��1�Ƃ��ăJ�E���g����
		//�̂Ő擪�������ׂ�΂悢
		for (int i = 1; i < _cardNum; i++) {
			//�X�R�A�Ƀf�[�^��������
			_score = _score + (*(data + i));
		}

		//�擪��1(A)�ł��邩���肵�󋵂ɂ����1 or 11�Ƃ��Čv�Z
		if (*data == 1) {
			if (_score + 11 < 22) { //11�Ƃ��Ĉ����Ă��o�[�X�g���Ȃ��ꍇ
				//11��������
				_score += 11;
			}
			else {
				//11�Ƃ��Ĉ����ƃo�[�X�g����ꍇ
				//�X�R�A��1��������
				_score += 1;
			}
		}
		else {
			//�擪��1�łȂ��Ȃ�,�X�R�A�Ƀf�[�^�����̂܂܉�����
			_score += data[0];
		}

		//�o�[�X�g�ł���ꍇ��0��Ԃ�
		if (_score > 21) {
			_score = 0;
		}

		// ���
		if (data != NULL)
		{
			delete[] data;
			data = NULL;
		}
	}

	return _score;
}

//�莝���ɃJ�[�h�̒ǉ�
void Person::hit(Shoe* shoe) {
	int card = shoe->takeCard();
	if (card >= 0) {
		_hand[_cardNum] = card;
		_cardNum++;
		_calcUpdate = true;
	}
	else
	{
		cout << "�J�[�h�������܂���ł����B" << endl;
	}
}

//��D��\��
void Person::showHands() {
	//�W���o��
	cout <<Pnam_<<" is " << "hand: ";
	//�z��̍ŏ�����Ō�܂ł����ɕ\��
	for (int i = 0; i < _cardNum; i++) {
		//�J�[�h�̎��(�X�y�[�h,�n�[�g,�_�C��,�N���u)��T��
		int type = (_hand[i] % 52) / 13; //�f�b�L���Ƃɕ�������,13�Ŋ�������(0-3)��4��ނ𕪊�

		//�W���o��
		const char* strType[] = { "s", "h", "d", "c" };
		cout << strType[type];
		cout << _hand[i] % 13 + 1 << ' ';
	}
	//���s
	cout << endl;
	cout << "score: " << getScore() << endl; //�X�R�A�̕\��
}

// �^�[������
bool Person::play(Shoe* shoe)
{
	playBase(shoe);

	if (getScore() <= 0) return false;
	return true;
}
char* Person::nameReturn()
{
	return Pnam_;
}

//// �^�[�����C������
void Person::playBase(Shoe* shoe)
{

}