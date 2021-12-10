test_that("can get power consumtion", {
  expect_equal(power_consumption(c(
    "00100",
    "11110",
    "10110",
    "10111",
    "10101",
    "01111",
    "00111",
    "11100",
    "10000",
    "11001",
    "00010",
    "01010")),
    198)
})

test_that("can get life support rating", {
  expect_equal(life_support_rating(c(
    "00100",
    "11110",
    "10110",
    "10111",
    "10101",
    "01111",
    "00111",
    "11100",
    "10000",
    "11001",
    "00010",
    "01010")),
    230)
})
