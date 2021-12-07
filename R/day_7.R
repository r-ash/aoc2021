#' Solve day 7 problem 1
#'
#' @param file Path to file of crab positions
#'
#' @return The minimum fuel needed to align the crabs
#' @export
solve_day_7 <- function(file) {
  crabs <- as.numeric(read.csv(file, header = FALSE))
  optimal_position(crabs)
}

#' Solve day 7 problem 2
#'
#' @param file Path to file of crab positions
#'
#' @return The minimum fuel needed to align the crabs
#' @export
solve_day_7_puzzle_2 <- function(file) {
  crabs <- as.numeric(read.csv(file, header = FALSE))
  optimal_position_2(crabs)
}
