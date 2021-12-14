#' Solve day 14 problem 1
#'
#' @param file Path to input
#'
#' @return The diff
#' @export
solve_day_14 <- function(file) {
  input <- readLines(file)
  polymer_size(input, 10)
}

#' Solve day 14 problem 2
#'
#' @param file Path to input
#'
#' @return The diff
#' @export
solve_day_14_puzzle_2 <- function(file) {
  input <- readLines(file)
  polymer_size(input, 40)
}
