#include<stdio.h>
#include "logic.h"
#include"Init.h"

void Main()
{
	SetWindowSize(12, 7.5);
	InitGraphics();

	AddBGM();
	CreateMap();
	DrawBackground();
	setButtonColors("Dark Gray", "Black", "Gray", "Black", 1);
	SetWindowTitle("����ɨ�� Hot hot hot!!!");
	startTimer(MenuTimer, 10);
	Display();
	registerKeyboardEvent(KeyboardEventProcess);// ����
	registerMouseEvent(MouseEventProcess);      // ���
	registerTimerEvent(TimerEventProcess);      // ��ʱ��
}