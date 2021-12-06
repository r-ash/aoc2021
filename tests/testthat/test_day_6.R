test_that("day can be run", {
  expect_equal(run_day(c(3, 4, 3, 1, 2)),
               c(2, 3, 2, 0, 1))
  expect_equal(run_day(c(2, 3, 2, 0, 1)),
               c(1, 2, 1, 6, 0, 8))
  expect_equal(run_day(c(1, 2, 1, 6, 0, 8)),
               c(0, 1, 0, 5, 6, 7, 8))
  expect_equal(run_day(c(0, 1, 0, 5, 6, 7, 8)),
               c(6, 0, 6, 4, 5, 6, 7, 8, 8))
})

test_that("multiple days can be run", {
  expect_equal(model_fish(c(3, 4, 3, 1, 2), 18),
               c(6, 0, 6, 4, 5, 6, 0, 1, 1, 2, 6, 0, 1, 1, 1, 2,
                 2, 3, 3, 4, 6, 7, 8, 8, 8, 8))
})

test_that("can count number of fish after n days", {
  expect_equal(count_fish(c(3, 4, 3, 1, 2), 18),
               26)
  expect_equal(count_fish(c(3, 4, 3, 1, 2), 80),
               5934)
})

test_that("can count number of fish after n days with class impl", {
  expect_equal(count_fish_class(c(3, 4, 3, 1, 2), 18),
               26)
  expect_equal(count_fish_class(c(3, 4, 3, 1, 2), 80),
               5934)
  expect_equal(count_fish_class(c(3, 4, 3, 1, 2), 256),
               26984457539)
})
