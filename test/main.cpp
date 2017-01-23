static_assert( std::is_trivially_destructible<date::day>{}, "");
static_assert( std::is_default_constructible<date::day>{}, "");
static_assert( std::is_trivially_copy_constructible<date::day>{}, "");
static_assert( std::is_trivially_copy_assignable<date::day>{}, "");
static_assert( std::is_trivially_move_constructible<date::day>{}, "");
static_assert( std::is_trivially_move_assignable<date::day>{}, "");

static_assert( std::is_nothrow_constructible<date::day, unsigned>{}, "");
static_assert( std::is_nothrow_constructible<unsigned, date::day>{}, "");
static_assert(!std::is_convertible<unsigned, date::day>{}, "");
static_assert(!std::is_convertible<date::day, unsigned>{}, "");
static_assert(static_cast<unsigned>(date::day{1}) == 1, "");

static_assert(!date::day{0}.ok(), "");
static_assert( date::day{1}.ok(), "");
static_assert( date::day{2}.ok(), "");
static_assert( date::day{3}.ok(), "");
static_assert( date::day{29}.ok(), "");
static_assert( date::day{30}.ok(), "");
static_assert( date::day{31}.ok(), "");
static_assert(!date::day{32}.ok(), "");

int main()
{
    using namespace date;
    static_assert(std::is_same<decltype(1_d), day>{}, "");

    static_assert(1_d == day{1}, "");
    static_assert(2_d == day{2}, "");

    static_assert(  1_d == 1_d, "");
    static_assert(!(1_d == 2_d), "");
    static_assert(!(2_d == 1_d), "");

    static_assert(!(1_d != 1_d), "");
    static_assert(  1_d != 2_d, "");
    static_assert(  2_d != 1_d, "");

    static_assert(!(1_d <  1_d), "");
    static_assert(  1_d <  2_d, "");
    static_assert(!(2_d <  1_d), "");

    static_assert(  1_d <= 1_d, "");
    static_assert(  1_d <= 2_d, "");
    static_assert(!(2_d <= 1_d), "");

    static_assert(!(1_d >  1_d), "");
    static_assert(!(1_d >  2_d), "");
    static_assert(  2_d >  1_d, "");

    static_assert(  1_d >= 1_d, "");
    static_assert(!(1_d >= 2_d), "");
    static_assert(  2_d >= 1_d, "");

    static_assert(3_d + days{7} == 10_d, "");
    static_assert(days{7} + 3_d == 10_d, "");
    static_assert(3_d + weeks{1} == 10_d, "");
    static_assert(weeks{1} + 3_d == 10_d, "");

    static_assert(7_d - days{3} == 4_d, "");
    static_assert(3_d - 7_d == days{-4}, "");
    static_assert(25_d - 11_d == weeks{2}, "");

    auto d = 1_d;
    assert(++d == 2_d);
    assert(d++ == 2_d);
    assert(d == 3_d);
    assert(d-- == 3_d);
    assert(d == 2_d);
    assert(--d == 1_d);
    assert((d += days{2}) == 3_d);
    assert((d -= days{2}) == 1_d);

    std::ostringstream os;
    os << d;
    assert(os.str() == "01");
    d += days{11};
    os.str("");
    os << d;
    assert(os.str() == "12");
}