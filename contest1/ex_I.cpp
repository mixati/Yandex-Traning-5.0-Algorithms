#include <iostream>
#include <set>
#include <limits.h>

using namespace std;

int main() {
    int count; // кол-во праздников
    int year; // год
    set<pair<int,int>> holidays; // праздники
    int days_of_weeks[] = { 0, 0, 0, 0, 0, 0, 0} ;
    string week_days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    cin >> count >> year;

    for (int i = 0; i < count; ++i ) {
        string month;
        int date;
        cin >> date >> month;
        if (month == "January")
            holidays.insert({1, date});
        else if (month == "February")
            holidays.insert({2, date});
        else if (month == "March")
            holidays.insert({3, date});
        else if (month == "April")
            holidays.insert({4, date});
        else if (month == "May")
            holidays.insert({5, date});
        else if (month == "June")
            holidays.insert({6, date});
        else if (month == "July")
            holidays.insert({7, date});
        else if (month == "August")
            holidays.insert({8, date});
        else if (month == "September")
            holidays.insert({9, date});
        else if (month == "October")
            holidays.insert({10, date});
        else if (month == "November")
            holidays.insert({11, date});
        else if (month == "December")
            holidays.insert({12, date});
    }

    string year_begining; // первый день года
    cin >> year_begining;
    int day = 0; // день недели в данный момент
    for (int i = 0; i < 7; ++i)
        if (year_begining == week_days[i]) {
            day = i;
            break;
        }
    
    // JANUARY
    for (int i = 1; i <= 31; ++i) {
        if (holidays.find({1,i}) == holidays.end())
            ++days_of_weeks[day];
        if (++day == 7)
            day = 0;
    }
    
    // FEBRUARY
    int feb_len = 28;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        feb_len = 29;
    for (int i = 1; i <= feb_len; ++i) {
        if (holidays.find({2,i}) == holidays.end())
            ++days_of_weeks[day];
        if (++day == 7)
            day = 0;
    }

    // MARCH
    for (int i = 1; i <= 31; ++i) {
        if (holidays.find({3,i}) == holidays.end())
            ++days_of_weeks[day];
        if (++day == 7)
            day = 0;
    }

    // APRIL
    for (int i = 1; i <= 30; ++i) {
        if (holidays.find({4,i}) == holidays.end())
            ++days_of_weeks[day];
        if (++day == 7)
            day = 0;
    }

    // MAY
    for (int i = 1; i <= 31; ++i) {
        if (holidays.find({5,i}) == holidays.end())
            ++days_of_weeks[day];
        if (++day == 7)
            day = 0;
    }

    // JUNE
    for (int i = 1; i <= 30; ++i) {
        if (holidays.find({6,i}) == holidays.end())
            ++days_of_weeks[day];
        if (++day == 7)
            day = 0;
    }

    // JULY
    for (int i = 1; i <= 31; ++i) {
        if (holidays.find({7,i}) == holidays.end())
            ++days_of_weeks[day];
        if (++day == 7)
            day = 0;
    }

    // AUGUST
    for (int i = 1; i <= 31; ++i) {
        if (holidays.find({8,i}) == holidays.end())
            ++days_of_weeks[day];
        if (++day == 7)
            day = 0;
    }

    // SEPTEMBER
    for (int i = 1; i <= 30; ++i) {
        if (holidays.find({9,i}) == holidays.end())
            ++days_of_weeks[day];
        if (++day == 7)
            day = 0;
    }

    // OCTOBER
    for (int i = 1; i <= 31; ++i) {
        if (holidays.find({10,i}) == holidays.end())
            ++days_of_weeks[day];
        if (++day == 7)
            day = 0;
    }

    // NOVEBER
    for (int i = 1; i <= 30; ++i) {
        if (holidays.find({11,i}) == holidays.end())
            ++days_of_weeks[day];
        if (++day == 7)
            day = 0;
    }

    // DECEMBER
    for (int i = 1; i <= 31; ++i) {
        if (holidays.find({12,i}) == holidays.end())
            ++days_of_weeks[day];
        if (++day == 7)
            day = 0;
    }



    // ищем лучший / худший варианты
    int min_count = INT_MAX;
    int min_day = 0;
    int max_count = 0;
    int max_day = 0;
    for (int i = 0; i < 7; ++i) {
        if (min_count > days_of_weeks[i]) {
            min_count = days_of_weeks[i];
            min_day = i;
        }
        if (max_count < days_of_weeks[i]) {
            max_count = days_of_weeks[i];
            max_day = i;
        }
    }

    cout << week_days[max_day] << ' ' << week_days[min_day];

    return 0;
}
