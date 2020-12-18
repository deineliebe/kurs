#include <iostream>
#include <cmath>
#include <chrono>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <string>



//First block

int byte_plus(int number);
int byte_minus(int number);
void first_task();
void second_task(int number);
void third_task(float number);
void forth_task(double number);
void first_main();



int byte_plus(int number)
{
    int dec = 1;
    bool check = 1;
    int save = number;
    while (check)
    {
        if (save % 10 == 0)
        {
            check = 0;
            number += dec;
        }
        else
        {
            number -= dec;
        }
        dec *= 10;
        save /= 10;
    }
    return number;
}

int byte_minus(int number)
{
    int dec = 1;
    bool check = 1;
    int save = number;
    while (check)
    {
        if (save % 10 == 0)
        {
            number += dec;
        }
        else
        {
            check = 0;
            number -= dec;
        }
        dec *= 10;
        save /= 10;
    }
    return number;
}

void first_task()
{
    std::cout << "\nYou choose first task!\n";
    std::cout << "First task: Write out v of memory (in bytes) on your computer for different types of data: int, short int, long int, float, double, long double, char и bool.\n";
    std::cout << "In type int " << sizeof(int) << " bytes.\n";
    std::cout << "In type short int " << sizeof(short int) << " bytes.\n";
    std::cout << "In type long int " << sizeof(long int) << " bytes.\n";
    std::cout << "In type float " << sizeof(float) << " bytes.\n";
    std::cout << "In type double " << sizeof(double) << " bytes.\n";
    std::cout << "In type long double " << sizeof(long double) << " bytes.\n";
    std::cout << "In type char " << sizeof(char) << " byte.\n";
    std::cout << "In type bool " << sizeof(bool) << " byte.\n";
}

void second_task(int number)
{
    unsigned int two_in_degree = 1073741824;
    int sign_number, cnt;
    if (number < 0)
    {
        sign_number = 1;
        number *= (-1);
    }
    else
    {
        sign_number = 0;
    }
    int save = number;
    cnt = 0;
    std::cout << sign_number << ' ';
    while (two_in_degree)
    {
        cnt += 1;
        if (cnt % 8 == 0)
        {
            std::cout << ' ';
        }
        if (number >= two_in_degree)
        {
            std::cout << 1;
        }
        else
        {
            std::cout << 0;
        }
        number %= two_in_degree;
        two_in_degree /= 2;
    }
    if (sign_number == 1)
    {
        cnt = 0;
        number = save;
        std::cout << "\nReverse code: " << sign_number << ' ';
        two_in_degree = 1073741824;
        while (two_in_degree)
        {
            cnt += 1;
            if (cnt % 8 == 0)
            {
                std::cout << ' ';
            }
            if (number >= two_in_degree)
            {
                std::cout << 0;
            }
            else
            {
                std::cout << 1;
            }
            number %= two_in_degree;
            two_in_degree /= 2;
        }
        two_in_degree = 1073741824;
        cnt = 0;
        number = save - 1;
        std::cout << "\nAdd code: " << sign_number << ' ';
        while (two_in_degree)
        {
            cnt += 1;
            if (cnt % 8 == 0)
            {
                std::cout << ' ';
            }
            if (number >= two_in_degree)
            {
                std::cout << 0;
            }
            else
            {
                std::cout << 1;
            }
            number %= two_in_degree;
            two_in_degree /= 2;
        }
    }
    std::cout << '\n';
}

void third_task(float number)
{
    unsigned int order;
    int sign_number, cnt;
    int d_cnt = 1;
    if (number < 0)
    {
        sign_number = 1;
        number *= (-1);
    }
    else
    {
        sign_number = 0;
    }
    cnt = 0;
    float save = number;
    order = 1111111;
    std::cout << sign_number << ' ';
    if (number >= 1)
    {
        while (save >= 1)
        {
            cnt += 1;
            save /= 2;
            order = byte_plus(order);
        }
        cnt -= 1;
    }
    else
    {
        while ((save < 1) and (order > 0))
        {
            cnt -= 1;
            save *= 2;
            order = byte_minus(order);
        }
    }
    int dec = 10000000;
    while (order < dec)
    {
        std::cout << 0;
        dec /= 10;
    }
    std::cout << order << ' ';
    float z_part = floor(number);
    float d_part = number - z_part;
    float two_in_degree = 1;
    d_cnt = 0;
    while ((two_in_degree * 2) <= z_part)
    {
        two_in_degree *= 2;
    }
    z_part -= two_in_degree;
    two_in_degree /= 2;
    while ((two_in_degree >= 1) and (d_cnt < 23))
    {
        if (z_part >= two_in_degree)
        {
            std::cout << 1;
            z_part -= two_in_degree;
        }
        else
        {
            std::cout << 0;
        }
        d_cnt += 1;
        two_in_degree /= 2;
    }
    if (d_cnt != 0)
    {
        std::cout << ' ';
    }
    if (cnt < 0)
    {
        while (d_part < 1 and cnt < 0)
        {
            cnt += 1;
            d_part *= 2;
        }
        cnt = 0;
        if (d_part >= 1)
        {
            d_part -= 1;
        }
    }
    d_cnt += 9;
    while (d_cnt < 32)
    {
        d_part *= 2;
        if (d_part >= 1)
        {
            std::cout << 1;
            d_part -= 1;
        }
        else
        {
            std::cout << 0;
        }
        d_cnt += 1;
    }
    std::cout << '\n';
}

