#' Solve day 5 problem 1
#'
#' @param file Path to file of vents
#'
#' @return The number of dangerous areas i.e. 2 or more vents
#' @export
solve_day_5 <- function(file) {
  vents <- readLines(file)
  count_dangerous_areas(vents)
}

#' Solve day 5 problem 2
#'
#' @param file Path to file of vents
#'
#' @return The number of dangerous areas i.e. 2 or more vents
#' @export
solve_day_5_puzzle_2 <- function(file) {
  vents <- readLines(file)
  count_dangerous_areas_2(vents)
}
