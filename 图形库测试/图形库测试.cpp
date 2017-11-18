// 图形库测试.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <graphics.h>			    // 就是需要引用这个图形库
#include <conio.h>
void main()
{
	initgraph(640, 480);		   // 这里和 TC 略有区别
	setlinecolor(RED);
	setfillcolor(BLUE);
	fillcircle(200, 200, 100);	   // 画圆，圆心(200, 200)，半径 100
	getchar();					   // 按任意键继续
	closegraph();				   // 关闭图形界面
}