void forth_task(double number)
{
    int order[11] = { 0,1,1,1,1,1,1,1,1,1,1 };
    int sign_number, cnt;
    int d_cnt = 11;
    if (number < 0)
    {
        sign_number = 1;
        number *= (-1);
    }
    else
    {
        sign_number = 0;
    }
    cnt = 0;
    double save = number;
    std::cout << sign_number << ' ';
    if (number >= 1)
    {
        while (save >= 1)
        {
            cnt += 1;
            save /= 2;
            bool check = 1;
            d_cnt = 10;
            while (check)
            {
                if (order[d_cnt] == 0)
                {
                    order[d_cnt] = 1;
                    check = 0;
                }
                else
                {
                    order[d_cnt] = 0;
                }
                d_cnt -= 1;
            }
        }
        cnt -= 1;
    }
    else
    {
        while ((save < 1) and (order > 0))
        {
            cnt -= 1;
            save *= 2;
            bool check = 1;
            d_cnt = 10;
            while (check)
            {
                if (order[d_cnt] == 0)
                {
                    order[d_cnt] = 1;
                }
                else
                {
                    order[d_cnt] = 0;
                    check = 0;
                }
                d_cnt -= 1;
            }
        }
    }
    d_cnt = 1;
    int dec = 100000000;
    for (int i = 0; i < 11; i++)
    {
        std::cout << order[i];
    }
    std::cout << ' ';
    double z_part = floor(number);
    double d_part = number - z_part;
    double two_in_degree = 1;
    d_cnt = 0;
    while ((two_in_degree * 2) <= z_part)
    {
        two_in_degree *= 2;
    }
    z_part -= two_in_degree;
    two_in_degree /= 2;
    while ((two_in_degree >= 1) and (d_cnt < 52))
    {
        if (z_part >= two_in_degree)
        {
            std::cout << 1;
            z_part -= two_in_degree;
        }
        else
        {
            std::cout << 0;
        }
        d_cnt += 1;
        two_in_degree /= 2;
    }
    if (d_cnt != 0)
    {
        std::cout << ' ';
    }
    if (cnt < 0)
    {
        while (d_part < 1 and cnt < 0)
        {
            cnt += 1;
            d_part *= 2;
        }
        cnt = 0;
        if (d_part >= 1)
        {
            d_part -= 1;
        }
    }
    d_cnt += 9;
    while (d_cnt < 61)
    {
        d_part *= 2;
        if (d_part >= 1)
        {
            std::cout << 1;
            d_part -= 1;
        }
        else
        {
            std::cout << 0;
        }
        d_cnt += 1;
    }
    std::cout << '\n';
}

void first_main()
{
    std::cout << "Hello!\n";
    int number;
    int int_num;
    float float_num;
    double double_num;
    number = 7;
    std::cout << "\n1) Write v of memory (in bytes) on your computer for different types of data: int, short int, long int, float, double, long double, char и bool.\n";
    std::cout << "2) Write all orders of integer number.\n";
    std::cout << "3) Write all orders of float number\n";
    std::cout << "4) Write all orders of double number\n";
    std::cout << "0) Exit.\n";
    try {
        while (number != 0)
        {
            std::cout << "\nWrite number: ";
            std::cin >> number;
            if (!std::cin)
            {
                throw "ex";
            }
            std::cout << '\n';
            switch (number)
            {
            case 1: first_task();
                break;
            case 2: std::cout << "\nYou choose second task!\n";
                std::cout << "Write all orders of intenger number.\n";
                std::cout << "Write number: ";
                std::cin >> int_num;
                second_task(int_num);
                if (!std::cin)
                {
                    throw "ex";
                }
                break;
            case 3: std::cout << "\nYou choose third task!\n";
                std::cout << "Write all orders of float number.\n";
                std::cout << "Write number: ";
                std::cin >> float_num;
                third_task(float_num);
                if (!std::cin)
                {
                    throw "ex";
                }
                break;
            case 4: std::cout << "\nYou choose forth task!\n";
                std::cout << "Write all orders of double number.\n";
                std::cout << "Write number: ";
                std::cin >> double_num;
                if (!std::cin)
                {
                    throw "ex";
                }
                forth_task(double_num);
                break;
            }
        }
    }
    catch (...)
    {
        std::cout << "\nWrong data!\n";
    }
}



//Second block

void quick_sort(int* arr, int start, int finish);
int left_binary(int* arr, int number);
int right_binary(int* arr, int number);
int brute_force(int* arr, int check, int number);
void fill_array(int* first_arr, int* second_arr);
int max_min(int* arr, bool check);
void show_array(int* arr);
void dop_task(int* arr, int* s_arr);
int second_main();



void quick_sort(int* arr, int start, int finish)
{
    int arr_s = start;
    int arr_f = finish;
    short int t;
    int mid = arr[(arr_s + arr_f) / 2];
    while (arr_s < arr_f)
    {
        while (arr[arr_s] < mid)
        {
            arr_s++;
        }
        while (arr[arr_f] > mid)
        {
            arr_f--;
        }
        if (arr_s <= arr_f)
        {
            t = arr[arr_s];
            arr[arr_s] = arr[arr_f];
            arr[arr_f] = t;
            arr_s++;
            arr_f--;
        }
    }
    if (start < arr_f)
    {
        quick_sort(arr, start, arr_f);
    }
    if (arr_s < finish)
    {
        quick_sort(arr, arr_s, finish);
    }
}

int left_binary(int* arr, int number)
{
    int left = 0;
    int right = 99;
    int mid = (left + right) / 2;
    while (left != mid)
    {
        if (number <= arr[mid])
        {
            right = mid;
            mid = (left + right) / 2;
        }
        else
        {
            left = mid;
            mid = (left + right) / 2;
        }
    }
    if (number <= arr[0])
    {
        left--;
    }
    if (number > arr[99])
    {
        left++;
    }
    return left + 1;
}

