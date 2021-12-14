#' Solve day 4 problem 1
#'
#' @param file Path to file of numbers
#'
#' @return The power consumption of the submarine
#' @export
solve_day_4 <- function(file) {
  numbers <- readLines(file)
  numbers <- numbers[numbers != ""]
  numbers <- lapply(numbers, function(row) {
    matches <- regmatches(row, gregexpr("[[:digit:]]+", row))
    as.numeric(unlist(matches))
  })
  winning_score(numbers)
}

#' Solve day 4 problem 2
#'
#' @param file Path to file of numbers
#'
#' @return The power consumption of the submarine
#' @export
solve_day_4_puzzle_2 <- function(file) {
  numbers <- readLines(file)
  numbers <- numbers[numbers != ""]
  numbers <- lapply(numbers, function(row) {
    matches <- regmatches(row, gregexpr("[[:digit:]]+", row))
    as.numeric(unlist(matches))
  })
  losing_score(numbers)
}
