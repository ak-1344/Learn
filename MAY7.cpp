/*
A fitness app tracks the fitness of person by 'yoga' class with yoga_duration and 'Exercise' class with exercise
type and exercise_time.By performing 'Yoga' and 'Exercise' the fitness condition is evaluated using the class
'Fit' with healthreport() method using the following conditions:
    1. if exercise_time>30minutes,
           exercise_type=running and
           yoga_duration>=15minutes      then fitness is good.
    2. if exercise_time<=30minutes to >10minutes,
           exercise_type=running
           yoga_duration<15minutes     then fitness is average.
    3. otherwise fitness is bad.
"Meditation" class with property Meditation_duration which is inherited from "yoga". Use member function in
Meditation class to find the Meditation nature of a person by the following conditions:
    1. if yoga_duration>=15minutes and
          Meditation_duration>=2hours to <=3hours then the nature of Meditation is good.
    2. if yoga_duration<15minutes to >=7minutes and
          Meditation_duration<2hours to >=3hours then the nature of Meditation is average.
    3. otherwise nature of Meditation is bad.
    Develop a c++ program to implement the given scenario.
*/
#include <iostream>
#include <string>
using namespace std;
class yoga
{
protected:
    double yoga_duration;
};
class Exercise
{
protected:
    string exercise_type;
    double exercise_time;
};
class Fit : public yoga, public Exercise
{
public:
    void healthreport(double extime, string extype, double yogatime)
    {
        exercise_time = extime;
        extype = exercise_type;
        yogatime = yoga_duration;
        if ((exercise_time >= 30.0) && (exercise_type == "running") && (yoga_duration >= 15.0))
        {
            cout << "Fitness is good.\n";
        }
        else if ((exercise_time <= 30.0 && exercise_time >= 10.0) && (exercise_type == "running") && (yoga_duration <= 15.0))
        {
            cout << "Fitness is average.\n";
        }
        else
        {
            cout << "Fitness is bad.\n";
        }
    }
};
class Meditation : public yoga
{
public:
    double Meditation_duration;

    void meditationNature(double yogatime, double mtime)
    {
        yoga_duration = yogatime;
        Meditation_duration = mtime;
        if ((yoga_duration >= 15.0) && (Meditation_duration >= 2.0 && Meditation_duration <= 3.0))
        {
            cout << "Meditation is good.\n";
        }
        else if ((yoga_duration <= 15.0 && yoga_duration >= 7.0) && (Meditation_duration < 2.0 && Meditation_duration >= 3.0))
        {
            cout << "Meditation is average.\n";
        }
        else
        {
            cout << "Meditation is bad.\n";
        }
    }
};
int main()
{
    Fit f1, f2, f3;
    Meditation m1, m2, m3;
    f1.healthreport(40.0, "running", 20.0);
    f2.healthreport(20.0, "running", 10.0);
    f3.healthreport(10.0, "running", 10.0);
    m1.meditationNature(20.0, 2.5);
    m2.meditationNature(10.0, 1.5);
    m3.meditationNature(5.0, 3.5);
}