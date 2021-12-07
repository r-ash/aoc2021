test_that("can get position cost", {
  expect_equal(position_cost(c(16, 1, 2, 0, 4, 2, 7, 1, 2, 14), 2),
               37)
  expect_equal(position_cost(c(16, 1, 2, 0, 4, 2, 7, 1, 2, 14), 1),
               41)
  expect_equal(position_cost(c(16, 1, 2, 0, 4, 2, 7, 1, 2, 14), 3),
               39)
  expect_equal(position_cost(c(16, 1, 2, 0, 4, 2, 7, 1, 2, 14), 10),
               71)
})

test_that("can get minimal fuel cost", {
  expect_equal(optimal_position(c(16, 1, 2, 0, 4, 2, 7, 1, 2, 14)),
               37)
})

test_that("can get position cost", {
  expect_equal(position_cost_2(c(16, 1, 2, 0, 4, 2, 7, 1, 2, 14), 2),
               206)
  expect_equal(position_cost_2(c(16, 1, 2, 0, 4, 2, 7, 1, 2, 14), 5),
               168)
})

test_that("can get minimal fuel cost part 2", {
  expect_equal(optimal_position_2(c(16, 1, 2, 0, 4, 2, 7, 1, 2, 14)),
               168)
})