int right_binary(int* arr, int number)
{
    int left = 0;
    int right = 99;
    int mid = (left + right) / 2;
    while (left != mid)
    {
        if (number < arr[mid])
        {
            right = mid;
            mid = (left + right) / 2;
        }
        else
        {
            left = mid;
            mid = (left + right) / 2;
        }
    }
    if (number < arr[0])
    {
        right--;
    }
    if (number >= arr[99])
    {
        right++;
    }
    return right;
}

int brute_force(int* arr, int check, int number)
{
    int cnt = 0;
    if (check == 1)
    {
        for (int i = 0; i < 100; i++)
        {
            if (arr[i] < number)
            {
                cnt += 1;
            }
        }
    }
    if (check == 2)
    {
        std::cout << "Indexes:";
        for (int i = 0; i < 100; i++)
        {
            if (arr[i] == number)
            {
                cnt += 1;
                std::cout << ' ' << i;
            }
        }
        std::cout << '\n';
    }
    if (check == 3)
    {
        for (int i = 0; i < 100; i++)
        {
            if (arr[i] > number)
            {
                cnt += 1;
            }
        }
    }
    if (check == 4)
    {
        for (int i = 0; i < 100; i++)
        {
            if (arr[i] == number)
            {
                cnt += 1;
            }
        }
    }
    return cnt;
}

void fill_array(int* first_arr, int* second_arr)
{
    bool sign_number;
    for (int i = 0; i < 100; i++)
    {
        sign_number = rand() % 2;
        if (sign_number)
        {
            first_arr[i] = rand() % 100;
        }
        else
        {
            first_arr[i] = (rand() % 100) * (-1);
        }
        second_arr[i] = first_arr[i];
    }
}

int max_min(int* arr, bool check = 0)
{
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < 100; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    if (!check)
    {
        std::cout << "min: " << min << ", max: " << max;
    }
    return (min + max) / 2;
}

void show_array(int* arr)
{
    int cnt = 0;
    for (int i = 0; i < 100; i++)
    {
        cnt++;
        std::cout << arr[i] << " ";
        if (cnt % 10 == 0)
        {
            std::cout << '\n';
        }
    }
    std::cout << '\n';
}

void dop_task(int* arr, int* s_arr)
{
    int i;
    for (i = 0; i < 99; i++)
    {
        arr[i] += arr[i + 1];
        s_arr[i] = arr[i];
    }
    arr[99] += arr[0];
    s_arr[99] = arr[99];
    show_array(arr);
    short int check = 100;
    int random_index;
    i = 0;
    while (i < 100)
    {
        random_index = (rand()) % 100;
        if (s_arr[random_index] != 1000)
        {
            arr[i] = s_arr[random_index];
            s_arr[random_index] = 1000;
            i++;
        }
    }
    for (i = 0; i < 100; i++)
    {
        s_arr[i] = arr[i];
    }
    show_array(arr);
    int cnt;
    for (i = 1; i < 10; i++)
    {
        cnt = 0;
        for (int j = 0; j < 100; j++)
        {
            if (arr[j] < 0)
            {
                if ((arr[j] * (-1)) % i == 0)
                {
                    cnt += 1;
                }
            }
            else
            {
                if (arr[j] % i == 0)
                {
                    cnt += 1;
                }
            }
        }
        std::cout << "Elements devides on " << i << ": " << cnt << '\n';
    }
}

