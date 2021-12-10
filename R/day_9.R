#' Solve day 9 problem 1
#'
#' @param file Path to file height map
#'
#' @return The risk level
#' @export
solve_day_9 <- function(file) {
  heightmap <- readLines(file)
  risk_level(heightmap)
}

#' Solve day 9 problem 2
#'
#' @param file Path to file height map
#'
#' @return The 3 largest basin sizes multiplied
#' @export
solve_day_9_puzzle_2 <- function(file) {
  heightmap <- readLines(file)
  basin_sizes(heightmap)
}
