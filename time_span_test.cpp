#include <iostream>
#include "time_span.h"
using namespace std;
bool CheckValues(TimeSpan time, int hours, int minutes, int seconds) {
    if ((time.hours() != hours) || (time.minutes() != minutes) || (time.seconds() != seconds)) {
        return false;
    }
    return true;
}

bool TestZeros() {
    TimeSpan ts(0, 0, 0);
    return CheckValues(ts, 0, 0, 0);
}

bool TestFloatSeconds() {
    TimeSpan ts(127.86);
    return CheckValues(ts, 0, 2, 8);
}

bool TestNegativeMinute() {
    TimeSpan ts(8, -23, 0);
    return CheckValues(ts, 7, 37, 0);
}

bool TestNegativeHour() {
    TimeSpan ts(-3, 73, 2);
    return CheckValues(ts, -1, -46, -58);
}

bool TestAdd() {
    TimeSpan ts1, ts2(5), ts3(7, 0), ts4(4, 0, 0);
    TimeSpan add_it_up = ts1 + ts2 + ts3 + ts4;
    return CheckValues(add_it_up, 4, 7, 5);
}

bool TestAddInPlace() {
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(1, 1, 1);
    if ((!CheckValues(ts1, 5, 6, 7)) || (!CheckValues(ts2, 1, 1, 1))) {
    return false;
    }
    ts1 += ts2;
    if ((!CheckValues(ts1, 6, 7, 8)) || (!CheckValues(ts2, 1, 1, 1))) {
    return false;
    }
    return true;
}

bool TestEqual() {
    TimeSpan ts1(1, 55, -23);
    TimeSpan ts2(1, 55, -23);
    if (ts1 == ts2) {
        return true;
    }
    return false;
}

bool TestNotEqual() {
    TimeSpan ts1(2, 8, 66);
    TimeSpan ts2(6, 4, 32);
    if (ts1 != ts2) {
        return true;
    }
    return false;
}

bool TestLessThan() {
    TimeSpan ts1(1, -20, 3);
    TimeSpan ts2(2, 7, 10);
    if (ts1 < ts2) {
        return true;
    }
    return false;
}

bool TestGreaterThan() {
    TimeSpan ts1(50, 22, -10);
    TimeSpan ts2(2, -7, -10);
    if (ts1 > ts2) {
        return true;
    }
    return false;
}

bool TestMinutesOverflow() {
    TimeSpan ts(1, 70, 0);
    return CheckValues(ts, 2, 10, 0);
}

bool TestSubtraction() {
    TimeSpan ts1(5, 55, 22);
    TimeSpan ts2(2, 44, 12);
    TimeSpan result = ts1 - ts2;
    return CheckValues(result, 3, 11, 10);
}

bool TestComplexOperations() {
    TimeSpan ts1(5, 15, 10);
    TimeSpan ts2(2, 3, 18);
    TimeSpan ts3 = ts1 + ts2;
    TimeSpan ts4(3, 15, 5);
    TimeSpan result = ts3 - ts4;
    return CheckValues(result, 4, 3, 23);
}

bool TestSubtractionInPlace() {
    TimeSpan ts1(5, 10, 20);
    TimeSpan ts2(2, 5, 10);
    ts1 -= ts2;
    return CheckValues(ts1, 3, 5, 10);
}

bool TestSubtractionZero() {
    TimeSpan ts1(5, 10, 20);
    TimeSpan ts2(5, 10, 20);
    ts1 -= ts2;
    return CheckValues(ts1, 0, 0, 0);
}

bool TestSubtractionNegativeHours() {
    TimeSpan ts1(5, 10, 20);
    TimeSpan ts2(7, 5, 10);
    ts1 -= ts2;
    return CheckValues(ts1, -1, -54, -50);
}

bool TestUnaryNegation() {
    TimeSpan ts(10, 20, 30);
    ts = -ts;
    return CheckValues(ts, -10, -20, -30);
}

bool TestRepeatedOperations() {
    TimeSpan ts1(0, 59, 59);
    for (int i = 0; i < 60; i++) {
        ts1 += TimeSpan(0, 1, 1);
    }
    return CheckValues(ts1, 2, 0, 59);
}

