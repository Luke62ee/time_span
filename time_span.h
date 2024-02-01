#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <iostream>
using namespace std;

class TimeSpan {
    public:
        //constructor
        TimeSpan();
        TimeSpan(double hours, double minutes, double seconds);
        TimeSpan(double minutes, double seconds);
        TimeSpan(double seconds);

        //getters-setters
        void set_time(int hours, int minutes, int seconds);
        int totalTime() const;
        int hours() const;
        int minutes() const;
        int seconds() const;
        
        //operator
        TimeSpan operator-() const;
        TimeSpan operator+(const TimeSpan& other) const;
        TimeSpan operator-(const TimeSpan& other) const;
        TimeSpan& operator+=(const TimeSpan& other);
        TimeSpan& operator-=(const TimeSpan& other);
        bool operator==(const TimeSpan& other) const;
        bool operator!=(const TimeSpan& other) const;
        bool operator<(const TimeSpan& other);
        bool operator>(const TimeSpan& other);
        bool operator<=(const TimeSpan& other);
        bool operator>=(const TimeSpan& other);
        friend ostream& operator<<(ostream &stream, const TimeSpan& other);
        friend istream& operator>>(istream &stream, TimeSpan& other);
        
    private:
        double hours_;
        double minutes_;
        double seconds_;

};
#endif
