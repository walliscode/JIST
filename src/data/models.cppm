export module data:models;

import std;

export namespace data::models {

/////////////////////////////////////////////////
/// @brief Smalled intervel we are concerned about for scheduling, this is
/// currently a magic number?
/////////////////////////////////////////////////
constexpr std::uint8_t kSmallestMinuteInterval{15};

/////////////////////////////////////////////////
/// @brief By using @ref kSmallestMinuteInterval we can calculate the number
/// daily intervals we need to account for.
/////////////////////////////////////////////////
constexpr std::size_t kDailyIntervals{(24 * 60) / kSmallestMinuteInterval};

using DailyAvailability = std::bitset<kDailyIntervals>;

/////////////////////////////////////////////////
/// @class YmdHash
/// @brief A hash function for std::chrono::year_month_day to be used in
/// unordered_map
/////////////////////////////////////////////////
struct YmdHash {
  std::size_t
  operator()(const std::chrono::year_month_day &ymd) const noexcept {
    auto days = std::chrono::sys_days{ymd}.time_since_epoch().count(); // int
    return std::hash<int>{}(days);
  }
};

///////////////////////////////////////////////////
/// @brief A schedule is a mapping of a date to the availability of an operator
/// ///////////////////////////////////////////////
using Schedule =
    std::unordered_map<std::chrono::year_month_day, DailyAvailability, YmdHash>;

/////////////////////////////////////////////////
/// @struct Operator
/// @brief An operator is a single person, this could be various job roles or
/// responsibilities.
/// The class itself contains all basic information about the operator. Any
/// derived information will be provided by functions interacting with the
/// class or from the class itself.
/////////////////////////////////////////////////
struct Operator {

  std::string m_name;
  std::unordered_set<std::uint8_t> m_skills;
  Schedule m_schedule;
  const std::uint8_t home_station_id;
};

/////////////////////////////////////////////////
/// @class Pump
/// @brief Status and availability of a pump. A pump is a colloquial term for a
/// Fire Engine.
/////////////////////////////////////////////////
struct Pump {
  Schedule m_schedule;
};

/////////////////////////////////////////////////
/// @class Station
/// @brief Represents a building/location where operators are based out of
///
/////////////////////////////////////////////////
struct Station {
  const std::uint8_t id;
};

} // namespace data::models
