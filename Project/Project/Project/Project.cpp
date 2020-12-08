#include <iostream>
#include <chrono>
#include <thread>
#include "date.h"

using namespace std::chrono;
using namespace std::chrono_literals;
using namespace std::this_thread;
using namespace date;
using std::cout;
using std::endl;

int main()
{
	//Part 1
	/*cout << "This is " << 5s << endl;
	cout << "This is " << 5.23s << endl;
	cout << "This is " << 7.6ms << endl;
	cout << "This is " << 2.3ns << endl;*/

	//Part 2
	/*auto t0 = steady_clock::now();
	sleep_for(50ms);
	auto t1 = steady_clock::now();
	auto timeLasted = t1 - t0;
	cout << "That took " << timeLasted.count()/1'000'000 << " milliseconds" << endl;*/

	//Part 3
	/*auto start = steady_clock::now();

	cout << "Time start..." << endl;
	sleep_for(2.5s);

	auto end = steady_clock::now(); //monotonic: Its member now never returns a lower value than in a previous call.
									//steady: Every tick the clock advances takes the same amount of time (in terms of physical time).dfsdf

	cout << "Time Passed in nanoseconds : " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;
	cout << "Time Passed  time in milliseconds : " << duration_cast<milliseconds>(end - start).count() << " milliseconds" << endl;
	cout << "Time Passed  time in seconds : " << duration_cast<seconds>(end - start).count() << " seconds";*/

	//Part 4
	/*auto t2 = high_resolution_clock::now();
	sleep_for(50ms);
	auto t3 = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(t3 - t2);
	cout << "That took " << duration.count() << " milliseconds" << endl;*/

	//Part 5
	/*auto t4 = high_resolution_clock::now();
	sleep_until(system_clock::now() + 73ms);
	auto t5 = high_resolution_clock::now();
	cout << "That took " << (t5-t4).count()/1'000'000 << " milliseconds" << endl;*/

	//Part 6
	/*auto now = system_clock::now();
	cout << "The current time is " << now << " UTC" << endl;
	auto current_year = year_month_day{ floor<days>(now) }.year();
	cout << "The current year is " << current_year << endl;
	auto h = floor<hours>(now) - sys_days{ jan / 1 / current_year };
	cout << "It has been " << h << " since New Years!" << endl << endl;*/

	//Part 7
	/*cout << month_day_last(month(11)) << endl << endl;

	cout << year_month_weekday(2020_y, month(December), Friday[5]) << endl << endl;

	cout << "The day is " << day(19) << endl << endl;

	auto monthDayYear{ month(12) / 5 / 2025 };
	cout << monthDayYear << endl;*/
}