int second_main()
{
    std::cout << "Hello!\n";
    int number = 9;
    std::cout << "\n1) Make array sie of N = 100. Elements of array become random numbers from -99 to 99.\n";
    std::cout << "2) Sort elements of array by quick sort(from the list to the biggest).Measure time by the chrono library.\n";
    std::cout << "3) Find minimum and maximum elements of array. Measure time of search in sorted and unsorted arrays by chrono.\n";
    std::cout << "4) Write middle number of minimum and maximum elements in array. Write indexes of all elements same with it and count them.\n";
    std::cout << "5) Count number of elements less than a (writen by user) in sorted array.\n";
    std::cout << "6) Count number of elements more than b (writen by user) in sorted array.\n";
    std::cout << "7) Write information about was number written by user in array or not. use binary search. Compary it speed with one's of linear search. (*)\n";
    std::cout << "8) Change places of array's elements (user writes indexes). Measure time by chrono.\n";
    std::cout << "9) Change every element by summ of itself and next element. Give tham random places. Write number of elements deviding on 1, 2, 3, 4, 5, 6, 7, 8, 9\n";
    std::cout << "0) Exit program.\n";
    bool if_arr = 0;
    short int if_sort = 0;
    int arr[100];
    int mid, a, b, cnt, temp;
    int s_arr[100];
    srand(static_cast<unsigned int>(time(0)));
    try {
        while (number != 0)
        {
            std::cout << "\nWrite number: ";
            std::cin >> number;
            if (!std::cin)
            {
                throw "ex";
            }
            std::cout << '\n';
            switch (number)
            {
            case 1: std::cout << "\n1) Make array sie of N = 100. Elements of array become random numbers from -99 to 99.\n";
                fill_array(arr, s_arr);
                show_array(arr);
                if_arr = 1;
                if_sort = 0;
                break;
            case 2:
            {
                std::cout << "\n2) Sort elements of array by quick sort(from the list to the biggest).Measure time by the chrono library.\n";
                if (!if_arr)
                {
                    fill_array(arr, s_arr);
                    show_array(arr);
                    if_arr = 1;
                }
                if_sort = 1;
                auto t_start = std::chrono::high_resolution_clock::now();
                quick_sort(arr, 0, 99);
                auto t_end = std::chrono::high_resolution_clock::now();
                std::chrono::duration< double > t_cnt = t_end - t_start;
                show_array(arr);
                std::cout << "\nНа сортировку ушло " << std::fixed << t_cnt.count() << " секунд\n";
                break;
            }
            case 3:
            {
                std::cout << "Find minimum and maximum elements of array. Measure time of search in sorted and unsorted arrays by chrono.\n";
                if (!if_arr)
                {
                    fill_array(arr, s_arr);
                    show_array(arr);
                    if_arr = 1;
                }
                if (!if_sort)
                {
                    quick_sort(arr, 0, 99);
                    if_sort = 1;
                }
                auto t_start = std::chrono::high_resolution_clock::now();
                max_min(s_arr);
                auto t_end = std::chrono::high_resolution_clock::now();
                std::chrono::duration< double > t_cnt = t_end - t_start;
                std::cout << "\nOn search min and max elements in unsorted array was taken " << std::fixed << t_cnt.count() << " seconds\n";
                t_start = std::chrono::high_resolution_clock::now();
                int min = arr[0];
                int max = arr[99];
                t_end = std::chrono::high_resolution_clock::now();
                t_cnt = t_end - t_start;
                std::cout << "\nOn search min and max elements in sorted array was taken " << std::fixed << t_cnt.count() << " seconds\n";
                break;
            }
            case 4:
                std::cout << "4) Write middle number of minimum and maximum elements in array. Write indexes of all elements same with it and count them.\n";
                if (!if_arr)
                {
                    fill_array(arr, s_arr);
                    show_array(arr);
                    if_arr = 1;
                }
                mid = max_min(arr, 1);
                std::cout << "Middle number of minimum and maximum elements in array is " << mid << ". Number of same elements is " << brute_force(arr, 2, mid) << ".\n";
                break;
            case 5:
                std::cout << "Count number of elements less than a (writen by user) in sorted array.\n";
                if (!if_arr)
                {
                    fill_array(arr, s_arr);
                    show_array(arr);
                    if_arr = 1;
                }
                if (!if_sort)
                {
                    quick_sort(arr, 0, 99);
                    show_array(arr);
                    if_sort = 1;
                }
                std::cout << "Write number: ";
                std::cin >> a;
                if (!std::cin)
                {
                    throw "ex";
                }
                std::cout << "Number of elements less than " << a << " is " << left_binary(arr, a) << ".\n";
                break;
            case 6:
                std::cout << "Count number of elements more than b (writen by user) in sorted array.\n";
                if (!if_arr)
                {
                    fill_array(arr, s_arr);
                    show_array(arr);
                    if_arr = 1;
                }
                if (!if_sort)
                {
                    quick_sort(arr, 0, 99);
                    show_array(arr);
                    if_sort = 1;
                }
                std::cout << "Write number: ";
                std::cin >> b;
                if (!std::cin)
                {
                    throw "ex";
                }
                std::cout << "Number of elements more than b " << b << " is " << 100 - right_binary(arr, b) << ".\n";
                break;
            case 7:
            {
                std::cout << "Write information about was number written by user in array or not. use binary search. Compary it speed with one's of linear search. (*)\n";
                if (!if_arr)
                {
                    fill_array(arr, s_arr);
                    show_array(arr);
                    if_arr = 1;
                }
                if (!if_sort)
                {
                    quick_sort(arr, 0, 99);
                    show_array(arr);
                    if_sort = 1;
                }
                std::cout << "Write number: ";
                std::cin >> a;
                if (!std::cin)
                {
                    throw "ex";
                }
                auto t_start = std::chrono::high_resolution_clock::now();
                cnt = right_binary(arr, a) - left_binary(arr, a);
                auto t_end = std::chrono::high_resolution_clock::now();
                std::chrono::duration< double > t_cnt = t_end - t_start;
                std::cout << "Number of elements same with " << a << " id " << cnt << ".\n";
                std::cout << "On binary search in sorted array was taken " << std::fixed << t_cnt.count() << " seconds\n";
                t_start = std::chrono::high_resolution_clock::now();
                brute_force(s_arr, 4, a);
                t_end = std::chrono::high_resolution_clock::now();
                t_cnt = t_end - t_start;
                std::cout << "On binary search in unsorted array was taken " << std::fixed << t_cnt.count() << " seconds\n";
                break;
            }
            case 8:
            {
                std::cout << "Change places of array's elements (user writes indexes). Measure time by chrono.\n";
                if (!if_arr)
                {
                    fill_array(arr, s_arr);
                    show_array(arr);
                    if_arr = 1;
                }
                std::cout << "Write two indexes of array: ";
                std::cin >> a >> b;
                if ((a < 0) or (a > 99) or (b < 0) or (b > 99))
                {
                    std::cout << "Indexes were written wrong. They must be integer numbers from 0 to 99";
                }
                else
                {
                    auto t_start = std::chrono::high_resolution_clock::now();
                    temp = arr[a];
                    arr[a] = arr[b];
                    arr[b] = temp;
                    auto t_end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration< double > t_cnt = t_end - t_start;
                    show_array(arr);
                    temp = s_arr[a];
                    s_arr[a] = s_arr[b];
                    s_arr[b] = temp;
                    std::cout << "On changig elements was taken " << std::fixed << t_cnt.count() << " seconds\n";
                }
                break;
            }
            case 9:
            {
                std::cout << "Change every element by summ of itself and next element. Give tham random places. Write number of elements deviding on 1, 2, 3, 4, 5, 6, 7, 8, 9\n";
                if (!if_arr)
                {
                    fill_array(arr, s_arr);
                    show_array(arr);
                    if_arr = 1;
                }
                dop_task(arr, s_arr);
            }
            }
        }
    }
    catch (...)
    {
        std::cout << "\nWrong data!\n";
    }
}



