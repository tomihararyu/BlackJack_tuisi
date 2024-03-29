#pragma once

#include "common.h"

class Shoe;

class Person
{
private:
	int _hand[HAND_SIZE];	// 理論上これくらい持てばOK...に今回はしちゃう
	bool _calcUpdate;
	int _cardNum;
	int _score;

public:
	// コンストラクタ
	Person(const char* Pname);

	//スコアの取得(hitされた時のみ再計算される)
	int getScore();

	//カードの追加
	void hit(Shoe* shoe);

	//手札を表示
	void showHands();

	//ターン処理
	bool play(Shoe* shoe);
	char* nameReturn();

protected:
	virtual void playBase(Shoe* shoe);	//ターン処理本体
	char* Pnam_;

};

