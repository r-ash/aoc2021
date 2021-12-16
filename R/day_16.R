#' Solve day 16 problem 1
#'
#' @param file Path to input
#'
#' @return The sum of version numbers
#' @export
solve_day_16 <- function(file) {
  input <- readLines(file)
  sum_version_numbers(input)
}

#' Solve day 16 problem 2
#'
#' @param file Path to input
#'
#' @return The value of package
#' @export
solve_day_16_puzzle_2 <- function(file) {
  input <- readLines(file)
  get_package_value(input)
}
