test_that("can get low points", {
  expect_equal(get_low_points(c("2199943210",
                                "3987894921",
                                "9856789892",
                                "8767896789",
                                "9899965678")),
               c(1, 0, 5, 5))
})

test_that("can get risk", {
  expect_equal(risk_level(c("2199943210",
                            "3987894921",
                            "9856789892",
                            "8767896789",
                            "9899965678")),
               15)
})
