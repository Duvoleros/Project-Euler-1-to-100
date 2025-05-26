import datetime
import calendar

def count_sundays_on_first_of_month(start_year, end_year):
    count = 0
    for year in range(start_year, end_year + 1):
        for month in range(1, 13):
            if calendar.weekday(year, month, 1) == 6:  # 6 represents Sunday
                count += 1
    return count

start_year = 1901
end_year = 2000

sundays_count = count_sundays_on_first_of_month(start_year, end_year)
print(f"The number of Sundays is: {sundays_count}")
