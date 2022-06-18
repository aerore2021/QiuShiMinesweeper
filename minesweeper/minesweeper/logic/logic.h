#pragma once
#ifndef  _logic_h

#define _logic_h

#include "random.h"
#include "boolean.h"
#include "time.h"

#define MAXROW	16
#define MAXCOL	16
#define MAXMINE 40
#define TIMES   2.5
#define STANDARD_SCORE 10000
unsigned int Seed;//���ɨ�׵�����ֵ

typedef struct {
	bool ifMine;	//�ײ�,����1������Ϊ0
	int  num;		//���Կ������ֲ�
	bool ifCovered;	//�жϸ����Ƿ��ƿ�
	bool flag;      //�ж��Ƿ����
} MINE;

MINE Mine[MAXROW][MAXCOL];

/*
	����һ��ɨ�׵�ͼ�ĺ�������˳�򣨾����ұ���ÿ���ö�Ҫ������죬�Ҿ������ǿ϶���Ҫ����
	CreateMine(); //��ʼ��Mine
	RandomMine(); �����������룬��SeedRand(seed)��//�������λ��
	int i, j;
	for (i = 0; i < MAXROW; i++) {
		for (j = 0; j < MAXCOL; j++) {
			Mine[i][j].num = Count(i, j);  //��������ֲ�
		}
	}
	//��ͼ//
	FisrtSquare(); //��α���������ʼ�հ���
*/

void CreateMine();
//��ʼ����ͼ������1.�ײ�ȫFLASE��0���ֲ���2.���ֲ�������֣�3.��ʼ�����и��ӱ���ס��TRUE����

/*������ͼ�����ɣ��ȿ��Դ������Ҳ������seed���ɡ�*/
void RandomMine();
//	���������
//  ����ε�����ֵ����ȫ�ֱ���Seed���������ʹ�õ�����ֵ��time�����õ��ġ���

void SeedRand(unsigned int seed);
//  ��seed������

void FirstSquare();
//   ������һ������ȷ���Ǹ����򣬶���һ���㣩

void SeedFirst(unsigned int seed);
//   ��seed������һ������ȷ���Ǹ����򣬶���һ���㣩

int Count(int row, int col);
//���㲢������Χ�˸����ӵ�����

void Clear(int row, int col);
//�����Ƹ��ӵݹ�,�ݹ�����������ֲ�Ϊ�㲢�ұ���ס�����ߺ���Ҫ�����������ݹ飩���ݹ�ĳ��������ֲ�����������
//ע�⣬�����׵�����£�����ֱ�ӵ���gameover()����Ȼÿ��clear������gameover��Ӧ����ÿ�ε�������ж�������ǲ����ף��ٿ��������clear��
//����λ�õĴ�����ֱ��ö���ˣ������˸��������Է��˺ܶ��࣬��Ϊ�ĸ�Ӧ�ò�����ô���࣬���������پ����ˣ�ȷ�������õġ�

int FinalScore(gametime);
//�������

void Passive_Cui(int row, int col);
//��������ʯ�ı���������һ��4*4���Զ����죻


void  UpdateList(int score);
//���������������γ�����������а��ı�

#endif // !_logic_h
