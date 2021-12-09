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
