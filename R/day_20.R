#' Solve day 20 problem 1
#'
#' @param file Path to input
#'
#' @return The number of lit areas
#' @export
solve_day_20 <- function(file) {
  input <- readLines(file)
  algorithm <- input[1]
  start <- input[seq.int(from = 3, to = length(input))]
  get_number_of_pixels_lit(start, algorithm, 2)
}

#' Solve day 20 problem 1
#'
#' @param file Path to input
#'
#' @return The number of lit areas
#' @export
solve_day_20_puzzle_2 <- function(file) {
  input <- readLines(file)
  algorithm <- input[1]
  start <- input[seq.int(from = 3, to = length(input))]
  get_number_of_pixels_lit(start, algorithm, 50)
}