//Третий блок

void show_matrix(int* arr, int matrix_size);
void fill_like_snake(int arr[100], int matrix_size);
void spiral_filling(int* arr, short unsigned int matrix_size);
void circle_changing(int* arr, int matrix_size);
void cross_changing(int* arr, int matrix_size);
void vertical_changing(int* arr, int matrix_size);
void horizontal_changing(int* arr, int matrix_size);
void sort_matrix(int* arr, int matrix_size);
int third_main();



void show_matrix(int* arr, int matrix_size)
{
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            std::cout << arr[(i * matrix_size) + j] << ' ';
        }
        std::cout << '\n';
    }
}

void fill_like_snake(int arr[100], int matrix_size)
{
    int* ptr = arr;
    CONSOLE_SCREEN_BUFFER_INFO info_y;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info_y);
    int y_coord = info_y.dwCursorPosition.Y + 1;
    COORD position;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < matrix_size; i++)
    {
        if (!(i % 2))
        {
            for (int j = 0; j < matrix_size; j++)
            {
                *ptr = rand() % (matrix_size * matrix_size) + 1;
                position.X = i * 4;
                position.Y = y_coord + j;
                SetConsoleCursorPosition(hConsole, position);
                std::cout << *ptr;
                Sleep(150);
                ptr += matrix_size;
            }
            ptr -= matrix_size;
        }
        else
        {
            for (int j = (matrix_size - 1); j > -1; j--)
            {
                *ptr = rand() % (matrix_size * matrix_size) + 1;
                position.X = i * 4;
                position.Y = y_coord + j;
                SetConsoleCursorPosition(hConsole, position);
                std::cout << *ptr;
                Sleep(150);
                ptr -= matrix_size;
            }
            ptr += matrix_size;
        }
        ptr += 1;
    }
    position.X = 0;
    position.Y = y_coord + matrix_size;
    SetConsoleCursorPosition(hConsole, position);
}

void spiral_filling(int* arr, short unsigned int matrix_size)
{
    int* ptr = arr;
    CONSOLE_SCREEN_BUFFER_INFO info_y;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info_y);
    int y_coord = info_y.dwCursorPosition.Y + 1;
    COORD position;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < matrix_size / 2; i++)
    {
        for (int j = 0; j < (matrix_size - i * 2 - 1); j++)
        {
            *ptr = rand() % (matrix_size * matrix_size) + 1;
            position.X = (j + i) * 4;
            position.Y = y_coord + i;
            SetConsoleCursorPosition(hConsole, position);
            std::cout << *ptr;
            Sleep(150);
            ptr++;
        }
        for (int j = 0; j < (matrix_size - i * 2 - 1); j++)
        {
            *ptr = rand() % (matrix_size * matrix_size) + 1;
            position.X = (matrix_size - i - 1) * 4;
            position.Y = y_coord + (i + j);
            SetConsoleCursorPosition(hConsole, position);
            std::cout << *ptr;
            Sleep(150);
            ptr += matrix_size;
        }
        for (int j = (matrix_size - i * 2 - 1); j > 0; j--)
        {
            *ptr = rand() % (matrix_size * matrix_size) + 1;
            position.X = (i + j) * 4;
            position.Y = y_coord + matrix_size - 1 - i;
            SetConsoleCursorPosition(hConsole, position);
            std::cout << *ptr;
            Sleep(150);
            ptr--;
        }
        for (int j = (matrix_size - i * 2 - 1); j > 0; j--)
        {
            *ptr = rand() % (matrix_size * matrix_size) + 1;
            position.X = i * 4;
            position.Y = y_coord + (j + i);
            SetConsoleCursorPosition(hConsole, position);
            std::cout << *ptr;
            Sleep(150);
            ptr -= matrix_size;
        }
        ptr += matrix_size + 1;
    }
    position.X = 0;
    position.Y = y_coord + matrix_size;
    SetConsoleCursorPosition(hConsole, position);
}

void circle_changing(int* arr, int matrix_size)
{
    int temp;
    int* ptr = arr;
    for (int i = 0; i < (matrix_size / 2); i++)
    {
        for (int j = 0; j < (matrix_size / 2); j++)
        {
            temp = *(ptr + (i * matrix_size) + j);
            *(ptr + (i * matrix_size) + j) = *(ptr + ((i + matrix_size / 2) * matrix_size) + j);
            *(ptr + ((i + matrix_size / 2) * matrix_size) + j) = *(ptr + ((i + matrix_size / 2) * matrix_size) + j + (matrix_size / 2));
            *(ptr + ((i + matrix_size / 2) * matrix_size) + j + (matrix_size / 2)) = *(ptr + (i * matrix_size) + j + (matrix_size / 2));
            *(ptr + (i * matrix_size) + j + (matrix_size / 2)) = temp;
        }
    }
}

void cross_changing(int* arr, int matrix_size)
{
    int temp;
    int* ptr = arr;
    for (int i = 0; i < (matrix_size / 2); i++)
    {
        for (int j = 0; j < (matrix_size / 2); j++)
        {
            temp = *(ptr + (i * matrix_size) + j);
            *(ptr + (i * matrix_size) + j) = *(ptr + ((i + matrix_size / 2) * matrix_size) + j + (matrix_size / 2));
            *(ptr + ((i + matrix_size / 2) * matrix_size) + j + (matrix_size / 2)) = temp;
            temp = *(ptr + ((i + matrix_size / 2) * matrix_size) + j);
            *(ptr + ((i + matrix_size / 2) * matrix_size) + j) = *(ptr + (i * matrix_size) + j + (matrix_size / 2));
            *(ptr + (i * matrix_size) + j + (matrix_size / 2)) = temp;
        }
    }
}

