#include "pch.h" 
#include <iostream> 
#include <windows.h> 
#include <stdio.h> 

enum Status
{
	Idle = 0,
	DeliveryBottle = 1,
	CleaningBottle = 2,
	ChooseMilk = 3,
	DeliveryBottleWithMilk = 4
};

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	Status state = Idle;
	int action = 0;
	int count = 0;
	while (true)
	{
		switch (state)
		{
		case Idle:
		{
			printf("Нажмите 1 для выдачи молока\n"); 
			scanf("%d", &action); 
			if (action == 1)
			{
				printf("Ожидайте бутылку\n"); 
				state = DeliveryBottle;
			}
			else
			{
				printf("Неверно выбранна команда\n"); 
			}
			action = 0;
		}
		break;
		case DeliveryBottle:
		{
			Sleep(1000);
			count++;
			printf("\nwww"+(4-count)); 
			if (count == 4)
			{
				
				printf("\nБутылка доставлена, начата отчистка\n"); 
				count = 0;
				state = CleaningBottle;
			}
		}
		break;
		case CleaningBottle:
		{
			Sleep(1000);
			count++;
			printf("\nfff" + (4 - count)); 
			if (count == 4)
			{
				printf("\nБутылка помыта\n"); 
				count = 0;
				state = ChooseMilk;
			}
		}
		break;
		case ChooseMilk:
		{
			printf("Выберите молоко:\n 1 - Коровье\n 2 - Козье\n 3 - Лошадинное\n 4 - Куринное \n"); 
			scanf("%d", &action); 
			switch (action)
			{
			case 1:
			case 2:
			case 3:
			case 4:
			{
				
				printf("\nМолоко наливается в бутылку \n"); 
				state = DeliveryBottleWithMilk;
			}
			break;
			default:
			
				printf("Такого молока нет "); 
				break;
			}
			action = 0;
		}
		break;
		case DeliveryBottleWithMilk:
		{
			Sleep(1000);
			count++;
			printf("" + (4 - count)); 
			if (count == 4)
			{
				printf("Получите \n"); 
				count = 0;
				state = Idle;
			}
		}
		break;
		}

	}
}