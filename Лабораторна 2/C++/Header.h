#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

struct date;
struct employee;

void input_file(string);
void output_file(string);
void birthday_in_this_month(string);
void create_second_file(string, string);
template <typename T1, typename T2>
int get_years_between_dates(T1, T2);
date get_system_date();
vector<string> split(string, char);