void vertical_changing(int* arr, int matrix_size)
{
    int temp;
    int* ptr = arr;
    for (int i = 0; i < (matrix_size / 2); i++)
    {
        for (int j = 0; j < (matrix_size / 2); j++)
        {
            temp = *(ptr + (i * matrix_size) + j);
            *(ptr + (i * matrix_size) + j) = *(ptr + ((i + matrix_size / 2) * matrix_size) + j);
            *(ptr + ((i + matrix_size / 2) * matrix_size) + j) = temp;
            temp = *(ptr + (i * matrix_size) + j + (matrix_size / 2));
            *(ptr + (i * matrix_size) + j + (matrix_size / 2)) = *(ptr + ((i + matrix_size / 2) * matrix_size) + j + (matrix_size / 2));
            *(ptr + ((i + matrix_size / 2) * matrix_size) + j + (matrix_size / 2)) = temp;
        }
    }
}

void horizontal_changing(int* arr, int matrix_size)
{
    int temp;
    int* ptr = arr;
    for (int i = 0; i < (matrix_size / 2); i++)
    {
        for (int j = 0; j < (matrix_size / 2); j++)
        {
            temp = *(ptr + (i * matrix_size) + j);
            *(ptr + (i * matrix_size) + j) = *(ptr + (i * matrix_size) + j + (matrix_size / 2));
            *(ptr + (i * matrix_size) + j + (matrix_size / 2)) = temp;
            temp = *(ptr + ((i + matrix_size / 2) * matrix_size) + j);
            *(ptr + ((i + matrix_size / 2) * matrix_size) + j) = *(ptr + ((i + matrix_size / 2) * matrix_size) + j + (matrix_size / 2));
            *(ptr + ((i + matrix_size / 2) * matrix_size) + j + (matrix_size / 2)) = temp;
        }
    }
}

void sort_matrix(int* arr, int matrix_size)
{
    int* ptr1 = arr;
    int* ptr2 = arr + 1;
    int temp;
    for (int i = 0; i < (matrix_size * matrix_size - 1); i++)
    {
        for (int j = i + 1; j < (matrix_size * matrix_size); j++)
        {
            if (*ptr1 > * ptr2)
            {
                temp = *ptr1;
                *ptr1 = *ptr2;
                *ptr2 = temp;
            }
            ptr2++;
        }
        ptr1++;
        ptr2 = ptr1 + 1;
    }
    show_matrix(arr, matrix_size);
}

