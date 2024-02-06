#pragma once

#include "common.h"

class Shoe;

class Person
{
private:
	int _hand[HAND_SIZE];	// ���_�ケ�ꂭ�炢���Ă�OK...�ɍ���͂����Ⴄ
	bool _calcUpdate;
	int _cardNum;
	int _score;

public:
	// �R���X�g���N�^
	Person(const char* Pname);

	//�X�R�A�̎擾(hit���ꂽ���̂ݍČv�Z�����)
	int getScore();

	//�J�[�h�̒ǉ�
	void hit(Shoe* shoe);

	//��D��\��
	void showHands();

	//�^�[������
	bool play(Shoe* shoe);
	char* nameReturn();

protected:
	virtual void playBase(Shoe* shoe);	//�^�[�������{��
	char* Pnam_;

};

