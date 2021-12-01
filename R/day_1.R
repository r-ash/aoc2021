#' Solve day 1 problem 1
#'
#' @param file Path to file of depth measurements
#'
#' @return The number of times a depth measurement increases
#' @export
solve_day_1 <- function(file) {
  lines <- readLines(file)
  depths <- as.integer(lines)
  count_increases(depths)
}

#' Solve day 1 problem 2
#'
#' @param file Path to file of component masses
#'
#' @return The number of times a three-measurement sliding window increases
#' @export
solve_day_1_puzzle_2 <- function(file) {
  lines <- readLines(file)
  masses <- as.integer(lines)
  window_increases(masses)
}
