test_that("can calculate total distance", {
  expect_equal(total_distance(c("forward 5",
                                "down 5",
                                "forward 8",
                                "up 3",
                                "down 8",
                                "forward 2")), 150)
})

test_that("can calculate total distance puzzle 2", {
  expect_equal(total_distance_2(c("forward 5",
                                  "down 5",
                                  "forward 8",
                                  "up 3",
                                  "down 8",
                                  "forward 2")), 900)
})