bool TestDifferentOperations() {
    TimeSpan ts1(1, 59, 30);
    TimeSpan ts2(0, 0, 45);
    TimeSpan ts3(0, 60, 0);
    TimeSpan result = ts1 + ts2 - ts3;
    return CheckValues(result, 1, 0, 15);
}

bool TestLessThanOrEqual() {
    TimeSpan ts1(0, 1, 3);
    TimeSpan ts2(0 ,1, 3);

    bool test1 = ts1 <= ts2;
    return test1;
}

bool TestLessThanOrEqualII() {
    TimeSpan ts1(1, -2, 20);
    TimeSpan ts2(2, 0, 0);

    bool test1 = ts1 <= ts2;
    return test1;
}

bool TestGreaterThanOrEqual() {
    TimeSpan ts1(8, 40, 125);
    TimeSpan ts2(5, -120, 30);
    
    bool test1 = ts1 >= ts2;
    return test1;
} 

bool TestGreaterThanOrEqualII() {
    TimeSpan ts1(8, 40, 125);
    TimeSpan ts2(8, 40, 125);
    
    bool test1 = ts1 >= ts2;
    return test1;
} 

int main() {
    cout << "Testing TimeSpan Class" << endl;
    cout << "1. TestZeros: " << (TestZeros() ? "PASS" : "FAIL") << endl;
    cout << "2. TestFloatSeconds: " << (TestFloatSeconds() ? "PASS" : "FAIL") << endl;
    cout << "3. TestNegativeMinute: " << (TestNegativeMinute() ? "PASS" : "FAIL") << endl;
    cout << "4. TestNegativeHour: " << (TestNegativeHour() ? "PASS" : "FAIL") << endl;
    cout << "5. TestAdd: " << (TestAdd() ? "PASS" : "FAIL") << endl;
    cout << "6. TestAddInPlace: " << (TestAddInPlace() ? "PASS" : "FAIL") << endl;
    cout << "7. TestAddInPlace: " << (TestAddInPlace() ? "PASS" : "FAIL") << endl;
    cout << "8. TestMinutesOverflow: " << (TestMinutesOverflow() ? "PASS" : "FAIL") << endl;
    cout << "9. TestEqual: " << (TestEqual() ? "PASS" : "FAIL") << endl;
    cout << "10. TestNotEqual: " << (TestNotEqual() ? "PASS" : "FAIL") << endl;
    cout << "11. TestLessThan: " << (TestLessThan() ? "PASS" : "FAIL") << endl;
    cout << "12. TestGreaterThan: " << (TestGreaterThan() ? "PASS" : "FAIL") << endl;
    cout << "13. TestSubtraction: " << (TestSubtraction() ? "PASS" : "FAIL") << endl;
    cout << "14. TestComplexOperations: " << (TestComplexOperations() ? "PASS" : "FAIL") << endl;
    cout << "15. TestSubtractionInPlace: " << (TestSubtractionInPlace() ? "PASS" : "FAIL") << endl;
    cout << "16. TestSubtractionZero: " << (TestSubtractionZero() ? "PASS" : "FAIL") << endl;
    cout << "17. TestSubtractionNegativeHours: " << (TestSubtractionNegativeHours() ? "PASS" : "FAIL") << endl;
    cout << "18. TestUnaryNegation: " << (TestUnaryNegation() ? "PASS" : "FAIL") << endl;
    cout << "19. TestRepeatedOperations: " << (TestRepeatedOperations() ? "PASS" : "FAIL") << endl;
    cout << "20. TestDifferentOperations: " << (TestDifferentOperations() ? "PASS" : "FAIL") << endl;
    cout << "21. TestLessThanOrEqual: " << (TestLessThanOrEqual() ? "PASS" : "FAIL") << endl;
    cout << "22. TestLessThanOrEqualII: " << (TestLessThanOrEqualII() ? "PASS" : "FAIL") << endl;
    cout << "23. TestGreaterThanOrEqual: " << (TestGreaterThanOrEqual() ? "PASS" : "FAIL") << endl;
    cout << "24. TestGreaterThanOrEqualII: " << (TestGreaterThanOrEqualII() ? "PASS" : "FAIL") << endl;
    cout << "Please type three numbers to help me to finish 25th test case:" << endl;
    TimeSpan ts;
    cin >> ts;
    cout << ts << endl;
    cout << "Testing Complete";
}

