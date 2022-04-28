#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main()
{
	float width, height, gravity; //��Ϸ���棬�������ٶ�
	float ball_x, ball_y, ball_vy,radius; // С��Բ�����꣬y�����ٶȣ��뾶
	float rect_left_x, rect_top_y, rect_width, rect_height, rect_vx;// �����ϰ�

	width = 600;
	height = 400;
	gravity = 0.6;
	initgraph(width, height);
	radius = 20; //�뾶
	ball_x = width / 4; //С��x����
	ball_y = height - radius; // С��y����
	ball_vy = 0; //С������y�ٶ�

	rect_height = 100; //����߶�
	rect_width = 20; //����߶�
	rect_left_x = width * 3 / 4; //�������x����
	rect_top_y = height - rect_height; //���鶥��y����
	rect_vx = -3; //����x���ƶ��ٶ�

	int i;
	int isBallonFloor = 1; //�ж����Ƿ��ڵ���
	int score = 0; //����

	while (1)
	{
		if (_kbhit())
		{
			char input = _getch(); //��ȡ�ַ�
			if (input == 'w' && isBallonFloor == 1)
			{
				ball_vy = -16; //��С��һ�����ϵĳ�ʼ�ٶ�
				isBallonFloor = 0;
			}
		}

		//�����ƶ�
		ball_vy = ball_vy + gravity;
		ball_y = ball_y + ball_vy;

		//���崥��
		if (ball_y >= height - radius)
		{
			ball_vy = 0; //yֹͣ��Ծ
			ball_y = height - radius; //���⴩ģ
			isBallonFloor = 1;
		}

		//��������
		rect_left_x = rect_left_x + rect_vx; 
		if (rect_left_x < 0 - rect_width)
		{
			rect_left_x = width;

			score++; //�÷�+1

			rect_height = rand() % int(height / 4) + height / 4; //�������߶�
			rect_vx = rand() / float(RAND_MAX) * 4 - 7; //���÷�������ٶ�
		}

		//�ж������Ƿ������˷���
		if (rect_left_x <= ball_x + radius && rect_left_x + rect_width >= ball_x - radius && rect_top_y <= ball_y + radius)
		{
			score = 0; //�÷�����
			Sleep(100);
		}

		cleardevice(); //��������

		//������
		fillcircle(ball_x, ball_y, radius);

		//������
		fillrectangle(rect_left_x, height - rect_height, rect_left_x + rect_width, height);

		//��ʾ�÷�
		TCHAR s[20]; //�����ַ�������
		swprintf_s(s, _T("%d"), score); //��scoreת��Ϊ�ַ���
		settextstyle(40, 0, _T("����")); //�������ִ�С������
		outtextxy(50, 30, s); //����÷�����

		Sleep(10); //�����ٶ�
	}
	closegraph();
	return 0;
}