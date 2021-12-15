#' Solve day 15 problem 1
#'
#' @param file Path to input
#'
#' @return The minimum risk
#' @export
solve_day_15 <- function(file) {
  input <- readLines(file)
  input <- strsplit(input, "")
  input <- lapply(input, as.numeric)
  get_min_risk(input)
}

#' Solve day 15 problem 2
#'
#' @param file Path to input
#'
#' @return The minimum risk
#' @export
solve_day_15_puzzle_2 <- function(file) {
  input <- readLines(file)
  input <- strsplit(input, "")
  input <- lapply(input, as.numeric)
  get_min_total_risk(input)
}
