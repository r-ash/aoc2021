#' Solve day 11 problem 1
#'
#' @param file Path to file of syntax errors
#'
#' @return The syntax error score
#' @export
solve_day_11 <- function(file) {
  octopuses <- readLines(file)
  get_flashes(octopuses, 100)
}

#' Solve day 11 problem 2
#'
#' @param file Path to file of syntax errors
#'
#' @return The syntax error score
#' @export
solve_day_11_puzzle_2 <- function(file) {
  octopuses <- readLines(file)
  get_first_all_flash(octopuses, 1000)
}
