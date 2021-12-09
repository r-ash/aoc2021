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
