#pragma once
#include <functional>
#include <iostream>
#include <vector>
#include <string>
#ifndef SORT_H
#define SORT_H

#include "list.h"

List<int> myList;
void Ascending(const int& i) {}//¸‡event1
void Descending(const int& j) {}//~‡event2
using event_handler_t = std::function<void(const std::string&)>;
bool up = false;
bool down = false;

int main()
{
	int i, j;
	int k = 5;//‰¼“ü—ÍList‚Ìsizeg—p
	for (int i = 0;i < k;i++)
	{
		for (j = k;j > i;j--)
		{
			if (up == true)
			{
				Ascending();
			}
			else if (down == true)
			{
				Descending();
			}

		}
	}




};
#endif