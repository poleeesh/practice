/* t_ime.cpp */
#include <iostream>
#include "t_ime.h"

using namespace std;


void Time::set_seconds(int s){
        seconds = s;
    };

int const Time::get_seconds(){
        return seconds;
    };

void Time::set_minutes(int s){
        minutes = s;
    };

int const Time::get_minutes(){
        return minutes;
    };

void Time::set_hours(int s){
        hours = s;
    };

int const Time::get_hours(){
        return hours;
    };

void const Time::show_time(){
    string t = to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds);
    cout << "Время: " << t << endl;
}

Time Time::add_time(Time a, Time b) {
    if (a.get_seconds() == 0 && a.get_minutes() == 0 && a.get_hours() == 0){
        throw TimeException();
    }
    if (b.get_seconds() == 0 && b.get_minutes() == 0 && b.get_hours() == 0){
        throw TimeException();
    }
    Time c;
    int sec = a.get_seconds() + b.get_seconds();
    int mins = a.get_minutes() + b.get_minutes();
    c.set_seconds(sec % 60);
    c.set_minutes((sec / 60) + (mins % 60));
    c.set_hours(a.get_hours() + b.get_hours() + (mins / 60));
    return c;
}


Time Time::operator+(const Time& t, const Time& t2) {
    return add_time(t, t2);
}


Time Time::operator+ (float & f, const Time& t2) {
    Time t = Time(t2.hours + f / 1, t2.seconds, t2.minutes + f - f / 1);
    return t;
}


Time Time::operator+(const Time& t2, float & f){
    return (f + t2);
}


Time Time::operator- (const Time& t3, const Time &t2) {
    Time t = Time(t3.hours - t2.hours, t3.seconds - t2.seconds, t3.minutes - t2.seconds);
    return t;
}


bool Time::operator< (const Time &t, const Time &t2) {
    int s = t.seconds + t.minutes * 60 + t.hours * 3600;
    int s2 = t2.seconds + t2.hours * 3600 + t2.minutes * 60;

    if (s < s2){
        return true;
    }
    return false;
}


bool Time::operator> (const Time &t, const Time &t2) {
    return t2 < t;
}


Time::Time(int h, int s, int m){
    if ((s > 59) || (m > 59)){
        throw TimeException();
    }
    Time::set_hours(h + (m / 60));
    Time::set_minutes((s / 60) + (m % 60));
    Time::set_seconds(s % 60);
}

Time::Time(){
    Time::set_hours(0);
    Time::set_minutes(0);
    Time::set_seconds(0);
}
