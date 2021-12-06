#' Solve day 2 problem 1
#'
#' @param file Path to file of commands
#'
#' @return The number of times a depth measurement increases
#' @export
solve_day_2 <- function(file) {
  commands <- readLines(file)
  total_distance(commands)
}

#' Solve day 2 problem 2
#'
#' @param file Path to file of commands
#'
#' @return The number of times a depth measurement increases
#' @export
solve_day_2_puzzle_2 <- function(file) {
  commands <- readLines(file)
  total_distance_2(commands)
}