int third_main()
{
    std::cout << "Привет!\n";
    int number = 5;
    srand(time(NULL));
    std::cout << "\n1. Используя арифметику указателей, заполнить квадратичную целочисленную матрицу порядка N (6,8,10) случайными числами от 1 до  N*N по двум схемам.\n";
    std::cout << "2. Получить новую матрицу, из матрицы п. 1, переставляя ее блоки в соответствии с четырьмя схемами.\n";
    std::cout << "3. Используя арифметику указателей, отсортировать элементы любой сортировкой.\n";
    std::cout << "4. Уменьшает, увеличивает, умножает или делит все элементы матрицы на введенное пользователем число.\n";
    std::cout << "0. Завершить программу.\n";
    bool if_arr, filling_method;
    int arr[100];
    if_arr = 0;
    int matrix_size, change_number, operation_number;
    try {
        while (!if_arr)
        {
            std::cout << "\n1. Используя арифметику указателей, заполнить квадратичную целочисленную матрицу порядка N (6,8,10) случайными числами от 1 до  N*N по двум схемам.\n";
            std::cout << "Выберите число: 6, 8, 10: ";
            std::cin >> matrix_size;
            if (!std::cin) throw "ex";
            if ((matrix_size == 6) or (matrix_size == 8) or (matrix_size == 10))
            {
                std::cout << "Нажмите 0, если хотите вывести матрицу спиралью, 1 - если змейкой: ";
                std::cin >> filling_method;
                if (!std::cin) throw "ex";
                if (filling_method) fill_like_snake(arr, matrix_size);
                else spiral_filling(arr, matrix_size);
                if_arr = 1;
            }
            else
            {
                std::cout << "Вы ввели некорректное число\n";
            }
        }
        while (number != 0)
        {
            std::cout << "\nВыбери номер: ";
            std::cin >> number;
            if (!std::cin)
            {
                throw "ex";
            }
            std::cout << '\n';
            switch (number)
            {
            case 1: std::cout << "\n1. Используя арифметику указателей, заполнить квадратичную целочисленную матрицу порядка N (6,8,10) случайными числами от 1 до  N*N по двум схемам.\n";
                std::cout << "Выберите число: 6, 8, 10: ";
                std::cin >> matrix_size;
                if (!std::cin) throw "ex";
                if ((matrix_size == 6) or (matrix_size == 8) or (matrix_size == 10))
                {
                    std::cout << "Нажмите 0, если хотите вывести матрицу спиралью, 1 - если змейкой: ";
                    std::cin >> filling_method;
                    if (!std::cin) throw "ex";
                    if (filling_method)
                    {
                        fill_like_snake(arr, matrix_size);
                    }
                    else
                    {
                        spiral_filling(arr, matrix_size);
                    }
                }
                else
                {
                    std::cout << "Вы ввели некорректное число\n";
                }
                break;
            case 2: "\n2. Получить новую матрицу, из матрицы п. 1, переставляя ее блоки в соответствии с четырьмя схемами.\n";
                std::cout << "Выберите метод перестановки: по кругу (a) - 1, крестом (b) - 2, по вертикали (c) - 3, по горизонтали (d) - 4: ";
                std::cin >> change_number;
                if (!std::cin) throw "ex";
                switch (change_number)
                {
                case 1: circle_changing(arr, matrix_size);
                    show_matrix(arr, matrix_size);
                    break;
                case 2: cross_changing(arr, matrix_size);
                    show_matrix(arr, matrix_size);
                    break;
                case 3: vertical_changing(arr, matrix_size);
                    show_matrix(arr, matrix_size);
                    break;
                case 4: horizontal_changing(arr, matrix_size);
                    show_matrix(arr, matrix_size);
                    break;
                default:
                    std::cout << "Неккоректное значение\n";
                    break;
                }
                break;
            case 3: std::cout << "3. Используя арифметику указателей, отсортировать элементы любой сортировкой.\n";
                sort_matrix(arr, matrix_size);
                break;
            case 4: std::cout << "4. Уменьшает, увеличивает, умножает или делит все элементы матрицы на введенное пользователем число.\n";
                std::cout << "Выберите операцию: уменьшить - 1, увеличить - 2, умножить - 3, поделить - 4: ";
                std::cin >> change_number;
                if (!std::cin) throw "ex";
                switch (change_number)
                {
                case 1:
                    std::cout << "Выберите число: ";
                    std::cin >> operation_number;
                    if (!std::cin) throw "ex";
                    for (int i = 0; i < (matrix_size * matrix_size); i++)
                    {
                        arr[i] -= operation_number;
                    }
                    show_matrix(arr, matrix_size);
                    break;
                case 2:
                    std::cout << "Выберите число: ";
                    std::cin >> operation_number;
                    if (!std::cin) throw "ex";
                    for (int i = 0; i < (matrix_size * matrix_size); i++)
                    {
                        arr[i] += operation_number;
                    }
                    show_matrix(arr, matrix_size);
                    break;
                case 3:
                    std::cout << "Выберите число: ";
                    std::cin >> operation_number;
                    if (!std::cin) throw "ex";
                    for (int i = 0; i < (matrix_size * matrix_size); i++)
                    {
                        arr[i] *= operation_number;
                    }
                    show_matrix(arr, matrix_size);
                    break;
                case 4:
                    std::cout << "Выберите число: ";
                    std::cin >> operation_number;
                    if (!std::cin) throw "ex";
                    if (operation_number == 0) throw "ex";
                    for (int i = 0; i < (matrix_size * matrix_size); i++)
                    {
                        arr[i] /= operation_number;
                    }
                    show_matrix(arr, matrix_size);
                    break;
                default: std::cout << "Неккоректное значение\n";
                    break;
                }
                break;
            }
        }
    }
    catch (...)
    {
        std::cout << "\nНекорректные данные!\n";
    }
}



//Четвёртый блок
void show_sentence(char sentence[][14], int len);
void delete_sentence(char sentence[][14], int len);
void show_sentence_from_last_elem(char sentence[][14], int len);
void check_elem_sign(char* word, int len_word);
void check_elem_letter(char* word, int len_word);
void check_first_letters(char sentence[][14], int len);
int fill_string(char sentence[][14]);
int fill_string_from_file(char sentence[][14]);
void linear_search(char sentence[][14], int len, std::string x);
int find_index(char letter, std::string x);
int find_len(char word[]);
bool boyer_mur_word(char word[], int i, std::string x);
void boyer_mur(char sentence[][14], int len, std::string x);
int forth_main();



void show_sentence(char sentence[][14], int len)
{
    int j;
    for (int i = 0; i < len; i++)
    {
        j = 0;
        while (sentence[i][j] != NULL)
        {
            std::cout << sentence[i][j];
            j += 1;
        }
        std::cout << ' ';
    }
    std::cout << '\n';
}

void delete_sentence(char sentence[][14], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            sentence[i][j] = NULL;
        }
    }
}

void show_sentence_from_last_elem(char sentence[][14], int len)
{
    int j;
    for (int i = len - 1; i > -1; i--)
    {
        j = 0;
        while (sentence[i][j] != NULL)
        {
            std::cout << sentence[i][j];
            j += 1;
        }
        std::cout << ' ';
    }
    std::cout << '\n';
}

void check_elem_sign(char* word, int len_word)
{
    int cnt = 0;
    int i = 0;
    while (word[i] != NULL)
    {
        if (!(((((int)(word[i]) > 64) and (int)(word[i]) < 91)) or (((int)(word[i]) > 96) and ((int)(word[i]) < 123))) or ((int)(word[i]) > 47 and (int)(word[i]) < 58)) cnt += 1;
        else cnt = 0;
        if ((cnt == 2 and word[i + 1] != '.') or (cnt > 3)) word[i] = NULL;
        i += 1;
    }
}

void check_elem_letter(char* word, int len_word)
{
    for (int i = 1; i < len_word; i++)
    {
        if (((int)(word[i]) > 64) and ((int)(word[i]) < 91))
        {
            word[i] = (char)((int)(word[i]) + 32);
        }
    }
}

void check_first_letters(char sentence[][14], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (((int)(sentence[i][0]) > 64) and ((int)(sentence[i][0]) < 91))
        {
            sentence[i][0] = (char)((int)(sentence[i][0]) + 32);
        }
    }

    show_sentence(sentence, len);
}

