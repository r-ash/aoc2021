#' Solve day 10 problem 1
#'
#' @param file Path to file of syntax errors
#'
#' @return The syntax error score
#' @export
solve_day_10 <- function(file) {
  errors <- readLines(file)
  error_score(errors)
}

#' Solve day 10 puzzle 2
#'
#' @param file Path to file of syntax errors
#'
#' @return The autocomplete score
#' @export
solve_day_10_puzzle_2 <- function(file) {
  errors <- readLines(file)
  autocomplete_score(errors)
}
