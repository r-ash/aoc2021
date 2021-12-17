test_that("can get highest y", {
  expect_equal(get_highest_path(c(20, 30, -10, -5)), 45);
})

test_that("can get no of initial velocities", {
  expect_equal(get_no_initial_velocities(c(20, 30, -10, -5)), 112)
})
