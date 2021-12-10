#' Solve day 3 problem 1
#'
#' @param file Path to file of numbers
#'
#' @return The power consumption of the submarine
#' @export
solve_day_3 <- function(file) {
  numbers <- readLines(file)
  power_consumption(numbers)
}

#' Solve day 3 problem 2
#'
#' @param file Path to file of numbers
#'
#' @return The life support rating of the submarine
#' @export
solve_day_3_puzzle_2 <- function(file) {
  numbers <- readLines(file)
  life_support_rating(numbers)
}
