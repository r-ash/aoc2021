#' Solve day 6 problem 1
#'
#' @param file Path to file of depth measurements
#'
#' @return The number of times a depth measurement increases
#' @export
solve_day_6 <- function(file) {
  fish <- as.numeric(read.csv(file, header = FALSE))
  count_fish(fish, days = 80)
}

#' Solve day 6 problem 2
#'
#' @param file Path to file of depth measurements
#'
#' @return The number of times a depth measurement increases
#' @export
solve_day_6_puzzle_2 <- function(file) {
  fish <- as.numeric(read.csv(file, header = FALSE))
  count_fish_class(fish, days = 256)
}
