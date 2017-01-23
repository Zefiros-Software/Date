#include "date.h"

int
main()
{
    using namespace date;

    static_assert( sizeof( days ) == 4, "" );
    static_assert( sizeof( weeks ) == 4, "" );
    static_assert( sizeof( months ) == 4, "" );
    static_assert( sizeof( years ) == 4, "" );

    static_assert( sizeof( sys_days ) == 4, "" );

    static_assert( sizeof( last_spec ) == 1, "" );

    static_assert( sizeof( day ) == 1, "" );
    static_assert( sizeof( month ) == 1, "" );
    static_assert( sizeof( year ) == 2, "" );

    static_assert( sizeof( weekday ) == 1, "" );
    static_assert( sizeof( weekday_indexed ) == 1, "" );
    static_assert( sizeof( weekday_last ) == 1, "" );

    static_assert( sizeof( month_day ) == 2, "" );
    static_assert( sizeof( month_day_last ) == 1, "" );
    static_assert( sizeof( month_weekday ) == 2, "" );
    static_assert( sizeof( month_weekday_last ) == 2, "" );

    static_assert( sizeof( year_month ) == 4, "" );

    static_assert( sizeof( year_month_day ) == 4, "" );
    static_assert( sizeof( year_month_day_last ) == 4, "" );
    static_assert( sizeof( year_month_weekday ) == 4, "" );
    static_assert( sizeof( year_month_weekday_last ) == 4, "" );

    // sizeof time_of_day varies
}