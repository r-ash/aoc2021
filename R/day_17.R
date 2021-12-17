#' Solve day 17 problem 1
#'
#' @param file Path to input
#'
#' @return The max height
#' @export
solve_day_17 <- function(file) {
  input <- readLines(file)
  input <- regmatches(input, gregexpr("[-[:digit:]]+", input))
  get_highest_path(as.numeric(unlist(input)))
}

#' Solve day 17 problem 2
#'
#' @param file Path to input
#'
#' @return The no of initial velocities which land in target zone
#' @export
solve_day_17_puzzle_2 <- function(file) {
  input <- readLines(file)
  input <- regmatches(input, gregexpr("[-[:digit:]]+", input))
  get_no_initial_velocities(as.numeric(unlist(input)))
}