int fill_string(char sentence[][14])
{
    bool check = 1;
    std::string temp;
    int len = 0;
    int check_cnt = 0;
    while (check and len < 49)
    {
        std::cin >> temp;
        if (temp.size() < 14)
        {
            for (int i = 0; i < temp.size(); i++)
            {
                sentence[len - check_cnt][i] = temp[i];
            }
        }
        else check_cnt += 1;
        if (temp[temp.size() - 1] == '.') check = 0;
        check_elem_letter(sentence[len], temp.size());
        check_elem_sign(sentence[len], temp.size());
        len += 1;
    }
    if (check_cnt)
    {
        std::cout << "\nWas " << check_cnt << " wrong words\n";
    }
    return len;
}

int fill_string_from_file(char sentence[][14])
{
    int len = 0;
    std::ifstream fin("fin.txt");
    if (fin.is_open())
    {
        bool check = 1;
        std::string temp;
        int check_cnt = 0;
        while (check and len < 49)
        {
            fin >> temp;
            if (temp.size() < 14)
            {
                for (int i = 0; i < temp.size(); i++)
                {
                    sentence[len - check_cnt][i] = temp[i];
                }
            }
            else check_cnt += 1;
            if (temp[temp.size() - 1] == '.') check = 0;
            check_elem_letter(sentence[len], temp.size());
            check_elem_sign(sentence[len], temp.size());
            len += 1;
        }
        if (check_cnt)
        {
            std::cout << "\nWas " << check_cnt << " wrong words\n";
        }
        fin.close();
    }
    else
    {
        std::cout << "\nWas file fin.txt opened?\n";
    }
    return len;
}

void linear_search(char sentence[][14], int len, std::string x)
{
    int check = 0;
    int i = 0;
    int j, save_i;
    while (check < x.size() and i < len)
    {
        j = 0;
        check = 0;
        while (check < x.size() and sentence[i][j] != NULL)
        {
            if (sentence[i][j] == x[check]) check++;
            else check = 0;
            j++;
        }
        i++;
    }
    if (check < x.size()) std::cout << "String you write wasn't in the main string\n";
    else std::cout << "String was found\n";
}

int find_index(char letter, std::string x)
{
    int i = x.size() - 1;
    while ((x[i] != letter) and (i > 1)) i--;
    return i;
}

int find_len(char word[])
{
    int len = 1;
    while (word[len] != NULL) len++;
    return len;
}

bool boyer_mur_word(char word[], int i, std::string x)
{
    int check = 0;
    int save;
    bool check_not_el = 1;
    int len = find_len(word);
    int index;
    while (check < (x.size() - 1) and i < len)
    {
        check = 0;
        save = i;
        index = find_index(word[i], x);
        while ((check < index) and (word[save] == x[index - check]))
        {
            save--;
            check++;
        }
        save = i + 1;
        while ((save < (len - 1)) and (word[save] == x[check + 1]))
        {
            save++;
            check++;
        }
        if (check < (x.size() - 1)) i += x.size();
        else check_not_el = 0;
    }
    return check_not_el;
}

void boyer_mur(char sentence[][14], int len, std::string x)
{
    int i = 0;
    int j = 0;
    bool check = 1;
    while (check and i < len)
    {
        while ((i < len) and (x.size() > find_len(sentence[i]))) i++;
        if (i < len) check = boyer_mur_word(sentence[i], x.size() - 1, x);
        i++;
    }
    if (!check) std::cout << "String was found\n";
    else std::cout << "String you write wasn't in the main string\n";
}

int forth_main()
{
    std::cout << "Hi!\n";
    std::string x;
    char sentence[50][14];
    int len = 50;
    bool change = 1;
    try
    {
        while (change != 0)
        {
            delete_sentence(sentence, len);
            len = 0;
            std::cout << "\nIf you want to use file, write 0. If you want to write from console, write 1: ";
            std::cin >> change;
            if (!std::cin) throw("ex");
            std::cout << "\nWrite sentence of words. After the last word write dot\n";
            if (change) len = fill_string(sentence);
            else len = fill_string_from_file(sentence);
            if (len)
            {
                std::cout << "\nSentence after correcting:\n";
                show_sentence(sentence, len);
                std::cout << "\nSentence in reverse order:\n";
                show_sentence_from_last_elem(sentence, len);
                std::cout << "\nSentence after making first letters small:\n";
                check_first_letters(sentence, len);
                std::cout << "\nWrite word for search:\n";
                std::cin >> x;
                if (!std::cin) throw("ex");
                if (x.size() < 14)
                {
                    std::cout << "\nLinear search:\n";
                    linear_search(sentence, len, x);
                    std::cout << "\nBoyer–Moore string-search algorithm:\n";
                    boyer_mur(sentence, len, x);
                }
                else std::cout << "String you write wasn't in the main string\n";
            }
            std::cout << "\nIf you want to continue, write 1. If you want to exit, write 0: ";
            std::cin >> change;
            if (!std::cin) throw("ex");
        }
    }
    catch (...)
    {
        std::cout << "\nWrong data!\n";
    }
}



//Выбор



int main()
{
	int number = 5;
    setlocale(LC_ALL, "Russian");
	try
	{
		while (number)
		{
			std::cout << "Write 1, 2, 3 or 4: 1 - for work with bytes, 2 - for work with sort, 3 - for work with arrays, 4 - for work with strings, 0 - to exit: ";
			std::cin >> number;
			if (!std::cin) throw ("ex");
            switch (number)
            {
            case 1: first_main();
                break;
            case 2: second_main();
                break;
            case 3: third_main();
                break;
            case 4: forth_main();
                break;
            }
		}
	}
	catch (...)
	{
        std::cout << "Wrong data!";
	}
}
