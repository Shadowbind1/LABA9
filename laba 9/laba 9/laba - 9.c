#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <windows.h>


int main(void)
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, ".UTF - 8");
    int choice;
    char continue_work = 'y';

    do
    {
        printf("\n========== ЛАБОРАТОРНАЯ РАБОТА 9 (вариант 4) ==========\n");
        printf("1. Таблица умножения + треугольники\n");
        printf("2. Количество цифр, больших 5\n");
        printf("3. Рисование прямоугольного треугольника\n");
        printf("0. Выход\n");
        printf("Выберите задание: ");
        scanf("%d", &choice);

        /* Очистка буфера после scanf */
        while (getchar() != '\n');

        switch (choice)
        {

        case 1:
        {
            int i, j;

            printf("\n--- 1. Полная таблица умножения ---\n\n");
            for (i = 1; i <= 10; i++)
            {
                for (j = 1; j <= 10; j++)
                    printf("%4d", i * j);
                printf("\n");
            }

            printf("\n--- 2. Левый нижний треугольник ---\n\n");
            for (i = 1; i <= 10; i++)
            {
                for (j = 1; j <= i; j++)
                    printf("%4d", i * j);
                printf("\n");
            }

            printf("\n--- 3. Индивидуальный вывод (вариант 4) ---\n\n");

            int num = 1;
            for (i = 1; i <= 7; i++)
            {
                for (j = 1; j <= i; j++)
                {
                    printf("%4d", num);
                    num++;
                }
                printf("\n");
            }
            break;
        }

        case 2:
        {
            long long number;
            printf("\nВведите целое число: ");
            scanf("%lld", &number);

            if (number < 0)
                number = -number;

            int count = 0;
            long long temp = number;

            if (temp == 0)
            {
                count = 0;
            }
            else
            {
                while (temp > 0)
                {
                    int digit = temp % 10;
                    if (digit > 5)
                        count++;
                    temp /= 10;
                }
            }

            printf("Количество цифр, больших 5: %d\n", count);
            while (getchar() != '\n');   /* очистка буфера */
            break;
        }

        case 3:
        {
            int R;
            char symbol;

            printf("\nВведите длину катета R: ");
            scanf("%d", &R);
            printf("Введите символ для рисования: ");
            scanf(" %c", &symbol);

            printf("\nПрямоугольный треугольник (заполненный):\n\n");
            for (int i = 1; i <= R; i++)
            {
                for (int j = 1; j <= i; j++)
                    printf("%c ", symbol);
                printf("\n");
            }
            while (getchar() != '\n');
            break;
        }

        case 0:
            continue_work = 'n';
            break;

        default:
            printf("Неверный выбор!\n");
            break;
        }

        if (choice != 0)
        {
            printf("\nПродолжить работу с программой? (y/n): ");
            continue_work = getchar();
            while (getchar() != '\n');
        }

    } while (continue_work == 'y' || continue_work == 'Y');

    printf("\nРабота завершена.\n");
    return 0;
}