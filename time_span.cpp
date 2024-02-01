#include <iostream>
#include <string>
#include <cmath>
#include "time_span.h"
using namespace std;

TimeSpan::TimeSpan() {
    hours_ = 0;
    minutes_ = 0;
    seconds_ = 0;
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds) {
    int totalSeconds = round(hours * 3600 + minutes * 60 + seconds);
    hours_ = totalSeconds / 3600;
    minutes_ = (totalSeconds % 3600) / 60;
    seconds_ = totalSeconds % 60;
}

TimeSpan::TimeSpan(double minutes, double seconds) {
    int totalSeconds = round(minutes * 60 + seconds);
    hours_ = 0;
    minutes_ = totalSeconds / 60;
    seconds_ = totalSeconds % 60;
}

TimeSpan::TimeSpan(double seconds) {
    int totalSeconds = round(seconds);
    hours_ = 0;
    minutes_ = totalSeconds / 60;
    seconds_ = totalSeconds % 60;
}

void TimeSpan::set_time(int hours, int minutes, int seconds) {
    hours_ = hours;
    minutes_ = minutes;
    seconds_ = seconds; 
}

int TimeSpan::totalTime() const {
    return hours_ * 3600 + minutes_ * 60 + seconds_;
}

int TimeSpan::hours() const {
    return totalTime() / 3600;
}

int TimeSpan::minutes() const {
    return (totalTime() % 3600) / 60;
}

int TimeSpan::seconds() const {
    return totalTime() % 60;
}

TimeSpan TimeSpan::operator-() const {
    TimeSpan temp;
    temp.hours_ = -hours_;
    temp.minutes_ = -minutes_;
    temp.seconds_ = -seconds_;
    while (temp.seconds_ < 0) {
        temp.seconds_ += 60;
        temp.minutes_ -= 1;
    }
    while (temp.seconds_ >= 60) {
        temp.seconds_ -= 60;
        temp.minutes_ += 1;
    }
    while (temp.minutes_ < 0) {
        temp.minutes_ += 60;
        temp.hours_ -= 1;
    }
    while (temp.minutes_ >= 60) {
        temp.minutes_ -= 60;
        temp.hours_ += 1;
    }
    return temp;
}

TimeSpan TimeSpan::operator+(const TimeSpan& other) const
{
    TimeSpan temp;
    temp.hours_ = hours_ + other.hours_;
    temp.minutes_ = minutes_ + other.minutes_;
    temp.seconds_ = seconds_ + other.seconds_;
    if (temp.minutes_ > 60) {
        temp.hours_ += 1;
        temp.minutes_ -= 60;
    }
    if (temp.seconds_ > 60) {
        temp.minutes_ += 1;
        temp.seconds_ -= 60;
    }
    return temp;
}

TimeSpan TimeSpan::operator-(const TimeSpan& other) const {
    TimeSpan temp;
    temp.hours_ = hours_ - other.hours_;
    temp.minutes_ = minutes_ - other.minutes_;
    temp.seconds_ = seconds_ - other.seconds_;
    while (temp.seconds_ < 0) {
        temp.seconds_ += 60;
        temp.minutes_ -= 1;
    }
    while (temp.seconds_ >= 60) {
        temp.seconds_ -= 60;
        temp.minutes_ += 1;
    }
    while (temp.minutes_ < 0) {
        temp.minutes_ += 60;
        temp.hours_ -= 1;
    }
    while (temp.minutes_ >= 60) {
        temp.minutes_ -= 60;
        temp.hours_ += 1;
    }
    return temp;
}

TimeSpan& TimeSpan::operator+=(const TimeSpan& other) {
    (*this).hours_ += other.hours_;
    (*this).minutes_ += other.minutes_;
    (*this).seconds_ += other.seconds_;
    if ((*this).minutes_ > 60) {
        (*this).hours_ += 1;
        (*this).minutes_ -= 60;
    }
    if ((*this).seconds_ > 60) {
        (*this).minutes_ += 1;
        (*this).seconds_ -= 60;
    }
    return *this;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan& other) {
    (*this).hours_ -= other.hours_;
    (*this).minutes_ -= other.minutes_;
    (*this).seconds_ -= other.seconds_;
    while ((*this).seconds_ < 0) {
        (*this).seconds_ += 60;
        (*this).minutes_ -= 1;
    }
    while ((*this).seconds_ >= 60) {
        (*this).seconds_ -= 60;
        (*this).minutes_ += 1;
    }
    while ((*this).minutes_ < 0) {
        (*this).minutes_ += 60;
        (*this).hours_ -= 1;
    }
    while ((*this).minutes_ >= 60) {
        (*this).minutes_ -= 60;
        (*this).hours_ += 1;
    }
    return *this;
}

bool TimeSpan::operator==(const TimeSpan& other) const {
    if (hours_ == other.hours_ && minutes_ == other.minutes_) {
        if (seconds_ == other.seconds_) {
            return true;
        }
    }
    return false;
}

bool TimeSpan::operator!=(const TimeSpan& other) const {
    if (hours_ != other.hours_) {
        return true;
    } else if (hours_ == other.hours_ && minutes_ != other.minutes_) {
        return true;
    } else if (hours_ == other.hours_ && minutes_ == other.minutes_ && seconds_ != other.seconds_) {
        return true;
    }
    return false;
}

bool TimeSpan::operator<(const TimeSpan& other) {
    if ((*this).hours_ < other.hours_) {
        return true;
    } else if ((*this).hours_ == other.hours_ && (*this).minutes_ < other.minutes_) {
        return true;
    } else if ((*this).hours_ == other.hours_ && (*this).minutes_ == other.minutes_ && (*this).seconds_ < other.seconds_) {
        return true;
    }
    return false;
}

bool TimeSpan::operator>(const TimeSpan& other) {
    if (hours_ > other.hours_) {
        return true;
    } else if (hours_ == other.hours_ && minutes_ > other.minutes_) {
        return true;
    } else if (hours_ == other.hours_ && minutes_ == other.minutes_ && seconds_ > other.seconds_) {
        return true;
    }
    return false;
}

bool TimeSpan::operator<=(const TimeSpan &other) {
    if ((*this).hours_ < other.hours_) {
        return true;
    } else if ((*this).hours_ == other.hours_ && (*this).minutes_ < other.minutes_) {
        return true;
    } else if ((*this).hours_ == other.hours_ && (*this).minutes_ == other.minutes_ && (*this).seconds_ < other.seconds_) {
        return true;
    } else if ((*this).hours_ == other.hours_ && (*this).minutes_ == other.minutes_ && (*this).seconds_ == other.seconds_) {
        return true;
    }
    return false;
}

bool TimeSpan::operator>=(const TimeSpan &other) {
    if ((*this).hours_ > other.hours_) {
        return true;
    } else if ((*this).hours_ == other.hours_ && (*this).minutes_ > other.minutes_) {
        return true;
    } else if ((*this).hours_ == other.hours_ && (*this).minutes_ == other.minutes_ && (*this).seconds_ > other.seconds_) {
        return true;
    } else if ((*this).hours_ == other.hours_ && (*this).minutes_ == other.minutes_ && (*this).seconds_ == other.seconds_) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream &stream, const TimeSpan& other) {
    stream << "Hours: " << other.hours_ << ",";
    stream << " Minutes: " << other.minutes() << ",";
    stream << " Seconds: " << other.seconds();
    return stream;
}

istream& operator>>(istream &stream, TimeSpan& other) {
    stream >> other.hours_;
    stream >> other.minutes_;
    stream >> other.seconds_;
    return stream;
}
