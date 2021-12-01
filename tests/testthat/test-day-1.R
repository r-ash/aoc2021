test_that("can calculate fuel requirements from mass", {
  expect_equal(fuel_required(12), 2)
  expect_equal(fuel_required(14), 2)
  expect_equal(fuel_required(1969), 654)
  expect_equal(fuel_required(100756), 33583)
  expect_equal(fuel_required(c(1969, 100756)), 654 + 33583)
  expect_equal(fuel_required(2), 0)
  expect_equal(fuel_required(-5), 0)
  expect_equal(fuel_required(0), 0)
})

test_that("can get fuel need recursively", {
  expect_equal(fuel_recursive(14), 2)
  expect_equal(fuel_recursive(1969), 966)
  expect_equal(fuel_recursive(100756), 50346)
})

test_that("can get mass of component and fuel", {
  expect_equal(fuel_and_fuel_mass_required(14), 2)
  expect_equal(fuel_and_fuel_mass_required(12), 2)
  expect_equal(fuel_and_fuel_mass_required(c(14, 12)), 4)
})
