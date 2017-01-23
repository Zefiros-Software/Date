#include "date.h"
#include <cassert>
#include <sstream>

void test_a()
{
    using namespace date;
    {
        // correct abbreviation
        std::istringstream in{"Sun 2016-12-11"};
        sys_days tp;
        parse( in, "%a %F", tp );
        assert( tp == 2016_y / 12 / 11 );
    }
    {
        // correct abbreviation
        std::istringstream in{"Sun 2016-12-11"};
        sys_days tp;
        parse( in, "%A %F", tp );
        assert( tp == 2016_y / 12 / 11 );
    }
    {
        // correct full name
        std::istringstream in{"Sunday 2016-12-11"};
        sys_days tp;
        parse( in, "%a %F", tp );
        assert( tp == 2016_y / 12 / 11 );
    }
    {
        // correct full name
        std::istringstream in{"Sunday 2016-12-11"};
        sys_days tp;
        parse( in, "%A %F", tp );
        assert( tp == 2016_y / 12 / 11 );
    }
    {
        // not a valid name
        std::istringstream in{"Dec 2016-12-11"};
        sys_days tp;
        parse( in, "%a %F", tp );
        assert( tp == 1970_y / 1 / 1 );
    }
    {
        // wrong name
        std::istringstream in{"Sat 2016-12-11"};
        sys_days tp;
        parse( in, "%a %F", tp );
        assert( tp == 1970_y / 1 / 1 );
    }
    {
        // extra ws in input
        std::istringstream in{"Sun  2016-12-11"};
        sys_days tp;
        parse( in, "%a %F", tp );
        assert( tp == 2016_y / 12 / 11 );
    }
    {
        // extra ws in format
        std::istringstream in{"Sun 2016-12-11"};
        sys_days tp;
        parse( in, "%a  %F", tp );
        assert( tp == 2016_y / 12 / 11 );
    }
}

void test_b()
{
    using namespace date;
    {
        // correct abbreviation
        std::istringstream in{"Dec 11 2016"};
        sys_days tp;
        parse( in, "%b %d %Y", tp );
        assert( tp == 2016_y / 12 / 11 );
    }
    {
        // correct abbreviation
        std::istringstream in{"Dec 11 2016"};
        sys_days tp;
        parse( in, "%B %d %Y", tp );
        assert( tp == 2016_y / 12 / 11 );
    }
    {
        // correct abbreviation
        std::istringstream in{"Dec 11 2016"};
        sys_days tp;
        parse( in, "%h %d %Y", tp );
        assert( tp == 2016_y / 12 / 11 );
    }
    {
        // correct full name
        std::istringstream in{"December 11 2016"};
        sys_days tp;
        parse( in, "%b %d %Y", tp );
        assert( tp == 2016_y / 12 / 11 );
    }
    {
        // correct full name
        std::istringstream in{"December 11 2016"};
        sys_days tp;
        parse( in, "%B %d %Y", tp );
        assert( tp == 2016_y / 12 / 11 );
    }
    {
        // correct full name
        std::istringstream in{"December 11 2016"};
        sys_days tp;
        parse( in, "%h %d %Y", tp );
        assert( tp == 2016_y / 12 / 11 );
    }
    {
        // incorrect abbreviation
        std::istringstream in{"Dece 11 2016"};
        sys_days tp;
        parse( in, "%b %d %Y", tp );
        assert( tp == 1970_y / 1 / 1 );
    }
}


int
main()
{
    test_a();
    test_b();
}