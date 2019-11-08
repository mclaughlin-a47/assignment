/*

* UUDate.cpp
*
* Version information
* Author: TODO - Add your name here
* Date: TODO - Add date you started working on the code
* Description: This file is the implementation file for the UUDate class and defines (implements) the functions of the class
*
* Copyright notice -
*/


#include "UUDate.h"

UUDate::UUDate() {
	//Initialise the date to 01/01/2000
	UUDate::SetYear(2000);
	UUDate::SetMonth(01);
	UUDate::SetDay(01);
}

UUDate::UUDate(int day, int month, int year) {
	SetYear(year);
	SetMonth(month);
	SetDay(day);

	if (validateDay(day) == false || validateMonth(month) == false || validateYr(year) == false) {
		SetYear(2000);
		SetMonth(1);
		SetDay(1);
	}

}

UUDate::UUDate(std::string date) { // 22/11/2002

	int a = (int)date.find("/");
	int b = (int)date.rfind("/");

	day_ = stoi(date.substr(0, a));
	month_ = stoi(date.substr(a + 1, b));
	year_ = stoi(date.substr(b+1, sizeof(date)-1));
}

int monthDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

void UUDate::IncrementDate() {
	//TODO - Add your implementation here
	day_++;
	if (day_ >= 31 || day_ == 30) {
		month_++;
		day_ = 1;
		year_++;
	
		while (month_ > 12) {
			month_ = 1;
		}
	}

	}

int UUDate::Between(UUDate date) {
	//TODO - Add your implementation here

	int num1 = year_ * 365 + day_;

	int num2 = date.year_ * 365 + date.day_;
	for (int i = 0; i < month_ - 1; i++) {
		num1 += monthDays[i];
	}
	num1 += LeapYearCtn(month_, year_);

	for (int i = 0; i < date.month_ - 1; i++) 
	num2 += monthDays[i];
	num2 += LeapYearCtn(date.month_, date.year_);

		return (num2 - num1);
	
}

int UUDate::GetDay() const {
	//TODO - Add your implementation here
	return day_;
}

void UUDate::SetDay(int day) {
	//TODO - Add your implementation here
	if ((validateDay(day)==true)) {
		day_ = day;
	}
}

int UUDate::GetMonth() const {
	//TODO - Add your implementation here
	return month_;
}

void UUDate::SetMonth(int month) {
	//TODO - Add your implementation here
	if (validateMonth(month)==true) {
		month_ = month;
	}
}

int UUDate::GetYear() const {
	//TODO - Add your implementation here
	return year_;
}

void UUDate::SetYear(int year) {
	//TODO - Add your implementation here
	if (validateYr(year) == true) {
		year_ = year;
	}

	}

std::string UUDate::GetDate() {
	//TODO - Add your implementation here
	return std::to_string(day_) + "/" + std::to_string(month_) + "/" + std::to_string(year_);
}

bool UUDate::LeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	}
	else {
		return false;
	}
}
int UUDate::LeapYearCtn(int month, int year)
{
	int years = year;

	if (month <= 2)
		years--;

	return years / 4 - years / 100 + years / 400;
}

bool UUDate::validateYr(int year) {

	if (year >= 1582 && year < 2020) {
		return true;
	}
	else {
		return false;
	}
}

bool UUDate::validateMonth(int month) {

	if (month >= 1 && month < 13) {
		return true;
	}
	else {
		return false;
	}
}

	bool UUDate::validateDay(int day) {

		if ((LeapYear(year_) == true) && (month_ == 2)) {
			if (day <= 29) {
				return true;
			}
		}
		else if(month_==2 && (day<=28)){
			return true;
		}
		else if ((month_ == 1) || (month_ == 3) || (month_ == 5) || (month_ == 7) || (month_ == 8) || (month_ == 10) || (month_ == 12)) {
			if (day <= 31) {
				return true;
			}
		}
		else if ((month_ == 4) || (month_ == 6) || (month_ == 9) || (month_ == 11)) {
			if (day <= 30) {
				return true;
			}
		}
		return false;

	}
