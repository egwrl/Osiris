#include "catch.hpp"

#include "../Osiris/InventoryChanger/ItemGenerator.cpp"

TEST_CASE("getStartOfYearTimestamp()") {
    REQUIRE(getStartOfYearTimestamp(2015) == 1420070400);
    REQUIRE(getStartOfYearTimestamp(2016) == 1451606400);
    REQUIRE(getStartOfYearTimestamp(2017) == 1483228800);
    REQUIRE(getStartOfYearTimestamp(2018) == 1514764800);
    REQUIRE(getStartOfYearTimestamp(2019) == 1546300800);
    REQUIRE(getStartOfYearTimestamp(2020) == 1577836800);
    REQUIRE(getStartOfYearTimestamp(2021) == 1609459200);
    REQUIRE(getStartOfYearTimestamp(2022) == 1640995200);
    REQUIRE(getStartOfYearTimestamp(2023) == 1672531200);
    REQUIRE(getStartOfYearTimestamp(2024) == 1704067200);
    REQUIRE(getStartOfYearTimestamp(2025) == 1735689600);
}

TEST_CASE("getEndOfYearTimestamp()") {
    REQUIRE(getEndOfYearTimestamp(2015) == 1451606399);
    REQUIRE(getEndOfYearTimestamp(2016) == 1483228799);
    REQUIRE(getEndOfYearTimestamp(2017) == 1514764799);
    REQUIRE(getEndOfYearTimestamp(2018) == 1546300799);
    REQUIRE(getEndOfYearTimestamp(2019) == 1577836799);
    REQUIRE(getEndOfYearTimestamp(2020) == 1609459199);
    REQUIRE(getEndOfYearTimestamp(2021) == 1640995199);
    REQUIRE(getEndOfYearTimestamp(2022) == 1672531199);
    REQUIRE(getEndOfYearTimestamp(2023) == 1704067199);
    REQUIRE(getEndOfYearTimestamp(2024) == 1735689599);
    REQUIRE(getEndOfYearTimestamp(2025) == 1767225599);
}

TEST_CASE("getRandomDateTimestampOfYear() for past years") {
    for (std::uint16_t year = 2015; year <= 2020; ++year) {
        for (std::size_t i = 0; i < 1000; ++i) {
            const auto timestamp = getRandomDateTimestampOfYear(year);
            REQUIRE((timestamp >= getStartOfYearTimestamp(year) && timestamp <= getEndOfYearTimestamp(year)));
        }
    }
}
