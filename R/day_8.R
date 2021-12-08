#' Solve day 8 problem 1
#'
#' @param file Path to file of entries
#'
#' @return The count of digits 1, 4, 7 and 8 in outputs
#' @export
solve_day_8 <- function(file) {
  entries <- readLines(file)
  count_digits(entries)
}

#' Solve day 8 problem 2
#'
#' @param file Path to file of entries
#'
#' @return The count of digits 1, 4, 7 and 8 in outputs
#' @export
solve_day_8_puzzle_2 <- function(file) {
  entries <- readLines(file)
  sum_readings(entries)
}
