#pragma once
#include <iostream>

using namespace std;

class MinHeaps
{
public:	
	int Arr[100];
	int Size = 0;

public:
	MinHeaps() { fill_n(Arr, 100, INT_MIN); }

	void Add(int data)
	{
		auto currentIndex = 0;
		if (Size < sizeof(Arr) / sizeof(int))
		{
			Arr[Size] = data;
			currentIndex = Size;
			Size++;
		}
		else
		{
			return;
		}		

		while (true)
		{
			if (currentIndex == 0)
				return;

			if (Arr[currentIndex] < Arr[(currentIndex + 1) / 2 - 1])
			{
				if (Arr[currentIndex] == Arr[(currentIndex + 1) / 2 - 1])
					return;

				auto temp = Arr[currentIndex];
				Arr[currentIndex] = Arr[(currentIndex + 1) / 2 - 1];
				Arr[(currentIndex + 1) / 2 - 1] = temp;

				currentIndex = (currentIndex + 1) / 2 - 1;
			}
			else
			{
				return;
			}
		}
	}

	int ExtractMin()
	{
		if (Size == 0)
			return INT_MIN;

		auto result = Arr[0];		
		Arr[0] = Arr[Size - 1];
		Arr[Size - 1] = INT_MIN;

		auto currentIndex = 0;

		while (true)
		{
			if (currentIndex >= sizeof(Arr) / sizeof(int) / 2 - 1)
				break;

			if (Arr[(currentIndex + 1) * 2 - 1] == INT_MIN && Arr[(currentIndex + 1) * 2] == INT_MIN)
			{
				break;
			}
			else if (Arr[(currentIndex + 1) * 2 - 1] == INT_MIN) // ���� �ڽ��� ������� -> �������ڽİ� ��ȯ
			{
				if (Arr[currentIndex] > Arr[(currentIndex + 1) * 2])
				{
					auto temp = Arr[currentIndex];
					Arr[currentIndex] = Arr[(currentIndex + 1) * 2];
					Arr[(currentIndex + 1) * 2] = temp;

					currentIndex = (currentIndex + 1) * 2;
				}
				else
				{
					break;
				}
			}
			else if (Arr[(currentIndex + 1) * 2] == INT_MIN) // ������ �ڽ��� ������� -> �����ڽİ� ��ȯ
			{
				if (Arr[currentIndex] > Arr[(currentIndex + 1) * 2 - 1])
				{
					auto temp = Arr[currentIndex];
					Arr[currentIndex] = Arr[(currentIndex + 1) * 2 - 1];
					Arr[(currentIndex + 1) * 2 - 1] = temp;

					currentIndex = (currentIndex + 1) * 2 - 1;
				}
				else
				{
					break;
				}
			}
			else // �ڽ��� ���϶� -> �ڽ� ���� ��Ұ��� ���� �����Ͱ� ��ȯ
			{
				if (Arr[(currentIndex + 1) * 2 - 1] < Arr[(currentIndex + 1) * 2]) // ���� �ڽ��� �� �������
				{
					if (Arr[currentIndex] > Arr[(currentIndex + 1) * 2 - 1])
					{
						auto temp = Arr[currentIndex];
						Arr[currentIndex] = Arr[(currentIndex + 1) * 2 - 1];
						Arr[(currentIndex + 1) * 2 - 1] = temp;

						currentIndex = (currentIndex + 1) * 2 - 1;
					}
					else
					{
						break;
					}
				}
				else // ������ �ڽ��� �� ���� ���
				{
					if (Arr[currentIndex] > Arr[(currentIndex + 1) * 2])
					{
						auto temp = Arr[currentIndex];
						Arr[currentIndex] = Arr[(currentIndex + 1) * 2];
						Arr[(currentIndex + 1) * 2] = temp;

						currentIndex = (currentIndex + 1) * 2;
					}
					else
					{
						break;
					}
				}
			}
		}		

		Size--;
		return result;
	}

	void Clear()
	{
		auto result = ExtractMin();

		while (result != INT_MIN)
		{
			cout << result << endl;
			result = ExtractMin();
		}		
	}
};

