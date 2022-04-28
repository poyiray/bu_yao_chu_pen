#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main()
{
	float width, height, gravity; //游戏画面，重力加速度
	float ball_x, ball_y, ball_vy,radius; // 小球圆心坐标，y方向速度，半径
	float rect_left_x, rect_top_y, rect_width, rect_height, rect_vx;// 方块障碍

	width = 600;
	height = 400;
	gravity = 0.6;
	initgraph(width, height);
	radius = 20; //半径
	ball_x = width / 4; //小球x坐标
	ball_y = height - radius; // 小球y坐标
	ball_vy = 0; //小球舒适y速度

	rect_height = 100; //方块高度
	rect_width = 20; //方块高度
	rect_left_x = width * 3 / 4; //方块左边x坐标
	rect_top_y = height - rect_height; //方块顶部y坐标
	rect_vx = -3; //方块x轴移动速度

	int i;
	int isBallonFloor = 1; //判断球是否在地上
	int score = 0; //分数

	while (1)
	{
		if (_kbhit())
		{
			char input = _getch(); //获取字符
			if (input == 'w' && isBallonFloor == 1)
			{
				ball_vy = -16; //给小球一个向上的初始速度
				isBallonFloor = 0;
			}
		}

		//球体移动
		ball_vy = ball_vy + gravity;
		ball_y = ball_y + ball_vy;

		//球体触地
		if (ball_y >= height - radius)
		{
			ball_vy = 0; //y停止跳跃
			ball_y = height - radius; //避免穿模
			isBallonFloor = 1;
		}

		//方块左移
		rect_left_x = rect_left_x + rect_vx; 
		if (rect_left_x < 0 - rect_width)
		{
			rect_left_x = width;

			score++; //得分+1

			rect_height = rand() % int(height / 4) + height / 4; //设计随机高度
			rect_vx = rand() / float(RAND_MAX) * 4 - 7; //设置方块随机速度
		}

		//判断球体是否碰到了方块
		if (rect_left_x <= ball_x + radius && rect_left_x + rect_width >= ball_x - radius && rect_top_y <= ball_y + radius)
		{
			score = 0; //得分清零
			Sleep(100);
		}

		cleardevice(); //清屏函数

		//画球体
		fillcircle(ball_x, ball_y, radius);

		//画方块
		fillrectangle(rect_left_x, height - rect_height, rect_left_x + rect_width, height);

		//显示得分
		TCHAR s[20]; //定义字符串数组
		swprintf_s(s, _T("%d"), score); //将score转换为字符串
		settextstyle(40, 0, _T("宋体")); //设置文字大小，字体
		outtextxy(50, 30, s); //输出得分文字

		Sleep(10); //设置速度
	}
	closegraph();
	return 0;
}
