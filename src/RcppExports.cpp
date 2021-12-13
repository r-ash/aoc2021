// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// count_increases
int count_increases(std::vector<int> values);
RcppExport SEXP _aoc2021_count_increases(SEXP valuesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<int> >::type values(valuesSEXP);
    rcpp_result_gen = Rcpp::wrap(count_increases(values));
    return rcpp_result_gen;
END_RCPP
}
// window_increases
int window_increases(std::vector<int> values);
RcppExport SEXP _aoc2021_window_increases(SEXP valuesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<int> >::type values(valuesSEXP);
    rcpp_result_gen = Rcpp::wrap(window_increases(values));
    return rcpp_result_gen;
END_RCPP
}
// error_score
int error_score(std::vector<std::string> nav_system);
RcppExport SEXP _aoc2021_error_score(SEXP nav_systemSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type nav_system(nav_systemSEXP);
    rcpp_result_gen = Rcpp::wrap(error_score(nav_system));
    return rcpp_result_gen;
END_RCPP
}
// autocomplete_score
long autocomplete_score(std::vector<std::string> nav_system);
RcppExport SEXP _aoc2021_autocomplete_score(SEXP nav_systemSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type nav_system(nav_systemSEXP);
    rcpp_result_gen = Rcpp::wrap(autocomplete_score(nav_system));
    return rcpp_result_gen;
END_RCPP
}
// total_dots
int total_dots(std::vector<std::string> input);
RcppExport SEXP _aoc2021_total_dots(SEXP inputSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type input(inputSEXP);
    rcpp_result_gen = Rcpp::wrap(total_dots(input));
    return rcpp_result_gen;
END_RCPP
}
// print_output
void print_output(std::vector<std::string> input);
RcppExport SEXP _aoc2021_print_output(SEXP inputSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type input(inputSEXP);
    print_output(input);
    return R_NilValue;
END_RCPP
}
// total_distance
int total_distance(std::vector<std::string> commands);
RcppExport SEXP _aoc2021_total_distance(SEXP commandsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type commands(commandsSEXP);
    rcpp_result_gen = Rcpp::wrap(total_distance(commands));
    return rcpp_result_gen;
END_RCPP
}
// total_distance_2
int total_distance_2(std::vector<std::string> commands);
RcppExport SEXP _aoc2021_total_distance_2(SEXP commandsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type commands(commandsSEXP);
    rcpp_result_gen = Rcpp::wrap(total_distance_2(commands));
    return rcpp_result_gen;
END_RCPP
}
// power_consumption
int power_consumption(std::vector<std::string> numbers);
RcppExport SEXP _aoc2021_power_consumption(SEXP numbersSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type numbers(numbersSEXP);
    rcpp_result_gen = Rcpp::wrap(power_consumption(numbers));
    return rcpp_result_gen;
END_RCPP
}
// life_support_rating
int life_support_rating(std::vector<std::string> numbers);
RcppExport SEXP _aoc2021_life_support_rating(SEXP numbersSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type numbers(numbersSEXP);
    rcpp_result_gen = Rcpp::wrap(life_support_rating(numbers));
    return rcpp_result_gen;
END_RCPP
}
// get_coordinates
std::vector<std::array<int, 4>> get_coordinates(std::vector<std::string> vents);
RcppExport SEXP _aoc2021_get_coordinates(SEXP ventsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type vents(ventsSEXP);
    rcpp_result_gen = Rcpp::wrap(get_coordinates(vents));
    return rcpp_result_gen;
END_RCPP
}
// count_dangerous_areas
int count_dangerous_areas(std::vector<std::string> vents);
RcppExport SEXP _aoc2021_count_dangerous_areas(SEXP ventsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type vents(ventsSEXP);
    rcpp_result_gen = Rcpp::wrap(count_dangerous_areas(vents));
    return rcpp_result_gen;
END_RCPP
}
// count_dangerous_areas_2
int count_dangerous_areas_2(std::vector<std::string> vents);
RcppExport SEXP _aoc2021_count_dangerous_areas_2(SEXP ventsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type vents(ventsSEXP);
    rcpp_result_gen = Rcpp::wrap(count_dangerous_areas_2(vents));
    return rcpp_result_gen;
END_RCPP
}
// model_fish
std::vector<int> model_fish(std::vector<int> fish, int days);
RcppExport SEXP _aoc2021_model_fish(SEXP fishSEXP, SEXP daysSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<int> >::type fish(fishSEXP);
    Rcpp::traits::input_parameter< int >::type days(daysSEXP);
    rcpp_result_gen = Rcpp::wrap(model_fish(fish, days));
    return rcpp_result_gen;
END_RCPP
}
// run_day
std::vector<int> run_day(std::vector<int> fish);
RcppExport SEXP _aoc2021_run_day(SEXP fishSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<int> >::type fish(fishSEXP);
    rcpp_result_gen = Rcpp::wrap(run_day(fish));
    return rcpp_result_gen;
END_RCPP
}
// count_fish
int count_fish(std::vector<int> fish, int days);
RcppExport SEXP _aoc2021_count_fish(SEXP fishSEXP, SEXP daysSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<int> >::type fish(fishSEXP);
    Rcpp::traits::input_parameter< int >::type days(daysSEXP);
    rcpp_result_gen = Rcpp::wrap(count_fish(fish, days));
    return rcpp_result_gen;
END_RCPP
}
// count_fish_class
long count_fish_class(std::vector<int> fish, int days);
RcppExport SEXP _aoc2021_count_fish_class(SEXP fishSEXP, SEXP daysSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<int> >::type fish(fishSEXP);
    Rcpp::traits::input_parameter< int >::type days(daysSEXP);
    rcpp_result_gen = Rcpp::wrap(count_fish_class(fish, days));
    return rcpp_result_gen;
END_RCPP
}
// position_cost
int position_cost(std::vector<int> positions, int alignment_position);
RcppExport SEXP _aoc2021_position_cost(SEXP positionsSEXP, SEXP alignment_positionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<int> >::type positions(positionsSEXP);
    Rcpp::traits::input_parameter< int >::type alignment_position(alignment_positionSEXP);
    rcpp_result_gen = Rcpp::wrap(position_cost(positions, alignment_position));
    return rcpp_result_gen;
END_RCPP
}
// optimal_position
int optimal_position(std::vector<int> positions);
RcppExport SEXP _aoc2021_optimal_position(SEXP positionsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<int> >::type positions(positionsSEXP);
    rcpp_result_gen = Rcpp::wrap(optimal_position(positions));
    return rcpp_result_gen;
END_RCPP
}
// position_cost_2
int position_cost_2(std::vector<int> positions, int alignment_position);
RcppExport SEXP _aoc2021_position_cost_2(SEXP positionsSEXP, SEXP alignment_positionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<int> >::type positions(positionsSEXP);
    Rcpp::traits::input_parameter< int >::type alignment_position(alignment_positionSEXP);
    rcpp_result_gen = Rcpp::wrap(position_cost_2(positions, alignment_position));
    return rcpp_result_gen;
END_RCPP
}
// optimal_position_2
int optimal_position_2(std::vector<int> positions);
RcppExport SEXP _aoc2021_optimal_position_2(SEXP positionsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<int> >::type positions(positionsSEXP);
    rcpp_result_gen = Rcpp::wrap(optimal_position_2(positions));
    return rcpp_result_gen;
END_RCPP
}
// str_in
bool str_in(std::string a, std::string b);
RcppExport SEXP _aoc2021_str_in(SEXP aSEXP, SEXP bSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type a(aSEXP);
    Rcpp::traits::input_parameter< std::string >::type b(bSEXP);
    rcpp_result_gen = Rcpp::wrap(str_in(a, b));
    return rcpp_result_gen;
END_RCPP
}
// str_diff
std::string str_diff(std::string a, std::string b);
RcppExport SEXP _aoc2021_str_diff(SEXP aSEXP, SEXP bSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type a(aSEXP);
    Rcpp::traits::input_parameter< std::string >::type b(bSEXP);
    rcpp_result_gen = Rcpp::wrap(str_diff(a, b));
    return rcpp_result_gen;
END_RCPP
}
// count_digits
int count_digits(std::vector<std::string> entries);
RcppExport SEXP _aoc2021_count_digits(SEXP entriesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type entries(entriesSEXP);
    rcpp_result_gen = Rcpp::wrap(count_digits(entries));
    return rcpp_result_gen;
END_RCPP
}
// sum_readings
int sum_readings(std::vector<std::string> entries);
RcppExport SEXP _aoc2021_sum_readings(SEXP entriesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type entries(entriesSEXP);
    rcpp_result_gen = Rcpp::wrap(sum_readings(entries));
    return rcpp_result_gen;
END_RCPP
}
// get_low_points
std::vector<std::array<int, 2>> get_low_points(std::vector<std::vector<int>> parsed);
RcppExport SEXP _aoc2021_get_low_points(SEXP parsedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::vector<int>> >::type parsed(parsedSEXP);
    rcpp_result_gen = Rcpp::wrap(get_low_points(parsed));
    return rcpp_result_gen;
END_RCPP
}
// risk_level
int risk_level(std::vector<std::string> map);
RcppExport SEXP _aoc2021_risk_level(SEXP mapSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type map(mapSEXP);
    rcpp_result_gen = Rcpp::wrap(risk_level(map));
    return rcpp_result_gen;
END_RCPP
}
// basin_sizes
int basin_sizes(std::vector<std::string> map);
RcppExport SEXP _aoc2021_basin_sizes(SEXP mapSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type map(mapSEXP);
    rcpp_result_gen = Rcpp::wrap(basin_sizes(map));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_aoc2021_count_increases", (DL_FUNC) &_aoc2021_count_increases, 1},
    {"_aoc2021_window_increases", (DL_FUNC) &_aoc2021_window_increases, 1},
    {"_aoc2021_error_score", (DL_FUNC) &_aoc2021_error_score, 1},
    {"_aoc2021_autocomplete_score", (DL_FUNC) &_aoc2021_autocomplete_score, 1},
    {"_aoc2021_total_dots", (DL_FUNC) &_aoc2021_total_dots, 1},
    {"_aoc2021_print_output", (DL_FUNC) &_aoc2021_print_output, 1},
    {"_aoc2021_total_distance", (DL_FUNC) &_aoc2021_total_distance, 1},
    {"_aoc2021_total_distance_2", (DL_FUNC) &_aoc2021_total_distance_2, 1},
    {"_aoc2021_power_consumption", (DL_FUNC) &_aoc2021_power_consumption, 1},
    {"_aoc2021_life_support_rating", (DL_FUNC) &_aoc2021_life_support_rating, 1},
    {"_aoc2021_get_coordinates", (DL_FUNC) &_aoc2021_get_coordinates, 1},
    {"_aoc2021_count_dangerous_areas", (DL_FUNC) &_aoc2021_count_dangerous_areas, 1},
    {"_aoc2021_count_dangerous_areas_2", (DL_FUNC) &_aoc2021_count_dangerous_areas_2, 1},
    {"_aoc2021_model_fish", (DL_FUNC) &_aoc2021_model_fish, 2},
    {"_aoc2021_run_day", (DL_FUNC) &_aoc2021_run_day, 1},
    {"_aoc2021_count_fish", (DL_FUNC) &_aoc2021_count_fish, 2},
    {"_aoc2021_count_fish_class", (DL_FUNC) &_aoc2021_count_fish_class, 2},
    {"_aoc2021_position_cost", (DL_FUNC) &_aoc2021_position_cost, 2},
    {"_aoc2021_optimal_position", (DL_FUNC) &_aoc2021_optimal_position, 1},
    {"_aoc2021_position_cost_2", (DL_FUNC) &_aoc2021_position_cost_2, 2},
    {"_aoc2021_optimal_position_2", (DL_FUNC) &_aoc2021_optimal_position_2, 1},
    {"_aoc2021_str_in", (DL_FUNC) &_aoc2021_str_in, 2},
    {"_aoc2021_str_diff", (DL_FUNC) &_aoc2021_str_diff, 2},
    {"_aoc2021_count_digits", (DL_FUNC) &_aoc2021_count_digits, 1},
    {"_aoc2021_sum_readings", (DL_FUNC) &_aoc2021_sum_readings, 1},
    {"_aoc2021_get_low_points", (DL_FUNC) &_aoc2021_get_low_points, 1},
    {"_aoc2021_risk_level", (DL_FUNC) &_aoc2021_risk_level, 1},
    {"_aoc2021_basin_sizes", (DL_FUNC) &_aoc2021_basin_sizes, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_aoc2021(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
