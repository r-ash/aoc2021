#' Solve day 13 problem 1
#'
#' @param file Path to input
#'
#' @return The total dots
#' @export
solve_day_13 <- function(file) {
  input <- readLines(file)
  total_dots(input)
}

#' Solve day 13 problem 2
#'
#' @param file Path to input
#'
#' @return Prints the answer
#' @export
solve_day_13_puzzle_2 <- function(file) {
  input <- readLines(file)
  print_output(input)
}
