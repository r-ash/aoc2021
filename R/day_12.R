#' Solve day 12 problem 1
#'
#' @param file Path to file of cave connections
#'
#' @return The total number of possible paths
#' @export
solve_day_12 <- function(file) {
  caves <- readLines(file)
  caves <- strsplit(caves,)
  get_num_paths(caves, small_caves = 1, verbose = FALSE)
}

#' Solve day 12 problem 2
#'
#' @param file Path to file of syntax errors
#'
#' @return The syntax error score
#' @export
solve_day_12_puzzle_2 <- function(file) {
  octopuses <- readLines(file)
  get_num_paths(caves, small_caves = 2, verbose = FALSE)
}
