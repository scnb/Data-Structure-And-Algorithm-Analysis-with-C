// ͼ�ο����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <graphics.h>			    // ������Ҫ�������ͼ�ο�
#include <conio.h>
void main()
{
	initgraph(640, 480);		   // ����� TC ��������
	setlinecolor(RED);
	setfillcolor(BLUE);
	fillcircle(200, 200, 100);	   // ��Բ��Բ��(200, 200)���뾶 100
	getchar();					   // �����������
	closegraph();				   // �ر�ͼ�ν���
}

