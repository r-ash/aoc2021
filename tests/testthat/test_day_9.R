test_that("can get low points", {
  expect_equal(get_low_points(list(c(2, 1, 9, 9, 9, 4, 3, 2, 1, 0),
                                   c(3, 9, 8, 7, 8, 9, 4, 9, 2, 1),
                                   c(9, 8, 5, 6, 7, 8, 9, 8, 9, 2),
                                   c(8, 7, 6, 7, 8, 9, 6, 7, 8, 9),
                                   c(9, 8, 9, 9, 9, 6, 5, 6, 7, 8))),
               list(c(0, 1), c(0, 9), c(2, 2), c(4, 6)))
})

test_that("can get risk", {
  expect_equal(risk_level(c("2199943210",
                            "3987894921",
                            "9856789892",
                            "8767896789",
                            "9899965678")),
               15)
})

test_that("can get size basins", {
  expect_equal(basin_sizes(c("2199943210",
                            "3987894921",
                            "9856789892",
                            "8767896789",
                            "9899965678")),
               1134)
})
